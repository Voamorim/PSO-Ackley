#ifndef PSO_HPP
#define PSO_HPP

#include <bits/stdc++.h>

using namespace std;

class Particle{
    private:
        vector<float> pos;
        vector<float> best_pos;
        float fitness;
        float velocity;
    public:
        float getVelocity(void) const;
        void setVelocity(const float new_velocity);

        vector<float> getPos(void) const;
        void setPos(const vector<float> &new_pos);

        vector<float> getBestPos(void) const;
        void setBestPos(const vector<float> &new_best_pos);

        float getFitness(void) const;
        void setFitness(const float new_fitness);

        Particle(vector<float> initial_pos);
        ~Particle();
};

class Pso{
    private:
        int npop; // Tamano da população
        int ngen; // Número máximo de iterações
        int ndimensions; // Número de dimensões

        float c1; // Taxa de aprendizado cognitiva
        float c2; // Taxa de aprendizado social
        float w; // Ponderação de inércia (fator de diversificação)

        Particle G_best;

        // Vetor para armazenar as particulas do enxame
        vector<Particle*> particles;

        // Função objetivo
        float ackley(vector<float> &x, const int n);

    public: 
        void createInitialPopulation(void);
        void evaluateFitness(void);
        void updateBestPositions(void);
        void updateVelocities(void);
};

#endif