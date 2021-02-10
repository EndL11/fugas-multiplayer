#include "GameManager.hpp"
#include "HeroManager.hpp"
#include "PlayerManager.hpp"

int main() {
	srand(time(NULL));
	int players_count, heroes_count;
	PlayerManager pm;
	HeroManager hm;
	std::cout << "Enter count of players: ";
	std::cin >> players_count;
	std::cout << "Enter count of heroes: ";
	std::cin >> heroes_count;
	for (int i = 0; i < players_count; i++) {
		int random_rank = rand() % 100 + 26;
		std::string name = "";
		std::cout << "Enter player name: ";
		std::cin >> name;
		pm.CreatePlayer(i, name, random_rank);
	}
	std::cout << "\n\n";
	for (int i = 0; i < heroes_count; i++) {
		int random_hp = rand() % 100 + 30;
		int random_damage = rand() % 100 + 26;
		std::string name = "";
		std::cout << "Enter hero name: ";
		std::cin >> name;
		hm.CreateHero(i, name, random_hp, random_damage);
	}
	std::cout << "\n\n";
	GameManager gm(pm);
	char answr;
	do {
		gm.PerformGameSession(pm.players(), hm.heroes());
		std::cout << "Session ended --------------------------------------\n\n";
		std::cout << "Want play again? (y/n)\n>: ";
		std::cin >> answr;
	}while (tolower(answr) != 'n');
	return 0;
}