#pragma once
#include <cmath>
#include "MathUtils.h"
struct Vector2
{
	float x;
	float y;

	Vector2() = default;
	Vector2(float x, float y)
	{
		this-> x = x;
		this-> y = y;
	}Vector2(int x, int y)
	{
		this-> x = (float)x;
		this-> y = (float)y;
	}

	float operator [] (unsigned int index) const {return (&x)[index]; }
	float& operator [] (unsigned int index) { return (&x)[index]; }
	

	Vector2 Add(Vector2 v) {return Vector2{x + v.x, y +v.y};}
	Vector2 operator + (const Vector2& v) const {return Vector2{ x + v.x, y + v.y };}
	Vector2 operator - (const Vector2& v) const {return Vector2{ x - v.x, y - v.y };}
	Vector2 operator * (const Vector2& v) const {return Vector2{ x * v.x, y * v.y };}
	Vector2 operator / (const Vector2& v) const {return Vector2{ x / v.x, y / v.y };}

	Vector2 operator + (float s) const {return Vector2{ x + s, y + s };}
	Vector2 operator - (float s) const {return Vector2{ x - s, y - s };}
	Vector2 operator * (float s) const {return Vector2{ x * s, y * s };}
	Vector2 operator / (float s) const {return Vector2{ x / s, y / s };}

	float Lenthsqr() const { return (x * x) + (y * y); }
	float Length() const { return Math::Sqrt((x * x) + (y * y)); }
	float Angle() { return Math::Atan2(x, y); }

	//Vector2 Rotate(float radians) const ;

};

//inline Vector2 Vector2::Rotate(float radians) const
//{
	//float x_ = v.x * std::cos(radians) - v.y * std::sin(radians);
	//float y_ = v.y * std::cos(radians) - v.y * std::sin(radians);
	
	

	//return { x_, y_ };

//}