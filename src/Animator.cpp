#pragma once

#include "Animator.hpp"
#include "Renderer.hpp"

namespace xenon {

    class Spaceship
    {
    private:
        GLuint texture;

        int textureWidth;
        int textureHeight;

        Animation animation;

        float x;
        float y;

        float width;
        float height;

    public:
        Spaceship(
            GLuint texture,
            int textureWidth,
            int textureHeight
        );

        void Update(float deltaTime);

        void Render(Renderer& renderer);
    };
}