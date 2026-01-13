#include "productos.hpp"

void crear(string nombre, int cantidad, producto& p){
    p.nombre=nombre;
    p.cantidad=cantidad;
}

/* Dado un contacto c, devuelve la cadena correspondiente al nombre de c. 
*/
string nombre(const producto& p){
    return p.nombre;
}
/* Dado un contacto c, devuelve el entero correspondiente al telefono de c. 
*/
int cantidad(const producto& p){
    return p.cantidad;
}

/* Devuelve verdad si y sólo si los contactos c1 y c2 tienen el mismo nombre. 
*/
bool operator==(const producto& p1, const producto& p2){
    return p1.nombre==p2.nombre;
}