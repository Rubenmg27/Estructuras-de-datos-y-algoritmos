#ifndef MULTI_HPP
#define MULTI_HPP

// PREDECLARACIÓN DEL TAD GENÉRICO multi


/* COMPLETAR CON LA ESPECIFICACIÓN DEL DOMINIO DE VALORES DEL TAD multi
   Y CON LAS CONDICIONES QUE SE LE EXIGEN AL PARÁMETRO DE TIPO T.
*/
template<typename T> struct multi;


/* COMPLETAR LA ESPECIFICACIÓN DE CADA OPERACIÓN DEL TAD
*/
template<typename T> void vacio(multi<T>& m);
template<typename T> void anadir(multi<T> m, const T& e);
template<typename T> void quitar(multi<T> m,const T& e,bool& b);
template<typename T> int multiplicidad(const multi<T> m,cont T& e);
template<typename T> int cardinal(const multi<T>& m);
template<typename T> void mostrar(const multi<T>& m);
template<typename T> void iniciarIterador(multi<T>& m);
template<typename T> bool existeSiguiente(const multi<T>& m);
template<typename T> void siguientep(multi<T>& m, T& e, bool& error);

//COMPLETAR OPERACIONES ITERADOR
//....


// DECLARACIÓN DEL TAD GENÉRICO multi

template<typename T>
struct multi{
    friend void vacio<T>(multi<T> m);
    friend bool anadir<T>(multi<T> m, const T& e);
    friend bool quitar<T>(const multi<T> m,const T& e,bool& b);
    friend int multiplicidad<T>(const multi<T> m,const T& e);
    friend int cardinal<T>(const multi<T>& m);
    friend void mostrar(const multi<T>& m);
    //COMPLETAR OPERACIONES ITERADOR
    friend void iniciarIterador<T>(multi<T>& m);
    friend bool existeSiguiente<T>(const multi<T>& m);
    friend void siguiente<T>(multi<T>& m, T& e, bool& error);

  private: 
    struct unaCelda{
        T clave;
        int valor;
        unaCelda* sig;
    }
    unaCelda* pri;
    int l;
    unaCelda* iter;

};


// IMPLEMENTACIÓN DE LAS OPERACIONES DEL TAD GENÉRICO multi

template<typename T> 
void vacio(multi<T>& m){
    m.l=0;
    m.pri=nullptr;
}

template<typename T> 
void anadir(multi<T> m, const T& e){
    typename multi<T>::unaCelda* aux;
    if(m.pri==nullptr){
        m.pri=new typename multi<T>::unaCelda;
        m.pri->clave=e;
        m.pri->valor=1;
        m.pri->sig=nillptr;
        m.l++;
    }
    else{ 
        if(e<(m.pri->clave)){
            aux=m.pri;
            m.pri=new typename multi<T>::unaCelda;
            m.pri->clave=e;
            m.pri->valor=1;
            m.pri->sig=aux;
            m.l++;
        }
        else{
            if(e==(m.pri->clave)){
                m.pri->valor++;
            }
            else{
                aux=m.pri;
                while((aux->sig!=nillptr) && (aux->sig->clave)<e){
                    aux=aux->sig;
                }
                if((aux->sig!=nillptr) && (e=(aux->sig->clave))){
                    aux->sig->valor++;
                }
                else{
                    typename multi<T>::unaCelda* nuevo=new typename multi<T>::unaCelda;
                    nuevo->clave=e;
                    nuevo->valor=1;
                    nuevo->sig=aux->sig;
                    aux->sig=nuevo;
                    m.l++;
                }
            }
        }
    }
}

template<typename T> 
void quitar(multi<T> m,const T& e,bool& b){
    typename multi<T>::elemento* aux1 = new typename multi<T>::elemento;
    typename multi<T>::elemento* aux2 = new typename multi<T>::elemento;
    bool parar;
    if (cardinal(m)!=0)
    {
        b=true;
        if (m.pri->clave <= e)
        {
            if (m.pri->clave==e)
            {
                m.pri->multiplicidad--;
                if (m.pri->multiplicidad==0)
                {
                    aux1=m.pri;
                    m.pri=m.pri->sig;
                    delete(m.pri);
                    m.l--;
                }
                
            }
            else{
                parar=false;
                aux1=m.pri->sig;
                aux2=m.pri;
                while (aux1!=nullptr && !parar)
                {
                    if(e<aux1->clave){
                        parar=true;
                    }
                    else if (e==aux1->clave)
                    {
                        aux1->multiplicidad--;
                        if (aux1->multiplicidad==0)
                        {
                            aux2->sig=aux1->sig;
                            delete(aux1);
                            m.l--;
                        }
                        parar=true;

                    }
                    else{
                        aux2=aux1;
                        aux1=aux1->sig;
                    }
                    
                }
                
            }
            
        }
        
    }
    else{
        b=false;   
    }
}

template<typename T> 
int multiplicidad(const multi<T> m,const T& e){
    typename multi<T>::elemento* aux1 = new typename multi<T>::elemento;
    typename multi<T>::elemento* aux2 = new typename multi<T>::elemento;
    bool parar;
    if (cardinal(m)!=0)
    {
        if (m.pri->clave <= e)
        {
            if (m.pri->clave==e)
            {
                return m.pri->multiplicidad;
            }
            else{
                parar=false;
                aux1=m.pri->sig;
                aux2=m.pri;
                while (aux1!=nullptr && !parar)
                {
                    if(e<aux1->clave){
                        parar=true;
                    }
                    else if (e==aux1->clave)
                    {
                        return multiplicidad;
                        parar=true;
                    }
                    else{
                        aux2=aux1;
                        aux1=aux1->sig;
                    }
                    
                }
                
            }
            
        }
        
    }
}

template<typename T> 
int cardinal(const multi<T>& m){
    return m.l;
}

template<typename T> 
void mostrar(const multi<T>& m){
    typename multi<T>::unaCelda* aux;
    aux=m.pri;
    while(aux!=nillptr){
        cout<<aux->clave<<" "<<aux->valor<<endl;
        aux=aux->sig;
    }   
}