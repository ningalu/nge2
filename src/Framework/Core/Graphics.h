#ifndef _FRAMEWORK_CORE_GRAPHICS_H
#define _FRAMEWORK_CORE_GRAPHICS_H

#include <memory>
#include <string>
#include <functional>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"

namespace nge {
    using TexturePtr = std::shared_ptr<SDL_Texture>;
    using FontPtr = std::shared_ptr<TTF_Font>;

    enum FontStyle {
        SOLID,
        SHADED,
        BLENDED
    };

    class Graphics {
        public:
            const static SDL_Rect FULL_TEXTURE;
            const static SDL_Point ROTATION_CENTRE;

            Graphics(std::string title, SDL_Rect windowRect);

            TexturePtr LoadTexture(const std::string& path);
            FontPtr LoadFont(const std::string& path, int size);
            TexturePtr LoadText(
                const FontPtr& font, 
                FontStyle style, 
                const std::string& text, 
                SDL_Color colour = {0, 0, 0, SDL_ALPHA_OPAQUE}, 
                SDL_Color bg = {0, 0, 0, SDL_ALPHA_TRANSPARENT} // doesnt really work?
            );

            void Clear();
            void DrawTexture(
                SDL_Texture* const texture, 
                const SDL_Rect* const src, 
                const SDL_Rect* const dst, 
                double angle = 0.0f,
                SDL_Point* rotationCentre = nullptr,
                SDL_RendererFlip flip = SDL_FLIP_NONE
            );
            void DrawTexture(
                const TexturePtr& texture, 
                const SDL_Rect* const src, 
                const SDL_Rect* const dst, 
                double angle = 0.0f,
                SDL_Point* rotationCentre = nullptr,
                SDL_RendererFlip flip = SDL_FLIP_NONE
            );
            void Present();

            void SetWindowSize(int w, int h);
            int GetWindowWidth() const;
            int GetWindowHeight() const;

            void SetWindowPosition(int x, int y);
            int GetWindowX() const;
            int GetWindowY() const;

            void SetWindowRect(SDL_Rect window);
            SDL_Rect GetWindowRect() const;

            SDL_Renderer* const GetRenderer();

            ~Graphics();

        private:
            std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window_;
            std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderer_;
            std::string title_;
    };

    using GraphicsPtr = std::shared_ptr<Graphics>;
}

#endif