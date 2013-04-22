#include "rationalnumbercollection.h"
#include "rationalnumber.h";

#include <stdlib.h>

/** Beinhaltet und deklariert alle im Header definierten Methoden der RationalNumberCollection
 */

int bin_search(RationalNumberCollection *c, RationalNumber n);
void sorting(RationalNumberCollection *c);

/**
 * @brief The Speichereinheit struct
 */
struct Speichereinheit{

    RationalNumber bruch;
    int anzahl;
};

/**
 * @brief The RationalNumberCollection struct
 */
struct RationalNumberCollection{
    Speichereinheit* liste;
    int anzahl;
    int unique;
    int arraySize;
    RationalNumber sum;
};

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

/** erzeugt die RationalNumberCollection gibt den Verweis zurueck,
 *  erstellt ein Array von der uebergebenen Groeße
 * @brief rncCreate
 * @param number
 * @return
 */
RationalNumberCollection* rncCreate(int number){

    RationalNumberCollection* rnc = (RationalNumberCollection*) malloc(sizeof(RationalNumberCollection));
    rnc->liste = (Speichereinheit*) malloc(sizeof(Speichereinheit)*number);
    rnc->arraySize = number;
    rncInit(rnc);
    return rnc;

}

/** Gibt den Speicher frei
 * @brief rncDelete
 * @param c
 */
void rncDelete(RationalNumberCollection* c){
    free(c->liste);
    free(c);
}

/** Vergroeßert das array
 * @brief addFieldToArray
 * @param c
 */
void addFieldToArray(RationalNumberCollection* c){
    Speichereinheit* listeTemp = (Speichereinheit*) malloc(sizeof(Speichereinheit)*(c->arraySize +10));

    for(int i= 0;i < c->arraySize; i++){
        listeTemp[i] = c->liste[i];
    }
    c->arraySize += 10;
    free(c->liste);
    c->liste = listeTemp;

}



/** Addiert einen Bruch in die Liste,
 * addiert ebenfalls sofort die summe und Sortiert die liste
 * @brief rncAdd
 * @param c
 * @param n
 */
void rncAdd(RationalNumberCollection *c,RationalNumber n){

  //  int i = findInList(c,n);
    int i = bin_search(c,n);
    if(i > -1){

        c->liste[i].anzahl++;

        }

    else {
        if(c->unique == c->arraySize){
            addFieldToArray(c);
        }
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

    //int i = findInList(c,n);
    int i = bin_search(c,n);
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

//int i = findInList(c,n);
    int i = bin_search(c,n);
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


/**
 * Sortiert eine Liste von Speichereinheiten gegeben in RationalNumberCollection nach der größe.
 * @brief sorting
 * @param c
 */

void sorting(RationalNumberCollection *c){


int posOfMinimum = -1;
RationalNumber x = {-999,-999};
Speichereinheit valueOfMinimum = {x,0};
int sortetUpToPos = 0;


for (int j = 0; j < c->unique; j++) {
            valueOfMinimum = c->liste[j];

            for (int i = sortetUpToPos; i < c->unique; i++) {

                Speichereinheit currentValue = c->liste[i];

                posOfMinimum = -1;
                if (rnLessThan(currentValue.bruch,valueOfMinimum.bruch)) {
                    posOfMinimum = i;
                    valueOfMinimum = currentValue;

                }
            }

            for (int i = posOfMinimum; i > sortetUpToPos; --i) {
                c->liste[i] = c->liste[i - 1];

            }

            c->liste[sortetUpToPos] = valueOfMinimum;
             ++sortetUpToPos;
        }
}


/**
 * Sucht mit binaerer Suche in einer Liste nach einer Ralationalzahl
 * gibt entweder -1 bei nicht gefunden, oder die Position im Array zurück.
 * @brief bin_search
 * @param c
 * @param n
 * @return
 */

int bin_search(RationalNumberCollection *c, RationalNumber n){

 int mitte;
 int links = 0;
 int rechts = c->unique -1;

if(c->unique == 0){
    return -1;
}

for(;;){

    mitte = ((rechts+links)/2); //bereich wird halbiert

    if(rechts < links){
        return -1;
    }

    // n gefunden ?
    if(rnEqual(c->liste[mitte].bruch,n)){
        return mitte;
    }

    if(rnLessThan(n,c->liste[mitte].bruch)){
        rechts = mitte-1;

    } else {

        links = mitte+1;
    }

}
    return -1;
}
