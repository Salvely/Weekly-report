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

#ifndef HW7_DEQUE_H_
#define HW7_DEQUE_H_

#include <stdbool.h>    // for bool type (true, false)
#include "./rat_num.h"

///////////////////////////////////////////////////////////////////////////////
// A Deque is a Double Ended Queue.
//
// Here we are providing the interface to implement a Deque, with an
// internal implementation of a doubly linked dq.
///////////////////////////////////////////////////////////////////////////////

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Internal structures for our Deque implementation.
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


// A single node within a deque.
//
// A node contains next and prev pointers as well as a customer-supplied
// payload.
typedef struct dq_node_st {
  rat_num         payload;     // customer-supplied payload
  struct dq_node_st *next;     // next node in deque, or NULL
  struct dq_node_st *prev;     // prev node in deque, or NULL
} DequeNode;

// The entire Deque.
// This struct contains metadata about the deque.
typedef struct dq_st {
  int         num_elements;  //  # elements in the list
  DequeNode   *front;  // beginning of deque, or NULL if empty
  DequeNode   *back;  // end of deque, or NULL if empty
} Deque;

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// "Methods" for our Deque implementation.
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// Allocates and returns a pointer to a new Deque.
// It is the Caller's responsibility to at some point call Deque_Free to free
// the associated memory.
//
// Arguments: none.
//
// Returns:
// - the newly-allocated linked list, or NULL on error.
Deque* Deque_Allocate(void);

// Free a Deque that was previously allocated by Deque_Allocate.
//
// Arguments:
// - dq: the deque to free.  It is unsafe to use "dq" after this
//   function returns.
void Deque_Free(Deque *dq);

// Return the number of elements in the deque.
//
// Arguments:
// - dq:  the deque to query.
//
// Returns:
// - deque size.
int Deque_Size(Deque *dq);

// Adds a new element to the front of the Deque.
//
// Arguments:
// - dq: the Deque to push onto.
// - payload: the payload to push to the front
void Deque_Push_Front(Deque *dq, rat_num payload);

// Pop an element from the front of the deque.
//
// Arguments:
// - dq: the Deque to pop from.
// - payload_ptr: a return parameter; on success, the popped node's payload
//   is returned through this parameter.
//
// Returns:
// - false on failure (eg, the deque is empty).
// - true on success.
bool Deque_Pop_Front(Deque *dq, rat_num *payload_ptr);

// Peeks at the element at the front of the deque.
//
// Arguments:
// - dq: the Deque to peek.
// - payload_ptr: a return parameter; on success, the peeked node's payload
//   is returned through this parameter.
//
// Returns:
// - false on failure (eg, the deque is empty).
// - true on success.
bool Deque_Peek_Front(Deque *dq, rat_num *payload_ptr);

// Pushes a new element to the end of the deque.
//
// This is the "end" version of Deque_Push_Front.
//
// Arguments:
// - dq: the Deque to push onto.
// - payload: the payload to push to the end
void Deque_Push_Back(Deque *dq, rat_num payload);

// Pops an element from the end of the deque.
//
// This is the "end" version of Deque_Pop_Front.
//
// Arguments:
// - dq: the Deque to remove from
// - payload_ptr: a return parameter; on success, the popped node's payload
//   is returned through this parameter.
//
// Returns:
// - false: on failure (eg, the deque is empty).
// - true: on success.
bool Deque_Pop_Back(Deque *dq, rat_num* payload_ptr);

// Peeks at the element at the back of the deque.
//
// Arguments:
// - dq: the Deque to peek.
// - payload_ptr: a return parameter; on success, the peeked node's payload
//   is returned through this parameter.
//
// Returns:
// - false on failure (eg, the deque is empty).
// - true on success.
bool Deque_Peek_Back(Deque *dq, rat_num *payload_ptr);

///////////////////////////////////////////////////////////////////////////////
// Deque iterator.
// 
// Deques support the notion of an iterator, similar to Java iterators.
// You use an iterator to navigate back and forth through the deque and
// to insert/remove/access elements from the deque. 
// You use DQIterator_Allocate() to allocate a new DQIterator and
// DQIterator_Free() to free an iterator when you're done with it, similar to
// what was done with the Deque "object"
//
// Similar to Java, there are issues that come up when one is using an iterator
// and then modifies the Deque outside of using the iterator. In this instance,
// if you use any of the Deque_*() function to mutate a deque,
// any iterators you have on that list become undefined (ie, dangerous to use; arbitrary
// memory corruption can occur). Thus, you should not use anue Deque_*()
// functions in between the manufacturing and freeing of an DQIterator.
//

// A Deque iterator.
typedef struct dqiter_st {
  Deque       *deque;  // the deque we're iterating over
  DequeNode   *node;  // the node we are at, or NULL if invalid
} DQIterator;


// Allocate an iterator for a specified Deque. starting at the first node
// in the Deque. Caller is responsible for eventually calling
// DQIterator_Free to free memory associated with the iterator.
//
// Arguments:
// - dq: the Deque we'll make an iterator for.
//
// Returns:
// - a newly-allocated iterator, which may be invalid or "past the end" if
//   the Deque cannot be iterated through (eg, empty).
//   Returns NULL on allocation failure.
DQIterator* DQIterator_Allocate(Deque *dq);

// When you're done with an iterator, you must free it by calling this
// function.
//
// Arguments:
// - iter: the iterator to free. Don't use it after freeing it.
void DQIterator_Free(DQIterator *iter);

// Tests to see whether the iterator is pointing at a valid element.
// Note tha a iterator on the last element of a deque would still be valid.
// An invalid iterator is one that is past the end of the Deque.
//
// Arguments:
// - iter: the iterator to test.
//
// Returns:
// - true: if iter is not past the end of the deque.
// - false: if iter is past the end of the deque.
bool DQIterator_IsValid(DQIterator *iter);

// Advance the iterator, i.e. move to the next node in the deque.  The
// passed-in iterator must be valid (eg, not "past the end").
// Passing in an invalid iterator is undefined behaviour.
//
// Arguments:
// - iter: the iterator.
//
// Returns:
// - true: if the iterator has been advanced to the next node.
// - false: if the iterator is no longer valid after the
//   advancing has completed (eg, it's now "past the end").
bool DQIterator_Next(DQIterator *iter);

// Returns the payload of the node that the iterator currently points
// at.  The passed-in iterator must be valid (eg, not "past the end").
// Passing in an invalid iterator is undefined behaviour.
//
// Arguments:
// - iter: the iterator to fetch the payload from.
// - payload: a "return parameter" through which the payload is returned.
void DQIterator_Get(DQIterator *iter, rat_num *payload);

// Remove the node the iterator is pointing to.  After deletion, the iterator
// may be in one of the following three states:
// - if there was only one element in the list, the iterator is now invalid
//   and cannot be used.  In this case, the caller is recommended to free
//   the now-invalid iterator.
// - if the deleted node had a successor (ie, it was pointing at the end),
//   the iterator is now pointing at the successor.
// - if the deleted node was the end, the iterator is now pointing at the
//    predecessor.
//
// The passed-in iterator must be valid (eg, not "past the end").
// Passing in an invalid iterator is undefined behaviour.
//
// Arguments:
// - iter:  the iterator to delete from.
//
// Returns:
// - true if the deletion succeeded, the deque is still non-empty,
//   and thus the iterator is still valid.
//
// - false if the deletion succeeded, but the deque is now empty.
//   and thus the iterator is now invalid.
bool DQIterator_Remove(DQIterator *iter);

// Rewind an iterator to the front of its deque.
//
// Arguments:
// - iter: the iterator to rewind.
void DQIterator_Rewind(DQIterator *iter);

#endif  // HW7_DEQUE_H_
