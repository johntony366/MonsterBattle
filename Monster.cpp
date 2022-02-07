#include "Monster.h"
#include "Creature.h"
#include <array>
#include <cstdlib>

int getRandomNumber(int min, int max)
{
	static constexpr double fraction = 1.0 / (RAND_MAX + 1.0);
	return min + static_cast<int>(max - min + 1) * (std::rand() * fraction);
}

Monster::Monster(Type type) : Creature{ getDefaultCreature(type) }
{

}

Monster Monster::getRandomMonster()
{
	int randomNumber = getRandomNumber(0, static_cast<int>(Type::max_types) - 1);
	return { static_cast<Type>(randomNumber) };
}

const Creature& Monster::getDefaultCreature(Type type)
{
	static const std::array<Creature, static_cast<std::size_t>(Type::max_types)> monsterData
	{
		{
			{ "dragon", 'D', 20, 4, 100},
			{ "orc", 'o', 4, 2, 25 },
			{ "slime", 's', 1, 1, 10 }
		}
	};
	return monsterData.at(static_cast<std::size_t>(type));
}
