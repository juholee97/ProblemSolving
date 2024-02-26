#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

long long  GreatestCommonDiv( long long  a, long long  b )
{
	long long  ret;
	while ( b != 0 )
	{
		ret = a % b;
		a = b;
		b = ret;
	}
	return a;
}

long long LeastCommonMult( long long a, long long b )
{
	return ( a * b ) / GreatestCommonDiv( a, b );
}

int main()
{
	int commonDiv, commonMult;
	std::cin >> commonDiv >> commonMult;

	std::vector<int> candidate;

	long long  limit = std::sqrt( commonMult ) + 1;
	for ( int i = 1; i < limit; i++ )
	{
		if ( commonMult % i == 0 && i <= commonMult / i )
		{
			candidate.push_back( i );
			if ( commonMult / i != i )
				candidate.push_back( commonMult / i );
		}
	}

	std::sort( candidate.begin(), candidate.end() );


	std::pair<long long, long long> result;
	long long minPair = 200000000;
	for ( int i = 0; i < candidate.size(); i++ )
	{
		for ( int j = i; j < candidate.size(); j++ )
		{
			if ( candidate[ i ] + candidate[ j ] < minPair &&
				 GreatestCommonDiv( candidate[ j ], candidate[ i ] ) == commonDiv &&
				 LeastCommonMult( candidate[ j ], candidate[ i ] ) == commonMult )
			{
				minPair = candidate[ i ] + candidate[ j ];
				result.first = candidate[ i ];
				result.second = candidate[ j ];
			}
		}
	}

	std::cout << result.first << " " << result.second;

	return 0;
}