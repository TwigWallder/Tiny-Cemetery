#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int hp = 100;
int mp = 100;
int positionX = 0;
int positionY = 0;
int xP = 5;
int yP = 5;

int choice = 0;
bool running = true;

int main() {
	// MAIN LOOP
	while (running) {
		render();
		rencontre();
		choiceManager();
	}

	printf(ANSI_COLOR_RED"Fermeture du jeu. . .\n"ANSI_COLOR_RESET);
	system("pause");

	return 0;
}

// RENDERING MAP & UI
int render() {
	printf("\n");
	printf("|--Tiny Cemetery--|\n");
	printf("|HP: %d | MP: %d|\n", hp, mp);
	printf("|-----------------|\n");

	// ACTUALISATION DE LA MAP
	for (int y = 0; y < 20; y++) {
		printf("\n");
		for (int x = 0; x < 60; x++) {
			int xOff = 30;
			if (x < xOff) {
				if (x == xP && y == yP) {
					printf(ANSI_COLOR_YELLOW "P"ANSI_COLOR_RESET);
				}
				else if (y < 1 || y == 19 || x == 0 || x == 29) {
					printf(ANSI_COLOR_MAGENTA "|" ANSI_COLOR_RESET);
				}
				else if ((y == 3 && x == 7) || (y == 10 && x == 6)) {
					printf(ANSI_COLOR_RED "M" ANSI_COLOR_RESET);
				}
				else if (y%4 == 0 && x%3 ==0) {
					printf("#");
				}
				else if (y == 5 && x == 10) {
					printf(ANSI_COLOR_MAGENTA "S" ANSI_COLOR_RESET);
				}
				else {
					printf(ANSI_COLOR_GREEN "," ANSI_COLOR_RESET);
				}
			}else if (x > xOff) {
				// INVENTAIRE
				if (y == 0 || y == 19) {
					printf("=");
				}
				if (y == 1 && x == 59) {
					printf("----------Inventory----------");
				}
				if (y == 2 && x == 59) {
					printf("[3]SANDWICH");
				}
				if (y == 4 && x == 59) {
					printf("[1]SILLIEST HELMET");
				}
				if (y == 6 && x == 59) {
					printf("[1]WEIRDLY SWORD");
				}
				if (y == 8 &&x == 59) {
					printf("[1]STINKY ARMOR");
				}
				if (y == 10 && x == 59) {
					printf("[1]WATA");
				}
			}

			
		}
	}
	printf("\n");

	return 0;
}

// MEET NPC
int rencontre() {
	if (positionX == 10 && positionY == 5) {
		printf("Vous rencontrez un shopKeeper\n");
		printf("Mais il ne fait rien '-'\n");
	}

	if (positionX == 7 && positionY == 3) {
		printf(ANSI_COLOR_RED"Vous rencontrez un monstre\n"ANSI_COLOR_RESET);
		hp -= 5;

	}
	return 0;
}

int choiceManager() {
	printf("Que vous voulez faire?\n");
	printf(ANSI_COLOR_YELLOW"[1] Position, [2] Inventaire, [3] Quit\n"ANSI_COLOR_RESET);

	scanf_s("%d", &choice);

	switch (choice) {
	case 1:
		printf("Ecrit votre position X et Y:\n");
		scanf_s("%d", &positionX);
		scanf_s("%d", &positionY);
		printf(ANSI_COLOR_YELLOW"Position actualiser !"ANSI_COLOR_RESET);
		xP = positionX;
		yP = positionY;
		break;
	case 2:
		printf(ANSI_COLOR_YELLOW"Flemme .-.\n"ANSI_COLOR_RESET);
		break;
	case 3:
		running = false;
		break;
	}
	return 0;
}
