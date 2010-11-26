Essentially external backing of my experiments (like most of my repos actually).

Notes for clang:
- USEDLIBS in 'tools/fex' treats clang libraries as targets
  	   Work around this issue with a link: $(PROJ_OBJ_ROOT)/Debug+Asserts/lib -> $(LLVM_OBJ_ROOT)/Debug+Asserts/lib
