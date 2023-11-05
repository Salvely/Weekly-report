////////////////////////////////////////////////////////////////////////////////
// File Name:      a2.hpp
//
// Author:         Gerald
// CS email:       gerald@cs.wisc.edu
//
// Description:    The header file for a2.
//
// IMPORTANT NOTE: THIS FILE SHOULD NOT BE MODIFIED.
////////////////////////////////////////////////////////////////////////////////

// Include Guard
// See: https://en.wikipedia.org/wiki/Include_guard
#ifndef A2_HPP
#define A2_HPP

#include <fstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// The rating associated with a neutral review.
static const double neutral_rating = 2.00;

/**
 * @brief Cleans the review data by removing punctuations and stopwords.
 *
 * @param inFile The input file with the raw review data.
 * @param outFile The output file where the clean review data is written.
 * @param stopwords A set of stopwords to be removed from the raw review data.
 */
void cleanData(std::ifstream &inFile, std::ofstream &outFile,
               std::unordered_set<std::string> &stopwords);

/**
 * @brief Reads the reviews and ratings from the file and creates a map from
 *        each word to a pair consisting of the total rating for this word and
 *        the total number of times this word has occurred in the reviews.
 *
 * @param file The file with the review data.
 * @param dict The map/dictionary that we are creating
 *             for each word in the review.
 */
void fillDictionary(std::ifstream &file,
                    std::unordered_map<std::string, std::pair<long, long>> &dict);

/**
 * @brief Read the stop words from a file and store them in a set.
 *
 * @param inFile The file with the stopwords.
 * @param stopwords The set to store the stopwords.
 */
void fillStopWords(std::ifstream &inFile,
                   std::unordered_set<std::string> &stopwords);

/**
 * @brief Read the reviews from a file and give a rating for each review.
 *
 * @param testFile The input file that contains the reviews to be rated.
 * @param dict The map/dictionary that we use to rate the reviews.
 * @param ratingsFile The output file into which we write our ratings
 *                    for each review.
 */
void rateReviews(std::ifstream &testFile,
                 std::unordered_map<std::string, std::pair<long, long>> &dict,
                 std::ofstream &ratingsFile);

/**
 * @brief Remove the empty words.
 *
 * @param tokens The list of words among which some may be empty.
 */
void removeEmptyWords(std::vector<std::string> &tokens);

/**
 * @brief Removes the punctuations from a vector of strings.
 *
 * @param in The input vector of strings with punctuations.
 * @param out The output vector of strings without punctuations.
 */
void removePunctuation(std::vector<std::string> &in,
                       std::vector<std::string> &out);

/**
 * @brief Removes the words with only one letter (e.g. 'A', 's').
 *        This method should NOT remove numbers (e.g. 3) since we want
 *        to keep the ratings along with each review.
 *
 * @param in The vector of strings which may contain single-lettered words.
 */
void removeSingleLetterWords(std::vector<std::string> &in);

/**
 * @brief Removes the stopwords from a vector of strings.
 *
 * @param tokens The vector of strings which may contain stopwords.
 * @param stopwords The set of stopwords that'll be removed from the vector.
 */
void removeStopWords(std::vector<std::string> &tokens,
                     std::unordered_set<std::string> &stopwords);

/**
 * @brief Removes whitespace characters like space (' ') and newline ('\n').
 *        See: http://en.cppreference.com/w/cpp/string/byte/isspace for a
 *        complete list of whitespace characters.
 *
 * @param tokens The words which may contain whitespace characters.
 */
void removeWhiteSpaces(std::vector<std::string> &tokens);

/**
 * @brief Replaces hyphens in a string with spaces.
 *
 * @example "awe-inspiring" becomes "awe inspiring"
 *
 * @param line The string that may contain hyphens.
 */
void replaceHyphensWithSpaces(std::string &line);

/**
 * @brief Splits a line of text into a vector of strings
 *        using the whitespace as the delimiter.
 *
 * @param line The input line of text to be split into multiple words.
 * @param tokens The vector which holds the strings after the line is split.
 */
void splitLine(std::string &line, std::vector<std::string> &tokens);

#endif //A2_HPP
