#include "Game.h"
#include "Creature.h"
#include "Player.h"
#include "Monster.h"
#include <iostream>

std::string Game::getPlayerName()
{
	std::cout << "Enter your name: "; std::string playerName; std::getline(std::cin >> std::ws, playerName);
	return playerName;
}

Game::Game() : m_player{ getPlayerName() }
{
	std::cout << "Welcome, " << m_player.getName() << ".\n";
	std::cout << m_player << '\n';

	playGame();

	if (m_player.hasWon())
	{
		std::cout << "You reached level 20 and won!\nGame finished with " << m_player.getHealth() << " health and " <<  m_player.getGold() << " gold.\n";
	}
	else
	{
		std::cout << "You died at level " << m_player.getLevel() << " with " << m_player.getGold() << " gold.\nBetter luck next time!\n\n";
	}

}

bool Game::startGame()
{
	std::cout << "Start Game (y/n): ";
	char choice;
	while (true)
	{
		std::cin >> choice;
		switch (choice)
		{
		case 'y':
			return true;
		case 'n':
			return false;
		default:
			std::cout << "Invalid input. Please try again\n";
		}
	}
}

void attemptEscape(Player& player, Monster& monster, bool& playerFlees)
{
	bool escaped{ static_cast<bool>(getRandomNumber(0,1)) };
	if (escaped)
	{
		std::cout << "You successfully fled.\n";
		playerFlees = true;
	}
	else
	{
		std::cout << "You failed to flee.\n";
		std::cout << "The " << monster.getName() << " hit you for " << monster.getDamage() << " damage!\n";
		player.reduceHealth(monster.getDamage());
	}
}

void fightMonster(Player& player, Monster& monster)
{
	std::cout << "You hit the " << monster.getName() << " for " << player.getDamage() << " damage.\n";
	monster.reduceHealth(player.getDamage());
	if (!monster.isDead())
	{
		std::cout << "The " << monster.getName() << " hit you for " << monster.getDamage() << " damage.\n";
		player.reduceHealth(monster.getDamage());
	}
}

void battleMonster(Player& player)
{
	Monster monster{ Monster::getRandomMonster() };
	std::cout << "You have encountered a " << monster.getName() << " (" << monster.getSymbol() << ").\n";
	bool playerFlees = false;
	while (!player.isDead() && !monster.isDead() && !playerFlees)
	{
		std::cout << "\nYou have " << player.getHealth() << " health and " << player.getDamage() << " strength, the " << monster.getName() << " has " << monster.getHealth() << " health.\n";
		std::cout << "Run or Fight (r/f): ";
		char choice;
		while (true)
		{
			std::cin >> choice;
			switch (choice)
			{
			case 'r':
				attemptEscape(player, monster, playerFlees);
				break;
			case 'f':
				fightMonster(player, monster);
				break;
			default:
				std::cout << "Invalid option. Please try again\n";
				continue;
			}
			break;
		}
	}

	if (monster.isDead())
	{
		std::cout << "You killed the " << monster.getName() << "!\n\n";
		player.levelUp(); std::cout << "You are now level " << player.getLevel() << ".\n";
		player.addGold(monster.getGold()); std::cout << "You received " << monster.getGold() << " gold!\n\n";

		if (Potion::potionDrop())
		{
			std::cout << "You found a potion! Drink it? (y/n): ";
			char choice;
			while (true)
			{
				std::cin >> choice;
				switch (choice)
				{
				case 'y':
					player.drinkPotion();
					return;
				case 'n':
					std::cout << "The potion was discarded\n";
					return;
				default:
					std::cout << "Invalid option. Please try again!\n";
				}
			}
		}
	}
}

void Game::playGame()
{
	while (!m_player.isDead() && !m_player.hasWon())
	{
		battleMonster(m_player);
	}
}