#ifndef SOLVE_HPP
#define SOLVE_HPP

#include "pso.hpp"
#include "build_csv.hpp"

#include <bits/stdc++.h>

using namespace std;

class Solve{
    private:
        void solveFactorialTest(ofstream &output_file);
        void solveGenerationsTest(ofstream &output_file);
    public:
        void solve();
        void factorialTest(ofstream &output_file);
        void generationsTest(ofstream &output_file);
};

#endif
