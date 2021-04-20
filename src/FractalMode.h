#pragma once
#include<cmath>

#include "ofMain.h"

class FractalMode{
	public:
		void draw(); 
		void setActivate();
		virtual void getActivate() = 0;
};