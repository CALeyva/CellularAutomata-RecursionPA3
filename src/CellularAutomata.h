#include "FractalMode.h"
#include "ofMain.h" // for ofColor data type
#include "ofxGui/src/ofxGui.h" // For range slider

class CellularAutomata : public FractalMode{
	public:
        CellularAutomata();
        void setInitialConditions(bool rand);
        vector<vector<int>> generate(int rule, int levels, vector<vector<int>> cells, vector<vector<ofColor>> &colors);
        vector<vector<int>> generate(vector<int> binary_rule, vector<vector<int>> cells, vector<vector<ofColor>> &colors, int levels, int size, int step, int index);
        vector<int> binaryByte(int num);
        int binary_converter(int dec);
        void draw_matrix(vector<vector<int>> cells, vector<vector<ofColor>> colors, int levels);
		void draw(int levels, bool colorCA);
    private:
        ofxPanel gui;
        ofxIntSlider rules;
        ofxToggle initialCond;
        vector<vector<int>> cells;
        vector<vector<ofColor>> colors;
        int cell_size = 25;
        int size = (int) ofGetWidth() / this->cell_size;
        int rule = 30;
        bool initialRand = false;
};