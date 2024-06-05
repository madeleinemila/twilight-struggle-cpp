#include <iostream>
#include "random.h"
#include "realign.h"

static void outputRegularRoll(int roll)
{
	std::cout << "Rollbot says the roll is: " << roll << std::endl;
}

int main(int argc, char *argv[])
{
	bool realign{};

	seedRandomness();

	if (argv[1] && strcmp(argv[1], "--realign") == 0)
	{
		realign = true;
	}

	if (realign)
	{
		RealignAdvantage realignAdvantage = parseRealignFlags(argc, argv);
		outputRealignmentResult(realignAdvantage);
	}
	else
	{
		outputRegularRoll(rollDice());
	}

	return 0;
}
