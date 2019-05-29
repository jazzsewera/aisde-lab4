/*
 *  AbstractPriorityObject.h
 *
 *  Created by aw on 11/27/09.
 *  Copyright 2009 p. All rights reserved.
 */
 
// Klasa okresla abstrakcyjny element danych, ktory moze byc trzymany w kolejce

#ifndef ABSTRACT_PRIORITY_OBJECT_H
#define ABSTRACT_PRIORITY_OBJECT_H

#include "statistics.h"

template <typename objTyp, typename objValue, typename objPriority>
class AbstractPriorityObject {

// atrybuty i metody do wykonywania statystyk dzialania kolejki
#if(STATISTICS)
	static unsigned long comparisons;
	static unsigned long copyings;
protected:
	void comparisonIncreament(){ comparisons++; }
	void copyingIncreament(){ copyings++; }
public:
	static unsigned long getComparisons(){ return comparisons; }
	static unsigned long getCopyings(){ return copyings; }
#endif

// interfejs obiektu, ktory moze byc przechowywany w kolejce
// powinien zawierac nastepujace metody:
public:
	virtual objPriority getPriority() = 0; // zwraca
	virtual objValue getValue() = 0;
	virtual bool operator<(objTyp&) = 0;

};

// alokacja atrybutow statycznych klasy
#if(STATISTICS)
	#ifdef MAIN_FILE
		template <typename objTyp, typename objValue, typename objPriority> unsigned long AbstractPriorityObject<objTyp,objValue,objPriority>::comparisons = 0L;
		template <typename objTyp, typename objValue, typename objPriority> unsigned long AbstractPriorityObject<objTyp,objValue,objPriority>::copyings = 0L;
	#endif
#endif

#endif
