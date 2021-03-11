#include "QSInterface.h"

class QS{
public:
	//void sortAll();
	int medianOfThree(int left, int right);
	//int partition(int left, int right, int pivotIndex);
	string getArray();
	int getSize();
    void printArray();
	bool addToArray(int value);
	bool createArray(int capacity);
	void clear();
private:
	int currentCapacity = 0;
	//int size = 0;
    int *dynArray;
	int currentInsertPosition = 0;
	//ool validArray(int left, int right, int middle, bool allTests);
};