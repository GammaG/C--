#ifndef RATIONALNUMBERCOLLECTION_H
#define RATIONALNUMBERCOLLECTION_H

#include "rationalnumber.h"


/**
 * Verwaltet eine liste von Speichereinheiten, sowie die anzahl aller und uniquer
 *Brueche, sowie die aktuelle summe
 *
 * @brief The RationalNumberCollection struct
 */
struct RationalNumberCollection;


/** Definierung aller methoden der RationalNumberCollection
 * @brief rncInit
 * @param c
 */


RationalNumberCollection* rncCreate(int number);
void rncInit(RationalNumberCollection *c);
void rncAdd(RationalNumberCollection *c,RationalNumber n);
int rncCount(RationalNumberCollection *c, RationalNumber n);
void rncRemove(RationalNumberCollection *c, RationalNumber n);
int findInList(RationalNumberCollection *c, RationalNumber n);
int rncTotalUniqueCount(RationalNumberCollection *c);
int rncTotalCount(RationalNumberCollection *c);
RationalNumber rncSum(RationalNumberCollection *c);
RationalNumber rncAverage(RationalNumberCollection *c);
bool rncMatchNumber(int a, int b);
void rncDelete(RationalNumberCollection* c);


#endif // RATIONALNUMBERCOLLECTION_H
