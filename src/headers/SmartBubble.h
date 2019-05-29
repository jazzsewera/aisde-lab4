/*
 *  SmartBubble.h
 *
 *  Created by aw on 12/1/09.
 *  Copyright 2009 p. All rights reserved.
 */


// Klasa organizujaca "bombelkowanie" wewnatrz tablicy danych

#ifndef SMART_BUBBLE_H
#define SMART_BUBBLE_H

#include "SmartDataTable.h"

template <typename typ>
class SmartBubble : public SmartDataTable<typ> {
public:
	// interfejs "bombelkowy" tablicy - metoda przeglada jednym "bombelkiem" cala tablice umieszczajac
	// "najwieksza" dana w pierwszym elemencie
	void bubble(){
		for(long i = SmartDataTable<typ>::getDataSize(); i >= 1L; i--){
			for(long j = i - 1; j >= 0L; j--){
				if(!((*this)[j] < (*this)[i])){
					SmartDataTable<typ>::move(++j, i);
					i = j;
					break;
				}
				if(j == 0){
					SmartDataTable<typ>::move(0, i);
					i = 0;
					break;
				}
			}
		}
	}
};

#endif
