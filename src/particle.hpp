#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <bits/stdc++.h>

using namespace std;

class Particle{
    private:
        vector<double> pos;
        vector<double> best_pos;
        vector<double> velocity;
        double fitness;
        double best_fitness;
    public:
        const vector<double>& getVelocity(void) const;
        void setVelocity(const vector<double> &new_velocity);

        const vector<double>& getPos(void) const;
        void setPos(const vector<double> &new_pos);

        const vector<double>& getBestPos(void) const;
        void setBestPos(const vector<double> &new_best_pos);

        const double getFitness(void) const;
        void updateFitness(const double new_fitness);

        const double getBestFitness(void) const;

        Particle(const int ndimensions);
        Particle(void);
        ~Particle();
};

#endif