#ifndef GAME_RENDERER_H
#define GAME_RENDERER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "Color.h"

class GameRenderer
{
	public:
		~GameRenderer (void);
		
		static void clear (void);
		static void present (void);
		
		static void draw (int x, int y, int w, int h, Color color);
		static void draw (int x, int y, int w, int h, Color color, SDL_Texture & texture );
		static void draw (int x, int y, int w, int h, Color color, SDL_Texture & texture, double angle );

		static SDL_Renderer & getRenderer (void);
		
	private:
		static GameRenderer instance;
		GameRenderer (void);
		
		SDL_Window* window_;
		SDL_Renderer* renderer_;
};

#endif
