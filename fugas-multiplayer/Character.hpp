#pragma once
#include <string>

class Character {
protected:
	int m_id;
	std::string m_name;
public:
	Character() {};
	Character(int t_id, std::string t_name): m_id(t_id), m_name(t_name) {};
	~Character() {};
	std::string name() {
		return this->m_name;
	}
	int id() {
		return this->m_id;
	}
	virtual void showInfo() {};
};