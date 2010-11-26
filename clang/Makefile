#
# Indicates our relative path to the top of the project's root directory.
#
ifndef GAIUS_LEVEL
GAIUS_LEVEL := .
DIRS := lib tools
EXTRA_DIST := include
PARALLEL_DIRS :=
endif

LEVEL := $(GAIUS_LEVEL)

CLANG_SRC_ROOT = $(LLVM_SRC_ROOT)/tools/clang
CLANG_OBJ_ROOT = $(LLVM_OBJ_ROOT)/tools/clang

#
# Include the Master Makefile that knows how to build all.
#
include $(GAIUS_LEVEL)/Makefile.common

CPP.Flags += -I$(CLANG_SRC_ROOT)/include -I$(CLANG_OBJ_ROOT)/include

# Disable -fstrict-aliasing. Darwin disables it by default (and LLVM doesn't
# work with it enabled with GCC), Clang/llvm-gc don't support it yet, and newer
# GCC's have false positive warnings with it on Linux (which prove a pain to
# fix). For example:
#   http://gcc.gnu.org/PR41874
#   http://gcc.gnu.org/PR41838
#
# We can revisit this when LLVM/Clang support it.
CXX.Flags += -fno-strict-aliasing
