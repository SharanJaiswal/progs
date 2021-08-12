#include <iostream>
#include <vector>

int main()
{
    #include "../fileio.h"
    int rows;
    std::cin >> rows;
    std::cout << rows << std::endl;
    std::vector<int> cols_cnt(rows);  // no. of cols in respective row
    // cols_cnt.reserve(rows);  // this will just block the memory as a whole, but not initialize them individually
    // So, vector indexing wont work with just reserve. push_back or emplace_back will work with reserve
    // indexing will work only when memory will get initialized
    for( auto &x : cols_cnt)    // dont forget to make x as a reference var, otherwise actual feeding wont get done
    {
        std::cin >> x;
    }
    std::vector< std::vector<int> > vect2d(rows);
    // vect2d.reserve(rows);
    for(int i = 0; i < rows; i++)
    {
        int col = cols_cnt[i];
        vect2d[i] = std::vector<int>(col);
        for(int &ele : vect2d[i])
        {
            std::cin >> ele;
        }
    }
    for(auto& row : vect2d)
    {
        for(int &ele : row)
        {
            std::cout << ele << ", ";
        } std::cout << std::endl;
    }

    // for equal no of rows and cols, at the very start initialize vectoe as
    // std::vector< std::vector<int> > vect2d( rows, std::vector<int> (cols) );
    // we can give the initial value for each element also(after cols but within () separated by ',')
    return 0;
}