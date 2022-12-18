#include "Logic.h"

int getRandom(int min, int max) {
	return min + (rand() % (max - min + 1));
}

int getRandom(int max) {
	return rand() % max;
}