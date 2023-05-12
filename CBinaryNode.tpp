// ============================================================================
// File: CBinaryNode.tpp
// ============================================================================
// Implementation file for the class CBinaryNode
// ============================================================================

// #REF
   // ItemType                m_item;           // Data portion
  // CBinaryNode<ItemType>  *m_leftChildPtr;   // Pointer to left child
  // CBinaryNode<ItemType>  *m_rightChildPtr;  // Pointer to right child


// ==== CBinaryNode<ItemType>::CBinaryNode =====================================
//
// This is the default constructor for CBinaryNode<ItemType>.  It initializes
// the left and right child pointer to nullptr and leave m_item as garbage.
//
// Input:
//       void
//       
// Output:
//       Nothing
//
// =============================================================================
template<class ItemType>
CBinaryNode<ItemType>::CBinaryNode() 
   : m_leftChildPtr(nullptr), m_rightChildPtr(nullptr)
{
   
}   // end of  CBinaryNode<ItemType>::CBinaryNode(default CTOR)




// ==== CBinaryNode<ItemType>::CBinaryNode =====================================
//
// This is the type constructor for CBinaryNode<ItemType>.  It initializes
// m_item and sets the left and right child pointer to nullptr.
//
// Input:
//       item [IN]      - A const ItemType reference to initialize the new node.
//       
// Output:
//       Nothing
//
// =============================================================================
template<class ItemType>
CBinaryNode<ItemType>::CBinaryNode(const ItemType &item) 
    : m_item(item), m_leftChildPtr(nullptr), m_rightChildPtr(nullptr)
{
    
}   // end of  CBinaryNode<ItemType>::CBinaryNode(Type CTOR)




// ==== CBinaryNode<ItemType>::CBinaryNode =====================================
//
// This is the type constructor for CBinaryNode<ItemType>.  It initializes all
// the private data members with the supplied arguments.
//
// Input:
//       item           [IN]    - A const ItemType reference to initialize the
//                                  new node.
//       leftChildPtr   [IN]    - A CBinaryNode<ItemType> pointer that points to
//                                  the left child.
//       rightChildPtr  [IN]    - A CBinaryNode<ItemType> pointer that points to
//                                  the right child.
//       
// Output:
//       Nothing
//
// =============================================================================
template<class ItemType>
CBinaryNode<ItemType>::CBinaryNode(const ItemType &item, 
              CBinaryNode<ItemType> *leftChildPtr,
              CBinaryNode<ItemType> *rightChildPtr)
    : m_item(item), m_leftChildPtr(leftChildPtr), m_rightChildPtr(rightChildPtr)
{
    
}   // end of  CBinaryNode<ItemType>::CBinaryNode(Type CTOR)




// ==== CBinaryNode<ItemType>::SetItem =========================================
//
// This function assigns a value to m_item.
//
// Input:
//       item [IN]      - A const ItemType reference.
//       
// Output:
//       void
//
// =============================================================================
template<class ItemType>
void    CBinaryNode<ItemType>::SetItem(const ItemType &item)
{
    m_item = item;
    
}   //end of CBinaryNode<ItemType>::SetItem




// ==== CBinaryNode<ItemType>::GetItem =========================================
//
// This function returns the value of m_item.
//
// Input:
//       void
//
// Output:
//       An ItemType.
//
// =============================================================================
template<class ItemType>
ItemType    CBinaryNode<ItemType>::GetItem() const
{
    return m_item;
    
}   //end of ItemType    CBinaryNode::GetItem() const




// ==== CBinaryNode<ItemType>::IsLeaf ==========================================
//
// This function checks if the node is a leaf.
//
// Input:
//       void
//
// Output:
//       Returns true if the node is a leaf, false otherwise.
//
// =============================================================================
template<class ItemType>
bool    CBinaryNode<ItemType>::IsLeaf() const
{
    if (m_leftChildPtr == nullptr && m_rightChildPtr == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}





// ==== CBinaryNode<ItemType>::GetLeftChildPtr =================================
//
// This function returns the pointer to the left node.
//
// Input:
//       void
//
// Output:
//       Returns a CBinaryNode<ItemType> pointer.
//
// =============================================================================
template<class ItemType>
CBinaryNode<ItemType>*  CBinaryNode<ItemType>::GetLeftChildPtr() const
{
    return m_leftChildPtr;
    
}   // end of CBinaryNode<ItemType>::GetLeftChildPtr




// ==== CBinaryNode<ItemType>::GetRightChildPtr ================================
//
// This function returns the pointer to the right node.
//
// Input:
//       void
//
// Output:
//       Returns a CBinaryNode<ItemType> pointer.
//
// =============================================================================
template<class ItemType>
CBinaryNode<ItemType>*  CBinaryNode<ItemType>::GetRightChildPtr() const
{
    return m_rightChildPtr;
    
}   // end of CBinaryNode<ItemType>::GetRightChildPtr




// ==== CBinaryNode<ItemType>::SetLeftChildPtr =================================
//
// This function assigns the poitner to the left node.
//
// Input:
//       leftChildPtr   [IN]    - A CBinaryNode<ItemType> pointer to the left
//                                  node.
//       
// Output:
//       void
//
// =============================================================================
template<class ItemType>
void   CBinaryNode<ItemType>::SetLeftChildPtr
            (CBinaryNode<ItemType> *leftChildPtr)
{
    m_leftChildPtr = leftChildPtr;
    
}   // end of CBinaryNode<ItemType>::SetLeftChildPtr




// ==== CBinaryNode<ItemType>::SetRightChildPtr ================================
//
// This function assigns the poitner to the right node.
//
// Input:
//       rightChildPtr   [IN]    - A CBinaryNode<ItemType> pointer to the left
//                                  node.
//       
// Output:
//       void
//
// =============================================================================
template<class ItemType>
void   CBinaryNode<ItemType>::SetRightChildPtr       
        (CBinaryNode<ItemType> *rightChildPtr)
{
    m_rightChildPtr = rightChildPtr;
    
}   // end of CBinaryNode<ItemType>::SetRightChildPtr

