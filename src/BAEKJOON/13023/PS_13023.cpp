#include <iostream>
#include <vector>

const int MAX_N = 2000;
std::vector<int> adj[ MAX_N ]; // 친구 관계를 저장하는 인접 리스트
bool visited[ MAX_N ]; // 방문 여부를 저장하는 배열

bool dfs( int node, int depth ) 
{
    if ( depth == 4 ) 
    { // 깊이가 4에 도달하면 조건을 만족
        return true;
    }
    visited[ node ] = true;
    for ( int neighbor : adj[ node ] ) 
    {
        if ( !visited[ neighbor ] ) 
        {
            if ( dfs( neighbor, depth + 1 ) ) 
            {
                return true;
            }
        }
    }
    visited[ node ] = false; // 방문 해제 (다른 경로를 탐색하기 위해)
    return false;
}

int main() 
{
    int N, M;
    std::cin >> N >> M;
    for ( int i = 0; i < M; ++i ) 
    {
        int a, b;
        std::cin >> a >> b;
        adj[ a ].push_back( b );
        adj[ b ].push_back( a );
    }

    for ( int i = 0; i < N; ++i ) 
    {
        std::fill( visited, visited + N, false ); // 방문 배열 초기화
        if ( dfs( i, 0 ) ) // 각 정점에서 DFS 시작
        { 
            std::cout << 1 << std::endl;
            return 0;
        }
    }

    std::cout << 0 << std::endl;
    return 0;
}
