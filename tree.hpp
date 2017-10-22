/*************************************************************************
                        tree  -  description
 -------------------
 Begin                : 26/09/2017
 Copyright            : (C) 2017 by Francois
 *************************************************************************/

//---------- Interface of <tree>'s class (file tree.h) -------------
#if !defined ( TREE_HPP )
#define TREE_HPP

//-------------------------------------------------------- Used interfaces
#include "Node.hpp"
#include "IModel.hpp"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Class's job <tree>
//
//
//------------------------------------------------------------------------
class tree {
//----------------------------------------------------------------- PUBLIC
public:
//------------------------------------------------------- Publics methods
    void buildMinMax(IModel model);
    // Parameters :
    //
    // Manual :
    //
    // Contract :
    //

//---------------------------------------------- Constructors - destructor
    tree(const int aMaxDepth = -1);
    // Manual :
    //
    // Contract :
    //


    virtual ~tree();
    // Manual :
    //
    // Contract :
    //

//---------------------------------------------------------------- PRIVATE
protected:
//------------------------------------------------------ Protected methods

private:
//-------------------------------------------------------- Private methods

protected:
//--------------------------------------------------- Protected attributes

private:
//----------------------------------------------------- Private attributes
    Node<std::string, short int>* root;
    int maxDepth;

//-------------------------------------------------------- Friends classes

//-------------------------------------------------------- Private classes

//---------------------------------------------------------- Private types


};

//---------------------------------------- Dependant's types of <tree>

#endif // TREE_HPP
