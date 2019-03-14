#include <random>
#include <iostream>
#include <ctime>

static std::mt19937 mt(time(0));

void randomxy(int minX, int maxX, int minY, int maxY, int &x, int &y) 
{
	auto xGenerator = std::uniform_int_distribution<int>(minX, maxX);
	x = xGenerator(mt);

	auto yGenerator = std::uniform_int_distribution<int>(minY, maxY);
	y = yGenerator(mt);
}
