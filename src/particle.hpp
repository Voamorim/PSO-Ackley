#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <bits/stdc++.h>

using namespace std;

class Particle{
    private:
        vector<long double> pos;
        vector<long double> best_pos;
        vector<long double> velocity;
        long double fitness;
        long double best_fitness;
    public:
        const vector<long double>& getVelocity(void) const;
        void setVelocity(const vector<long double> &new_velocity);

        const vector<long double>& getPos(void) const;
        void setPos(const vector<long double> &new_pos);

        const vector<long double>& getBestPos(void) const;
        void setBestPos(const vector<long double> &new_best_pos);

        const long double getFitness(void) const;
        void updateFitness(const long double new_fitness);

        const long double getBestFitness(void) const;

        Particle(const int ndimensions);
        Particle(void);
        ~Particle();
};

#endif