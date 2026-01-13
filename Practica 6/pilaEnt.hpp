/*  
 * Autores: Rubén Martín González NIP:841886	
 *          Sergio Salesa Quintanilla NIP:811019 
 * Fecha: 7/1/2023
 * Comentario: Fichero pilaEnt.hpp del TAD genérico PilaEnt para su uso en el multi2.hpp
 *             Este fichero utiliza el fichero multi2.hpp 
 */
#ifndef PILAENT_HPP
#define PILAENT_HPP

// Capacidad máxima de almacenamiento de datos en una pila
const int DIM = 120;            // Redefinir su valor en caso necesario

template<typename T> struct PilaEnt;

template<typename T> void vaciar(PilaEnt<T> &p);
template<typename T> void apilar(PilaEnt<T> &p,const T& nuevo);
template<typename T> void desapilar(PilaEnt<T> &p);
template<typename T> void cima(PilaEnt<T> &p, T& e);
template<typename T> bool estaVacia(const PilaEnt<T> &p);


// Un dato definido a partir del tipo PilaEnt representa una pila
// de datos de enteros. Los datos son gestionados según una política LIFO,
// es decir el último en ser apilado será el primero en ser desapilado.
template<typename T>
struct PilaEnt{
    friend void vaciar<T>(PilaEnt<T> &p);
    friend void apilar<T>(PilaEnt<T> &p,const T& nuevo);
    friend void desapilar<T>(PilaEnt<T> &p);
    friend void cima<T>(PilaEnt<T> &p,T& e);
    friend bool estaVacia<T>(const PilaEnt<T> &p);
    // Número de datos almacenados en la pila
    int numDatos;
    // Los datos de la pila se almacenan en datos[0,numDatos-1], siendo
    // datos[0] el más antiguo, datos[1] el segundo más antiguo y, así
    // sucesivamente, siendo datos[numDatos-1] la cima o dato más reciente
    // de los almacenados en la pila
    T datos[DIM];
};

//  Notación empleada en la especificación de funciones:
//    p = [] la pila está vacía, es decir, almacena 0 datos
//    p = [d_1, d_2, ..., d_K] la pila almacena K datos. El más antiguo
//        es el dato d_1, el segundo más antiguo el dato d_2, etc., etc.,
//        y el más reciente es el dato d_K

// Pre:  ---
// Post: p = []
template<typename T>
void vaciar(PilaEnt<T> &p){
    p.numDatos = 0;
}

// Pre:  p = [d_1, d_2, ..., d_K] AND K >= 0 AND K < DIM
// Post: p = [d_1, d_2, ..., d_K, nuevo]
template<typename T>
void apilar(PilaEnt<T> &p, const T& nuevo){
    p.datos[p.numDatos] = nuevo;
    p.numDatos++;
}

// Pre:  p = [d_1, d_2, ...,d_(K-1), d_K] AND K > 0
// Post: p = [d_1, d_2, ..., d_(K-1)]
template<typename T>
void desapilar(PilaEnt<T> &p){
    p.numDatos--;
}

// Pre:  p = [d_1, d_2, ...,d_(K-1),d_K] AND K > 0
// Post: cima(p) = d_K
template<typename T>
void cima(PilaEnt<T> &p,T& e){
    e=p.datos[p.numDatos-1];   
}

// Pre: ---
// Post: estaVacia(p) = (p = [])
template<typename T>
bool estaVacia(const PilaEnt<T> &p){
    return p.numDatos == 0;
}

#endif
