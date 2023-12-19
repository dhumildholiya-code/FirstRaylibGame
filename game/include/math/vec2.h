#pragma once
#include<iostream>

class Vec2 {
public:
	float x;
	float y;

public:
	static Vec2 zero() { return Vec2(0.0f, 0.0f); }
	static Vec2 one() { return Vec2(1.0f, 1.0f); }
	static Vec2 right() { return Vec2(1.0f, 0.0f); }
	static Vec2 left() { return Vec2(-1.0f, 0.0f); }
	static Vec2 up() { return Vec2(0.0f, -1.0f); }
	static Vec2 down() { return Vec2(0.0f, 1.0f); }

public:
	Vec2(float xin, float yin) :
		x{ xin }, y{ yin }
	{ }
	Vec2()
	{
		x = 0.0; y = 0.0;
	}
	~Vec2() {}

	float sqrMagnitude() const {
		return x * x + y * y;
	}
	float magnitude() const {
		return sqrtf(sqrMagnitude());
	}
	void normalize() {
		float mag = magnitude();
		if (abs(mag - 0.0f) < 0.001f) return;
		x = x / mag;
		y = y / mag;
	}
	void rotateBy(float angle) {
		angle = angle * DEG2RAD;
		Vec2 a = Vec2(cosf(angle), sinf(angle));
		Vec2 b = Vec2(-sinf(angle), cosf(angle));

		float newX = a.x * x + b.x * y;
		float newY = a.y * x + b.y * y;
		x = newX; y = newY;
	}

	//static mehtods
	static float dist(const Vec2& from, const Vec2& to) {
		return (to - from).magnitude();
	}
	static float dot(const Vec2& lhs, const Vec2& rhs) {
		return lhs.x * rhs.x + lhs.y * rhs.y;
	}
	static float angle(const Vec2& a, const Vec2& b) {
		float magProduct = a.magnitude() * b.magnitude();
		float cosAngle = dot(a, b) / magProduct;
		std::cout << "Cos Angle : " << cosAngle << std::endl;
		float angle = acos(cosAngle);
		return angle;
	}

	//Operator Overloading
	Vec2 operator + (const Vec2& rhs) const {
		return Vec2(x + rhs.x, y + rhs.y);
	}
	void operator += (const Vec2& rhs) {
		x += rhs.x; y += rhs.y;
	}
	Vec2 operator - (const Vec2& rhs) const {
		return Vec2(x - rhs.x, y - rhs.y);
	}
	void operator -= (const Vec2& rhs) {
		x -= rhs.x; y -= rhs.y;
	}
	Vec2 operator * (float value) const {
		return Vec2(x * value, y * value);
	}
	void operator *= (const Vec2& rhs) {
		x *= rhs.x; y *= rhs.y;
	}
	Vec2 operator / (float value) const {
		return Vec2(x / value, y / value);
	}
	void operator /= (const Vec2& rhs) {
		x /= rhs.x; y /= rhs.y;
	}

	friend std::ostream& operator << (std::ostream& os, const Vec2& vec) {
		os << "Vec2:" << "(" << vec.x << ", " << vec.y << ")";
		return os;
	}
};
