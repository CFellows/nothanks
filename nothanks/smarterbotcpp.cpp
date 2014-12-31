#include "bots.h"
#include <random>


smarterbot::smarterbot()
{

}

void smarterbot::Move(nothanks_game &game)
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