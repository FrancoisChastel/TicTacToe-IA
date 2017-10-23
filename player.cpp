#include "player.hpp"
#include "Model.hpp"
#include <cstdlib>

namespace TICTACTOE
{

GameState Player::play(const GameState &pState,const Deadline &pDue)
{
    Model* model = new Model((TICTACTOE::Cell) pState.getNextPlayer());
    model->obtainBestMove(pState);

    std::vector<TICTACTOE::GameState> pMoves;
    pState.findPossibleMoves(pMoves);
    return pMoves[0];
}

/*namespace TICTACTOE*/ }
