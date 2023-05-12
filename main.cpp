// ============================================================================
// File: main.cpp
// ============================================================================
// Programmer: Thomas Ortiz
// Date: 04/25/2023
// Class: CSCI 133 ("Data Structures Using C++")
// Time: ID 01358275
// Instructor: Dr. Rodriguez
// Project: Project CBST
//
// Description:
//  This program works with the ADT CBST.  It allows the user to remove
//  and insert items (nodes) in the tree and keep it balanced using AVL.
// ============================================================================

#include    <iostream>
#include    <fstream>
#include    <cstdlib>
using namespace std;

#include    "CBST.h"
#include    "CPersonInfo.h"

// global constants
const int MAX_ITEMS = 30;

// function prototype
void    Visit(const CPersonInfo &item);


// ==== main ==================================================================
//
// ============================================================================

int     main()
{
    CBST<CPersonInfo>    treeList;          // create a tree list
    CPersonInfo          people[MAX_ITEMS]; // allocate an array of CPersonInfo
    ifstream             inFile("PersonBankInfo.txt");
    char                 header[256];
    int                  index;

    if (inFile.fail())
    {
        cerr << "Error opening \"PersonBankInfo.txt\"...\n\n";
        exit(EXIT_FAILURE);
    }

    // Get rid of the header in the file ("First", "Last", ... , "Savings")
    inFile.getline(header, 256);

    // Read all the items in the file and store in a CPersonInfo array
    for (index = 0; index < MAX_ITEMS; ++index)
    {
        inFile >> people[index];  // usage of overloaded stream operator
    }

    // Add 20 items (CPersonInfo) to the treeList and remove them to test it.
    for (index = 0; index < 20; ++index)
    {
        treeList.Add(people[index]);
    }

    // Display the treeList in pre-order
    cout << "\n\nDisplaying treeList in pre-order\n\n";
    treeList.PreorderTraverse(Visit);
    cout << endl;

    // Display the treeList in post-order
    cout << "\n\nDisplaying treeList in post-order\n\n";
    treeList.PostorderTraverse(Visit);
    cout << endl;
    
    // Display the treeList in inorder
    cout << "\n\nDisplaying treeList in in-order\n\n";
    treeList.InorderTraverse(Visit);
    cout << endl;

    // Display the treeList in level-order
    cout << "\n\nDisplaying treeList in level-order\n\n";
    treeList.LevelorderTraverse(Visit);
    cout << endl;
    
    // Remove the first 10 items
    for (index = 0; index < 10; ++index)
    {
        treeList.Remove(people[index]);
    }
    
    // Add 10 more items (CPersonInfo) to the treeList
    for (index = 20; index < MAX_ITEMS; ++index)
    {
        treeList.Add(people[index]);
    }

    // Create more CBST objects to test the type and copy CTORs
    CBST<CPersonInfo>    treeList2(treeList);   // Copy CTOR
    CBST<CPersonInfo>    treeList3(people[0]);  // Type CTOR
    
    // Check for assignment to self.
    treeList2 = treeList2;
    
    // Test the overloaded assignment operator
    treeList3 = treeList2;
    
    // Display the treeList3 in pre-order
    cout << "\n\nDisplaying treeList3 in pre-order\n\n";
    treeList3.PreorderTraverse(Visit);
    cout << endl;

    // Display the treeList3 in post-order
    cout << "\n\nDisplaying treeList3 in post-order\n\n";
    treeList3.PostorderTraverse(Visit);
    cout << endl;
    
    // Display the treeList3 in inorder
    cout << "\n\nDisplaying treeList3 in in-order\n\n";
    treeList3.InorderTraverse(Visit);
    cout << endl;

    // Display the treeList3 in level-order
    cout << "\n\nDisplaying treeList3 in level-order\n\n";
    treeList3.LevelorderTraverse(Visit);
    cout << endl;
    
    // You may add more lines to test various other functions to your choosing.
    // Though this should get you started.

    return 0;

}  // end of "main"



// ==== Visit =================================================================
//
// This function displays a CPersonInfo.
//
// Input:
//      item [in]   -- A pass by reference CPersonInfo object.
//
// Output:
//      void
//
// ============================================================================
void    Visit(const CPersonInfo &item)
{
    cout << item << endl; // usage of overloaded stream operator
}
