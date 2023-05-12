// =============================================================================
// File: CBinaryNodeTree.tpp
// =============================================================================
// Implementation file for the class CBinaryNodeTree.tpp
// =============================================================================

//  #reference
//   CBinaryNode<ItemType>   *m_rootPtr;

#include <iostream>



// ==== CBinaryNodeTree<ItemType>::CBinaryNodeTree =============================
//
// This is the default constructor for CBinaryNodeTree.  It sets the root to
// nullptr.
//
// Input:
//       void
//       
// Output:
//       Nothing
//
// =============================================================================
template <class ItemType>
CBinaryNodeTree<ItemType>::CBinaryNodeTree()
    : m_rootPtr(nullptr)
{
    
}   // end of CBinaryNodeTree<ItemType>::CBinaryNodeTree (default)




// ==== CBinaryNodeTree<ItemType>::CBinaryNodeTree =============================
//
// This is the type constructor for CBinaryNodeTree.  It allocates a space for a
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
template <class ItemType>
CBinaryNodeTree<ItemType>::CBinaryNodeTree(const ItemType &rootItem)
{
   m_rootPtr = new CBinaryNode<ItemType>(rootItem);
    
}




// ==== CBinaryNodeTree<ItemType>::CBinaryNodeTree =============================
//
// This is the type constructor for CBinaryNodeTree.  It allocates a space for a
// CBinaryNode and sets it equal to m_rootPtr.  The new node will have it's
// right and left child pointers set to rightTreePtr and leftTreePtr,
// respectively.
//
// Input:
//       rootItem      [IN]    - A const ItemType reference to initialize the
//                                  new node.
//       leftTreePtr   [IN]    - A const CBinaryNode<ItemType> pointer that
//                                  points to the left child.
//       rightTreePtr  [IN]    - A const CBinaryNode<ItemType> pointer that
//                                  points to the right child.
//       
// Output:
//       Nothing
//
// =============================================================================
template <class ItemType>
CBinaryNodeTree<ItemType>::CBinaryNodeTree(const ItemType &rootItem,
                   const CBinaryNodeTree<ItemType> *leftTreePtr,
                   const CBinaryNodeTree<ItemType> *rightTreePtr)
{
    m_rootPtr = new CBinaryNode<ItemType>(rootItem, leftTreePtr, rightTreePtr);
    
}




// ==== CBinaryNodeTree<ItemType>::CBinaryNodeTree =============================
//
// This is the copy constructor for CBinaryNodeTree. It creates a deep copy of
// "tree."
//
// Input:
//       tree   [IN]    - A const templated CBinaryNodeTree that will be copied.
//       
// Output:
//       Nothing
//
// =============================================================================
template <class ItemType>
CBinaryNodeTree<ItemType>::CBinaryNodeTree
                            (const CBinaryNodeTree<ItemType> &tree)
{
    CBinaryNode<ItemType>   *treeCopy = new CBinaryNode<ItemType>();
    treeCopy->SetRootPtr(tree->GetRootPtr());
    treeCopy->SetItem(tree->GetItem());
    treeCopy->SetLeftChildPtr(tree->GetLeftChildPtr());
    treeCopy->SetRightChildPtr(tree->GetRightChildPtr());
    
}




// ==== CBinaryNodeTree<ItemType>::~CBinaryNodeTree ============================
//
// This is the destructor for CBinaryNodeTree.  It will release all the nodes
// from the heap.
//
// Input:
//       void
//       
// Output:
//       Nothing
//
// =============================================================================
template <class ItemType>
CBinaryNodeTree<ItemType>::~CBinaryNodeTree()
{
    DestroyTree(m_rootPtr);     // will traverse and delete each node in tree
    
    // cout << "\nCBinaryNodeTree Destructor Successful...\n";
   
}




// ==== CBinaryNodeTree<ItemType>::IsEmpty =====================================
//
// This function checks if the tree is empty or not.
//
// Input:
//       void
//
// Output:
//       Returns true if the tree is empty, otherwise false.
//
// =============================================================================
template <class ItemType>
bool    CBinaryNodeTree<ItemType>::IsEmpty() const
{
    if(m_rootPtr == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}



// ==== CBinaryNodeTree<ItemType>::GetHeight ===================================
//
// This function returns the height of the tree.  It calls the protected member
// function GetHeightHelper to get the height from the root of the tree.
//
// Input:
//       void
//
// Output:
//       Returns an integer for the height of the tree.
//
// =============================================================================
template <class ItemType>
int     CBinaryNodeTree<ItemType>::GetHeight() const
{
    return GetHeightHelper(m_rootPtr);
    
}




// ==== CBinaryNodeTree<ItemType>::GetNumberOfNodes ============================
//
// This function returns the number of nodes in the tree.  It calls the
// protected member function GetNumberOfNodesHelper to get the number of nodes
// from the root of the tree.
//
// Input:
//       void
//
// Output:
//       Returns an integer for the number of nodes in the tree.
//
// =============================================================================
template <class ItemType>
int     CBinaryNodeTree<ItemType>::GetNumberOfNodes() const
{
    return GetNumberOfNodesHelper(m_rootPtr);
    
}




// ==== CBinaryNodeTree<ItemType>::GetRootData =================================
//
// This function returns the data item in the root of the tree.
//
// Throws a PrecondViolatedExcept if the root of the tree is empty (nullptr).
//
// Input:
//       void
//
// Output:
//       Returns an ItemType, which is the item in the root of the tree.
//
// =============================================================================
template <class ItemType>
ItemType    CBinaryNodeTree<ItemType>::GetRootData() const 
            throw(PrecondViolatedExcept)
{
    if (IsEmpty())
    {
        throw PrecondViolatedExcept("Precondition Violated Exception: ");
    }
    else
    {
        return m_rootPtr->GetItem();
    }
    
}




// ==== CBinaryNodeTree<ItemType>::SetRootData =================================
//
// This function sets the data item in the root of the tree.
//
// Input:
//       newData    [IN]    - A const ItemType reference that has the new data
//                              value.
//       
// Output:
//       void
//
// =============================================================================
template <class ItemType>
void    CBinaryNodeTree<ItemType>::SetRootData(const ItemType &newData)
{
    if (IsEmpty())
    {
        // code for empty tree scenario
    }
    else
    {
        m_rootPtr->SetItem(newData);
    }
    
}





// ==== CBinaryNodeTree<ItemType>::Clear =======================================
//
// This function removes all nodes from the heap and sets the root pointer to
// nullptr.  To make things easier, this function can call the member function
// DestroyTree.
//
// Input:
//       void
//       
// Output:
//       void
//
// =============================================================================
template <class ItemType>
void CBinaryNodeTree<ItemType>::Clear()
{
    DestroyTree(m_rootPtr);
    m_rootPtr = nullptr;
    
}




// ==== CBinaryNodeTree<ItemType>::Contains ====================================
//
// This function checks if a particular entry exists in the tree.
//
// Input:
//       anEntry    [IN]    - A const ItemType reference to check of its
//                              existence.
//
// Output:
//       Returns true if the entry is already in the tree, false otherwise.
//
// =============================================================================
template <class ItemType>
bool    CBinaryNodeTree<ItemType>::Contains(const ItemType &anEntry) const
{
    bool containsItem = false;  //will get passed by reference 
    
    // check if node exists, otherwise will receive a nullptr
    return FindNode(m_rootPtr, anEntry, containsItem) != nullptr;
    
    
}




// ==== CBinaryNodeTree<ItemType>::PreorderTraverse ============================
//
// This function traverses in pre-order by calling the protected member function
// Preorder.
//
// Input:
//       void Visit(ItemType &item) [IN]    - The function used to display (or
//                                              process) a node.
//
// Output:
//       void
//
// =============================================================================
template <class ItemType>
void    
CBinaryNodeTree<ItemType>::PreorderTraverse (void Visit(const ItemType &item)) 
    const
{
    Preorder(Visit, m_rootPtr);
    
}




// ==== CBinaryNodeTree<ItemType>::InorderTraverse =============================
//
// This function traverses in in-order by calling the protected member function
// Inorder.
//
// Input:
//       void Visit(ItemType &item) [IN]    - The function used to display (or
//                                              process) a node.
// Output:
//       void
//
// =============================================================================
template <class ItemType>
void    
CBinaryNodeTree<ItemType>::InorderTraverse (void Visit(const ItemType &item)) 
    const
{
    Inorder(Visit, m_rootPtr);
    
}




// ==== CBinaryNodeTree<ItemType>::PostorderTraverse ===========================
//
// This function traverses in post-order by calling the protected member
// function Postorder.
//
// Input:
//       void Visit(ItemType &item) [IN]    - The function used to display (or
//                                              process) a node.
// Output:
//       void
//
// =============================================================================
template <class ItemType>
void    
CBinaryNodeTree<ItemType>::PostorderTraverse (void Visit(const ItemType &item)) 
    const
{
    Postorder(Visit, m_rootPtr);
    
}




// ==== CBinaryNodeTree<ItemType>::LevelorderTraverse ==========================
//
// This function traverses in level-order by calling the protected member
// function Levelorder for each level to process.
//
// Input:
//       void Visit(ItemType &item) [IN]    - The function used to display (or
//                                              process) a node.
// Output:
//       void
//
// =============================================================================
template <class ItemType>
void    
CBinaryNodeTree<ItemType>::LevelorderTraverse (void Visit(const ItemType &item)) 
    const
{
    // checks for empty tree
    if (IsEmpty())
    {
        return;
    }
    
        //   ("index")      (break condition)     (lvl increment)
    for (int treeLevel = 0; treeLevel <= GetHeight(); treeLevel++)
    {
        Levelorder(Visit, m_rootPtr, treeLevel);
        
    }
    
}





// ==== CBinaryNodeTree<ItemType>::operator= ==================================
//
// This function assigns the right-hand side CBinaryNodeTree to the left-hand
// side CBinaryNodeTree.  Make sure to protect against assignment to self!
//
// Input:
//       rhs    [IN]    - A const templated CBinaryNodeTree to copy from.
//
// Output:
//       A templated CBinaryNodeTree reference object (the left-hand side of the
//          tree.
//
// =============================================================================
template <class ItemType>
CBinaryNodeTree<ItemType>& 
CBinaryNodeTree<ItemType>::operator=(const CBinaryNodeTree<ItemType> &rhs)
{
    if (this == &rhs)
    {
        return  *this;
    }
    else
    {
        DestroyTree(m_rootPtr);
        m_rootPtr = CopyTree(rhs.m_rootPtr());
    }
    
    return *this;
    
}




// ==== CBinaryNodeTree<ItemType>::GetRootPtr ==================================
//
// This function returns m_rootPtr
//
// Input:
//       Nothing
//
// Output:
//       A CBinaryNode<ItemType> templated pointer that is the address of the
//          root pointer.
//
// =============================================================================
template <class ItemType>
CBinaryNode<ItemType>*  CBinaryNodeTree<ItemType>::GetRootPtr() const
{
    return m_rootPtr;
    
}




// ==== CBinaryNodeTree<ItemType>::SetRootPtr ==================================
//
// This function sets m_rootPtr
//
// Input:
//       rootPtr    [IN]    - A CBinaryNode<ItemType> pointer.
// Output:
//       Nothing
//
// =============================================================================
template <class ItemType>
void    CBinaryNodeTree<ItemType>::SetRootPtr(CBinaryNode<ItemType>* rootPtr)
{
    m_rootPtr = rootPtr;
    
}




// ==== CBinaryNodeTree<ItemType>::GetParentNode ===============================
//
// This function searches for the parent node of any node in the tree.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to start the
//                              search of the parent node.
//      nodePtr     [IN]    - A templated CBinaryNode pointer to find the parent
//                              of.
//
// Output:
//       A CBinaryNode<ItemType> templated pointer that is the address of the
//          parent node pointer.
//
// =============================================================================
template <class ItemType>
CBinaryNode<ItemType>*  
CBinaryNodeTree<ItemType>::GetParentNode(CBinaryNode<ItemType> *subTreePtr,
                            CBinaryNode<ItemType> *nodePtr) const
{
    // uses recursive call to find correct parentNode.
    
    //base case: end of tree reached
    if (subTreePtr == nullptr)
    {
        return subTreePtr;
    }
    //base case: nodePtr found on left
    if (subTreePtr->GetLeftChildPtr() == nodePtr)
    {
        return subTreePtr;
    }
    //base case: nodePtr found on right
    if (subTreePtr->GetRightChildPtr() == nodePtr)
    {
        return subTreePtr;
    }
    
    CBinaryNode<ItemType>   *parentNode;
    
    // Recursive call to search in left subtree
    parentNode = GetParentNode(subTreePtr->GetLeftChildPtr(), nodePtr);
    
    // Recursive search of right side if target not found in left subtree
    if(parentNode == nullptr)
    {
        parentNode = GetParentNode(subTreePtr->GetParentNode(), nodePtr);
    }
    
    return parentNode;
    
}




// ==== CBinaryNodeTree<ItemType>::GetHeightHelper =============================
//
// This function finds the height starting at subTreePtr (this could be root or
// any other node within the tree).
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to find the height
//                              from.
//
// Output:
//       An int that is the height from subTreePtr.
//
// =============================================================================
template <class ItemType>
int 
CBinaryNodeTree<ItemType>::GetHeightHelper(CBinaryNode<ItemType> *subTreePtr) 
    const
{
    // uses recursive call to determine height
    
    //base case: end of subtree reached, height = 0
    if (subTreePtr == nullptr)
    {
        return 0;
    }
    
    int lHeight = 0;   //keeps left side height
    int rHeight = 0;   //keeps right side height
    
    //recursive call 
    lHeight = GetHeightHelper(subTreePtr->GetLeftChildPtr());
    rHeight = GetHeightHelper(subTreePtr->GetRightChildPtr());
    
    //compare to get max height
    if (lHeight < rHeight)
    {
        return rHeight + 1;
    }
    else 
    {
        return lHeight + 1;
    }
}



// ==== CBinaryNodeTree<ItemType>::GetNumberOfNodesHelper ======================
//
// This function finds the number of nodes starting at subTreePtr (this could be
// root or any other node within the tree).
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to find the number
//                              of nodes from.
//
// Output:
//       An int that represents the number of nodes from subTreePtr.
//
// =============================================================================
template <class ItemType>
int CBinaryNodeTree<ItemType>::GetNumberOfNodesHelper
                               (CBinaryNode<ItemType> *subTreePtr) const
{
    // uses recursive call to determine amount of nodes in tree
    
    //base case: emtpy tree, no amount value to return
    if (subTreePtr == nullptr)
    {
        return 0;
    }
    
    int     lNodesAmnt  = 0;    //holds amount of left side nodes
    int     rNodesAmnt  = 0;    //holds amount of right side nodes
    
    //recursive call
    lNodesAmnt = GetNumberOfNodesHelper(subTreePtr->GetLeftChildPtr());
    rNodesAmnt = GetNumberOfNodesHelper(subTreePtr->GetRightChildPtr());
    
    return lNodesAmnt + rNodesAmnt + 1;

}
  



// ==== CBinaryNodeTree<ItemType>::FindMinNode =================================
//
// This function finds the minimum ItemType Node in the tree starting from
// subTreePtr. If there is no minimum ItemType Node found, the function returns
// nullptr.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to find the
//                              minimum node from.
//
// Output:
//       A templated CBinaryNode<ItemType> pointer that points to the minimum
//          node.
//
// =============================================================================
template <class ItemType>
CBinaryNode<ItemType>* 
CBinaryNodeTree<ItemType>::FindMinNode(CBinaryNode<ItemType> *subTreePtr)
{
    // uses recursive call to find node with min ItemType value
    
    //base case: tree is empty, no value to return
    if (subTreePtr == nullptr)
    {
        return subTreePtr;   // will return null ptr
    }
    //base case: current node is left-most node/ min value
    if (subTreePtr->GetLeftChildPtr() == nullptr)
    {
        return subTreePtr;  // returns nullptr
    }
    
    //recursive call, will return min value
    return FindMinNode(subTreePtr->GetLeftChildPtr());
    
}




// ==== CBinaryNodeTree<ItemType>::FindMaxNode =================================
//
// This function finds the maximum ItemType Node in the tree starting from
// subTreePtr. If there is no maximum ItemType Node found, the function returns
// nullptr.
//
// Input:
//      subTreePtr  [IN]    - A templated CBinaryNode pointer to find the
//                              maximum node from.
//
// Output:
//       A templated CBinaryNode<ItemType> pointer that points to the maximum
//          node.
//
// =============================================================================
template <class ItemType>
CBinaryNode<ItemType>* 
CBinaryNodeTree<ItemType>::FindMaxNode(CBinaryNode<ItemType> *subTreePtr)
{
    // uses recursive call to find node with min ItemType value
    
    //base case: tree is empty, no value to return
    if (subTreePtr == nullptr)
    {
        return subTreePtr;   // will return null ptr
    }
    //base case: current node is right-most node/ max value
    if (subTreePtr->GetRightChildPtr() == nullptr)
    {
        return subTreePtr;  // returns nullptr
    }
    
    //recursive call, will return max value
    return FindMaxNode(subTreePtr->GetRightChildPtr());
    
}





// ==== CBinaryNodeTree<ItemType>::CopyTree ====================================
//
// This function copies a tree using a deep copy.
//
// Input:
//      oldTreeRootPtr  [IN]    - A templated CBinaryNode pointer to copy from.
//
// Output:
//       A templated CBinaryNode<ItemType> pointer that points to the new root.
//
// =============================================================================
template <class ItemType>
CBinaryNode<ItemType>* 
CBinaryNodeTree<ItemType>::CopyTree(const CBinaryNode<ItemType> *oldTreeRootPtr) 
    const
{
    //base case: checks for empty tree, nohting left to copy
    if (oldTreeRootPtr == nullptr)
    {
        return nullptr;
    }
    
    //will be used to store rootPtr for tree copy
    CBinaryNode<ItemType>   *copyTreeRootPtr = new CBinaryNode<ItemType>(); 
   
    //creates copy of item for new node from current node
    ItemType    itemCopy = oldTreeRootPtr->GetItem();   
    //copy item of current node
    copyTreeRootPtr->SetItem(itemCopy);
    
    //get left child of current node
    CBinaryNode<ItemType> *leftChild   =   oldTreeRootPtr->GetLeftChildPtr(); 
    //recursive call to copy left side of tree
    copyTreeRootPtr->SetLeftChildPtr(CopyTree(leftChild));
    
    //get right child of current node
    CBinaryNode<ItemType> *rightChild  =   oldTreeRootPtr->GetRightChildPtr();
    //recursive call to copy right side of tree
    copyTreeRootPtr->SetRightChildPtr(CopyTree(rightChild));

    return copyTreeRootPtr;
    
}





// ==== CBinaryNodeTree<ItemType>::DestroyTree =================================
//
// This function destroys a tree.  In other words, it releases the memory from
// the heap.
//
// Input:
//       CBinaryNode<ItemType> *subTreePtr [IN/OUT] - The tree to destroy.
//       
// Output:
//       void
//
// =============================================================================
template <class ItemType>
void CBinaryNodeTree<ItemType>::DestroyTree(CBinaryNode<ItemType> *subTreePtr)
{
    // uses recrusive call to detroy tree through subTrees
    
    //bae case: subTree is empty
    if (subTreePtr == nullptr)
    {
        return;
    }
    
    //recursive call to destory subTreePtr children 
    CBinaryNode<ItemType> *leftChild = subTreePtr->GetLeftChildPtr();
    DestroyTree(leftChild);
    CBinaryNode<ItemType> *rightChild = subTreePtr->GetRightChildPtr();
    DestroyTree(subTreePtr->GetRightChildPtr());
    
    delete subTreePtr;      //free memory of current node
    
}




// ==== CBinaryNodeTree<ItemType>::Preorder ====================================
//
// This function traverses the tree in pre-order.
//
// Input:
//      void Visit(ItemType &item) [IN]    - The function used to display (or
//                                              process) a node.
//      treePtr                    [IN]    - The tree to process.
//
// Output:
//       void
//
// =============================================================================
template <class ItemType>
void CBinaryNodeTree<ItemType>::Preorder(void Visit(const ItemType &item),
        CBinaryNode<ItemType> *treePtr) const
{
    //base case: subTree empty
    if (treePtr == nullptr)
    {
        return;
    }
    
    //PreOrder: item(parent) -> left -> right
    
    //visit current node 
    Visit(treePtr->GetItem());
    //call Preorder to traverse left subTree
    CBinaryNode<ItemType> *leftChild = treePtr->GetLeftChildPtr();
    Preorder(Visit, leftChild);
    //call Preorder to traverse right subTree
    CBinaryNode<ItemType> *rightChild = treePtr->GetRightChildPtr();
    Preorder(Visit, rightChild);
    
}




// ==== CBinaryNodeTree<ItemType>::Inorder ====================================
//
// This function traverses the tree in in-order.
//
// Input:
//      void Visit(ItemType &item) [IN]    - The function used to display (or
//                                              process) a node.
//      treePtr                    [IN]    - The tree to process.
//
// Output:
//       void
//
// =============================================================================
template <class ItemType>
void 
CBinaryNodeTree<ItemType>::Inorder(void Visit(const ItemType &item),
                            CBinaryNode<ItemType> *treePtr) const
{
    //base case: subTree empty
    if (treePtr == nullptr)
    {
        return;
    }
    
    //InOrder: left -> item(parent) -> right
    
    //call Inorder to traverse left subTree
    CBinaryNode<ItemType> *leftChild = treePtr->GetLeftChildPtr();
    Inorder(Visit, leftChild);
    
    //visit current node 
    Visit(treePtr->GetItem());
 
    //call Inorder to traverse right subTree
    CBinaryNode<ItemType> *rightChild = treePtr->GetRightChildPtr();
    Inorder(Visit, rightChild);
    
}




// ==== Postorder ===================================
//
// This function traverses the tree in post-order.
//
// Input:
//      void Visit(ItemType &item) [IN]    - The function used to display (or
//                                              process) a node.
//      treePtr                    [IN]    - The tree to process.
//
// Output:
//       void
//
// =============================================================================
template <class ItemType>
void CBinaryNodeTree<ItemType>::Postorder(void Visit(const ItemType &item),
                                    CBinaryNode<ItemType> *treePtr) const
{
    //base case: subTree empty
    if (treePtr == nullptr)
    {
        return;
    }
    
    //PostOrder: left -> right -> item(parent)
    
    //call Postorder to traverse left subTree
    CBinaryNode<ItemType> *leftChild = treePtr->GetLeftChildPtr();
    Postorder(Visit, leftChild);
    
    //call Postorder to traverse right subTree
    CBinaryNode<ItemType> *rightChild = treePtr->GetRightChildPtr();
    Postorder(Visit, rightChild);
    
    //visit current node 
    Visit(treePtr->GetItem());
 
}





// ==== CBinaryNodeTree<ItemType>::Levelorder ==================================
//
// This function traverses the tree in level-order.
//
// Input:
//      void Visit(ItemType &item) [IN]    - The function used to display (or
//                                              process) a node.
//      treePtr                    [IN]    - The tree to process.
//		level                      [IN]    - The height of the tree (total
//                                              levels to process).
//
// Output:
//       void
//
// =============================================================================
template <class ItemType>
void CBinaryNodeTree<ItemType>::Levelorder(void Visit(const ItemType &item),
                                CBinaryNode<ItemType> *treePtr, int level) const
{
    //base case: 
    if (treePtr == nullptr)
    {
        return;
    }
    
    //case 1: level == 1  
    if (level == 1)
    {
        ItemType    currentItem = treePtr->GetItem();
        Visit(currentItem);
    }
    
    // recursive call to visit left and right children of current node
    else
    {
        CBinaryNode<ItemType> *leftChild = treePtr->GetLeftChildPtr();
        Levelorder(Visit, leftChild, level - 1);
        
        CBinaryNode<ItemType> *rightChild = treePtr->GetRightChildPtr();
        Levelorder(Visit, rightChild, level - 1);
    }
    
}


