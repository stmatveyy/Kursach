#include <iostream>
#include <conio.h>
#include "Prey.h"
#include "Prey.h"
#include "Arena.h"
#include "Console_utils.h"


int main()
{

	Arena arena(30, 30);
	Predator predator;
	Prey prey;
	unsigned int play_choice;
	char dir_choice = ' ';
	bool game_over = false;
	unsigned int distance;
	std::cout << "The Chase game.\n Choose your player.\n 1 --- Predator 2 --- Prey\n"; std::cin >> play_choice;

	switch (play_choice)
	{
	case 1:

		predator.choose(true);
		prey.choose(false);
		arena.Update(predator, prey);
		setCursorPosition(0, 0);
		arena.Draw();

		while (!game_over)
		{
			dir_choice = _getch();
			switch (dir_choice)
			{
			case 'w': dir_choice = 1;break; 
			case 'd': dir_choice = 2; break; 
			case 'x': dir_choice = 3; break;
			case 'a': dir_choice = 4; break;
			default: break;
			}
			setCursorPosition(35, 35);
			std::cout << "Distance: "; std::cin >> distance;

			predator.Move(dir_choice, distance);
			
			setCursorPosition(0, 0);
			prey.moveRandomly();
			arena.Update(predator, prey);
			arena.Draw();
			game_over = predator.CalculateDistance(prey) < 2.0;
		}
		setCursorPosition(0, 0);
		std::cout << "You win!";

	case 2:

		predator.choose(false);
		prey.choose(true);
		arena.Update(predator, prey);
		setCursorPosition(0, 0);
		arena.Draw();

		while (!game_over)
		{
			dir_choice = _getch();
			switch (dir_choice)
			{
			case 'w': dir_choice = 1; break;
			case 'e': dir_choice = 2; break;
			case 'd': dir_choice = 3; break;
			case 'c': dir_choice = 4; break;
			case 'x': dir_choice = 5; break;
			case 'z': dir_choice = 6; break;
			case 'a': dir_choice = 7; break;
			case 'q': dir_choice = 8; break;
			default: break;
			}

			prey.Move(dir_choice);

			
			predator.moveTowards(prey);
			setCursorPosition(0, 0);
			arena.Update(predator, prey);
			arena.Draw();
			game_over = predator.CalculateDistance(prey) < 2.0;
		}
		setCursorPosition(0, 0);
		std::cout << "You lose!";
	default:
		break;
	}
}
