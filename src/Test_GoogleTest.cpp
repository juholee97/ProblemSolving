#include <string>
#include <variant>
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

// BAEKJOON PS : 16496
struct InputData_16496
{
	std::vector<int32_t> inputdatas;
	std::string result;
};

TEST_F( ProblemSolving_Test, BAEKJOON_16496 )
{
	std::vector<InputData_16496> datas;

	datas.push_back( { {323, 323343}, "323343323" } );
	datas.push_back( { {343, 343323}, "343343323" } );
	datas.push_back( { {1, 0}, "10" } );
	datas.push_back( { {0, 0, 0}, "0" } );

	

	for ( auto data : datas )
	{
		mCPS_16496.get()->Init();
		std::string result = mCPS_16496.get()->Execute( data.inputdatas );

		EXPECT_EQ( result, data.result );
	}
}