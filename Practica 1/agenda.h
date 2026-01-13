/* 
   Nombre: Sergio Salesa Quintanilla 
   NIP: 811019
*/

#ifndef AGENDA_H
#define AGENDA_H

#include "contacto.h"

// PREDECLARACIÓN DEL TAD agenda

const int MAX = 40;

/* Los valores del TAD agenda representan colecciones de contactos a las 
   que se pueden añadir elementos de tipo contacto, y de las que se pueden eliminar 
   sus contactos de uno en uno, eliminándose siempre el último contacto añadido de 
   todos los que contenga la agenda.
   Dado que la implementación es estática, se impone una máxima capacidad de la
   agenda igual al valor de la constante MAX.
 */
struct agenda;

/* Devuelve una agenda vacía en a, sin contactos.
*/
void iniciar(agenda& a);

/* Si la agenda a no está llena (numero de contactos almacenados menor que MAX),
   la función devuelve verdad y añade el contacto c a la agenda a.
   Si la agenda está llena, la función devuelve falso y la agenda a no se modifica.
*/
bool anyadir(agenda& a, const contacto c);

/* Devuelve verdad si y sólo si la agenda a está vacía. 
*/
bool vacia(const agenda& a);

/* Si a no está vacía, la función devuelve verdad y de la agenda a se elimina el último contacto 
   añadido a ella. Si a está vacía, la función devuelve falso y la agenda no se modifica.
*/
bool borrarUltimo(agenda& a);

/* Dada una agenda a y un contacto c, devuelve verdad si y sólo si en 
   a hay algún contacto igual a c (en el sentido de la función == del TAD contacto), 
   falso en caso contrario.
 */
bool esta(const agenda& a, const contacto& c);

/* Dada una agenda a, se prepara el iterador para que el siguiente contacto a visitar
   sea el primer contacto de la agenda
 */

void iniciarIterador(agenda& a);

/* Dada una agenda a, devuelve false si se han visitado todos los contactos de esta.
   Verdadero en caso contrario.
 */

bool existeSiguiente(const agenda& a);

/* Si existeSiguiente(a) es verdadero, siguiente devolverá el contacto en el que está
   y avanzará al siguiente contacto de la agenda y pondrá en bool error a false. 
   Si es falso no devolverá nada, no avanzará la agenda y contra en bool error a true.
 */

void siguiente(agenda& a, contacto& c, bool& error);


// DECLARACIÓN DEL TAD agenda

struct agenda{
    friend void iniciar(agenda& a);
    friend bool anyadir(agenda& a, const contacto c);
	 friend bool vacia(const agenda& a);
    friend bool borrarUltimo(agenda& a);
  	 friend bool esta(const agenda& a, const contacto& c);
    friend void iniciarIterador(agenda& a);
    friend bool existeSiguiente(const agenda& a);
    friend void siguiente(agenda& a, contacto& c, bool& error);
   private: 
     //campos
     contacto datos[MAX];
     int total;
     int totali;
};

#endif //fin de agenda.h

