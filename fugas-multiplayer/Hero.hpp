#pragma once
#include <iostream>
#include "Character.hpp"
class Hero : public Character{
	int m_hp = 0;
	int m_damage = 0;
public:
	Hero() {};
	Hero(int t_id, std::string t_name, int t_hp, int t_damage)
		: Character(t_id, t_name), m_hp(t_hp), m_damage(t_damage)
	{};
	~Hero() {};
	int hp() {
		return this->m_hp;
	}
	int damage() {
		return this->m_damage;
	}
	void showInfo() {
		std::cout << "Hero info: " << "\nID: " << this->m_id << "\tName: " << this->m_name << "\tHp: " << m_hp << "\tDamage: " << m_damage << "\n\n";
	}
	friend bool operator==(const Hero &lhero, const Hero &rhero) {
		return lhero.m_id == rhero.m_id;
	}
};