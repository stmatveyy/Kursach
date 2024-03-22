#pragma once
#ifndef CRARACTER_H
#define CHARACTER_H
#include "Point2D.h"

class Character : public Point2D {
protected:

	int max_travel_distance;
	int possible_directions;
	
	virtual void Move(int direction) = 0;
	virtual void Move(int direction, int distance) = 0;
};

#endif