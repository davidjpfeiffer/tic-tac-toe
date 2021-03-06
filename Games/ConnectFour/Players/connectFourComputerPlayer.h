#ifndef __CONNECTFOURCOMPUTERPLAYER
#define __CONNECTFOURCOMPUTERPLAYER

#include <vector>

#include "../connectFourPlayer.h"
#include "../connectFourGameState.h"

class ConnectFourComputerPlayer : public ConnectFourPlayer
{
  public:

  std::string getName() const
  {
    return "Computer Player";
  }
  
  Player * clone() const
  {
    return new ConnectFourComputerPlayer;
  }
  
  void getMove(GameState * p_gameState)
  {
    ConnectFourGameState * gameState = (ConnectFourGameState *)p_gameState;
    std::vector<unsigned> availableMoves = gameState->board.getAvailableMoves();
    ConnectFourGameState theoreticalGameState;
    
    // If we can win, take win
    
    for(unsigned move : availableMoves)
    {
      theoreticalGameState.board = gameState->board;
      theoreticalGameState.board.set(move, getBoardValue());
      
      if (this->gameDefinition.playerHasWon(& theoreticalGameState, getPlayerValue()))
      {
        gameState->board.set(move, getBoardValue());
        return;
      }
    }
    
    // If we can prevent win, prevent win
    
    for(unsigned move : availableMoves)
    {
      theoreticalGameState.board = gameState->board;
      theoreticalGameState.board.set(move, getOpponentBoardValue());
      
      if (this->gameDefinition.playerHasWon(& theoreticalGameState, getOpponentPlayerValue()))
      {
        gameState->board.set(move, getBoardValue());
        return;
      }
    }
    
    // Default to random move
    
    this->gameDefinition.makeRandomMove(p_gameState, this->getPlayerValue());
  }
};

#endif