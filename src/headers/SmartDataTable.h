/*
 *  SmartDataTable.h
 *
 *  Created by aw on 11/30/09.
 *  Copyright 2009 p. All rights reserved.
 */

// Tablica przechowująca dane przy tablicowych implementacjach kolejki priorytetowej.
// Jest to "sprytna tablica" wyposazona w dodatkowe metody i atrybuty

#ifndef SMART_DATA_TABLE_H
#define SMART_DATA_TABLE_H
#include "SmartTable.h"
#include "AbstractPriorityQueue.h"

template <typename typ>
class SmartDataTable : public SmartTable<typ> {
	long dataSize; // liczba danych w tablicy (moze sie zmieniac w wyniku wykonania operacji interfejsu kolejki: get i put )
	
public:
	SmartDataTable<typ>() : dataSize(-1L) {}

// metody określające wartość i dostęp do liczby danych	z zewnątrz klasy
	long getDataSize(){ return dataSize; }
	void increaseDataSize(){ dataSize++; }
	void decreaseDataSize(){ dataSize--; }

// dodawanie elementu do tablicy (na pierwsze wolne miejsce)
	void operator += (typ& t){ (*this)[++dataSize] = t; }

// przekazanie kopii pierwszego elementu tablicy danych;
// na pierwsze miejsce przerzucany jest ostatni element, a rozmiar danych zmniejszany jest o jeden
	typ getFirst(){
		if(dataSize < 0L) throw QueueException(QUEUE_EMPTY);
		typ ret = (*this)[0];
		if(dataSize > 0L) (*this)[0] = (*this)[dataSize--];
		return ret;
	}

// przekazanie kopii drugiego elementu tablicy danych;
// na drugie miejsce przerzucany jest ostatni element, a rozmiar danych zmniejszany jest o jeden
	typ getSecound(){
		if(dataSize < 1L) throw QueueException(QUEUE_EMPTY);
		typ ret = (*this)[1];
		if(dataSize > 1L) (*this)[1] = (*this)[dataSize--];
		return ret;
	}
	
// przekazanie kopii ostatniego elementu tablicy danych;
// rozmiar danych zmniejszany jest o jeden
	typ getLast(){
		if(dataSize < 0L) throw QueueException(QUEUE_EMPTY);
		return (*this)[dataSize--];
	}
	
// zamiana miejscami dwóch elementów w tablicy danych
// (procedura jest zoptymalizowana pod względem liczby wywolan operatora [])
// procedura niezoptymalizowana wygladala by tak:
//  typ bufor = (*this)[i];
//  (*this)[i] = (*this)[j];
//  (*this)[j] = bufor;
	void swap(long i, long j){
		typ& refi = (*this)[i];
		typ bufor = refi;
		typ& refj = (*this)[j];
		refi = refj;
		refj = bufor;
	}

	void swap(long i){
		if((*this)[i].getPriority() < (*this)[dataSize].getPriority()){
			swap(i, dataSize);
		}
	}
	
// przesuwanie bloku danych z przeniesieniem ostatniego elementu tego bloku na pierwsze miejsce
	void move(long i, long j){
		if(j > i){
			typ bufor = (*this)[j];
			for(long k = j; k > i; k--) swap(k, k-1);
			(*this)[i] = bufor;
		}
	}

// metoda pomocnicza do wyprowadzania na konsole zawartości tablicy danych
public:
	void printDataTable(const char* string){
		std::cout << "DataTable (" << string << "):\n";
		for(long i = 0; i <= getDataSize(); i++) std::cout << (*this)[i].getValue() << "\n";
		std::cout << "-------\n";
	}	
};

#endif
