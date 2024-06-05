#include <iostream>
#include <regex>
#include <string.h>
#include "random.h"
#include "realign.h"

RealignAdvantage parseRealignFlags(int argc, char *argv[])
{
	std::smatch matchesUS{};
	std::smatch matchesUSSR{};
	int advUS = 0;
	int advUSSR = 0;

	for (int i = 2; i < argc; i++)
	{
		if (argv[i])
		{
			std::string str1(argv[i]);

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

	return RealignAdvantage{.US = advUS, .USSR = advUSSR};
}

static void outputStatus(std::string player, int adv, int roll)
{
	std::cout << player << " advantage: " << adv << std::endl;
	std::cout << "🎲 " << player << " rolled: " << roll << std::endl;
}

void outputRealignmentResult(RealignAdvantage realignAdvantage)
{
	int rollUSSR = rollDice();
	outputStatus("USSR", realignAdvantage.USSR, rollUSSR);

	int rollUS = rollDice();
	outputStatus("US", realignAdvantage.US, rollUS);

	int difference = rollUS - rollUSSR + realignAdvantage.US - realignAdvantage.USSR;
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
