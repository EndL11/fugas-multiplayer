#pragma once
#include <array>
#include <functional>
#include "Hero.hpp"
#include "Player.hpp"

struct ReadyPlayer
{
	Hero hero;
	Player player;
	ReadyPlayer() {};
	ReadyPlayer(Player &t_player, Hero &t_hero): hero(t_hero), player(t_player) {};
	void showInfo() {
		player.showInfo();
		hero.showInfo();
	}
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
	std::array<ReadyPlayer, 5> team() { return this->m_team; }
	int totalHP(){
		int hp = 0;
		for (auto ready_player : m_team) {
			hp += ready_player.hero.hp();
		}
		return hp;
	}
	int totalDamage() {
		int damage = 0;
		for (auto ready_player : m_team) {
			damage += ready_player.hero.damage();
		}
		return damage;
	}

	void Rating(const std::function<void(Player&)>& t_ratingEvent) {
		for (auto ready_player : m_team) {
			std::cout << "Before " << ready_player.player.name() << " rank: " << ready_player.player.rank() << std::endl;
			t_ratingEvent(ready_player.player);
			std::cout << "After " << ready_player.player.name() << " rank: " << ready_player.player.rank() << "\n" << std::endl;
		}
	}
};