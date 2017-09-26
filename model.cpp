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
// type model::MÈthode ( liste de paramËtres )
// Algorithm :
//
//{
//} //----- End of method

//---------------------------------------------- Constructors - destructor
model::model(const model &unmodel)
// Algorithm :
//
{
#ifdef MAP
    cout << "Call of copy constructor <model>" << endl;
#endif
} //----- End of model (Copy constructor)


model::model()
// Algorithm :
//
{
#ifdef MAP
    cout << "Call of constructor <model>" << endl;
#endif
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
const void log(const std::string log)
// Algorithm : N/A
{
#ifdef MAP
    cout << "Call of the logger" << endl;
#endif
    std::cerr << log << std::endl;
} //----- End of model
