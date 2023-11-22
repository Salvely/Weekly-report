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
#include <ctype.h>

#include "./Deque.h"

#define MAX_LINE_LENGTH 100

int main();

// Helper function to find the Greated Common Divisor
//
// If you want to create other helper functions. You should declare it
// at the top of the program first and then implement it below main.
// (similar to how this function is declared and defined)
int gcd(int a, int b);
bool dispatch_command(Deque *d, char* command);
void lower_string(char *upper_string);

int main() {
  // be sure to return EXIT_SUCCESS when the program runs successfully
  // and EXIT_FAILURE when the program encounters a fatal runtime error
  // like a malloc error or a STACK ERROR
	char input[100];
	Deque* d = Deque_Allocate();
	if(d == NULL) {
		exit(EXIT_FAILURE);
	}
	while (fscanf(stdin, "%s", input))
	{
		lower_string(input);
		bool success = false;
		success = dispatch_command(d, input);
		if(!success) {
			exit(EXIT_FAILURE);
		}
		rat_num result;
		// get the last element in the Deque
		success = Deque_Peek_Back(d, &result);
		if(success) {
			// simplify it
			int num = gcd(result.denominator, result.numerator);
			result.denominator = result.denominator / num;
			result.numerator = result.numerator / num;
			// print it
			printf("%d/%d\n", result.denominator, result.numerator);			
		}

	}
	Deque_Free(d);
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

bool dispatch_command(Deque *d, char *command)
{
	bool success = false;
	if (!strcmp(command, "dup"))
	{
		rat_num num;
		success = Deque_Peek_Back(d, &num);
		if(!success) {
			exit(EXIT_FAILURE);
		}
		Deque_Push_Back(d, num);
		return true;
	}
	else if(!strcmp(command, "swap")) {
		rat_num num1;
		success = Deque_Pop_Back(d, &num1);
		if(!success) {
			exit(EXIT_FAILURE);
		}
		rat_num num2;
		success = Deque_Pop_Back(d, &num2);
		if(!success) {
			exit(EXIT_FAILURE);
		}

		Deque_Push_Back(d, num1);
		Deque_Push_Back(d, num2);
		return true;
	}
	else if(!strcmp(command, "quit")) {
		Deque_Free(d);
		exit(EXIT_SUCCESS);
	}
	else if(!strcmp(command, "drop")) {
		rat_num num;
		Deque_Pop_Back(d, &num);
	}
	else if(!strcmp(command, "clear")) {
		rat_num num;
		while (d->num_elements != 0)
		{
			Deque_Pop_Back(d, &num);
		}
	}
	else 
	{
		char c = command[0];
		if(isdigit(c)) {
			rat_num num;
			num.denominator = atoi(command);
			num.numerator = 1;
			Deque_Push_Back(d, num);
		}
		else {
			rat_num num1;
			success = Deque_Pop_Back(d, &num1);
			if(!success) {
				fprintf(stderr,"STACK ERROR\n");
				Deque_Free(d);
				exit(EXIT_FAILURE);
			}
			rat_num num2;
			success = Deque_Pop_Back(d, &num2);
			if(!success) {
				fprintf(stderr,"STACK ERROR\n");
				Deque_Free(d);
				exit(EXIT_FAILURE);
			}
			
			rat_num sum;

			if(!success) {
				exit(EXIT_FAILURE);
			}
			switch (c)
			{
				case '+':
					{
						sum.numerator = num1.numerator * num2.numerator;
						sum.denominator = num1.denominator * num2.numerator + num2.denominator * num1.numerator;
						Deque_Push_Back(d, sum);
					}
					break;
				case '-':
					{
						sum.numerator = num1.numerator * num2.numerator;
						sum.denominator = num2.denominator * num1.numerator - num1.denominator * num2.numerator;
						Deque_Push_Back(d, sum);
					}
					break;
				case '*':
					{
						sum.numerator = num1.numerator * num2.numerator;
						sum.denominator = num1.denominator * num2.denominator;
						Deque_Push_Back(d, sum);
					}
					break;
				case '/':
					{
						sum.numerator = num1.denominator * num2.numerator;
						sum.denominator = num1.numerator * num2.denominator;
						Deque_Push_Back(d, sum);
					}
					break;
				default:
					break;
			}			
		}

	}
	return true;
}

void lower_string(char *upper_string)
{
	int i = 0;
	while(upper_string[i] != '\0') {
		upper_string[i] = tolower(upper_string[i]);
		i += 1;
	}
}
