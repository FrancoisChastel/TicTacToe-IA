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
void tree::buildMinMax(IModel model,
                       int depth=0,
                       TICTACTOE::GameState possibleState)
// Algorithm :
//
{
    depth++;

    if (depth > this->maxDepth)
    {
        break;
    }
    else
    {

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
