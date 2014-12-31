
#include <iostream>
#include "nothanks_game.h"
#include "bots.h"

using namespace std;

int main()
{
	nothanks_game game(2);
	randombot bots[2];
	
	while (! game.is_game_finished())
	{
		cout << "Turn " << game.TurnNumber() << endl;
		cout << "Card " << game.ViewCard() << endl;
		cout << "Current Player " << game.getCurrentPlayer().get_score() << endl;
		//game.TakeCard();
		bots[game.TurnNumber() % 2].Move(game);
	}
	//cout << "Player score " << game.getCurrentPlayer().get_score() << endl;
	cout << "Game Over!" << endl;
	for (auto p : game.getPlayers())
	{
		cout << "Player score " << p.get_score() << endl;
	}
	cout << "Finished." << endl;
	return 0;
}