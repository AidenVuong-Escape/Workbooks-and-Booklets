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

When running this code would output
```
shields 0, engines 2.5, armed true, plating 46, class F
```

which means shieldStrength was uninitialised. 

rewriting all five declarations using brace initialisation would look like this:
```c++
int shieldStrength{ 0 };
float enginePower{ 2.5f };
bool weaponsArmed{ true };
int hullPlating{ 46 };
char shipClass{ 'F' };
```

Refuses to compile under braces: hullPlating{ 45.8 }. The compiler's word is narrowing (double > int would lose the .8).
The quieter one: enginePower = 2.5. 2.5 is a double and gets converted to float. Write 2.5f.
Debug vs Release: Debug gives -858993460 every time. Release gives whatever was left in memory, often 0 but not reliably. That's why it's dangerous: it looks fine in the build that ships.

Problem 3 - The status readout (completion) - Extra

```c++
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
```

>10 means right-aligned, 10 wide. >8.2f means right-aligned, 8 wide, 2 decimals.
Fuel: 0.6237 × 100 = 62.37.
Mass has to be 'long long' because 4,200,000,000 is bigger than int's max (2,147,483,647).
The Mass row won't line up: the number is 10 characters in an 8-wide field. std::format widens the field rather than cutting your number off, so that's expected.

Problem 4 - Predict, then measure (prediction) - Core

```
Type	      Bytes	   Largest value
bool	      1	       true
char	      1	       127
short	      2	       32,767
int	          4	       2,147,483,647
long long	  8	       9,223,372,036,854,775,807
float	      4	       ≈ 3.4 × 10³⁸
std::uint8_t  1	       255
std::int32_t  4	       2,147,483,647
```

The Bool value surprised me the most because it only holds a true or false value, even though it takes up a byte of memory. I expected it to be smaller, but it needs to be a byte so that it can be addressed in memory.
A long long stores a number the plain way: every one of its 64 bits goes towards counting, so it can hold every whole number from about −9.2 quintillion to +9.2 quintillion, one after another with no gaps.

A float stores a number more like scientific notation. Instead of writing out 300,000,000 in full, you'd write 3 × 10⁸: a few significant digits, plus a number saying how far to move the decimal point. A float splits its 32 bits the same way:
some bits hold the digits (about 7 significant digits' worth)
some bits hold the scale (how big or small the number is)

long long counts every whole number in a smaller range exactly, while float covers a much bigger range approximately.
What does it give up in exchange? It gives up precision, because it only keeps about 7 significant digits, so large values get rounded and many numbers in its range can't be stored exactly.

Problem 5 - The shield percentage bug (debugging) - Core

1. both variables are int, so the division is integer division. 73 / 120 becomes 0 before the result is stored in the float.
2. While running the given code, the output would be:
```
Shields at 0.0%
```
to fix this, we can cast one of the variables to float before the division. For example:
```c++
float fraction = static_cast<float>(currentShields) / maximumShields;
```
Without the cast, would look like this:
```c++
float percentage = currentShields * 100.0f / maximumShields;
```
Both give 60.8%.

I would prefer to use the first method with the cast because it makes it clear that we are intentionally converting the integer to a float for the purpose of accurate division. It also avoids any potential confusion about the order of operations and ensures that the division is performed in floating-point arithmetic rather than integer arithmetic.

Problem 6 - Name the numbers (refactoring) - Extra

1. Each unexplained number becomes a constexpr constant above the function:
```c++
constexpr int PointsPerEnemy{ 150 };
constexpr int PointsPerWave{ 1000 };
constexpr int PointsPerSecondRemaining{ 25 };
constexpr int RankAThreshold{ 5000 };
```

2.
```c++
constexpr int MaximumEnemies{ 40 };
constexpr int MaximumWaves{ 5 };
constexpr int MaximumSecondsRemaining{ 90 };

constexpr int PerfectScore{ (MaximumEnemies * PointsPerEnemy)
                          + (MaximumWaves * PointsPerWave)
                          + (MaximumSecondsRemaining * PointsPerSecondRemaining) };
```

3.
```c++
if (score > RankAThreshold)
{
    std::cout << std::format("Score {} of a possible {} — rank A\n", score, PerfectScore);
}
else
{
    std::cout << std::format("Score {} of a possible {} — rank B\n", score, PerfectScore);
}
```

4.
```c++
PointsPerEnemy = 200;
```
Visual Studio underlines it straight away, and building gives an error along the lines of: expression must be a modifiable lvalue
Here's the error from the compiler:
```
C3892: 'PointsPerEnemy': you cannot assign to a variable that is const
```

Problem 7 - The auto audit (judgement) - Extra

1.
```
+-------------------------------+---------+----------------------------------+
| Line                          | Verdict | Write instead                    |
+-------------------------------+---------+----------------------------------+
| auto shipClass{ 'K' };        | Replace | char shipClass{ 'K' };           |
| auto hullPoints{ 250 };       | Replace | int hullPoints{ 250 };           |
| auto shieldRegenRate{ 2 };    | Replace | float shieldRegenRate{ 2.0f };   |
| auto isDocked{ false };       | Replace | bool isDocked{ false };          |
| auto fuelBurn{ 3 / 4 };       | Replace | float fuelBurn{ 3.0f / 4.0f };   |
| auto crewCount{ 12u };        | Replace | int crewCount{ 12 };             |
| auto turnRadius{ 45.0f };     | Replace | float turnRadius{ 45.0f };       |
| auto missileYield{ 1.5 };     | Replace | double missileYield{ 1.5 };      |
+-------------------------------+---------+----------------------------------+
```
fuelBurn would be a bug even with the type written out: 3 / 4 is integer division, which gives 0, not 0.75. Same problem as Problem 5.
shieldRegenRate is caused by auto. It deduces int from 2, but a rate should be fractional, so later maths gets truncated.

Stretch — the disappearing byte - Extra

1.
```c++
std::uint8_t damage{ 200 };
std::cout << "Damage: " << damage << "\n";
```
The first two lines are wrong. You'd expect Damage: 200, but you get a strange symbol instead. this is becausestd::uint8_t is just another name for unsigned char. std::cout sees a char type and prints it as a character, not a number. It looks up which character number 200 is and draws that.
200 draws as ╚
100 draws as d

The value stored is still 200 and 100. Only the way it's printed is wrong. To print the number, use static_cast<int>(damage) or std::format, which prints the number.

2.
The total prints 44, not 300,
```c++
std::uint8_t total{ };
total = damage + armour;
```
Step 1, the addition. C++ can't do arithmetic on types smaller than int, so it first converts (promotes) both values to int. The sum is int + int = 300, which is correct.
Step 2, storing it. total is a uint8_t, which can only hold 0 to 255. Storing 300 in it doesn't fit, so it wraps around, keeping only what's left after subtracting 256:

300 − 256 = 44

3.
Fix this by making total an int instead of a uint8_t. Then it can hold the full sum without wrapping around.
```c++
int total{ damage + armour };
std::cout << "Total: " << total << "\n";   // Total: 300
```
Full Fixed Function:
```c++
void Stretch()
{
    std::uint8_t damage{ 200 };
    std::uint8_t armour{ 100 };

    std::cout << "Damage: " << static_cast<int>(damage) << "\n";
    std::cout << "Armour: " << static_cast<int>(armour) << "\n";

    int total{ damage + armour };
    std::cout << "Total: " << total << "\n";
}
```

Output:
```
Damage: 200
Armour: 100
Total: 300
```