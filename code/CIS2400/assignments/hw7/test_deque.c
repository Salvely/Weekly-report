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

#include <stdlib.h>
#include "./Deque.h"

// global constants:
rat_num kOne =   {1, 1};
rat_num kTwo =   {2, 1};
rat_num kThree = {3, 1};
rat_num kFour =  {4, 1};
rat_num kFive =  {5, 1};

#define ASSERT_TRUE(x) if(!(x)) return false  
#define ASSERT_FALSE(x) if(x) return false  
#define ASSERT_EQ(x, y) if((x) != (y)) return false  
#define ASSERT_NE(x, y) if((x) == (y)) return false  
#define ASSERT_EQ_RAT_NUM(x, y) if(((x).numerator != (y).numerator) || \
                                ((x).denominator != (y).denominator)) return false  

bool Test_Deque_Basic() {
  // Try creating a deque.
  Deque* dqp = Deque_Allocate();
  ASSERT_TRUE(dqp != NULL);
  ASSERT_EQ(0, Deque_Size(dqp));
  ASSERT_EQ(NULL, dqp->front);
  ASSERT_EQ(NULL, dqp->back);

  // Try deleting the (empty) deque.
  Deque_Free(dqp);
  dqp = NULL;

  return true;
}

bool Test_Deque_PushPop_Front() {
  // Creating a deque.
  Deque *dqp = Deque_Allocate();
  ASSERT_TRUE(dqp != NULL);
  ASSERT_EQ(0, Deque_Size(dqp));
  ASSERT_EQ(NULL, dqp->front);
  ASSERT_EQ(NULL, dqp->back);

  // Insert an element.
  rat_num payload_ptr;
  Deque_Push_Front(dqp, kOne);
  ASSERT_EQ(1, Deque_Size(dqp));
  ASSERT_EQ(dqp->front, dqp->back);
  ASSERT_EQ(NULL, dqp->front->prev);
  ASSERT_EQ(NULL, dqp->back->next);
  ASSERT_EQ_RAT_NUM(kOne, dqp->front->payload);
  ASSERT_TRUE(Deque_Peek_Front(dqp, &payload_ptr));
  ASSERT_EQ_RAT_NUM(kOne, payload_ptr);

  // Pop the element.
  ASSERT_TRUE(Deque_Pop_Front(dqp, &payload_ptr));
  ASSERT_EQ_RAT_NUM(kOne, payload_ptr);
  ASSERT_EQ(0, Deque_Size(dqp));

  // Try (and fail) to pop the element a second time.
  ASSERT_FALSE(Deque_Peek_Front(dqp, &payload_ptr));
  ASSERT_FALSE(Deque_Pop_Front(dqp, &payload_ptr));
  ASSERT_FALSE(Deque_Peek_Front(dqp, &payload_ptr));

  // Insert two elements.
  Deque_Push_Front(dqp, kOne);
  ASSERT_EQ(1, Deque_Size(dqp));
  ASSERT_EQ(dqp->front, dqp->back);
  ASSERT_EQ(NULL, dqp->front->prev);
  ASSERT_EQ(NULL, dqp->back->next);
  ASSERT_EQ_RAT_NUM(kOne, dqp->front->payload);

  Deque_Push_Front(dqp, kTwo);
  ASSERT_EQ(2, Deque_Size(dqp));
  ASSERT_NE(dqp->front, dqp->back);
  ASSERT_EQ(NULL, dqp->front->prev);
  ASSERT_EQ(NULL, dqp->back->next);
  ASSERT_EQ(dqp->back, dqp->front->next);
  ASSERT_EQ(dqp->front, dqp->back->prev);
  ASSERT_EQ_RAT_NUM(kTwo, dqp->front->payload);
  ASSERT_EQ_RAT_NUM(kOne, dqp->back->payload);
  ASSERT_TRUE(Deque_Peek_Front(dqp, &payload_ptr));
  ASSERT_EQ_RAT_NUM(kTwo, payload_ptr);

  // Pop the first element.
  ASSERT_TRUE(Deque_Pop_Front(dqp, &payload_ptr));
  ASSERT_EQ_RAT_NUM(kTwo, payload_ptr);
  ASSERT_EQ(1, Deque_Size(dqp));
  ASSERT_EQ(dqp->front, dqp->back);
  ASSERT_EQ(NULL, dqp->front->prev);
  ASSERT_EQ(NULL, dqp->back->next);
  ASSERT_EQ_RAT_NUM(kOne, dqp->front->payload);

  // Free the non-empty deque.
  Deque_Free(dqp);
  dqp = NULL;
  return true;
}

bool Test_Deque_PushPop_Back() {
  // Creating a deque.
  Deque *dqp = Deque_Allocate();
  ASSERT_TRUE(dqp != NULL);
  ASSERT_EQ(0, Deque_Size(dqp));
  ASSERT_EQ(NULL, dqp->front);
  ASSERT_EQ(NULL, dqp->back);

  // Insert an element.
  rat_num payload_ptr;
  Deque_Push_Back(dqp, kOne);
  ASSERT_EQ(1, Deque_Size(dqp));
  ASSERT_EQ(dqp->front, dqp->back);
  ASSERT_EQ(NULL, dqp->front->prev);
  ASSERT_EQ(NULL, dqp->back->next);
  ASSERT_EQ_RAT_NUM(kOne, dqp->front->payload);
  ASSERT_TRUE(Deque_Peek_Back(dqp, &payload_ptr));
  ASSERT_EQ_RAT_NUM(kOne, payload_ptr);
  

  // Delete the element.
  ASSERT_TRUE(Deque_Pop_Back(dqp, &payload_ptr));
  ASSERT_EQ_RAT_NUM(kOne, payload_ptr);
  ASSERT_EQ(0, Deque_Size(dqp));
  

  // Delete the element a second time.
  ASSERT_FALSE(Deque_Peek_Back(dqp, &payload_ptr));
  ASSERT_FALSE(Deque_Pop_Back(dqp, &payload_ptr));
  ASSERT_FALSE(Deque_Peek_Back(dqp, &payload_ptr));
  

  // Insert two elements.
  Deque_Push_Back(dqp, kOne);
  ASSERT_EQ(1, Deque_Size(dqp));
  ASSERT_EQ(dqp->front, dqp->back);
  ASSERT_EQ(NULL, dqp->front->prev);
  ASSERT_EQ(NULL, dqp->back->next);
  ASSERT_EQ_RAT_NUM(kOne, dqp->front->payload);

  Deque_Push_Back(dqp, kTwo);
  ASSERT_EQ(2, Deque_Size(dqp));
  ASSERT_NE(dqp->front, dqp->back);
  ASSERT_EQ(NULL, dqp->front->prev);
  ASSERT_EQ(NULL, dqp->back->next);
  ASSERT_EQ(dqp->back, dqp->front->next);
  ASSERT_EQ(dqp->front, dqp->back->prev);
  ASSERT_EQ_RAT_NUM(kOne, dqp->front->payload);
  ASSERT_EQ_RAT_NUM(kTwo, dqp->back->payload);
  ASSERT_TRUE(Deque_Peek_Back(dqp, &payload_ptr));
  ASSERT_EQ_RAT_NUM(kTwo, payload_ptr);
  

  // Delete the first element.
  ASSERT_TRUE(Deque_Pop_Back(dqp, &payload_ptr));
  ASSERT_EQ_RAT_NUM(kTwo, payload_ptr);
  ASSERT_EQ(1, Deque_Size(dqp));
  ASSERT_EQ(dqp->front, dqp->back);
  ASSERT_EQ(NULL, dqp->front->prev);
  ASSERT_EQ(NULL, dqp->back->next);
  ASSERT_EQ_RAT_NUM(kOne, dqp->front->payload);
  

  // Delete the non-empty deque.
  Deque_Free(dqp);
  dqp = NULL;
  return true;
}

bool Test_DQIterator_Basic() {
  // Create a deque.
  Deque *dqp = Deque_Allocate();

  // Add some data to the deque.
  Deque_Push_Back(dqp, kFive);
  Deque_Push_Back(dqp, kFour);
  Deque_Push_Back(dqp, kThree);
  Deque_Push_Back(dqp, kTwo);
  Deque_Push_Back(dqp, kOne);

  // Create the iterator.
  DQIterator *dqi = DQIterator_Allocate(dqp);
  ASSERT_TRUE(dqi != NULL);
  ASSERT_EQ(dqp, dqi->deque);
  ASSERT_EQ(dqp->front, dqi->node);
  

  // Navigate using the iterator.
  rat_num payload;
  DQIterator_Get(dqi, &payload);
  ASSERT_EQ_RAT_NUM(kFive, payload);
  ASSERT_TRUE(DQIterator_Next(dqi));
  DQIterator_Get(dqi, &payload);
  ASSERT_EQ_RAT_NUM(kFour, payload);
  ASSERT_TRUE(DQIterator_Next(dqi));
  DQIterator_Get(dqi, &payload);
  ASSERT_EQ_RAT_NUM(kThree, payload);
  ASSERT_TRUE(DQIterator_Next(dqi));
  DQIterator_Get(dqi, &payload);
  ASSERT_EQ_RAT_NUM(kTwo, payload);
  ASSERT_TRUE(DQIterator_Next(dqi));
  DQIterator_Get(dqi, &payload);
  ASSERT_EQ_RAT_NUM(kOne, payload);
  ASSERT_FALSE(DQIterator_Next(dqi));
  ASSERT_FALSE(DQIterator_IsValid(dqi));
  

  // The deque contains 5 elements; try a delete from the front of the deque.
  DQIterator_Rewind(dqi);
  DequeNode *prev,
    *next = dqi->node->next,
    *nextnext = dqi->node->next->next;
  ASSERT_TRUE(DQIterator_Remove(dqi));
  ASSERT_EQ(next, dqp->front);
  ASSERT_EQ(next, dqi->node);
  ASSERT_EQ(NULL, dqi->node->prev);
  ASSERT_EQ(nextnext, dqi->node->next);
  ASSERT_EQ(4, Deque_Size(dqi->deque));

  DQIterator_Get(dqi, &payload);
  ASSERT_EQ_RAT_NUM(kFour, payload);
  

  // Delete the rest, but move the iterator forward by one to test removing
  // from the middle (ie, the 2nd element).
  ASSERT_TRUE(DQIterator_Next(dqi));
  prev = dqi->node->prev;
  next = dqi->node->next;
  nextnext = dqi->node->next->next;
  ASSERT_TRUE(DQIterator_Remove(dqi));
  ASSERT_EQ(3, Deque_Size(dqi->deque));
  ASSERT_EQ(next, dqi->node);
  ASSERT_EQ(prev, dqi->node->prev);
  ASSERT_EQ(nextnext, dqi->node->next);
  ASSERT_EQ(prev->next, dqi->node);
  ASSERT_EQ(dqi->node, nextnext->prev);

  // We're stidq deleting from the middle (ie, the 2nd element).
  next = dqi->node->next;
  prev = dqi->node->prev;
  ASSERT_TRUE(DQIterator_Remove(dqi));
  ASSERT_EQ(2, Deque_Size(dqi->deque));
  ASSERT_EQ(next, dqi->node);
  ASSERT_EQ(prev, dqi->node->prev);
  ASSERT_EQ(NULL, dqi->node->next);
  ASSERT_EQ(prev->next, dqi->node);

  // This deletes from the back position, since we are at the second element of
  // a two-element deque.
  prev = dqi->node->prev;
  ASSERT_TRUE(DQIterator_Remove(dqi));
  ASSERT_EQ(1, Deque_Size(dqi->deque));
  ASSERT_EQ(NULL, dqi->node->next);
  ASSERT_EQ(prev, dqi->node);
  ASSERT_EQ(NULL, dqi->node->prev);
  ASSERT_EQ(prev, dqp->back);  // edge case found 17sp

  // Remove the remaining node from the deque.
  ASSERT_FALSE(DQIterator_Remove(dqi));
  ASSERT_EQ(0, Deque_Size(dqi->deque));
  ASSERT_EQ(NULL, dqi->node);
  ASSERT_EQ(NULL, dqp->front);
  ASSERT_EQ(NULL, dqp->back);

  // Free the iterator.
  DQIterator_Free(dqi);
  

  // Free the deque.
  Deque_Free(dqp);
  return true;
}

