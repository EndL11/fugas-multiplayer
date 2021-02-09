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
	~Player() {};
	void plusRank(int t_rank) {
		std::cout << "Player " << m_name << " +" << t_rank << "rank points." << std::endl;
		this->m_rank += t_rank;
	}
	void minusRank(int t_rank) {
		std::cout << "Player " << m_name << " -" << t_rank << "rank points." << std::endl;
		this->m_rank -= t_rank;
	}
	void showInfo() {
		std::cout << "Player info: " << "\nID: " << m_id << "\tName: " << m_name << "\tRank: " << m_rank << "\n";
	}
	std::string name() {
		return this->m_name;
	}
	int id() {
		return this->m_id;
	}
	int rank() {
		return this->m_rank;
	}
	friend bool operator==(const Player &lplayer, const Player &rplayer) {
		return lplayer.m_id == rplayer.m_id;
	}
};