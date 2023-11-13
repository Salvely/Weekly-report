///////////////////////////////////////////////////////////////////////////////
// File Name:      test.c
//
// Author:         Varun Naik
// CS email:       vnaik@cs.wisc.edu
//
// Description:    Unit tests for a5. As a reminder, even if you pass all of
//                 these tests, you are not yet guaranteed 90/90 on the
//                 autograder portion. But if you do not pass these tests, you
//                 will probably receive a very low score on the autograder.
//
// Sources:        Google Test, cppreference.com, Linux man pages
//
// URL(s) of sources:
//                 https://github.com/google/googletest
//                 http://en.cppreference.com/w/
//                 https://linux.die.net/
///////////////////////////////////////////////////////////////////////////////

#include <complex>
#include <sys/resource.h>

#include "gtest/gtest.h"
#include "Matrix.hpp"

/**
 * @brief Empties the contents of the buffer, and clears its error state flags.
 *
 * @param buff The buffer to which the output is written
 */
void clearBuff(std::stringstream &buff) {
    buff.str("");
    buff.clear();
}

/**
 * @brief Helper function that returns an AssertionResult for MATCH_NEXT_LINE.
 *
 * Do not call this function directly. Call MATCH_NEXT_LINE instead.
 *
 * @param expr0 The first expression passed to MATCH_NEXT_LINE
 * @param expr1 The second expression passed to MATCH_NEXT_LINE
 * @param buff See comment for MATCH_NEXT_LINE
 * @param str See comment for MATCH_NEXT_LINE
 * @return AssertionSuccess() on success or AssertionFailure() on failure
 */
::testing::AssertionResult matchNextLine(const std::string &expr0,
                                         const std::string &expr1,
                                         std::stringstream &buff,
                                         const std::string &str) {
    std::string line;
    std::getline(buff, line);
    if (buff.eof()) {
        return ::testing::AssertionFailure()
            << "Line printed to buff is incorrect" << std::endl
            << " Printed: (end of printed output)" << std::endl
            << "Expected: \"" << str << "\"";
    } else {
        if (line == str) {
            return ::testing::AssertionSuccess();
        } else {
            return ::testing::AssertionFailure()
                << "Line printed to buff is incorrect" << std::endl
                << " Printed: \"" << line << "\"" << std::endl
                << "Expected: \"" << str << "\"";
        }
    }
}

/**
 * @brief Reads the next line from buff and checks that it is equal to str.
 *        Raises a non-fatal failure with the correct line number if we have
 *        reached the end of file, or if the pattern does not match.
 *
 * @param buff The buffer to which the output is written
 * @param str The exact string to compare to
 */
#define MATCH_NEXT_LINE(buff, str) \
    EXPECT_PRED_FORMAT2(matchNextLine, buff, str)

/**
 * @brief Helper function that returns an AssertionResult for MATCH_END.
 *
 * Do not call this function directly. Call MATCH_END instead.
 *
 * @param expr0 The first expression passed to MATCH_END
 * @param buff See comment for MATCH_END
 * @return AssertionSuccess() on success or AssertionFailure() on failure
 */
::testing::AssertionResult matchEnd(const std::string &expr0, std::stringstream &buff) {
    std::string line;
    getline(buff, line);
    if (buff.eof()) {
        return ::testing::AssertionSuccess();
    } else {
        return ::testing::AssertionFailure()
            << "Line printed to buff is incorrect" << std::endl
            << " Printed: \"" << line << "\"" << std::endl
            << "Expected: (end of printed output)";
    }
}

/**
 * @brief Reads the next line from buff and checks that the end of the stream
 *        has been reached. Raises a non-fatal failure with the correct line
 *        number otherwise.
 *
 * @param buff The buffer to which the output is written
 */
#define MATCH_END(buff) \
    EXPECT_PRED_FORMAT1(matchEnd, buff)

#ifdef RunIntTest

/**
 * @brief Test case for integers. This is almost the same as the first half of
 *        main() for a4.
 */
TEST(A5Test, IntTest) {
    // create a matrix and check its dimensions.
    Matrix<int> a(2, 4);
    EXPECT_EQ(a.getRows(), 2);
    EXPECT_EQ(a.getCols(), 4);

    // create a 2 x 2 matrix of integers.
    Matrix<int> m(2, 2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;
    std::stringstream buff;
    buff << m << std::endl;
    MATCH_NEXT_LINE(buff, "1 2");
    MATCH_NEXT_LINE(buff, "3 4");
    MATCH_NEXT_LINE(buff, "");
    MATCH_END(buff);
    clearBuff(buff);

    // create another 2 x 2 matrix of integers.
    Matrix<int> n(2, 2);
    n[0][0] = 3;
    n[0][1] = 1;
    n[1][0] = 7;
    n[1][1] = 2;
    EXPECT_EQ(n[0][0], 3);
    EXPECT_EQ(n[0][1], 1);
    EXPECT_EQ(n[1][0], 7);
    EXPECT_EQ(n[1][1], 2);

    // perform comparisons of matrices.
    Matrix<int> mCopy(2, 2);
    mCopy[0][0] = 1;
    mCopy[0][1] = 2;
    mCopy[1][0] = 3;
    mCopy[1][1] = 4;
    EXPECT_EQ(m, mCopy);
    EXPECT_NE(m, n);

    // add 2 matrices of integers.
    Matrix<int> iAdd = m + n;
    EXPECT_EQ(iAdd[0][0], 4);
    EXPECT_EQ(iAdd[0][1], 3);
    EXPECT_EQ(iAdd[1][0], 10);
    EXPECT_EQ(iAdd[1][1], 6);

    // subtract 2 matrices of integers.
    Matrix<int> iSub = m - n;
    EXPECT_EQ(iSub[0][0], -2);
    EXPECT_EQ(iSub[0][1], 1);
    EXPECT_EQ(iSub[1][0], -4);
    EXPECT_EQ(iSub[1][1], 2);

    // multiply 2 matrices of integers.
    Matrix<int> iMul = m * n;
    EXPECT_EQ(iMul[0][0], 17);
    EXPECT_EQ(iMul[0][1], 5);
    EXPECT_EQ(iMul[1][0], 37);
    EXPECT_EQ(iMul[1][1], 11);

    // multiply a matrix of integers with an integer.
    Matrix<int> iScalarMul = 2 * m;
    EXPECT_EQ(iScalarMul[0][0], 2);
    EXPECT_EQ(iScalarMul[0][1], 4);
    EXPECT_EQ(iScalarMul[1][0], 6);
    EXPECT_EQ(iScalarMul[1][1], 8);
    iScalarMul = n * 3;
    EXPECT_EQ(iScalarMul[0][0], 9);
    EXPECT_EQ(iScalarMul[0][1], 3);
    EXPECT_EQ(iScalarMul[1][0], 21);
    EXPECT_EQ(iScalarMul[1][1], 6);

    // compound addition of matrix of integers.
    m += n;
    EXPECT_EQ(m[0][0], 4);
    EXPECT_EQ(m[0][1], 3);
    EXPECT_EQ(m[1][0], 10);
    EXPECT_EQ(m[1][1], 6);
    EXPECT_EQ(m, iAdd);

    // compound subtraction of matrix of integers.
    m -= 2 * n;
    EXPECT_EQ(m[0][0], -2);
    EXPECT_EQ(m[0][1], 1);
    EXPECT_EQ(m[1][0], -4);
    EXPECT_EQ(m[1][1], 2);
    EXPECT_EQ(m, iSub);

    // compound addition and multiplication of matrix of integers.
    m += n;
    m *= n;
    EXPECT_EQ(m[0][0], 17);
    EXPECT_EQ(m[0][1], 5);
    EXPECT_EQ(m[1][0], 37);
    EXPECT_EQ(m[1][1], 11);
    EXPECT_EQ(m, iMul);

    // compound multiplication of a matrix of integers with an integer.
    m *= 10;
    EXPECT_EQ(m[0][0], 170);
    EXPECT_EQ(m[0][1], 50);
    EXPECT_EQ(m[1][0], 370);
    EXPECT_EQ(m[1][1], 110);
}

#endif

#ifdef RunComplexTest

/**
 * @brief Test case for complex numbers. This is almost the same as the second
 *        half of main() for a4.
 */
TEST(A5Test, ComplexTest) {
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
    EXPECT_EQ(cm[0][0], c1);
    EXPECT_EQ(cm[0][1], c2);
    EXPECT_EQ(cm[1][0], c3);
    EXPECT_EQ(cm[1][1], c4);

    // create another 2 x 2 matrix of complex numbers.
    Matrix<std::complex<int>> cn(2, 2);
    cn[0][0] = c2;
    cn[0][1] = c3;
    cn[1][0] = c4;
    cn[1][1] = c5;
    EXPECT_EQ(cn[0][0], c2);
    EXPECT_EQ(cn[0][1], c3);
    EXPECT_EQ(cn[1][0], c4);
    EXPECT_EQ(cn[1][1], c5);

    // add 2 matrices of complex numbers.
    Matrix<std::complex<int>> cAdd = cm + cn;
    EXPECT_EQ(cAdd[0][0], c1 + c2);
    EXPECT_EQ(cAdd[0][1], c2 + c3);
    EXPECT_EQ(cAdd[1][0], c3 + c4);
    EXPECT_EQ(cAdd[1][1], c4 + c5);

    // subtract 2 matrices of complex numbers.
    Matrix<std::complex<int>> cSub = cm - cn;
    EXPECT_EQ(cSub[0][0], c1 - c2);
    EXPECT_EQ(cSub[0][1], c2 - c3);
    EXPECT_EQ(cSub[1][0], c3 - c4);
    EXPECT_EQ(cSub[1][1], c4 - c5);

    // multiply 2 matrices of complex numbers.
    Matrix<std::complex<int>> cMul = cm * cn;
    EXPECT_EQ(cMul[0][0], c1*c2 + c2*c4);
    EXPECT_EQ(cMul[0][1], c1*c3 + c2*c5);
    EXPECT_EQ(cMul[1][0], c3*c2 + c4*c4);
    EXPECT_EQ(cMul[1][1], c3*c3 + c4*c5);

    // create 2 complex numbers.
    std::complex<int> cScalar1(4, 0);
    std::complex<int> cScalar2(5, 0);
    // multiply a complex number with a matrix of complex numbers.
    Matrix<std::complex<int>> cScalarMul = cScalar1 * cm;
    EXPECT_EQ(cScalarMul[0][0], cScalar1 * c1);
    EXPECT_EQ(cScalarMul[0][1], cScalar1 * c2);
    EXPECT_EQ(cScalarMul[1][0], cScalar1 * c3);
    EXPECT_EQ(cScalarMul[1][1], cScalar1 * c4);
    cScalarMul = cn * cScalar2;
    EXPECT_EQ(cScalarMul[0][0], cScalar2 * c2);
    EXPECT_EQ(cScalarMul[0][1], cScalar2 * c3);
    EXPECT_EQ(cScalarMul[1][0], cScalar2 * c4);
    EXPECT_EQ(cScalarMul[1][1], cScalar2 * c5);

    // compound addition of matrix of complex numbers.
    cm += cn;
    EXPECT_EQ(cm, cAdd);

    // compound subtraction of matrix of complex numbers.
    std::complex<int> cScalar3 = 2;
    cm -= cScalar3 * cn;
    EXPECT_EQ(cm, cSub);

    // compound addition and multiplication of matrix of complex numbers.
    cm += cn;
    cm *= cn;
    EXPECT_EQ(cm, cMul);

    // compound multiplication of matrix of complex numbers with a complex number.
    std::complex<int> cScalar4(10, 0);
    cm *= cScalar4;
    EXPECT_EQ(cm[0][0], cScalar4 * cMul[0][0]);
    EXPECT_EQ(cm[0][1], cScalar4 * cMul[0][1]);
    EXPECT_EQ(cm[1][0], cScalar4 * cMul[1][0]);
    EXPECT_EQ(cm[1][1], cScalar4 * cMul[1][1]);
}

#endif

#ifdef RunBasicExceptionTest

/**
 * @brief Test case that constructs (but does not throw) the three types of
 *        exceptions.
 */
TEST(A5Test, BasicExceptionTest) {
    InvalidDimension e1(-3, 4);
    IndexOutOfBounds e2(-3);
    IncompatibleMatrices e3("Addition", 3, 3, 4, 4);
}

#endif

#ifdef RunInheritExceptionTest

/**
 * @brief Test case that makes sure the three types of exceptions can be
 *        thrown, and that they inherit from std::exception.
 */
TEST(A5Test, InheritExceptionTest) {
    try {
        throw InvalidDimension(-3, 4);
        ADD_FAILURE() << "InvalidDimension not thrown";
    } catch (std::exception e) {
        const char *what = e.what();
    } catch (...) {
        ADD_FAILURE() << "Make sure InvalidDimension inherits from std::exception";
    }

    try {
        throw IndexOutOfBounds(-3);
        ADD_FAILURE() << "IndexOutOfBounds not thrown";
    } catch (std::exception e) {
        const char *what = e.what();
    } catch (...) {
        ADD_FAILURE() << "Make sure IndexOutOfBounds inherits from std::exception";
    }

    try {
        throw IncompatibleMatrices("Addition", 3, 3, 4, 4);
        ADD_FAILURE() << "IncompatibleMatrices not thrown";
    } catch (std::exception e) {
        const char *what = e.what();
    } catch (...) {
        ADD_FAILURE() << "Make sure IncompatibleMatrices inherits from std::exception";
    }
}

#endif

#ifdef RunInvalidDimensionTest

/**
 * @brief Test case for InvalidDimension.
 */
TEST(A5Test, InvalidDimensionTest) {
    try {
        Matrix<int> m(-3, 4);
        ADD_FAILURE() << "InvalidDimension(-3, 4) not thrown";
    } catch (InvalidDimension e) {
        char msg[256];
        const char *what = e.what();
        strncpy(msg, what, 255);
        msg[255] = '\0';
        EXPECT_STREQ(msg, "Invalid Dimension Exception: -3 is an invalid dimension for rows");
    }

    try {
        Matrix<int> m(3, -4);
        ADD_FAILURE() << "InvalidDimension(3, -4) not thrown";
    } catch (InvalidDimension e) {
        char msg[256];
        const char *what = e.what();
        strncpy(msg, what, 255);
        msg[255] = '\0';
        EXPECT_STREQ(msg, "Invalid Dimension Exception: -4 is an invalid dimension for columns");
    }

    try {
        Matrix<int> m(-3, -4);
        ADD_FAILURE() << "InvalidDimension(-3, -4) not thrown";
    } catch (InvalidDimension e) {
        char msg[256];
        const char *what = e.what();
        strncpy(msg, what, 255);
        msg[255] = '\0';
        EXPECT_STREQ(msg, "Invalid Dimension Exception: -3 and -4 are invalid dimensions " \
            "for rows and columns respectively");
    }
}

#endif

#ifdef RunIndexOutOfBoundsTest

/**
 * @brief Test case for IndexOutOfBounds.
 */
TEST(A5Test, IndexOutOfBoundsTest) {
    Matrix<int> m(3, 3);

    try {
        m[3][2] = 0;
        ADD_FAILURE() << "IndexOutOfBounds(3) not thrown";
    } catch (IndexOutOfBounds e) {
        char msg[256];
        const char *what = e.what();
        strncpy(msg, what, 255);
        msg[255] = '\0';
        EXPECT_STREQ(msg, "Index Out Of Bounds Exception: 3 is an invalid index for rows");
    }

    try {
        m[-3][2] = 0;
        ADD_FAILURE() << "IndexOutOfBounds(-3) not thrown";
    } catch (IndexOutOfBounds e) {
        char msg[256];
        const char *what = e.what();
        strncpy(msg, what, 255);
        msg[255] = '\0';
        EXPECT_STREQ(msg, "Index Out Of Bounds Exception: -3 is an invalid index for rows");
    }
}

#endif

#ifdef RunIncompatibleMatricesTest

/**
 * @brief Test case for IncompatibleMatrices.
 */
TEST(A5Test, IncompatibleMatricesTest) {
    Matrix<int> m1(3, 3);
    Matrix<int> n1(4, 4);
    Matrix<int> m2(1, 2);
    Matrix<int> n2(1, 2);

    try {
        Matrix<int> r = m1 + n1;
        ADD_FAILURE() << "IncompatibleMatrices(\"Addition\", 3, 3, 4, 4) not thrown";
    } catch (IncompatibleMatrices e) {
        char msg[256];
        const char *what = e.what();
        strncpy(msg, what, 255);
        msg[255] = '\0';
        EXPECT_STREQ(msg, "Incompatible Matrices Exception: Addition of LHS matrix with " \
            "dimensions 3 x 3 and RHS matrix with dimensions 4 x 4 is undefined");
    }

    try {
        Matrix<int> r = m1 - n1;
        ADD_FAILURE() << "IncompatibleMatrices(\"Subtraction\", 3, 3, 4, 4) not thrown";
    } catch (IncompatibleMatrices e) {
        char msg[256];
        const char *what = e.what();
        strncpy(msg, what, 255);
        msg[255] = '\0';
        EXPECT_STREQ(msg, "Incompatible Matrices Exception: Subtraction of LHS matrix with " \
            "dimensions 3 x 3 and RHS matrix with dimensions 4 x 4 is undefined");
    }

    try {
        Matrix<int> r = m2 * n2;
        ADD_FAILURE() << "IncompatibleMatrices(\"Multiplication\", 1, 2, 1, 2) not thrown";
    } catch (IncompatibleMatrices e) {
        char msg[256];
        const char *what = e.what();
        strncpy(msg, what, 255);
        msg[255] = '\0';
        EXPECT_STREQ(msg, "Incompatible Matrices Exception: Multiplication of LHS matrix with " \
            "dimensions 1 x 2 and RHS matrix with dimensions 1 x 2 is undefined");
    }
}

#endif

/**
 * @brief Unit test execution begins here.
 *
 * @param argc Number of command-line arguments
 * @param argv Command line arguments
 * @return 0 for normal program termination, other error code for abnormal termination
 */
int main(int argc, char **argv) {
    // Limit size of virtual memory to 2^25 bytes
    // See: https://linux.die.net/man/2/setrlimit
    struct rlimit lim;
    lim.rlim_cur = 33554432;
    lim.rlim_max = 33554432;
    int status = setrlimit(RLIMIT_AS, &lim);
    if (status == -1) {
        return 1;
    }

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
