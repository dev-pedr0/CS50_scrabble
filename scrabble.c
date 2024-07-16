#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void) {

    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2) {
        printf("Player 1 wins!\n");
        return 0;
    } else if (score2 > score1) {
        printf("Player 2 wins!\n");
        return 0;
    } else {
        printf("Tie!\n");
        return 0;
    }

    return 1;
}

int compute_score(string word) {
    int p = 0;
    int score = 0;
    for (int i = 0; i < strlen(word); i++) {
        if (isupper(word[i]) != 0) {
            p = word[i] - 65;
            score = score + POINTS[p];
        } else if (islower(word[i]) != 0) {
            p = word[i] - 97;
            score = score + POINTS[p];
        } else {
            score = score + 0;
        }
    }
    return score;
}
