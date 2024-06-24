#include <iostream>
#include <vector>
#include <algorithm>

int main ()
{
    unsigned int data_size;
    std::cin >> data_size;

    std::vector<unsigned int> datas(data_size);
    for( auto & data : datas)
    {
        std::cin >> data;
    }

    std::vector<unsigned int> longest;

    for( const auto & data : datas)
    {   
        // std::lower_bound는 range내의 데이터 중, data보다 크거나 같은 iterator를 반환함.
        // 따라서 누적된 벡터에 만족하는 iterator가 없다면 data가 가장 큰 값이므로 push_back하고
        // 누적된 벡터 중, 위 조건을 만족하는 iterator가 있다면, 해당 iterator를 data값으로 변경.
        auto it = std::lower_bound ( longest.begin(), longest.end(), data);
        if( it == longest.end() )
        {
            longest.push_back(data);
        }
        else
        {
            *it = data;
        }
    }

    std::cout << longest.size();
}




