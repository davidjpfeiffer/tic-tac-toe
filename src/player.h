#ifndef __PLAYER
#define __PLAYER

#include <string>
#include <cstring>
#include "utilities.h"

class Player
{
private:

  BoardValue boardValue;
  BoardValue opponentBoardValue;

public:

  virtual Board getMove(const Board &) = 0;

  std::string getName()
  {
    std::string prefix = "Player ";
    char playerNumber = getBoardValueAsChar(this->getBoardValue());
    return prefix + playerNumber;
  }
  
  void setBoardValue(BoardValue boardValue)
  {
    this->boardValue = boardValue;
    this->opponentBoardValue = this->boardValue == BoardValue::PlayerTwo ? BoardValue::PlayerOne : BoardValue::PlayerTwo;
  }

  BoardValue getBoardValue()
  {
    return this->boardValue;
  }

  BoardValue getOpponentBoardValue()
  {
    return this->opponentBoardValue;
  }
};

#endif