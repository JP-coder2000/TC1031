//////////////////////////////////////
// Implementación de un ADT Arreglo //
// Estructura de Datos              //
//////////////////////////////////////


//Este archivo fue transcrito del GITHUB del profesor.

#include <iostream>
#include <fstream> // manejo de archivos

using namespace std;

#define MAX 500 // máximo total del arreglo
/**Actividad: implementar metodo que intercambie 2 elementos del arreglo*/
// https://drive.google.com/file/d/1mzZRV9gLpeYYp2v8OQSXF9FNM0s5cyrC/view?usp=sharing
class Arreglo
{
private:
    /* data */
    int datos[MAX];
    int tam = 0;
public:
    int * getDatos(){
        return datos;
    }
    int getSize(){
        return tam;
    }
    // recibe un dato entero y lo coloca al final del arreglo
    void insertar(int dato){
        if (tam < MAX){
            datos[tam] = dato;
            tam++; // se incrementa en 1 el tamaño del arreglo
        }
        else{
            cout << "El arreglo está lleno, no se puede insertar el dato" << endl;
        }
    }

    int borrar(){
        int dato;
        while(tam > 0){
            dato = datos[tam-1];
            tam--;
        }
        
        return dato;
    }

    // imprime el contenido del arreglo
    void imprimir(){
        for (int i = 0; i < tam; i++){
            cout << datos[i] << " ";
        }
        cout << endl;
    }

    // Lee un archivo de números enteros para colocarlos en el arreglo
    // El archivo tiene en el primer renglón el número de valores para tam
    // Los siguientes tam renglones contienen un valor por renglón
    void leerDatos(string archivo){
        int n, numero;
        fstream miArchivo(archivo);
        if (miArchivo.is_open()){
            miArchivo >> n;
            for (int i = 0; i < n; i++){
                miArchivo >> numero;
                insertar(numero);
            }
            miArchivo.close();
        }
        else cout << "No se puede abrir el archivo";
    }

    void leerValores(string archivo){
        int n, numero, q, valores;
        fstream miArchivo(archivo);
        if (miArchivo.is_open()){
            miArchivo >> n;
            for (int i = 0; i < n; i++){
                miArchivo >> numero;
            }
            miArchivo >> q;
            for (int i = 0; i < q; i++){
                miArchivo >> valores;
                insertar(valores);
            }
            miArchivo.close();
        }
        else cout << "No se puede abrir el archivo";
    }


    void intercambiar(int i, int j){
        int paso;
        paso = datos[i];
        datos[i] = datos[j];
        datos[j] = paso;
    }

    // ordena el ADT usando Selection Sort
    void selectionSort(){
        int menor;
        for(int i =0; i<= tam-2; i++){
            menor = i;
            for(int j =i+1; j<= tam-1; j++){
                if(datos[j] < datos[menor]){
                    menor = j; //posicion del menor
                }
            }
            // intercambio
            intercambiar(i, menor);
        }
    }

    void insertionSort(){
        for(int i =1; i< tam; i++){
            for(int j = i-1; j >= 0; j--){
                if(datos[j+1] < datos[j])
                    intercambiar(j+1, j);
                else
                    break;
            }
        }
    }
};