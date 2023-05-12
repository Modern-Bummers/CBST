// ============================================================================
// File: PrecondViolatedExcept.cpp
// ============================================================================
// Implementation file for the class PrecondViolatedExcept
// ============================================================================

#include <iostream>
#include "PrecondViolatedExcept.h"



// ==== PrecondViolatedExcept::PrecondViolatedExcept ===========================
//
// This is the PrecondViolatedExcept constructor.  It sets the error message to
// the member variable m_errorMsg.
//
// Input:
//       errorMsg   [IN]    - A const string that contains the error message.
//
// Output:
//       Nothing
//
// =============================================================================
PrecondViolatedExcept::PrecondViolatedExcept(const std::string errorMsg)
    :m_errorMsg(errorMsg)
{
    
}   //end of PrecondViolatedExcept::PrecondViolatedExcept




// ==== PrecondViolatedExcept::GetMsg ==========================================
//
// This function returns the message stored.
//
// Input:
//       void
//
// Output:
//       Returns a string.
//
// =============================================================================
std::string     PrecondViolatedExcept::GetMsg() const
{
    return m_errorMsg;
    
}   //end of PrecondViolatedExcept::GetMsg




// ==== PrecondViolatedExcept::SetMsg ==========================================
//
// This function sets the error message to the member variable m_errorMsg.
//
// Input:
//       errorMsg   [IN]    - A const string that contains the error message.
//
// Output:
//       Nothing
//
// =============================================================================
void    PrecondViolatedExcept::SetMsg(const std::string errorMsg)
{
    m_errorMsg = errorMsg;
    
} //end of PrecondViolatedExcept::SetMsg


