#pragma once

#include "ofMain.h"

class FractalMode{
	private:
		bool activated = false;
	public:
		void draw(); 
		virtual void setActivate(bool a) { this->activated = a; };
		virtual bool getActivate() { return this->activated; };
};