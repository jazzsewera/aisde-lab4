/*
 *  SelectionQueue.h
 *
 *  Created by aw on 12/2/09.
 *  Copyright 2009 p. All rights reserved.
 */



// Kolejka priorytetowa dzialajaca z uzyciem selekcji (dwie wersje: leniwa i nadgorliwa)
// dziedziczenie dwubazowe:
// - dziedziczony jest interfejs odpowiedniej kolejki
// - dziedziczona jest turniejowa wersja tablicowej bazy danych

#ifndef SELECTION_QUEUE_H
#define SELECTION_QUEUE_H
#include "SmartSelection.h"
#include "AbstractPriorityQueue.h"

// Wersja nadgorliwa
template <typename typ>
class SelectionQueueOfficious : public SmartSelection<typ>, public AbstractPriorityOfficiousQueue<typ>{
public:
	SelectionQueueOfficious() : AbstractPriorityOfficiousQueue<typ>("Selection"){ std::cout << "\n"; }
	
	// wypelnienie trescia metod prywatnego interfejsu kolejki nadgorliwej
private:
	void putOfficious(typ& a) {
		(*this) += a; // dodanie nowego elementu danych
		SmartSelection<typ>::selection(); // wykonanie selekcji - zawsze aktualnie najwiekszy ma byc dostepny
	}
	
	typ getOfficious(){
		typ ret = SmartSelection<typ>::getFirst(); // wykonanie kopii wyjmowanych danych
		SmartSelection<typ>::selection(); // wykonanie selekcji - zawsze aktualnie najwiekszy ma byc dostepny 
		return ret;
	}
};

// Wersja leniwa
template <typename typ>
class SelectionQueueLazy : public SmartSelection<typ>, public AbstractPriorityLazyQueue<typ> {	
public:
	SelectionQueueLazy() : AbstractPriorityLazyQueue<typ>("Selection"){ std::cout << "\n"; }
	
	// wypelnienie trescia metod prywatnego interfejsu kolejki leniwej
private:
	void putLazy(typ& a) {
		(*this) += a; // dodanie nowego elementu danych
	}
	
	typ getLazy(){
		if(SmartSelection<typ>::getDataSize() < 0L) throw QueueException(QUEUE_EMPTY);

		SmartSelection<typ>::selection(); // wykonanie selekcji - trzeba znalezc element najwiekszy 
		return SmartSelection<typ>::getFirst();
	}
};

#endif
