////////////////////////////////////////////////////////////////////////////////
// File Name:      trim.hpp
//
// Author:         Gerald
// CS email:       gerald@cs.wisc.edu
//
// Description:    The header file for trimming a string.
//
// IMPORTANT NOTE: THIS FILE SHOULD NOT BE MODIFIED.
//
// Code Source: The following 3 functions were originally written by Evan Teran
//              for the following question on stack overflow.
//
// Reference: http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
////////////////////////////////////////////////////////////////////////////////

#ifndef TRIM_H
#define TRIM_H

#include <cctype>
#include <string>

/**
 * @brief Trims the whitespace on the left side of the string.
 *
 * @param s The string to be trimmed.
 *
 * @return The trimmed string without whitespaces.
 */
std::string &ltrim(std::string &s);

/**
 * @brief Trims the whitespace on the right side of the string.
 *
 * @param s The string to be trimmed.
 *
 * @return The trimmed string without whitespaces.
 */
std::string &rtrim(std::string &s);

/**
 * @brief Trims the whitespace on both the sides of the string.
 *
 * @param s The string to be trimmed.
 *
 * @return The trimmed string without whitespaces.
 */
std::string &trim(std::string &s);

#endif //TRIM_H