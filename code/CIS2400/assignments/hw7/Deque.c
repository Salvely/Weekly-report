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

// #include <cstddef>
// #include <cstddef>
#include <stdio.h>
#include <stdlib.h>

#include "Deque.h"


///////////////////////////////////////////////////////////////////////////////
// Deque implementation.

Deque* Deque_Allocate() {
	Deque *d = (Deque *)malloc(sizeof(Deque));
	d->back = NULL;
	d->front = NULL;
	d->num_elements = 0;
	return d;
}

void Deque_Free(Deque *dq)
{
	DequeNode *ptr = dq->front;
	while(ptr != NULL) {
		DequeNode *current = ptr;
		ptr = ptr->next;
		free(current);
		dq->num_elements -= 1;
	}
	free(dq);
}

int Deque_Size(Deque *dq)
{
    return dq->num_elements;
}

void Deque_Push_Front(Deque *dq, rat_num payload)
{
	DequeNode *new_node = (DequeNode *)malloc(sizeof(DequeNode));
	new_node->payload = payload;

	new_node->prev = NULL;
	new_node->next = dq->front;
	if(dq->front != NULL) {
		dq->front->prev = new_node;
	} else {
		dq->back = new_node;
	}
	dq->front = new_node;
	dq->num_elements += 1;
}

bool Deque_Pop_Front(Deque *dq, rat_num *payload_ptr)
{
	if(Deque_Size(dq) == 0) {
		return false;
	}
	DequeNode *node = dq->front;
	dq->front = dq->front->next;
	if(dq->front != NULL)
		dq->front->prev = NULL;
	dq->num_elements -= 1;

	payload_ptr->denominator = node->payload.denominator;
	payload_ptr->numerator = node->payload.numerator;
	free(node);
	return true;
}

bool Deque_Peek_Front(Deque *dq, rat_num *payload_ptr)
{
	if(Deque_Size(dq) == 0) {
		return false;
	}
	DequeNode *node = dq->front;
	payload_ptr->denominator = node->payload.denominator;
	payload_ptr->numerator = node->payload.numerator;
	return true;
}

void Deque_Push_Back(Deque *dq, rat_num payload)
{
	DequeNode *node = (DequeNode *)malloc(sizeof(DequeNode));
	node->payload = payload;
	node->prev = dq->back;
	if(node->prev != NULL) {
		node->prev->next = node;
	} else {
		dq->front = node;
	}
	node->next = NULL;
	dq->back = node;
	dq->num_elements += 1;
}

bool Deque_Pop_Back(Deque *dq, rat_num *payload_ptr)
{
	if(Deque_Size(dq) == 0) {
		return false;
	}
	DequeNode *node = dq->back;
	dq->back = dq->back->prev;
	if(dq->back != NULL)
		dq->back->next = NULL;
	dq->num_elements -= 1;
	payload_ptr->denominator = node->payload.denominator;
	payload_ptr->numerator = node->payload.numerator;
	free(node);
	return true;
}

bool Deque_Peek_Back(Deque *dq, rat_num *payload_ptr)
{
    if(Deque_Size(dq) == 0) {
		return false;
	}
	DequeNode *node = dq->back;
	payload_ptr->denominator = node->payload.denominator;
	payload_ptr->numerator = node->payload.numerator;
	return true;
}

// TODO: The rest of the Deque functions described in Deque.h

///////////////////////////////////////////////////////////////////////////////
// DQIterator implementation.

DQIterator* DQIterator_Allocate(Deque *dq) {
  // TODO: The rest of this function
	DQIterator *iter = (DQIterator *)malloc(sizeof(DQIterator));
	iter->deque = dq;
	iter->node = dq->front;
	return iter;
}

void DQIterator_Free(DQIterator *iter)
{
	free(iter);
}

bool DQIterator_IsValid(DQIterator *iter)
{
	return (iter->node != NULL);
}

bool DQIterator_Next(DQIterator *iter)
{
	iter->node = iter->node->next;
	return DQIterator_IsValid(iter);
}

void DQIterator_Get(DQIterator *iter, rat_num *payload)
{
	if(!DQIterator_IsValid(iter)) {
		return;
	}
	DequeNode *node = iter->node;
	payload->denominator = node->payload.denominator;
	payload->numerator = node->payload.numerator;
}

bool DQIterator_Remove(DQIterator *iter)
{
	if(!DQIterator_IsValid(iter)) {
		return false;
	}
	DequeNode *node = iter->node;

	if(node->next == NULL && node->prev == NULL) {
		iter->node = NULL;
		iter->deque->front = NULL;
		iter->deque->back = NULL;
		node->prev = NULL;
		node->next = NULL;
		iter->deque->num_elements -= 1;
		free(node);
		return false;
	}
	else {
		if(node->next != NULL) {
			node->next->prev = node->prev;
		}
		else {
			iter->deque->back = node->prev;
			node->prev->next = NULL;
		}

		if(node->prev != NULL) {
			node->prev->next = node->next;
		}
		else {
			iter->deque->front = node->next;
			iter->deque->front->prev = NULL;
		}
		iter->node = node->next;	
	}

	if(iter->node == NULL) {
		iter->node = node->prev;
	}
	free(node);
	iter->deque->num_elements -= 1;
	return true;
}

void DQIterator_Rewind(DQIterator *iter)
{
	iter->node = iter->deque->front;
}

// TODO: The rest of the DQIterator functions described in Deque.h
