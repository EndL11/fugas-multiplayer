#pragma once
#include <list>
#include <stdlib.h>
#include <time.h>
#include "Team.hpp"

template<typename T>
T GetElementFromListByIndex(std::list<T> &list, int t_index) {
	int i = 0;
	for (T element : list) {
		if (i == t_index) {
			return element;
		}
		i++;
	}
}

class TeamManager {
	std::list<Team> m_teams;
public:
	TeamManager() {};
	~TeamManager() {
		std::cout << "Team manager removed" << std::endl;
	};
	Team GenerateNewTeam(std::string t_name, std::array<ReadyPlayer, 5> t_team) {
		Team new_team(t_name, t_team);
		m_teams.push_back(new_team);
		return new_team;
	}
	Team GenerateNewTeam(std::list<Player> &t_players, std::list<Hero> &t_heroes) {
		srand(time(NULL));

		std::string team_name;
		std::array<ReadyPlayer, 5> team;
		for (int i = 0; i < 5; i++) {
			int playerIndex = rand() % t_players.size();
			int heroIndex = rand() % t_heroes.size();

			std::cout << "Player index: " << playerIndex << "\n";
			std::cout << "Hero index: " << heroIndex << "\n\n";

			Player player = GetElementFromListByIndex<Player>(t_players, playerIndex);
			Hero hero = GetElementFromListByIndex<Hero>(t_heroes, heroIndex);

			ReadyPlayer ready_player(player, hero);
			team[i] = ready_player;
		}
		std::cout << "Enter team name: ";
		std::cin >> team_name;
		Team new_team(team_name, team);
		m_teams.push_back(new_team);
		return new_team;
	}
	void GetTeamInfo(Team &t_team) {
		std::cout << "Team " << t_team.name() << std::endl;
		std::cout << "Member list:" << std::endl;
		for (auto ready_player : t_team.team()) {
			ready_player.showInfo();
		}
	}
	void GetTeamInfo(std::string &t_name) {
		for (auto team : m_teams) {
			if (team.name() == t_name) {
				std::cout << "Team " << team.name() << std::endl;
				std::cout << "Member list:" << std::endl;
				for (auto ready_player : team.team()) {
					ready_player.showInfo();
				}
			}
		}
		std::cout << "Team not found!" << std::endl;
	}
};