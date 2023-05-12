// ============================================================================
// File: CBST.tpp
// ============================================================================
// Implementation file for the class CBST
// ============================================================================



// ==== CBST<ItemType>::CBST ===================================================
//
// This is the default constructor for CBST<ItemType>. It sets the root to
// nullptr.
//
// Input:
//       void
//       
// Output:
//       Nothing
//
// =============================================================================
template<class ItemType>
CBST<ItemType>::CBST()
{
    this->SetRootPtr(nullptr);
    
}




// ==== CBST<ItemType>::CBST ===================================================
//
// This is the type constructor for CBST<ItemType>.  It allocates a space for a
// CBinaryNode and sets it equal to m_rootPtr.  The new node will have it's
// right and left child pointers set to nullptr.
//
// Input:
//       rootItem   [IN]    - A const reference ItemType.
//       
// Output:
//       Nothing
//
// =============================================================================
template<class ItemType>
CBST<ItemType>::CBST(const ItemType &rootItem)
{
    // utilizes type CTOR from CBinaryNode class
    CBinaryNode<ItemType>    *newNode;
    newNode = new CBinaryNode<ItemType>(rootItem);
    this->SetRootPtr(newNode);
   
    
}





// ==== CBST<ItemType>::CBST ===================================================
//
// This is the copy constructor for CBST<ItemType>. It creates a deep copy of
// "tree."
//
// Input:
//       tree   [IN]    - A const templated CBST that will be copied.
//       
// Output:
//       Nothing
//
// =============================================================================
template<class ItemType>
CBST<ItemType>::CBST(const CBST<ItemType> &tree)
{
    //gets root of &tree and uses CopyTree() to copy tree to nodeCopy
    CBinaryNode<ItemType>   *nodeCopy = this->CopyTree(tree.GetRootPtr());
    this->SetRootPtr(nodeCopy);
    
}





// ==== CBST<ItemType>::~CBST ==================================================
//
// This is the destructor for CBST<ItemType>.  It will release all the nodes
// from the heap.
//
// Input:
//       void
//       
// Output:
//       Nothing
//
// =============================================================================
template<class ItemType>
CBST<ItemType>::~CBST()
{
    this->DestroyTree(this->GetRootPtr());
    
}




// ==== CBST<ItemType>::Add ====================================================
//
// This function adds an item to a tree.  Calls the PlaceNode function to add
// the node to the tree to make sure it is balanced using AVL.
//
// Input:
//       newEntry   [IN]    - A const ItemType reference to the new entry to be
//                              added to the tree.
//       
// Output:
//       Returns true if successful, otherwise false.
//
// =============================================================================
template<class ItemType>
bool    CBST<ItemType>::Add(const ItemType &newEntry)
{
    //create a node with passed item to Add
    CBinaryNode<ItemType>   *newNode = new CBinaryNode<ItemType>(newEntry);
    //calls PlaceNode() to add new node to tree
    CBinaryNode<ItemType>   *addNode = PlaceNode(this->GetRootPtr(), newNode);
    this->SetRootPtr(addNode);
    
    return this->Contains(newEntry);

}




// ==== CBST<ItemType>::Remove =================================================
//
// This function removes an entry (a node), if it exists, from the tree.
//
// Input:
//       anEntry    [IN]    - A const ItemType reference to the new entry to be
//                              added to the tree.
//
// Output:
//       Returns true if successful, otherwise false.
//
// =============================================================================
template<class ItemType>
bool    CBST<ItemType>::Remove(const ItemType &anEntry)
{
    //used to hold bool value for sucessful removal
    bool    removed = false;
    
    //creation of new node to hold new RootPtr
    CBinaryNode<ItemType>   *newNodePtr; 
    newNodePtr = RemoveValue(this->GetRootPtr(), anEntry, removed);
    this->SetRootPtr(newNodePtr);
    
    //returns value that was passed by reference when RemoveValue() called
    return removed;
    
}




// ==== CBST<ItemType>::operator= ==============================================
//
// This function assigns the right-hand side CBST to the left-hand side CBST.
// Make sure to protect against assignment to self!
//
// Input:
//       rhs    [IN]    - A const templated CBST to copy from.
// Output:
//       A templated CBST reference object (the left-hand side of the tree.
//
// =============================================================================
template<class ItemType>
CBST<ItemType>& CBST<ItemType>::operator=(const CBST<ItemType> &rhs)
{
    //checks assignment to self
     if (this != &rhs) 
     {
        this->DestroyTree(this->GetRootPtr());

        //makes a copy if rhs not empty
        if (rhs.GetRootPtr() != nullptr) 
        {
            CBinaryNode<ItemType>*  newRootPtr;
            newRootPtr = this->CopyTree(rhs.GetRootPtr());
            this->SetRootPtr(newRootPtr);
        } 
        else 
        {
            // If rhs is empty, set the root pointer to nullptr
            this->SetRootPtr(nullptr);
        }
    }

    return *this;
    
}




// ==== CBST<ItemType>::PlaceNode ==============================================
//
// This function adds a node in the tree. It makes sure that the same node value
// is not added twice.  Furthermore, as soon as it adds a node, it makes sure
// the tree is still AVL balanced.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to start the
//                              search of where to add the node.
//      nodePtr     [IN]    - A templated CBinaryNode pointer node that will be
//                              added to the tree.
// Output:
//       A CBinaryNode<ItemType> templated pointer that is the address of
//          the updated parent node pointer (after any shifts caused from AVL
//          balancing, parent node may need updating).
//
// =============================================================================
template<class ItemType>
CBinaryNode<ItemType>*  
CBST<ItemType>::PlaceNode(CBinaryNode<ItemType> *subTreePtr, 
                            CBinaryNode<ItemType> *newNode)
{
    //Uses recursion to place node in appropriate location
    
    //base case: subTree is empty
    if (subTreePtr == nullptr)
    {
        return newNode;
    }
    
    //compare values, if subTreePtr value greater, newNode placed on left
    if (subTreePtr->GetItem() > newNode->GetItem())
    {
        CBinaryNode<ItemType>   *placeLeftPtr;
        placeLeftPtr = PlaceNode(subTreePtr->GetLeftChildPtr(), newNode);
        subTreePtr->SetLeftChildPtr(placeLeftPtr);
    }
    //if subTreePtrvalue lesser or equal, newNode place on Right
    else if (subTreePtr->GetItem() <= newNode->GetItem())
    {
        CBinaryNode<ItemType>   *placeRightPtr;
        placeRightPtr = PlaceNode(subTreePtr->GetRightChildPtr(), newNode);
        subTreePtr->SetRightChildPtr(placeRightPtr);
    }
    
        //AVL tree balancing 
    
    //case: empty
    if (subTreePtr == nullptr) 
    {
        return subTreePtr;
    }

    //uses GetHeight() function to determine current height and needed rotation
    int     leftHeight  = this->GetHeight(subTreePtr->GetLeftChildPtr());
    int     rightHeight = this->GetHeight(subTreePtr->GetRightChildPtr());
    int     currentBal  = leftHeight - rightHeight;
    
    int     leftLeftHeight = 0;
    //      GetHeight(subTreePtr->GetLeftChildPtr()->GetLeftChildPtr());
    int     leftRightHeight = 0; 
    //      GetHeight(subTreePtr->GetLeftChildPtr()->GetRightChildPtr());
    int     rightRightHeight = 0;
    //      GetHeight(subTreePtr->GetRightChildPtr()->GetRightChildPtr());
    int     rightLeftHeight = 0;
    //      GetHeight(subTreePtr->GetRightChildPtr()->GetLeftChildPtr());
    
    //checks if a left child exists, if yes the assigns heights
    if (subTreePtr->GetLeftChildPtr() != nullptr)
    {
        leftLeftHeight = 
        GetHeight(subTreePtr->GetLeftChildPtr()->GetLeftChildPtr());
        
        leftRightHeight = 
        GetHeight(subTreePtr->GetLeftChildPtr()->GetRightChildPtr());
    }

    //checks if a right child exists, if yes then assigns heights
    if (subTreePtr->GetRightChildPtr() != nullptr)
    {
        rightRightHeight = 
        GetHeight(subTreePtr->GetRightChildPtr()->GetRightChildPtr());
        
        rightLeftHeight = 
        GetHeight(subTreePtr->GetRightChildPtr()->GetLeftChildPtr());
    }
    
    //case: left Left Rotation needed
    if ((currentBal > 1) && (leftLeftHeight >= leftRightHeight))
    {
        subTreePtr = RightRotate(subTreePtr);
        
    }

    //case: Right Right Rotation needed
    if ((currentBal < -1) && (rightRightHeight >= rightLeftHeight))
    {
        subTreePtr = LeftRotate(subTreePtr);
                             
    }

    //case: Left Right Rotation needed 
    if ((currentBal > 1) && (leftLeftHeight < leftRightHeight))
    {
        subTreePtr = LeftRightRotate(subTreePtr);
    }

    //case: Right Left Rotation needed
    if ((currentBal < -1) && (rightRightHeight < rightLeftHeight))
    {
        subTreePtr = RightLeftRotate(subTreePtr);
    }

    return subTreePtr;

} 




// ==== CBST<ItemType>::LeftRotate =============================================
//
// This function rotates the nodes to the left.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to start the
//                              rotation.
// Output:
//       An updated CBinaryNode<ItemType> templated pointer that is the new
//          "subTreePtr" after the rotation.
//
// =============================================================================
template<class ItemType>
CBinaryNode<ItemType>*  
CBST<ItemType>::LeftRotate(CBinaryNode<ItemType> *subTreePtr)
{
    //use new root node to hold rightChild
    CBinaryNode<ItemType>   *rootPtr;
    rootPtr = subTreePtr->GetRightChildPtr();
    //sets as leftChild of new root node
    subTreePtr->SetRightChildPtr(rootPtr->GetLeftChildPtr());
    //sets leftChild to be the current root of subTree  
    rootPtr->SetLeftChildPtr(subTreePtr);
    
    return rootPtr;

}




// ==== CBST<ItemType>::RightRotate ============================================
//
// This function rotates the nodes to the right.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to start the
//                              rotation.
// Output:
//       An updated CBinaryNode<ItemType> templated pointer that is the new
//          "subTreePtr" after the rotation.
//
// =============================================================================
template<class ItemType>
CBinaryNode<ItemType>*  
CBST<ItemType>::RightRotate(CBinaryNode<ItemType> *subTreePtr)
{
    //use new root node to hold lefttChild
    CBinaryNode<ItemType>   *rootPtr;
    rootPtr = subTreePtr->GetLeftChildPtr();
    //sets as rightChild of new root node
    subTreePtr->SetLeftChildPtr(rootPtr->GetRightChildPtr());
    //sets rightChild to be the current root of subTree  
    rootPtr->SetRightChildPtr(subTreePtr);
    
    return rootPtr;

}




// ==== CBST<ItemType>::LeftRightRotate ========================================
//
// This function rotates the nodes to the left and then right.  In other words,
// it rotates the left child of subTreePtr to the left and then rotates
// subTreePtr to the right.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to start the
//                              rotation.
// Output:
//       An updated CBinaryNode<ItemType> templated pointer that is the new
//          "subTreePtr" after the rotation.
//
// =============================================================================
template<class ItemType>
CBinaryNode<ItemType>* 
CBST<ItemType>::LeftRightRotate(CBinaryNode<ItemType> *subTreePtr)
{
    //left rotation of subTreePtr leftChild
    CBinaryNode<ItemType>   *rotateNode;
    rotateNode = LeftRotate(subTreePtr->GetLeftChildPtr());
    subTreePtr->SetLeftChildPtr(rotateNode);
    
    //rotation of rootNode to right
    CBinaryNode<ItemType>   *updatedRotation = RightRotate(subTreePtr);
    
    return updatedRotation;
    
}





// ==== CBST<ItemType>::RightLeftRotate ========================================
//
// This function rotates the nodes to the right and then left.  In other words,
// it rotates the right child of subTreePtr to the right and then rotates
// subTreePtr to the left.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to start the
//                              rotation.
// Output:
//       An updated CBinaryNode<ItemType> templated pointer that is the new
//          "subTreePtr" after the rotation.
//
// =============================================================================
template<class ItemType>
CBinaryNode<ItemType>* 
CBST<ItemType>::RightLeftRotate(CBinaryNode<ItemType> *subTreePtr)
{
    //right rotation of subTreePtr rightChild
    CBinaryNode<ItemType>   *rotateNode;
    rotateNode = RightRotate(subTreePtr->GetRightChildPtr());
    subTreePtr->SetRightChildPtr(rotateNode);
    
    //rotation of rootNode to left
    CBinaryNode<ItemType>   *updatedRotation = LeftRotate(subTreePtr);
    
    return updatedRotation;
    
}




// ==== CBST<ItemType>::RemoveValue ============================================
//
// This function removes a value from the tree.  It also keeps the tree AVL
// balanced after each removal.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to start the
//                              search of the node to remove.
//      target      [IN]    - A const ItemType value that we want to remove from
//                              the tree.
//      success     [OUT]   - A bool value that is marked true if sucessful,
//                              false otherwise.
//
// Output:
//       An updated CBinaryNode<ItemType> templated pointer that is the new
//          "subTreePtr" after the removal.
//
// =============================================================================
template<class ItemType>
CBinaryNode<ItemType>* 
CBST<ItemType>::RemoveValue(CBinaryNode<ItemType> *subTreePtr,
                             const ItemType &target, bool &success)
{
    //uses recursion to remove node from tree
    
    //base case: tree is empty
    if (subTreePtr == nullptr)
    {
        //updates success ref
        success = false;
        return subTreePtr;
    }
    //case:passed target value is less than current node
    //result: move left
    if (subTreePtr->GetItem() > target)
    {
        CBinaryNodeTree<ItemType>   *removeNode;
        removeNode = subTreePtr->GetLeftChildPtr();
        subTreePtr->SetLeftChildPtr(RemoveValue(removeNode, target, success));
        
    }
    //case: passed target value greater than current node
    //result: move right
    else if (subTreePtr->GetItem() < target)
    {
        CBinaryNodeTree<ItemType>   *removeNode;
        removeNode = subTreePtr->GetRightChildPtr();
        subTreePtr->SetRightChildPtr(RemoveValue(removeNode, target, success));
        
    }
    //node values match, target found
    else
    {
        //case: is a leafNode
        if (subTreePtr->IsLeaf())
        {
            //deletes node and free memory
            delete subTreePtr;
            subTreePtr = nullptr;
            //updates sucess accordingly
            success = true;
            
        }
        //case: target node only has one child; leftChild
        else if (subTreePtr->GetRightChildPtr() == nullptr)
        {
            //creates nodePtr to hold target for delete 
            CBinaryNode<ItemType> *targetNode = subTreePtr;
            //updates root to point to child
            subTreePtr = subTreePtr->GetLeftChildPtr();
            delete targetNode;
            success = true;
        }
        //case: target node only has one child; rightChild
        else if (subTreePtr->GetLeftChildPtr() == nullptr)
        {
            //creates nodePtr to hold target for delete 
            CBinaryNode<ItemType> *targetNode = subTreePtr;
            //updates root to point to child
            subTreePtr = subTreePtr->GetRightChildPtr();
            delete targetNode;
            success = true;
        }
        //case: node has two children
        else
        {
            CBinaryNode<ItemType>* targetNode;
            targetNode = FindMax(subTreePtr->GetLeftChildPtr());
            subTreePtr->SetItem(targetNode->GetItem());
            subTreePtr->SetLeftChildPtr(RemoveValue(
                subTreePtr->GetLeftChildPtr(), targetNode->GetItem(), success));
        }
    }

    //AVL tree balancing 
    
    //case: empty
    if (subTreePtr == nullptr) 
    {
        return subTreePtr;
    }
    
    subTreePtr->SetHeight(max(GetHeight(subTreePtr->GetLeftChildPtr()),
                               GetHeight(subTreePtr->GetRightChildPtr())) + 1);

    //uses GetHeight() function to determine current height and needed rotation
    int     leftHeight  = GetHeight(subTreePtr->GetLeftChildPtr());
    int     rightHeight = GetHeight(subTreePtr->GetRightChildPtr());
    int     currentBal  = leftHeight - rightHeight;
    
    int     leftLeftHeight = 0;
    //      GetHeight(subTreePtr->GetLeftChildPtr()->GetLeftChildPtr());
    int     leftRightHeight = 0; 
    //      GetHeight(subTreePtr->GetLeftChildPtr()->GetRightChildPtr());
    int     rightRightHeight = 0;
    //      GetHeight(subTreePtr->GetRightChildPtr()->GetRightChildPtr());
    int     rightLeftHeight = 0;
    //      GetHeight(subTreePtr->GetRightChildPtr()->GetLeftChildPtr());
    
    //checks if a left child exists, if yes the assigns heights
    if (subTreePtr->GetLeftChildPtr() != nullptr)
    {
        leftLeftHeight = 
        GetHeight(subTreePtr->GetLeftChildPtr()->GetLeftChildPtr());
        
        leftRightHeight = 
        GetHeight(subTreePtr->GetLeftChildPtr()->GetRightChildPtr());
    }

    //checks if a right child exists, if yes then assigns heights
    if (subTreePtr->GetRightChildPtr() != nullptr)
    {
        rightRightHeight = 
        GetHeight(subTreePtr->GetRightChildPtr()->GetRightChildPtr());
        
        rightLeftHeight = 
        GetHeight(subTreePtr->GetRightChildPtr()->GetLeftChildPtr());
    }
    
    //case: left Left Rotation needed
    if ((currentBal > 1) && (leftLeftHeight >= leftRightHeight))
    {
        subTreePtr = RightRotate(subTreePtr);
        
    }

    //case: Right Right Rotation needed
    if ((currentBal < -1) && (rightRightHeight >= rightLeftHeight))
    {
        subTreePtr = LeftRotate(subTreePtr);
                             
    }

    //case: Left Right Rotation needed 
    if ((currentBal > 1) && (leftLeftHeight < leftRightHeight))
    {
        subTreePtr = LeftRightRotate(subTreePtr);
    }

    //case: Right Left Rotation needed
    if ((currentBal < -1) && (rightRightHeight < rightLeftHeight))
    {
        subTreePtr = RightLeftRotate(subTreePtr);
    }

    return subTreePtr;

}




// ==== CBinaryNodeTree<ItemType>::FindNode ====================================
//
// This function finds a target node if it exists.
//
// Input:
//      treePtr     [IN]    - A templated CBinaryNode pointer to start the
//                              search of the node to find
//      target      [IN]    - A const ItemType value that we want to find from
//                              the tree.
//      success     [OUT]   - A bool value that is marked true if sucessful,
//                              false otherwise.
//
// Output:
//       An CBinaryNode<ItemType> templated pointer of the node found.  If not
//          found, a nullptr is returned.
//
// =============================================================================
template<class ItemType>
CBinaryNode<ItemType>* 
CBST<ItemType>::FindNode(CBinaryNode<ItemType> *treePtr, const ItemType &target,
                         bool &success) const
{
    //uses recursion to find node
    
    //base case: tree is empty
    if (treePtr == nullptr)
    {
        //updates &success reference
        success = false;
        return treePtr; //returns nullptr
    }
    //case: target found; when target == current node item
    else if (target == treePtr->GetItem())
    {
        //updates &success reference
        success = true;
        return treePtr;
    }
    //recursive call to continue search
    else
    {
        //search left side if target is less than current node item
        if (target < treePtr->GetItem())
        {
            //use left child for recursive call
            return FindNode(treePtr->GetLeftChildPtr(), target, success);
        }
        // search right if target is greater than current node item
        else 
        {
            //use right child for recursive call
            return FindNode(treePtr->GetRightChildPtr(), target, success);
        }
    }
}
                    


