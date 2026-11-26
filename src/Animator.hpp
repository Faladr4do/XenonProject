#pragma once

#include "Renderer.hpp"

namespace xenon {

    class Animation
    {
    private:
        int frameWidth;
        int frameHeight;

        int totalFrames;
        int currentFrame;

        float frameDuration;
        float elapsedTime;

        bool looping;

    public:
        Animation(
            int frameWidth,
            int frameHeight,
            int totalFrames,
            float frameDuration,
            bool looping = true
        );

        void Update(float deltaTime);

        SpriteRect GetCurrentFrame() const;

        void Reset();
    };
}