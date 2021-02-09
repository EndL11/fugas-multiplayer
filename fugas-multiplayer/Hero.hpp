#pragma once
#include <string>
class Hero {
	std::string m_name;
	int m_id;
	int m_hp;
	int m_damage;
public:
	Hero() {};
	Hero(int t_id, std::string t_name, int t_hp, int t_damage)
		: m_id(t_id), m_name(t_name), m_hp(t_hp), m_damage(t_damage)
	{};
	~Hero() {};
	int hp() {
		return this->hp;
	}
	int damage() {
		return this->damage;
	}
};