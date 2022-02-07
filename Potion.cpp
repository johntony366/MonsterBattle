#include "Potion.h"
#include "Monster.h"
#include <cstdlib>
#include <iostream>

bool Potion::potionDrop()
{
	return getRandomNumber(1, 3) == 1; //probability 1/3
}

Potion::Potion() : m_potionType{ static_cast<Type>(getRandomNumber(0, static_cast<int>(Type::max_potion_types) -1)) }, m_potionEffect{ static_cast<Effect>(getRandomNumber(0, static_cast<int>(Effect::max_effects) - 1)) }
{
}

Potion::Type Potion::getType()
{
	return m_potionType;
}

Potion::Effect Potion::getEffect()
{
	return m_potionEffect;
}
