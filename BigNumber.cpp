// Including BigNumber library on project file
#include "BigNumber.h"
#include <iostream>

using namespace std;

int main()
{

/*********************************************************************************************************/

    /**
        Instantiating class object
        @param 1: string with a numeric value
    */

    BigNumber big("5");
    cout << big << endl;

    /** Output
        5
    */


/*********************************************************************************************************/

    /**
        method abs()
        @return BigNumber with absolute value of (this)
    */

    BigNumber bigAbs("-155");
    cout << bigAbs.abs() << endl;

    /** Output
        155
    */


/*********************************************************************************************************/

    /**
        method add(BigNumber val)
        @return BigNumber with the sum of (this + val)
    */

    BigNumber bigAdd1("982556172");
    BigNumber bigAdd2("2132221");
    cout << bigAdd1.add(bigAdd2) << endl;

    /** Output
        984688393
    */


/*********************************************************************************************************/

    /**
        method compare(BigNumber val)
        @return BigNumber with the comparison between (this and val)
    */

    BigNumber bigCompare("5");
    cout << bigCompare.compare(BigNumber("4")) << " " << bigCompare.compare(BigNumber("5")) << " " << bigCompare.compare(BigNumber("6")) << endl;

    /** Output
        -1 0 1
    */


/*********************************************************************************************************/

    /**
        method factorial()
        @return BigNumber as result of (BigNumber val!)
    */

    BigNumber bigFactorial("25");
    cout << bigFactorial.factorial() << endl;

    /** Output
        15511210043330985984000000
    */


/*********************************************************************************************************/

    /**
        method fibonacci()
        @return BigNumber as result of the fibonacci of val
    */

    BigNumber bigFib("60");
    cout << bigFib.fibonacci() << endl;

    /** Output
        1548008755920
    */


/*********************************************************************************************************/

    /**
        method multiply(BigNumber val)
        @return BigNumber with the multiplication of (this + val)
    */

    BigNumber bigMultiply1("992761");
    BigNumber bigMultiply2("55231");
    cout << bigMultiply1.multiply(bigMultiply2) << endl;

    /** Output
        54831182791
    */


/*********************************************************************************************************/

    /**
        method power(BigNumber pow)
        @return a BigNumber with the value of (this ^ pow)
    */

    BigNumber bigPow("2");
    cout << bigPow.power(BigNumber("10")) << endl;

    /** Output
        1
    */


/*********************************************************************************************************/

    /**
        method bitAnd(BigNumber val)
        Method to return bitwise between BigNumber's.
        @return a BigNumber with a integer value
    */

    BigNumber bigAnd("12");
    cout << bigAnd.bitAnd(BigNumber("8")) << " as bitwise" << endl;

    /** Output
        0 as bitwise
    */


/*********************************************************************************************************/

    /**
        method maximum(BigNumber val)
        Method to return the max value of two BigNumber's.
        @return a BigNumber
    */

    BigNumber bigMax("131283");
    cout << bigMax.maximum(BigNumber("812378123")) << endl;

    /** Output
        812378123
    */


/*********************************************************************************************************/

    /**
        method minimum(BigNumber val)
        Method to return the min value of two BigNumber's.
        @return a BigNumber
    */

    BigNumber bigMin("131283");
    cout << bigMax.minimum(BigNumber("812378123")) << endl;

    /** Output
        131283
    */


/*********************************************************************************************************/

    /**
        method signum()
        @return a int, -1 if the value is negative, 0 if is null or 1 if is positive
    */

    BigNumber bigSign("3");
    cout << bigSign.signum() << endl;

    /** Output
        1
    */


/*********************************************************************************************************/

    /**
        method size()
        @return the size of the BigNumber
    */

    BigNumber bigSize("532133213");
    cout << bigSize.size() << endl;

    /** Output
        9
    */


/*********************************************************************************************************/

    /**
        method subtract(BigNumber Sub)
        @return BigNumber with the value of (this - Big)
    */

    BigNumber bigSub1("882");
    BigNumber bigSub2("542");
    cout << bigSub1.subtract(bigSub2) << endl;

    /** Output
        340
    */


/*********************************************************************************************************/

    /**
        method toDouble()
        @return double value of BigNumber
    */

    BigNumber bigDouble("45.12");
    cout << bigDouble << " (BigNumber) = " << bigDouble.toDouble() << " (double)" << endl;

    /** Output
        45.12 (BigNumber) = 45.12 (double)
    */


/*********************************************************************************************************/

    /**
        method toInt()
        @return integer value of BigNumber
    */

    BigNumber bigInt("12452");
    cout << bigInt << " (BigNumber) = " << bigInt.toInt() << " (integer)" << endl;

    /** Output
        12452 (BigNumber) = 12452 (integer)
    */


/*********************************************************************************************************/

    /**
        method toLong()
        @return long value of BigNumber
    */

    BigNumber bigLong("2147483647");
    cout << bigLong << " (BigNumber) = " << bigLong.toLong() << " (long)" << endl;

    /** Output
        2147483647 (BigNumber) = 2147483647 (long)
    */


/*********************************************************************************************************/

    /**
        method toLongLong()
        @return long long value of BigNumber
    */

    BigNumber bigLongLong("9223372036854775807");
    cout << bigLongLong << " (BigNumber) = " << bigLongLong.toLongLong() << " (long long)" << endl;

    /** Output
        9223372036854775807 (BigNumber) = 9223372036854775807 (long long)
    */


/*********************************************************************************************************/

    /**
        method toString()
        @return a string with the value of BigNumber
    */

    BigNumber bitString("92233720368547758071299285671627367261732");
    cout << bitString << " (BigNumber) = " << bitString.toString() << " (string)" << endl;

    /** Output
        92233720368547758071299285671627367261732 (BigNumber) = 92233720368547758071299285671627367261732 (string)
    */


/*********************************************************************************************************/

    /**
        method valueOf(int val)
        This method is static, it can be called without a class object.
        @return a BigNumber with a integer value
    */

    BigNumber bigInteger = BigNumber::valueOf(15);
    cout << bigInteger << " (as BigNumber)" << endl;

    /** Output
        15 (as BigNumber)
    */




    return 0;
}
