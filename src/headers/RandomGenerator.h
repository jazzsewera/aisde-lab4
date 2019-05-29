/*
 *  RandomGenerator.h
 *
 *  Created by aw on 12/2/09.
 *  Copyright 2009 p. All rights reserved.
 */

#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H
#include <stdlib.h>

class RandomGenerator {
public:
	RandomGenerator(unsigned long s){
		unsigned int is = s;
		srand(is);
	}

// metoda generuje pseudoprzypadkowa liczbe z zakresu miedzy maximum a minimum
	int getRandom(int minimum, int maximum){
		return (int)(((double)rand()*(double)(maximum-minimum))/(double)RAND_MAX+.5);
	}

// metoda generuje true lub false z 5o% prawdopodobienstwem
	bool getRandom(){ return (bool)getRandom(0, 1); }
};

#endif
