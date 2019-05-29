/*
 *  SmartSelection.h
 *
 *  Created by aw on 12/2/09.
 *  Copyright 2009 p. All rights reserved.
 */


// Klasa organizujaca selekcje wewnatrz tablicy danych

#ifndef SMART_SELECTION_H
#define SMART_SELECTION_H

#include "SmartDataTable.h"

template <typename typ>
class SmartSelection : public SmartDataTable<typ> {
public:
	// interfejs "selekcyjny" tablicy - metoda przeglada cala tablice umieszczajac
	// "najwieksza" dana w pierwszym elemencie
	void selection(){
		long currMax = SmartDataTable<typ>::getDataSize();
		for(long i = currMax; i >= 0L; i--){
			if(!((*this)[i] < (*this)[currMax])) currMax = i;
		}
		if(currMax != 0) SmartDataTable<typ>::swap(0, currMax);
	}
};

#endif
