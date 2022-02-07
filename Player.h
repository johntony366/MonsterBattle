#pragma once

#include "Creature.h"
#include "Potion.h"
#include <iostream>
#include <string>

class Player: public Creature
{
private:
	int m_level;
public:
	Player(const std::string& name);

	void levelUp(); //Increments level and damage by 1
	int getLevel() const;
	bool hasWon() const;
	void drinkPotion();

	friend std::ostream& operator<<(std::ostream& out, const Player& player);

};

