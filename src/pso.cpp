#include "pso.hpp"
#include "particle.hpp"

mt19937 globalGenerator(random_device{}());

void Pso::createInitialPopulation(void){
    for(int p = 0; p < npop; ++p){
        Particle *particle = new Particle(ndimensions);

        vector<float> pos(ndimensions);
        vector<float> velocity(ndimensions);

        uniform_real_distribution<float> pos_gen(MIN_X, MAX_X);
        uniform_real_distribution<float> vel_gen(MIN_VELOCITY, MAX_VELOCITY);

        for(int dimension = 0; dimension < ndimensions; ++dimension){
            pos[dimension] = pos_gen(globalGenerator);
            velocity[dimension] = vel_gen(globalGenerator);
        }
        particle->setPos(pos);
        particle->setBestPos(pos);
        particle->setVelocity(velocity);
        
        particle->updateFitness(ackley(pos, ndimensions));  

        // Caso a particula tenha um fitness menor que o melhor do enxame,
        // atualiza a melhor partícula encontrada
        if(particle->getFitness() < G_best->getFitness()){
            G_best->setBestPos(particle->getPos());
            G_best->updateFitness(particle->getFitness());
        }

        particles.push_back(particle);
    }
}

void Pso::updateFitness(const int particle_idx){
    float fitness = ackley(particles[particle_idx]->getPos(), ndimensions);
    particles[particle_idx]->updateFitness(fitness);
    if(fitness < G_best->getFitness()){
        cout << "fit: " << fitness << endl;
        cout << "pos: ";
        auto pos = particles[particle_idx]->getPos();
        for(auto x : pos) cout << x << ' ';
        cout << endl; 

        G_best->setPos(particles[particle_idx]->getPos());
        G_best->setBestPos(particles[particle_idx]->getPos());
        G_best->updateFitness(fitness);
    }
}

void Pso::updateParticles(void){
    for(int p = 0; p < npop; ++p){
        const vector<float> &particle_best_pos = particles[p]->getBestPos();
        const vector<float> &particle_pos = particles[p]->getPos();
        const vector<float> &particle_velocity = particles[p]->getVelocity();

        vector<float> new_velocity(ndimensions);
        for(int d = 0; d < ndimensions; ++d) {
            uniform_real_distribution<float> r_gen(0.0f, 1.0f);
            float r1 = r_gen(globalGenerator);
            float r2 = r_gen(globalGenerator);


            float cognitive_component = c1 * r1 * (particle_best_pos[d] - 
                                                   particle_pos[d]);
            float social_component = c2 * r2 * (G_best->getBestPos()[d] - 
                                                particle_pos[d]);

            new_velocity[d] = w * particle_velocity[d] + cognitive_component +
                              social_component;
           
            // Mantém a velocidade dentro dos limites estabelecidos
            new_velocity[d] = min(new_velocity[d], MAX_VELOCITY);
            new_velocity[d] = max(new_velocity[d], MIN_VELOCITY);
        }

        vector<float> new_pos = particle_pos;
        for(int d = 0; d < ndimensions; ++d){
            new_pos[d] += new_velocity[d];
           
            // Mantém a posição dentro dos limites de busca
            new_pos[d] = min(new_pos[d], MAX_X);
            new_pos[d] = max(new_pos[d], MIN_X);
        }
       
        particles[p]->setPos(new_pos);

        updateFitness(p);
    }
}

float Pso::ackley(const vector<float> &x, const int n){
    float sum_1 = 0.0f;
    float sum_2 = 0.0f;

    for(int i = 0; i < n; ++i){
        sum_1 += pow(x[i], 2);
        sum_2 += cos(2.0 * M_PI * x[i]);
    }

    return -20.0 * exp(-0.2 * sqrt(1.0/n * sum_1))
           - exp(1.0/n * sum_2) + 20.0 + exp(1.0f);
}

int Pso::getNgen(void) const{
    return ngen;
}

int Pso::getNdimensions(void) const{
    return ndimensions;
}

int Pso::getNpop(void) const{
    return npop;
}

float Pso::getC1(void) const{
    return c1;
}

float Pso::getC2(void) const{
    return c2;
}

float Pso::getW(void) const{
    return w;
}

float Pso::getGbestFitness(void) const{
    return G_best->getFitness();
}

float Pso::getAverageFitness(void) const{
    float fitness_sum = 0.0f;
    for(auto particle : particles){
        fitness_sum += particle->getFitness();
    }
    return fitness_sum / npop;
}

void Pso::printBestPos(void) const{
    cout << fixed << setprecision(12);

    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "    Algoritmo de Otimizacao por Enxame de Particulas     " << endl;
    cout << "            para otimizar a funcao de Ackley             " << endl;
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "- Melhor resultado encontrado: " << G_best->getFitness() << endl;
    cout << "- Posicao: (";
    stringstream coordinates;
    for(const auto &x : G_best->getPos())
        coordinates << fixed << setprecision(12) << x << ", ";
    string s = coordinates.str();
    s.pop_back();
    s.pop_back();
    cout << s << ")" << endl;
}

Pso::Pso(const int _npop, const int _ngen, const int _ndimensions, 
         const float _c1, const float _c2, const float _w) : 
    npop(_npop), ngen(_ngen), ndimensions(_ndimensions), c1(_c1), c2(_c2), 
    w(_w) {
        G_best = new Particle(ndimensions);
        
        vector<float> pos;
        for(int i = 0; i < ndimensions; ++i) 
            pos.push_back(MAX_X);
        G_best->setPos(pos);
    }

Pso::~Pso(){
    for(int p = 0; p < npop; ++p)
        delete particles[p];
    delete G_best;
}