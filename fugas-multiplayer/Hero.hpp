#pragma once
#include <iostream>
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
	~Hero() {
		std::cout << "Hero with id: " << m_id << " and name: " << m_name << " deleted" << std::endl;
	};
	int hp() {
		return this->m_hp;
	}
	int damage() {
		return this->m_damage;
	}
	int id() {
		return this->m_id;
	}
	std::string name() {
		return this->m_name;
	}
	void showInfo() {
		std::cout << "Hero info: " << "\nID: " << m_id << "\tName: " << m_name << "\tHp: " << m_hp << "\tDamage: " << m_damage << "\n\n";
	}
	friend bool operator==(const Hero &lhero, const Hero &rhero) {
		return lhero.m_id == rhero.m_id;
	}
};