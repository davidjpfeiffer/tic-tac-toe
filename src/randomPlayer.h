#ifndef __RANDOMPLAYER
#define __RANDOMPLAYER

#include "player.h"
#include "utilities.h"

class RandomPlayer : public Player
{
	public:
	
	Board getMove(const Board & board)
	{
		return makeRandomMove(board, this->getPlayerBoardValue());
	}
};

#endif