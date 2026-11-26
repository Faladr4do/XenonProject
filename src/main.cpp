#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <iostream>
#include <SDL3/SDL.h>
#include <glad/glad.h>
#include <iostream>
#include <stdexcept>
#include "World.hpp"
#include "Enemy.hpp"
#include "Spaceship.hpp"
#include "Renderer.hpp"




GLuint LoadTexture(
	const char* path,
	int& width,
	int& height
)
{
	int channels;

	stbi_set_flip_vertically_on_load(true);

	unsigned char* data = stbi_load(
		path,
		&width,
		&height,
		&channels,
		0
	);

	if (!data)
		throw std::runtime_error("Failed to load texture");

	GLenum format = channels == 4 ? GL_RGBA : GL_RGB;

	GLuint texture;

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexImage2D(
		GL_TEXTURE_2D,
		0,
		format,
		width,
		height,
		0,
		format,
		GL_UNSIGNED_BYTE,
		data
	);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	stbi_image_free(data);

	return texture;
}
int main()
{
	using namespace xenon;

	if (!SDL_Init(SDL_INIT_VIDEO)) {
		std::cout << "SDL_Init failed: " << SDL_GetError() << std::endl;
		return -1;
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

	SDL_Window* window = SDL_CreateWindow("OpenGL", 800, 600, SDL_WINDOW_OPENGL);
	if (window == nullptr) {
		std::cout << "Failed to create SDL Window: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return -1;
	}

	SDL_GLContext context = SDL_GL_CreateContext(window);
	if (!context) {
		std::cout << "Failed to create OpenGL context: " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return -1;
	}

	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		SDL_GL_DestroyContext(context);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return -2;
	}
	



	// Load shader
	GLuint shaderProgram = CreateShaderProgram();

	// Load texture
	int textureWidth;
	int textureHeight;

	GLuint spaceshipTexture = LoadTexture(
		"assets/textures/spaceship.png",
		textureWidth,
		textureHeight
	);

	// Create renderer
	Renderer renderer(shaderProgram, 800, 600);

	// Create spaceship
	Spaceship spaceship(
		spaceshipTexture,
		textureWidth,
		textureHeight
	);

	SDL_Event windowEvent;
	bool running = true;
	while (running) {
		while (SDL_PollEvent(&windowEvent)) {
			if (windowEvent.type == SDL_EVENT_QUIT) {
				running = false;
			}
		}



		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		SDL_GL_SwapWindow(window);
	}

	SDL_GL_DestroyContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}