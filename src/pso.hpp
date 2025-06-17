#ifndef PSO_HPP
#define PSO_HPP

#include "particle.hpp"

#include <bits/stdc++.h>

using namespace std;

class Pso{
    private:
        int npop; // Tamano da população
        int ngen; // Número máximo de iterações
        int ndimensions; // Número de dimensões

        float c1; // Taxa de aprendizado cognitiva
        float c2; // Taxa de aprendizado social
        float w; // Ponderação de inércia (fator de diversificação)

        Particle *G_best;

        const float MAX_X = 2.0;
        const float MIN_X = -MAX_X;

        const float MAX_VELOCITY = MAX_X;
        const float MIN_VELOCITY = MIN_X;

        // Função objetivo
        float ackley(const vector<float> &x, const int n);
    public: 
        // Vetor para armazenar as particulas do enxame
        vector<Particle*> particles;

        void createInitialPopulation(void);
        void updateFitness(const int particle_idx);
        void updateParticles(void);

        int getNgen(void) const;
        int getNpop(void) const;
        int getNdimensions(void) const;
        float getC1(void) const;
        float getC2(void) const;
        float getW(void) const;
        float getGbestFitness(void) const;
        float getAverageFitness(void) const;

        void printBestPos(void) const;

        Pso(const int _npop, const int _ngen, const int _ndimensions, 
            const float _c1, const float _c2, const float _w);
        ~Pso();
};

#endif