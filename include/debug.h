// PREPROCESSOR {{{1

#ifndef DEBUG_H
#define DEBUG_H


//#define NDEBUG
#include <assert.h>
// DEBUG_TAG {{{1

#if ! defined(NDEBUG)

#define DEBUG_LLT 1

#endif
// PRAGMA_GCC {{{1

// https://www.fluentcpp.com/2019/08/30/how-to-disable-a-warning-in-cpp/

#define DO_PRAGMA(X) \
		_Pragma(#X)
#define NO_WARNING_BEGIN \
		DO_PRAGMA(GCC diagnostic push)
#define NO_WARNING_END \
		DO_PRAGMA(GCC diagnostic pop) 
#define NO_WARNING(warn) \
		DO_PRAGMA(GCC diagnostic ignored #warn)
// EOF {{{1

#endif
