#include <iostream>
#include <format>
#include <string>

//problem01
void Problem01()
{
    int health{ 10 };
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

//problem02
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

// problem03
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

//problem04

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

//problem05
enum class Command
{
    MoveNorth,
    MoveSouth,
    Attack,
    Wait,
    Quit,
};

void HandleCommand(Command command)
{
    switch (command)
    {
    case Command::MoveNorth:
        std::cout << "   You move north.\n";
        return;

    case Command::MoveSouth:
        std::cout << "   You move south.\n";
        return;

    case Command::Attack:
        std::cout << "   You attack!\n";
        return;

    case Command::Wait:
        std::cout << "   You wait.\n";
        return;

    case Command::Quit:
        std::cout << "   You quit.\n";
        return;
    }

    std::cout << "   Unknown command.\n";
}

void Problem05()
{
    HandleCommand(Command::MoveNorth);
    HandleCommand(Command::Attack);
    HandleCommand(Command::Quit);
}

// main function
int main()
{
	Problem01();
    Problem02();
    TryToCastSpell(false, 10, 5, false); // You do not know that spell.
    TryToCastSpell(true, 10, 5, true);  // You cannot speak.
    TryToCastSpell(true, 3, 5, false); // Not enough mana.
    TryToCastSpell(true, 5, 5, false); // The spell goes off!
    Problem04();
    Problem05();
}