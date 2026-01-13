/*  
 * Autores: Rubén Martín González NIP:841886	
 *          Sergio Salesa Quintanilla NIP:811019 
 * Fecha: 7/1/2023
 * Comentario: Fichero multi2.hpp del TAD genérico colaprio para su uso en el main.cpp
 *             Este fichero utiliza el fichero pilaEnt.hpp 
 */

#ifndef multi2_HPP
#define multi2_HPP
#include "pilaEnt.hpp"

using namespace std;
// PREDECLARACIÓN DEL TAD GENÉRICO multi2

template<typename T> struct multi2;
template<typename T> void crearmulti(multi2<T>& d);
template<typename T> void anadirmulti(multi2<T>& d,const T& e);
template<typename T> void quitarmulti(multi2<T>& d,const T& e,bool& b);
template<typename T> int multi2plicidadmulti(multi2<T>& m,const T& e);
template<typename T> int cardinalmulti(const multi2<T>& d);
template<typename T> void iniciarIteradormulti(multi2<T>& m);
template<typename T> bool existeSiguientemulti(const multi2<T>& m);
template<typename T> void siguientemulti(multi2<T>& m, T& e,int& valor,bool& error);

//FUNCIONES INTERNAS AUXILIARES 
template<typename T> void anadirRec(typename multi2<T>::nodo*& d,const T& clave);
template<typename T> void quitarRec(typename multi2<T>::nodo*& d,const T& clave,bool& b);
template<typename T> void borrarMax(typename multi2<T>::nodo*& d,T& calve,int valor);
template<typename T> int multi2plicidadRec(typename multi2<T>::nodo*& d,const T& clave);

// DECLARACIÓN DEL TAD GENÉRICO multi2

template<typename T>
struct multi2{
    friend void crearmulti<T>(multi2<T>& d);
    friend void anadirmulti<T>(multi2<T>& d,const T& e);
    friend void quitarmulti<T>(multi2<T>& d,const T& e,bool& b);
    friend int multi2plicidadmulti<T>(multi2<T>& d,const T& e);
    friend int cardinalmulti<T>(const multi2<T>& d);
    friend void iniciarIteradormulti<T>(multi2<T>& m);
    friend bool existeSiguientemulti<T>(const multi2<T>& m);
    friend void siguientemulti<T>(multi2<T>& m, T& e,int& valor,bool& error);

  private: 
    struct nodo{
        T clave;
        int valor;
        nodo* der;
        nodo* izq;
    };
    nodo* raiz;
    int l;
    PilaEnt<nodo*> iter;

    //FUNCIONES INTERNAS AUXILIARES 
    friend void anadirRec(nodo*& d,const T& clave){
        nodo* aux;
        if(d==NULL){
            d=new(nodo);
            d->clave=clave;
            d->valor=1;
            d->der=NULL;
            d->izq=NULL;
        }
        else{ 
            if(clave<(d->clave)){
                anadirRec(d->izq,clave);
            }
            else if(clave>(d->clave)){
                anadirRec(d->der,clave);
            }
            else{
                d->valor++;  
            }
        }
    }

    friend void quitarRec(nodo*& d,const T& clave,bool& b){
        nodo* aux;
        if (d==NULL)
        {
            b=false; 
        }
        else{
            if(d->clave <clave){
                quitarRec(d->der,clave,b);
            }
            if(d->clave >clave){
                quitarRec(d->izq,clave,b);
            }
            else if(d->clave==clave){
                d->valor--;
                if(d->izq==NULL){
                    if(d->valor==0){
                        aux=d;
                        d=d->der;
                        delete(aux);
                    }
                }
                else{
                    borrarMax(d->izq,d->clave,d->valor);
                }
                b=true;
            }
        }
    }

    friend void borrarMax(nodo*& d,T& clave,int valor){
        nodo* aux;
        if(d->der==NULL){
            if(d->valor==0){
                clave=d->clave;
                valor=d->valor;
                aux=d;
                d=d->izq;
                delete(aux);
            }
        }
        else{
            borrarMax(d->der,clave,valor);
        }
    }

    friend void multi2plicidadRec(nodo*& d,const T& clave,int& multipli){
        if (d!=NULL){
            if(clave<d->clave){
                multi2plicidadRec(d->izq,clave,multipli);
            }
            if(clave>d->clave){
                multi2plicidadRec(d->der,clave,multipli);
            }
            else if(clave==d->clave){
                multipli = d->valor;
            }
        }
        else{
            multipli = 0;
        }
    }
};


// IMPLEMENTACIÓN DE LAS OPERACIONES DEL TAD GENÉRICO multi2

template<typename T> 
void crearmulti(multi2<T>& d){
    d.l=0;
    d.raiz=NULL;
}


template<typename T> 
void anadirmulti(multi2<T>& d,const T& e){
    anadirRec(d.raiz,e);
    d.l++;
}

template<typename T> 
void quitarmulti(multi2<T>& d,const T& e,bool& b){
    quitarRec(d.raiz,e,b);
    if(b){
        d.l--;
    }
}


template<typename T> 
int multi2plicidadmulti(multi2<T>& d,const T& e){
    int auxi;
    multi2plicidadRec(d.raiz,e,auxi);
    return auxi;
}

template<typename T> 
int cardinalmulti(const multi2<T>& d){
    return d.l;
}




template<typename T> void iniciarIteradormulti(multi2<T>& d){
    typename multi2<T>::nodo* aux = new typename multi2<T>::nodo;
    vaciar(d.iter);
    aux=d.raiz;
    while(aux!=NULL){
        apilar(d.iter,aux);
        aux=aux->izq;
    }
}

template<typename T> bool existeSiguientemulti(const multi2<T>& d){
    return !estaVacia(d.iter);
}

template<typename T> void siguientemulti(multi2<T>& d, T& clave,int& valor,bool& error){
    typename multi2<T>::nodo* aux = new typename multi2<T>::nodo;
    if (existeSiguientemulti(d))
    {
        error = false;
        cima(d.iter,aux);
        desapilar(d.iter);
        clave=aux->clave;
        valor=aux->valor;
        aux=aux->der;
        while(aux!=NULL){
            apilar(d.iter,aux);
            aux=aux->izq;
        }
    }
    else{
        error = true;
    } 
}

#endif

