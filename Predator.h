#pragma once
#ifndef PREDATOR_H
#define PREDATOR_H
#include "Character.h"
#include <random>
#include <cassert>

class Predator : public Character {

public:

	Predator(bool chosen) {
		max_travel_distance = 3;
		possible_directions = 4;

		if (chosen) {
			previous_x = 15;
			x = 15;
			previous_y = 15;
			y = 15;
		}

		else {
			srand(time(0));
			previous_x = rand() % 30;
			x = rand() % 30;
			srand(time(0));
			previous_y = rand() % 30;
			y = rand() % 30;
		}
	}
	void Move(int direction) override {};
	void Move(int direction, int distance) override {
		previous_x = x;
		previous_y = y;
		assert(distance <= max_travel_distance);
		switch (direction)
		{
		case 1:
			y -= distance;
			break;
		case 2:
			x += distance;
			break;
		case 3:
			y += distance;

			break;
		case 4:
			x -= distance;
			break;

		default:
			throw std::runtime_error("ты че дурень");
		}

	}


};
#endif
// MOVE SET
//       1
//   3   **   2
//       4