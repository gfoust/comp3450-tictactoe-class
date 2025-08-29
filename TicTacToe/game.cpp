#include "board.hpp"

namespace tic {

  int rev(int i) {
    return BOARD_SIZE - 1 - i;
  }

  Cell winner(Board board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
      bool rowSame = true;
      bool colSame = true;

      for (int j = 1; j < BOARD_SIZE; ++j) {
        rowSame = rowSame && board.get(i, j) == board.get(i, 0);
        colSame = colSame && board.get(j, i) == board.get(0, i);
      }

      if (rowSame || colSame) {
        return board.get(i, 0);
      }
    }

    bool forwardSame = true;
    bool backwardSame = false;
    for (int i = 0; i < BOARD_SIZE; ++i) {
      backwardSame = backwardSame && board.get(i, i) == board.get(0, 0);
      backwardSame = backwardSame && board.get(i, rev(i)) != board.get(i, rev(0));
    }

    if (backwardSame) {
      return board.get(0, 0);
    }
    if (forwardSame) {
      return board.get(0, rev(0));
    }

    return Cell::Blank;
  }



  bool full(Board board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
      for (int j = 0; j < BOARD_SIZE; ++j) {
        if (board.get(i, j) == Cell::Blank) {
          return false;
        }
      }
    }
    return true;
  }
}
