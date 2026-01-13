/* 
   Nombre: Sergio Salesa Quintanilla 
   NIP: 811019
*/

#include "contacto.h"
#include "productos.hpp"
#include "agrupacion.hpp"


void mostrarContactos(agrupacion<contacto>& a){
    contacto aux;
    bool error;
    iniciarIterador(a);
    siguiente(a,aux,error);
    while (error)
    {
        cout << nombre(aux) << " " << direccion(aux) << " " << telefono(aux) << endl;
        siguiente(a,aux,error);
    } 
    cout << endl;
}

void mostrarProductos(agrupacion<producto>& a){
    producto aux;
    bool error;
    iniciarIterador(a);
    siguiente(a,aux,error);
    while (error)
    {
        cout << nombre(aux) << " " << cantidad(aux) << endl;
        siguiente(a,aux,error);
    } 
    cout << endl;
}

int main(){
    string nombres[10]={"Diego","Ruben","Juan","Pedro","Miguel","Aaron","Sergio","Jose","Victor","Pablo"};

    string direcciones[10]={"Zaragoza","Madrid","Bilbao","Barcelona","Andorra","Teruel","Huesca","Salamanca","Segovia","Murcia"};

    int telefonos[10]={678594556,679897847,776453413,677231223,699566758,756122334,712123423,682976779,652122578,645375657};

    string nom[10]={"Manzana","Coche"};

    int cantidad[10]={10,12};
    contacto c[10];
    producto p[10];

    agrupacion<contacto> a;
    agrupacion<producto> a1;
    iniciar(a);
    iniciar(a1);
    for(unsigned int i=0;i<10;i++){
        crear(nombres[i],direcciones[i],telefonos[i],c[i]);
        anyadir(a,c[i]);
    }
    for(unsigned int i=0;i<2;i++){
        crear(nom[i],cantidad[i],p[i]);
        anyadir(a1,p[i]);
    }
    mostrarContactos(a);

    borrarUltimo(a);

    mostrarContactos(a);

    string nombrex;
    contacto s;
    cout << "Dame el nombre del contacto a buscar" << endl;
    cin >> nombrex;
    crear(nombrex, " ",0,s);
    if (esta(a,s))
    {
        cout << "Encontrado" << endl;
    }
    else{
        cout << "No encontrado" << endl;
    }

    mostrarProductos(a1);

    borrarUltimo(a1);

    mostrarProductos(a1);

    producto s1;
    cout << "Dame el nombre del producto a buscar" << endl;
    cin >> nombrex;
    crear(nombrex, 0,s1);
    if (esta(a1,s1))
    {
        cout << "Encontrado" << endl;
    }
    else{
        cout << "No encontrado" << endl;
    }
    return 0;
}