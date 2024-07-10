#pragma once
#include <cmath>
#include "MathUtils.h"

struct Color
{
	float r;
	float g;
	float b;
	float a;

	Color() = default;
	Color(float x, float y)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}


	float operator [] (unsigned int index) const { return (&r)[index]; }
	float& operator [] (unsigned int index) { return (&r)[index]; }

	//Color operator + (const Color& c) const { return Color{ x + v.x, y + v.y }; }
	//Color operator - (const Color& c) const { return Color{ x - v.x, y - v.y }; }
	//Color operator * (const Color& c) const { return Color{ x * v.x, y * v.y }; }
	//Color operator / (const Color& c) const { return Color{ x / v.x, y / v.y }; }
	//
	//Color operator + (float s) const { return Color{ x + s, y + s }; }
	//Color operator - (float s) const { return Color{ x - s, y - s }; }
	//Color operator * (float s) const { return Color{ x * s, y * s }; }
	//Color operator / (float s) const { return Color{ x / s, y / s }; }


	
};