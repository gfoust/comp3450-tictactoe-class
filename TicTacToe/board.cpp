#include "board.hpp"
#include <string>
#include <stdexcept>

namespace tic {

  Board::Board() {
    for (Row& row : grid) {
      for (Cell& cell : row) {
        cell = Cell::Blank;
      }
    }
  }


  void checkPosition(int row, int col) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
      throw std::logic_error(
        "Invalid board position: " +
        std::to_string(row) +
        ", " +
        std::to_string(col)
      );
    }
  }


  Cell Board::get(int row, int col) {
    checkPosition(row, col);
    return grid[row][col];
  }


  void Board::set(int row, int col, Cell cell) {
    checkPosition(row, col);
    if (cell != Cell::Blank && grid[row][col] != Cell::Blank) {
      throw std::logic_error("Cell must be blank");
    }
    grid[row][col] = cell;
  }

}