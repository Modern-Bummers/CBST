// ============================================================================
// File: CBinaryNodeTree.h
// ============================================================================
// Header file for the class CBinaryNodeTree
// ============================================================================

#ifndef CBINARYNODETREE_HEADER
#define CBINARYNODETREE_HEADER

#include "CBinaryTreeInterface.h"
#include "CBinaryNode.h"
#include "PrecondViolatedExcept.h"

template <class ItemType>
class   CBinaryNodeTree : public CBinaryTreeInterface<ItemType>
{
public:
   // =========================================================================
   //      Constructors and Destructor
   // =========================================================================
   
   /** Sets m_rootPtr to nullptr*/
   CBinaryNodeTree();

   /** Allocates space for a CBinaryNode and sets it equal to m_rootPtr.  The
        allocated node initializes the item and sets nullptr to its left and
        right childs. */
   CBinaryNodeTree(const ItemType &rootItem);

   /** Allocates space for a CBinaryNode and sets it equal to m_rootPtr. The
        allocated node initializes the item and sets the left and right child
        pointers appropriately. */
   CBinaryNodeTree(const ItemType &rootItem,
                   const CBinaryNodeTree<ItemType> *leftTreePtr,
                   const CBinaryNodeTree<ItemType> *rightTreePtr);

   /** Copy constructor.  It copies the tree that was given as an argument.
        Uses a deep copy. */
   CBinaryNodeTree(const CBinaryNodeTree<ItemType> &tree);

   /** Destructor.  Releases the memory of the tree appropriately. */
   virtual ~CBinaryNodeTree();

   // =========================================================================
   //      Member Functions
   // =========================================================================

   /** Checks if m_rootPtr is nullptr
    @param Nothing.
    @return  True if it is empty, or false if it is not. */
   virtual bool IsEmpty() const;

   /** Counts the height of the tree by calling the function GetHeightHelper.
    @param Nothing.
    @return  An int value representing the height of the tree. */
   virtual int GetHeight() const;

   /** Counts the number of nodes the tree has by calling the function
       GetNumberOfNodesHelper.
    @param Nothing.
    @return  An int value representing the number of nodes the tree has. */
   virtual int GetNumberOfNodes() const;

   /** Gets the item at root location.
    @param Nothing.
    @return  An ItemType that is located at the root.
    @throw  PrecondViolatedExcept if the tree is empty. */
   virtual ItemType GetRootData() const throw(PrecondViolatedExcept);

   /** Assigns an item at root location. If the root is empty, a new
       CBinaryNode is created and item is initialzed.
    @param newData: An ItemType that will be assigned/initialzed at the root
                    location.
    @return  Nothing. */
   virtual void SetRootData(const ItemType &newData);

   /** Adds a new node to the tree.  
    @param newData: An ItemType that will be used to initialzed the new node.
    @return  True if add was successful, or false if it is not. */
   virtual bool Add(const ItemType &newData) = 0;

   /** Removes a node from the tree.
    @param target: An ItemType that will be used to find the node to delete.
    @return  True if remove was successful, or false if it is not. */
   virtual bool Remove(const ItemType &data) = 0;

   /** Clears all nodes of the tree.  The function calls DestroyTree.
    @param Nothing.
    @return  Nothing. */
   virtual void Clear();
   
   /** Checks if an item exists in the tree.  This function calls FindNode.
    @param anEntry: An ItemType that will be used to check if it exists.
    @return  True if found, or false if it is not. */
   virtual bool Contains(const ItemType &anEntry) const;

   /** A function used to transverse the tree in preorder.  Calls the function
       Preorder. This function is the processing step of each node.  It is as
       simple as displaying the ItemType object.
    @param Visit: A function that is a void return type and takes an argument
                  of ItemType. This function is the processing step of each
                  node.  It is as simple as displaying the ItemType object.
    @return  Nothing. */
   virtual void PreorderTraverse(void Visit(const ItemType &item)) const;

   /** A function used to transverse the tree in inorder.  Calls the function
       Inorder. This function is the processing step of each node.  It is as
       simple as displaying the ItemType object.
    @param Visit: A function that is a void return type and takes an argument
                  of ItemType.
    @return  Nothing. */
   virtual void InorderTraverse(void Visit(const ItemType &item)) const;

   /** A function used to transverse the tree in postorder.  Calls the function
       Postorder. This function is the processing step of each node.  It is as
       simple as displaying the ItemType object.
    @param Visit: A function that is a void return type and takes an argument
                  of ItemType.
    @return  Nothing. */
   virtual void PostorderTraverse(void Visit(const ItemType &item)) const;
   
   /** A function used to transverse the tree in level order.  Calls the
   	   function Levelorder. This function is the processing step of each node. 
   	   It is as simple as displaying the ItemType object.
    @param Visit: A function that is a void return type and takes an argument
                  of ItemType.
    @return  Nothing. */
   virtual void LevelorderTraverse(void Visit(const ItemType &item)) const;

   /** Overloaded assignment operator.  Used to assign a CBinaryNodeTree
    @param rhs: A const CBinaryNodeTree reference object.
    @return  CBinaryNodeTree reference object. */
   CBinaryNodeTree<ItemType>& operator=(const CBinaryNodeTree<ItemType> &rhs);

protected:
   // =========================================================================
   //      Protected Member Functions
   // =========================================================================
 
   /** This function returns m_rootPtr
    @param Nothing
    @return  CBinaryNode: Returns the root pointer. */
   CBinaryNode<ItemType>* GetRootPtr() const;
   
	/** This function assigns an address to m_rootPtr
    @param rootPtr: A new address to assign to m_rootPtr
    @return  Nothing. */
   void SetRootPtr(CBinaryNode<ItemType>* rootPtr);

   /** This function finds and returns the parent node of nodePtr
    @param subTreePtr: A pointer of CBinaryNodeTree type for a node (root)
    @param nodePtr: A pointer of CBinaryNodeTree type to find the parent of.
    @return  CBinaryNode: Returns the parent node of nodePtr. */
   CBinaryNode<ItemType>* GetParentNode(CBinaryNode<ItemType> *subTreePtr,
                                        CBinaryNode<ItemType> *nodePtr) const;

   /** This function calculates the height of the tree by providing the root/
       subtree root pointer.
    @param subTreePtr: A pointer of CBinaryNodeTree type for the root of the
                       tree.
    @return  An int value. */
   int GetHeightHelper(CBinaryNode<ItemType> *subTreePtr) const;

    /** This function calculates the number of nodes of the tree by providing
        the root/subtree root pointer.
    @param subTreePtr: A pointer of CBinaryNodeTree type for the root of the
                       tree.
    @return  An int value. */
   int GetNumberOfNodesHelper(CBinaryNode<ItemType> *subTreePtr) const;
    
    /** Finds the minimum ItemType Node in subTreePtr.
    @param subTreePtr: A pointer of CBinaryNodeTree type for the root of the
                       tree.
    @return  CBinaryNode: Returns the minimum ItemType Node.
                          node. */
   CBinaryNode<ItemType>* FindMinNode(CBinaryNode<ItemType> *subTreePtr);
    
    /** Finds the maximum ItemType Node in subTreePtr.
    @param subTreePtr: A pointer of CBinaryNodeTree type for the root of the
                       tree.
    @return  CBinaryNode: Returns the maximum ItemType Node.
                          node. */
   CBinaryNode<ItemType>* FindMaxNode(CBinaryNode<ItemType> *subTreePtr);
   
    /** Removes the target value from the tree
    @param subTreePtr: A pointer of CBinaryNodeTree type for the root of the
                       tree.
    @param target: A const ItemType reference to remove.
    @param success: A bool reference to report success or failture of the
                    removal.
    @return  CBinaryNode: Returns the updated subTreePtr after adding the new
                          node. */
   virtual CBinaryNode<ItemType>* RemoveValue(CBinaryNode<ItemType> *subTreePtr,
                                     const ItemType &target, bool &success) = 0;
   
    /** Recursively searches for target value in the tree by using a
        preorder traversal.
    @param treePtr: A pointer of CBinaryNodeTree type for the root of the
                       tree.
    @param target: A const ItemType reference to find.
    @param success: A bool reference to report success or failture of the
                    search.
    @return  CBinaryNode: Returns target node pointer. */
   virtual CBinaryNode<ItemType>* FindNode(CBinaryNode<ItemType> *treePtr,
                                   			const ItemType &target, 
                                   			bool &success) const = 0;
   
    /** Copies the tree rooted at oldTreeRootPtr and returns a pointer to
        the copy.
    @param oldTreeRootPtr: A pointer of CBinaryNodeTree type for the root of the
                       tree.
    @return  CBinaryNode: Returns the new tree pointer. */
   CBinaryNode<ItemType>* CopyTree(const CBinaryNode<ItemType> *oldTreeRootPtr) 
   																	      const;
   
    /** Recursively deletes all nodes from the tree.
    @param subTreePtr: A pointer of CBinaryNodeTree type for the root of the
                       tree.
    @return  Nothing. */
   void DestroyTree(CBinaryNode<ItemType> *subTreePtr);
   
    /** Recursive traversal helper methods for Preorder
    @param Visit: A function that processes an ItemType object. This function
                  is as simple as displaying the ItemType object.
    @param treePtr: A pointer of CBinaryNodeTree type for the root of the
                       tree.
    @return  Nothing. */
   void Preorder(void Visit(const ItemType &item),
                 CBinaryNode<ItemType> *treePtr) const;

    /** Recursive traversal helper methods for Inorder
    @param Visit: A function that processes an ItemType object. This function
                  is as simple as displaying the ItemType object.
    @param treePtr: A pointer of CBinaryNodeTree type for the root of the
                       tree.
    @return  Nothing. */
   void Inorder(void Visit(const ItemType &item),
                CBinaryNode<ItemType> *treePtr) const;

    /** Recursive traversal helper methods for Postorder
    @param Visit: A function that processes an ItemType object. This function
                  is as simple as displaying the ItemType object.
    @param treePtr: A pointer of CBinaryNodeTree type for the root of the
                       tree.
    @return  Nothing. */
   void Postorder(void Visit(const ItemType &item),
                  CBinaryNode<ItemType> *treePtr) const;
                  
    /** Recursive traversal helper methods for Levelorder
    @param Visit: A function that processes an ItemType object. This function
                  is as simple as displaying the ItemType object.
    @param treePtr: A pointer of CBinaryNodeTree type for the root of the
                       tree.
    @param level: An int representing the height of the tree (total levels).
    @return  Nothing. */
   void Levelorder(void Visit(const ItemType &item),
                  CBinaryNode<ItemType> *treePtr,
                  int level) const;

private:
   // =========================================================================
   //      Data Member
   // =========================================================================

    CBinaryNode<ItemType>   *m_rootPtr;
};

#include "CBinaryNodeTree.tpp"

#endif  // CBINARYNODETREE_HEADER
