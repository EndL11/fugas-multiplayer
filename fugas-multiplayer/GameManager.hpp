#pragma once
#include "Session.hpp"
#include "TeamManager.hpp"
#include "Hero.hpp"
#include "PlayerManager.hpp"

class GameManager {
	std::list<Session> m_game_sessions;
	PlayerManager m_pm;
public:
	GameManager() {};
	GameManager(PlayerManager &t_pm): m_pm(t_pm) {};
	~GameManager() {};

	void PerformGameSession( std::list<Hero> &t_heroes) {
		int rate = 25;
		TeamManager team_manager;
		std::list<Player> players = m_pm.list();
		std::list<Hero> heroes = t_heroes;
		//	generating teams
		Team team_one = team_manager.GenerateNewTeam(players, heroes);
		Team team_two = team_manager.GenerateNewTeam(players, heroes);
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
		m_pm.Rating(session.GetWinnerTeam().team(), [rate](Player &t_player) {t_player.plusRank(rate); });
		m_pm.Rating(session.GetLoserTeam().team(), [rate](Player &t_player) {t_player.minusRank(rate); });
	};
};
