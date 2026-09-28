#include <iostream>
#include <format>

// ... constant declarations go here, above the function ...

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