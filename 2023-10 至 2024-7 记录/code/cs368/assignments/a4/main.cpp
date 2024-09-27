///////////////////////////////////////////////////////////////////////////////
// File Name:      main.cpp
//
// Author:         Gerald
// CS email:       gerald@cs.wisc.edu
//
// Description:    The main program for a4.
//
// IMPORTANT NOTE: This file should NOT be modified.
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <complex>
#include <vector>

#include "Matrix.hpp"

/**
 * @brief The program execution begins here.
 * @return 0 for normal program termination.
 */
int main() {
    // PART 1 - MATRIX OF INTEGERS.

    // create a matrix and check its dimensions.
    Matrix<int> a(2, 4);
    std::cout << "Matrix a has " << a.getRows() << " rows and " 
              << a.getCols() << " columns" << std::endl << std::endl;

    // create a 2 x 2 matrix of integers.
    Matrix<int> m(2, 2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;
    std::cout << "Matrix m:" << std::endl;
    std::cout << m << std::endl;

    // create another 2 x 2 matrix of integers.
    Matrix<int> n(2, 2);
    n[0][0] = 3;
    n[0][1] = 1;
    n[1][0] = 7;
    n[1][1] = 2;
    std::cout << "Matrix n:" << std::endl;
    std::cout << n << std::endl;

    // perform comparisons of matrices.
    Matrix<int> mCopy(2, 2);
    mCopy[0][0] = 1;
    mCopy[0][1] = 2;
    mCopy[1][0] = 3;
    mCopy[1][1] = 4;
    if (m == mCopy) {
        std::cout << "m and mCopy are equal." << std::endl;
    } else {
        std::cout << "m and mCopy are NOT equal." << std::endl;
    }
    if (m != n) {
        std::cout << "m and n are NOT equal." << std::endl;
    } else {
        std::cout << "m and n are equal." << std::endl;
    }
    std::cout << std::endl;

    // add 2 matrices of integers.
    Matrix<int> iAdd = m + n;
    std::cout << "iAdd = m + n" << std::endl;
    std::cout << iAdd << std::endl;

    // subtract 2 matrices of integers.
    Matrix<int> iSub = m - n;
    std::cout << "iSub = m - n" << std::endl;
    std::cout << iSub << std::endl;

    // multiply 2 matrices of integers.
    Matrix<int> iMul = m * n;
    std::cout << "iMul = m * n" << std::endl;
    std::cout << iMul << std::endl;

    // multiply a matrix of integers with an integer.
    Matrix<int> iScalarMul = 2 * m;
    std::cout << "iScalarMul = 2 * m" << std::endl;
    std::cout << iScalarMul << std::endl;
    iScalarMul = n * 3;
    std::cout << "iScalarMul = n * 3" << std::endl;
    std::cout << iScalarMul << std::endl;

    // compound addition of matrix of integers.
    m += n;
    std::cout << "m += n" << std::endl;
    std::cout << m << std::endl;
    std::cout << "iAdd:" << std::endl;
    std::cout << iAdd << std::endl;
    if (m == iAdd) {
        std::cout << "m and iAdd are equal." << std::endl;
    } else {
        std::cout << "m and iAdd are NOT equal." << std::endl;
    }
    std::cout << std::endl;

    // compound subtraction of matrix of integers.
    m -= 2 * n;
    std::cout << "m -= 2 * n" << std::endl;
    std::cout << m << std::endl;
    std::cout << "iSub:" << std::endl;
    std::cout << iSub << std::endl;
    if (m == iSub) {
        std::cout << "m and iSub are equal." << std::endl;
    } else {
        std::cout << "m and iSub are NOT equal." << std::endl;
    }
    std::cout << std::endl;

    // compound addition and multiplication of matrix of integers.
    m += n;
    m *= n;
    std::cout << "m += n" << std::endl;
    std::cout << "m *= n" << std::endl;
    std::cout << m << std::endl;
    std::cout << "iMul * 2:" << std::endl;
    std::cout << iMul * 2<< std::endl;
    if (m != iMul) {
        std::cout << "m and iMul are NOT equal." << std::endl;
    } else {
        std::cout << "m and iMul are equal." << std::endl;
    }
    std::cout << std::endl;

    // compound multiplication of a matrix of integers with an integer.
    m *= 10;
    std::cout << "m *= 10" << std::endl;
    std::cout << m << std::endl;

    // PART 2 - MATRIX OF COMPLEX NUMBERS.

    // create 5 complex numbers.
    std::complex<int> c1(1, 0);
    std::complex<int> c2(0, 1);
    std::complex<int> c3(-1, 0);
    std::complex<int> c4(0, -1);
    std::complex<int> c5(1, 2);

    // create a 2 x 2 matrix of complex numbers.
    Matrix<std::complex<int>> cm(2, 2);
    cm[0][0] = c1;
    cm[0][1] = c2;
    cm[1][0] = c3;
    cm[1][1] = c4;
    std::cout << "Matrix cm:" << std::endl;
    std::cout << cm << std::endl;

    // create another 2 x 2 matrix of complex numbers.
    Matrix<std::complex<int>> cn(2, 2);
    cn[0][0] = c2;
    cn[0][1] = c3;
    cn[1][0] = c4;
    cn[1][1] = c5;
    std::cout << "Matrix cn:" << std::endl;
    std::cout << cn << std::endl;

    // add 2 matrices of complex numbers.
    Matrix<std::complex<int>> cAdd = cm + cn;
    std::cout << "cAdd = cm + cn" << std::endl;
    std::cout << cAdd << std::endl;

    // subtract 2 matrices of complex numbers.
    Matrix<std::complex<int>> cSub = cm - cn;
    std::cout << "cSub = cm - cn" << std::endl;
    std::cout << cSub << std::endl;

    // multiply 2 matrices of complex numbers.
    Matrix<std::complex<int>> cMul = cm * cn;
    std::cout << "cMul = cm * cn" << std::endl;
    std::cout << cMul << std::endl;

    // create 2 complex numbers.
    std::complex<int> cScalar1(4, 0);
    std::complex<int> cScalar2(5, 0);
    // multiply a complex number with a matrix of complex numbers.
    Matrix<std::complex<int>> cScalarMul = cScalar1 * cm;
    std::cout << "cScalarMul = 4 * cm" << std::endl;
    std::cout << cScalarMul << std::endl;
    cScalarMul = cn * cScalar2;
    std::cout << "cScalarMul = cn * 5" << std::endl;
    std::cout << cScalarMul << std::endl;

    // compound addition of matrix of complex numbers.
    cm += cn;
    std::cout << "cm += cn" << std::endl;
    std::cout << cm << std::endl;
    std::cout << "cAdd:" << std::endl;
    std::cout << cAdd << std::endl;
    if (cm == cAdd) {
        std::cout << "cm and cAdd are equal." << std::endl;
    } else {
        std::cout << "cm and cAdd are NOT equal." << std::endl;
    }
    std::cout << std::endl;

    // compound subtraction of matrix of complex numbers.
    std::complex<int> cScalar3 = 2;
    cm -= cScalar3 * cn;
    std::cout << "cm -= 2 * cn" << std::endl;
    std::cout << cm << std::endl;
    std::cout << "cSub:" << std::endl;
    std::cout << cSub << std::endl;
    if (cm == cSub) {
        std::cout << "cm and cSub are equal." << std::endl;
    } else {
        std::cout << "cm and cSub are NOT equal." << std::endl;
    }
    std::cout << std::endl;

    // compound addition and multiplication of matrix of complex numbers.
    cm += cn;
    cm *= cn;
    std::cout << "cm += cn" << std::endl;
    std::cout << "cm *= cn" << std::endl;
    std::cout << cm << std::endl;
    std::cout << "cMul:" << std::endl;
    std::cout << cMul << std::endl;
    if (cm != cMul) {
        std::cout << "cm and cMul are NOT equal." << std::endl;
    } else {
        std::cout << "cm and cMul are equal." << std::endl;
    }
    std::cout << std::endl;

    // compound multiplication of matrix of complex numbers with a complex number.
    std::complex<int> cScalar4(10, 0);
    cm *= cScalar4;
    std::cout << "cm *= 10" << std::endl;
    std::cout << cm << std::endl;

    return 0;
}
