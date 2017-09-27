/*************************************************************************
                        model  -  description
 -------------------
 Begin                : 26/09/2017
 copyright            : (C) 2017 par Francois
 *************************************************************************/

//---------- Realization of <model>'s class (file model.cpp) --

//---------------------------------------------------------------- INCLUDE

//------------------------------------------------------- System's include

//---------------------------------------------------- Personnal's include
#include "model.hpp"

//-------------------------------------------------------------- Constants

//-------------------------------------------------------- Class variables

//---------------------------------------------------------- Private types

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Friendly's methods


//--------------------------------------------------------- Public methods
TICTACTOE::GameState model::obtainBestMove(TICTACTOE::GameState currentState)
// Algorithm :
{
    return currentState;
} //----- End of method



int model::scoringState(const TICTACTOE::GameState aState, TICTACTOE::Cell targetedCell)
// Algorithm : x/A
{
    int theScore = 0;

    std::vector<TICTACTOE::Cell> continuousList(SZ_BOARD, TICTACTOE::CELL_EMPTY);

    // Compute-Row
    for (int row=0; row < SZ_BOARD; row++)
    {
        for (int col=0; row < SZ_BOARD; col++)
        {
            continuousList[col] = (TICTACTOE::Cell) aState.at(row, col);
        }
        theScore += computeScore(computeContiniousList(continuousList, targetedCell));
    }

    // Compute-Line
    for (int col=0; col < SZ_BOARD; col++)
    {
        for (int row=0; row < SZ_BOARD; row++)
        {
            continuousList[row] = (TICTACTOE::Cell) aState.at(row, col);
        }
        theScore += computeScore(computeContiniousList(continuousList, targetedCell));
    }

    std::vector<TICTACTOE::Cell> continuousList2(SZ_BOARD, TICTACTOE::CELL_EMPTY);
    // Compute-Diagoline
    for (int cursor=0; cursor < SZ_BOARD; cursor++)
    {
        continuousList[cursor] = (TICTACTOE::Cell) aState.at(cursor, cursor);
        continuousList2[cursor] = (TICTACTOE::Cell) aState.at(SZ_BOARD - cursor, cursor);

    }
    theScore += computeScore(computeContiniousList(continuousList, targetedCell)) +
                computeScore(computeContiniousList(continuousList2, targetedCell));


    return theScore;
} //----- End of method



int model::computeScore(const int alignedCells)
{
    int score;

    switch (alignedCells)
    {
        case 0 :
            score = PD_0_ALIGNED;
            break;
        case 1 :
            score = PD_1_ALIGNED;
            break;
        case 2 :
            score = PD_2_ALIGNED;
            break;
        case 3 :
            score = PD_3_ALIGNED;
            break;
        case 4 :
            score = PD_VICTORY;
            break;
        default:
            score = PD_0_ALIGNED;
            break;
    }

    return score;
} //----- End of method

int model::computeContiniousList(std::vector<TICTACTOE::Cell> cell,
                                 TICTACTOE::Cell targetedCell)
{
    //TODO : heuristic
    int theNumberOfContinuous = 0;
    int aNumberOfContinuous = 0;

    for (int cursor = 0; cursor < cell.size(); cursor++)
    {
        if ((TICTACTOE::Cell) cell[cursor] != targetedCell) aNumberOfContinuous = 0;
        else                                                aNumberOfContinuous++;

        if (aNumberOfContinuous > theNumberOfContinuous) theNumberOfContinuous = aNumberOfContinuous;
    }

    return theNumberOfContinuous;
} //----- End of method


//---------------------------------------------- Constructors - destructor
model::model(TICTACTOE::Cell currentCell)
// Algorithm :
//
{
#ifdef MAP
    cout << "Call of constructor <model>" << endl;
#endif
    this->ownCell = currentCell;
} //----- End of model


model::~model()
// Algorithm :
//
{
#ifdef MAP
    cout << "Call of destructor <model>" << endl;
#endif
} //----- End of model

//---------------------------------------------------------------- PRIVATE

//------------------------------------------------------ Protected methods

//-------------------------------------------------------- Private methods
const void model::log(const std::string log)
// Algorithm : N/A
{
#ifdef MAP
    cout << "Call of the logger" << endl;
#endif
    std::cerr << log << std::endl;
} //----- End of model
