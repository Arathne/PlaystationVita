#ifndef GAME_SETTINGS_H
#define GAME_SETTINGS_H

class GameSettings
{
	public:
		~GameSettings (void);
		
		static void setSpeed (int speed);
		static void setStartLength (int length);
		static void setGrowthRate (int rate);

		static int getSpeed (void);
		static int getStartLength (void);
		static int getGrowthRate (void);

	private:
		GameSettings (void);

		static GameSettings instance;

		int speed_;
		int startLength_;
		int growthRate_;

};

#endif
