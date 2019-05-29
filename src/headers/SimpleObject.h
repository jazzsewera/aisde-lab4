/*
 *  ObjectInt.h
 *
 *  Created by aw on 11/29/09.
 *  Copyright 2009 p. All rights reserved.
 *
 */

// Prosty obiekt, ktory moze byc trzymany w kolejce
// Obiekt zawiera jedna dana, wartosc ktorej jest jednoczesnie wartoscia priorytetu 

#ifndef OBJECT_INT_H
#define OBJECT_INT_H
#include "AbstractPriorityObject.h"

template <typename typ>
class SimpleObject : public AbstractPriorityObject<SimpleObject<typ>,typ,typ> {
	typ data;
	
public:
	SimpleObject<typ>(){}
	SimpleObject<typ>(typ d) : data(d) {}

	void setValue(typ s){ data = s; }
	
	typ getPriority(){ return data; };
	typ getValue(){ return data; }
	
	bool operator<(SimpleObject<typ>& x){
#if(STATISTICS)
		AbstractPriorityObject<SimpleObject<typ>,typ,typ>::comparisonIncreament();
#endif
		return getPriority() < x.getPriority();
	}
	
#if(STATISTICS)
// konstruktor kopiujacy (korzysta z operatora podstawienia)
	SimpleObject<typ>(const SimpleObject<typ>& source){ *this = source; }
// operator podstawienia
	SimpleObject<typ>& operator=(const SimpleObject<typ>& source){
		data = source.data;
		AbstractPriorityObject<SimpleObject<typ>,typ,typ>::copyingIncreament();
		return *this;
	}
#endif		
	
};

#endif
