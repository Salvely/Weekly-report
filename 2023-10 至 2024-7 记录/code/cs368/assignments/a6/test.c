///////////////////////////////////////////////////////////////////////////////
// File Name:      test.c
//
// Author:         Varun Naik
// CS email:       vnaik@cs.wisc.edu
//
// Description:    Unit tests for a6. As a reminder, even if you pass all of
//                 these tests, you are not yet guaranteed 100/100 on the
//                 assignment. But if you do not pass these tests, you will
//                 probably receive a very low score on the autograder.
//
// Sources:        Google Test, cppreference.com, Linux man pages
//
// URL(s) of sources:
//                 https://github.com/google/googletest
//                 http://en.cppreference.com/w/
//                 https://linux.die.net/
///////////////////////////////////////////////////////////////////////////////

#include "Vector.hpp"
#include "gtest/gtest.h"

#include <sys/resource.h>
#include <type_traits>

/**
 * @brief Compile-time checks for the Vector class. This function is never
 *        called, but it should compile without any errors.
 */
void compilerChecks() {
    // Iterator definitions
    static_assert(
        std::is_same<Vector<int>::iterator, int *>::value,
        "Vector<int>::iterator is not aliased to int *"
    );
    static_assert(
        std::is_same<Vector<int>::const_iterator, const int *>::value,
        "Vector<int>::const_iterator is not aliased to const int *"
    );
    static_assert(
        std::is_same<Vector<double>::iterator, double *>::value,
        "Vector<double>::iterator is not aliased to double *"
    );
    static_assert(
        std::is_same<Vector<double>::const_iterator, const double *>::value,
        "Vector<double>::const_iterator is not aliased to const double *"
    );

    // Do not run this code, just make sure it compiles
    if (false) {
        Vector<int> vInt;
        const Vector<int> &vIntRef = vInt;
        Vector<double> vDouble;
        const Vector<double> &vDoubleRef = vDouble;
        // Check return types
        static_assert(
            std::is_same<Vector<int> &, decltype(vInt.operator=(vInt))>::value,
            "Vector<int>::operator= return type is not Vector<int> &"
        );
        static_assert(
            std::is_same<Vector<double> &, decltype(vDouble.operator=(vDouble))>::value,
            "Vector<double>::operator= return type is not Vector<double> &"
        );
        static_assert(
            std::is_same<Vector<int>::iterator, decltype(vInt.Begin())>::value,
            "Vector<int>::Begin() return type is not Vector<int>::iterator"
        );
        static_assert(
            std::is_same<Vector<double>::iterator, decltype(vDouble.Begin())>::value,
            "Vector<double>::Begin() return type is not Vector<double>::iterator"
        );
        static_assert(
            std::is_same<Vector<int>::const_iterator, decltype(vIntRef.Begin())>::value,
            "Vector<int>::Begin() const return type is not Vector<int>::const_iterator"
        );
        static_assert(
            std::is_same<Vector<double>::const_iterator, decltype(vDoubleRef.Begin())>::value,
            "Vector<double>::Begin() const return type is not Vector<double>::const_iterator"
        );
        static_assert(
            std::is_same<Vector<int>::iterator, decltype(vInt.End())>::value,
            "Vector<int>::End() return type is not Vector<int>::iterator"
        );
        static_assert(
            std::is_same<Vector<double>::iterator, decltype(vDouble.End())>::value,
            "Vector<double>::End() return type is not Vector<double>::iterator"
        );
        static_assert(
            std::is_same<Vector<int>::const_iterator, decltype(vIntRef.End())>::value,
            "Vector<int>::End() const return type is not Vector<int>::const_iterator"
        );
        static_assert(
            std::is_same<Vector<double>::const_iterator, decltype(vDoubleRef.End())>::value,
            "Vector<double>::End() const return type is not Vector<double>::const_iterator"
        );
        static_assert(
            std::is_same<std::size_t, decltype(vInt.Capacity())>::value,
            "Vector<int>::Capacity() return type is not std::size_t"
        );
        static_assert(
            std::is_same<std::size_t, decltype(vInt.Size())>::value,
            "Vector<int>::Size() return type is not std::size_t"
        );
        static_assert(
            std::is_same<void, decltype(vInt.Push_Back(0))>::value,
            "Vector<int>::Push_Back() return type is not void"
        );
        static_assert(
            std::is_same<void, decltype(vInt.Pop_Back())>::value,
            "Vector<int>::Pop_Back() return type is not void"
        );
        static_assert(
            std::is_same<void, decltype(vInt.Reserve(0))>::value,
            "Vector<int>::Reserve() return type is not void"
        );
        static_assert(
            std::is_same<int &, decltype(vInt[0])>::value,
            "Vector<int>::operator[] return type is not int &"
        );
        static_assert(
            std::is_same<double &, decltype(vDouble[0])>::value,
            "Vector<double>::operator[] return type is not double &"
        );
        static_assert(
            std::is_same<const int &, decltype(vIntRef[0])>::value,
            "Vector<int>::operator[] const return type is not const int &"
        );
        static_assert(
            std::is_same<const double &, decltype(vDoubleRef[0])>::value,
            "Vector<double>::operator[] const return type is not const double &"
        );
        static_assert(
            std::is_same<int &, decltype(vInt.At(0))>::value,
            "Vector<int>::At() return type is not int &"
        );
        static_assert(
            std::is_same<double &, decltype(vDouble.At(0))>::value,
            "Vector<double>::At() return type is not double &"
        );
        static_assert(
            std::is_same<const int &, decltype(vIntRef.At(0))>::value,
            "Vector<int>::At() const return type is not const int &"
        );
        static_assert(
            std::is_same<const double &, decltype(vDoubleRef.At(0))>::value,
            "Vector<double>::At() const return type is not const double &"
        );
        static_assert(
            std::is_same<bool, decltype(vInt.Empty())>::value,
            "Vector<int>::Empty() return type is not bool"
        );
        static_assert(
            std::is_same<void, decltype(vInt.Clear())>::value,
            "Vector<int>::Clear() return type is not void"
        );
        static_assert(
            std::is_same<Vector<int>::iterator, decltype(vInt.Erase(vInt.Begin()))>::value,
            "Vector<int>::Erase() return type is not Vector<int>::iterator"
        );
        static_assert(
            std::is_same<Vector<double>::iterator, decltype(vDouble.Erase(vDouble.Begin()))>::value,
            "Vector<double>::Erase() return type is not Vector<double>::iterator"
        );
    }

    // Do not run this code, just make sure it compiles
    if (false) {
        // Default constructor
        Vector<int> v1;
        const Vector<int> &vRef = v1;

        // Begin() and End()
        Vector<int>::iterator it;
        Vector<int>::const_iterator constIt;
        it = v1.Begin();
        constIt = vRef.Begin();
        it = v1.End();
        constIt = vRef.End();

        // Capacity() and Size()
        int n;
        n = vRef.Capacity();
        n = vRef.Size();

        // Push_Back() and Pop_Back()
        v1.Push_Back(1);
        v1.Pop_Back();

        // Reserve()
        v1.Reserve(8);

        // Array subscripting operator
        v1.Push_Back(1);
        v1[0] = 2;
        n = vRef[0];

        // At()
        v1.At(0) = 3;
        n = vRef.At(0);

        // Empty()
        bool empty = vRef.Empty();

        // Clear()
        v1.Clear();

        // Erase()
        v1.Push_Back(4);
        it = v1.Erase(v1.Begin());

        // Copy constructor
        Vector<int> v2(vRef);

        // Copy assignment operator
        (v2 = vRef).Push_Back(1);
    }
}

#ifdef RunBasicTest

/**
 * @brief Test case that checks basic behavior for Capacity(), Size(), Empty(),
 *        Push_Back(), operator[], and At().
 */
TEST(A6Test, BasicTest) {
    Vector<int> v;
    EXPECT_EQ(v.Capacity(), 4);
    EXPECT_EQ(v.Size(), 0);
    EXPECT_EQ(v.Empty(), true);

    v.Push_Back(1);
    EXPECT_EQ(v.Capacity(), 4);
    EXPECT_EQ(v.Size(), 1);
    EXPECT_EQ(v.Empty(), false);

    v.Push_Back(2);
    EXPECT_EQ(v.Capacity(), 4);
    EXPECT_EQ(v.Size(), 2);
    EXPECT_EQ(v.Empty(), false);

    v.Push_Back(3);
    EXPECT_EQ(v.Capacity(), 4);
    EXPECT_EQ(v.Size(), 3);
    EXPECT_EQ(v.Empty(), false);

    v.Push_Back(4);
    EXPECT_EQ(v.Capacity(), 4);
    EXPECT_EQ(v.Size(), 4);
    EXPECT_EQ(v.Empty(), false);

    v.Push_Back(5);
    EXPECT_EQ(v.Capacity(), 8);
    EXPECT_EQ(v.Size(), 5);
    EXPECT_EQ(v.Empty(), false);

    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
    EXPECT_EQ(v[2], 3);
    EXPECT_EQ(v[3], 4);
    EXPECT_EQ(v[4], 5);

    EXPECT_EQ(v.At(0), 1);
    EXPECT_EQ(v.At(1), 2);
    EXPECT_EQ(v.At(2), 3);
    EXPECT_EQ(v.At(3), 4);
    EXPECT_EQ(v.At(4), 5);
}

#endif

#ifdef RunPushPerformanceTest

/**
 * @brief Test case that checks whether Push_Back() runs in O(1) amortized
 *        time.
 */
TEST(A6Test, PushPerformanceTest) {
    Vector<int> v;
    EXPECT_EQ(v.Capacity(), 4);
    EXPECT_EQ(v.Size(), 0);
    EXPECT_EQ(v.Empty(), true);
    Vector<int>::iterator begin = v.Begin();

    v.Push_Back(1);
    EXPECT_EQ(v.Capacity(), 4);
    EXPECT_EQ(v.Size(), 1);
    EXPECT_EQ(v.Empty(), false);
    EXPECT_EQ(v.Begin(), begin);
    EXPECT_EQ(v.Begin(), &v[0]);

    v.Push_Back(2);
    EXPECT_EQ(v.Capacity(), 4);
    EXPECT_EQ(v.Size(), 2);
    EXPECT_EQ(v.Empty(), false);
    EXPECT_EQ(v.Begin(), begin);
    EXPECT_EQ(v.Begin(), &v[0]);
    EXPECT_EQ(v.Begin() + 1, &v[1]);

    v.Push_Back(3);
    EXPECT_EQ(v.Capacity(), 4);
    EXPECT_EQ(v.Size(), 3);
    EXPECT_EQ(v.Empty(), false);
    EXPECT_EQ(v.Begin(), begin);
    EXPECT_EQ(v.Begin(), &v[0]);
    EXPECT_EQ(v.Begin() + 1, &v[1]);
    EXPECT_EQ(v.Begin() + 2, &v[2]);

    v.Push_Back(4);
    EXPECT_EQ(v.Capacity(), 4);
    EXPECT_EQ(v.Size(), 4);
    EXPECT_EQ(v.Empty(), false);
    EXPECT_EQ(v.Begin(), begin);
    EXPECT_EQ(v.Begin(), &v[0]);
    EXPECT_EQ(v.Begin() + 1, &v[1]);
    EXPECT_EQ(v.Begin() + 2, &v[2]);
    EXPECT_EQ(v.Begin() + 3, &v[3]);
}

#endif

#ifdef RunPopTest

/**
 * @brief Test case for Pop_Back().
 */
TEST(A6Test, PopTest) {
    Vector<int> v;
    v.Push_Back(1);
    v.Push_Back(2);
    v.Push_Back(3);
    v.Push_Back(4);
    v.Push_Back(5);
    EXPECT_EQ(v.Capacity(), 8);
    EXPECT_EQ(v.Size(), 5);
    EXPECT_EQ(v.Empty(), false);

    v.Pop_Back();
    EXPECT_EQ(v.Capacity(), 8);
    EXPECT_EQ(v.Size(), 4);
    EXPECT_EQ(v.Empty(), false);

    v.Pop_Back();
    EXPECT_EQ(v.Capacity(), 8);
    EXPECT_EQ(v.Size(), 3);
    EXPECT_EQ(v.Empty(), false);

    v.Pop_Back();
    EXPECT_EQ(v.Capacity(), 8);
    EXPECT_EQ(v.Size(), 2);
    EXPECT_EQ(v.Empty(), false);

    v.Pop_Back();
    EXPECT_EQ(v.Capacity(), 8);
    EXPECT_EQ(v.Size(), 1);
    EXPECT_EQ(v.Empty(), false);

    v.Pop_Back();
    EXPECT_EQ(v.Capacity(), 8);
    EXPECT_EQ(v.Size(), 0);
    EXPECT_EQ(v.Empty(), true);

    v.Pop_Back();
    EXPECT_EQ(v.Capacity(), 8);
    EXPECT_EQ(v.Size(), 0);
    EXPECT_EQ(v.Empty(), true);

    v.Push_Back(10);
    EXPECT_EQ(v.Capacity(), 8);
    EXPECT_EQ(v.Size(), 1);
    EXPECT_EQ(v.Empty(), false);
}

#endif

#ifdef RunReserveTest

/**
 * @brief Test case for Reserve().
 */
TEST(A6Test, ReserveTest) {
    Vector<int> v;
    EXPECT_EQ(v.Capacity(), 4);
    EXPECT_EQ(v.Size(), 0);
    EXPECT_EQ(v.Empty(), true);

    v.Reserve(2);
    EXPECT_EQ(v.Capacity(), 4);
    EXPECT_EQ(v.Size(), 0);
    EXPECT_EQ(v.Empty(), true);

    v.Push_Back(1);
    v.Push_Back(2);
    v.Push_Back(3);
    v.Push_Back(4);
    v.Push_Back(5);
    EXPECT_EQ(v.Capacity(), 8);
    EXPECT_EQ(v.Size(), 5);
    EXPECT_EQ(v.Empty(), false);
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
    EXPECT_EQ(v[2], 3);
    EXPECT_EQ(v[3], 4);
    EXPECT_EQ(v[4], 5);

    v.Reserve(16);
    EXPECT_EQ(v.Capacity(), 16);
    EXPECT_EQ(v.Size(), 5);
    EXPECT_EQ(v.Empty(), false);
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
    EXPECT_EQ(v[2], 3);
    EXPECT_EQ(v[3], 4);
    EXPECT_EQ(v[4], 5);
}

#endif

#ifdef RunClearTest

/**
 * @brief Test case for Clear().
 */
TEST(A6Test, ClearTest) {
    Vector<int> v;
    v.Push_Back(1);
    v.Push_Back(2);
    v.Push_Back(3);
    v.Push_Back(4);
    v.Push_Back(5);
    EXPECT_EQ(v.Capacity(), 8);
    EXPECT_EQ(v.Size(), 5);
    EXPECT_EQ(v.Empty(), false);

    v.Clear();
    EXPECT_EQ(v.Capacity(), 8);
    EXPECT_EQ(v.Size(), 0);
    EXPECT_EQ(v.Empty(), true);

    v.Clear();
    EXPECT_EQ(v.Capacity(), 8);
    EXPECT_EQ(v.Size(), 0);
    EXPECT_EQ(v.Empty(), true);

    v.Push_Back(10);
    EXPECT_EQ(v.Capacity(), 8);
    EXPECT_EQ(v.Size(), 1);
    EXPECT_EQ(v.Empty(), false);
}

#endif

#ifdef RunIteratorTest

/**
 * @brief Test case for Begin(), End(), and Erase().
 */
TEST(A6Test, IteratorTest) {
    Vector<int> v;
    Vector<int>::iterator it;
    v.Push_Back(1);
    v.Push_Back(2);
    v.Push_Back(3);
    v.Push_Back(4);
    v.Push_Back(5);
    EXPECT_EQ(v.Capacity(), 8);
    EXPECT_EQ(v.Size(), 5);
    EXPECT_EQ(v.Empty(), false);
    EXPECT_EQ(v.Begin() + 5, v.End());

    it = v.Erase(v.Begin() + 1);
    EXPECT_EQ(it, v.Begin() + 1);
    EXPECT_EQ(v.Capacity(), 8);
    EXPECT_EQ(v.Size(), 4);
    EXPECT_EQ(v.Empty(), false);
    EXPECT_EQ(v.Begin() + 4, v.End());
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 3);
    EXPECT_EQ(v[2], 4);
    EXPECT_EQ(v[3], 5);

    it = v.Erase(v.Begin() + 2);
    EXPECT_EQ(it, v.Begin() + 2);
    EXPECT_EQ(v.Capacity(), 8);
    EXPECT_EQ(v.Size(), 3);
    EXPECT_EQ(v.Empty(), false);
    EXPECT_EQ(v.Begin() + 3, v.End());
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 3);
    EXPECT_EQ(v[2], 5);

    it = v.Erase(v.Begin());
    EXPECT_EQ(it, v.Begin());
    EXPECT_EQ(v.Capacity(), 8);
    EXPECT_EQ(v.Size(), 2);
    EXPECT_EQ(v.Empty(), false);
    EXPECT_EQ(v.Begin() + 2, v.End());
    EXPECT_EQ(v[0], 3);
    EXPECT_EQ(v[1], 5);

    it = v.Erase(v.Begin() + 1);
    EXPECT_EQ(it, v.End());
    EXPECT_EQ(v.Capacity(), 8);
    EXPECT_EQ(v.Size(), 1);
    EXPECT_EQ(v.Empty(), false);
    EXPECT_EQ(v.Begin() + 1, v.End());
    EXPECT_EQ(v[0], 3);

    it = v.Erase(v.Begin());
    EXPECT_EQ(v.Begin(), v.End());
    EXPECT_EQ(it, v.End());
    EXPECT_EQ(v.Capacity(), 8);
    EXPECT_EQ(v.Size(), 0);
    EXPECT_EQ(v.Empty(), true);
    EXPECT_EQ(v.Begin(), v.End());
}

#endif

#ifdef RunBracketAtTest

/**
 * @brief Test case for operator[] and At().
 */
TEST(A6Test, BracketAtTest) {
    Vector<int> v;
    const Vector<int> &vRef = v;
    v.Push_Back(1);
    v.Push_Back(2);
    v.Push_Back(3);
    v.Push_Back(4);
    v.Push_Back(5);
    EXPECT_EQ(v.Capacity(), 8);
    EXPECT_EQ(v.Size(), 5);
    EXPECT_EQ(v.Empty(), false);

    v[0] = 10;
    EXPECT_EQ(v[0], 10);
    EXPECT_EQ(v.At(0), 10);

    v.At(0) = 20;
    EXPECT_EQ(v[0], 20);
    EXPECT_EQ(v.At(0), 20);

    EXPECT_EQ(v.Capacity(), 8);
    EXPECT_EQ(v.Size(), 5);
    EXPECT_EQ(v.Empty(), false);

    int n;
    EXPECT_NO_THROW({
        n = vRef[5];
    });
    EXPECT_NO_THROW({
        v[5] = 0;
    });

    EXPECT_THROW({
        n = vRef.At(5);
    }, std::out_of_range);
    EXPECT_THROW({
        v.At(5) = 0;
    }, std::out_of_range);
}

#endif

#ifdef RunCopyConstructorTest

/**
 * @brief Test case for the copy constructor.
 */
TEST(A6Test, CopyConstructorTest) {
    Vector<int> v1;
    v1.Push_Back(1);
    v1.Push_Back(2);
    v1.Push_Back(3);
    v1.Push_Back(4);
    v1.Push_Back(5);
    EXPECT_EQ(v1.Capacity(), 8);
    EXPECT_EQ(v1.Size(), 5);
    EXPECT_EQ(v1.Empty(), false);
    EXPECT_EQ(v1[0], 1);
    EXPECT_EQ(v1[1], 2);
    EXPECT_EQ(v1[2], 3);
    EXPECT_EQ(v1[3], 4);
    EXPECT_EQ(v1[4], 5);

    Vector<int> v2(v1);
    EXPECT_EQ(v2.Capacity(), 8);
    EXPECT_EQ(v2.Size(), 5);
    EXPECT_EQ(v2.Empty(), false);
    EXPECT_EQ(v2[0], 1);
    EXPECT_EQ(v2[1], 2);
    EXPECT_EQ(v2[2], 3);
    EXPECT_EQ(v2[3], 4);
    EXPECT_EQ(v2[4], 5);

    v1.Push_Back(6);
    v2.Push_Back(7);

    EXPECT_EQ(v1.Capacity(), 8);
    EXPECT_EQ(v1.Size(), 6);
    EXPECT_EQ(v1.Empty(), false);
    EXPECT_EQ(v1[5], 6);

    EXPECT_EQ(v2.Capacity(), 8);
    EXPECT_EQ(v2.Size(), 6);
    EXPECT_EQ(v2.Empty(), false);
    EXPECT_EQ(v2[5], 7);
}

#endif

#ifdef RunCopyAssignmentTest

/**
 * @brief Test case for the copy assignment operator.
 */
TEST(A6Test, CopyAssignmentTest) {
    Vector<int> v1;
    v1.Push_Back(1);
    v1.Push_Back(2);
    v1.Push_Back(3);
    v1.Push_Back(4);
    v1.Push_Back(5);
    EXPECT_EQ(v1.Capacity(), 8);
    EXPECT_EQ(v1.Size(), 5);
    EXPECT_EQ(v1.Empty(), false);
    EXPECT_EQ(v1[0], 1);
    EXPECT_EQ(v1[1], 2);
    EXPECT_EQ(v1[2], 3);
    EXPECT_EQ(v1[3], 4);
    EXPECT_EQ(v1[4], 5);

    Vector<int> v2;
    v2 = v1;
    EXPECT_EQ(v2.Capacity(), 8);
    EXPECT_EQ(v2.Size(), 5);
    EXPECT_EQ(v2.Empty(), false);
    EXPECT_EQ(v2[0], 1);
    EXPECT_EQ(v2[1], 2);
    EXPECT_EQ(v2[2], 3);
    EXPECT_EQ(v2[3], 4);
    EXPECT_EQ(v2[4], 5);

    v1.Push_Back(6);
    v2.Push_Back(7);

    EXPECT_EQ(v1.Capacity(), 8);
    EXPECT_EQ(v1.Size(), 6);
    EXPECT_EQ(v1.Empty(), false);
    EXPECT_EQ(v1[5], 6);

    EXPECT_EQ(v2.Capacity(), 8);
    EXPECT_EQ(v2.Size(), 6);
    EXPECT_EQ(v2.Empty(), false);
    EXPECT_EQ(v2[5], 7);
}

#endif

#ifdef RunSelfAssignmentTest

namespace SelfAssignmentTestNamespace {
    bool replaceWithZeros = false;
};

/**
 * @brief Custom delete operator for SelfAssignmentTest.
 *
 * @param ptr A pointer to the memory to be deallocated
 */
void operator delete(void *ptr) throw() {
    if (SelfAssignmentTestNamespace::replaceWithZeros) {
        int *intPtr = (int *)ptr;
        *intPtr = 0;
    }
}

/**
 * @brief Custom delete[] operator for SelfAssignmentTest.
 *
 * @param ptr A pointer to the memory to be deallocated
 */
void operator delete[](void *ptr) throw() {
    if (SelfAssignmentTestNamespace::replaceWithZeros) {
        int *intPtr = (int *)ptr;
        *intPtr = 0;
    }
}

/**
 * @brief Test case for self assignment using the copy assignment operator.
 */
TEST(A6Test, SelfAssignmentTest) {
    Vector<int> v1;
    v1.Push_Back(1);
    v1.Push_Back(2);
    v1.Push_Back(3);
    v1.Push_Back(4);
    v1.Push_Back(5);
    EXPECT_EQ(v1.Capacity(), 8);
    EXPECT_EQ(v1.Size(), 5);
    EXPECT_EQ(v1.Empty(), false);
    EXPECT_EQ(v1[0], 1);
    EXPECT_EQ(v1[1], 2);
    EXPECT_EQ(v1[2], 3);
    EXPECT_EQ(v1[3], 4);
    EXPECT_EQ(v1[4], 5);

    Vector<int> v2;
    v2 = v1;
    EXPECT_EQ(v2.Capacity(), 8);
    EXPECT_EQ(v2.Size(), 5);
    EXPECT_EQ(v2.Empty(), false);
    EXPECT_EQ(v2[0], 1);
    EXPECT_EQ(v2[1], 2);
    EXPECT_EQ(v2[2], 3);
    EXPECT_EQ(v2[3], 4);
    EXPECT_EQ(v2[4], 5);

    SelfAssignmentTestNamespace::replaceWithZeros = true;
    v2 = v2;
    SelfAssignmentTestNamespace::replaceWithZeros = false;
    EXPECT_EQ(v2.Capacity(), 8);
    EXPECT_EQ(v2.Size(), 5);
    EXPECT_EQ(v2.Empty(), false);
    EXPECT_EQ(v2[0], 1);
    EXPECT_EQ(v2[1], 2);
    EXPECT_EQ(v2[2], 3);
    EXPECT_EQ(v2[3], 4);
    EXPECT_EQ(v2[4], 5);
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
