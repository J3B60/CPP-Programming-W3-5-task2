#pragma once
// Include guards in modern compilers are a bit smarter. #pragma once does all of the #ifdef, #define, #endif logic for us
// Again, it needs to be at the top of the codefile

// We need to include the file that defines what a Pallet is.
// This is *your* pallet.h file.

// IF YOU HAVE CALLED YOUR PALLET HEADER FILE SOMETHING DIFFERENT THAN WHAT WE TOLD YOU IN WEEK 3,
// YOU NEED TO CHANGE THE INCLUDE BELOW APPROPRIATELY
#include "pallet.h"

// Function prototype for GeneratePallet
// We're delaring a function that returns a Pallet that takes no arguments
// If you called your Pallet class something other than what we told you in week 3, you're going to need to edit some code (yours or ours)
Pallet GeneratePallet();