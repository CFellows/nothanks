#include "nothanks_bot.h"

class randombot : public nothanks_bot
{
public:
	randombot();

	void Move(nothanks_game &game);
};

class smarterbot : public nothanks_bot
{
public:
	smarterbot();

	void Move(nothanks_game &game);
};