/*
 *  AbstractPriorityQueue.h
 *
 *  Created by aw on 11/27/09.
 *  Copyright 2009 p. All rights reserved.
 */

// Definicja interfejsu kolejki priorytetowej
// w dwoch wersjach: leniwej (Lazy) i nadgorliwej (Officious)

#ifndef ABSTRACT_PRIORITY_QUEUE_H
#define ABSTRACT_PRIORITY_QUEUE_H

#include "AbstractQueue.h"
// Abstrakcyjna kolejka priorytetowa to po prostu abstrakcyjna kolejka uogolniona
#define AbstractPriorityQueue AbstractQueue

template <typename typ>
class AbstractPriorityLazyQueue : public AbstractPriorityQueue<typ> {
protected:
	AbstractPriorityLazyQueue(const char* txt) : AbstractQueue<typ>("Lazy"){ std::cout << txt; }

private:
// wymuszenie stworzenia dla interfejsu leniwych wersji metod
	virtual void putLazy(typ&) = 0;
	virtual typ getLazy() = 0;
	
public:
// metody interfejsu kolejki "na zewnatrz" beda sie nazywac standardowo, ale "wewnatrz" beda w wersji leniwej
	void put(typ& a) { putLazy(a); }
	typ get(){ return getLazy(); }
};


template <typename typ>
class AbstractPriorityOfficiousQueue : public AbstractPriorityQueue<typ> {
protected:
	AbstractPriorityOfficiousQueue(const char* txt) : AbstractQueue<typ>("Officious"){ std::cout << txt; }

private:
	// wymuszenie stworzenia dla interfejsu nadgorliwych wersji metod
	virtual void putOfficious(typ&) = 0;
	virtual typ getOfficious() = 0;
	
public:
// metody interfejsu kolejki "na zewnatrz" beda sie nazywac standardowo, ale "wewnatrz" beda w wersji nadgorliwej
	void put(typ& a) { putOfficious(a); }
	typ get(){ return getOfficious(); }
};
#endif
