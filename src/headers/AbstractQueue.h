/*
 *  AbstractQueue.h
 *
 *  Created by aw on 11/27/09.
 *  Copyright 2009 p. All rights reserved.
 */

// Definicja interfejsu kolejki uogolnionej.
// Musza byc dwie procedury:
// put - wlozenie do kolejki
// get - wyjecie z kolejki

#ifndef ABSTRACT_QUEUE_H
#define ABSTRACT_QUEUE_H

#include <iostream>

template <typename typ>
class AbstractQueue{
protected:
	AbstractQueue(const char* txt){ std::cout << "\nCreation of " << txt; }
public:
	virtual	void put(typ&) = 0;
	virtual	typ get() = 0;
};



// Klasa pomocnicza do tworzenia wyjatkow zwiazanych z kolejka
class QueueException{
	int excID;
public:
	QueueException(int i) : excID(i){}
};

#define QUEUE_EMPTY      1
#define QUEUE_FULL       2

#endif
