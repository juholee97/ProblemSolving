#pragma once
#include <iostream>
#include <memory>
#include "BAEKJOON/16496/PS_16496.hpp"

class ProblemSolving_Test : public testing::Test
{
protected:
	void SetUp() override
	{
		mCPS_16496 = std::make_unique<PS_16496>();
	}

	void TearDown() override
	{
	}

	std::unique_ptr<PS_16496> mCPS_16496;
};