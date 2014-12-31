#pragma once

#include "nothanks_player_state.h"
#include <vector>
#include <deque>

class nothanks_game
{
public:
	nothanks_game(int numplayers);

	//bots call these to view the state of the game
	const int ViewCard();
	const int ViewChips();

	//

	void TakeCard();
	void PlayChip();

	const int TurnNumber();

	const  bool is_game_finished();

	//nothanks_game& operator=(const nothanks_game &other);
	//nothanks_game(const nothanks_game &other);

	static const int START_CARD = 3;
	static const int END_CARD = 35;
	static const int NUM_CARDS_TO_REMOVE = 9;

	const std::vector<nothanks_player_state> getPlayers();
	std::vector<int>::const_iterator seen_cards();

	nothanks_player_state getCurrentPlayer();

private:
	int m_numPlayers;
	int m_turnNumber;
	int m_CurrentCard;
	int m_CurrentChips;
	bool m_finished;
	nothanks_player_state m_currentPlayer;
	std::deque<nothanks_player_state> m_players;
	std::vector<int> m_seenCards;
	std::deque<int> m_remainingCards;

	void Initialize();
};
