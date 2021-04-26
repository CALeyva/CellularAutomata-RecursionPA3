#include "FractalMode.h"

class SierpinskiFractal : public FractalMode{
	public:
		void draw(float x, float y, float size, int n, unsigned int icolor, vector<ofColor> colors);
};