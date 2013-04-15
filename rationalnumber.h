#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

/**
 * @author Marco Seidler
 * @date 10.04.13
 * @brief The RationalNumber struct
 */
struct RationalNumber{
    int numerator;
    int denominator;

    };

/**
 * hier werden die Methoden deklariert
 * @brief rnIsValid
 * @param n
 * @return
 */

bool rnIsValid(RationalNumber n);
bool rnEqual(RationalNumber a, RationalNumber b);
bool rnLessThan(RationalNumber a, RationalNumber b);
RationalNumber rnAdd(RationalNumber a, RationalNumber b);
RationalNumber rnSubtract(RationalNumber a, RationalNumber b);
RationalNumber rnMultiply(RationalNumber a, RationalNumber b);
RationalNumber rnDivide(RationalNumber a, RationalNumber b);
int euclid(int a, int b);



#endif // RATIONALNUMBER_H
