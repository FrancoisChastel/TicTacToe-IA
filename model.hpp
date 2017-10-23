/*************************************************************************
                        model  -  description
 -------------------
 Begin                : 26/09/2017
 Copyright            : (C) 2017 by Francois
 *************************************************************************/

//---------- Interface of <Model>'s class (file Model.h) -------------

#if !defined ( MODEL_HPP )
#define MODEL_HPP

//-------------------------------------------------------- Used interfaces
#include <iostream>
#include "gamestate.hpp"
#include "tree.hpp"

//------------------------------------------------------------- Constantes
const int Heuristic_Array[4][4] = {
  {     0,   -10,  -100, -10000 },
  {    10,     0,     0,     0 },
  {   100,     0,     0,     0 },
  {  10000,     0,     0,     0 }
};
const int PD_VICTORY      = INT8_MAX;
const int SZ_BOARD        = 4;
const int DEEPEST_POSSIBLE= 0;

//------------------------------------------------------------------------
// Class's job <Model>
//      - Hold the Model (basically a minimax with a-b pruning algorithms)
//      in order to solve A2 assignement in AI course at KTH.
//      - I would like you to notice that this class is "Model" and not
//      "Model", in my opinion the second option is usually better for
//      readability reason but I prefer to fit in the existing code.
//------------------------------------------------------------------------

class Model {
//----------------------------------------------------------------- PUBLIC

public:
//------------------------------------------------------- Publics methods
    TICTACTOE::GameState obtainBestMove(TICTACTOE::GameState currentState);
    // Parameters :
    //
    // Manual :
    //
    // Contract :
    //


//---------------------------------------------- Constructors - destructor
    Model(TICTACTOE::Cell targetedCell);
    // Manual :
    //
    // Contract :
    //

    virtual ~Model();
    // Manual :
    //
    // Contract :
    //

//---------------------------------------------------------------- PRIVATE
protected:
//------------------------------------------------------ Protected methods

private:
//-------------------------------------------------------- Private methods
    const void log(const std::string log);
    // Parameters :
    //
    // Manual :
    //
    // Contract :
    //

    int scoringState(const TICTACTOE::GameState aState,
                     const TICTACTOE::Cell targetCell);
    // Parameters :
    //
    // Manual :
    //
    // Contract :
    //

    int computeScore(const std::vector<TICTACTOE::Cell> cell,
                     const TICTACTOE::Cell targetedCell);
    // Parameters :
    //
    // Manual :
    //
    // Contract :
    //

    Node<TICTACTOE::GameState, std::pair<int,int>>* obtainBestNode(TICTACTOE::GameState currentState,
                                                                   int depth=0,
                                                                   bool isOpponent=false);
    // Parameters :
    //
    // Manual :
    //
    // Contract :
    //

protected:
//--------------------------------------------------- Protected attributes

private:
//----------------------------------------------------- Private attributes
    TICTACTOE::Cell ownedCell;

//-------------------------------------------------------- Friends classes

//-------------------------------------------------------- Private classes

//---------------------------------------------------------- Private types


};

//---------------------------------------- Dependant's types of <Model>

#endif // MODEL_HPP
