#pragma once
#ifndef PREY_H
#define PREY_H


#include "Character.h"
#include <random>

class Prey : public Character {
public:
	Prey(bool chosen) {
		max_travel_distance = 1;
		possible_directions = 8;

		if (chosen) {
			x, previous_x = 15;
			y, previous_y = 15;
		}

		else {
			srand(time(0));
			x,previous_x = rand() % 30;
			srand(time(0));
			y,previous_y = rand() % 30;
		}
	}

	void Move(int direction) override {
		switch (direction)
		{
		case 1:
			y -= 1;
			break;

		case 2:
			y -= 1;
			x += 1;
			break;

		case 3:
			x += 1;
			break;

		case 4:
			y += 1;
			x += 1;
			break;

		case 5:
			y += 1;
			break;

		case 6:
			y += 1;
			x -= 1;
			break;

		case 7:
			x -= 1;
			break;

		case 8:
			y -= 1;
			x -= 1;
			break;

		default:
			throw std::runtime_error("ты че вообще дурак");
		}
		previous_x = x;
		previous_y = y;
	}
};
#endif

//         MOVE SET:
//             1
//       8           2
//                    
//     7      ()       3
//                     
//       6           4
//             5