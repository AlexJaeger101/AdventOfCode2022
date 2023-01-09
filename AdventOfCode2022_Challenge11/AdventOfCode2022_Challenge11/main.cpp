#include <iostream>
#include <string>
#include <fstream>
#include <vector>

bool whereToThrow(int oldVal, Operation operation, int divisor);

enum Operator
{
	ADD,
	MULT
};

struct Operation
{
	Operator mOperator;		// How worry level changes (can be + or *)
	int mOperationVal;		// new = old + mOperationVal (can also be *, depends on mOperation)
};

struct Monkey
{
	std::vector<int> mItemList;		// List of item worry levels
	Operation mOperation;			// The operation to calculate new value
	int mDivisor;					// Divisible by this value

	//Monkeys have two buddies they can throw to
	int mBuddy1;
	int mBuddy2;
};

int main()
{

	return 0;
}

// Returns where the monkey is throwing
bool whereToThrow(int oldVal, Operation operation, int divisor)
{
	if (operation.mOperator == ADD)
	{
		return ((oldVal + operation.mOperationVal) % divisor) == 0;
	}

	return ((oldVal * operation.mOperationVal) % divisor) == 0;
}