#pragma once
#include "nothanks_game.h"

class nothanks_bot
{
public:
	virtual ~nothanks_bot();

	//must call either PlaceChip() or TakeCard();
	virtual void Move(nothanks_game &game) = 0;
};