// ============================================================================
// File: CBinaryNode.h
// ============================================================================
// Header file for the class CBinaryNode
// ============================================================================
 
#ifndef CBINARY_NODE_HEADER
#define CBINARY_NODE_HEADER

template<class ItemType>
class CBinaryNode
{   
public:
   // =========================================================================
   //      Constructors and Destructor
   // =========================================================================

   /** Initializes left and right child ptr to nullptr and leaves m_item as
       garbage. */
   CBinaryNode();

   /** Initializes m_item and sets left and right child ptr to nullptr. */
   CBinaryNode(const ItemType &item);

   /** Initializes all the private data members with the supplied arguments. */
   CBinaryNode(const ItemType &item,
              CBinaryNode<ItemType> *leftChildPtr,
              CBinaryNode<ItemType> *rightChildPtr);

   // =========================================================================
   //      Member Functions
   // =========================================================================

   /** Assigns item to m_item
    @param item  The data value (passed by reference) to add to the node.
    @return  Nothing. */
   void 				  SetItem(const ItemType &item);

   /** Retrieves m_item
    @param Nothing.
    @return  ItemType */
   ItemType 			  GetItem() const;

   /** Checks if a node is a leaf.
    @param Nothing.
    @return  True if the node is a leaf, or false if it is not. */
   bool 				  IsLeaf() const;

   /** Retrieves the pointer to the left node (left child).
    @param Nothing.
    @return  CBinaryNode<ItemType>*. A templated pointer to the left node. */
   CBinaryNode<ItemType>* GetLeftChildPtr() const;

   /** Retrieves the pointer to the right node (right child).
    @param Nothing.
    @return  CBinaryNode<ItemType>*. A templated pointer to the right node. */
   CBinaryNode<ItemType>* GetRightChildPtr() const;

   /** Assigns a pointer to the left node (left child).
    @param CBinaryNode<ItemType>*. A templated pointer to the left node.
    @return  Nothing. */
   void   SetLeftChildPtr(CBinaryNode<ItemType> *leftChildPtr);

   /** Assigns a pointer to the right node (right child).
    @param CBinaryNode<ItemType>*. A templated pointer to the right node.
    @return  Nothing. */
   void   SetRightChildPtr(CBinaryNode<ItemType> *rightChildPtr);
   
private:
   // =========================================================================
   //      Data Members
   // =========================================================================

   ItemType                m_item;           // Data portion
   CBinaryNode<ItemType>  *m_leftChildPtr;   // Pointer to left child
   CBinaryNode<ItemType>  *m_rightChildPtr;  // Pointer to right child
}; // end CBinaryNode

#include "CBinaryNode.tpp"

#endif 
