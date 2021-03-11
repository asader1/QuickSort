#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "QS.h"
using namespace std;




bool QS::createArray(int capacity) {
    currentCapacity = capacity;
    //if (currentInsertPosition != 0) {
    //    currentInsertPosition = 0;
    //}
    if (capacity < 0) {
        return false;
    } else {
        dynArray = new int(capacity);
        currentInsertPosition = 0;
        cout << "We are here. Capacity: " << to_string(capacity) << endl;
        return true;
    }
}

bool QS::addToArray(int value){
    if (currentInsertPosition <= currentCapacity-1){
        dynArray[currentInsertPosition] = value;
        currentInsertPosition++;
        return true;
    }
    else{
        return false;
    }
}

void QS::printArray(){
    cout << "printing Array. currentInsertPosition: " << to_string(currentInsertPosition) << endl;
    for(int i = 0; i < currentInsertPosition; i++){
        cout << to_string(i) << " " << to_string(dynArray[i]) << endl;
        }
}

void QS::clear(){
    currentInsertPosition = 0;
    //dynArray[currentInsertPosition] = 0;
}

string QS::getArray() {
    string arrayAsString = "nothing";
    cout << "Started getArray. getSize: " << getSize() << endl;
    for(int i = 0; i < getSize(); i++){
        cout << "first loop: " << to_string(i) << " " << to_string(dynArray[i]) << endl;
    }

    cout << arrayAsString << endl;
    for(int i = 0; i < 9; i++){
        arrayAsString = arrayAsString + to_string(dynArray[i]);
        cout << "second loop: " << i << ": " << to_string(dynArray[i]) << " arrayAsString: " << arrayAsString << endl;
        //if(i != getSize()-1){
        //    arrayAsString = arrayAsString + ",";
        //}
    }


    cout << "End of getAray. arrayAsString: " << arrayAsString << endl;
    return arrayAsString;
}

int QS::getSize() {
    return currentInsertPosition;
}

int QS::medianOfThree(int left, int right){
    //if(dynArray(left, right, 0, false) == false){
    //    return -1;
    //}
    int middle = (left + right)/2;
    cout << "left: " << to_string(left) << "middle: " << to_string(middle) << "right: " << to_string(right) << endl;

    int tempArray[3] = {dynArray[left],dynArray[middle],dynArray[right]}; //array to hold left, middle, and right
    int tempArrayLen = *(&tempArray + 1) - tempArray;
    cout << "tempArrayLen: " << to_string(tempArrayLen) << endl;

//implement bubble sort
    int i, j, temp;
    for (i = 0; i < tempArrayLen; i++) {
        // Last i elements are already in place
        for (j = 0; j < tempArrayLen-i-1; j++) {
            if (tempArray[j] > tempArray[j + 1]) {
                //swap(&arr[j], &arr[j + 1]);
                //void swap(int *xp, int *yp)
                temp = tempArray[j];
                tempArray[j] = tempArray[j+1];
                tempArray[j+1] = temp;
            }
        }
    }

    cout << "tempArray0: "  << to_string(tempArray[0]) << endl;
    cout << "tempArray1: "  << to_string(tempArray[1]) << endl;
    cout << "tempArray2: "  << to_string(tempArray[2]) << endl;

    return middle;
}




/*
void QS::sortAll(){
	// getSize();
	// if(currentArray[0] != 0 && currentArray[size-1] != 0){
	// 	int pivot = medianOfThree(currentArray[0], currentArray[size-1]);
	// 	partition(currentArray[0], currentArray[pivot], currentArray[size-1]);
	// }
}

bool QS::validArray(int left, int right, int middle, bool allTests){
	if(currentArray[left] == 0 && currentArray[right] == 0){
		return false;
	}
	if(left >= right || left < 0){
		return false;
	}
	if(allTests == true){
		if(middle < left || middle > right){
			return false;
		}
	}
}

int QS::medianOfThree(int left, int right){
	if(validArray(left, right, 0, false) == false){
		return -1;
	}
	int middle = (left + right)/2;
	if(currentArray[left] > currentArray[right]){
		int temp = currentArray[right];
		currentArray[right] = currentArray[left];
		currentArray[left] = temp;
	}
	if(currentArray[left] > currentArray[middle]){
		int temp = currentArray[middle];
		currentArray[middle] = currentArray[left];
		currentArray[left] = temp;
	}
	return middle;
}

int QS::partition(int left, int right, int pivotIndex){
	if(validArray(left, right, pivotIndex, true) == false){
		return -1;
	}

	int temp = currentArray[left];
	currentArray[left] = currentArray[pivotIndex];
	currentArray[pivotIndex] = temp;
	pivotIndex = left;

	for(int i = 0; i < right; i++){
		if(currentArray[i] < currentArray[pivotIndex] && i == pivotIndex+1){
			int temp = currentArray[i];
			currentArray[i] = currentArray[pivotIndex];
			currentArray[pivotIndex] = temp;
			pivotIndex = i;
		}
		else if(currentArray[i] < currentArray[pivotIndex] && i != pivotIndex+1){
			for(int j = i; j >= pivotIndex; j--){
				int temp = currentArray[j];
				currentArray[j] = currentArray[j-1];
				currentArray[j-1] = temp;
				if(j == pivotIndex){
					pivotIndex = j+1;
				}
			}
		}
	}

	return pivotIndex;
}

string QS::getArray(){
	string arrayString = "";
	if(currentArray[0] == 0 && currentArray[size-1] == 0){
		return arrayString;
	}
	else{
		for(int i = 0; i < size; i++){
			arrayString.push_back((char)currentArray[i]);
			if(i != size-1){
				arrayString.push_back(',');
			}
		}
	}
	return arrayString;
}

int QS::getSize(){
	int tempSize = 0;

	for(int i = 0; i < size; i++){
		if(currentArray[i] != 0){
			tempSize = tempSize+1;
		}
		else{
			return size = tempSize;
		}
	}
	if(tempSize == size){
		return size;
	}
}
	
bool QS::addToArray(int value){ 
	currentArray[counter] = value;
	counter = counter+1;
	return true;
}

bool QS::createArray(int capacity){ //capacity = size
    if(capacity <= 0){
        return false;
    }
    if(currentArray[0] != 0){
        clear();
    }
    new int[capacity];
    size = getSize();
    return true;
}

void QS::clear(){
	int currentArray[0];
	counter = 0;
}


*/