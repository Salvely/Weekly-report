///////////////////////////////////////////////////////////////////////////////
// File Name:      processStudent.hpp
//
// Author:         Gerald
// CS email:       gerald@cs.wisc.edu
//
// Description:    Methods to perform some processing on student objects.
//
// IMPORTANT NOTE: This file should NOT be modified.
///////////////////////////////////////////////////////////////////////////////

#ifndef A3_PROCESSSTUDENT_HPP
#define A3_PROCESSSTUDENT_HPP

#include <fstream>
#include <functional>
#include <vector>

#include "GradStudent.hpp"
#include "UndergradStudent.hpp"

// The maximum number of assignments.
static const int max_assignments = 7;

// The delimiter character in students.txt input file.
static const char dlm = ',';

/**
 * @brief Read students' data from an input file and store them in 2 vectors
 *        based on the type of the student.
 *
 * @param inFile The input file with students' data.
 * @param gstudents Vector of graduate students.
 * @param ugstudents Vector of undergraduate students.
 */
void fillStudents(std::ifstream &inFile,
                  std::vector<GradStudent> &gstudents,
                  std::vector<UndergradStudent> &ugstudents);

/**
 * @brief Prints the details of a group of students.
 *
 * @param students A vector of student references to be printed.
 */
void printStudents(const std::vector<std::reference_wrapper<Student>> &students);

/**
 * @brief Computes the statistics like number of students, mean of total score, and
 *        the sorted list of students in descending order based on their total.
 *
 * @param students A vector of student references for which the statistics needs to computed.
 */
void computeStatistics(std::vector<std::reference_wrapper<Student>> &students);

#endif //A3_PROCESSSTUDENT_HPP
