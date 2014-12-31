
#include <iostream>
#include "nothanks_game.h"
#include "bots.h"

using namespace std;

int main()
{
	const int NUM_PLAYERS = 2;
	nothanks_game game(NUM_PLAYERS);
	randombot bots[NUM_PLAYERS];
	
	while (! game.is_game_finished())
	{
		cout << "Turn " << game.TurnNumber() << ".";
		cout << "Card: " << game.ViewCard() << ".";
		cout << "Chips: " << game.ViewChips() << "." << endl;
		
		cout << "Player " << (game.TurnNumber() % 2) + 1 << ": " << game.getCurrentPlayer().get_score() << endl;
		//game.TakeCard();
		bots[game.TurnNumber() % 2].Move(game);
	}
	//cout << "Player score " << game.getCurrentPlayer().get_score() << endl;
	cout << "Game Over!" << endl;
	int pnum = 1;
	for (auto p : game.getPlayers())
	{
		cout << "Player" << pnum <<" score: " << p.get_score() << endl;
		++pnum;
	}
	cout << "Finished." << endl;
	return 0;
}