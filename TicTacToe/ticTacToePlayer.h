#ifndef __TICTACTOEPLAYER
#define __TICTACTOEPLAYER

#include "ticTacToeGameDefinition.h"
#include "ticTacToeBoardValue.h"

class TicTacToePlayer : public Player
{
  private:
  
  TicTacToeBoardValue boardValue;
  TicTacToeBoardValue opponentBoardValue;
  
  void onPlayerValueSet(const PlayerValue & p_playerValue)
  {
    this->boardValue = p_playerValue == PlayerValue::PlayerOne ? TicTacToeBoardValue::O : TicTacToeBoardValue::X;
    this->opponentBoardValue = p_playerValue == PlayerValue::PlayerOne ? TicTacToeBoardValue::X : TicTacToeBoardValue::O;
  }
  
  protected:
  
  TicTacToeGameDefinition gameDefinition;
  
  public:
  
  TicTacToeBoardValue getBoardValue() const
  {
    return this->boardValue;
  }
  
  TicTacToeBoardValue getOpponentBoardValue() const
  {
    return this->opponentBoardValue;
  }
};

#endif