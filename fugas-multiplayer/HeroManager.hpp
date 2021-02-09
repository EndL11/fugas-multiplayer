#pragma once
#include "Hero.hpp"
#include <list>
class HeroManager {
	std::list<Hero> m_heroes;
public:
	HeroManager() {};
	~HeroManager() {};
	Hero CreateHero(int t_id, std::string t_name, int t_hp, int t_damage) {
		Hero new_hero(t_id, t_name, t_hp, t_damage);
		m_heroes.push_back(new_hero);
		return new_hero;
	}
	Hero GetHeroByName(std::string t_name) {
		try {
			for (auto hero : m_heroes) {
				if (hero.name() == t_name) {
					return hero;
				}
			}
			throw "Hero not found";
		}
		catch (std::string e) {
			std::cout << "Error: " << e << std::endl;
		}
	}
	Hero GetHeroById(int t_id) {
		try {
			for (auto hero : m_heroes) {
				if (hero.id() == t_id) {
					return hero;
				}
			}
			throw "Hero not found";
		}
		catch (std::string e) {
			std::cout << "Error: " << e << std::endl;
		}
	}

	void DeleteHero(int t_id) {
		Hero hero = this->GetHeroById(t_id);
		m_heroes.remove(hero);
	}
	void DeleteHero(const Hero &t_hero) {
		m_heroes.remove(t_hero);
	}
	void ShowHeroInfo(int t_id) {
		Hero hero = this->GetHeroById(t_id);
		hero.showInfo();
	};
	void ShowHeroInfo(std::string t_name) {
		Hero hero = this->GetHeroByName(t_name);
		hero.showInfo();
	};
	void ShowHeroInfo(Hero &t_hero) {
		t_hero.showInfo();
	};

	std::list<Hero>& heroes() { return this->m_heroes; }
};