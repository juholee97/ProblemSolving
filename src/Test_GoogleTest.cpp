#include <string>
#include <gtest/gtest.h>
#include "Test_GoogleTest.hpp"

// BAEKJOON PS : 2839
TEST_F( ProblemSolving_Test, BAEKJOON_2839 )
{
	std::vector< std::pair<int32_t, int32_t> > input_datas;
	input_datas.push_back( { 18, 4 } );
	input_datas.push_back( { 4, -1 } );
	input_datas.push_back( { 6, 2 } );
	input_datas.push_back( { 9, 3 } );
	input_datas.push_back( { 11, 3 } );

	for ( auto input_data : input_datas )
	{
		std::function< int32_t( int32_t, int32_t, int32_t )> Find_minimum_saltbag = [ & ] ( int32_t salt, int32_t saltbag_5, int32_t saltbag_3 ) -> int32_t
		{
			if ( salt > saltbag_5 * 5 + saltbag_3 * 3 )
			{
				int32_t ret = Find_minimum_saltbag( salt, saltbag_5 + 1, saltbag_3 );

				if ( salt != ret )
				{
					return ret;
				}
				else
				{
					return Find_minimum_saltbag( salt, saltbag_5, saltbag_3 + 1 );
				}
			}
			else if ( salt == saltbag_5 * 5 + saltbag_3 * 3 )
			{
				return saltbag_5 + saltbag_3;
			}
			else
			{
				return salt;
			}
		};

		int32_t result = Find_minimum_saltbag( input_data.first, 0, 0 );
		if ( result == input_data.first )
		{
			result = -1;
		}

		EXPECT_EQ( result, input_data.second );
	}
}