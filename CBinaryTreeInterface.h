// ============================================================================
// File: CBinaryTreeInterface.h
// ============================================================================
// Header file for the class CBinaryTreeInterface
// ============================================================================

#ifndef CBINARY_TREE_INTERFACE_HEADER
#define CBINARY_TREE_INTERFACE_HEADER



template<class ItemType>
class CBinaryTreeInterface
{
public:
   /** Tests whether this binary tree is empty.
    @return True if the binary tree is empty, or false if not. */
   virtual bool IsEmpty() const = 0;
   
   /** Gets the height of this binary tree.
    @return The height of the binary tree. */
   virtual int GetHeight() const = 0;
   
   /** Gets the number of nodes in this binary tree.
    @return The number of nodes in the binary tree. */
   virtual int GetNumberOfNodes() const = 0;
   
   /** Gets the data that is in the root of this binary tree.
    @pre  The binary tree is not empty.
    @post  The root’s data has been returned, and the binary tree is unchanged.
    @return  The data in the root of the binary tree. */
   virtual ItemType GetRootData() const = 0;
   
   /** Replaces the data item in the root of this binary tree
       with the given data, if the tree is not empty. However, if
       the tree is empty, inserts a new root node containing the
       given data into the tree.
    @pre  None.
    @post  The data in the root of the binary tree is as given.
    @param newData  The data for the root. */
   virtual void SetRootData(const ItemType& newData) = 0;
   
   /** Adds a new node containing the given data to this binary tree.
    @param newData  The data for the new node.
    @post  The binary tree contains a new node.
    @return  True if the addition is successful, or false not. */
   virtual bool Add(const ItemType& newData) = 0;
   
   /** Removes the node containing the given data item from this binary tree.
    @param data  The data value to remove from the binary tree.
    @return  True if the removal is successful, or false not. */
   virtual bool Remove(const ItemType& data) = 0;
   
   /** Removes all nodes from this binary tree. */
   virtual void Clear() = 0;
   
   /** Tests whether a given entry occurs in this binary tree.
    @post  The binary search tree is unchanged.
    @param anEntry  The entry to find.
    @return  True if the entry occurs in the tree, or false if not. */
   virtual bool Contains(const ItemType& anEntry) const = 0;
   
   /** Traverses this binary tree in preorder (inorder, postorder, levelorder)
   	   and calls the function Visit once for each node.
    @param Visit A client-defined function that performs an operation on
       or with the data in each visited node. */
   virtual void PreorderTraverse(void Visit(const ItemType &item)) const = 0;
   virtual void InorderTraverse(void Visit(const ItemType &item)) const = 0;
   virtual void PostorderTraverse(void Visit(const ItemType &item)) const = 0;
   virtual void LevelorderTraverse(void Visit(const ItemType &item)) const = 0;
   
   /** Destroys object and frees memory allocated by object. */
   virtual ~CBinaryTreeInterface() {  }
   
}; // end CBinaryTreeInterface
#endif
