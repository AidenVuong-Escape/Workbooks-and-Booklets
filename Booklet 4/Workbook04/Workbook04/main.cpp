#include <iostream>
#include <format>
#include <string>

void Problem01()
{
    int health{ 30 };
    int enemyCount{ 3 };
    // ... the chain goes here ...
    if (health == 0)
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