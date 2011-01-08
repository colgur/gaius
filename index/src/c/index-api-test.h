#ifndef INDEX_API_TEST_H
#define INDEX_API_TEST_H

#include "clang-c/Index.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*PostVisitTU)(CXTranslationUnit);

#define LOAD_SOURCE_TEST            "-test-load-source"
#define INCLUSION_STACK_SOURCE_TEST "-test-inclusion-stack-source"

CXCursorVisitor GetVisitor(const char *s);
void PrintInclusionStack(CXTranslationUnit TU);
int perform_test_load_source(int argc, const char **argv,
                             const char *filter, CXCursorVisitor Visitor,
                             PostVisitTU PV);

#ifdef __cplusplus
}
#endif
#endif
