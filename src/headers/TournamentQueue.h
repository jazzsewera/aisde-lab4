/*
 *  TournamentQueue.h
 *
 *  Created by aw on 11/29/09.
 *  Copyright 2009 p. All rights reserved.
 */
 
 // Kolejka priorytetowa dzialajaca z uzyciem turnieju (dwie wersje: leniwa i nadgorliwa)
 // dziedziczenie dwubazowe:
 // - dziedziczony jest interfejs odpowiedniej kolejki
 // - dziedziczona jest turniejowa wersja tablicowej bazy danych

#ifndef TOURNAMENT_QUEUE_H
#define TOURNAMENT_QUEUE_H
#include "SmartTournament.h"
#include "AbstractPriorityQueue.h"

// Wersja nadgorliwa
template <typename typ>
class TournamentQueueOfficious : public SmartTournament<typ>, public AbstractPriorityOfficiousQueue<typ>{
public:
	TournamentQueueOfficious() : AbstractPriorityOfficiousQueue<typ>("Tournament"){ std::cout << "\n"; }
	
	// wypelnienie trescia metod prywatnego interfejsu kolejki nadgorliwej
private:
	void putOfficious(typ& a) {
		(*this) += a; // dodanie nowego elementu danych
		SmartTournament<typ>::tournament(); // wykonanie turnieju - zawsze aktualnie najwiekszy ma byc dostepny
	}
	
	typ getOfficious(){
		typ ret = SmartTournament<typ>::getFirst(); // wykonanie kopii wyjmowanych danych
		SmartTournament<typ>::tournament(); // wykonanie turnieju - zawsze aktualnie najwiekszy ma byc dostepny 
		return ret;
	}
};

// Wersja leniwa
template <typename typ>
class TournamentQueueLazy : public SmartTournament<typ>, public AbstractPriorityLazyQueue<typ> {	
public:
	TournamentQueueLazy() : AbstractPriorityLazyQueue<typ>("Tournament"){ std::cout << "\n"; }
	
	// wypelnienie trescia metod prywatnego interfejsu kolejki leniwej
private:
	void putLazy(typ& a) {
		(*this) += a; // dodanie nowego elementu danych
	}
	
	typ getLazy(){
		if(SmartTournament<typ>::getDataSize() < 0L) throw QueueException(QUEUE_EMPTY);

		SmartTournament<typ>::tournament(); // wykonanie turnieju - trzeba znalezc element najwiekszy 
		return SmartTournament<typ>::getFirst();
	}
};

#endif
