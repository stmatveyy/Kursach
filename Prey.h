#pragma once
#ifndef PREY_H
#define PREY_H


#include "Character.h"
#include <random>

class Prey : public Character {
public:
	Prey() {
		max_travel_distance = 1;
		possible_directions = 8;
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

	void Move(int direction) override {
		previous_x = x;
		previous_y = y;
		if (x >= 30 || x < 0 || y >= 30 || y < 0) {
			x = previous_x;
			y = previous_y;
		}
		else {

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
				break;
			}
		}
	}

	void moveRandomly() {
		if (x >= 30 || x < 0 || y >= 30 || y < 0) {
			x = previous_x;
			y = previous_y;
		}
		else {
			previous_x = x;
			previous_y = y;

			static std::random_device rd;
			static std::mt19937 gen(rd());
			static std::uniform_int_distribution<> dis(0, 7); // 8 возможных направлений, генерируем одно

			int direction = dis(gen);

			switch (direction) {
			case 0: x++; break; // Вправо
			case 1: y++; break; // Вниз
			case 2: x--; break; // Влево
			case 3: y--; break; // Вверх
			case 4: x++; y++; break; // Право-вниз
			case 5: x--; y++; break; // Влево-вниз
			case 6: x--; y--; break; // Влево-вверх
			case 7: x++; y--; break; // Вправо-вверх
			}

		}
		
	}
	void Move(int direction, int distance) override {
		throw std::runtime_error("Нельзя вызвать такой метод");
	};
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