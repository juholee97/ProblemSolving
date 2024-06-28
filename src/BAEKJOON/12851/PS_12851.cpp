#include<iostream>
#include<queue>
#include<vector>
struct ValueState
{
    int value;
    int cnt;
};

int main ()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::queue<ValueState> bfs;
    std::vector<bool> visit(150001, false);
    int start, goal;

    std::cin >> start >> goal;
    bfs.push(ValueState{start, 0});

    bool isMatch = false;
    int minTime = 0;
    int cntMinTime = 0;
    while (!bfs.empty())
    {   
        auto [ value, time ] = bfs.front();
        bfs.pop();
        visit[value] = true;
        
        if( isMatch == true )
        {
            if( value == goal )
            {
                cntMinTime++;
            }
            continue;
        }
        else if( isMatch == false )
        {
            int next_values[3] = { value-1, value+1, value*2};
            int next_time = time + 1;
            for( const auto next_value : next_values )
            {
                if( 0 < next_value && next_value <= 150000 && !visit[next_value] )
                {
                    bfs.push(ValueState{next_value, next_time});
                }
            }
        }
        if ( value == goal )
        {
            isMatch = true;
            minTime = time;
            cntMinTime++;
        }

    } 
    std::cout << minTime << "\n" << cntMinTime;
    
}