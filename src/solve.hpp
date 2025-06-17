#ifndef SOLVE_HPP
#define SOLVE_HPP

#include "pso.hpp"
#include "build_csv.hpp"

#include <bits/stdc++.h>

using namespace std;

class Solve{
    private:
        void solveFactorialTest(const int npop, const int ngen, 
                                const int ndimensions, const float c1,
                                const float c2, const float w,
                                ofstream &output_file);
        void solveGenerationsTest(const int npop, const int ngen, 
                                  const int ndimensions, const float c1,
                                  const float c2, const float w,
                                  ofstream &output_file);
    public:
        void solve();
        void factorialTest(ofstream &output_file);
        void generationsTest(ofstream &output_file);
};

#endif
