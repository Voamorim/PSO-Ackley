#include "pso.hpp"

float Pso::ackley(vector<float> &x, const int n){
    float sum_1 = 0.0f;
    float sum_2 = 0.0f;

    for(int i = 0; i < n; ++i){
        sum_1 += pow(x[i], 2);
        sum_2 += cos(2.0 * M_PI * x[i]);
    }

    return -20.0 * exp(-0.2 * sqrt(1.0/n * sum_1))
           - exp(1.0/n * sum_2) + 20.0 + M_E;
}