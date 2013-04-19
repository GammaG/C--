#include "rationalnumbercollection.h"
#include "rationalnumber.h";
#include "selectionsort.h"


/** Beinhaltet und deklariert alle im Header definierten Methoden der RationalNumberCollection
 */


/**
 * Initialisiert alle Attrubute und gibt ihnen einen Startwert
 * @brief rncInit
 * @param c
 */
void rncInit(RationalNumberCollection *c){
    c->anzahl=0;
    c->unique=0;
    c->sum.denominator=0;
    c->sum.numerator=0;

}

/** Addiert einen Bruch in die Liste,
 * addiert ebenfalls sofort die summe und Sortiert die liste
 * @brief rncAdd
 * @param c
 * @param n
 */
void rncAdd(RationalNumberCollection *c,RationalNumber n){

    int i = findInList(c,n);
    if(i > -1){

        c->liste[i].anzahl++;

        }

    else {
        c->liste[c->unique].bruch= n;
        c->liste[c->unique].anzahl += 1;
        c->unique++;
        sorting(c);
    }

    c->anzahl++;
    c->sum = rnAdd(c->sum,n);

}

/**
 *Gibt die Anzahl eines Bruches in der Liste zurück.
 * @brief rncCount
 * @param c
 * @param n
 * @return
 */
int rncCount(RationalNumberCollection *c, RationalNumber n){

    int i = findInList(c,n);
    if(i>-1){

            return c->liste[i].anzahl;


    }

    return 0;
}


/** Entfernt einen Bruch aus der Liste und aus der Summe
 * @brief rncRemove
 * @param c
 * @param n
 */
void rncRemove(RationalNumberCollection *c, RationalNumber n){

int i = findInList(c,n);
        if(i>-1){
            c->liste[i].anzahl--;
            c->anzahl--;
            if(c->liste[i].anzahl <= 0) {

                c->liste[i] = c->liste[c->unique];
                c->unique--;

        }
      c->sum = rnDivide(c->sum,n);
      sorting(c);
    }


}

/**
 *Überpruft ob ein Bruch schon in der Liste ist, und gibt die Position zurück
 * @brief findInList
 * @param c
 * @param n
 * @return
 */
int findInList(RationalNumberCollection *c, RationalNumber n){
    for(int i= 0; i < c->anzahl; i++){
        if(rnEqual(c->liste[i].bruch, n)){
            return i;
        }
    }
    return -1;
}

/** Gibt die Anzahl uniqer Brueche zurueck
 * @brief rncTotalUniqueCount
 * @param c
 * @return
 */

int rncTotalUniqueCount(RationalNumberCollection *c){
    return c->unique;
}

/** Gibt die Gesamtanzahl aller Brueche zurueck
 * @brief rncTotalCount
 * @param c
 * @return
 */
int rncTotalCount(RationalNumberCollection *c){
    return c->anzahl;
}

/** Gibt die aktuelle Summe aller brueche zurueck
 * @brief rncSum
 * @param c
 * @return
 */
RationalNumber rncSum(RationalNumberCollection *c){
    return c->sum;
}

/** Gibt den Durchschnitt aller aktuellen Brueche zurueck
 * @brief rncAverage
 * @param c
 * @return
 */
RationalNumber rncAverage(RationalNumberCollection *c){
    RationalNumber rat = {c->sum.denominator/c->anzahl,c->sum.numerator/c->anzahl};
    int min = euclid(rat.denominator,rat.numerator);

    int x = rat.numerator/min;
    int y = rat.denominator/min;

    RationalNumber nr = {x,y};

    return nr;
}

/** Ueberprueft zwei Zahlen auf Gleichheit
 * @brief rncMatchNumber
 * @param a
 * @param b
 * @return
 */
bool rncMatchNumber(int a, int b){

    if(a == b){ return true; }

    return false;

}
