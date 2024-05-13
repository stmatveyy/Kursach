#pragma once
#ifndef ARENA_H
#define ARENA_H
#include <vector>
#include <iomanip>
#include "Predator.h"
#include "Prey.h"
#include <iostream>
#include "Console_utils.h"

class Arena {
private:

	unsigned int width;
	unsigned int height;
	char*** data;

	char predator_sprite[3];
	char prey_sprite[3];
	char empty_sprite[3];

	void DrawHorisontal() {
		for (unsigned int j = 0; j < width * 3 + 2; ++j) {
			if (j == 0) {
				std::cout << "    ";
			}
			std::cout << '~';
		}
	}

public:

	Arena() : width(30), height(30), predator_sprite("**"), prey_sprite("()"), empty_sprite("--") {

		data = new char** [height];
		for (unsigned int i = 0; i < height; ++i) {
			data[i] = new char* [width];
			for (unsigned int j = 0; j < width; ++j) {
				data[i][j] = new char[3];
			}
		}

		for (unsigned int i = 0; i < height; ++i) {
			for (unsigned int j = 0; j < width; ++j) {
				for (unsigned int k = 0; k < 2; ++k) {
					data[i][j][k] = '--';
				}
			}
		}
	}

	Arena(unsigned int width, unsigned int height) : width(30), height(30), predator_sprite("**"), prey_sprite("()"), empty_sprite("--") {

		data = new char** [height];
		for (unsigned int i = 0; i < height; ++i) {
			data[i] = new char* [width];
			for (unsigned int j = 0; j < width; ++j) {
				data[i][j] = new char[3];
			}
		}

		for (unsigned int i = 0; i < height; ++i) {
			for (unsigned int j = 0; j < width; ++j) {
				for (unsigned int k = 0; k < 2; ++k) {
					data[i][j][k] = '--';
				}
			}
		}
	}

	~Arena() {
		for (unsigned int i = 0; i < height; ++i) {
			for (unsigned int j = 0; j < width; ++j) {
				delete[] data[i][j];
			}
			delete[] data[i];
		}
		delete[] data;
	}

	char**& operator[](unsigned int index) {
		return data[index];
	}


	void Draw() { 

		DrawHorisontal();

		for (unsigned int i = 0; i < height; ++i) {
			std::cout << std::endl;

			for (unsigned int j = 0; j < width; ++j) {
				if (j == 0) {
					std::cout << std::setw(3) <<width - i << "| ";
				}
				for (unsigned int k = 0; k < 2; ++k) {
					std::cout << data[i][j][k];
				}
				std::cout << ' ';
				if (j == width - 1) {
					std::cout << '|';
				}
			}
			
		}
		std::cout << std::endl;
		DrawHorisontal();

		std::cout << std::endl;
		std::cout << "    ";
		for (unsigned int k = 1; k <= width; ++k) {
			std::cout << ' ' << std::setw(2) << k;
		}
		std::cout << std::endl;
	};

	void Update(Predator predator, Prey prey) {

		bool predator_in_bounds = predator.GetX() < 30 && predator.GetY() < 30 && predator.GetX() >0 && predator.GetY() > 0;
		bool prey_in_bounds = prey.GetX() < 30 && prey.GetY() < 30 && prey.GetX() >= 0 && prey.GetY() > 0;

		int predator_prevX = predator.GetPreviousX();
		int predator_prevY = predator.GetPreviuosY();

		int predator_x = predator.GetX();
		int predator_y = predator.GetY(); // Получаем все позиции: и предыдущие, и следующие

		if (predator_in_bounds) {
			UpdateCell(predator_prevX, predator_prevY, empty_sprite);
			UpdateCell(predator_x, predator_y, predator_sprite);
		}
		
		int prey_prevX = prey.GetPreviousX();
		int prey_prevY = prey.GetPreviuosY();

		int prey_x = prey.GetX();
		int prey_y = prey.GetY();
		
		if (prey_in_bounds) {
			UpdateCell(prey_prevX, prey_prevY, empty_sprite);
			UpdateCell(prey_x, prey_y, prey_sprite);
		}
		
	}

	void UpdateCell(int x, int y, char sprite[3]) {
		data[y][x][0] = sprite[0];
		data[y][x][1] = sprite[1];
	}
};


#endif