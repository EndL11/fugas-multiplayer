#pragma once
#include <list>
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
	Team GenerateNewTeam(std::string t_name, std::array<std::tuple<Player, Hero>, 5> t_team) {
		Team new_team(t_name, t_team);
		m_teams.push_back(new_team);
		return new_team;
	}
	Team GenerateNewTeam(std::list<Player> &t_players, std::list<Hero> &t_heroes) {
		std::array<int, 5> players_ids;
		std::array<int, 5> heroes_ids;
		players_ids.fill(-1);
		heroes_ids.fill(-1);

		std::string team_name;
		std::array<std::tuple<Player, Hero>, 5> team;

		for (int i = 0; i < 5;) {
			int playerIndex = rand() % t_players.size();
			Player player = GetElementFromListByIndex<Player>(t_players, playerIndex);

			bool already_added = false;
			do {
				for (auto id : players_ids) {
					if (id == player.id()) {
						already_added = true;
						break;
					}
				}
				playerIndex = rand() % t_players.size();
			} while (already_added);

			already_added = false;
			int heroIndex = rand() % t_heroes.size();
			Hero hero = GetElementFromListByIndex<Hero>(t_heroes, heroIndex);
			do {
				for (auto id : heroes_ids) {
					if (id == hero.id()) {
						already_added = true;
						break;
					}
				}
				heroIndex = rand() % t_heroes.size();
			} while (already_added);			

			t_players.remove(player);
			t_heroes.remove(hero);
			std::tuple<Player, Hero> ready_player = std::make_tuple(player, hero);
			team[i] = ready_player;
			players_ids[i] = player.id();
			heroes_ids[i] = hero.id();
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