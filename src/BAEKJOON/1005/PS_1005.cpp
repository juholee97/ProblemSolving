#include <iostream>
#include <vector>
#include <cmath>

long long CalcCost( const int build, const std::vector<std::vector<int> >& rules, const std::vector<int>& costs, std::vector<long long>& costResults )
{
	if ( rules[ build ].size() == 0 )
	{
		return costs[ build ];
	}
	else if ( costResults[ build ] != -1 )
	{
		return costResults[ build ];
	}
	long long finalCost = 0;
	long long tmp;
	for ( auto request : rules[ build ] )
	{
		tmp = CalcCost( request, rules, costs, costResults );
		if ( tmp > finalCost )
		{
			finalCost = tmp;
		}
	}
	costResults[ build ] = costs[ build ] + finalCost;
	return costResults[ build ];
}

int main()
{
	std::ios_base::sync_with_stdio( false );
	std::cin.tie( NULL );
	std::cout.tie( NULL );
	int testCase = {};
	int towerSize = {};
	int buildRuleSize = {};
	int requestBuild = {};
	int targetBuild = {};
	std::cin >> testCase;
	std::vector<long long> results( testCase );
	for ( auto& result : results )
	{
		std::cin >> towerSize >> buildRuleSize;

		std::vector<int> costs( towerSize );
		std::vector<long long> costResults( towerSize, -1 );
		std::vector<std::vector<int> > rules( towerSize );

		for ( auto& cost : costs )
		{
			std::cin >> cost;
		}
		for ( int i = 0; i < buildRuleSize; i++ )
		{
			std::cin >> requestBuild >> targetBuild;
			rules[ targetBuild - 1 ].push_back( requestBuild - 1 );
		}

		int absoluteWinningBuild;
		std::cin >> absoluteWinningBuild;
		result = CalcCost( absoluteWinningBuild - 1, rules, costs, costResults );
	}
	for ( const auto result : results )
	{
		std::cout << result << "\n";
	}
	return 0;
}