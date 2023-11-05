///////////////////////////////////////////////////////////////////////////////
// File Name:      GradStudent.hpp
//
// Author:         Gerald
// CS email:       gerald@cs.wisc.edu
//
// Description:    The header file for the GradStudent class.
//
// IMPORTANT NOTE: This file should NOT be modified.
///////////////////////////////////////////////////////////////////////////////

#ifndef A3_GRADSTUDENT_HPP
#define A3_GRADSTUDENT_HPP

#include "Student.hpp"

/**
 * @brief A Graduate Student class.
 */
class GradStudent : public Student {
private:
    std::string researchArea;
    std::string advisor;
    static int numGradStudents;

public:
    /**
     * @brief Constructor for a graduate student.
     *
     * @param name Graduate student's name.
     * @param yearOfBirth Graduate student's YOB.
     * @param assignmentsScore Graduate student's assignment scores.
     * @param projectScore Graduate student's project score.
     * @param researchArea Graduate student's research area.
     * @param advisor Graduate student's advisor.
     */
    GradStudent(std::string name,
                int yearOfBirth,
                const std::vector<double> &assignmentsScore,
                double projectScore,
                std::string researchArea,
                std::string advisor);

    /**
     * @brief Getter for the student's research area.
     *
     * @return The research area of the student.
     */
    std::string getResearchArea();

    /**
     * @brief Getter for the student's advisor.
     *
     * @return The advisor of the student.
     */
    std::string getAdvisor();

    /**
     * @brief Get the total number of graduate students.
     *
     * @return The number of graduate students.
     */
    static int getNumStudents();

    virtual void printDetails() override;

    virtual double getTotal() override;

    virtual std::string getGrade() override;
};

#endif //A3_GRADSTUDENT_HPP
