//===-- HelloWorld.cpp - Example Transformations --------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "llvm/Transforms/Utils/HelloWorld.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instruction.h"

using namespace llvm;

PreservedAnalyses HelloWorldPass::run(Function &F,
                                      FunctionAnalysisManager &AM) {
  size_t InstCount = 0;
  errs() << F.getName() << "\n";
  size_t BBIndex = 0;
  for (const BasicBlock &BB : F) {
    errs() << "bb#" << BBIndex;
    if (BB.hasName())
      errs() << " (" << BB.getName() << ")";
    errs() << ":\n";

    size_t InstIndexInBB = 0;
    for (const Instruction &I : BB) {
      ++InstCount;
      errs() << "  [" << InstIndexInBB << "] " << I << "\n";
      ++InstIndexInBB;
    }
    ++BBIndex;
  }
  errs() << "instruction-count: " << InstCount << "\n";
  return PreservedAnalyses::all();
}
