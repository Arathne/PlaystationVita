#include "GameRenderer.h"

/* STATIC */

GameRenderer GameRenderer::instance;

void GameRenderer::present (void)
{
	SDL_RenderPresent( instance.renderer_ );
}

void GameRenderer::clear (void)
{
	SDL_SetRenderDrawColor( instance.renderer_, 0, 0, 0, 255 );
	SDL_RenderClear( instance.renderer_ );
}

void GameRenderer::draw (int x, int y, int w, int h, Color color)
{
	SDL_Rect rectangle;
	rectangle.x = x;
	rectangle.y = y;
	rectangle.w = w;
	rectangle.h = h;

	SDL_SetRenderDrawColor( instance.renderer_, color.red(), color.green(), color.blue(), color.alpha() );
	SDL_RenderFillRect( instance.renderer_, &rectangle );
}

void GameRenderer::draw (int x, int y, int w, int h, Color color, SDL_Texture & texture)
{
	SDL_Rect rectangle;
	rectangle.x = x;
	rectangle.y = y;
	rectangle.w = w;
	rectangle.h = h;
	
	SDL_SetTextureColorMod( &texture, color.red(), color.green(), color.blue() );
	SDL_RenderCopy( instance.renderer_, &texture, nullptr, &rectangle );
}

void GameRenderer::draw (int x, int y, int w, int h, Color color, SDL_Texture & texture, double angle )
{
	SDL_Rect rectangle;
	rectangle.x = x;
	rectangle.y = y;
	rectangle.w = w;
	rectangle.h = h;
	
	SDL_Point point;
	point.x = 0;
	point.y = 0;

	SDL_SetTextureColorMod( &texture, color.red(), color.green(), color.blue() );
	SDL_RenderCopyEx(instance.renderer_, &texture, nullptr, &rectangle, angle, &point, SDL_FLIP_NONE);
}

SDL_Renderer & GameRenderer::getRenderer (void)
{
	return *instance.renderer_;
}

/* INSTANCE */

GameRenderer::GameRenderer (void)
{
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	window_ = SDL_CreateWindow( "Snake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 960, 544, SDL_WINDOW_SHOWN );
	renderer_ = SDL_CreateRenderer( window_, -1, SDL_RENDERER_PRESENTVSYNC );
}

GameRenderer::~GameRenderer (void)
{
	SDL_DestroyRenderer(renderer_);
	SDL_DestroyWindow(window_);
	TTF_Quit();
}
