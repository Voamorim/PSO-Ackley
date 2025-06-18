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

        double c1; // Taxa de aprendizado cognitiva
        double c2; // Taxa de aprendizado social
        double w; // Ponderação de inércia (fator de diversificação)

        Particle *G_best;

        const double MAX_X = 2.0;
        const double MIN_X = -MAX_X;

        const double MAX_VELOCITY = MAX_X;
        const double MIN_VELOCITY = MIN_X;

        // Função objetivo
        double ackley(const vector<double> &x, const int n);
    public: 
        // Vetor para armazenar as particulas do enxame
        vector<Particle*> particles;

        int found_min; 
        int current_generation;

        void createInitialPopulation(void);
        void updateFitness(const int particle_idx);
        void updateParticles(void);

        int getNgen(void) const;
        int getNpop(void) const;
        int getNdimensions(void) const;
        double getC1(void) const;
        double getC2(void) const;
        double getW(void) const;
        double getGbestFitness(void) const;
        double getAverageFitness(void) const;

        void printBestPos(void) const;

        Pso(const int _npop, const int _ngen, const int _ndimensions, 
            const double _c1, const double _c2, const double _w);
        ~Pso();
};

#endif