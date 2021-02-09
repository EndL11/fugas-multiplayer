#pragma once
#include "Session.hpp"
#include "TeamManager.hpp"
#include "Hero.hpp"
#include "Player.hpp"

class GameManager {
	std::list<Session> m_game_sessions;
public:
	GameManager() {};
	~GameManager() {};

	void PerformGameSession(std::list<Player> &t_players, std::list<Hero> &t_heroes) {
		std::cout << "Players Count: " << t_players.size() << std::endl;
		std::cout << "Heroes Count: " << t_heroes.size() << std::endl;
		int rate = 25;
		TeamManager team_manager;
		//	generating teams
		Team team_one = team_manager.GenerateNewTeam(t_players, t_heroes);
		Team team_two = team_manager.GenerateNewTeam(t_players, t_heroes);
		//	showing each team info
		team_manager.GetTeamInfo(team_one);
		team_manager.GetTeamInfo(team_two);
		//	creating session
		Session session(team_one, team_two);
		//	calculating winner
		session.CalculateWinner();
		//	saving session
		m_game_sessions.push_back(session);
		//	changing players rank
		session.GetWinnerTeam().Rating([rate](Player &t_player) {t_player.plusRank(rate); });
		session.GetLoserTeam().Rating([rate](Player &t_player) {t_player.minusRank(rate); });
	};
};
