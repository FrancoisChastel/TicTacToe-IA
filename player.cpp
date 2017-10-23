#include "player.hpp"
#include "Model.hpp"
#include <cstdlib>

namespace TICTACTOE
{

GameState Player::play(const GameState &pState,const Deadline &pDue)
{
    Model* model = new Model((TICTACTOE::Cell) pState.getNextPlayer());

    return model->obtainBestMove(pState);
}

/*namespace TICTACTOE*/ }
