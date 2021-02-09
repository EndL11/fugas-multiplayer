#pragma once
#include <iostream>
#include <string>
class Player{
	int m_id;
	int m_rank;
	std::string m_name;
public:
	Player() {};
	Player(int t_id, std::string t_name, int t_rank): m_id(t_id), m_name(t_name), m_rank(t_rank) {};
	~Player() {
		std::cout << "Player with id: " << this->m_id << " and name: " << m_name << " deleted" << std::endl;
	};
	void plusRank(int t_rank) {
		this->m_rank += t_rank;
	}
	void minusRank(int t_rank) {
		this->m_rank -= t_rank;
	}
	void showInfo() {
		std::cout << "Player info: " << "\nID: " << m_id << "\tName: " << m_name << "\tRank: " << m_rank << "\n\n";
	}
	std::string name() {
		return this->m_name;
	}
	int id() {
		return this->id;
	}
	int rank() {
		return this->rank;
	}
	friend bool operator==(const Player &lplayer, const Player &rplayer) {
		return lplayer.id() == rplayer.id();
	}
};