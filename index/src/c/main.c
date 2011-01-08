#include "clang-c/Index.h"
#include "index-api-test.h"

#include <string.h>

static void print_usage(void) {
  fprintf(stderr,
    "usage: gaius-index-c %s <symbol filter> {<args>}*\n"
    "       gaius-index-c %s {<args>}*\n",
    LOAD_SOURCE_TEST,
    INCLUSION_STACK_SOURCE_TEST );
  fprintf(stderr,
    " <symbol filter> values:\n%s",
    "   all - load all symbols, including those from PCH\n"
    "   local - load all symbols except those in PCH\n"
    "   category - only load ObjC categories (non-PCH)\n"
    "   interface - only load ObjC interfaces (non-PCH)\n"
    "   protocol - only load ObjC protocols (non-PCH)\n"
    "   function - only load functions (non-PCH)\n"
    "   typedef - only load typdefs (non-PCH)\n"
    "   scan-function - scan function bodies (non-PCH)\n\n");
}

int main(int argc, const char **argv) {
  clang_enableStackTraces();
  if (argc >= 4 && strcmp(argv[1], LOAD_SOURCE_TEST) == 0) {
    CXCursorVisitor I = GetVisitor(argv[1] + strlen(LOAD_SOURCE_TEST));
    if (I) {
      return perform_test_load_source(argc - 3, argv + 3, argv[2], I, NULL);
    }
  }
  /* else if (argc > 3 && strcmp(argv[1], FUNCTION_CALLEES) == 0) { */
  /*   return print_function_callees(argc - 1, argv + 1); */
  /* } */
  else if (argc > 2 && strcmp(argv[1], INCLUSION_STACK_SOURCE_TEST) == 0) {
    return perform_test_load_source(argc - 2, argv + 2, "all", NULL,
				    PrintInclusionStack);
  }
           
  print_usage();
  return 1;
}
