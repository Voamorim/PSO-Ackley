#include "solve.hpp"
#include "pso.hpp"
#include "build_csv.hpp"

void Solve::solve(){
    const int npop = 100;
    const int ngen = 100;
    const int ndimensions = 2;

    const float c1 = 3.5;
    const float c2 = 0.5;
    const float w = 0.7;

    Pso *pso = new Pso(npop, ngen, ndimensions, c1, c2, w);

    pso->createInitialPopulation();
    for(int generation = 0; generation < pso->getNgen(); ++generation){
        pso->updateParticles();
    }
    pso->printBestPos();
    delete pso;
}

void Solve::factorialTest(ofstream &output_file){
    const int npop = 200;
    const int ngen = 200; 
    array<int, 3> ndimensions = {2, 3, 4};

    array<float, 4> c1 = {1.0, 1.4, 1.8, 2.0};
    array<float, 4> c2 = {1.0, 1.4, 1.8, 2.0};
    array<float, 3> w = {0.5, 0.7, 0.9};

    BuildCSV *csv_builder = new BuildCSV();
    csv_builder->printFacIdfCSV(output_file);
    delete csv_builder;

    for(int indimensions = 0; indimensions < (int) ndimensions.size(); 
                                                                ++indimensions){
        for(int ic1 = 0; ic1 < (int) c1.size(); ++ic1){
            for(int ic2 = 0; ic2 < (int) c2.size(); ++ic2){
                for(int iw = 0; iw < (int) w.size(); ++iw){
                    solveFactorialTest(npop, ngen, ndimensions[indimensions], 
                                       c1[ic1], c2[ic2], w[iw], output_file);
                }
            }
        }
    }

    output_file.close();
}

void Solve::generationsTest(ofstream &output_file){
    const int npop = 100;
    const int ngen = 100;
    const int ndimensions = 2;

    const float c1 = 0.5;
    const float c2 = 3.5;
    const float w = 0.7;

    solveGenerationsTest(npop, ngen, ndimensions, c1, c2, w, output_file);

    output_file.close();
}

void Solve::solveFactorialTest(const int npop, const int ngen, 
                               const int ndimensions, const float c1, 
                               const float c2, const float w, 
                               ofstream &output_file){
    Pso *pso = new Pso(npop, ngen, ndimensions, c1, c2, w);

    pso->createInitialPopulation();
    for(int generation = 0; generation < pso->getNgen(); ++generation){
        pso->updateParticles();
    }

    BuildCSV *csv_builder = new BuildCSV();
    csv_builder->printFacResultsCSV(pso, output_file);
    delete csv_builder;

    delete pso;
}

void Solve::solveGenerationsTest(const int npop, const int ngen, 
                                 const int ndimensions, const float c1, 
                                 const float c2, const float w, 
                                 ofstream &output_file){
    Pso *pso = new Pso(npop, ngen, ndimensions, c1, c2, w);

    BuildCSV *csv_builder = new BuildCSV();
    csv_builder->printGenIdfCSV(pso, output_file);
    delete csv_builder;


    pso->createInitialPopulation();
    for(int generation = 0; generation < pso->getNgen(); ++generation){
        output_file << generation << ',';
        pso->updateParticles();

        for(int p = 0; p < pso->getNpop() - 1; ++p){
            output_file << pso->particles[p]->getFitness() << ',';
        }
        output_file << pso->particles[pso->getNpop() - 1]->getFitness() << '\n';
    }

    delete pso;
}
