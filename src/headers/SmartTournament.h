/*
 *  SmartTournament.h
 *
 *  Created by aw on 11/29/09.
 *  Copyright 2009 p. All rights reserved.
 */
 
// Klasa organizujaca turnieje wewnatrz tablicy danych

#ifndef SMART_TOURNAMENT_H
#define SMART_TOURNAMENT_H

#include "SmartDataTable.h"

template <typename typ>
class SmartTournament : public SmartDataTable<typ> {
public:
// interfejs "turniejowy" tablicy - metoda wykonuje turniej w calej tablicy umieszczajac
// "najwieksza" dana w pierwszym elemencie
	void tournament(){ doTournament(SmartDataTable<typ>::getDataSize()); }

private:
// metoda lokalna (rekurencyjna): wykonuje "pojedynki" par danych dla kolejnych etapów turnieju;
// "zwyciezca" pojedynku jest przenoszony do lewej czesci tablicy, "przegrany" do prawej
	void doTournament(long last){
		if(0L < last){
			long i = 0L;
			long j = last;
			while(j > i){
				if((*this)[i] < (*this)[j]){
					SmartDataTable<typ>::swap(i, j);
				}
				j--;
				i++;
			}
			doTournament(last>>1); // do dalszych "gier" przechodzi tylko lewa polowa tablicy
		}
	}
};

#endif
