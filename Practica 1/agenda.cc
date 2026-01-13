/* 
   Nombre: Sergio Salesa Quintanilla 
   NIP: 811019
*/

#include "agenda.h"

/* Devuelve una agenda vacía en a, sin contactos.
*/
void iniciar(agenda& a){
    a.total=0;
}

/* Si la agenda a no está llena (numero de contactos almacenados menor que MAX),
   la función devuelve verdad y añade el contacto c a la agenda a.
   Si la agenda está llena, la función devuelve falso y la agenda a no se modifica.
*/
bool anyadir(agenda& a, const contacto c){
    if (a.total<MAX)
    {
        a.datos[a.total]=c;
        a.total++;
        return true;
    }
    else{
        return false;
    }
    
}

/* Devuelve verdad si y sólo si la agenda a está vacía. 
*/
bool vacia(const agenda& a){
    return a.total==0;
}

/* Si a no está vacía, la función devuelve verdad y de la agenda a se elimina el último contacto 
   añadido a ella. Si a está vacía, la función devuelve falso y la agenda no se modifica.
*/
bool borrarUltimo(agenda& a){
    if (!vacia(a))
    {
        a.total--;
        return true;
    }
    else{
        return false;
    }   
}

/* Dada una agenda a y un contacto c, devuelve verdad si y sólo si en 
   a hay algún contacto igual a c (en el sentido de la función == del TAD contacto), 
   falso en caso contrario.
 */
bool esta(const agenda& a, const contacto& c){
    bool encontrado = false;
    int i = 0;
    while (!encontrado && i<MAX)
    {
        if (c==a.datos[i])
        {
            encontrado=true;
        }
        else{
            i++;
        }
        
    }
    return encontrado;
}

/* Dada una agenda a, se prepara el iterador para que el siguiente contacto a visitar
   sea el primer contacto de la agenda
 */

void iniciarIterador(agenda& a){
    a.totali=0;
}

/* Dada una agenda a, devuelve false si se han visitado todos los contactos de esta.
   Verdadero en caso contrario.
 */

bool existeSiguiente(const agenda& a){
    return a.totali<a.total;
}

/* Si existeSiguiente(a) es verdadero, siguiente devolverá el contacto en el que está
   y avanzará al siguiente contacto de la agenda y pondrá en bool error a false. 
   Si es falso no devolverá nada, no avanzará la agenda y contra en bool error a true.
 */

void siguiente(agenda& a, contacto& c, bool& error){
    if (existeSiguiente(a))
    {
        c=a.datos[a.totali];
        a.totali++;
        error=false;
    }
    else{
        error=true;
    }
    
}