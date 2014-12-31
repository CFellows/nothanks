#include "bots.h"
#include <random>

nothanks_bot::~nothanks_bot()
{}

randombot::randombot()
{

}

void randombot::Move(nothanks_game &game)
{
	auto player = game.getCurrentPlayer();

	auto others = game.getPlayers();

	if ((rand() % 2 == 0) && player.can_Play_Counter())
	{
		game.PlayChip();
	}
	else
	{
		game.TakeCard();
	}
	return;
}