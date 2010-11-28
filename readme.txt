Abandoning this project for now: Just can't be bothered to work out issues associated with llvm makefile system. Working out of a clang sub-directory seems easier (see https://github.com/colgur/clang/tree/master/projects/).

This clang sub-dir is still usable, just need to work around clang-llvm dependency:
- USEDLIBS in 'tools/fex/Makefile' treats clang libraries as targets
  	   Work around this issue with a link: $(PROJ_OBJ_ROOT)/Debug+Asserts/lib -> $(LLVM_OBJ_ROOT)/Debug+Asserts/lib
