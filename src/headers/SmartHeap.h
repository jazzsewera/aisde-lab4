/*
 *  SmartHeap.h
 *
 *  Created by aw on 11/28/09.
 *  Copyright 2009 p. All rights reserved.
 */

// Klasa organizujaca kopiec wewnatrz tablicy danych
// (uwaga: korzen ma indeks 1)

#ifndef SMART_HEAP_H
#define SMART_HEAP_H

#include "SmartDataTable.h"

template <typename typ>
class SmartHeap : public SmartDataTable<typ> {

public:
// dodanie "pustego" elementu: w kopcu nie jest stosowany indeks 0
	SmartHeap<typ>() { typ a = typ(); (*this) += a; }

// interfejs klasy:

// przywrocenie ukopcowania po umiesczeniu nowego elementu w korzeniu
	void fixRoot(){ fixDown(1L); }
// przywrocenie ukopcowania po umiesczeniu nowego elementu w ostatnim lisciu
	void fixLast(){ fixUp(SmartDataTable<typ>::getDataSize()); }
// ukopcowanie calej tablicy
	void fixHeap(){ for(long k = SmartDataTable<typ>::getDataSize()>>1; k >= 1; k--) fixDown(k); }
	
private:
// lokalne procedury kopcujace:
	void fixUp(long k){ // przenoszenie elementu w gore kopca (w strone korzenia)
		while(k > 1){			
			if(!((*this)[k>>1] < (*this)[k])) break;
			SmartDataTable<typ>::swap(k, k>>1);
			k = k>>1;
		}
	}

	void fixDown(long k){ // przenoszenie elementu w dol kopca (w strone lisci)
		while((k<<1) <= SmartDataTable<typ>::getDataSize()){
			long j = k<<1;
			if(j < SmartDataTable<typ>::getDataSize() && ((*this)[j] < (*this)[j+1])) j++;
			if(!((*this)[k] < (*this)[j])) break;
			SmartDataTable<typ>::swap(k, j);
			k = j;
		}
	}
};

#endif
