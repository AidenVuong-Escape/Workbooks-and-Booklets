#include <iostream>
#include <format>

void Problem03()
{
	char callsign{ 'K' };
	int torpedoes{ 6 };
	float fuelFraction{ 0.6237f };
	bool autopilotEngaged{ false };
	long long massInKilograms{ 4200000000LL };

	std::cout << std::format("|{:>10} |{:>8} |\n", "Callsign", callsign);
	std::cout << std::format("|{:>10} |{:>8} |\n", "Torpedoes", torpedoes);
	std::cout << std::format("|{:>10} |{:>8.2f} |\n", "Fuel", fuelFraction * 100.0f);
	std::cout << std::format("|{:>10} |{:>8} |\n", "Autopilot", autopilotEngaged);
	std::cout << std::format("|{:>10} |{:>8} |\n", "Mass", massInKilograms);
}