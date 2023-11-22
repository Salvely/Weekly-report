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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./Deque.h"

#define MAX_LINE_LENGTH 100

// Helper function to find the Greated Common Divisor
//
// If you want to create other helper functions. You should declare it
// at the top of the program first and then implement it below main.
// (similar to how this function is declared and defined)
int gcd(int a, int b);

int main() {
  // be sure to return EXIT_SUCCESS when the program runs successfully
  // and EXIT_FAILURE when the program encounters a fatal runtime error
  // like a malloc error or a STACK ERROR
  return EXIT_SUCCESS;
}

int gcd(int a, int b) {
  // Euclid's method
  if (b == 0) {
    return 0;
  }
  while (b != 0) {
    int tmp = b;
    b = a % b;
    a = tmp;
  }
  return a;
}
