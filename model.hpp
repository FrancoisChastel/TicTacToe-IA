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

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Class's job <model>
//      - Hold the model (basically a minimax with a-b pruning algorithms)
//      in order to solve A2 assignement in AI course at KTH
//------------------------------------------------------------------------

// Specification template :
//      - T         : object on the node of the Binary Tree. For that
//                    purpose you need to overload your operators.
template<typename T>
class model {
//----------------------------------------------------------------- PUBLIC

public:
    //------------------------------------------------------- Publics methods
    T* addElement(T element);
    // Parameters :
    //
    // Manual :
    //
    // Contract :
    //

//-------------------------------------------------- Operators overloading
    model &operator=(const model &amodel);
    // Manual :
    //
    // Contract :
    //

//---------------------------------------------- Constructors - destructor
    model(const model &amodel);
    // Manual :
    //
    // Contract :
    //


    model();
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

protected:
//--------------------------------------------------- Protected attributes

private:
//----------------------------------------------------- Private attributes

//-------------------------------------------------------- Friends classes

//-------------------------------------------------------- Private classes

//---------------------------------------------------------- Private types


};

//---------------------------------------- Dependant's types of <model>

#endif // MODEL_HPP
