///////////////////////////////////////////////////////////////////////////////
// File Name:      test.c
//
// Author:         Varun Naik
// CS email:       vnaik@cs.wisc.edu
//
// Description:    Unit tests for a4. As a reminder, even if you pass all of
//                 these tests, you are not yet guaranteed 90/90 on the
//                 autograder portion. But if you do not pass these tests, you
//                 will probably receive a very low score on the autograder.
//
// Sources:        Google Test, cppreference.com
//
// URL(s) of sources:
//                 https://github.com/google/googletest
//                 http://en.cppreference.com/w/
///////////////////////////////////////////////////////////////////////////////

#include <complex>
#include <fstream>
#include <type_traits>

#include "gtest/gtest.h"
#include "Matrix.hpp"

/**
 * @brief Empties the contents of the buffer, and clears its error state flags.
 *
 * @param buff The buffer containing the lines written to cout
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
            << "Line printed to cout is incorrect" << std::endl
            << " Printed: (end of printed output)" << std::endl
            << "Expected: \"" << str << "\"";
    } else {
        if (line == str) {
            return ::testing::AssertionSuccess();
        } else {
            return ::testing::AssertionFailure()
                << "Line printed to cout is incorrect" << std::endl
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
 * @param buff The buffer containing the lines written to cout
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
            << "Line printed to cout is incorrect" << std::endl
            << " Printed: \"" << line << "\"" << std::endl
            << "Expected: (end of printed output)";
    }
}

/**
 * @brief Reads the next line from buff and checks that the end of the stream
 *        has been reached. Raises a non-fatal failure with the correct line
 *        number otherwise.
 *
 * @param buff The buffer containing the lines written to cout
 */
#define MATCH_END(buff) \
    EXPECT_PRED_FORMAT1(matchEnd, buff)

/**
 * @brief A test fixture class for all a4 tests.
 */
class A4Test : public ::testing::Test {
protected:
    std::stringstream buff;
    // cout_buff is a pointer. Don't worry, we will cover this later in the semester.
    std::streambuf *cout_buff;

    /**
     * @brief Code to run before each unit test.
     *
     * Redirects std::cout to the in-memory variable buff.
     * See: http://en.cppreference.com/w/cpp/io/basic_ios/rdbuf
     */
    virtual void SetUp() override {
        cout_buff = std::cout.rdbuf(buff.rdbuf());
    }

    /**
     * @brief Code to run after each unit test.
     *
     * Resets std::cout so that calls to cout print to the screen again.
     */
    virtual void TearDown() override {
        std::cout.rdbuf(cout_buff);
    }
};

// Define a type IntegerMatrix, depending on the value of a command-line
// argument to the compiler
#if UseTemplate == 0
typedef Matrix IntegerMatrix;
#elif UseTemplate == 1
typedef Matrix<int> IntegerMatrix;
#endif

#ifdef RunBasicMatrixTest

/**
 * @brief Test case to make sure the constructor, getRows() and getCols()
 *        behave as desired.
 */
TEST_F(A4Test, BasicMatrixTest) {
    IntegerMatrix a(2, 4);
    EXPECT_EQ(a.getRows(), 2);
    EXPECT_EQ(a.getCols(), 4);

    MATCH_END(buff);
    clearBuff(buff);
}

#endif

#ifdef RunConstMatrixTest

/**
 * @brief Test case to make sure the constructor, getRows() and getCols()
 *        behave as desired for a const reference to a Matrix.
 */
TEST_F(A4Test, ConstMatrixTest) {
    IntegerMatrix a(2, 4);
    const IntegerMatrix &a2 = a;
    EXPECT_EQ(a2.getRows(), 2);
    EXPECT_EQ(a2.getCols(), 4);

    MATCH_END(buff);
    clearBuff(buff);
}

#endif

#ifdef RunBasicBracketTest

/**
 * @brief Test case to make sure bracket notation behaves as desired.
 */
TEST_F(A4Test, BasicBracketTest) {
    IntegerMatrix m(2, 2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;

    EXPECT_EQ(m[0][0], 1);
    EXPECT_EQ(m[0][1], 2);
    EXPECT_EQ(m[1][0], 3);
    EXPECT_EQ(m[1][1], 4);

    MATCH_END(buff);
    clearBuff(buff);
}

#endif

#ifdef RunConstBracketTest

/**
 * @brief Test case to make sure bracket notation behaves as desired for a
 *        const reference to a Matrix.
 */
TEST_F(A4Test, ConstBracketTest) {
    IntegerMatrix m(2, 2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;

    const IntegerMatrix &m2 = m;
    EXPECT_EQ(m2[0][0], 1);

    MATCH_END(buff);
    clearBuff(buff);
}

#endif

#ifdef RunBasicPrintTest

/**
 * @brief Test case to make sure the << operator behaves as desired.
 */
TEST_F(A4Test, BasicPrintTest) {
    IntegerMatrix m(2, 2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;
    MATCH_END(buff);
    clearBuff(buff);

    std::cout << m << std::endl;
    MATCH_NEXT_LINE(buff, "1 2");
    MATCH_NEXT_LINE(buff, "3 4");
    MATCH_NEXT_LINE(buff, "");
    MATCH_END(buff);
    clearBuff(buff);
}

#endif

#ifdef RunConstPrintTest

/**
 * @brief Test case to make sure the << operator behaves as desired for a const
 *        reference to a Matrix.
 */
TEST_F(A4Test, ConstPrintTest) {
    IntegerMatrix m(2, 2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;
    MATCH_END(buff);
    clearBuff(buff);

    const IntegerMatrix &m2 = m;
    std::cout << m2 << std::endl;
    MATCH_NEXT_LINE(buff, "1 2");
    MATCH_NEXT_LINE(buff, "3 4");
    MATCH_NEXT_LINE(buff, "");
    MATCH_END(buff);
    clearBuff(buff);
}

#endif

#ifdef RunBasicComparisonTest

/**
 * @brief Test case to make sure the == and != operators behave as desired.
 */
TEST_F(A4Test, BasicComparisonTest) {
    IntegerMatrix m(2, 2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;

    IntegerMatrix n(2, 2);
    n[0][0] = 3;
    n[0][1] = 1;
    n[1][0] = 7;
    n[1][1] = 2;

    IntegerMatrix mCopy(2, 2);
    mCopy[0][0] = 1;
    mCopy[0][1] = 2;
    mCopy[1][0] = 3;
    mCopy[1][1] = 4;

    // These call == and !=, respectively
    EXPECT_EQ(m, mCopy);
    EXPECT_NE(m, n);

    MATCH_END(buff);
    clearBuff(buff);
}

#endif

#ifdef RunConstComparisonTest

/**
 * @brief Test case to make sure the == and != operators behave as desired for
 *        const references to Matrices.
 */
TEST_F(A4Test, ConstComparisonTest) {
    IntegerMatrix m(2, 2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;

    IntegerMatrix n(2, 2);
    n[0][0] = 3;
    n[0][1] = 1;
    n[1][0] = 7;
    n[1][1] = 2;

    IntegerMatrix mCopy(2, 2);
    mCopy[0][0] = 1;
    mCopy[0][1] = 2;
    mCopy[1][0] = 3;
    mCopy[1][1] = 4;

    const IntegerMatrix &m2 = m;
    const IntegerMatrix &n2 = n;
    const IntegerMatrix &mCopy2 = mCopy;

    EXPECT_EQ(m2, mCopy2);
    EXPECT_NE(m2, n2);

    MATCH_END(buff);
    clearBuff(buff);
}

#endif

#ifdef RunMismatchedComparisonTest

/**
 * @brief Test case to make sure the != operator behaves as desired for
 *        Matrices of different dimensions.
 */
TEST_F(A4Test, MismatchedComparisonTest) {
    IntegerMatrix m(2, 2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;

    IntegerMatrix n(2, 3);
    n[0][0] = 1;
    n[0][1] = 2;
    n[1][0] = 3;
    n[1][1] = 4;
    n[0][2] = 0;
    n[1][2] = 0;

    IntegerMatrix o(3, 2);
    o[0][0] = 1;
    o[0][1] = 2;
    o[1][0] = 3;
    o[1][1] = 4;
    o[2][0] = 0;
    o[2][1] = 0;

    EXPECT_NE(m, n);
    EXPECT_NE(m, o);
    EXPECT_NE(n, o);

    MATCH_END(buff);
    clearBuff(buff);
}

#endif

#ifdef RunBasicAdditionTest

/**
 * @brief Test case to make sure the + operator behaves as desired.
 */
TEST_F(A4Test, BasicAdditionTest) {
    IntegerMatrix m(2, 2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;

    IntegerMatrix n(2, 2);
    n[0][0] = 3;
    n[0][1] = 1;
    n[1][0] = 7;
    n[1][1] = 2;

    IntegerMatrix iAdd = m + n;
    EXPECT_EQ(iAdd[0][0], 4);
    EXPECT_EQ(iAdd[0][1], 3);
    EXPECT_EQ(iAdd[1][0], 10);
    EXPECT_EQ(iAdd[1][1], 6);

    MATCH_END(buff);
    clearBuff(buff);
}

#endif

#ifdef RunConstAdditionTest

/**
 * @brief Test case to make sure the + operator return type is const. This test
 *        should fail to compile.
 */
TEST_F(A4Test, ConstAdditionTest) {
    IntegerMatrix m(2, 2);
    IntegerMatrix n(2, 2);
    (m + n) = n;
}

#endif

#ifdef RunMismatchedAdditionTest

/**
 * @brief Test case to make sure the + operator behaves as desired for Matrices
 *        of different dimensions.
 */
TEST_F(A4Test, MismatchedAdditionTest) {
    IntegerMatrix m(2, 2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;

    IntegerMatrix n(2, 1);
    n[0][0] = 3;
    n[1][0] = 7;

    // The following line should crash with any error message
    EXPECT_DEATH(m + n, ".*");

    MATCH_END(buff);
    clearBuff(buff);
}

#endif

#ifdef RunBasicSubtractionTest

/**
 * @brief Test case to make sure the - operator behaves as desired.
 */
TEST_F(A4Test, BasicSubtractionTest) {
    IntegerMatrix m(2, 2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;

    IntegerMatrix n(2, 2);
    n[0][0] = 3;
    n[0][1] = 1;
    n[1][0] = 7;
    n[1][1] = 2;

    IntegerMatrix iSub = m - n;
    EXPECT_EQ(iSub[0][0], -2);
    EXPECT_EQ(iSub[0][1], 1);
    EXPECT_EQ(iSub[1][0], -4);
    EXPECT_EQ(iSub[1][1], 2);

    MATCH_END(buff);
    clearBuff(buff);
}

#endif

#ifdef RunBasicMatrixMultiplicationTest

/**
 * @brief Test case to make sure the * operator for matrix multiplication
 *        behaves as desired.
 */
TEST_F(A4Test, BasicMatrixMultiplicationTest) {
    IntegerMatrix m(2, 2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;

    IntegerMatrix n(2, 2);
    n[0][0] = 3;
    n[0][1] = 1;
    n[1][0] = 7;
    n[1][1] = 2;

    IntegerMatrix iMul = m * n;
    EXPECT_EQ(iMul[0][0], 17);
    EXPECT_EQ(iMul[0][1], 5);
    EXPECT_EQ(iMul[1][0], 37);
    EXPECT_EQ(iMul[1][1], 11);

    MATCH_END(buff);
    clearBuff(buff);
}

#endif

#ifdef RunBasicScalarMultiplicationTest

/**
 * @brief Test case to make sure the * operator for scalar multiplication
 *        behaves as desired.
 */
TEST_F(A4Test, BasicScalarMultiplicationTest) {
    IntegerMatrix m(2, 2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;

    IntegerMatrix iScalarMul = 2 * m;
    EXPECT_EQ(iScalarMul[0][0], 2);
    EXPECT_EQ(iScalarMul[0][1], 4);
    EXPECT_EQ(iScalarMul[1][0], 6);
    EXPECT_EQ(iScalarMul[1][1], 8);

    iScalarMul = 3 * m;
    EXPECT_EQ(iScalarMul[0][0], 3);
    EXPECT_EQ(iScalarMul[0][1], 6);
    EXPECT_EQ(iScalarMul[1][0], 9);
    EXPECT_EQ(iScalarMul[1][1], 12);

    MATCH_END(buff);
    clearBuff(buff);
}

#endif

#ifdef RunBasicCompoundAdditionTest

/**
 * @brief Test case to make sure the += operator behaves as desired.
 */
TEST_F(A4Test, BasicCompoundAdditionTest) {
    IntegerMatrix m(2, 2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;

    IntegerMatrix n(2, 2);
    n[0][0] = 3;
    n[0][1] = 1;
    n[1][0] = 7;
    n[1][1] = 2;

    m += n;
    EXPECT_EQ(m[0][0], 4);
    EXPECT_EQ(m[0][1], 3);
    EXPECT_EQ(m[1][0], 10);
    EXPECT_EQ(m[1][1], 6);

    MATCH_END(buff);
    clearBuff(buff);
}

#endif

#ifdef RunConstCompoundAdditionTest

/**
 * @brief Test case to make sure the += operator behaves as desired for a const
 *        reference to a Matrix.
 */
TEST_F(A4Test, ConstCompoundAdditionTest) {
    IntegerMatrix m(2, 2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;

    IntegerMatrix n(2, 2);
    n[0][0] = 3;
    n[0][1] = 1;
    n[1][0] = 7;
    n[1][1] = 2;

    const IntegerMatrix &n2 = n;
    (m += n2) += n2;
    EXPECT_EQ(m[0][0], 7);
    EXPECT_EQ(m[0][1], 4);
    EXPECT_EQ(m[1][0], 17);
    EXPECT_EQ(m[1][1], 8);

    MATCH_END(buff);
    clearBuff(buff);
}

#endif

#ifdef RunBasicCompoundSubtractionTest

/**
 * @brief Test case to make sure the -= operator behaves as desired.
 */
TEST_F(A4Test, BasicCompoundSubtractionTest) {
    IntegerMatrix m(2, 2);
    m[0][0] = 4;
    m[0][1] = 3;
    m[1][0] = 10;
    m[1][1] = 6;

    IntegerMatrix n(2, 2);
    n[0][0] = 3;
    n[0][1] = 1;
    n[1][0] = 7;
    n[1][1] = 2;

    m -= 2 * n;
    EXPECT_EQ(m[0][0], -2);
    EXPECT_EQ(m[0][1], 1);
    EXPECT_EQ(m[1][0], -4);
    EXPECT_EQ(m[1][1], 2);

    MATCH_END(buff);
    clearBuff(buff);
}

#endif

#ifdef RunBasicCompoundMatrixMultiplicationTest

/**
 * @brief Test case to make sure the *= operator behaves as desired for matrix
 *        multiplication.
 */
TEST_F(A4Test, BasicCompoundMatrixMultiplicationTest) {
    IntegerMatrix m(2, 2);
    m[0][0] = -2;
    m[0][1] = 1;
    m[1][0] = -4;
    m[1][1] = 2;

    IntegerMatrix n(2, 2);
    n[0][0] = 3;
    n[0][1] = 1;
    n[1][0] = 7;
    n[1][1] = 2;

    m += n;
    m *= n;
    EXPECT_EQ(m[0][0], 17);
    EXPECT_EQ(m[0][1], 5);
    EXPECT_EQ(m[1][0], 37);
    EXPECT_EQ(m[1][1], 11);

    MATCH_END(buff);
    clearBuff(buff);
}

#endif

#ifdef RunBasicCompoundScalarMultiplicationTest

/**
 * @brief Test case to make sure the *= operator behaves as desired for scalar
 *        multiplication.
 */
TEST_F(A4Test, BasicCompoundScalarMultiplicationTest) {
    IntegerMatrix m(2, 2);
    m[0][0] = 17;
    m[0][1] = 5;
    m[1][0] = 37;
    m[1][1] = 11;

    m *= 10;
    EXPECT_EQ(m[0][0], 170);
    EXPECT_EQ(m[0][1], 50);
    EXPECT_EQ(m[1][0], 370);
    EXPECT_EQ(m[1][1], 110);

    MATCH_END(buff);
    clearBuff(buff);
}

#endif

#ifdef RunComplexTest

/**
 * @brief Test case for complex numbers. This is almost the same as the second
 *        half of main().
 */
TEST_F(A4Test, ComplexTest) {
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

    MATCH_END(buff);
    clearBuff(buff);
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
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
