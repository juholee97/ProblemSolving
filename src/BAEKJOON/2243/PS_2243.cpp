#include <iostream>
#include <algorithm>
#include <map>


int main ()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::map<int, long long> candyBox;
    int order, order_type, popCandy, taste_value;
    long long candy_cnt;
    std::cin >> order;

    while( order-- != 0)
    {
        std::cin >> order_type;
        if (order_type == 1)
        {
            std::cin >> popCandy;
            long long count = 0;
            for( auto & candy : candyBox )
            {
                count += candy.second;
                if( count >= popCandy )
                {
                    std::cout << candy.first << "\n";
                    candy.second -= 1;
                    break;
                }
            }
        }
         else if ( order_type == 2)
         {
            std::cin >> taste_value >> candy_cnt;
            candyBox[taste_value] += candy_cnt;
        }
    }
}