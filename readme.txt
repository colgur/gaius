Notes on 'index' sub-dir:
- Tinkering with Autotools to create stand-alone LLVM-CLANG app
- Use 'autoreconf --install' with 'index/configure.ac'
- LLVM 2.8 was installed to my $HOME. I used configure LDFLAGS="-L$HOME/lib -Wl,-rpath -Wl,$HOME/lib -lpthread -ldl -lm" LIBS="-lclang -lclangIndex -lclangFrontend -lclangDriver -lclangSerialization -lclangParse -lclangSema -lclangAnalysis -lclangAST -lclangLex -lclangBasic -lLLVMMC -lLLVMBitReader -lLLVMCore -lLLVMSupport -lLLVMSystem" CPPFLAGS="-I$HOME/include -D_DEBUG -D_GNU_SOURCE -D__STDC_LIMIT_MACROS -D__STDC_CONSTANT_MACROS" CFLAGS="-I$HOME/include -D_DEBUG -D_GNU_SOURCE -D__STDC_LIMIT_MACROS -D__STDC_CONSTANT_MACROS -g -fPIC" CXXFLAGS="-I$HOME/include-D_DEBUG -D_GNU_SOURCE -D__STDC_LIMIT_MACROS -D__STDC_CONSTANT_MACROS -g -fno-exceptions -fno-rtti -fPIC -Woverloaded-virtual -Wcast-qual"

Notes on 'clang' sub-dir:
- Uses the LLVM Makefile System
- Relocation doesn't work very well. Working out of a clang sub-directory is easier (see https://github.com/colgur/clang/tree/master/projects/)
- Work around a clang-llvm dependency issue: USEDLIBS in 'tools/fex/Makefile' treats clang libraries as targets. Add the link: $(PROJ_OBJ_ROOT)/Debug+Asserts/lib -> $(LLVM_OBJ_ROOT)/Debug+Asserts/lib
