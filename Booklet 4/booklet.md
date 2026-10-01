Problem 1 - Assemble the threat assessment (ordering) - Warm-up

1.

```c++
#include <iostream>

void Problem01()
{
    int health{ 30 };
    int enemyCount{ 3 };
    // ... the chain goes here ...
    if (health <= 0)
    {
        std::cout << "Status: dead\n"; 
    }
    else if (health < 25)
    {
        std::cout << "Status: critical\n";
    }
    else if (enemyCount > 2)
    {
        std::cout << "Status: outnumbered\n";
    }
    else
    {
        std::cout << "Status: ready\n";
    }
}

int main()
{
	Problem01();
}
```

I have left out 'else if (enemyCount)', because this line does not mention a comparison operator. The 'else if' statement should include a condition that evaluates to true or false, such as 'else if (enemyCount > 2)'. Without a comparison operator, the code will not compile correctly.
I have left out 'else if (health < 25) std::cout << "Status: critical\n";', because the std::cout statement is not enclosed in braces. In C++, if you have a single statement following an 'if' or 'else if', you can omit the braces, but it is generally good practice to include them for clarity and to avoid errors when adding more statements later.
I have left out 'if (health = 0)', because this is an assignment operation, not a comparison. The correct comparison operator should be '==' to check if health is equal to 0. Using '=' will assign the value 0 to health, which is not the intended behavior and will lead to incorrect logic in the program.

All three would compile fine, but they would not behave as intended. The first issue is a logical error that would prevent the program from correctly assessing the threat level based on the number of enemies. The second issue is a stylistic choice that could lead to confusion or errors in the future. The third issue is a critical logical error that would cause the program to always evaluate health as 0, leading to incorrect status output.

I get
```c++
Status: outnumbered
```
when running the current script.

When setting the health variable to 10, the output will change to:
```c++
Status: critical
```
This is correct because the health is less than 25, which triggers the "critical" status condition.

2.

```c++
void Problem02()
{
    int mana{ 0 };
    int arrows{ 5 };
    bool hasStaff{ true };

    if (mana)
    {
        std::cout << "A: mana\n";
    }

    if (arrows)
    {
        std::cout << "B: arrows\n";
    }

    if (hasStaff == true)
    {
        std::cout << "C: staff\n";
    }

    if (mana = 10)
    {
        std::cout << "D: mana again\n";
    }

    std::cout << std::format("E: mana is {}\n", mana);

    if (arrows > 3)
        std::cout << "F: plenty of arrows\n";
        std::cout << "G: ready\n";

    if (mana > 5 && arrows > 10)
    {
        std::cout << "H: fully equipped\n";
    }
    else if (mana > 5 || arrows > 10)
    {
        std::cout << "I: partly equipped\n";
    }
}
```

The output would be:
```
B: arrows
C: staff
D: mana again
E: mana is 10
F: plenty of arrows
G: ready
I: partly equipped
```
A does not print because the condition `if (mana)` evaluates to false since `mana` is initialized to 0. In C++, any non-zero value is considered true, and zero is considered false.
B prints because 5 converts to true
D prints because mana = 10 assigns 10 and then tests it, so it's always true.
That also explains E showing 10.
G prints no matter what.
H fails because arrows > 10 is false, so I catches it with ||

3.
```c++
void TryToCastSpell(bool knowsSpell, int mana, int manaCost, bool isSilenced)
{
    if (knowsSpell)
    {
        if (!isSilenced)
        {
            if (mana >= manaCost)
            {
                std::cout << "   The spell goes off!\n";
            }
            else
            {
                std::cout << "   Not enough mana.\n";
            }
        }
        else
        {
            std::cout << "   You cannot speak.\n";
        }
    }
    else
    {
        std::cout << "   You do not know that spell.\n";
    }
}
```
This is the guard clause version:
```c++
void TryToCastSpell(bool knowsSpell, int mana, int manaCost, bool isSilenced)
{
    if (!knowsSpell)
    {
        std::cout << "   You do not know that spell.\n";
        return;
    }

    if (isSilenced)
    {
        std::cout << "   You cannot speak.\n";
        return;
    }

    if (mana < manaCost)
    {
        std::cout << "   Not enough mana.\n";
        return;
    }

    std::cout << "   The spell goes off!\n";
}
```

When adding `TryToCastSpell(true, 10, 5, false);` to the main function, the output will be:
```
   The spell goes off!
```
These are all the possible outputs for the function `TryToCastSpell` based on different input parameters:
```c++
    TryToCastSpell(false, 10, 5, false); // You do not know that spell.
    TryToCastSpell(true, 10, 5, true);  // You cannot speak.
    TryToCastSpell(true, 3, 5, false); // Not enough mana.
    TryToCastSpell(true, 5, 5, false); // The spell goes off!
```

            Deepest line	Success line
Original	4	            4
Guarded	    2	            1

The amount of code didn't change, but each failure condition now sits directly beside its own message and ends the function, so the success path reads straight down at the shallowest level without tracking which else belongs to which if.

Problem04

```c++
// TODO 1
enum class DamageType
{
    Physical = 0,
    Fire = 1,
    Ice = 2,
    Poison = 3,
};

// TODO 2
enum class ArmourType
{
    None,
    Leather,
    Chain,
    Plate,
};

// TODO 3
int ApplyResistance(int damage, DamageType type, ArmourType armour)
{
    switch (armour)
    {
    case ArmourType::None:
        return damage;

    case ArmourType::Leather:
        if (type == DamageType::Poison)
            return damage / 2;
        return damage;

    case ArmourType::Chain:
        switch (type)
        {
        case DamageType::Physical: return damage / 2;
        case DamageType::Ice:      return damage * 2;
        default:                   return damage;
        }

    case ArmourType::Plate:
        switch (type)
        {
        case DamageType::Physical: return damage / 2;
        case DamageType::Fire:
        case DamageType::Ice:      return damage * 2;
        default:                   return damage;
        }
    }

    return damage; // unreachable for valid input, but silences "not all paths return"
}

// TODO 4
const char* NameOf(DamageType type)
{
    switch (type)
    {
    case DamageType::Physical: return "physical";
    case DamageType::Fire:     return "fire";
    case DamageType::Ice:      return "ice";
    case DamageType::Poison:   return "poison";
    }
    return "unknown";
}

//main problem04 function
void Problem04()
{
    // TODO 5
    std::cout << std::format("20 {} damage against plate becomes {}\n",
        NameOf(DamageType::Fire),
        ApplyResistance(20, DamageType::Fire, ArmourType::Plate));

    std::cout << std::format("20 {} damage against chain becomes {}\n",
        NameOf(DamageType::Physical),
        ApplyResistance(20, DamageType::Physical, ArmourType::Chain));
}
```
Output:
```
20 fire damage against plate becomes 40
20 physical damage against chain becomes 10
```

problem05

```c++
//problem05
enum class Command { MoveNorth, MoveSouth, Attack, Wait, Quit };

void HandleCommand(Command command)
{
    switch (command)
    {
    case Command::MoveNorth:
        std::cout << "   You move north.\n";

    case Command::MoveSouth:
        std::cout << "   You move south.\n";
        break;

    case Command::Attack:
        std::cout << "   You attack!\n";
        break;

    case Command::Wait:
        std::cout << "   You wait.\n";
        break;
    }
}

void Problem05()
{
    HandleCommand(Command::MoveNorth);
    HandleCommand(Command::Attack);
    HandleCommand(Command::Quit);
}
```

The provided code for Problem05 outputs:
```
   You move north.
   You move south.
   You attack!
```

A case label is only an entry point into the switch. It doesn't mark where that case ends. Execution jumps to case Command::MoveNorth:, prints "north", and there's no break. So it carries straight on into the next statements, which happen to be the MoveSouth code. It prints "south", hits that break, and leaves. This is called fall-through.

In the switch: there's no case Command::Quit, and no default either. When no label matches, the switch simply does nothing, and C++ doesn't treat that as an error.


Problem 6

1. ? :, because it picks one of two values inline, and std::format needs a value rather than a statement: health > 0 ? "alive" : "dead".
2. switch, because a key press is a single integral or enum value compared against many fixed constants, so eleven labels read better than eleven chained else ifs.
3. switch. Every case is one value of an enum class, and without a default the compiler (with -Wswitch on) warns if a new state is added and not handled.
4. if, because this is one combined condition: poisoned && health < maxHealth / 2 && antidotes == 0. A switch can only test one value against constants.
5. ? :, because it chooses between two small values in an expression: StartsWithVowel(name) ? "an" : "a".
6. if/else if. A switch only accepts integral and enum types, so it can't take a std::string, and the comparisons have to be written out with ==. If the list grows long, a lookup table (e.g. std::unordered_map) is the usual next step.