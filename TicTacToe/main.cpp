#include <iostream>

void playGame() {
  io::printIntroduction();

  tic::Game game;

  //Params params = io::getGameParameters();
  //game.setup(params);

  while (!game.isOver()) {
    io::printBoard(game.board());
    Loc move = io::getNextMove(game.board());
    game.makeMove(move);
  }

  io::printResults(game.winner());
    
}

int main() {

  try {
    playGame();
  }
  catch (std::exception& error) {
    std::cerr << "ERROR: " << error.what() << std::endl;
  }
}