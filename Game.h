#pragma once
#ifndef GAME_H
#define GAME_H
#include "Arena.h"
#include "Predator.h"
#include "Prey.h"

class Game  {
public:
	Game(bool chase) {
		Arena arena(30, 30);
		if (chase) {
			Predator(true);
			P
		}
		
	}
	bool is_over;
	void StartLoop() {
		while (!is_over) {

		}
	}



};
#endif // GAME_H
