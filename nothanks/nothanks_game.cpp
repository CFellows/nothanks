#pragma once

#include "nothanks_game.h"
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;

nothanks_game::nothanks_game(int numplayers) :
m_numPlayers(numplayers),
m_turnNumber(0),
m_CurrentCard(0),
m_CurrentChips(0),
m_finished(false),
m_players( ),
m_seenCards( ),
m_remainingCards( ),
m_currentPlayer()
{
	if (numplayers < 2)
	{
		m_numPlayers = 2;
	}

	Initialize();

}

void nothanks_game::Initialize()
{
	//create players
	for (int i = 0; i < m_numPlayers; ++i)
	{
		nothanks_player_state p{};
		m_players.push_back(p);
	}

	// cards are numbered nothanks_game::START_CARD to nothanks_game::END_CARD 
	// with nothanks_game::NUM_CARDS_TO_REMOVE randomly removed
	int numtoremove = nothanks_game::NUM_CARDS_TO_REMOVE;
	vector<int> removed{};
	int numcards = nothanks_game::END_CARD - nothanks_game::START_CARD;
	
	for (int i = 0; i < numtoremove; ++i)
	{
		int r = rand() % numcards;

		auto iter = std::find(removed.begin(), removed.end(), r);

		if (iter == removed.end())
		{
			removed.push_back(r);
		}
		else
		{
			--i;
		}
		
	}

	std::sort(removed.begin(), removed.end());

	auto iter = removed.begin();

	for (int i = 0; i < numcards; i++)
	{
		int c = i + nothanks_game::START_CARD;

		while ((iter != removed.end()) && (i == *iter))
		{
			++i;
			++iter;
		}

		if (i < numcards)
		{
			c = i + nothanks_game::START_CARD;
			m_remainingCards.push_back(c);
		}
	}

	unsigned int seed = static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count());

	shuffle(m_remainingCards.begin(), m_remainingCards.end(), std::default_random_engine(seed));

	//TODO: Should use pointers here.
	//pop a card off remainingcards
	m_CurrentCard = m_remainingCards.front();
	m_remainingCards.pop_front();
	//pop a player off players
	m_currentPlayer = m_players.front();
	m_players.pop_front();
}

	//bots call these to view the state of the game
const int nothanks_game::ViewCard() { return m_CurrentCard; }
const int nothanks_game::ViewChips() { return m_CurrentChips; }

nothanks_player_state nothanks_game::getCurrentPlayer() { return m_currentPlayer; }

void nothanks_game::TakeCard()
{
	if (m_finished)
		return;

	m_currentPlayer.addCard(m_CurrentCard);
	m_seenCards.push_back(m_CurrentCard);
	m_CurrentCard = m_remainingCards.front();
	m_remainingCards.pop_front();

	m_currentPlayer.addChips(m_CurrentChips);
	m_CurrentChips = 0;

	m_turnNumber++;
	if (m_remainingCards.size() == 0)
	{
		m_finished = true;
	}
	m_players.push_back(m_currentPlayer);

	if (m_finished)
	{
		//TODO Current player invalid;
		return;
	}

	m_currentPlayer = m_players.front(); //do you need to pop off of a queue?
	m_players.pop_front();
	
}
void nothanks_game::PlayChip()
{
	if(m_finished)
		return;

	m_CurrentChips++;

	m_turnNumber++;
	m_players.push_back(m_currentPlayer);
	m_currentPlayer = m_players.front();
	m_players.pop_front();
}

const int nothanks_game::TurnNumber() { return m_turnNumber; }

const bool nothanks_game::is_game_finished() { return m_finished; }

	//nothanks_game& operator=(const nothanks_game &other);
	//nothanks_game(const nothanks_game &other);

const std::vector<nothanks_player_state> nothanks_game::getPlayers()
{
	std::vector<nothanks_player_state> players{ 0 };

	for (auto p : m_players)
	{
		players.push_back(p);
	}

	return players;
}
std::vector<int>::const_iterator nothanks_game::seen_cards()
{
	return m_seenCards.cbegin();
}
