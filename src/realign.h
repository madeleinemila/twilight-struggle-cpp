#pragma once

struct RealignAdvantage
{
	int US;
	int USSR;
};

RealignAdvantage parseRealignFlags(int argc, char *argv[]);

void outputRealignmentResult(RealignAdvantage realignment);
