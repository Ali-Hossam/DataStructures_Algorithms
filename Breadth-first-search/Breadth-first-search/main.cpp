#include "World.h"
#include <iostream>

int main()
{
	World world("Egypt");
	world.addCountry("Palestine", "Egypt");
	world.addCountry("Libya", "Egypt");
	world.addCountry("Sudan", "Egypt");
	world.addCountry("Jordan", "Palestine");
	world.addCountry("Syria", "Palestine");
	world.addCountry("Iraq", "Palestine");
	world.addCountry("Iraq", "Syria");
	world.addCountry("Iraq", "Jordan");
	world.addCountry("Turkey", "Iraq");
	world.addCountry("Turkey", "Syria");

	std::cout << world.search("Turkey");
	return 0;
}