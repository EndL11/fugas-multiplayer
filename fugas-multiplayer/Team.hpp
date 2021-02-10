#pragma once
#include <array>
#include <functional>
#include "Hero.hpp"
#include "Player.hpp"

class ReadyPlayer
{
	Hero m_hero;
	Player m_player;
public:
	ReadyPlayer() {};
	ReadyPlayer(Player t_player, Hero t_hero): m_hero(t_hero), m_player(t_player) {};
	void showInfo() {
		m_player.showInfo();
		m_hero.showInfo();
	}
	Player player() { return this->m_player; }
	Hero hero() { return this->m_hero; }
};

class Team {
	std::string m_name;
	std::array<ReadyPlayer, 5> m_team;
public:
	Team() {};
	Team(std::string t_name, std::array<ReadyPlayer, 5> t_team)
		: m_name(t_name), m_team(t_team)
	{
		std::cout << "Team with name " << t_name << " created." << std::endl;
	};
	~Team() {};
	std::string name() { return this->m_name; }
	const std::array<ReadyPlayer, 5> team() { return this->m_team; }

	int totalHP(){
		int hp = 0;
		for (auto ready_player : m_team) {
			hp += ready_player.hero().hp();
		}
		return hp;
	}
	int totalDamage() {
		int damage = 0;
		for (auto ready_player : m_team) {
			damage += ready_player.hero().damage();
		}
		return damage;
	}
};