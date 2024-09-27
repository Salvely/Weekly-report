///////////////////////////////////////////////////////////////////////////////
// File Name:      main.cpp
//
// Author:         Gerald
// CS email:       gerald@cs.wisc.edu
//
// Description:    The main program for a3.
//
// IMPORTANT NOTE: This file should NOT be modified.
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <functional>
#include <vector>

#include "GradStudent.hpp"
#include "processStudent.hpp"
#include "UndergradStudent.hpp"

/**
 * @brief The program execution begins here.
 * @param argc The number of command-line arguments.
 * @param argv The command line arguments.
 * @return 0 for normal program termination, -1 for abnormal termination.
 */
int main(int argc, char *argv[]) {

    // Check if the program is given command line arguments.
    if (argc != 2) {
        std::cerr << "USAGE: " << argv[0] << " <students.txt>" << std::endl;
        return 1;
    }

    // Open the students.txt input file.
    std::ifstream inFile(argv[1]);
    if (!inFile.is_open()) {
        std::cerr << "Input file " << argv[1] << " cannot be opened!" << std::endl;
        return 1;
    }

    std::vector<GradStudent> gstudents;
    std::vector<UndergradStudent> ugstudents;

    fillStudents(inFile, gstudents, ugstudents);

    std::cout << "The total number of students in the class = "
              << Student::getNumStudents() << std::endl << std::endl;

    // create a vector of references for undergraduate students.
    std::vector<std::reference_wrapper<Student>> ugstudentRefs;
    for (auto it = ugstudents.begin(); it != ugstudents.end(); ++it) {
        ugstudentRefs.push_back(*it);
    }

    std::cout << "UNDERGRADUATE STUDENT INFORMATION" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    printStudents(ugstudentRefs);

    std::cout << "UNDERGRADUATE STUDENT STATISTICS" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    computeStatistics(ugstudentRefs);

    // create a vector of references for graduate students.
    std::vector<std::reference_wrapper<Student>> gstudentRefs;
    for (auto it = gstudents.begin(); it != gstudents.end(); ++it) {
        gstudentRefs.push_back(*it);
    }

    std::cout << "GRADUATE STUDENT INFORMATION" << std::endl;
    std::cout << "----------------------------" << std::endl;
    printStudents(gstudentRefs);

    std::cout << "GRADUATE STUDENT STATISTICS" << std::endl;
    std::cout << "---------------------------" << std::endl;
    computeStatistics(gstudentRefs);

    return 0;
}
