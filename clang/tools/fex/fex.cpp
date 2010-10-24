#include "llvm/Support/CommandLine.h"

static llvm::cl::opt<std::string>
OutputFilename("o", llvm::cl::desc("Specify output filename"), llvm::cl::value_desc("filename"));

static llvm::cl::opt<std::string>
InputFilenames(llvm::cl::Positional, llvm::cl::desc("<input file>"));

int
main (int argc, char ** argv)
{
  llvm::cl::ParseCommandLineOptions(argc, argv, "fex");
  return (0);
}

