// ============================================================================
// File: CPersonInfo.h
// ============================================================================
// Header file for the class CPersonInfo
// ============================================================================
 
#ifndef CPERSONINFO_HEADER
#define CPERSONINFO_HEADER

#include <iostream>

class CPersonInfo
{   
public:
   // =========================================================================
   //      Constructors and Destructor
   // =========================================================================

   /** Initializes the strings to an empty string and all ints to 0. */
   CPersonInfo();

   /** Initializes the strings with their first and last name and sets all ints
        to 0 as default arguments.*/
   CPersonInfo(const std::string &fname, const std::string &lname,
               int age = 0, double checking = 0, double savings = 0);

   /** Compiler provided copy constructor and destructor will suffice.  */

   // =========================================================================
   //      Member Functions
   // =========================================================================

   /** Sets the first name of the class private data member
    @param fname:  A string (passed by reference) to update m_fname.
    @return  Nothing. */
   void         SetFirstName(const std::string &fname);

   /** Sets the last name of the class private data member
    @param lname:  A string (passed by reference) to update m_lname.
    @return  Nothing. */
   void         SetLastName(const std::string &lname);

   /** Sets the age of the class private data member
    @param age:  An int to update m_age.
    @return  Nothing. */
   void         SetAge(int age);

   /** Sets the checking of the class private data member
    @param checking:  A double to update m_checking.
    @return  Nothing. */
   void         SetChecking(double checking);

   /** Sets the savings of the class private data member
    @param savings:  A double to update m_savings.
    @return  Nothing. */
   void         SetSavings(double savings);

   /** Returns the first name of the class private data member
    @param Nothing.
    @return  A string. */
   std::string  GetFirstName() const;

   /** Returns the last name of the class private data member
    @param Nothing.
    @return  A string. */
   std::string  GetLastName() const;

   /** Returns the age of the class private data member
    @param Nothing.
    @return  An int. */
   int          GetAge() const;

   /** Returns the checking amount of the class private data member
    @param Nothing.
    @return  A double. */
   double       GetChecking() const;

   /** Returns the savings amount of the class private data member
    @param Nothing.
    @return  A double. */
   double       GetSavings() const;

   // =========================================================================
   //      Overloaded operators
   // =========================================================================

   /** Checks if two CPersonInfo classes are exactly the same.
    @param rhs: A const reference to a CPersonInfo object.
    @return  True if they are the same, false otherwise. */
   bool         operator==(const CPersonInfo &rhs);

   /** Checks which CPersonInfo class is greater. For our case, we will
       distinguish what is greater by the m_age private data member. May switch
       in the future, but this is a good start.
    @param rhs: A const reference to a CPersonInfo object.
    @return  True if it is greater, false otherwise. */
   bool         operator>(const CPersonInfo &rhs);

   /** Checks which CPersonInfo class is lesser. For our case, we will
       distinguish what is lesser by the m_age private data member. May switch
       in the future, but this is a good start.
    @param rhs: A const reference to a CPersonInfo object.
    @return  True if it is lesser, false otherwise. */
   bool         operator<(const CPersonInfo &rhs);
   

   
private:
   // =========================================================================
   //      Data Members
   // =========================================================================

   std::string  m_fname;
   std::string  m_lname;
   int          m_age;
   double       m_checking;
   double       m_savings;

}; // end CPersonInfo

// =========================================================================
//      Overloaded stream operators prototypes
// =========================================================================

   /** Overloads the extraction operator to extract a CPersonInfo object.
    @param ins: An input reference stream.
    @param person: A reference to a CPersonInfo object.
    @return  An input reference stream. */
   std::istream& operator>>(std::istream &ins, CPersonInfo &person);

   /** Overloads the insertion operator to display a CPersonInfo object.
    @param outs: An output reference stream.
    @param person: A reference to a CPersonInfo object.
    @return  An output reference stream. */
   std::ostream& operator<<(std::ostream &outs, const CPersonInfo &person);

#endif 
