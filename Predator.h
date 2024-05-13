#pragma once
#ifndef PREDATOR_H
#define PREDATOR_H
#include "Character.h"
#include <random>
#include <cassert>

class Predator : public Character {

public:

	Predator() {
		max_travel_distance = 3;
		possible_directions = 4;

	}
	void choose(bool chosen) {
		if (chosen) {
			previous_x = 15;
			x = 15;
			previous_y = 15;
			y = 15;
		}

		else {
			srand(time(0));
			x = rand() % 30;
			previous_x = x;

			srand(time(0));
			y = rand() % 30;
			previous_y = y;
		}
	}

	void Move(int direction) override {};
	void Move(int direction, int distance) override {

		assert(distance <= max_travel_distance);
		if (x >= 30 || x < 0 || y >= 30 || y < 0) {
			x = previous_x;
			y = previous_y;
		}
		else {
			previous_x = x;
			previous_y = y;
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
				break;
			}

		}
		
	}
	void moveTowards(const Point2D& target) {
		int dx = target.GetX() - x;
		int dy = target.GetY() - y;

		// Выбираем направление, основываясь на том, по какой оси наибольшее расстояние до жертвы
		int primaryDirectionX = (dx != 0) ? (dx > 0 ? 2 : 4) : 0;
		int primaryDirectionY = (dy != 0) ? (dy > 0 ? 3 : 1) : 0;

		// Выбираем рандомную дистанцию (1-3)
		static std::random_device rd;
		static std::mt19937 gen(rd());
		static std::uniform_int_distribution<> dis(1, 3);

		int distanceToMove = dis(gen);

		// Если по оси Х дистанция больше, двигаемся только по ней
		if (abs(dx) > abs(dy)) {
			Move(primaryDirectionX, distanceToMove);
		}

		else {
			Move(primaryDirectionY, distanceToMove);
		}
	}

};
#endif
// MOVE SET
//       1
//   4   **   2
//       3