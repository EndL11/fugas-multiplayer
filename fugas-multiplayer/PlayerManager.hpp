#pragma once
#include <list>
#include "Player.hpp"
#include "Team.hpp"
class PlayerManager {
	std::list<Player> m_players;
public:
	PlayerManager() {};
	PlayerManager(PlayerManager &t_pm) {
		this->m_players = t_pm.m_players;
	};
	~PlayerManager() {};
	Player CreatePlayer(int t_id, std::string t_name, int t_rank) {
		Player new_player(t_id, t_name, t_rank);
		m_players.push_back(new_player);
		return new_player;
	}
	Player GetPlayerByName(std::string t_name) {
		try {
			for (auto player : m_players) {
				if (player.name() == t_name) {
					return player;
				}
			}
			throw "Player not found";
		}
		catch (std::string e) {
			std::cout << "Error: " << e << std::endl;
		}
	}
	Player& GetPlayerById(int t_id) {
		try {
			for (auto &player : this->m_players) {
				if (player.id() == t_id) {
					return player;
				}
			}
			throw 1;
		}
		catch (int e) {
			std::cout << "Error: " << e << std::endl;
		}
	}

	void DeletePlayer(int t_id) {
		Player player = this->GetPlayerById(t_id);
		m_players.remove(player);
	}
	void DeletePlayer(const Player &t_player) {
		m_players.remove(t_player);
	}
	void ShowPlayerInfo(int t_id) {
		Player player = this->GetPlayerById(t_id);
		player.showInfo();
	};
	void ShowPlayerInfo(std::string t_name) {
		Player player = this->GetPlayerByName(t_name);
		player.showInfo();
	};
	void ShowPlayerInfo(Player &t_player) {
		t_player.showInfo();
	};

	void Rating(const std::array<ReadyPlayer, 5> &t_team, const std::function<void(Player&)>& t_ratingEvent) {
		for (auto ready_player : t_team) {
			Player& tmp_player = GetPlayerById(ready_player.player().id());
			t_ratingEvent(tmp_player);
		}
	}

	std::list<Player>& players() { return this->m_players; }
};