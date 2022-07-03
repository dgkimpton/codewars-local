#include "battle/kata.h"
#include "solution.h"

Describe(KataRunner)
{
	It(Works)
	{
		Assert::That(solution(true), Equals(true));
	}
};