#pragma once

class Vec2
{
public:
	float x;
	float y;
public:
	Vec2() = default;
	Vec2(float xPos, float yPos);
	Vec2 operator+(const Vec2& rhs) const;
	Vec2& operator+=(const Vec2& rhs);
	Vec2 operator*(const float rhs) const;
	Vec2& operator*=(const float rhs);
	Vec2 operator-(const Vec2& rhs) const;
	Vec2& operator-=(const Vec2& rhs);
	float GetLength() const;
	float GetLengthSq() const;
	Vec2& Normalize();
	Vec2 GetNormalize() const;
};