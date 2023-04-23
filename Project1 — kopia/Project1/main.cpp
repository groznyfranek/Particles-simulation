#include <SFML/Graphics.hpp>
#include <random>
#include "particle.h"
#include "simulation.h"


int main()
{
	Simulation s(10, 20.f);
	s.run();
	return 0;
}