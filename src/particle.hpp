#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <bits/stdc++.h>

using namespace std;

class Particle{
    private:
        vector<float> pos;
        vector<float> best_pos;
        vector<float> velocity;
        float fitness;
        float best_fitness;
    public:
        vector<float> getVelocity(void) const;
        void setVelocity(const vector<float> &new_velocity);

        vector<float> getPos(void) const;
        void setPos(const vector<float> &new_pos);

        vector<float> getBestPos(void) const;
        void setBestPos(const vector<float> &new_best_pos);

        float getFitness(void) const;
        void updateFitness(const float new_fitness);

        float getBestFitness(void) const;

        Particle(const int ndimensions);
        Particle(void);
        ~Particle();
};

#endif