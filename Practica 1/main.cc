/* 
   Nombre: Sergio Salesa Quintanilla 
   NIP: 811019
*/

#include "contacto.h"
#include "agenda.h"


void mostrarDatos(agenda& a){
    contacto aux;
    bool error;
    iniciarIterador(a);
    siguiente(a,aux,error);
    while (!error)
    {
        cout << nombre(aux) << " " << direccion(aux) << " " << telefono(aux) << endl;
        siguiente(a,aux,error);
    } 
    cout << endl;
}

int main(){
    string nombres[10]={"Diego","Ruben","Juan","Pedro","Miguel","Aaron","Sergio","Jose","Victor","Pablo"};

    string direcciones[10]={"Zaragoza","Madrid","Bilbao","Barcelona","Andorra","Teruel","Huesca","Salamanca","Segovia","Murcia"};

    int telefonos[10]={678594556,679897847,776453413,677231223,699566758,756122334,712123423,682976779,652122578,645375657};

    contacto c[10];

    agenda a;

    iniciar(a);

    for(unsigned int i=0;i<10;i++){
        crear(nombres[i],direcciones[i],telefonos[i],c[i]);
        anyadir(a,c[i]);
    }

    mostrarDatos(a);

    borrarUltimo(a);

    mostrarDatos(a);

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
    return 0;
}