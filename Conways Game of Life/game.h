#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>



enum GameState
{
	GAME_ACTIVE,
	GAME_PAUSED
};

enum Life
{
	DEAD, 
	ALIVE
	
};

const int GRID_X = 100;
const int GRID_Y = 100;
const float CELL_SIZE = 20.0f;




class Game
{
	public:
		GameState		State;
		bool			Keys[1024];
		bool			Buttons[7];
		bool			ButtonAction;
		unsigned int	Width, Height;


		unsigned int	clock = 0;

		Life			Cell[GRID_X][GRID_Y] = {};


		// Constructors/Destructors
		Game(unsigned int width, unsigned int height);
		~Game();

		void Init();

		void ProcessInput(float dt, GLFWwindow* window);
		void Update(float dt);

		void Render();
};


Life ProcessRuleLive(Life (&grid)[GRID_X][GRID_Y], int x, int y);

Life ProcessRuleDead(Life (&grid)[GRID_X][GRID_Y], int x, int y);

float clamp(float value, float min, float max);
int clamp(int value, int min, int max);
