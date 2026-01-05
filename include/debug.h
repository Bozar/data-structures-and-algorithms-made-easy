// PREPROCESSOR {{{1

#ifndef DEBUG_H
#define DEBUG_H


//#define NDEBUG
//#include <assert.h>

// DEBUG_TAG {{{1

#if defined(NDEBUG) // UNDEF_TAG {{{2

#undef DEBUG_LLT

#else // DEFINE_TAG {{{2

#define DEBUG_LLT

#endif

// EOF {{{1

#endif
