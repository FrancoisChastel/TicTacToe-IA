/*************************************************************************
                        model  -  description
 -------------------
 Begin                : 26/09/2017
 Copyright            : (C) 2017 by Francois
 *************************************************************************/

//---------- Interface of <model>'s class (file model.h) -------------

#if !defined ( MODEL_HPP )
#define MODEL_HPP

//-------------------------------------------------------- Used interfaces
#include <iostream>
#include "gamestate.hpp"
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
// Class's job <model>
//      - Hold the model (basically a minimax with a-b pruning algorithms)
//      in order to solve A2 assignement in AI course at KTH.
//      - I would like you to notice that this class is "model" and not
//      "Model", in my opinion the second option is usually better for
//      readability reason but I prefer to fit in the existing code.
//------------------------------------------------------------------------

class model {
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
    model(TICTACTOE::Cell currentCell);
    // Manual :
    //
    // Contract :
    //


    virtual ~model();
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
    // Manual :
    //
    // Contract :
    //

    int scoringState(const TICTACTOE::GameState aState,
                     TICTACTOE::Cell targetCell);
    // Manual :
    //
    // Contract :
    //

    int computeScore(const int alignedCells);
    // Manual :
    //
    // Contract :
    //

    int computeContiniousList(std::vector<TICTACTOE::Cell> cell,
                              TICTACTOE::Cell targetedCell);
    // Manual :
    //
    // Contract :
    //

protected:
//--------------------------------------------------- Protected attributes

private:
//----------------------------------------------------- Private attributes
    TICTACTOE::Cell ownCell;
//-------------------------------------------------------- Friends classes

//-------------------------------------------------------- Private classes

//---------------------------------------------------------- Private types


};

//---------------------------------------- Dependant's types of <model>

#endif // MODEL_HPP
