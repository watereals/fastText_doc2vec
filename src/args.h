/**
 * Copyright (c) 2016-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#ifndef FASTTEXT_ARGS_H
#define FASTTEXT_ARGS_H

#include <string>

enum class model_name : int {cbow=1, sg, sup, pvdm, pvdbow};
enum class loss_name : int {hs=1, ns, softmax};

class Args {
  public:
    Args();
    std::string input;
    std::string modelInput;
    std::string test;
    std::string output;
    double lr;
    int lrUpdateRate;
    int dim;
    int ws;
    int epoch;
    int minCount;
    int neg;
    int wordNgrams;
    loss_name loss;
    model_name model;
    int bucket;
    int minn;
    int maxn;
    int thread;
    double t;
    std::string label;

    void parseArgs(int, char**);
    void printHelp();
    void save(std::ofstream&);
    void load(std::ifstream&);
};

#endif