#include "Logic.h"

int getRandom(int min, int max) {
	return min + (rand() % (max - min + 1));
}