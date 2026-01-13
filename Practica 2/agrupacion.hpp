/* Nombre, apellidos y NIP del (de los) autor(es).
*/

#ifndef AGRUPACION_HPP
#define AGRUPACION_HPP

// PREDECLARACIÓN DEL TAD GENÉRICO agrupacion

const int MAX = 40;

/* COMPLETAR CON LA ESPECIFICACIÓN DEL DOMINIO DE VALORES DEL TAD agrupacion
   Y CON LAS CONDICIONES QUE SE LE EXIGEN AL PARÁMETRO DE TIPO T.
*/
template<typename T> struct agrupacion;


/* COMPLETAR LA ESPECIFICACIÓN DE CADA OPERACIÓN DEL TAD
*/
template<typename T> void iniciar(agrupacion<T>& a);

/* ...
*/
template<typename T> void anyadir(agrupacion<T>& a, const T& e);

/* ...
*/
template<typename T> bool vacia(const agrupacion<T>& a);

/* ...
*/
template<typename T> bool borrarUltimo(agrupacion<T>& a);

/* ...
*/
template<typename T> bool esta(const agrupacion<T>& a, const T& e);

//COMPLETAR OPERACIONES ITERADOR
/* ...
*/
template<typename T> void iniciarIterador(agrupacion<T>& a);

/* ...
*/
template<typename T> bool existeSiguiente(const agrupacion<T>& a);

/* ...
*/
template<typename T> void siguiente(agrupacion<T>& a, T& e, bool& error);


// DECLARACIÓN DEL TAD GENÉRICO agrupacion

template<typename T>
struct agrupacion{
    friend void iniciar<T>(agrupacion<T>& a);
    friend void anyadir<T>(agrupacion<T>& a, const T& e);
    friend bool vacia<T>(const agrupacion<T>& a);
    friend bool borrarUltimo<T>(agrupacion<T>& a);
    friend bool esta<T>(const agrupacion<T>& a, const T& e);
    friend void iniciarIterador<T>(agrupacion<T>& a);
    friend bool existeSiguiente<T>(const agrupacion<T>& a);
    friend void siguiente<T>(agrupacion<T>& a, T& e, bool& error);
    //COMPLETAR OPERACIONES ITERADOR
    //....
  private: 
     //campos
     T datos[MAX];
     int total;
    //COMPLETAR CAMPOS ITERADOR
     int totalI;
};


// IMPLEMENTACIÓN DE LAS OPERACIONES DEL TAD GENÉRICO agrupacion

template<typename T>
void iniciar(agrupacion<T>& a) {
    a.total=0;
}

template<typename T>
void anyadir(agrupacion<T>& a, const T& e) {
    a.datos[a.total]=e;
    a.total++;
}

template<typename T>
bool vacia(const agrupacion<T>& a) {
    return a.total==0;
}
	
template<typename T>
bool borrarUltimo(agrupacion<T>& a) {
    bool empty = vacia(a);
    if (!empty)
    {
        a.total--;   
    }
    return empty;
    
}

template<typename T>
bool esta(const agrupacion<T>& a, const T& e) {
    int i = 0;
    bool estaE = false;
    while (i<a.total && !estaE)
    {
        if(a.datos[i]==e){
            estaE = true;
        }
        else{
            i++;
        }
    }
    return estaE;
}

//COMPLETAR IMPLEMENTACION OPERACIONES ITERADOR


template<typename T> void iniciarIterador(agrupacion<T>& a){
    a.totalI = 0;
}


template<typename T> bool existeSiguiente(const agrupacion<T>& a){
    return a.totalI<a.total;
}


template<typename T> void siguiente(agrupacion<T>& a, T& e, bool& error){
    error = existeSiguiente(a);
    if (error)
    {
        e=a.datos[a.totalI];
        a.totalI++;
    }
    
}

#endif //fin de agrupacion.hpp

