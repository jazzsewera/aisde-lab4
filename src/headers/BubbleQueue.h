/*
 *  BubbleQueue.h
 *
 *  Created by aw on 12/1/09.
 *  Copyright 2009 p. All rights reserved.
 */


// Kolejka priorytetowa dzialajaca z uzyciem "bombelkowania" (dwie wersje: leniwa i nadgorliwa)
// dziedziczenie dwubazowe:
// - dziedziczony jest interfejs odpowiedniej kolejki
// - dziedziczona jest turniejowa wersja tablicowej bazy danych

#ifndef BUBBLE_QUEUE_H
#define BUBBLE_QUEUE_H
#include "SmartBubble.h"
#include "AbstractPriorityQueue.h"

// Wersja nadgorliwa
template <typename typ>
class BubbleQueueOfficious : public SmartBubble<typ>, public AbstractPriorityOfficiousQueue<typ>{
public:
	BubbleQueueOfficious() : AbstractPriorityOfficiousQueue<typ>("Bubble"){ std::cout << "\n"; }
	
// wypelnienie trescia metod prywatnego interfejsu kolejki nadgorliwej
private:
	void putOfficious(typ& a) {
		(*this) += a; // dodanie nowego elementu danych
		SmartBubble<typ>::bubble(); // wykonanie "bombelkowania" - zawsze aktualnie najwiekszy ma byc dostepny
	}
	
	typ getOfficious(){
		typ ret = SmartBubble<typ>::getFirst(); // wykonanie kopii wyjmowanych danych
		SmartBubble<typ>::bubble(); // wykonanie "bombelkowania" - zawsze aktualnie najwiekszy ma byc dostepny 
		return ret;
	}
};

// Wersja leniwa
template <typename typ>
class BubbleQueueLazy : public SmartBubble<typ>, public AbstractPriorityLazyQueue<typ> {	
public:
	BubbleQueueLazy() : AbstractPriorityLazyQueue<typ>("Bubble"){ std::cout << "\n"; }

// wypelnienie trescia metod prywatnego interfejsu kolejki leniwej
private:
	void putLazy(typ& a) {
		(*this) += a; // dodanie nowego elementu danych
	}
	
	typ getLazy(){
		if(SmartBubble<typ>::getDataSize() < 0L) throw QueueException(QUEUE_EMPTY);

		SmartBubble<typ>::bubble(); // wykonanie "bombelkowania" - trzeba znalezc element najwiekszy 
		return SmartBubble<typ>::getFirst();
	}
};

#endif
