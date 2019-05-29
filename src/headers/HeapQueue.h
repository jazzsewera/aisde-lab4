/*
 *  HeapQueue.h
 *
 *  Created by aw on 11/29/09.
 *  Copyright 2009 p. All rights reserved.
 */

// Kolejka priorytetowa dzialajaca z uzyciem kopca (dwie wersje: leniwa i nadgorliwa)
// dziedziczenie dwubazowe:
// - dziedziczony jest interfejs odpowiedniej kolejki
// - dziedziczona jest turniejowa wersja tablicowej bazy danych

#ifndef HEAP_QUEUE_H
#define HEAP_QUEUE_H
#include "SmartHeap.h"
#include "AbstractPriorityQueue.h"

// Wersja nadgorliwa
template <typename typ>
class HeapQueueOfficious : public SmartHeap<typ>, public AbstractPriorityOfficiousQueue<typ>{
public:
	HeapQueueOfficious() : AbstractPriorityOfficiousQueue<typ>("Heap"){ std::cout << "\n"; }
	
private:
	void putOfficious(typ& a) {
		(*this) += a; // dodanie do liscia nowego elementu danych
		SmartHeap<typ>::fixLast(); // przywrocenie ukopcowania od liscia
	}
	
	typ getOfficious(){
		typ ret = SmartHeap<typ>::getSecound(); // wykonanie kopii wyjmowanych danych (a potem skrajny lisc przerzucany jest do korzenia)
		SmartHeap<typ>::fixRoot(); // przywrocenie ukopcowania od korzenia
		return ret;
	}
};


// Wersja leniwa
template <typename typ>
class HeapQueueLazy : public SmartHeap<typ>, public AbstractPriorityLazyQueue<typ> {	
// wypelnienie trescia metod prywatnego interfejsu kolejki leniwej
public:
	HeapQueueLazy() : AbstractPriorityLazyQueue<typ>("Heap"){ std::cout << "\n"; }
	
private:
	void putLazy(typ& a) {
		(*this) += a; // dodanie do liscia nowego elementu danych
	}
	
	typ getLazy(){
		if(SmartHeap<typ>::getDataSize() < 0L) throw QueueException(QUEUE_EMPTY);

		SmartHeap<typ>::fixHeap(); // ukopcowanie danych - trzeba znalezc element najwiekszy
		return SmartHeap<typ>::getSecound();
	}
};

#endif
