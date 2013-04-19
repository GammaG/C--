/*
   Simple Unit Test for type RationalNumber
*/

#include <stdio.h>
#include <assert.h>

#include "rationalnumber.h"
#include "rationalnumbercollection.h"
#include "selectionsort.h"

using namespace std;

int main()
{

    printf("Performing unit tests for RationalNumber...\n");

    /* Part 1 - RationalNumber data type */
    RationalNumber  n1 = { 3, 4 },
                    n2 = { 6, 4 },
                    n3 = { 3, 2 },
                    n4 = { -9, -6 },
                    n5 = { 9, -6 },
                    n6 = { 9, 4 },
                    n0 = { 0, 4 },
                    nn = { 4, 0 };

    assert( rnIsValid(n0) );
    assert( !rnIsValid(nn) );

    assert( rnEqual( n2, n3) );
    assert( rnEqual( rnAdd(n1,n1), n2) );
    assert( rnEqual( n2,n4) );
    assert( !rnEqual( n4,n5) );
    assert( rnLessThan( n5,n3) );

    RationalNumber t1 = rnAdd(n1,n2);
    RationalNumber t2 = rnDivide(n3,n3);
    RationalNumber t3 = rnDivide(n2,n2);
    RationalNumber t4 = rnDivide(n6,n0);

    assert( rnEqual(t1, n6) );
    assert( rnEqual(t2, t3) );
    assert( !rnIsValid(t4) );

    printf("successful!\n");

    printf("from here on number 1.2\n");

    RationalNumberCollection c;
    rncInit(&c);
    RationalNumber n={1,2};
    rncAdd(&c, n);

    rncAdd(&c,n0);
    rncAdd(&c,n1);
    rncAdd(&c,n2);
    rncAdd(&c,n3);
    rncAdd(&c,n4);
    rncAdd(&c,n5);
    rncAdd(&c,n6);

    printf("hinzufuegen hat geklappt\n");

    RationalNumber sum = {13,2};

    assert( rnEqual(rncSum(&c),sum));
    assert( rncMatchNumber(rncTotalCount(&c), 8));
    assert( rncMatchNumber(rncTotalUniqueCount(&c), 6));
    assert( rncMatchNumber(rncCount(&c,n5),1));

    RationalNumber ava = {0,1};

    assert (rnEqual(rncAverage(&c),ava));

    printf("Vergleiche waren erfolgreich\n");

    return 0;
}

