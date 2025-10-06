#pragma once

#include "resource_manager.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>



class SpriteRenderer
{
    public:
        SpriteRenderer(Shader&& shader);
        ~SpriteRenderer();

        void DrawSprite(glm::vec2 position, glm::vec2 size = glm::vec2(10.0f, 10.0f), float rotate = 0.0f, glm::vec3 color = glm::vec3(0.0f));
    private:
        Shader       shader;
        unsigned int quadVAO;

        void initRenderData();
};

