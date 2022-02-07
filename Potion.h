#pragma once
#include "Player.h"

class Potion
{
public:
	enum class Type
	{
		health,
		strength,
		poison,
		max_potion_types
	};

	enum class Effect
	{
		small,
		medium,
		large,
		max_effects
	};
private:
	Type m_potionType;
	Effect m_potionEffect;

public:
	static bool potionDrop();
	Potion();
	Type getType();
	Effect getEffect();
	
};

