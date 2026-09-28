Problem 1 - Assemble the threat assessment (ordering) - Warm-up

1.

```c++
#include <iostream>

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
```

I have left out 'else if (enemyCount)', because this line does not mention a comparison operator. The 'else if' statement should include a condition that evaluates to true or false, such as 'else if (enemyCount > 2)'. Without a comparison operator, the code will not compile correctly.
