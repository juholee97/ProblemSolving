#include <iostream>
#include <string>
#include <algorithm>

int can_be_match ( const std::string & startArr, std::string endArr )
{
    while ( startArr.size() < endArr.size() )
    {
        if(endArr.back() == 'A')
        {
            endArr.pop_back();
        }
        else
        {
            endArr.pop_back();
            std::reverse(endArr.begin(), endArr.end());
        }
    }
    return (startArr == endArr) ? 1 : 0;
}

int main()
{
    std::string startArr, endArr;
    std::cin >> startArr;
    std::cin >> endArr;

    std::cout << can_be_match(startArr, endArr);
}