#include <iostream>
#include <format>
#include <limits>
#include <cstdint>

constexpr int MaximumShields{ 120 };
constexpr int MaximumHull{ 200 };

void Problem01()
{
    // ... body lines go here ...
    int currentShields{ 73 };
    int currentHull{ 150 };
    float shieldPercent = static_cast<float>(currentShields) / MaximumShields * 100.0f;
    float hullPercent = static_cast<float>(currentHull) / MaximumHull * 100.0f;
    std::cout << std::format("Shields {:.1f}% Hull {:.1f}%\n", shieldPercent, hullPercent);
}

void Problem02()
{
    int shieldStrength{ 0 };
    float enginePower{ 2.5f };
    bool weaponsArmed{ true };
    int hullPlating{ 46 };
    char shipClass{ 'F' };


    std::cout << std::format("shields {}, engines {}, armed {}, plating {}, class {}\n",
        shieldStrength, enginePower, weaponsArmed, hullPlating, shipClass);

}

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

void Problem04()
{
    std::cout << std::format("bool {} bytes, max {}\n",
        sizeof(bool), std::numeric_limits<bool>::max());
    std::cout << std::format("char {} bytes, max {}\n",
        sizeof(char), static_cast<int>(std::numeric_limits<char>::max()));
    std::cout << std::format("short {} bytes, max {}\n",
        sizeof(short), std::numeric_limits<short>::max());
    std::cout << std::format("int {} bytes, max {}\n",
        sizeof(int), std::numeric_limits<int>::max());
    std::cout << std::format("long long {} bytes, max {}\n",
        sizeof(long long), std::numeric_limits<long long>::max());
    std::cout << std::format("float {} bytes, max {}\n",
        sizeof(float), std::numeric_limits<float>::max());
    std::cout << std::format("uint8_t {} bytes, max {}\n",
        sizeof(std::uint8_t), std::numeric_limits<std::uint8_t>::max());
    std::cout << std::format("int32_t {} bytes, max {}\n",
        sizeof(std::int32_t), std::numeric_limits<std::int32_t>::max());
}

void Problem05()
{
    int currentShields{ 73 };
    int maximumShields{ 120 };
    float fraction = currentShields / maximumShields;
    float percentage = fraction * 100.0f;
    std::cout << std::format("Shields at {:.1f}%\n", percentage);
}

constexpr int PointsPerEnemy{ 150 };
constexpr int PointsPerWave{ 1000 };
constexpr int PointsPerSecondRemaining{ 25 };
constexpr int RankAThreshold{ 5000 };

constexpr int MaximumEnemies{ 40 };
constexpr int MaximumWaves{ 5 };
constexpr int MaximumSecondsRemaining{ 90 };

constexpr int PerfectScore{ (MaximumEnemies * PointsPerEnemy)
                          + (MaximumWaves * PointsPerWave)
                          + (MaximumSecondsRemaining * PointsPerSecondRemaining) };

void Problem06()
{
    int enemiesDestroyed{ 14 };
    int wavesSurvived{ 3 };
    int secondsRemaining{ 47 };

    int score = (enemiesDestroyed * PointsPerEnemy)
        + (wavesSurvived * PointsPerWave)
        + (secondsRemaining * PointsPerSecondRemaining);

    if (score > RankAThreshold)
    {
        std::cout << std::format("Score {} of a possible {} — rank A\n", score, PerfectScore);
    }
    else
    {
        std::cout << std::format("Score {} of a possible {} — rank B\n", score, PerfectScore);
    }
}

void Stretch()
{
    std::uint8_t damage{ 200 };
    std::uint8_t armour{ 100 };

    std::cout << "Damage: " << static_cast<int>(damage) << "\n";
    std::cout << "Armour: " << static_cast<int>(armour) << "\n";

    int total{ damage + armour };
    std::cout << "Total: " << total << "\n";
}

int main()
{
    Problem01();
    Problem02();
    Problem03();
	Problem04();
	Problem05();
	Problem06();
    Stretch();
	return 0;
}