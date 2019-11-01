#include "random.h"
#include <iostream>


RandomNumbers::RandomNumbers(unsigned long int seed_candidate) {
	seed = seed_candidate;
	if(seed_candidate <= 0) {
		std::random_device rd;
		seed = rd();	
	} 
	rng = std::mt19937 (seed_candidate);
}

void RandomNumbers::normal(std::vector<double>& tab, double mean, double sd) {
	std::normal_distribution<double> dis_norm(mean, sd); 
	for (auto i = tab.begin(); i!=tab.end(); ++i) *i = dis_norm(rng);         
}

double RandomNumbers::normal(double mean, double sd) {
	std::normal_distribution<double> dis_norm(mean, sd);
	return dis_norm(rng);	
}

void RandomNumbers::poisson(std::vector<int>& tab, double mean) {
	std::poisson_distribution<int> dis_pois(mean);
	for (auto i = tab.begin(); i!=tab.end(); ++i) *i = dis_pois(rng);          	
}

int RandomNumbers::poisson(double mean) {
	std::poisson_distribution<int> dis_poi(mean); 
	return dis_poi(rng);	
}

void RandomNumbers::uniform_double(std::vector<double>& tab, double lower, double upper){
	std::uniform_real_distribution<> dis_uni(lower, upper);
	for (auto i = tab.begin(); i!=tab.end(); ++i) *i = dis_uni(rng);
}

double RandomNumbers::uniform_double(double lower, double upper) {
	std::uniform_real_distribution<> dis_uni(lower, upper);
	return dis_uni(rng);
}
