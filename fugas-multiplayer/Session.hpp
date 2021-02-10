#pragma once
#include <time.h>
#include "Team.hpp"
class Session {
	time_t m_start_time;
	Team m_team_one;
	Team m_team_two;
	//	1 if win first team, 2 if win second team, 0 if draw
	int m_winner{ 0 };
public:
	Session() {};
	Session(Team &t_team_one, Team &t_team_two)
		: m_start_time(time(0)), m_team_one(t_team_one), m_team_two(t_team_two)
	{};
	~Session() {};
	void CalculateWinner() {
		int hp_one = m_team_one.totalHP();
		int hp_two = m_team_two.totalHP();

		hp_one -= m_team_two.totalDamage();
		hp_two -= m_team_one.totalDamage();

		m_winner = hp_one > hp_two ? 1 : 2;

		if (hp_one == hp_two) { 
			m_winner = 0; 
			std::cout << "Draw!!!" << std::endl;
			return;
		}
		showWinnerMessage();
	}
	Team& GetLoserTeam() {
		if (m_winner == 1) {
			return m_team_two;
		}
		else if (m_winner == 2) {
			return m_team_one;
		}
		std::cout << "Draw!" << std::endl;
		int rand_team = rand() % 3 + 1;
		this->m_winner = rand_team;
		return (rand_team == 1 ? m_team_two : m_team_one);
	}
	Team& GetWinnerTeam() {
		if (m_winner == 1) {
			return m_team_one;
		}
		else if (m_winner == 2) {
			return m_team_two;
		}
		std::cout << "Draw!" << std::endl;
		int rand_team = rand() % 3 + 1;
		this->m_winner = rand_team;
		showWinnerMessage();
		return (rand_team == 2 ? m_team_two : m_team_one);
	}

	void showWinnerMessage() {
		std::cout << "Team " << "'" << (m_winner == 1 ? m_team_one.name() : m_team_two.name()) << "' wins!" << std::endl;
	}
};