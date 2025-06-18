#include "particle.hpp"

const vector<double>& Particle::getVelocity(void) const{
    return velocity;
}

void Particle::setVelocity(const vector<double>& new_velocity){
    velocity = new_velocity;
    //copy(new_velocity.begin(), new_velocity.end(), velocity.begin());
}

const vector<double>& Particle::getPos(void) const {
    return pos;
}

void Particle::setPos(const vector<double> &new_pos){
    pos = new_pos;
    //copy(new_pos.begin(), new_pos.end(), pos.begin());
}

const vector<double>& Particle::getBestPos(void) const{
    return best_pos;
}

void Particle::setBestPos(const vector<double> &new_best_pos){
    //copy(new_best_pos.begin(), new_best_pos.end(), best_pos.begin());
    best_pos = new_best_pos;
}

const double Particle::getFitness(void) const{
    return fitness;
}

void Particle::updateFitness(const double new_fitness){
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