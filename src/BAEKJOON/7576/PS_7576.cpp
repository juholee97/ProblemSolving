#include <iostream>
#include <queue>
#include <vector>

struct tomato_info 
{
    int x;
    int y;
    int date;
};

int main() 
{
    int x, y, data;
    std::cin >> x >> y;
    std::vector<std::vector<int>> tomatos(y, std::vector<int>(x));
    std::queue<tomato_info> reds;
    int green_cnt = 0;
    
    for (int i = 0; i < y; i++) 
    {
        for (int j = 0; j < x; j++) 
        {
            std::cin >> data;
            tomatos[i][j] = data;
            if (data == 1) 
            {
                reds.push({j, i, 0});
            } 
            else if (data == 0) 
            {
                green_cnt++;
            }
        }
    }

    // 상 하 좌 우
    std::vector<std::pair<int, int>> deltas = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int total_dates = 0;

    while (!reds.empty()) 
    {
        auto red = reds.front();
        reds.pop();
        for (const auto& delta : deltas) 
        {
            int dx = red.x + delta.first;
            int dy = red.y + delta.second;

            if ((0 <= dx && dx < x) && (0 <= dy && dy < y) && tomatos[dy][dx] == 0) 
            {
                tomatos[dy][dx] = 1;
                green_cnt--;
                int used_date = red.date + 1;
                reds.push({dx, dy, used_date});
                total_dates = std::max(total_dates, used_date);
            }
        }
    }

    if (green_cnt == 0) 
    {
        std::cout << total_dates;
    } 
    else 
    {
        std::cout << -1;
    }
    return 0;
}
