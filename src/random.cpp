#include <cstdlib>
#include <time.h>
#include <unistd.h>
#include "random.h"

void seedRandomness()
{
	// Use current time and PID as seed for random number generator
	unsigned int currentTime = (time(NULL) & 0xFFFF);
	unsigned int pid = static_cast<unsigned int>(getpid()) << 16;
	srand(currentTime | pid);
}

int rollDice()
{
	return 1 + (rand() % 6);
}
