/*  
 * Autores: Rubén Martín González NIP:841886	
 *          Sergio Salesa Quintanilla NIP:811019 
 * Fecha: 7/1/2023
 * Comentario: Fichero cola.hpp del TAD genérico cola para su uso en el colaprio.hpp
 */
#ifndef COLA_HPP
#define COLA_HPP

// PREDECLARACIÓN DEL TAD GENÉRICO cola

template<typename T> struct cola;
template<typename T> void crearcolaVacia(cola<T>& c);
template<typename T> void encolarcola(cola<T>& c, const T& e,const int numero);
template<typename T> bool vaciacola(const cola<T>& c);
template<typename T> void primerocola(const cola<T>& c, T& e, bool& error);
template<typename T> void desencolarcola(cola<T>& c);
template<typename T> int longitudcola(const cola<T>& c);
template<typename T> void iniciarIteradorcola(cola<T>& c);
template<typename T> bool existeSiguientecola(const cola<T>& c);
template<typename T> void siguientecola(cola<T>& c, T& e,int& valor, bool& error);


// DECLARACIÓN DEL TAD GENÉRICO cola

template<typename T>
struct cola{
    friend void crearcolaVacia<T>(cola<T>& c);
    friend void encolarcola<T>(cola<T>& c, const T& e,const int numero);
    friend bool vaciacola<T>(const cola<T>& c);
    friend void primerocola<T>(const cola<T>& c, T& e, bool& error);
    friend void desencolarcola<T>(cola<T>& c);
    friend int longitudcola<T>(const cola<T>& c);
    friend void iniciarIteradorcola<T>(cola<T>& c);
    friend bool existeSiguientecola<T>(const cola<T>& c);
    friend void siguientecola<T>(cola<T>& c, T& e,int& valor, bool& error);

    private: 
     struct dato
     {
         T elemento;
         dato* sig;
         int valor;
     };

     dato* pri;
     dato* ult;
     int l;
     dato* iter;
};


// IMPLEMENTACIÓN DE LAS OPERACIONES DEL TAD GENÉRICO cola

template<typename T> void crearcolaVacia(cola<T>& c){
    c.l=0;
    c.pri = NULL;
    c.ult=c.pri;
}

template<typename T> void encolarcola(cola<T>& c, const T& e,const int numero){
    if (c.l==0)
    {
        c.ult = new typename cola<T>::dato;
        c.pri=c.ult;
    }
    else{
        c.ult->sig = new typename cola<T>::dato;
        c.ult=c.ult->sig;
    }
    c.ult->elemento=e;
    c.ult->valor=numero;
    c.ult->sig=NULL;
    c.l++;
}

template<typename T> bool vaciacola(const cola<T>& c){
    return c.pri==NULL;
}

template<typename T> void primerocola(const cola<T>& c, T& e, bool& error){
    if(vacia(c)){
        error=true;
    }
    else{
        error=false;
        e=c.pri->elemento;
    }
}

template<typename T> void desencolarcola(cola<T>& c){
    typename cola<T>::dato* aux = new typename cola<T>::dato;
    if (!vacia(c))
    {
        aux=c.pri;
        c.pri=c.pri->sig;
        delete(aux);
        c.l--;
        if (c.l==0)
        {
            c.ult=NULL;
        }
    }
}

template<typename T> int longitudcola(const cola<T>& c){
    return c.l;
}

template<typename T> void iniciarIteradorcola(cola<T>& c){
    c.iter=c.pri;
}

template<typename T> bool existeSiguientecola(const cola<T>& c){
    return c.iter!=NULL;
}

template<typename T> void siguientecola(cola<T>& c, T& e,int& valor, bool& error){
    if (existeSiguientecola(c))
    {
        error = false;
        e=c.iter->elemento;
        valor=c.iter->valor;
        c.iter=c.iter->sig;
    }
    else{
        error = true;
    }
    
}
#endif //fin de cola.hpp
