#include <cstdlib>
#include <iostream>
#include <regex>
#include <string.h>
#include <time.h>
#include <unistd.h>

/*

No flag                    -> Rolls one die.
--realign                  -> Rolls a die each for USSR & US and provides difference.
--realign [ us(a)=# | ussr=# ]  -> Rolls a die each for USSR & US and provides difference, factoring in board advantage.

*/

int main(int argc, char *argv[])
{
	bool realign;
	int advUS = 0;
	int advUSSR = 0;
	std::smatch matchesUS;
	std::smatch matchesUSSR;

	for (int i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], "--realign") == 0)
		{
			realign = true;

			if (argv[i + 1])
			{
				std::string str1(argv[i + 1]);

				if (regex_search(str1, matchesUS, std::regex("usa?=(\\d)")))
				{
					advUS = std::stoi(matchesUS[1]);
				}

				if (regex_search(str1, matchesUSSR, std::regex("ussr=(\\d)")))
				{
					advUSSR = std::stoi(matchesUSSR[1]);
				}
			}
		}
	}

	// Use current time and PID as seed for random number generator
	srand((time(NULL) & 0xFFFF) | (getpid() << 16));

	int result = 1 + (rand() % 6);

	if (realign)
	{
		std::cout << "USSR advantage: " << advUSSR << std::endl;
		std::cout << "🎲 USSR rolled: " << result << std::endl;

		int resultUS = 1 + (rand() % 6);
		std::cout << "US advantage:   " << advUS << std::endl;
		std::cout << "🎲 US rolled:   " << resultUS << std::endl;

		int difference = resultUS - result + advUS - advUSSR;
		if (!difference)
		{
			std::cout << "No difference." << std::endl;
		}
		else if (difference < 0)
		{
			std::cout << "🔴 USSR gets to remove " << difference * -1 << " US influence." << std::endl;
		}
		else
		{
			std::cout << "🔵 US gets to remove " << difference << " USSR influence." << std::endl;
		}
	}
	else
	{
		std::cout << "Rollbot says the roll is: " << result << std::endl;
	}
	return 0;
}
