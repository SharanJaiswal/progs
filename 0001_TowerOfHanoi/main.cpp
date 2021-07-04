#include <iostream>

void TowerOfHanoi(int n, char x, char y, char z)
{
    if (n > 0)
    {

        TowerOfHanoi(n-1, x, z, y);
        std::cout << "Moving topmost disk on Tower " << x << " to Tower " << y << "." << std::endl;
        TowerOfHanoi(n-1, z, y, x);
    }
}

int main()
{
    #include "../fileio.h"
    int n;
    std::cin >> n;
    char x = 'A', y = 'B', z = 'C';
    TowerOfHanoi(n, x, y, z);
    return 0;
}