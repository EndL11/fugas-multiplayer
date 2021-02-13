#pragma once
#include <iostream>
#include "Character.hpp"
class Player : public Character{
	int m_rank;
public:
	Player() {};
	Player(int t_id, std::string t_name, int t_rank): Character(t_id, t_name), m_rank(t_rank) {};
	~Player() {};
	Player plusRank(int t_rank) {
		std::cout << "Player " << this->m_name << " +" << t_rank << "rank points." << std::endl;
		this->m_rank += t_rank;
		return *this;
	}
	Player minusRank(int t_rank) {
		std::cout << "Player " << this->m_name << " -" << t_rank << "rank points." << std::endl;
		this->m_rank -= t_rank;
		return *this;
	}
	void showInfo() {
		std::cout << "Player info: " << "\nID: " << this->m_id << "\tName: " << this->m_name << "\tRank: " << m_rank << "\n";
	}
	int rank() {
		return m_rank;
	}
	friend bool operator==(const Player &lplayer, const Player &rplayer) {
		return lplayer.m_id == rplayer.m_id;
	}
};