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
#include <stdbool.h>

#include "./test_deque.h"

int main() {

  printf("Deque Basic Test...\t\t");
  if (Test_Deque_Basic()) {
    printf("Passed\n");
  } else {
    printf("Failed\n");
  }

  printf("Deque PushPop Front Test...\t");
  if (Test_Deque_PushPop_Front()) {
    printf("Passed\n");
  } else {
    printf("Failed\n");
  }

  printf("Deque PushPop Back Test...\t");
  if (Test_Deque_PushPop_Back()) {
    printf("Passed\n");
  } else {
    printf("Failed\n");
  }

  printf("Deque Iterator Basic Test...\t");
  if (Test_DQIterator_Basic()) {
    printf("Passed\n");
  } else {
    printf("Failed\n");
  }

}
