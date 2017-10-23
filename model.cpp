/*************************************************************************
                        model  -  description
 -------------------
 Begin                : 26/09/2017
 copyright            : (C) 2017 par Francois
 *************************************************************************/

//---------- Realization of <Model>'s class (file Model.cpp) --

//---------------------------------------------------------------- INCLUDE

//------------------------------------------------------- System's include

//---------------------------------------------------- Personnal's include
#include "Model.hpp"

//-------------------------------------------------------------- Constants

//-------------------------------------------------------- Class variables

//---------------------------------------------------------- Private types

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Friendly's methods


//--------------------------------------------------------- Public methods
TICTACTOE::GameState Model::obtainBestMove(TICTACTOE::GameState currentState)
// Algorithm : N/A
{

    return currentState;
} //----- End of method



int Model::scoringState(const TICTACTOE::GameState aState, const TICTACTOE::Cell targetedCell)
// Algorithm : N/A
{
    int theScore = 0;

    std::vector<TICTACTOE::Cell> continuousList(SZ_BOARD, TICTACTOE::CELL_EMPTY);

    // Compute-Row
    for (int row=0; row < SZ_BOARD; row++)
    {
        for (int col=0; col < SZ_BOARD; col++)
        {
            continuousList[col] = (TICTACTOE::Cell) aState.at(row, col);
        }
        theScore += computeScore(continuousList, targetedCell);
    }

    // Compute-Line
    for (int col=0; col < SZ_BOARD; col++)
    {
        for (int row=0; row < SZ_BOARD; row++)
        {
            continuousList[row] = (TICTACTOE::Cell) aState.at(row, col);
        }
        theScore += computeScore(continuousList, targetedCell);
    }

    std::vector<TICTACTOE::Cell> continuousList2(SZ_BOARD, TICTACTOE::CELL_EMPTY);
    // Compute-Diagoline
    for (int cursor=0; cursor < SZ_BOARD; cursor++)
    {
        continuousList[cursor] = (TICTACTOE::Cell) aState.at(cursor, cursor);
        continuousList2[cursor] = (TICTACTOE::Cell) aState.at((SZ_BOARD - 1) - cursor, cursor);

    }
    theScore += computeScore(continuousList, targetedCell) +
                computeScore(continuousList2, targetedCell);


    return theScore;
} //----- End of method


int Model::computeScore(const std::vector<TICTACTOE::Cell> cell,
                        const TICTACTOE::Cell targetedCell)
{

    int NumberOfGoodCells = 0;
    int NumberOfOpponentCells = 0;

    TICTACTOE::Cell opponentCell = TICTACTOE::CELL_X;

    if ((TICTACTOE::Cell) targetedCell ==  TICTACTOE::CELL_X) opponentCell = TICTACTOE::CELL_O;

    for (int cursor = 0; cursor < cell.size(); cursor++)
    {
        if ((TICTACTOE::Cell) cell[cursor] == targetedCell) NumberOfGoodCells++;

        if ((TICTACTOE::Cell) cell[cursor] == opponentCell) NumberOfOpponentCells++;
    }

    return Heuristic_Array[NumberOfGoodCells][NumberOfOpponentCells];
} //----- End of method


//---------------------------------------------- Constructors - destructor
Model::Model(TICTACTOE::Cell currentCell)
// Algorithm :
//
{
#ifdef MAP
    cout << "Call of constructor <Model>" << endl;
#endif
    this->ownedCell = currentCell;
} //----- End of Model


Model::~Model()
// Algorithm :
//
{
#ifdef MAP
    cout << "Call of destructor <Model>" << endl;
#endif
} //----- End of Model

//---------------------------------------------------------------- PRIVATE

//------------------------------------------------------ Protected methods

//-------------------------------------------------------- Private methods
const void Model::log(const std::string log)
// Algorithm : N/A
{
#ifdef MAP
    cout << "Call of the logger" << endl;
#endif
    std::cerr << log << std::endl;
} //----- End of Model


Node<TICTACTOE::GameState, std::pair<int, int>>* Model::obtainBestNode(TICTACTOE::GameState currentState,
                                                                       int depth=0,
                                                                       bool isOpponent=false)
// Algorithm :
//  - Min-max ;
//  - alpha-beta pruning ;
//  - hashing.
{
    depth++;

    if (depth == DEEPEST_POSSIBLE ||
            (currentState.isEOG() || currentState.isOWin() || currentState.isXWin()))
    {
        int score = this->scoringState(currentState, this->ownedCell);

        // Nega-max simplification
        if (isOpponent) score = -score;

        return new Node<TICTACTOE::GameState, std::pair<int, int>>(currentState,
                                                                   std::make_pair(score, score));
    }
    else
    {
        std::vector<TICTACTOE::GameState> pMoves;
        currentState.findPossibleMoves(pMoves);
        Node<TICTACTOE::GameState, std::pair<int, int>>* node = new Node<TICTACTOE::GameState, std::pair<int, int>>(currentState,
                                                                                                                    std::make_pair(INT8_MIN, INT8_MIN));


        for (TICTACTOE::GameState pMove : pMoves)
        {
            Node<TICTACTOE::GameState, std::pair<int, int>>* son = obtainBestNode(pMove, depth, !isOpponent);

            // Nega-max simplification
            if (node->score.first < -son->score.first) node->score.first = -son->score.first;


            node->addNode();
        }

    }
}
