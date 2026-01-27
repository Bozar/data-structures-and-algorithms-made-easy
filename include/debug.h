// PREPROCESSOR {{{1

#ifndef DEBUG_H
#define DEBUG_H


//#define NDEBUG
#include <assert.h>
// SWITCH_DEBUG_MODE {{{1

#if ! defined(NDEBUG)

#define DEBUG_LLT 0
#define DEBUG_STK 1

#endif
// PRINT_MESSAGE {{{1

#define PRINT_ERR(...) do { \
	fprintf(stderr, "%s:%d: %s: ", __FILE__, __LINE__, __func__); \
	fprintf(stderr, __VA_ARGS__); \
	fprintf(stderr, "\n"); \
} while(0)


#define PRINT_LOG(...) do { \
	fprintf(stdout, "%s:%d: %s: ", __FILE__, __LINE__, __func__); \
	fprintf(stdout, __VA_ARGS__); \
	fprintf(stdout, "\n"); \
} while(0)
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

#endif // DEBUG_H
