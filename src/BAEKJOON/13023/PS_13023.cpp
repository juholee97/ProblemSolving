#include <iostream>
#include <vector>

const int MAX_N = 2000;
std::vector<int> adj[ MAX_N ]; // ģ�� ���踦 �����ϴ� ���� ����Ʈ
bool visited[ MAX_N ]; // �湮 ���θ� �����ϴ� �迭

bool dfs( int node, int depth ) 
{
    if ( depth == 4 ) 
    { // ���̰� 4�� �����ϸ� ������ ����
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
    visited[ node ] = false; // �湮 ���� (�ٸ� ��θ� Ž���ϱ� ����)
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
        std::fill( visited, visited + N, false ); // �湮 �迭 �ʱ�ȭ
        if ( dfs( i, 0 ) ) // �� �������� DFS ����
        { 
            std::cout << 1 << std::endl;
            return 0;
        }
    }

    std::cout << 0 << std::endl;
    return 0;
}
