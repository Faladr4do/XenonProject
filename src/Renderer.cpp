#include "Renderer.hpp"

namespace xenon {

    Renderer::Renderer(
        GLuint shaderProgram,
        int screenWidth,
        int screenHeight
    )
        : shaderProgram(shaderProgram),
        screenWidth(screenWidth),
        screenHeight(screenHeight)
    {
        float vertices[] = {
            0.0f, 0.0f, 0.0f, 0.0f,
            1.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 1.0f,

            0.0f, 1.0f, 0.0f, 1.0f,
            1.0f, 0.0f, 1.0f, 0.0f,
            1.0f, 1.0f, 1.0f, 1.0f
        };

        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(
            GL_ARRAY_BUFFER,
            sizeof(vertices),
            vertices,
            GL_STATIC_DRAW
        );

        glVertexAttribPointer(
            0, 2, GL_FLOAT, GL_FALSE,
            4 * sizeof(float), (void*)0
        );
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(
            1, 2, GL_FLOAT, GL_FALSE,
            4 * sizeof(float),
            (void*)(2 * sizeof(float))
        );
        glEnableVertexAttribArray(1);

        glBindVertexArray(0);
    }

    Renderer::~Renderer()
    {
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
    }

    void Renderer::Draw(
        GLuint texture,
        int textureWidth,
        int textureHeight,
        float x,
        float y,
        float width,
        float height,
        SpriteRect source
    )
    {
        glUseProgram(shaderProgram);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);

        glUniform1i(
            glGetUniformLocation(shaderProgram, "spriteTexture"),
            0
        );

        glUniform2f(
            glGetUniformLocation(shaderProgram, "screenSize"),
            (float)screenWidth,
            (float)screenHeight
        );

        glUniform2f(
            glGetUniformLocation(shaderProgram, "spritePosition"),
            x, y
        );

        glUniform2f(
            glGetUniformLocation(shaderProgram, "spriteSize"),
            width, height
        );

        glUniform2f(
            glGetUniformLocation(shaderProgram, "uvOffset"),
            (float)source.x / textureWidth,
            (float)source.y / textureHeight
        );

        glUniform2f(
            glGetUniformLocation(shaderProgram, "uvScale"),
            (float)source.width / textureWidth,
            (float)source.height / textureHeight
        );

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        glBindVertexArray(0);
    }
}