/*************************************************************************
                        tree  -  description
 -------------------
 Begin                : 26/09/2017
 copyright            : (C) 2017 par Francois
 *************************************************************************/

//---------- Realization of <tree>'s class (file tree.cpp) --

//---------------------------------------------------------------- INCLUDE

//------------------------------------------------------- System's include

//---------------------------------------------------- Personnal's include
#include "tree.hpp"
#include "gamestate.hpp"

//-------------------------------------------------------------- Constants

//-------------------------------------------------------- Class variables

//---------------------------------------------------------- Private types

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Friendly's methods


//--------------------------------------------------------- Public methods
template<typename T> int tree<T>::alphaBeta( TICTACTOE::GameState state,
                                             int depth=0,
                                             int alpha,
                                             int beta,
                                             const TICTACTOE::Cell playerCell)
// state : the current state we are analyzing
// α : the current best value achievable by A
// β : the current best value achievable by B
// targetedCell : the current player
// returns the minimax value of the s t a t e
// Algorithm :
//
{
    bool endGame = false;
    if ( playerCell == CELL_X )
    {
      endGame = state.isXWin();
    }
    else
    {
      endGame = state.isOWin();
    }

    if ( depth = 0 || endGame || state.isEOG() )
    {
      //  terminal state
      v = model::scoringState(state, targetedState);
    }

    else if ( playerCell == ACell )
    {
      // Player A, maximise the score
      v = -1000000; // -infinity

      TICTACTOE::GameState child;
      std::vector<TICTACTOE::GameState>  childStates;

      state.findPossibleMoves( childStates );

      while ( !childStates.empty() || beta < alpha)
      {
        child = childStates.back();
        childStates.pop_back();

        v = max( v, alphaBeta( child, depth - 1, alpha, beta, playerCell ) );
        alpha = max( v, alpha );
      }
    }

    else
    {
      // Player B, minimize the score
      v = 1000000; // + infinity

      TICTACTOE::GameState child;
      std::vector<TICTACTOE::GameState>  childStates;

      state.findPossibleMoves( childStates );

      while ( !childStates.empty() || beta < alpha)
      {
        child = childStates.back();
        childStates.pop_back();

        v = min( v, alphaBeta( child, depth - 1, alpha, beta, playerCell ) );
        alpha = min( v, alpha );
      }
    }

} //----- End of method

//---------------------------------------------- Constructors - destructor
template<typename T> tree<T>::tree(const int aMaxDepth)
// Algorithm :
//
{
#ifdef MAP
    cout << "Call of constructor <tree>" << endl;
#endif
    this->maxDepth = aMaxDepth;
    this->root = new node<T, int>();
} //----- End of tree


template<typename T> tree<T>::~tree()
// Algorithm :
//
{
#ifdef MAP
    cout << "Call of destructor <tree>" << endl;
#endif
} //----- End of tree

//---------------------------------------------------------------- PRIVATE

//------------------------------------------------------ Protected methods

//-------------------------------------------------------- Private methods
