// =================================================================
//
// File: main.cpp
// Author: Juan Pablo Cabrera Quiroga, asesoría de Santiago Rodriguez
// El archivo main de este programa está hecho por mi (Juan Pablo Cabrera) pero tuve de base los conocimientos y ayuda de mi compañero 
//Santiago rodriguez. Los demás puntos .h están hechos por mí.
// Date: 06/09/2022
//
// =================================================================
#include <iostream>
#include <vector>
#include "header.h"
#include "search.h"
#include "bubble.h"
#include "selection.h"
#include "insertion.h"
#include "arreglo.h"


using namespace std;

int main(int argc, char* argv[]) {   
   Arreglo datos, valores;
   
   //====================================================================
   //Desplegar num de comparaciones que hace cada algoritmo de busqueda
   //
   //Orden: Bubble, Sort, Insertion
   //====================================================================
   datos.leerDatos("input1.txt");
   cout << bubbleSort(datos.getDatos(), datos.getSize()) << " ";
   datos.borrar();
   datos.leerDatos("input1.txt");
   cout << selectionSort(datos.getDatos(), datos.getSize()) << " ";
   datos.borrar();
   datos.leerDatos("input1.txt");
   cout << insertionSort(datos.getDatos(), datos.getSize());
   cout << endl;

   //=======================================================================
   //Desplegar las en cada linea:
   //posicion, num comparaciones secuencial, num comparaciones binarias
   //=======================================================================
   valores.leerValores("input1.txt");
   cout << endl;
   for(int i=0; i<valores.getSize(); i++){
      cout << sequentialSearch(datos.getDatos(), datos.getSize(), valores.getDatos()[i]) << " " 
      << cantSequential(datos.getDatos(), datos.getSize(), valores.getDatos()[i]) << " "
      << cantBinary(datos.getDatos(), datos.getSize(), valores.getDatos()[i]) << endl;
   }




   return 0;
}
