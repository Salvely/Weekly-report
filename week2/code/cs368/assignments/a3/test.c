///////////////////////////////////////////////////////////////////////////////
// File Name:      test.c
//
// Author:         Varun Naik
// CS email:       vnaik@cs.wisc.edu
//
// Description:    Unit tests for a3. As a reminder, even if you pass all of
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

#include <fstream>

#include "gtest/gtest.h"
#include "GradStudent.hpp"
#include "processStudent.hpp"
#include "UndergradStudent.hpp"

/**
 * @brief Helper function that returns an AssertionResult for ASSERT_OPEN.
 *
 * Do not call this function directly. Call ASSERT_OPEN instead.
 *
 * @param expr0 The first expression passed to ASSERT_OPEN
 * @param inFile See "file" argument for ASSERT_OPEN
 * @return AssertionSuccess() on success or AssertionFailure() on failure
 */
::testing::AssertionResult assertOpen(const std::string &expr0, std::ifstream &inFile) {
    if (inFile.is_open()) {
        return ::testing::AssertionSuccess();
    } else {
        return ::testing::AssertionFailure() << "Expected " << expr0 << " to be open";
    }
}

/**
 * @brief Helper function that returns an AssertionResult for ASSERT_OPEN.
 *
 * Do not call this function directly. Call ASSERT_OPEN instead.
 *
 * @param expr0 The first expression passed to ASSERT_OPEN
 * @param outFile See "file" argument for ASSERT_OPEN
 * @return AssertionSuccess() on success or AssertionFailure() on failure
 */
::testing::AssertionResult assertOpen(const std::string &expr0, std::ofstream &outFile) {
    if (outFile.is_open()) {
        return ::testing::AssertionSuccess();
    } else {
        return ::testing::AssertionFailure() << "Expected " << expr0 << " to be open";
    }
}

/**
 * @brief Raises a fatal failure with the correct line number if file is not
 *        open.
 *
 * @param file The input or output file
 */
#define ASSERT_OPEN(file) \
    ASSERT_PRED_FORMAT1(assertOpen, file)

/**
 * @brief Helper function that returns an AssertionResult for EXPECT_EOF.
 *
 * Do not call this function directly. Call EXPECT_EOF instead.
 *
 * @param expr0 The first expression passed to EXPECT_EOF
 * @param inFile See comment for EXPECT_EOF
 * @return AssertionSuccess() on success or AssertionFailure() on failure
 */
::testing::AssertionResult expectEof(const std::string &expr0, std::istream &inFile) {
    if (inFile.eof()) {
        return ::testing::AssertionSuccess();
    } else {
        return ::testing::AssertionFailure() << "Expected " << expr0 << " to be at EOF";
    }
}

/**
 * @brief Raises a non-fatal failure with the correct line number if inFile has
 *        not reached EOF.
 *
 * @param inFile The input file
 */
#define EXPECT_EOF(inFile) \
    ASSERT_PRED_FORMAT1(expectEof, inFile)

/**
 * @brief Helper function that returns an AssertionResult for ASSERT_NOT_FAILED.
 *
 * Do not call this function directly. Call ASSERT_NOT_FAILED instead.
 *
 * @param expr0 The first expression passed to ASSERT_NOT_FAILED
 * @param outFile See comment for ASSERT_NOT_FAILED
 * @return AssertionSuccess() on success or AssertionFailure() on failure
 */
::testing::AssertionResult assertNotFailed(const std::string &expr0, std::ofstream &outFile) {
    if (outFile.fail()) {
        return ::testing::AssertionFailure()
            << "Expected " << expr0 << " to be in a non-failed state";
    } else {
        return ::testing::AssertionSuccess();
    }
}

/**
 * @brief Raises a fatal failure with the correct line number if outFile is in
 *        a failed state.
 *
 * @param outFile The output file
 */
#define ASSERT_NOT_FAILED(outFile) \
    ASSERT_PRED_FORMAT1(assertNotFailed, outFile)

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
 * @brief A test fixture class for all a3 tests.
 */
class A3Test : public ::testing::Test {
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

/**
 * @brief A dummy subclass of Student for testing purposes.
 *
 * Normally, the implementation of each method would be in a separate file. We
 * put everything in here to be concise - we only want one test file with C++
 * code.
 */
class TestStudent : public Student {
public:
    // Inherit Student constructor
    using Student::Student;

    // Dummy version of getTotal()
    virtual double getTotal() override {
        return 0.0;
    }

    // Dummy version of getGrade()
    virtual std::string getGrade() override {
        return "";
    }
};

/**
 * @brief Test case for Student. Makes sure the Student methods do not crash.
 */
TEST_F(A3Test, BasicStudentTest) {
    // Set up TestStudent object
    TestStudent student(
        "Varun Naik",
        1994,
        { 90.0, 94.0, 95.0, 96.0, 97.0, 98.0, 99.0 },
        100.0
    );

    // Call Student methods
    student.getId();
    student.getName();
    student.getYearOfBirth();
    student.getAge();
    student.getAssignmentsScore();
    student.getProjectScore();

    // Call static methods
    Student::getNumStudents();
}

/**
 * @brief Test case for UndergradStudent. Makes sure the UndergradStudent
 *        methods do not crash.
 */
TEST_F(A3Test, BasicUndergradStudentTest) {
    // Set up UndergradStudent object
    UndergradStudent student(
        "Varun Naik",
        1994,
        { 90.0, 94.0, 95.0, 96.0, 97.0, 98.0, 99.0 },
        100.0,
        "Sellery",
        "Senior"
    );

    // Call Student methods
    student.getId();
    student.getName();
    student.getYearOfBirth();
    student.getAge();
    student.getAssignmentsScore();
    student.getProjectScore();

    // Call UndergradStudent methods
    student.getResidenceHall();
    student.getYearInCollege();
    student.printDetails();
    student.getTotal();
    student.getGrade();

    // Call static methods
    Student::getNumStudents();
    UndergradStudent::getNumStudents();
}

/**
 * @brief Test case for GradStudent. Makes sure the GradStudent methods do not
 *        crash.
 */
TEST_F(A3Test, BasicGradStudentTest) {
    // Set up GradStudent object
    GradStudent student(
        "Varun Naik",
        1994,
        { 90.0, 94.0, 95.0, 96.0, 97.0, 98.0, 99.0 },
        100.0,
        "Databases",
        "Adalbert Gerald Soosai Raj"
    );

    // Call Student methods
    student.getId();
    student.getName();
    student.getYearOfBirth();
    student.getAge();
    student.getAssignmentsScore();
    student.getProjectScore();

    // Call GradStudent methods
    student.getResearchArea();
    student.getAdvisor();
    student.printDetails();
    student.getTotal();
    student.getGrade();

    // Call static methods
    Student::getNumStudents();
    GradStudent::getNumStudents();
}

/**
 * @brief Test case for processStudent.cpp. Makes sure the functions in the
 *        file do not crash. Performs best-effort cleanup of modified files.
 */
TEST_F(A3Test, BasicProcessStudentTest) {
    // Make sure the students file has the correct contents
    std::ofstream outFile("testStudents.txt");
    ASSERT_OPEN(outFile) << "Cannot open testStudents.txt for output";
    outFile << "G,Rex Fernando,1997,57,90,81,96,80,95,78,68,Cryptography,Amit Sahai" << std::endl;
    outFile << "U,Amal Shalini,1993,55,71,71,63,60,78,83,89,Sellery,Senior" << std::endl;
    outFile << "U,Bharathi Sriramulu,1992,66,76,93,66,50,89,69,59,Waters,Sophomore" << std::endl;
    outFile << "G,Soosai Raj,2000,80,91,75,91,93,92,95,97,Teacher Education,Thomas" << std::endl;
    ASSERT_NOT_FAILED(outFile) << "Error writing to testStudents.txt";
    outFile.close();

    // Open the students.txt input file.
    std::ifstream inFile("testStudents.txt");
    ASSERT_OPEN(inFile) << "Cannot open testStudents.txt for input";

    std::vector<GradStudent> gstudents;
    std::vector<UndergradStudent> ugstudents;

    // Call fillStudents()
    fillStudents(inFile, gstudents, ugstudents);
    inFile.close();
    std::remove("testStudents.txt");

    // create a vector of references for undergraduate students.
    std::vector<std::reference_wrapper<Student>> ugstudentRefs;
    for (auto it = ugstudents.begin(); it != ugstudents.end(); ++it) {
        ugstudentRefs.push_back(*it);
    }

    // create a vector of references for graduate students.
    std::vector<std::reference_wrapper<Student>> gstudentRefs;
    for (auto it = gstudents.begin(); it != gstudents.end(); ++it) {
        gstudentRefs.push_back(*it);
    }

    // Call printStudents() and computeStatistics() for undergrads
    printStudents(ugstudentRefs);
    computeStatistics(ugstudentRefs);

    // Call printStudents() and computeStatistics() for grads
    printStudents(gstudentRefs);
    computeStatistics(gstudentRefs);
}

/**
 * @brief Test case for Student. Makes sure the Student methods behave as
 *        desired.
 */
TEST_F(A3Test, AdvancedStudentTest) {
    // Set up TestStudent object
    TestStudent student(
        "Varun Naik",
        1994,
        { 90.0, 94.0, 95.0, 96.0, 97.0, 98.0, 99.0 },
        100.0
    );

    // Call Student methods
    EXPECT_EQ(student.getId(), 1);
    EXPECT_EQ(student.getName(), "Varun Naik");
    EXPECT_EQ(student.getYearOfBirth(), 1994);
    EXPECT_EQ(student.getAge(), 22);
    const std::vector<double> assignmentsScore = { 90.0, 94.0, 95.0, 96.0, 97.0, 98.0, 99.0 };
    EXPECT_EQ(student.getAssignmentsScore(), assignmentsScore);
    EXPECT_EQ(student.getProjectScore(), 100.0);

    // Call static methods
    EXPECT_EQ(Student::getNumStudents(), 1);

    MATCH_END(buff);
    clearBuff(buff);
}

/**
 * @brief Test case for UndergradStudent. Makes sure the UndergradStudent
 *        methods behave as desired.
 */
TEST_F(A3Test, AdvancedUndergradStudentTest) {
    // Set up UndergradStudent object
    UndergradStudent student(
        "Varun Naik",
        1994,
        { 90.0, 94.0, 95.0, 96.0, 97.0, 98.0, 99.0 },
        100.0,
        "Sellery",
        "Senior"
    );

    // Call Student methods
    EXPECT_EQ(student.getId(), 1);
    EXPECT_EQ(student.getName(), "Varun Naik");
    EXPECT_EQ(student.getYearOfBirth(), 1994);
    EXPECT_EQ(student.getAge(), 22);
    const std::vector<double> assignmentsScore = { 90.0, 94.0, 95.0, 96.0, 97.0, 98.0, 99.0 };
    EXPECT_EQ(student.getAssignmentsScore(), assignmentsScore);
    EXPECT_EQ(student.getProjectScore(), 100.0);

    // Call UndergradStudent methods
    EXPECT_EQ(student.getResidenceHall(), "Sellery");
    EXPECT_EQ(student.getYearInCollege(), "Senior");

    MATCH_END(buff);
    clearBuff(buff);

    student.printDetails();
    MATCH_NEXT_LINE(buff, "STUDENT DETAILS:");
    MATCH_NEXT_LINE(buff, "Id = 1");
    MATCH_NEXT_LINE(buff, "Name = Varun Naik");
    MATCH_NEXT_LINE(buff, "Age = 22");
    MATCH_NEXT_LINE(buff, "Assignments = [90, 94, 95, 96, 97, 98, 99]");
    MATCH_NEXT_LINE(buff, "Project = 100");
    MATCH_NEXT_LINE(buff, "Total = 96.9");
    MATCH_NEXT_LINE(buff, "Grade = CR");
    MATCH_NEXT_LINE(buff, "Type = Undergraduate Student");
    MATCH_NEXT_LINE(buff, "Residence Hall = Sellery");
    MATCH_NEXT_LINE(buff, "Year in College = Senior");
    MATCH_END(buff);
    clearBuff(buff);

    EXPECT_NEAR(student.getTotal(), 96.9, 0.000001);
    EXPECT_EQ(student.getGrade(), "CR");

    // Call static methods
    EXPECT_EQ(Student::getNumStudents(), 1);
    EXPECT_EQ(UndergradStudent::getNumStudents(), 1);

    MATCH_END(buff);
    clearBuff(buff);
}

/**
 * @brief Test case for GradStudent. Makes sure the GradStudent methods behave
 *        as desired.
 */
TEST_F(A3Test, AdvancedGradStudentTest) {
    // Set up GradStudent object
    GradStudent student(
        "Varun Naik",
        1994,
        { 90.0, 94.0, 95.0, 96.0, 97.0, 98.0, 99.0 },
        100.0,
        "Databases",
        "Adalbert Gerald Soosai Raj"
    );

    // Call Student methods
    EXPECT_EQ(student.getId(), 1);
    EXPECT_EQ(student.getName(), "Varun Naik");
    EXPECT_EQ(student.getYearOfBirth(), 1994);
    EXPECT_EQ(student.getAge(), 22);
    const std::vector<double> assignmentsScore = { 90.0, 94.0, 95.0, 96.0, 97.0, 98.0, 99.0 };
    EXPECT_EQ(student.getAssignmentsScore(), assignmentsScore);
    EXPECT_EQ(student.getProjectScore(), 100.0);

    // Call GradStudent methods
    EXPECT_EQ(student.getResearchArea(), "Databases");
    EXPECT_EQ(student.getAdvisor(), "Adalbert Gerald Soosai Raj");

    MATCH_END(buff);
    clearBuff(buff);

    student.printDetails();
    MATCH_NEXT_LINE(buff, "STUDENT DETAILS:");
    MATCH_NEXT_LINE(buff, "Id = 1");
    MATCH_NEXT_LINE(buff, "Name = Varun Naik");
    MATCH_NEXT_LINE(buff, "Age = 22");
    MATCH_NEXT_LINE(buff, "Assignments = [90, 94, 95, 96, 97, 98, 99]");
    MATCH_NEXT_LINE(buff, "Project = 100");
    MATCH_NEXT_LINE(buff, "Total = 97.7857");
    MATCH_NEXT_LINE(buff, "Grade = CR");
    MATCH_NEXT_LINE(buff, "Type = Graduate Student");
    MATCH_NEXT_LINE(buff, "Research Area = Databases");
    MATCH_NEXT_LINE(buff, "Advisor = Adalbert Gerald Soosai Raj");
    MATCH_END(buff);
    clearBuff(buff);

    EXPECT_NEAR(student.getTotal(), 97.7857142857, 0.000001);
    EXPECT_EQ(student.getGrade(), "CR");

    // Call static methods
    EXPECT_EQ(Student::getNumStudents(), 1);
    EXPECT_EQ(GradStudent::getNumStudents(), 1);

    MATCH_END(buff);
    clearBuff(buff);
}

/**
 * @brief Test case for processStudent.cpp. Makes sure the functions in the
 *        file behave as desired. Performs best-effort cleanup of modified files.
 */
TEST_F(A3Test, AdvancedProcessStudentTest) {
    // Make sure the students file has the correct contents
    std::ofstream outFile("testStudents.txt");
    ASSERT_OPEN(outFile) << "Cannot open testStudents.txt for output";
    outFile << "G,Rex Fernando,1997,57,90,81,96,80,95,78,68,Cryptography,Amit Sahai" << std::endl;
    outFile << "U,Amal Shalini,1993,55,71,71,63,60,78,83,89,Sellery,Senior" << std::endl;
    outFile << "U,Bharathi Sriramulu,1992,66,76,93,66,50,89,69,59,Waters,Sophomore" << std::endl;
    outFile << "G,Soosai Raj,2000,80,91,75,91,93,92,95,97,Teacher Education,Thomas" << std::endl;
    ASSERT_NOT_FAILED(outFile) << "Error writing to testStudents.txt";
    outFile.close();

    // Open the students.txt input file.
    std::ifstream inFile("testStudents.txt");
    ASSERT_OPEN(inFile) << "Cannot open testStudents.txt for input";

    std::vector<GradStudent> gstudents;
    std::vector<UndergradStudent> ugstudents;

    // Call fillStudents()
    fillStudents(inFile, gstudents, ugstudents);
    EXPECT_EQ(Student::getNumStudents(), 4);
    EXPECT_EQ(UndergradStudent::getNumStudents(), 2);
    EXPECT_EQ(GradStudent::getNumStudents(), 2);
    EXPECT_EOF(inFile) << "fillStudents() does not read all lines in inFile";
    inFile.close();
    std::remove("testStudents.txt");

    // create a vector of references for undergraduate students.
    std::vector<std::reference_wrapper<Student>> ugstudentRefs;
    for (auto it = ugstudents.begin(); it != ugstudents.end(); ++it) {
        ugstudentRefs.push_back(*it);
    }

    // create a vector of references for graduate students.
    std::vector<std::reference_wrapper<Student>> gstudentRefs;
    for (auto it = gstudents.begin(); it != gstudents.end(); ++it) {
        gstudentRefs.push_back(*it);
    }

    MATCH_END(buff);
    clearBuff(buff);

    // Call printStudents() and computeStatistics() for undergrads
    printStudents(ugstudentRefs);
    MATCH_NEXT_LINE(buff, "STUDENT DETAILS:");
    MATCH_NEXT_LINE(buff, "Id = 2");
    MATCH_NEXT_LINE(buff, "Name = Amal Shalini");
    MATCH_NEXT_LINE(buff, "Age = 23");
    MATCH_NEXT_LINE(buff, "Assignments = [55, 71, 71, 63, 60, 78, 83]");
    MATCH_NEXT_LINE(buff, "Project = 89");
    MATCH_NEXT_LINE(buff, "Total = 74.8");
    MATCH_NEXT_LINE(buff, "Grade = CR");
    MATCH_NEXT_LINE(buff, "Type = Undergraduate Student");
    MATCH_NEXT_LINE(buff, "Residence Hall = Sellery");
    MATCH_NEXT_LINE(buff, "Year in College = Senior");
    MATCH_NEXT_LINE(buff, "");
    MATCH_NEXT_LINE(buff, "STUDENT DETAILS:");
    MATCH_NEXT_LINE(buff, "Id = 3");
    MATCH_NEXT_LINE(buff, "Name = Bharathi Sriramulu");
    MATCH_NEXT_LINE(buff, "Age = 24");
    MATCH_NEXT_LINE(buff, "Assignments = [66, 76, 93, 66, 50, 89, 69]");
    MATCH_NEXT_LINE(buff, "Project = 59");
    MATCH_NEXT_LINE(buff, "Total = 68.6");
    MATCH_NEXT_LINE(buff, "Grade = N");
    MATCH_NEXT_LINE(buff, "Type = Undergraduate Student");
    MATCH_NEXT_LINE(buff, "Residence Hall = Waters");
    MATCH_NEXT_LINE(buff, "Year in College = Sophomore");
    MATCH_NEXT_LINE(buff, "");
    MATCH_END(buff);
    clearBuff(buff);

    computeStatistics(ugstudentRefs);
    MATCH_NEXT_LINE(buff, "Number of students = 2");
    MATCH_NEXT_LINE(buff, "The mean of the total score = 71.7");
    MATCH_NEXT_LINE(buff,
        "The sorted list of students (id, name, total, grade) in descending order of total:");
    MATCH_NEXT_LINE(buff, "2, Amal Shalini, 74.8, CR");
    MATCH_NEXT_LINE(buff, "3, Bharathi Sriramulu, 68.6, N");
    MATCH_NEXT_LINE(buff, "");
    MATCH_END(buff);
    clearBuff(buff);
    EXPECT_EQ(ugstudentRefs.size(), 2);
    int uid0 = ugstudentRefs[0].get().getId();
    int uid1 = ugstudentRefs[1].get().getId();
    ASSERT_TRUE(uid0 == 2 and uid1 == 3)
        << "ugstudentRefs is not sorted in decreasing order by total";

    // Call printStudents() and computeStatistics() for grads
    printStudents(gstudentRefs);
    MATCH_NEXT_LINE(buff, "STUDENT DETAILS:");
    MATCH_NEXT_LINE(buff, "Id = 1");
    MATCH_NEXT_LINE(buff, "Name = Rex Fernando");
    MATCH_NEXT_LINE(buff, "Age = 19");
    MATCH_NEXT_LINE(buff, "Assignments = [57, 90, 81, 96, 80, 95, 78]");
    MATCH_NEXT_LINE(buff, "Project = 68");
    MATCH_NEXT_LINE(buff, "Total = 75.2143");
    MATCH_NEXT_LINE(buff, "Grade = N");
    MATCH_NEXT_LINE(buff, "Type = Graduate Student");
    MATCH_NEXT_LINE(buff, "Research Area = Cryptography");
    MATCH_NEXT_LINE(buff, "Advisor = Amit Sahai");
    MATCH_NEXT_LINE(buff, "");
    MATCH_NEXT_LINE(buff, "STUDENT DETAILS:");
    MATCH_NEXT_LINE(buff, "Id = 4");
    MATCH_NEXT_LINE(buff, "Name = Soosai Raj");
    MATCH_NEXT_LINE(buff, "Age = 16");
    MATCH_NEXT_LINE(buff, "Assignments = [80, 91, 75, 91, 93, 92, 95]");
    MATCH_NEXT_LINE(buff, "Project = 97");
    MATCH_NEXT_LINE(buff, "Total = 92.5714");
    MATCH_NEXT_LINE(buff, "Grade = CR");
    MATCH_NEXT_LINE(buff, "Type = Graduate Student");
    MATCH_NEXT_LINE(buff, "Research Area = Teacher Education");
    MATCH_NEXT_LINE(buff, "Advisor = Thomas");
    MATCH_NEXT_LINE(buff, "");
    MATCH_END(buff);
    clearBuff(buff);

    computeStatistics(gstudentRefs);
    MATCH_NEXT_LINE(buff, "Number of students = 2");
    MATCH_NEXT_LINE(buff, "The mean of the total score = 83.8929");
    MATCH_NEXT_LINE(buff,
        "The sorted list of students (id, name, total, grade) in descending order of total:");
    MATCH_NEXT_LINE(buff, "4, Soosai Raj, 92.5714, CR");
    MATCH_NEXT_LINE(buff, "1, Rex Fernando, 75.2143, N");
    MATCH_NEXT_LINE(buff, "");
    MATCH_END(buff);
    clearBuff(buff);
    EXPECT_EQ(gstudentRefs.size(), 2);
    int gid0 = gstudentRefs[0].get().getId();
    int gid1 = gstudentRefs[1].get().getId();
    ASSERT_TRUE(gid0 == 4 and gid1 == 1)
        << "gstudentRefs is not sorted in decreasing order by total";
}

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
