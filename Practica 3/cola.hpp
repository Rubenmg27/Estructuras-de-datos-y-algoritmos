#ifndef COLA_HPP
#define COLA_HPP

/* COMPLETAR CON LA ESPECIFICACIÓN DEL DOMINIO DE VALORES DEL TAD agrupacion
   Y CON LAS CONDICIONES QUE SE LE EXIGEN AL PARÁMETRO DE TIPO T.
*/
template<typename T> struct cola;


/* COMPLETAR LA ESPECIFICACIÓN DE CADA OPERACIÓN DEL TAD
*/
template<typename T> void crearVacia(cola<T>& c);
template<typename T> void encolar(cola<T>& c, const T& e);
template<typename T> bool vacia(const cola<T>& c);
template<typename T> void primero(const cola<T>& c, T& e, bool& error);
template<typename T> void desencolar(cola<T>& c);
template<typename T> int longitud(const cola<T>& c);
template<typename T> void iniciarIterador(cola<T>& c);
template<typename T> bool existeSiguiente(const cola<T>& c);
template<typename T> void siguiente(cola<T>& c, T& e, bool& error);


// DECLARACIÓN DEL TAD GENÉRICO agrupacion

template<typename T>
struct cola{
    friend void crearVacia<T>(cola<T>& c);
    friend void encolar<T>(cola<T>& c, const T& e);
    friend bool vacia<T>(const cola<T>& c);
    friend void primero<T>(const cola<T>& c, T& e, bool& error);
    friend void desencolar<T>(cola<T>& c);
    friend int longitud<T>(const cola<T>& c);
    friend void iniciarIterador<T>(cola<T>& c);
    friend bool existeSiguiente<T>(const cola<T>& c);
    friend void siguiente<T>(cola<T>& c, T& e, bool& error);

    private: 
     struct dato
     {
         T elemento;
         dato* sig;
     };

     dato* pri;
     dato* ult;
     int l;
     dato* iter;
};


// IMPLEMENTACIÓN DE LAS OPERACIONES DEL TAD GENÉRICO agrupacion

template<typename T> void crearVacia(cola<T>& c){
    c.l=0;
    c.pri = nullptr;
    c.ult=c.pri;
}

template<typename T> void encolar(cola<T>& c, const T& e){
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
    c.ult->sig=nullptr;
    c.l++;
}

template<typename T> bool vacia(const cola<T>& c){
    return c.pri==nullptr;
}

template<typename T> void primero(const cola<T>& c, T& e, bool& error){
    if(vacia(c)){
        error=true;
    }
    else{
        error=false;
        e=c.pri->elemento;
    }
}

template<typename T> void desencolar(cola<T>& c){
    typename cola<T>::dato* aux = new typename cola<T>::dato;
    if (!vacia(c))
    {
        aux=c.pri;
        c.pri=c.pri->sig;
        delete(aux);
        c.l--;
        if (c.l==0)
        {
            c.ult=nullptr;
        }
    }
}

template<typename T> int longitud(const cola<T>& c){
    return c.l;
}

template<typename T> void iniciarIterador(cola<T>& c){
    c.iter=c.pri;
}

template<typename T> bool existeSiguiente(const cola<T>& c){
    return c.iter->sig!=nullptr;
}

template<typename T> void siguiente(cola<T>& c, T& e, bool& error){
    if (existeSiguiente(c))
    {
        error = false;
        e=c.iter->elemento;
        c.iter=c.iter->sig;
    }
    else{
        error = true;
    }
    
}
#endif //fin de cola.hpp
