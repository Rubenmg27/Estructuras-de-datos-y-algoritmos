/* 
   Nombre: Sergio Salesa Quintanilla 
   NIP: 811019
*/

#ifndef PRODUCTO_H    
#define PRODUCTO_H  //evitar compilar compila varias veces contactos con esto solo lo hará una vez

#include<iostream>
using namespace std;

// PREDECLARACIÓN DEL TAD contacto

/* Los valores del TAD contacto representan información de personas,
a las que llamamos contactos, para las que se tiene 
información de su nombre, su dirección y su número de teléfono.
Dos contactos se consideran iguales (con el operador ==) si tienen el mismo nombre.
*/
struct producto;

/* Dada una cadena nombre, una cadena direccion y un entero telefono, 
devuelve un contacto c con esos datos. 
*/
void crear(string nombre, int cantidad, producto& p);

/* Dado un contacto c, devuelve la cadena correspondiente al nombre de c. 
*/
string nombre(const producto& p); //no se puede modificar c, usar para datos voluminosos

/* Dado un contacto c, devuelve el entero correspondiente al telefono de c. 
*/
int cantidad(const producto& p);

/* Devuelve verdad si y sólo si los contactos c1 y c2 tienen el mismo nombre. 
*/
bool operator==(const producto& p1, const producto& p2);

// DECLARACIÓN DEL TAD contacto

struct producto {
  friend void crear(string nombre, int cantidad, producto& p);
  friend string nombre(const producto& p);
  friend int cantidad(const producto& p);
  friend bool operator==(const producto& p1, const producto& p2);
  private:
   string nombre;
   int cantidad;
};

#endif
