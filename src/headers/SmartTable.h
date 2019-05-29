/*
 *  Created by aw on 5/8/08.
 *  Copyright 2008 Adam Wojtasik. All rights reserved.
 */
 
// Zawartość tego pliku nie ma znaczenia dla ćwiczenia nr 4 AISDE
// Jest tu pomocnicza struktura "sprytnej" tablicy, czyli takiej,
// która sama dostosowuje swoj maksymalny rozmiar do liczby danych,
// jakie maja sie w niej znalezc


#ifndef SMART_TABLE_H
#define SMART_TABLE_H
#include <stdlib.h>
#include <iostream>

#define DEFAULT_PAGE_SIZE 100

class SmartTableError{
public:
	int		errID;

// constructor
	SmartTableError(int i) : errID(i){}
};



template <typename typ>
class SmartTablePage{
private:
	SmartTablePage*	nextPage;
	typ*			pagePtr;

// constructor	
public:
	SmartTablePage(long a) : nextPage(NULL) { if((pagePtr = new typ[a]) == NULL) throw SmartTableError(1); }

// destructor
public:
	~SmartTablePage(){ delete[] pagePtr; }

	template <class> friend class SmartTable;
};



template <typename typ>
class SmartTable{
private:
	const long					pageSize;

	long						maxIndex;
	SmartTablePage<typ>*		firstPage;

// constructor
public:	
	SmartTable<typ>() : pageSize(DEFAULT_PAGE_SIZE), firstPage(NULL), maxIndex(-1L) {}
	SmartTable<typ>(long a) : pageSize(a), firstPage(NULL), maxIndex(-1L) {}

// destructor
	~SmartTable<typ>(){
		while(firstPage != NULL){
			SmartTablePage<typ>* currPage = firstPage;
			firstPage = firstPage->nextPage;
			delete currPage;
		}
	}

// operators
	typ& operator[](long);
	void operator += (typ& t){ (*this)[maxIndex+1] = t; }


// utilities	
	long getMaxIndex(){ return maxIndex; }	

	typ* convertToTable(){
		typ* ret = new typ[maxIndex + 1];
		for(long i = 0; i <= maxIndex; i++) ret[i] = (*this)[i];

		return ret;
	}
};



template <typename typ>
typ& SmartTable<typ> :: operator[](long index){		
	long page = index/pageSize;

	SmartTablePage<typ>* prevPage = NULL;
	SmartTablePage<typ>* currPage = firstPage;

	if(index > maxIndex) maxIndex = index;

	for(long i = 0; i <= page; i++){

		if(currPage == NULL){

			SmartTablePage<typ>* newPage;
			if((newPage = new SmartTablePage<typ>(pageSize)) == NULL) throw SmartTableError(2);

			if(prevPage == NULL) firstPage = newPage;
			else prevPage->nextPage = newPage;

			prevPage = newPage;
			currPage = NULL;
		}
		else{
			prevPage = currPage;
			currPage = currPage->nextPage;
		}
	}

	return (prevPage->pagePtr)[index%pageSize];	// zwrocenie referencji znalezionego obiektu
}

#endif
