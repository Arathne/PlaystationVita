#include "Menu.h"

#define SNAKE_SIZE 32
#define SNAKE_MARGIN 40

#define SPACING 60
#define CENTER_X 960/2
#define CENTER_Y 544/2

Menu::Menu (void):
	selected_(0),
	title_(Text(CENTER_X, 40, "SNAKE", "app0:/assets/joystix.ttf", 110, GameRenderer::getRenderer())),
	snake_(new Snake(960-SNAKE_SIZE-SNAKE_MARGIN, -SNAKE_SIZE)),
	signature_( Text(55, 544/2, "ARATHNE", "app0:/assets/joystix.ttf", 10, GameRenderer::getRenderer()))
{
	title_.moveX(-(title_.getWidth()/2));
	title_.setColor(150, 0, 255, 255);
	
	signature_.setColor(0, 0, 0, 255);

	options_.push_back(new Selector(CENTER_X, 250, "PLAY", 40, *((Node*) new Game()) ));
	options_.push_back(new Selector(CENTER_X, 250+SPACING, "OPTIONS", 40, *((Node*) new Settings())));
	options_.at(selected_) -> hover();

	snake_ -> direction(DOWN);
}

Menu::~Menu (void) 
{
	for (auto it = options_.begin(); it != options_.end(); it++)
	{
		delete *it;
	}

	delete snake_;
}

Node* Menu::process (void)
{
	Node* nextState = this;
	
	Menu::input();
	
	Menu::snake();

	GameRenderer::clear();
	Menu::draw();
	GameRenderer::present();
	
	if (Input::began(SCE_CTRL_CROSS)) 
	{
		nextState = &options_.at(selected_) -> select();
	}

	return nextState;
}

void Menu::input (void)
{
	if (Input::began(SCE_CTRL_UP) && selected_ > 0) {
		options_.at(selected_) -> unhover();
		selected_--;
		options_.at(selected_) -> hover();
	}
	else if (Input::began(SCE_CTRL_DOWN) && selected_ < options_.size()-1) {
		options_.at(selected_) -> unhover();
		selected_++;
		options_.at(selected_) -> hover();
	}
}

void Menu::snake (void)
{
	int y = snake_ -> getPositionY();
	std::cout << y << std::endl;

	if (y >= 544 + GameSettings::getStartLength() - SNAKE_SIZE) 
	{
		delete snake_;
		snake_ = new Snake(SNAKE_MARGIN, 544);
		snake_ -> direction(UP);
	}
	else if (y <= -GameSettings::getStartLength()) 
	{
		delete snake_;
		snake_ = new Snake(960-SNAKE_SIZE-SNAKE_MARGIN, -SNAKE_SIZE);
		snake_ -> direction(DOWN);
	}

	snake_ -> update();
}

void Menu::draw (void)
{
	snake_ -> draw();
	
	for (auto it = options_.begin(); it != options_.end(); it++)
	{
		(*it) -> draw();
	}

	title_.draw();
	signature_.draw(-90);
}
