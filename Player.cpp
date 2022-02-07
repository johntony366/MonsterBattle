#include "Player.h"
#include "Potion.h"

Player::Player(const std::string& name) : Creature{ name, '@', 10, 1, 0 }, m_level{ 1 }
{
}

void Player::levelUp()
{
	++m_level; ++m_damage;
}

int Player::getLevel() const
{
	return m_level;
}

bool Player::hasWon() const
{
	return m_level >= 20;
}

void Player::drinkPotion()
{
	Potion potion;
	switch (potion.getType())
	{
	case Potion::Type::health:
		std::cout << "You drank a health potion and your health increased by ";
		int increaseHealth;
		potion.getEffect() == Potion::Effect::large ? increaseHealth = 5 : increaseHealth = 2;
		std::cout << increaseHealth << '\n';
		m_health += increaseHealth;
		break;
	case Potion::Type::strength:
		std::cout << "You drank a strength potion and your strength increased by 1\n";
		++m_damage;
		break;
	case Potion::Type::poison:
		std::cout << "You drank a poison potion and your health decreased by 1\n";
		--m_health;
		break;
	}

}

std::ostream& operator<<(std::ostream& out, const Player& player)
{
	out << "You have " << player.getHealth() << " health and are carrying " << player.getGold() << " gold.";
	return out;
}
