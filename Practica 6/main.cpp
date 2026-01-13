/*  
 * Autores: Rubén Martín González NIP:841886	
 *          Sergio Salesa Quintanilla NIP:811019 
 * Fecha: 7/1/2023
 * Comentario: Fichero main.cpp de la practica6 de Estructuras de Datos y Algoritmos
 *             Compilacion: make -f Makefile_p6
 *             Limpieza: make -f Makefile_p6 clean 
 *
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include "multi2.hpp"
#include "colaprio.hpp"

using namespace std;

/* Programa de prueba del módulo multi.hpp que crea un multiconjunto vacío de strings y luego lee un fichero "entrada.txt"
 * con operaciones a realizar con ese multiconjunto, indicadas con la siguiente sintaxis, y escribe en un fichero "salida.txt"
 * lo indicado según cada opción:
 * A -> añade un ejemplar del string incluido en la siguiente línea y escribe en salida "AÑADIDO string"
 * Q -> quita (si existe) un ejemplar del string incluido en la siguiente línea y escribe en salida "QUITADO string"
 *      o "NO QUITADO string", según corresponda
 * M -> escribe en salida la multiplicidad (M) del string incluido en la siguiente línea (0, si no existe) con la
 *      sintaxis: MULTIPLICIDAD DE string = M
 * L -> escribe en salida todos los elementos distintos del multiconjunto (sea C el cardinal), uno por línea y con formato:
 *      "string M" (donde M es la multiplicidad de ese string),
 *      precedidos por una primera línea con "--- CARDINAL = C", y finalizando con una línea con "---".
 * */

int main()
{
    multi2<string> multiconjcad;
    colaprio<string> cola;
    crearmulti(multiconjcad);
    crearcolaprio(cola);

    ifstream inf;
    inf.open("entrada.txt");
    if (inf.is_open())
    {

        // Tarea 1
        // Procedemos a leer del fichero "entrada.txt" las cadenas que hay en este y las añadimos a multiconjcad
        string elemento;
        int valor,i=0;
        bool error;
        while (inf>>elemento)
        {
            anadirmulti(multiconjcad, elemento);
        }
        inf.close();

        // Tarea 2
        // Iniciamos el iterador de multiconjcad para introducir los elementos en cola. Si la multiplicidad 
        // del elemento es 1 se introducirá el elemento en la cola prioritaria por orden de llegada, si si es mayor a 1 por la no prioritaria
        iniciarIteradormulti(multiconjcad);
        while (existeSiguientemulti(multiconjcad))
        {
            siguientemulti(multiconjcad, elemento,valor, error);
            if (valor== 1)                                          //Multiplicidad = 1
            {
                encolarp(cola, elemento,valor, true);
            }
            else                                                    //Multiplicidad > 1 
            {
                encolarp(cola, elemento,valor, false);
            }
        }
        
        // Tarea 3
        // Finalmente, se va a generar el fichero de salida "salida.txt" con los elementos de cola escritos con su nombre 
        // (y su multiplicidad en el caso en el que sea esta mayor a 1). Primero se escribirán todos los de multiplicidad 1 y
        // después los de multiplicidad > 1.
        ofstream outf;
        outf.open("salida.txt");
        if (outf.is_open())
        {
            // Bucle con iteradores de colaprio metiendo los elementos en outf << ... << endl;
            // OJO EL ORDEN ALFABÉTICO
            iniciarIteradorp(cola);
            while (existeSiguientep(cola,true)){                    //Cola de los prioritarios (Multiplicidad = 1)
                siguientep(cola,elemento,valor,true,error);
                outf<<elemento<<endl;
            }
            while (existeSiguientep(cola,false)){                   //Cola de los no prioritarios (Multiplicidad > 1)
                siguientep(cola,elemento,valor,false,error);
                outf<<elemento<<setw(3)<<valor<<endl;
            }

            // Bucle con iteradores de colanoprio metiendo los elementos en outf << ... << " "<< multi endl;
            // OJO EL ORDEN ALFABÉTICO
            return 0;
        }
        else
        {
            cout << "Error al abrir el fichero \"salida.txt\"" << endl;
            return -1;
        }
    }
    else
    {
        cout << "Error al abrir el fichero \"entrada.txt\"" << endl;
        return -1;
    }
}
