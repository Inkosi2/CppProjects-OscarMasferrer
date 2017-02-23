#include <iostream>
#include <string>
#include <stdbool.h>
#include <time.h>
using namespace std;

enum EnemyType{zombie, vampire, ghost, whitch};

string lista[10] = {"Pepe", "Juan", "Manolo", "Godofredo", "Idroj", "Albert", "Antxel", "Bea", "Pedro", "Merienda"};

const int numEnemigos = 5;

struct Enemy
{
	EnemyType type;
	string name;
	int health;
};

bool iguales(Enemy enemy1, Enemy enemy2) {

	if (enemy1.type == enemy2.type && enemy1.name == enemy2.name) {
		return true;
	}
	else {
		return false;
	}

}

bool operator == (Enemy enemy1, Enemy enemy2) {
	
	if (enemy1.type == enemy2.type && enemy1.name == enemy2.name) {
		return true;
	}
	else {
		return false;
	}

}

Enemy CreateRandomEnemy() {
	Enemy aux;
	aux.health = rand() % 101; //vida de 0 a 100
	int aux2 = rand() % 4;
	switch (aux2)
	{
	case (0):
		aux.type = zombie;
		break;
	case (1):
		aux.type = vampire;
		break;
	case(2) :
		aux.type = ghost;
		break;
	case(3):
		aux.type = whitch;
		break;
	default:
		break;
	}
	aux.name = lista[rand() % 10];
	return aux;
}

void main() {
	srand(time(NULL));
	Enemy lista[numEnemigos];
	Enemy aux;
	for (int i = 0; i < numEnemigos; i++) {
		lista[i] = CreateRandomEnemy();
		for (int j = 0; j < numEnemigos; j++){
			if (i == j) {
				continue;
			}
			else {
				if (lista[i] == lista[j]) {
					i--;
					break;
				}
			}
		}
	}
	for (int k = 0; k < numEnemigos; k++) {
		cout << lista[k].name << " is a " << lista[k].type << " whose health is " << lista[k].health << endl;
	}
}