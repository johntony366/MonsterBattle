#pragma once
#include "Creature.h"
#include "Player.h"
#include "Monster.h"
#include <string>
class Game
{
private:
	Player m_player;
	std::string getPlayerName();
public:
	Game();
	static bool startGame();
	void playGame();
};

