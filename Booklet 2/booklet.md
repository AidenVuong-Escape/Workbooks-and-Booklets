```c++
void Engine::Run()
{
 // Our traditional game loop. `while (running)` - not `while (true)` - so the
 // game can be asked to stop and shut down cleanly (see Lab 4).
 while (running)
 {
 HandleInput();
 Update();
 Render();
 context.present(console);
 }
}
```

The four lines in 'Run()' would continuously update the game via the users inputs and their surroundings. HandleInput would read for user inputs on the keyboard and mouse. Update would update the game world. Render would show the current state of the game. Context.present would show the graphics to the users screen.

Workbook 02 - Types, Variables & Initialisation

Problem 1 - Assemble the status function (ordering) · Warm-up

```c++
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
```

B has no cast. 73/120 is less than 0. C++ does integer division which ignores everything after the decimal point. 
E is uninitialized. This creates the variable but never gives it a value. It stores whatever was in memory at that location.
I is a C-style cast. Though it works, it is not the preferred way to cast in C++. The preferred way is to use `static_cast` or `dynamic_cast` when appropriate.

Solution 2 — Fix the initialisations

```c++
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
```

