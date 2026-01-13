/* Nombre, apellidos y NIP del (de los) autor(es).
*/

#include "cola.hpp"
#ifndef COLAPRIO_HPP
#define COLAPRIO_HPP

// PREDECLARACIÓN DEL TAD GENÉRICO colaprio


/* COMPLETAR CON LA ESPECIFICACIÓN DEL DOMINIO DE VALORES DEL TAD colaprio
   Y CON LAS CONDICIONES QUE SE LE EXIGEN AL PARÁMETRO DE TIPO T.
*/
template<typename T> struct colaprio;


/* COMPLETAR LA ESPECIFICACIÓN DE CADA OPERACIÓN DEL TAD
*/
template<typename T> void crear(colaprio<T>& c);
template<typename T> void encolarp(colaprio<T>& c, const T& e,bool prio);
template<typename T> bool esVacia(const colaprio<T>& c);
template<typename T> void primerop(const colaprio<T>& c, T& e, bool& error);
template<typename T> void desencolarp(colaprio<T>& c);
template<typename T> int longitudp(const colaprio<T>& c);
template<typename T> int longClase(const colaprio<T>& c,bool prio);
template<typename T> void iniciarIteradorp(colaprio<T>& c);
template<typename T> bool existeSiguientep(const colaprio<T>& c);
template<typename T> void siguientep(colaprio<T>& c, T& e, bool& error);

//COMPLETAR OPERACIONES ITERADOR
//....


// DECLARACIÓN DEL TAD GENÉRICO colaprio

template<typename T>
struct colaprio{
    friend void crear<T>(colaprio<T>& c);
    friend void encolarp<T>(colaprio<T>& c, const T& e,bool prio);
    friend bool esVacia<T>(const colaprio<T>& c);
    friend void primerop<T>(const colaprio<T>& c,T& e,bool& error);
    friend void desencolarp<T>(colaprio<T>& c);
    friend int longitudp<T>(const colaprio<T>& c);
    friend int longClase<T>(const colaprio<T>& c,bool prio);
    //COMPLETAR OPERACIONES ITERADOR
    friend void iniciarIteradorp<T>(colaprio<T>& c);
    friend bool existeSiguientep<T>(const colaprio<T>& c);
    friend void siguientep<T>(colaprio<T>& c, T& e, bool& error);
  private: 

    cola<T> prio;
    cola<T> noprio;
};


// IMPLEMENTACIÓN DE LAS OPERACIONES DEL TAD GENÉRICO colaprio

template<typename T>
void crear(colaprio<T>& c) {
    crearVacia(c.noprio);
    crearVacia(c.prio);
}

template<typename T>
void encolarp(colaprio<T>& c, const T& e,bool prio) {
    if(prio){
        encolar(c.prio,e);
    }
    else{
        encolar(c.noprio,e);
    }
}

template<typename T>
bool esVacia(const colaprio<T>& c) {
    return vacia(c.prio) && vacia(c.noprio);
}
	
template<typename T>
void primerop(const colaprio<T>& c,T& e,bool& error) {
    if(!vacia(c.prio)){
        primero(c.prio,e,error);
    }
    else if(!vacia(c.noprio)){
        primero(c.noprio,e,error);
    }
}

template<typename T>
void desencolarp(colaprio<T>& c) {
    if(!vacia(c.prio)){
        desencolar(c.prio);
    }
    else if(!vacia(c.noprio)){
        desencolar(c.noprio);
    }
}

template<typename T>
int longitudp(const colaprio<T>& c) {
    return longitud(c.prio)+longitud(c.noprio);
}

template<typename T>
int longClase(const colaprio<T>& c,bool prio) {
    if(prio){
        return longitud(c.prio);
    }
    else{
        return longitud(c.noprio);
    }
}

//COMPLETAR IMPLEMENTACION OPERACIONES ITERADOR

template<typename T> void iniciarIteradorp(colaprio<T>& c){
    iniciarIterador(c.prio);
    iniciarIterador(c.noprio);
}


template<typename T> bool existeSiguientep(const colaprio<T>& c){
    return existesiguiente(c.prio) || existesiguiente(c.noprio);
}


template<typename T> void siguientep(colaprio<T>& c, T& e, bool& error){
    if(existeSiguiente(c.prio)){
        siguiente(c.prio,e,error);
    }
    else if(existeSiguiente(c.noprio)){
        siguiente(c.noprio,e,error);
    }
}


#endif //fin de colaprio.hpp
