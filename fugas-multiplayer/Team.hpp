#pragma once
#include <array>
#include <functional>
#include <tuple>
#include "Hero.hpp"
#include "Player.hpp"

class Team {
	std::string m_name;
	std::array<std::tuple<Player, Hero>, 5> m_team;
public:
	Team() {};
	Team(std::string t_name, std::array<std::tuple<Player, Hero>, 5> t_team)
		: m_name(t_name), m_team(t_team)
	{
		std::cout << "Team with name " << t_name << " created." << std::endl;
	};
	~Team() {};
	std::string name() { return this->m_name; }
	const std::array<std::tuple<Player, Hero>, 5> team() { return this->m_team; }

	int totalHP(){
		int hp = 0;
		for (auto ready_player : m_team) {
			hp += std::get<1>(ready_player).hp();
		}
		return hp;
	}
	int totalDamage() {
		int damage = 0;
		for (auto ready_player : m_team) {
			damage += std::get<1>(ready_player).damage();
		}
		return damage;
	}
};