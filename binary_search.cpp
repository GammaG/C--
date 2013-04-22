#include "binary_search.h"
#include "rationalnumbercollection.h"
#include "rationalnumber.h"

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
