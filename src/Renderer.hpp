#pragma once

#include <glad/glad.h>

namespace xenon {

    struct SpriteRect
    {
        int x;
        int y;
        int width;
        int height;
    };

    class Renderer
    {
    private:
        GLuint VAO;
        GLuint VBO;

        GLuint shaderProgram;

        int screenWidth;
        int screenHeight;

    public:
        Renderer(
            GLuint shaderProgram,
            int screenWidth,
            int screenHeight
        );

        ~Renderer();

        void Draw(
            GLuint texture,
            int textureWidth,
            int textureHeight,
            float x,
            float y,
            float width,
            float height,
            SpriteRect source
        );
    };
}