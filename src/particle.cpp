#include "particle.hpp"

const vector<long double>& Particle::getVelocity(void) const{
    return velocity;
}

void Particle::setVelocity(const vector<long double>& new_velocity){
    velocity = new_velocity;
}

const vector<long double>& Particle::getPos(void) const {
    return pos;
}

void Particle::setPos(const vector<long double> &new_pos){
    pos = new_pos;
}

const vector<long double>& Particle::getBestPos(void) const{
    return best_pos;
}

void Particle::setBestPos(const vector<long double> &new_best_pos){
    best_pos = new_best_pos;
}

const long double Particle::getFitness(void) const{
    return fitness;
}

const long double Particle::getBestFitness(void) const{
    return best_fitness;
}

void Particle::updateFitness(const long double new_fitness){
    fitness = new_fitness;

    if(new_fitness < best_fitness){
        best_fitness = new_fitness;
        best_pos = pos;
    }
}

Particle::Particle(const int _ndimensions) : 
    pos(_ndimensions), best_pos(_ndimensions), velocity(_ndimensions), 
    fitness(FLT_MAX), best_fitness(FLT_MAX) {} 

Particle::Particle(void) : fitness(FLT_MAX), best_fitness(FLT_MAX) {}

Particle::~Particle() {}