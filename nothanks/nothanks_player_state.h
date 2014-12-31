#pragma once

#include <vector>
#include <queue>

class nothanks_player_state
{
public:
	nothanks_player_state();
	int get_score();
	int get_chips_count();
	void addCard(int c);
	const bool can_Play_Counter();
	void removeCounter();
	void addChips(int chips);

private:
	int m_score;
	int m_EarnedCounters;
	std::vector<int> m_cards;
};