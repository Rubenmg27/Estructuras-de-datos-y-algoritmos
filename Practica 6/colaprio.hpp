/*  
 * Autores: Rubén Martín González NIP:841886	
 *          Sergio Salesa Quintanilla NIP:811019 
 * Fecha: 7/1/2023
 * Comentario: Fichero colaprio.hpp del TAD genérico colaprio para su uso en el main.cpp
 *             Este fichero utiliza el fichero cola.hpp 
 */
#include "cola.hpp"
#ifndef COLAPRIO_HPP
#define COLAPRIO_HPP

// PREDECLARACIÓN DEL TAD GENÉRICO colaprio

template<typename T> struct colaprio;
template<typename T> void crearcolaprio(colaprio<T>& c);
template<typename T> void encolarp(colaprio<T>& c, const T& e,const int numero,bool prio);
template<typename T> bool esVaciap(const colaprio<T>& c);
template<typename T> void primerop(const colaprio<T>& c, T& e, bool& error);
template<typename T> void desencolarp(colaprio<T>& c);
template<typename T> int longitudp(const colaprio<T>& c);
template<typename T> int longClase(const colaprio<T>& c,bool prio);
template<typename T> void iniciarIteradorp(colaprio<T>& c);
template<typename T> bool existeSiguientep(const colaprio<T>& c,bool prio);
template<typename T> void siguientep(colaprio<T>& c, T& e,int& valor,bool prio, bool& error);

// DECLARACIÓN DEL TAD GENÉRICO colaprio

template<typename T>
struct colaprio{
    friend void crearcolaprio<T>(colaprio<T>& c);
    friend void encolarp<T>(colaprio<T>& c, const T& e,const int numero,bool prio);
    friend bool esVaciap<T>(const colaprio<T>& c);
    friend void primerop<T>(const colaprio<T>& c,T& e,bool& error);
    friend void desencolarp<T>(colaprio<T>& c);
    friend int longitudp<T>(const colaprio<T>& c);
    friend int longClase<T>(const colaprio<T>& c,bool prio);
    //COMPLETAR OPERACIONES ITERADOR
    friend void iniciarIteradorp<T>(colaprio<T>& c);
    friend bool existeSiguientep<T>(const colaprio<T>& c,bool prio);
    friend void siguientep<T>(colaprio<T>& c, T& e,int& valor,bool prio, bool& error);
  private: 

    cola<T> prio;
    cola<T> noprio;
};


// IMPLEMENTACIÓN DE LAS OPERACIONES DEL TAD GENÉRICO colaprio

template<typename T>
void crearcolaprio(colaprio<T>& c) {
    crearcolaVacia(c.noprio);
    crearcolaVacia(c.prio);
}

template<typename T>
void encolarp(colaprio<T>& c, const T& e,const int numero,bool prio) {
    if(prio){
        encolarcola(c.prio,e,numero);
    }
    else{
        encolarcola(c.noprio,e,numero);
    }
}

template<typename T>
bool esVaciap(const colaprio<T>& c) {
    return vaciacola(c.prio) && vacia(c.noprio);
}
	
template<typename T>
void primerop(const colaprio<T>& c,T& e,bool& error) {
    if(!vaciacola(c.prio)){
        primerocola(c.prio,e,error);
    }
    else if(!vaciacola(c.noprio)){
        primerocola(c.noprio,e,error);
    }
}

template<typename T>
void desencolarp(colaprio<T>& c) {
    if(!vaciacola(c.prio)){
        desencolarcola(c.prio);
    }
    else if(!vaciacola(c.noprio)){
        desencolarcola(c.noprio);
    }
}

template<typename T>
int longitudp(const colaprio<T>& c) {
    return longitudcola(c.prio)+longitudcola(c.noprio);
}

template<typename T>
int longClase(const colaprio<T>& c,bool prio) {
    if(prio){
        return longitudcola(c.prio);
    }
    else{
        return longitudcola(c.noprio);
    }
}

//COMPLETAR IMPLEMENTACION OPERACIONES ITERADOR

template<typename T> void iniciarIteradorp(colaprio<T>& c){
    iniciarIteradorcola(c.prio);
    iniciarIteradorcola(c.noprio);
}


template<typename T> bool existeSiguientep(const colaprio<T>& c,bool prio){
    if(prio){
        return existeSiguientecola(c.prio);
    }
    else{
        return existeSiguientecola(c.noprio);
    }
}


template<typename T> void siguientep(colaprio<T>& c, T& e,int& valor,bool prio, bool& error){
    if(prio){
        if(existeSiguientecola(c.prio)){
            siguientecola(c.prio,e,valor,error);
        }
    }
    else if(existeSiguientecola(c.noprio)){
        siguientecola(c.noprio,e,valor,error);
    }
}


#endif //fin de colaprio.hpp
