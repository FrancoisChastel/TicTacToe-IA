/*************************************************************************
                        node  -  description
 -------------------
 Begin                : 27/09/2017
 Copyright            : (C) 2017 by Francois
 *************************************************************************/

//---------- Interface of <node>'s class (file node.h) -------------
#include <vector>

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
class Node {
//----------------------------------------------------------------- PUBLIC
public:
//------------------------------------------------------- Publics methods
    Node<T, TScore>* getNode(int index)
    // Parameters :
    //
    // Manual :
    //
    // Contract :
    //
    {
        return this->nodes[index];
    };

    unsigned long size()
    // Parameters :
    //
    // Manual :
    //
    // Contract :
    //
    {
        return this->nodes.size();
    };

    void addNode(Node<T, TScore>* node)
    // Parameters :
    //
    // Manual :
    //
    // Contract :
    //
    {
        this->nodes.push_back(node);
    };

    TScore getScore()
    // Parameters :
    //
    // Manual :
    //
    // Contract :
    //
    {
        return score;
    };

//---------------------------------------------- Constructors - destructor
    Node(T aValue = nullptr,
         TScore aScore = nullptr)
    // Manual :
    //
    // Contract :
    //
    {
        this->value = aValue;
        this->score = aScore;
    }


    virtual ~Node()
    // Manual :
    //
    // Contract :
    //
    {
        for (Node<T, TScore> * element : nodes)
        {
            delete element;
        }
        delete value;
        delete score;
    }

    T                               value;
    TScore                          score;


//---------------------------------------------------------------- PRIVATE
protected:
//------------------------------------------------------ Protected methods

private:
//-------------------------------------------------------- Private methods

protected:
//--------------------------------------------------- Protected attributes

private:
//----------------------------------------------------- Private attributes
    std::vector<Node<T, TScore>*>   nodes;

//-------------------------------------------------------- Friends classes

//-------------------------------------------------------- Private classes

//---------------------------------------------------------- Private types


};

//---------------------------------------- Dependant's types of <tree>

#endif // NODE_HPP

