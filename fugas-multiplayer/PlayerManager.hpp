#pragma once
#include <list>
#include "Player.hpp"
#include "Team.hpp"
#include "Manager.hpp"
class PlayerManager : public Manager<Player>{
public:
	PlayerManager() {};
	PlayerManager(PlayerManager &t_pm) {
		this->m_list = t_pm.m_list;
	};
	~PlayerManager() {};

	void CreatePlayer(int t_id, std::string t_name, int t_rank) {
		Player new_player(t_id, t_name, t_rank);
		m_list.push_back(new_player);
	}	

	void Rating(const std::array<std::tuple<Player, Hero>, 5> &t_team, const std::function<void(Player&)>& t_ratingEvent) {
		for (auto ready_player : t_team) {
			Player& tmp = GetById(std::get<0>(ready_player).id());
			t_ratingEvent(tmp);
		}
	}
};