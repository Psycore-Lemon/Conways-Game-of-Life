#include "game.h"
#include "resource_manager.h"
#include "sprite_renderer.h"

SpriteRenderer* Renderer;

Game::Game(unsigned int width, unsigned int height)
	: State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{

}

Game::~Game()
{
	delete Renderer;
}

void Game::Init()
{
    // load shaders
    ResourceManager::LoadShader("sprite.vs", "sprite.fs", nullptr, "sprite");
    // configure shaders
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->Width),
        static_cast<float>(this->Height), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
    // set render-specific controls
    Renderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));
}

void Game::ProcessInput(float dt, GLFWwindow* window)
{

}

void Game::Update(float dt)
{

}

void Game::Render()
{
    //DrawSprite(glm::vec2 position, glm::vec2 size = glm::vec2(10.0f, 10.0f), float rotate = 0.0f, glm::vec3 color = glm::vec3(0.0f));
    for (int i = 0; i < GRID_X; i ++)
    {
        for (int j = 0; j < GRID_Y; j++)
        {
            if (Cell[i][j] == ALIVE)
            {
                Renderer->DrawSprite(glm::vec2(i, j) * CELL_SIZE, glm::vec2(10.0f,10.0f),0.0f, glm::vec3(1.0f));
            }
            else
            {
                Renderer->DrawSprite(glm::vec2(i, j) * CELL_SIZE, glm::vec2(10.0f, 10.0f), 45.0f, glm::vec3(1.0f,1.0f,0.0f));
            }
        }
    }
    
}

Life ProcessRuleLive(Life(&grid)[GRID_X][GRID_Y], int x, int y)
{
    int counter = 0;

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (grid[i][j] == ALIVE && !(i == 0 && j ==0))
            {
                counter++;
            }
        }
    }

    return ALIVE;
}

Life ProcessRuleDead(Life(&grid)[GRID_X][GRID_Y], int x, int y);

float clamp(float value, float min, float max);
int clamp(int value, int min, int max);