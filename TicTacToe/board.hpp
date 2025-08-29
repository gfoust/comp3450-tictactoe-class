#include <array>
#include "cell.hpp"

namespace tic {


  const int BOARD_SIZE = 3;

  class Board {
  public:
    using Row = std::array<Cell, BOARD_SIZE>;
    using Grid = std::array<Row, BOARD_SIZE>;

    Board();

    void clear();
    Cell get(int row, int col);
    void set(int row, int col, Cell cell);

  private:
    Grid grid = {};


  };

}