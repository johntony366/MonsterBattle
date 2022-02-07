#pragma once

#include "Creature.h"

class Monster : public Creature
{
public:
	enum class Type
	{
		dragon,
		orc,
		slime,
		max_types
	};
private:
	static const Creature& getDefaultCreature(Type type);
public:
	Monster(Type type);
	static Monster getRandomMonster();
};

int getRandomNumber(int min, int max);
