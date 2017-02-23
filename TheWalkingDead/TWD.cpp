#include <iostream>​
#include <string>
#include <ctime>
#include <string>

enum class Weapon { FISTS, GUN, SHOTGUN, REVOLVER, SNIPER, MACHINE_GUN, MAX};

#define numZombies 10


std::ostream& operator<<(std::ostream& os, Weapon aux) {
	switch (aux){
	case Weapon::FISTS: return os << "fists";
	case Weapon::GUN: return os << "gun";
	case Weapon::SHOTGUN: return os << "shotgun";
	case Weapon::REVOLVER: return os << "revolver";
	case Weapon::SNIPER: return os << "sniper";
	case Weapon::MACHINE_GUN: return os << "machine gun";		
	default:return os << "";
	}
}

class Zombie;

class Player {
public:
	Weapon arma;
	float precision;
	int life;

	void attack(Zombie &);

	bool isAlive() {
		return (life > 0);
	}
	
	Player (): arma(Weapon(rand() % static_cast<int>(Weapon::MAX))),
		precision(rand() % 1 + (rand()%10 * 0.1)), life(rand() % 101)
	{
	};
};

class Zombie {
public:
	int distanceToPlayer;
	float speed;
	float damage;
	int life;

	void attack(Player &p) {
		if (distanceToPlayer <= 0) {
			p.life -= damage;
		}
		else {
			distanceToPlayer--;
		}
	}
	
	bool isAlive() {
		return (life > 0);
	}

	Zombie() : distanceToPlayer(rand() % 181 + 20), speed(rand() % 21 + rand() % 9 * 0.1), damage(rand() % 21 + rand() % 9 * 0.1), life(rand() % 101)
	{
	};
};

void Player::attack(Zombie &z) {
	z.life -= static_cast <float>(arma)*precision;
}


void main() {
	srand(time(nullptr));
	Player player;
	Zombie list[numZombies];
	bool zombiesAreAlive;
	do {
		zombiesAreAlive = false;
		for (int i = 0; i < numZombies; i++) {
			if (list[i].isAlive()) {
				player.attack(list[i]);
				list[i].attack(player);
				zombiesAreAlive = true;
				std::cout << "Zombie [" << i << "]" << std::endl << "        life = " << list[i].life << " distance = " << list[i].distanceToPlayer << " speed = " << list[i].speed << " damage = " << list[i].damage << std::endl;
			}
		}
	} while (player.isAlive() && zombiesAreAlive);
	if (zombiesAreAlive) {
		std::cout << "Has muerto";
	}
	else {
		std::cout << "Estás vivo";
	}
}