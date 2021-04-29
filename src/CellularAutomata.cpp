#include "CellularAutomata.h"

/*
*  TO-DO:
*   X- Check edge cases
*   - Modify rule colors
*   - cell size initializer
*   X- matrix initializer
*   X- draw_matrix()
*   X- draw()
*   - rule changes
*   - &args: cells, colors
*   X- check for resizing
*   X- check reinitialization error
*/

// See rules at: https://plato.stanford.edu/entries/cellular-automata/supplement.html#:~:text=As%20we%20have%20seen%2C%20in,total%20of%20256%20possible%20rules.

CellularAutomata::CellularAutomata() {
    gui.setup();
    gui.add(rules.setup("Rule Selection", this->rule, 0, 255));
    gui.add(initialCond.setup("Initial Condition", this->initialRand));
    setInitialConditions(this->initialRand);
}

void CellularAutomata::setInitialConditions(bool rand) {
    this->cells.clear();
    vector<int> row(this->size, 0); // add random to fit entire screen
    // Modify to get custom initial conditions
    row[size/2] = 1;
    this->cells.push_back(row);
}

vector<vector<int>> CellularAutomata::generate(int rule, int levels, vector<vector<int>> c, vector<vector<ofColor>> &colors) {
    if (c.size() < levels) {
        int step = c.size();
        int size_buffer = c.size();
        vector<int> row(this->size, 0);
        while (levels > size_buffer) {
            c.push_back(row);
            size_buffer++;
        }
        c = generate(binaryByte(rule), c, colors, levels, this->size, step, 0);
    }
    draw_matrix(c, colors, levels);
    return c;
}

vector<vector<int>> CellularAutomata::generate(vector<int> binary_rule, vector<vector<int>> c, vector<vector<ofColor>> &colors, int levels, int size, int step, int index) {
    if (step >= levels) return c; // (index >= size && step >= levels)
    if (index >= size) return generate(binary_rule, c, colors, levels, size, step+1, 0);
    int parent;
    if (index == 0) parent = c[step-1][index] * 10 + c[step-1][index+1];
    else if (index + 1 == size) parent = c[step-1][index-1] * 100 + c[step-1][index] * 10;
    else parent = c[step-1][index-1] * 100 + c[step-1][index] * 10 + c[step-1][index+1];
    switch (parent) {
        // Modify rule colors
        case 111:
            // colors[step][index] = ofColor(255,0,0); // Red
            c[step][index] = binary_rule[0];
            break;
        case 110:
            // colors[step][index] = ofColor(255,127,0); // Orange
            c[step][index] = binary_rule[1];
            break;
        case 101:
            // colors[step][index] = ofColor(255,255,0); // Yellow
            c[step][index] = binary_rule[2];
            break;
        case 100:
            // colors[step][index] = ofColor(0,255,0); // Green
            c[step][index] = binary_rule[3];
            break;
        case 11:
            // colors[step][index] = ofColor(0,0,255); // Blue
            c[step][index] = binary_rule[4];
            break;
        case 10:
            // colors[step][index] = ofColor(75,0,130); // Purple
            c[step][index] = binary_rule[5];
            break;
        case 1:
            // colors[step][index] = ofColor(148,0,211); // Indigo
            c[step][index] = binary_rule[6];
            break;
        case 0:
            // colors[step][index] = ofColor(255,0,255); // Pink
            c[step][index] = binary_rule[7];
            break;
    }
    return generate(binary_rule, c, colors, levels, size, step, index+1);
}

vector<int> CellularAutomata::binaryByte(int num) {
    num = binary_converter(num);
    vector<int> bin = {0,0,0,0,0,0,0,0};
    int i = 7;
    while (num != 0) {
        bin[i] = num % 10;
        num /= 10;
        i--;
    }
    return bin;
}

int CellularAutomata::binary_converter(int dec) {
    if (dec == 0) return 0;
    return dec % 2 + 10 * binary_converter(dec / 2);
}

void CellularAutomata::draw_matrix(vector<vector<int>> c, vector<vector<ofColor>> colors, int levels) { // check & in colors arg
    int initial_x = ofGetWidth() % this->cell_size / 2;
    int x = initial_x;
    int y = 0;
    ofSetBackgroundColor(ofColor(255,255,255));
    for (int row = 0; row < levels; row++) {
        for (int col = 0; col < this->size; col++) {
            ofFill();
            if (c[row][col] == 1) ofSetColor(ofColor(0,0,0)); // Add rule colors
            else ofSetColor(ofColor(255,255,255));
            ofDrawRectangle(x,y,this->cell_size,this->cell_size);
            x += this->cell_size;
        }
        x = initial_x;
        y += this->cell_size;
    }
}

void CellularAutomata::draw(int levels, bool colorCA) { // When change of rule?
    bool altered = false;
    // if (this->cells[cells.size()-1][0] == 1) {
    //     // this->size += (int) this->size / 4;
    //     this->cell_size = (int) ofGetWidth() / (this->cell_size + 5);
    //     changed = true;
    // } 
    if (levels > (int) ofGetHeight() / this->cell_size) {
        this->cell_size = (int) ofGetHeight() / levels;
        altered = true;
    } if (this->size != (int) ofGetWidth() / this->cell_size) {
        this->size = (int) ofGetWidth() / this->cell_size;
        altered = true;
    } 
    // if (this->cells[cells.size()-1][0] == 1 || levels > (int) ofGetHeight() / this->cell_size || this->size != (int) ofGetWidth() / this->cell_size) {
    //     //this->cell_size = min(min((int) ofGetWidth() / this->size, (int) ofGetHeight() / levels), (int) ofGetWidth() / this->size);
    //     setInitialConditions();
    // }
    if (this->rule != rules) {
        this->rule = rules;
        altered = true;
    } if (this->initialRand != initialCond) {
        this->initialRand = initialCond;
        altered = true;
    }
    
    if (altered) {
        altered = false;
        setInitialConditions(this->initialRand);
    }
    this->cells = generate(rules, levels, this->cells, this->colors);
    gui.draw();
}