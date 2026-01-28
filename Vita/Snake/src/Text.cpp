#include "Text.h"

/* CONSTRUCTORS */

Text::Text (void):
	content_("-"),
	path_(""),
	fontSize_(0),
	x_(0),
	y_(0),
	font_(nullptr),
	texture_(nullptr),
	renderer_(nullptr)
{}

Text::Text (const char* content, const char* path, int fontSize, SDL_Renderer & renderer):
	content_(content),
	path_(path),
	fontSize_(fontSize),
	x_(0),
	y_(0),
	font_(TTF_OpenFont(path, fontSize)),
	texture_(nullptr),
	renderer_(&renderer)
{
	Text::updateTexture();
}

Text::Text (int x, int y, const char* content, const char* path, int fontSize, SDL_Renderer & renderer):
	content_(content),
	path_(path),
	fontSize_(fontSize),
	x_(x),
	y_(y),
	font_(TTF_OpenFont(path, fontSize)),
	texture_(nullptr),
	renderer_(&renderer)
{
	Text::updateTexture();
}

Text::Text (const Text & rhs):
	content_(rhs.content_),
	path_(rhs.path_),
	fontSize_(rhs.fontSize_),
	x_(rhs.x_),
	y_(rhs.y_),
	width_(rhs.width_),
	height_(rhs.height_),
	font_(rhs.font_),
	texture_(rhs.texture_),
	renderer_(rhs.renderer_),
	color_(rhs.color_)
{}

Text::~Text (void)
{
	if (font_ != nullptr)
		TTF_CloseFont(font_);
	
	if (texture_ != nullptr)
		SDL_DestroyTexture(texture_);
}

/* SETTERS */

void Text::setRenderer(SDL_Renderer & renderer)
{
	renderer_ = &renderer;
}

void Text::setContent (const char* content)
{
	content_ = content;
	Text::updateTexture();
}

void Text::setContent (int number)
{
	std::string s = std::to_string(number);
	content_ = s.c_str();
	Text::updateTexture();
}

void Text::setPosition (int x, int y)
{
	x_ = x;
	y_ = y;
}

void Text::setPositionX (int x)
{
	x_ = x;
}

void Text::setPositionY (int y)
{
	y_ = y;
}

void Text::move (int x, int y)
{
	x_ += x;
	y_ += y;
}

void Text::moveX (int x)
{
	x_ += x;
}

void Text::moveY (int y)
{
	y_ += y;
}

void Text::setFont (const char* path, int fontSize)
{
	if (font_ != nullptr)
		TTF_CloseFont(font_);
	
	path_ = path;
	fontSize_ = fontSize;

	font_ = TTF_OpenFont(path, fontSize);

	Text::updateTexture();
}

void Text::setColor (int red, int green, int blue, int alpha)
{
	color_ = Color::make(red, green, blue, alpha);
}

/* GETTERS */

const char* Text::getContent (void) const
{
	return content_;
}

SDL_Texture & Text::getTexture (void) const
{
	return *texture_;
}

int Text::getPositionX (void)
{
	return x_;
}

int Text::getPositionY (void)
{
	return y_;
}

int Text::getWidth (void)
{
	return width_;
}

int Text::getHeight (void)
{
	return height_;
}

Color Text::getColor (void) const
{
	return color_;
}

/* OPERATORS */

const Text & Text::operator = (const Text & rhs)
{
	if (&rhs != &(*this))
	{
		content_ = rhs.content_;
		path_ = rhs.path_;
		fontSize_ = rhs.fontSize_;
		x_ = rhs.x_;
		y_ = rhs.y_;
		width_ = rhs.width_;
		height_ = rhs.height_;
		font_ = rhs.font_;
		texture_ = rhs.texture_;
		renderer_ = rhs.renderer_;
		color_ = rhs.color_;
	}

	return *this;
}

/* METHODS */

void Text::draw (void)
{
	if (texture_ != nullptr)
		GameRenderer::draw(x_, y_, width_, height_, color_, *texture_);
}

void Text::draw (double angle)
{
	if (texture_ != nullptr)
		GameRenderer::draw(x_, y_, width_, height_, color_, *texture_, angle);
}

/* PRIVATE */

void Text::updateTexture (void)
{
	if (font_ != nullptr && renderer_ != nullptr)
	{
		if (texture_ != nullptr)
			SDL_DestroyTexture(texture_);
	
		SDL_Color white = {255, 255, 255};

		SDL_Surface* surface = TTF_RenderText_Solid(font_, content_, white);
		texture_ = SDL_CreateTextureFromSurface(renderer_, surface);
	
		width_ = surface -> w;
		height_ = surface -> h;

		SDL_FreeSurface(surface);
	}
}
