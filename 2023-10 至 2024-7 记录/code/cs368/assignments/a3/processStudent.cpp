///////////////////////////////////////////////////////////////////////////////
// File Name:      processStudent.cpp
//
// Author:         <your name>
// CS email:       <your CS email>
//
// Description:    Methods to perform some processing on student objects.
///////////////////////////////////////////////////////////////////////////////

#include "processStudent.hpp"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>


void fillStudents(std::ifstream &inFile,
                  std::vector<GradStudent> &gstudents,
                  std::vector<UndergradStudent> &ugstudents) {

    // TODO: Implement this method.

}

void printStudents(const std::vector<std::reference_wrapper<Student>> &students) {

    // TODO: Implement this method.

}

void computeStatistics(std::vector<std::reference_wrapper<Student>> &students) {

    // TODO: Implement this method.

    // compute the # of students based on the type of students.

    // compute the mean of the total score.

    // sort and print the students based on their total.
}

