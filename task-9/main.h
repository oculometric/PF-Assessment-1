#pragma once

#include <cmath>

// Vector2 class stub
class Vector2
{
public:
	float x, y;

	float magnitude();
	float distance(Vector2);

	Vector2(float, float);
};

// Vector2-related operator overloads
Vector2 operator+(Vector2 a, Vector2 b) { return Vector2(a.x + b.x, a.y + b.y); }
Vector2 operator-(Vector2 a, Vector2 b) { return Vector2(a.x - b.x, a.y - b.y); }
Vector2 operator*(Vector2 a, Vector2 b) { return Vector2(a.x * b.x, a.y * b.y); }
Vector2 operator/(Vector2 a, Vector2 b) { return Vector2(a.x / b.x, a.y / b.y); }
Vector2 operator*(Vector2 a, float scalar) { return Vector2(a.x * scalar, a.y * scalar); }
Vector2 operator/(Vector2 a, float scalar) { return Vector2(a.x / scalar, a.y / scalar); }

// including stream output
ostream& operator<<(ostream& stream, Vector2 v)
{
	stream << "(" << v.x << ", " << v.y << ")";
	return stream;
}

// get the magnitude of a Vector2
float Vector2::magnitude()
{
	return sqrt((x * x) + (y * y));
}

// get the distance between two Vector2 points
float Vector2::distance(Vector2 other)
{
	return (other - *this).magnitude();
}

// initialise the Vector2
Vector2::Vector2(float _x, float _y)
{
	x = _x;
	y = _y;
}

// get the distance between points, by just calling the Vector2 method
float GetDistanceBetweenPoints(Vector2 a, Vector2 b)
{
	return a.distance(b);
}