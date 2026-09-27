```c++

void Engine::Run()

{

&#x20;// Our traditional game loop. `while (running)` - not `while (true)` - so the

&#x20;// game can be asked to stop and shut down cleanly (see Lab 4).

&#x20;while (running)

&#x20;{

&#x20;HandleInput();

&#x20;Update();

&#x20;Render();

&#x20;context.present(console);

&#x20;}

}

```



The four lines in 'Run()' would continuously update the game via the users inputs and their surroundings. HandleInput would read for user inputs on the keyboard and mouse. Update would update the game world. Render would show the current state of the game. Context.present would show the graphics to the users screen.



Workbook 02 - Types, Variables \& Initialisation



Problem 1 - Assemble the status function (ordering) · Warm-up



```c++

// ... constant declarations go here, above the function ...



constexpr int MaximumShields{ 120 };

constexpr int MaximumHull{ 200 };



void Problem01()

{

&#x20;   // ... body lines go here ...

&#x20;   int currentShields{ 73 };

&#x20;   int currentHull{ 150 };

&#x20;   float shieldPercent = static\_cast<float>(currentShields) / MaximumShields \* 100.0f;

&#x20;   float hullPercent = static\_cast<float>(currentHull) / MaximumHull \* 100.0f;

&#x20;   std::cout << std::format("Shields {:.1f}% Hull {:.1f}%\\n", shieldPercent, hullPercent);

}

```



B has no cast. 73/120 is less than 0. C++ does integer division which ignores everything after the decimal point. 

E is uninitialized. This creates the variable but never gives it a value. It stores whatever was in memory at that location.

I is a C-style cast. Though it works, it is not the preferred way to cast in C++. The preferred way is to use `static\_cast` or `dynamic\_cast` when appropriate.



Solution 2 — Fix the initialisations



```c++

void Problem02()

{

&#x20;   int shieldStrength{ 0 };

&#x20;   float enginePower{ 2.5f };

&#x20;   bool weaponsArmed{ true };

&#x20;   int hullPlating{ 46 };

&#x20;   char shipClass{ 'F' };



&#x20;   std::cout << std::format("shields {}, engines {}, armed {}, plating {}, class {}\\n",

&#x20;       shieldStrength, enginePower, weaponsArmed, hullPlating, shipClass);

}

```





