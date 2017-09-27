/*************************************************************************
                        node  -  description
 -------------------
 Begin                : 27/09/2017
 Copyright            : (C) 2017 by Francois
 *************************************************************************/

//---------- Interface of <node>'s class (file node.h) -------------
#if !defined ( NODE_HPP )
#define NODE_HPP

//-------------------------------------------------------- Used interfaces

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Class's job <node>
//
//
//------------------------------------------------------------------------

// Specification template :
//      - T         : object that will be hold in the node of the tree
//      - TScore    : object that will be hold in the node of the tree
template<typename T, typename TScore>
class node {
//----------------------------------------------------------------- PUBLIC
public:
//------------------------------------------------------- Publics methods
    void buildMinMax(void (*function)(int,int));
    // Parameters :
    //
    // Manual :
    //
    // Contract :
    //

//---------------------------------------------- Constructors - destructor
    node(T aValue = nullptr, TScore aScore = nullptr)
    // Manual :
    //
    // Contract :
    //
    {
        this->value = aValue;
        this->score = aScore;
    }


    virtual ~node()
    // Manual :
    //
    // Contract :
    //
    {
        delete left;
        delete right;
        delete value;
        delete score;
    }

//---------------------------------------------------------------- PRIVATE
protected:
//------------------------------------------------------ Protected methods

private:
//-------------------------------------------------------- Private methods

protected:
//--------------------------------------------------- Protected attributes

private:
//----------------------------------------------------- Private attributes
    node<T, TScore>*    left;
    node<T, TScore>*    right;
    T                   value;
    TScore              score;

//-------------------------------------------------------- Friends classes

//-------------------------------------------------------- Private classes

//---------------------------------------------------------- Private types


};

//---------------------------------------- Dependant's types of <tree>

#endif // NODE_HPP

