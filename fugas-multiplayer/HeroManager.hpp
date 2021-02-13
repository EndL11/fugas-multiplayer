#pragma once
#include "Hero.hpp"
#include <list>
#include "Manager.hpp"
class HeroManager: public Manager<Hero> {
public:
	HeroManager() {};
	~HeroManager() {};
	void CreateHero(int t_id, std::string t_name, int t_hp, int t_damage) {
		Hero new_hero(t_id, t_name, t_hp, t_damage);
		m_list.push_back(new_hero);
	}
};