#define VARIANT 8
#define MAIN_FILE

#include <iostream>

#include "RandomGenerator.h"
#include "HeapQueue.h"
#include "TournamentQueue.h"
#include "BubbleQueue.h"
#include "SelectionQueue.h"

#include "SimpleObject.h"


void testVariant(int variant) {
	// Wybor implementacji kolejki:

	// TournamentQueueOfficious<SimpleObject<int> > theQueue; std::cout << "== TournamentQueueOfficious ==\n";
	// TournamentQueueLazy<SimpleObject<int> > theQueue; std::cout << "== TournamentQueueLazy ==\n";
	// HeapQueueOfficious<SimpleObject<int> > theQueue; std::cout << "== HeapQueueOfficious ==\n";
	// HeapQueueLazy<SimpleObject<int> > theQueue; std::cout << "== HeapQueueLazy ==\n";
	// BubbleQueueOfficious<SimpleObject<int> > theQueue; std::cout << "== BubbleQueueOfficious ==\n";
	// BubbleQueueLazy<SimpleObject<int> > theQueue; std::cout << "== BubbleQueueLazy ==\n";
	// SelectionQueueOfficious<SimpleObject<int> > theQueue; std::cout << "== SelectionQueueOfficious ==\n";
	SelectionQueueLazy<SimpleObject<int> > theQueue; std::cout << "== SelectionQueueLazy ==\n";
	RandomGenerator gen(300499); // tu nalezy wstawic numer indeksu

	const int SIZE = 50;

	SimpleObject<int> a = SimpleObject<int>(8);

	switch (variant) {
	case 0:
		std::cout << "\nIn order full read\n";
		for (int i = 0; i < SIZE; ++i) {
			a.setValue(i);
			theQueue.put(a);
		}

#ifdef _DEBUG
		std::cout << "\n[ ";
#endif

		for (int i = 0; i < SIZE; ++i) {
			try {
#ifdef _DEBUG
				std::cout << theQueue.get().getValue() << ", ";
#else
				theQueue.get().getValue();
#endif
			} catch (QueueException& exc) {
				std::cout << "Queue is empty\n";
				break;
			}
		}

#ifdef _DEBUG
		std::cout << "]\n";
#endif

		break;

	case 1:
		std::cout << "\nReverse order full read\n";
		for (int i = SIZE; i > 0; --i) {
			a.setValue(i);
			theQueue.put(a);
		}

#ifdef _DEBUG
		std::cout << "\n[ ";
#endif

		for (int i = 0; i < SIZE; ++i) {
			try {
#ifdef _DEBUG
				std::cout << theQueue.get().getValue() << ", ";
#else
				theQueue.get().getValue();
#endif
			} catch (QueueException& exc) {
				std::cout << "Queue is empty\n";
				break;
			}
		}

#ifdef _DEBUG
		std::cout << "]\n";
#endif

		break;

	case 2:
		std::cout << "\nAlternating full write/read\n";
#ifdef _DEBUG
		std::cout << "\n[ ";
#endif

		for (int i = 0; i < SIZE; ++i) {
			a.setValue(i);
			theQueue.put(a);
			try {
#ifdef _DEBUG
				std::cout << theQueue.get().getValue() << ", ";
#else
				theQueue.get().getValue();
#endif
			} catch (QueueException& exc) {
				std::cout << "Queue is empty\n";
				break;
			}
		}

#ifdef _DEBUG
		std::cout << "]\n";
#endif

		break;

	case 3:
		std::cout << "\nIn order half read\n";
		for (int i = 0; i < SIZE; ++i) {
			a.setValue(i);
			theQueue.put(a);
		}

#ifdef _DEBUG
		std::cout << "\n[ ";
#endif

		for (int i = 0; i < SIZE/2; ++i) {
			try {
#ifdef _DEBUG
				std::cout << theQueue.get().getValue() << ", ";
#else
				theQueue.get().getValue();
#endif
			} catch (QueueException& exc) {
				std::cout << "Queue is empty\n";
				break;
			}
		}

#ifdef _DEBUG
		std::cout << "]\n";
#endif

		break;

	case 4:
		std::cout << "\nReverse order half read\n";
		for (int i = SIZE; i > 0; --i) {
			a.setValue(i);
			theQueue.put(a);
		}

#ifdef _DEBUG
		std::cout << "\n[ ";
#endif

		for (int i = 0; i < SIZE/2; ++i) {
			try {
#ifdef _DEBUG
				std::cout << theQueue.get().getValue() << ", ";
#else
				theQueue.get().getValue();
#endif
			} catch (QueueException& exc) {
				std::cout << "Queue is empty\n";
				break;
			}
		}

#ifdef _DEBUG
		std::cout << "]\n";
#endif

		break;

	case 5:
		std::cout << "\nHalf write, then alternating read\n";
		for (int i = 0; i < SIZE/2; ++i) {
			a.setValue(i);
			theQueue.put(a);
		}

#ifdef _DEBUG
		std::cout << "\n[ ";
#endif

		for (int i = 0; i < SIZE/2; ++i) {
			a.setValue(i);
			theQueue.put(a);
			try {
#ifdef _DEBUG
				std::cout << theQueue.get().getValue() << ", ";
#else
				theQueue.get().getValue();
#endif
			} catch (QueueException& exc) {
				std::cout << "Queue is empty\n";
				break;
			}
		}

#ifdef _DEBUG
		std::cout << "]\n";
#endif

		break;

	case 6:
		std::cout << "\nHalf random write, then alternating write/read\n";
		for (int i = 0; i < SIZE/2; ++i) {
			a.setValue(gen.getRandom(0, SIZE));
			theQueue.put(a);
		}

#ifdef _DEBUG
		std::cout << "\n[ ";
#endif

		for (int i = 0; i < SIZE/2; ++i) {
			a.setValue(gen.getRandom(0, SIZE));
			theQueue.put(a);
			try {
#ifdef _DEBUG
				std::cout << theQueue.get().getValue() << ", ";
#else
				theQueue.get().getValue();
#endif
			} catch (QueueException& exc) {
				std::cout << "Queue is empty\n";
				break;
			}
		}

#ifdef _DEBUG
		std::cout << "]\n";
#endif

		break;

	case 7:
		std::cout << "\nRandom alternating write/read\n";

#ifdef _DEBUG
		std::cout << "\n[ ";
#endif

		for (int i = 0; i < SIZE; ++i) {
			a.setValue(gen.getRandom(0, SIZE));
			theQueue.put(a);
			try {
#ifdef _DEBUG
				std::cout << theQueue.get().getValue() << ", ";
#else
				theQueue.get().getValue();
#endif
			} catch (QueueException& exc) {
				std::cout << "Queue is empty\n";
				break;
			}
		}

#ifdef _DEBUG
		std::cout << "]\n";
#endif

		break;

	case 8:
		std::cout << "\nRandom write, then one read\n";
		for (int i = 0; i < SIZE; ++i) {
			a.setValue(gen.getRandom(0, SIZE));
			theQueue.put(a);
		}

#ifdef _DEBUG
		std::cout << "\n[ ";
#endif

		try {
#ifdef _DEBUG
			std::cout << theQueue.get().getValue() << ", ";
#else
			theQueue.get().getValue();
#endif
		} catch (QueueException& exc) {
			std::cout << "Queue is empty\n";
		}

#ifdef _DEBUG
		std::cout << "]\n";
#endif

		break;
	}

	std::cout << "Comparisons: " << SimpleObject<int>::getComparisons() << "\n";
	std::cout << "Copyings: " << SimpleObject<int>::getCopyings() << "\n";
}


int main (int argc, char* const argv[]) {
	testVariant(VARIANT);

  return 0;
}
