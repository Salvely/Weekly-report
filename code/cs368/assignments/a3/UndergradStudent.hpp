///////////////////////////////////////////////////////////////////////////////
// File Name:      UndergradStudent.hpp
//
// Author:         Gerald
// CS email:       gerald@cs.wisc.edu
//
// Description:    The header file for the UndergradStudent class.
//
// IMPORTANT NOTE: This file should NOT be modified.
///////////////////////////////////////////////////////////////////////////////

#ifndef A3_UNDERGRADSTUDENT_HPP
#define A3_UNDERGRADSTUDENT_HPP

#include "Student.hpp"

#include <string>
#include <vector>

/**
 * @brief An undergraduate student class.
 */
class UndergradStudent : public Student {
private:
    std::string residenceHall;
    std::string yearInCollege;
    static int numUndergradStudents;

public:
    /**
     * @brief Constructor for an undergraduate student.
     *
     * @param name Undergraduate student's name
     * @param yearOfBirth Undergraduate student's YOB
     * @param assignmentsScore Undergraduate student's assignment scores.
     * @param projectScore Undergraduate student's project score.
     * @param residenceHall Undergraduate student's residence hall.
     * @param yearInCollege Undergraduate student's year in college.
     */
    UndergradStudent(std::string name,
                     int yearOfBirth,
                     const std::vector<double> &assignmentsScore,
                     double projectScore,
                     std::string residenceHall,
                     std::string yearInCollege);

    /**
     * @brief Getter for a student's residence hall.
     *
     * @return The residence hall in which the student resides.
     */
    std::string getResidenceHall();

    /**
     * @brief Getter for a student's year in college.
     *
     * @return The year in college of the student.
     */
    std::string getYearInCollege();

    /**
     * @brief Get the total number of undergraduate students.
     *
     * @return The number of undergraduate students.
     */
    static int getNumStudents();

    virtual void printDetails() override;

    virtual double getTotal() override;

    virtual std::string getGrade() override;
};

#endif //A3_UNDERGRADSTUDENT_HPP
