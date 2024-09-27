/*
 * Wordle.c : Travis McGaha - Oct. 27, 2022
 */

#include "lc4libc.h"
#include "alpha_sprites.h"
#include "dict.h"


#define BLACK_COLOR   0x0000U
#define WHITE_COLOR   0x7FFFU

#define UNKNOWN       0x4E74U
#define WRONG_CHAR    0x2129U
#define MATCH         0x2EE1U
#define WRONG_INDEX   0x7F60U


// Global variables that are used for pseudo-random
// number generation. You do NOT have to modify these
// or understand how they work. If you want to know
// more look up "Linear Feedback Shift Registers"
unsigned int lfsr = 0;
unsigned int lfsr_status = 0;

/*
 * #############  UTILITIES DECLARATIONS  ######################
 */

// #############  INCOMPLETE UTILITIES  ######################
// (You need to implement these functions. The empty functions are below main)

// Takes a character and returns the equivalent character in uppercase.
// If the character is not a lowercase letter, returns the original input.
//
// Argument:
// - c: the character to convert to upper case
//
// Returns:
// - the character in uppercase if the input was a lowercase letter
//   or the original input character in all other cases.
char toupper(char c);

// Compares two strings and returns whether they are equivalent.
// The characters in the two input strings should not be modified.
//
// Argument:
// - str1: The first string
// - str2: The second string
//
// Returns:
// - 1 iff the two strings are the same length and have the same characters.
//   0 in all other cases.
int str_equals(char* str1, char* str2);

// Updates the status array based on how the users guess compares to the
// secret word that is tyring to be guessed.
// Each index in `char_statusses` corresponds to the same index in `guess`.
// char_statusses[i] is set to be: 
// - MATCH if guess[i] equals secret_word[i]
// - WRONG_INDEX if guess[i] is not the same as secret_word[i] BUT
//   guess[i] is equal to a character in secret_word at a different index.
// - WRONG_CHAR if the character guess[i] is not found in the secret_word.
//
// Arguments:
// - guess: a length 5 null-terminated string that contains the users guess
// - secret_word: a length 5 null-terminated string that contains the secret word
// - char_statuses: an array of length 5 containing the status of each character
//   in guess as described above.
void update_status(char* guess, char* secret_word, unsigned int* char_statuses);

// Checks an array of char_statuses to see if the user guessed the secret
// word correctly. (e.g. all values are MATCH) 
//
// Arguments:
// - char_statuses: an array of length 5 containing the statuses to check
//
// Returns:
// - 1 if all statuses in char_statuses is MATCH, 0 otherwise
int check_win(unsigned int* char_statuses);


// #############  PROVIDED UTILITIES  ######################

// Prints a newline to the ASCII Display
//
// Arguments:
// - None
void endl ();

// Given a signed integer, prints it in Decimal to the ASCII Display
//
// Arguments:
// - 'n', the 2C number to print to the ASCII Display
void printnum (int n);

// Given a character c, returns whether it is an english alphabet letter
//
// Arguments:
// - 'c', the character we want to check for being alphabetic
//
// Returns:
// - 1 iff the character is an ASCII letter (e.g. a-z or A-Z), 0 otherwise.
int isalpha(char c);

// Updates one of the squares on the 5 x 6 WORDLE "board" where each row is a
// 5-letter guess and each column corresponds to the different characters of
// a guess
//
// Arguments:
// - row: The row number of the square to update
//        Undefined behaviour if it is less than 0 or greater than 5
// - col: The column number of the square to update
//        Undefined behaviour if it is less than 0 or greater than 5
// - c: the character to draw on the square being updated.
//      if c is the null-terminator, then no character sprite is drawn.
//      Undefined behaviour if C is not the null terminator or an ASCII letter.
// - color: the 16-bit rgb color that will be used as the color of the square
void update_square(int row, int col, char c, unsigned int color);

// Gets a word from the keyboard input while updating display
// to show the current word input. Word is not finalized until ENTER is hit.
// Allows for users to hit backspace to delete the previous typed in charcter.
// If the user types in QUIT then hits enter, this function returns 0 to indicate
// that the user want's to end the program.
//
// Arguments:
// - row_num: the number of the row to display the current input from keyboard
// - dest: where the resulting word read in from the user is stored.
//         Assumed that there is enough space to store a null-terminated
//         string of length 5. Characters will of the string will be stored
//         as all capital letters. 
//
// Returns:
// - 1 if a word was sucessfully read in from the user.
//   0 if the user specified QUIT
int get_word (int row_num, char* dest);

// Given a pointer to memory to store a length 5 string, populates the memory
// location with a random english 5-letter null-terminated word.
//
// Arguments:
// - A pointer to where the secret word should be stored
void generate_secret(char* secret_word);

// Given a character , returns the associated sprite for that character
//
// Arguments:
// - The character we want to get the sprite for.
//
// Returns:
// - the sprite associated with the character. This should not be modified
//   and only used for passing into lc4_draw_sprite()
// - NULL pointer (0x0000) if the input is not alphabetic.
unsigned int * get_sprite(char c);

/*
 * #############  MAIN PROGRAM  ######################
 */

int main () {
  char decision;
  int i = 0;
  char guess[6] = {'\0', '\0', '\0', '\0', '\0', '\0'};
  char secret_word[6] = {'\0', '\0', '\0', '\0', '\0', '\0'};
  unsigned int status[5] = {UNKNOWN, UNKNOWN, UNKNOWN, UNKNOWN, UNKNOWN};
  int guesses = 0;
  
  lc4_puts ((unsigned int*)"!!! Welcome to LC4 Wordle !!!\n");
  lc4_puts ((unsigned int*)"When you are ready to quit, next time\n");
  lc4_puts ((unsigned int*)"you can input a word, type in QUIT and\n");
  lc4_puts ((unsigned int*)"hit ENTER.\n");

  while (1) {
    decision = '\0'; 
    // reset display
    lc4_draw_square(4, 2, 120, BLACK_COLOR);
    lc4_puts ((unsigned int*)"Would you like a random word Y/N?\n");
    while (decision != 'Y' && decision != 'N') {
      decision = toupper(lc4_getc());
    }
    if (!lfsr_status) {
      if(lc4_get_seed_status()) {
        lfsr = lc4_get_seed();
      } else {
        lfsr = 0x3CE6U;
      }
      lfsr_status = 1;
    }


    if (decision == 'N') {
      lc4_puts((unsigned int*)"provide secret word\n");
      if(!get_word(0, secret_word)) {
        lc4_puts((unsigned int*)"quitting, goodbye!\n");
        break;
      }
      lc4_draw_square(4, 2, 120, WHITE_COLOR);
    } else {
      // gen secret word
      generate_secret(secret_word);
    }

    lc4_puts((unsigned int*)"guess word then hit enter\n");
    while (guesses < 6) {
      if (!get_word(guesses, guess)) {
        lc4_puts((unsigned int*)"quitting, goodbye!\n");
        return 0;
      }

      update_status(guess, secret_word, status);
      for (i = 0; i < 5; i++) {
        update_square(guesses, i , guess[i], status[i]);
      }
      if (check_win(status)) {
        guesses = 10;
        lc4_puts((unsigned int*)"You win!\n");
        break;
      }
      // move to next guess and reset string
      guesses = guesses + 1;
      for (i = 0; i < 6; i++) {
        guess[i] = '\0';
      }
    }

    if (guesses == 6) {
       lc4_puts((unsigned int*)"You ran out of guesses\n");
       lc4_puts((unsigned int*)"The secret word was:");
       lc4_puts((unsigned int*)secret_word);
       endl();
    }

    // reset guess & secret start again
    guesses = 0;
    for (i = 0; i < 6; i++) {
      guess[i] = '\0';
      secret_word[i] = '\0';
    }
    
  }

  return 0;
}

/*
 * #############  UTILITIES DEFINITIONS  ######################
 */

// Takes a character and returns the equivalent character in uppercase.
// If the character is not a lowercase letter, returns the original input.
//
// Argument:
// - c: the character to convert to upper case
//
// Returns:
// - the character in uppercase if the input was a lowercase letter
//   or the original input character in all other cases.
char toupper(char c) {
  // YOUR CODE HERE
  //
  // HINT: remember that characters are integer types, so
  // they can be compared like numbers and arithmetic can be performed
  // on them. Take a look at isalpha() for some inspiration
  if (c >= 'a' && c <= 'z')
      c = c - 32;
  return c;
}

// Compares two strings and returns whether they are equivalent.
// The characters in the two input strings should not be modified.
//
// Argument:
// - str1: The first string
// - str2: The second string
//
// Returns:
// - 1 iff the two strings are the same length and have the same characters.
//   0 in all other cases.
int str_equals(char* str1, char* str2) {
  // YOUR CODE HERE
  while (*str1 != '\0' && *str2 != '\0') {
    str1 += 1;
    str2 += 1;
  }
  return (*str1 == *str2);
}

// Updates the status array based on how the users guess compares to the
// secret word that is tyring to be guessed.
// Each index in `char_statusses` corresponds to the same index in `guess`.
// char_statusses[i] is set to be: 
// - MATCH if guess[i] equals secret_word[i]
// - WRONG_INDEX if guess[i] is not the same as secret_word[i] BUT
//   guess[i] is equal to a character in secret_word at a different index.
// - WRONG_CHAR if the character guess[i] is not found in the secret_word.
//
// Arguments:
// - guess: a length 5 null-terminated string that contains the users guess
// - secret_word: a length 5 null-terminated string that contains the secret word
// - char_statuses: an array of length 5 containing the status of each character
//   in guess as described above.
void update_status(char* guess, char* word, unsigned int* char_statuses) {
  // YOUR CODE HERE
  int i;
  for (i = 0; i < 5; i++) {
    int j;
    int find = 0;
    for (j = i; j < 5; j++) {
      if (guess[i] == word[j]) {
        find = 1;
        if (i == j) {
          char_statuses[i] = MATCH;
        } else if (i != j) {
          char_statuses[i] = WRONG_INDEX;
        }
      }
    }
    if (!find) {
      char_statuses[i] = WRONG_CHAR;
    }
  }
}

// Checks an array of char_statuses to see if the user guessed the secret
// word correctly. (e.g. all values are MATCH) 
//
// Arguments:
// - char_statuses: an array of length 5 containing the statuses to check
//
// Returns:
// - 1 if all statuses in char_statuses is MATCH, 0 otherwise
int check_win(unsigned int* char_statuses) {
  // YOUR CODE HERE
  int i;
  for (i = 0; i < 5; i++) {
    if (char_statuses[i] != MATCH)
      return 0;
  }
  return 1;
}

void printnum (int n) {
  int abs_n;
  char str[10], *ptr;

  // Corner case (n == 0)
  if (n == 0) {
    lc4_puts ((unsigned int*)"0");
    return;
  }
 
  abs_n = (n < 0) ? -n : n;

  // Corner case (n == -32768) no corresponding +ve value
  if (abs_n < 0) {
    lc4_puts ((unsigned int*)"-32768");
    return;
  }

  ptr = str + 10; // beyond last character in string

  *(--ptr) = 0; // null termination

  while (abs_n) {
    *(--ptr) = (abs_n % 10) + 48; // generate ascii code for digit
    abs_n /= 10;
  }

  // Handle -ve numbers by adding - sign
  if (n < 0) *(--ptr) = '-';

  lc4_puts((unsigned int*)ptr);
}

int isalpha(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void endl () {
  lc4_puts((unsigned int*)"\n");
}

unsigned int * get_sprite(char c) {
  c = toupper(c);
  if (c == 'A') {
    return A_sprite;
  } else if (c == 'B') {
    return B_sprite;
  } else if (c == 'C') {
    return C_sprite;
  } else if (c == 'D') {
    return D_sprite;
  } else if (c == 'E') {
    return E_sprite;
  } else if (c == 'F') {
    return F_sprite;
  } else if (c == 'G') {
    return G_sprite;
  } else if (c == 'H') {
    return H_sprite;
  } else if (c == 'I') {
    return I_sprite;
  } else if (c == 'J') {
    return J_sprite;
  } else if (c == 'K') {
    return K_sprite;
  } else if (c == 'L') {
    return L_sprite;
  } else if (c == 'M') {
    return M_sprite;
  } else if (c == 'N') {
    return N_sprite;
  } else if (c == 'O') {
    return O_sprite;
  } else if (c == 'P') {
    return P_sprite;
  } else if (c == 'Q') {
    return Q_sprite;
  } else if (c == 'R') {
    return R_sprite;
  } else if (c == 'S') {
    return S_sprite;
  } else if (c == 'T') {
    return T_sprite;
  } else if (c == 'U') {
    return U_sprite;
  } else if (c == 'V') {
    return V_sprite;
  } else if (c == 'W') {
    return W_sprite;
  } else if (c == 'X') {
    return X_sprite;
  } else if (c == 'Y') {
    return Y_sprite;
  } else if (c == 'Z') {
    return Z_sprite;
  } else {
    return 0x0000U;
  }
}

void update_square(int row, int col, char c, unsigned int color) {
  int x;
  int y;
  unsigned int *sprite;
  x = 14 + 20 * col;
  y = 2 + 20 * row;
  lc4_draw_square(x, y, 18, color);
  if (c != '\0') {
    sprite = get_sprite(c);
    lc4_draw_sprite(x + 2, y + 2, WHITE_COLOR, sprite);
  }
}

int get_word (int row_num, char* dest) {
  char curr_char;
  int len = 0;
  for (len = 0; len < 5; len++) {
    update_square(row_num, len, '\0', UNKNOWN);
  }
  len = 0;

  while (1) {
    curr_char = lc4_getc();
    if (isalpha(curr_char) && len < 5) {
      dest[len] = toupper(curr_char);
      update_square(row_num, len, dest[len], UNKNOWN);
      len++;
    } else if(curr_char == 8 && len > 0) {
      len--;
      dest[len] = '\0';
      update_square(row_num, len, dest[len], UNKNOWN);
    } else if (curr_char == '\n') {
      if (len == 5) {
        return 1;
      } else if (str_equals(dest, "QUIT")) {
        return 0;
      }
    }
  }
  return 0;
}

void generate_secret(char* secret_word) {
  int word_index;
  int i;
  int bit;
  int random_num = 0;

  for (i = 0; i < 16; i++) {
    bit = ((lfsr >> 5) ^ (lfsr >> 3) ^ (lfsr >> 2) ^ lfsr);
    bit = bit & 1;
    random_num = (random_num << 1) | bit;
    bit = bit << 7;
    bit = bit << 7;
    lfsr = (lfsr >> 1) | (bit << 1);
  }
  word_index = random_num % NUM_SECRETS;
  for (i = 0; i < 6; i++) {
    secret_word[i] = toupper(dictionary[word_index][i]);
  }
}

