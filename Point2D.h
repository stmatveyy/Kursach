#pragma once
#include <cmath>
#ifndef POINT2D_H
#define POINT2D_H
class Point2D {
protected:
	int x;
	int y;
	int previous_x;
	int previous_y;
public:
	
	int CalculateDistance(Point2D& other) {
		return std::sqrt(pow((other.x - x), 2) + pow((other.y - y), 2));
	}

	int GetX() const { return x; }
	int GetY() const { return y; }

	int GetPreviousX() { return previous_x; }
	int GetPreviuosY() { return previous_y; }
};

#endif