#pragma once
#include <list>
#include <vector>
#include "Team.hpp"

class TeamManager {
	std::list<Team> m_teams;
public:
	TeamManager() {};
	~TeamManager() {
		std::cout << "Team manager removed" << std::endl;
	};
	Team GenerateNewTeam(std::string t_name, std::array<std::tuple<Player, Hero>, 5> t_team) {
		Team new_team(t_name, t_team);
		m_teams.push_back(new_team);
		return new_team;
	}
	Team GenerateNewTeam(std::vector<Player> &t_players, std::vector<Hero> &t_heroes) {
		std::string team_name;
		std::array<std::tuple<Player, Hero>, 5> team;

		for (int i = 0; i < 5;) {
			int randomPlayerIndex = rand() % t_players.size();
			int randomHeroIndex = rand() % t_heroes.size();

			std::tuple<Player, Hero> ready_player = std::make_tuple(t_players[randomPlayerIndex], t_heroes[randomHeroIndex]);

			t_players.erase(t_players.begin() + randomPlayerIndex, t_players.begin() + randomPlayerIndex + 1);
			t_heroes.erase(t_heroes.begin() + randomHeroIndex, t_heroes.begin() + randomHeroIndex + 1);

			team[i] = ready_player;
			i++;
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
			std::get<0>(ready_player).showInfo();
			std::get<1>(ready_player).showInfo();
		}
	}
	void GetTeamInfo(std::string &t_name) {
		for (auto team : m_teams) {
			if (team.name() == t_name) {
				std::cout << "Team " << team.name() << std::endl;
				std::cout << "Member list:" << std::endl;
				for (auto ready_player : team.team()) {
					std::get<0>(ready_player).showInfo();
					std::get<1>(ready_player).showInfo();
				}
			}
		}
		std::cout << "Team not found!" << std::endl;
	}
};