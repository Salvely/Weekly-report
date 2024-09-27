#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define length 18

typedef struct word_struct word_t;
struct word_struct {
	char *str;
	int len;
};

bool isAlpha (char ltr) {
    bool soln = (('a' <= ltr && ltr <= 'z') || ('A' <= ltr && ltr <= 'Z'));
    return soln;
}

void toggleCase (word_t *msg) {
    char ltr;
    for (int i = 0; i < msg->len; i++) {
        ltr = msg->str[i];
        if (isAlpha(ltr))
            if (ltr <= 'Z')
                msg->str[i] = ltr + 32;
            else
                msg->str[i] = ltr - 32;
    }
}

void reverse (word_t *msg) {
    char *buf = (char *)calloc(length, sizeof(char));
    buf[length - 1] = '\0';
    for (int i = 0; i < msg->len - 1; i++) {
        buf[msg->len - i - 2] = msg->str[i];
    }
    strncpy(msg->str, buf, length);
}

void unscramble (word_t *msg) {
    char ltr;
    char chng = 13;
    for (int i = 0; i < msg->len; i++) {
        ltr = msg->str[i];
        if (isAlpha(ltr)) {
            if (ltr > 'm' || (ltr > 'M' && ltr <= 'Z')) {
                msg->str[i] = ltr - chng;
            } else {
                msg->str[i] = ltr + chng;
            }
        }
    }
}

int main () {
    word_t *secret_msg = (word_t *) calloc(1, sizeof(word_t));
    secret_msg->str = (char *) calloc(length, sizeof(char));
    strncpy(secret_msg->str, "!312 Av XPHy QBBt", length);;
    secret_msg->len = length;

    unscramble(secret_msg);
    reverse(secret_msg);
    toggleCase(secret_msg);

    printf("%s\n", secret_msg->str);
    free(secret_msg->str);
    free(secret_msg);
    return 0;
}
