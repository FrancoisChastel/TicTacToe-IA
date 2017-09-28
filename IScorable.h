/*************************************************************************
                        IScorable  -  description
 -------------------
 Begin                : 28/09/2017
 Copyright            : (C) 2017 by Francois
 *************************************************************************/

//---------- Interface of <IScorable>'s class (file IScorable.h) -------------
#if !defined ( ISCORABLE_H )
#define ISCORABLE_H

//-------------------------------------------------------- Used interfaces

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Class's job <IScorable>
//
//
//------------------------------------------------------------------------

// Specification template :
//      - T         : object on the node of the Binary Tree. For that
//                    purpose you need to overload your operators ;
//      - TCompare  : object part of T object, you can add, search and
//                    delete based on this TCompare. For that purpose you
//                    need to overload your operator.
template<typename T, typename TCompare>
class IScorable {
//----------------------------------------------------------------- PUBLIC

public:
//------------------------------------------------------- Publics methods
    // T* addElement(TCompare element);
    // Parameters :
    //
    // Manual :
    //
    // Contract :
    //

//---------------------------------------------- Constructors - destructor
    IScorable();
    // Manual :
    //
    // Contract :
    //


    virtual ~IScorable();
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

//-------------------------------------------------------- Friends classes

//-------------------------------------------------------- Private classes

//---------------------------------------------------------- Private types


};

//---------------------------------------- Dependant's types of <IScorable>

#endif // ISCORABLE_H
