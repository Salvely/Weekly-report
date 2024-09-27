///////////////////////////////////////////////////////////////////////////////
// File Name:      main.cpp
//
// Author:         Varun Naik
// CS email:       vnaik@cs.wisc.edu
//
// Description:    Unit tests for a2. As a reminder, even if you pass all of
//                 these tests, you are not yet guaranteed 90/90 on the
//                 autograder portion. But if you do not pass these tests, you
//                 will probably receive a very low score on the autograder.
//                 We named this file test.c rather than test.cpp so that you
//                 can still compile your code with `g++ -std=c++11 *.cpp`.
//
// Sources:        Google Test
//
// URL(s) of sources: https://github.com/google/googletest
///////////////////////////////////////////////////////////////////////////////

#include "a2.hpp"
#include "gtest/gtest.h"
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <regex>

/**
 * @brief Raises a fatal failure if inFile is not open
 *
 * @param inFile The input file
 * @param msg The message to print on failure
 */
void assertOpen(std::ifstream &inFile, const std::string &msg) {
    ASSERT_TRUE(inFile.is_open()) << msg;
}

/**
 * @brief Raises a fatal failure if outFile is not open
 *
 * @param outFile The output file
 * @param msg The message to print on failure
 */
void assertOpen(std::ofstream &outFile, const std::string &msg) {
    ASSERT_TRUE(outFile.is_open()) << msg;
}

/**
 * @brief Raises a non-fatal failure if inFile has not reached EOF
 *
 * @param inFile The input file
 * @param msg The message to print on failure
 */
void expectEof(std::ifstream &inFile, const std::string &msg) {
    EXPECT_TRUE(inFile.eof()) << msg;
}

/**
 * @brief Raises a fatal failure if outFile is in a failed state
 *
 * @param outFile The output file
 * @param msg The message to print on failure
 */
void assertNotFailed(std::ofstream &outFile, const std::string &msg) {
    ASSERT_TRUE(!outFile.fail()) << msg;
}

/**
 * @brief Reads the next line from inFile and checks that it matches the pattern.
 *        Raises a non-fatal failure if we have reached the end of file, or if
 *        the pattern does not match.
 *
 * Uses regular expressions to check if the next line is approximately correct.
 * The grammar is described at http://en.cppreference.com/w/cpp/regex/ecmascript.
 * In short:
 *     * matches 0 or more occurrences of the previous character
 *     + matches 1 or more occurrences of the previous character
 *     ? matches 0 or 1 occurrences of the previous character
 *
 * @param inFile The input file from which we read the next line
 * @param pattern The regular expression pattern to match
 */
void matchNextLine(std::ifstream &inFile, const std::string &pattern) {
    std::string line;
    std::getline(inFile, line);
    if (inFile.eof()) {
        ADD_FAILURE()
            << "No more lines in file, cannot match pattern \"" << pattern << "\"";
    } else {
        std::regex reg(pattern);
        EXPECT_TRUE(std::regex_match(line, reg))
            << "line \"" << line << "\" does not match pattern \"" << pattern << "\"";
    }
}

/**
 * @brief Reads the next line from inFile and checks that EOF has been reached.
 *        Raises a non-fatal failure otherwise.
 *
 * @param inFile The input file from which we read the next line
 */
void matchEof(std::ifstream &inFile) {
    std::string line;
    getline(inFile, line);
    EXPECT_TRUE(inFile.eof())
        << "Expected end of file, got line \"" << line << "\"";
}

/**
 * @brief Checks whether word maps to a pair (n1, n2) in dictionary. Raises a
 *        non-fatal failure otherwise.
 *
 * @param dictionary The dictionary passed to fillDictionary()
 * @param word The word to find in the dictionary
 * @param n1 The first number in the pair
 * @param n2 The second number in the pair
 */
void checkDictionaryPair(std::unordered_map<std::string, std::pair<long, long>> &dictionary,
                         const std::string &word,
                         long n1,
                         long n2) {
    auto search = dictionary.find(word);
    if (search == dictionary.end()) {
        ADD_FAILURE() << "\"" << word << "\" not in dictionary";
    } else {
        std::pair<long, long> pair0 = search->second;
        std::pair<long, long> pair1 = std::make_pair(n1, n2);
        EXPECT_EQ(pair0, pair1)
            << "\"" << word << "\" maps to "
            << "(" << pair0.first << ", " << pair0.second << ")"
            << ", when it should map to "
            << "(" << n1 << ", " << n2 << ")";
    }
}

/**
 * @brief Checks a mapping from word to a pair (n1, n2) in dictionary.
 *
 * @param dictionary The dictionary passed to fillDictionary()
 * @param word The word to add to the dictionary
 * @param n1 The first number in the pair
 * @param n2 The second number in the pair
 */
void addDictionaryPair(std::unordered_map<std::string, std::pair<long, long>> &dictionary,
                         const std::string &word,
                         long n1,
                         long n2) {
    std::pair<long, long> pair = std::make_pair(n1, n2);
    dictionary.emplace(word, pair);
}

/**
 * @brief Test case for cleanData(). Performs best-effort cleanup of modified files.
 */
TEST(A2Test, CleanData) {
    // Set up parameters for function call
    std::ifstream rawReviewRatingsInputFile("rawReviewRatings.txt");
    assertOpen(rawReviewRatingsInputFile, "Cannot open rawReviewRatings.txt for input");

    std::ofstream cleanReviewRatingsOutputFile("testCleanReviewRatings.txt");
    assertOpen(cleanReviewRatingsOutputFile, "Cannot open testCleanReviewRatings.txt for output");

    std::unordered_set<std::string> stopwords;
    stopwords.insert("and");
    stopwords.insert("is");
    stopwords.insert("the");

    // Call cleanData() from a2.cpp
    cleanData(rawReviewRatingsInputFile, cleanReviewRatingsOutputFile, stopwords);

    // Check state of files
    assertOpen(rawReviewRatingsInputFile, "cleanData() should not close inFile");
    expectEof(rawReviewRatingsInputFile, "cleanData() does not read all lines in inFile");
    rawReviewRatingsInputFile.close();
    assertOpen(cleanReviewRatingsOutputFile, "cleanData() should not close outFile");
    cleanReviewRatingsOutputFile.close();

    std::ifstream cleanReviewRatingsInputFile("testCleanReviewRatings.txt");
    assertOpen(cleanReviewRatingsInputFile, "Cannot open testCleanReviewRatings.txt for input");

    // Check contents of file
    matchNextLine(cleanReviewRatingsInputFile, "4 The Jungle Book awesome *");
    matchNextLine(cleanReviewRatingsInputFile, "2 The Lion King awe inspiring *");
    matchNextLine(cleanReviewRatingsInputFile, "0 Jack Jill worst *");
    matchNextLine(cleanReviewRatingsInputFile, "1 Finding Dory good *");
    matchNextLine(cleanReviewRatingsInputFile, "3 Zootopia fantastic *");
    matchNextLine(cleanReviewRatingsInputFile, "4 Jungle Book fantastic *");
    matchNextLine(cleanReviewRatingsInputFile, "3 Lion King fantastic *");
    matchEof(cleanReviewRatingsInputFile);

    cleanReviewRatingsInputFile.close();
    std::remove("testCleanReviewRatings.txt");
}

/**
 * @brief Test case for fillDictionary(). Performs best-effort cleanup of modified files.
 */
TEST(A2Test, FillDictionary) {
    // Make sure the clean review ratings file has the correct contents
    std::ofstream cleanReviewRatingsOutputFile("testCleanReviewRatings.txt");
    assertOpen(cleanReviewRatingsOutputFile, "Cannot open testCleanReviewRatings.txt for output");
    cleanReviewRatingsOutputFile << "4 The Jungle Book awesome " << std::endl;
    cleanReviewRatingsOutputFile << "2 The Lion King awe inspiring " << std::endl;
    cleanReviewRatingsOutputFile << "0 Jack Jill worst " << std::endl;
    cleanReviewRatingsOutputFile << "1 Finding Dory good " << std::endl;
    cleanReviewRatingsOutputFile << "3 Zootopia fantastic " << std::endl;
    cleanReviewRatingsOutputFile << "4 Jungle Book fantastic " << std::endl;
    cleanReviewRatingsOutputFile << "3 Lion King fantastic " << std::endl;
    assertNotFailed(cleanReviewRatingsOutputFile, "Error writing to testCleanReviewRatings.txt");
    cleanReviewRatingsOutputFile.close();

    // Set up parameters for function call
    std::ifstream cleanReviewRatingsInputFile("testCleanReviewRatings.txt");
    assertOpen(cleanReviewRatingsInputFile, "Cannot open testCleanReviewRatings.txt for input");

    std::unordered_map<std::string, std::pair<long, long>> dictionary;

    // Call fillDictionary() from a2.cpp
    fillDictionary(cleanReviewRatingsInputFile, dictionary);

    // Check state of files
    assertOpen(cleanReviewRatingsInputFile, "fillDictionary() should not close newInFile");
    expectEof(cleanReviewRatingsInputFile, "fillDictionary() does not read all lines in newInFile");
    cleanReviewRatingsInputFile.close();
    std::remove("testCleanReviewRatings.txt");

    // Check contents of dictionary
    checkDictionaryPair(dictionary, "Jack", 0, 1);
    checkDictionaryPair(dictionary, "Jill", 0, 1);
    checkDictionaryPair(dictionary, "Finding", 1, 1);
    checkDictionaryPair(dictionary, "Zootopia", 3, 1);
    checkDictionaryPair(dictionary, "The", 6, 2);
    checkDictionaryPair(dictionary, "Jungle", 8, 2);
    checkDictionaryPair(dictionary, "Book", 8, 2);
    checkDictionaryPair(dictionary, "Lion", 5, 2);
    checkDictionaryPair(dictionary, "King", 5, 2);
    checkDictionaryPair(dictionary, "fantastic", 10, 3);
    EXPECT_EQ(dictionary.size(), 16);
}

/**
 * @brief Test case for rateReviews(). Performs best-effort cleanup of modified files.
 */
TEST(A2Test, RateReviews) {
    // Make sure the clean reviews file has the correct contents
    std::ofstream cleanReviewsOutputFile("testCleanReviews.txt");
    assertOpen(cleanReviewsOutputFile, "Cannot open testCleanReviews.txt for output");
    cleanReviewsOutputFile << "like The Jungle Book " << std::endl;
    cleanReviewsOutputFile << "The Lion King fantastic " << std::endl;
    cleanReviewsOutputFile << "Jack Jill bad " << std::endl;
    cleanReviewsOutputFile << "Finding Nemo great " << std::endl;
    cleanReviewsOutputFile << "Zootopia awesome " << std::endl;
    assertNotFailed(cleanReviewsOutputFile, "Error writing to testCleanReviews.txt");
    cleanReviewsOutputFile.close();

    // Set up parameters for function call
    std::ifstream cleanReviewsInputFile("testCleanReviews.txt");
    assertOpen(cleanReviewsInputFile, "Cannot open testCleanReviews.txt for input");

    std::unordered_map<std::string, std::pair<long, long>> dictionary;
    addDictionaryPair(dictionary, "awesome", 4, 1);
    addDictionaryPair(dictionary, "Jack", 0, 1);
    addDictionaryPair(dictionary, "Jill", 0, 1);
    addDictionaryPair(dictionary, "Finding", 1, 1);
    addDictionaryPair(dictionary, "Zootopia", 3, 1);
    addDictionaryPair(dictionary, "The", 6, 2);
    addDictionaryPair(dictionary, "Jungle", 8, 2);
    addDictionaryPair(dictionary, "Book", 8, 2);
    addDictionaryPair(dictionary, "Lion", 5, 2);
    addDictionaryPair(dictionary, "King", 5, 2);
    addDictionaryPair(dictionary, "fantastic", 10, 3);

    std::ofstream ratingsOutputFile("testRatings.txt");
    assertOpen(ratingsOutputFile, "Cannot open testRatings.txt for output");

    // Call rateReviews() from a2.cpp
    rateReviews(cleanReviewsInputFile, dictionary, ratingsOutputFile);

    // Check state of files
    assertOpen(cleanReviewsInputFile, "rateReviews() should not close testFile");
    expectEof(cleanReviewsInputFile, "rateReviews() does not read all lines in testFile");
    cleanReviewsInputFile.close();
    std::remove("testCleanReviews.txt");
    assertOpen(ratingsOutputFile, "rateReviews() should not close ratingsFile");
    ratingsOutputFile.close();

    std::ifstream ratingsInputFile("testRatings.txt");
    assertOpen(ratingsInputFile, "Cannot open testRatings.txt for input");

    // Check contents of file
    matchNextLine(ratingsInputFile, "3.25");
    matchNextLine(ratingsInputFile, "2.83");
    matchNextLine(ratingsInputFile, "0.67");
    matchNextLine(ratingsInputFile, "1.67");
    matchNextLine(ratingsInputFile, "3.50");
    matchEof(ratingsInputFile);

    ratingsInputFile.close();
    std::remove("testRatings.txt");
}

/**
 * @brief End-to-end test case. This function is very similar to main() in main.cpp,
 *        with some additional checks at the end. Performs best-effort cleanup of
 *        modified files.
 */
TEST(A2Test, EndToEnd) {
    // Open the input file containing the raw data.
    std::ifstream rawReviewRatingsInputFile("rawReviewRatings.txt");
    assertOpen(rawReviewRatingsInputFile, "Cannot open rawReviewRatings.txt for input");

    // Open an output file for storing the clean data.
    std::ofstream cleanReviewRatingsOutputFile("testCleanReviewRatings.txt");
    assertOpen(cleanReviewRatingsOutputFile, "Cannot open testCleanReviewRatings.txt for output");

    // A set to store the stopwords.
    std::unordered_set<std::string> stopwords;

    // Open the input file containing the stopwords.
    std::ifstream stopwordsFile("stopwords.txt");
    assertOpen(stopwordsFile, "Cannot open stopwords.txt for input");

    // Read a collections of stopwords from the stopwords file
    // and store it in a set.
    fillStopWords(stopwordsFile, stopwords);
    stopwordsFile.close();

    // Clean the raw data and store it in an output file.
    cleanData(rawReviewRatingsInputFile, cleanReviewRatingsOutputFile,
              stopwords);
    rawReviewRatingsInputFile.close();
    cleanReviewRatingsOutputFile.close();

    // A map from each word to a pair consisting of the total rating for this
    // word and the total number of times this word has occurred in the reviews.
    std::unordered_map<std::string, std::pair<long, long>> dictionary;

    // Open an input file containing the clean data.
    std::ifstream cleanReviewRatingsInputFile("testCleanReviewRatings.txt");
    assertOpen(cleanReviewRatingsInputFile, "Cannot open testCleanReviewRatings.txt for input");

    // Create a mapping between the words and their associated values.
    fillDictionary(cleanReviewRatingsInputFile, dictionary);
    cleanReviewRatingsInputFile.close();
    std::remove("testCleanReviewRatings.txt");

    // Open the file with the raw reviews.
    std::ifstream rawReviewsInputFile("rawReviews.txt");
    assertOpen(rawReviewsInputFile, "Cannot open rawReviews.txt for input");

    // Open an output file for storing the clean reviews.
    std::ofstream cleanReviewsOutputFile("testCleanReviews.txt");
    assertOpen(cleanReviewsOutputFile, "Cannot open testCleanReviews.txt for output");

    // Clean the raw reviews and store them in an output file.
    cleanData(rawReviewsInputFile, cleanReviewsOutputFile, stopwords);
    rawReviewsInputFile.close();
    cleanReviewsOutputFile.close();

    // Open the input file containing the clean reviews.
    std::ifstream cleanReviewsInputFile("testCleanReviews.txt");
    assertOpen(cleanReviewsInputFile, "Cannot open testCleanReviews.txt for input");

    // Open an output file for storing the ratings for each review.
    std::ofstream ratingsOutputFile("testRatings.txt");
    assertOpen(ratingsOutputFile, "Cannot open testRatings.txt for output");

    // Rate the reviews and write the ratings to an output file.
    rateReviews(cleanReviewsInputFile, dictionary, ratingsOutputFile);
    cleanReviewsInputFile.close();
    std::remove("testCleanReviews.txt");

    // Check contents of file
    std::ifstream ratingsInputFile("testRatings.txt");
    assertOpen(ratingsInputFile, "Cannot open testRatings.txt for input");

    matchNextLine(ratingsInputFile, "3.25");
    matchNextLine(ratingsInputFile, "2.83");
    matchNextLine(ratingsInputFile, "0.67");
    matchNextLine(ratingsInputFile, "1.67");
    matchNextLine(ratingsInputFile, "3.50");
    matchEof(ratingsInputFile);

    ratingsInputFile.close();
    std::remove("testRatings.txt");
}

/**
 * @brief Unit test execution begins here.
 *
 * @param argc Number of command-line arguments
 * @param argv Command line arguments
 * @return 0 for normal program termination, other error code for abnormal termination
 */
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
