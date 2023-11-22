/*
 * Copyright ©2022 Travis McGaha.  All rights reserved.  Permission is
 * hereby granted to students registered for University of Pennsylvania
 * CIS 2400 for use solely during Fall Semester 2022 for purposes of
 * the course.  No other use, copying, distribution, or modification
 * is permitted without prior written consent. Copyrights for
 * third-party components of this work must be honored.  Instructors
 * interested in reusing these course materials should contact the
 * author.
 */

#ifndef HW7_RAT_NUM_H_
#define HW7_RAT_NUM_H_

///////////////////////////////////////////////////////////////////////////////
// rat_num represents a rational number.
// It includes all of the elements in the set of rationals.
// Examples of rat_nums include "-1/13", "53/7", "4/1", and "0/1".
///////////////////////////////////////////////////////////////////////////////

// Represents a rational number
typedef struct rat_num_st {
  int numerator;
  int denominator;
} rat_num;

#endif  // HW7_RAT_NUM_H_
