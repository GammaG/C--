#include "selectionsort.h"
#include "rationalnumbercollection.h"
#include "rationalnumber.h"

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
