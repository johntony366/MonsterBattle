#include "Creature.h"
#include "Player.h"
#include "Monster.h"
#include "Game.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>



int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	std::rand();


	while (Game::startGame())
	{
		Game game;
	}
}