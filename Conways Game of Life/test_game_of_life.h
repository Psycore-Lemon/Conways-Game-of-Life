#pragma once
#include <cassert>
#include "game.h"


// The Width of the screen
const unsigned int SCREEN_WIDTH_TEST = 800;
// The height of the screen
const unsigned int SCREEN_HEIGHT_TEST = 600;

Game Conway_Test(SCREEN_WIDTH_TEST, SCREEN_HEIGHT_TEST);


/// <Conway's Rules>
/// 
/// #1 Any live cell with fewer than two live neighbours dies, as if by underpopulation.
/// #2 Any live cell with two or three live neighbours lives on to the next generation.
/// #3 Any live cell with more than three live neighbours dies, as if by overpopulation.
///	#4 Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
/// 
/// </Conway's Rules>
void  test_rule_1()
{
	//Conway_Test.Init();

	Conway_Test.Cell[0][1] = ALIVE;
	Conway_Test.Update(0.0f);
	
	std::cout << (Conway_Test.Cell[0][1]);

	assert(Conway_Test.Cell[0][1] == DEAD);

	//Conway_Test.~Game();

}

void test_rule_2()
{
	//Conway_Test.Init();
	

	Conway_Test.Cell[1][1] = ALIVE;
	Conway_Test.Cell[0][1] = ALIVE;
	Conway_Test.Cell[1][0] = ALIVE;

	std::cout << (Conway_Test.Cell[1][1]);

	Conway_Test.Update(0.0f);

	std::cout << (Conway_Test.Cell[1][1]);

	assert(Conway_Test.Cell[1][1] == ALIVE);
	assert(Conway_Test.Cell[0][1] == ALIVE);
	assert(Conway_Test.Cell[1][0] == ALIVE);

	//Conway_Test.~Game();
}

void test_rule_3()
{
	//Conway_Test.Init();

	Conway_Test.Cell[1][1] = ALIVE;
	Conway_Test.Cell[0][1] = ALIVE;
	Conway_Test.Cell[1][0] = ALIVE;
	Conway_Test.Cell[2][1] = ALIVE;
	Conway_Test.Cell[1][2] = ALIVE;

	Conway_Test.Update(0.0f);


	assert(Conway_Test.Cell[1][1] == DEAD);

	//Conway_Test.~Game();

}

void test_rule_4()
{
	
	//Conway_Test.Init();

	Conway_Test.Cell[1][1] = DEAD;
	Conway_Test.Cell[0][1] = ALIVE;
	Conway_Test.Cell[1][0] = ALIVE;
	Conway_Test.Cell[2][1] = ALIVE;

	Conway_Test.Update(0.0f);

	assert(Conway_Test.Cell[1][1] == ALIVE);

	//Conway_Test.~Game();

}

int runUnitTests()
{
	test_rule_1();
	test_rule_2();
	test_rule_3();
	test_rule_4();

	return 0;
}

int runIntegrationTests()
{
	return 0;
}

int runStressTests()
{
	return 0;
}