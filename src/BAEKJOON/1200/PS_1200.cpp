#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstdint>


int64_t Solve_1200( int value, const int n )
{
	int64_t ret = 0;
	for ( int64_t i = 1; i <= n; i++ )
	{
		if ( n * i < value )
		{
			ret += n;
		}
		else {
			if ( value % i == 0 )
			{
				ret += ( value / i ) - 1;
			}
			else
			{
				ret += ( value / i );
			}
		}
	}
	return ret + 1;
}


int main()
{
	std::ios_base::sync_with_stdio( false );
	std::cin.tie( NULL );
	std::cout.tie( NULL );

	int64_t n, k;

	std::cin >> n >> k;

	int64_t start = 1;
	int64_t end = k + 1;
	int64_t mid = ( start + end ) / 2;
	int64_t result;
	while ( start + 1 < end )
	{
		mid = ( start + end ) / 2;
		result = Solve_1200( mid, n );

		if ( result <= k )
		{
			start = mid;
		}
		else
		{
			end = mid;
		}
	}

	std::cout << start;

	return 0;
}