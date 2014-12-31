
#include "nothanks_player_state.h"
#include <algorithm>

nothanks_player_state::nothanks_player_state() :
m_score{ 0 },
m_EarnedCounters{10},
m_cards( 0 )
{
}

void nothanks_player_state::addChips(int chips)
{
	m_EarnedCounters += chips;
}

int nothanks_player_state::get_score()
{
	//TODO: change score in add chips and add card, not here.
	//recalculate score
	m_score = -m_EarnedCounters;

	std::sort(m_cards.begin(), m_cards.end());

	auto end = m_cards.cend();
	auto iter = m_cards.cbegin();

	while (iter != end)
	{
		auto run_start = *iter;
		m_score += run_start;
		auto run = run_start;
		++iter;
		while ((iter != end) && (run == *iter + 1))
		{
			run = *iter;
			++iter;
		}
	}

	return m_score;
}

int nothanks_player_state::get_chips_count()
{
	return m_EarnedCounters;
}

void nothanks_player_state::addCard(int c)
{
	m_cards.push_back(c);
	return;
}

const bool nothanks_player_state::can_Play_Counter()
{
	return (m_EarnedCounters > 0);
}

void nothanks_player_state::removeCounter()
{
	m_EarnedCounters--;
	_ASSERT(m_EarnedCounters > 0);
}
