#include "GameManager.hpp"
#include "HeroManager.hpp"
#include "PlayerManager.hpp"

int main() {
	srand(time(NULL));
	int players_count = 0, heroes_count = 0;
	PlayerManager pm;
	HeroManager hm;

	while (players_count < 10) {
		std::cout << "Enter count of players: ";
		std::cin >> players_count;
	}
	while (heroes_count < 10) {
		std::cout << "Enter count of heroes: ";
		std::cin >> heroes_count;
	}

	for (int i = 0; i < players_count; i++) {
		int random_rank = rand() % 100 + 26;
		std::string name = "Player_" + std::to_string(i + 1);
		pm.CreatePlayer(i, name, random_rank);
	}
	for (int i = 0; i < heroes_count; i++) {
		int random_hp = rand() % 100 + 30;
		int random_damage = rand() % 100 + 26;
		std::string name = "Hero_" + std::to_string(i + 1);
		hm.CreateHero(i, name, random_hp, random_damage);
	}

	GameManager gm(pm);
	char answr;

	do {
		gm.PerformGameSession(hm.list());
		std::cout << "Session ended --------------------------------------\n\n";
		std::cout << "Want play again? (y/n)\n>: ";
		std::cin >> answr;
	}while (tolower(answr) != 'n');
	
	return 0;
}