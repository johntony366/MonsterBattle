#pragma once

#include <iostream>
#include <string>

class Creature
{
protected:
	std::string m_name;
	char m_symbol;
	int m_health;
	int m_damage;
	int m_gold;
public:
	Creature(std::string name, char symbol, int health, int dpa, int gold);

	//getters
	const std::string& getName() const;
	char getSymbol() const;
	int getHealth() const;
	int getDamage() const;
	int getGold() const;
	bool isDead() const;

	//setters
	void reduceHealth(int hp);
	void addGold(int gold);


};

