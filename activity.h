// =================================================================
//
// File: activity.h
// Author: Juan Pablo Cabrera
// Date: 25/08/22
//
// =================================================================
#ifndef ACTIVITY_H
#define ACTIVITY_H

// =================================================================
// sumaIterativa. Calculate the sum from 1 to n with an iterative
// method.
//
// @param n	The maximum limit of the sum.
// @return	The result of the addition from 1 to n.
// @Complexity	O(n). Esto se debe a que el tiempo se va mostrando secuencialmente, el ciclo va incrementando por uno.
// =================================================================
unsigned int sumaIterativa( unsigned int n) {
    
    int suma_iterativa = 0;
    int i = 1;
    
        while (i<= n){
            suma_iterativa = suma_iterativa + i; //od1
            i++;// od1
        }
	return suma_iterativa;
}

// =================================================================
// sumaRecursiva. Calculate the sum from 1 to n with an recursive
// method.
//
// @param n	The maximum limit of the sum.
// @return	The result of the addition from 1 to n.
// @Complexity	O(n). Esto se debe a que el tiempo se va mostrando secuencialmente, el ciclo va incrementando por uno.
// =================================================================
unsigned int sumaRecursiva(unsigned int n) {

        if (n == 1)
            return 1;
            
        else
            return n + sumaRecursiva(n-1);

	return 0;
}


// =================================================================
// sumaDirecta. Calculate the sum from 1 to n with a mathematical
// method.
//
// @param n	The maximum limit of the sum.
// @return	The result of the addition from 1 to n.
// @Complexity	O(1) esto porque el numero de tareas no depende del valor de entrada.
// =================================================================
unsigned int sumaDirecta(unsigned int n) {

	int sum = 0;

	sum = (n*(n+1))/2;

	return sum;
}

#endif /* ACTIVITY_H */
