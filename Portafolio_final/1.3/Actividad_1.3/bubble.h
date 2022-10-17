#ifndef BUBBLE_H
#define BUBBLE_H

#include "header.h"
#include <vector>

// =================================================================
// Performs the bubble sort algorithm on two vectors.
//
// @param v, a vector of T elements.
// @param v2, a second vector of string elements.
// =================================================================
template <class T>
void bubbleSort(std::vector<T> &v,std::vector<string> &v2) {
	for(int i = v.size() - 1; i > 0; i--){
		for(int j = 0; j < i; j++){
			if(v[j] > v[j + 1]){
				swap(v, j, j + 1);
				swap(v2,j,j+1);
			}
		}
	}
}

#endif 