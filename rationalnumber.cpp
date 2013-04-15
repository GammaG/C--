#include "rationalnumber.h"

/**
 * @author Marco Seidler
 *  Quelldatei welche die gesamte Funktionalität der Berechnungen beeinhaltet.
 *  Hier werden die Funktionen compiliert.
 *  @date 10.04.13
 *
 */


/**
 * Methode Prüft ob eine übergebene RationalNumber gültig ist, der Denominator nicht 0 ist.
 * @brief rnIsValid
 * @param n
 * @return
 */
bool rnIsValid(RationalNumber n){
    if(n.denominator == 0 ){
        return false;
    }

   return true;
}


/**
 * Methode überprüft, ob zwei übergebene RationalNumber gleich sind.
 * @brief rnEqual
 * @param a
 * @param b
 * @return true oder false
 */
bool rnEqual(RationalNumber a, RationalNumber b){

    int min_a = euclid(a.numerator, a.denominator);
    int min_b = euclid(b.numerator, b.denominator);

    RationalNumber i = {(a.numerator/min_a),(a.denominator/min_a)};
    RationalNumber j = {(b.numerator/min_b),(b.denominator/min_b)};


    if((i.numerator==j.numerator)
            &&(i.denominator==j.denominator)){
        return true;
    }

    return false;
 }


/**
 * Überprüft für zwei übergebene RationalNumbers, welcher für beide kleiner ist.
 * @brief rnLessThan
 * @param a
 * @param b
 * @return
 */
bool rnLessThan(RationalNumber a, RationalNumber b){

    int min_a = euclid(a.numerator, a.denominator);
    int min_b = euclid(b.numerator, b.denominator);

    RationalNumber i = {(a.numerator/min_a),(a.denominator/min_a)};
    RationalNumber j = {(b.numerator/min_b),(b.denominator/min_b)};


    if((i.denominator < j.denominator)){
        return true;
    }

    return false;
 }

/**
 * Addiert zu übergebenen RationaNumber a, die übergebene RationalNumber b und returnd
 * das Ergebniss.
 * @brief rnAdd
 * @param a
 * @param b
 * @return
 */
RationalNumber rnAdd(RationalNumber a, RationalNumber b){

    int y = a.denominator*b.denominator;

    int x = ((a.numerator*b.denominator)+(b.numerator*a.denominator));

    int min = euclid(x,y);

return RationalNumber{(x/min),(y/min)};

}

/**
 * Subtract zu übergebenen RationaNumber a, die übergebene RationalNumber b und returnd
 * das Ergebniss.
 * @brief rnSubtract
 * @param a
 * @param b
 * @return
 */
RationalNumber rnSubtract(RationalNumber a, RationalNumber b){


    int y = a.denominator*b.denominator;

    int x = ((a.numerator*b.denominator)-(b.numerator*a.denominator));

    int min = euclid(x,y);

return RationalNumber{(x/min),(y/min)};

}

/**
 * Multipliziert zu übergebenen RationaNumber a, die übergebene RationalNumber b und returnd
 * das Ergebniss.
 * @brief rnMultiply
 * @param a
 * @param b
 * @return
 */
RationalNumber rnMultiply(RationalNumber a, RationalNumber b){

    int y = a.denominator*b.denominator;

    int x = a.numerator*b.numerator;

    int min = euclid(x,y);

return RationalNumber{(x/min),(y/min)};


}

/**
 * Dividiert zu übergebenen RationaNumber a, die übergebene RationalNumber b und returnd
 * das Ergebniss.
 * @brief rnDivide
 * @param a
 * @param b
 * @return
 */
RationalNumber rnDivide(RationalNumber a, RationalNumber b){


    int x = a.numerator*b.denominator;

    int y = a.denominator*b.numerator;

    int min = euclid(x,y);

return RationalNumber{(x/min),(y/min)};

}

/**
 * Algorithmus von Euclid. Ermittelt den kleinsten gemeinsamen Teiler und returnd ihn.
 * @brief euclid
 * @param a
 * @param b
 * @return
 */
int euclid(int a, int b){
    if (b == 0){
        return a;
    }
    return euclid(b, a%b);
}
