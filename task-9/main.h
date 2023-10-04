#pragma once

#include <cmath>

class Vector2
{
public:
	float x, y;

	float magnitude();
	float distance(Vector2);

	Vector2(float, float);
};

Vector2 operator+(Vector2 a, Vector2 b) { return Vector2(a.x + b.x, a.y + b.y); }
Vector2 operator-(Vector2 a, Vector2 b) { return Vector2(a.x - b.x, a.y - b.y); }
Vector2 operator*(Vector2 a, Vector2 b) { return Vector2(a.x * b.x, a.y * b.y); }
Vector2 operator/(Vector2 a, Vector2 b) { return Vector2(a.x / b.x, a.y / b.y); }
Vector2 operator*(Vector2 a, float scalar) { return Vector2(a.x * scalar, a.y * scalar); }
Vector2 operator/(Vector2 a, float scalar) { return Vector2(a.x / scalar, a.y / scalar); }

ostream& operator<<(ostream& stream, Vector2 v)
{
	stream << "(" << v.x << ", " << v.y << ")";
	return stream;
}


float Vector2::magnitude()
{
	return sqrt((x * x) + (y * y));
}

float Vector2::distance(Vector2 other)
{
	return (other - *this).magnitude();
}

Vector2::Vector2(float _x, float _y)
{
	x = _x;
	y = _y;
}

float GetDistanceBetweenPoints(Vector2 a, Vector2 b)
{
	return a.distance(b);
}