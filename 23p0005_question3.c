#include <stdio.h>

// Function to get the rank of a card
int getRank(char rank) {
    if (rank >= '2' && rank <= '9') {
        return rank - '0';
    } else if (rank == 'T') {
        return 10;
    } else if (rank == 'J') {
        return 11;
    } else if (rank == 'Q') {
        return 12;
    } else if (rank == 'K') {
        return 13;
    } else if (rank == 'A') {
        return 14;
    }
    return 0; 
}

// Function to parse a line of input into two separate poker hands
void parse_PokerHands(const char *input, char *hand1, char *hand2) {
    int i = 0, j = 0;
    while (*input != '\0') {
        if (*input != ' ') {
            if (i < 10)
                hand1[i++] = *input;
            else
                hand2[j++] = *input;
        }
        input++;
    }
}

// Function to count the occurrences of each rank in a hand
void count_Ranks(const char *hand, int *count) {
    for (int i = 0; i < 10; i += 2) {
        int rank = getRank(hand[i]);
        count[rank]++;
    }
}

// Function to evaluate the rank of a poker hand
int evaluate_Hand(const char *hand) {
    int count[15];
    count_Ranks(hand, count);

    return 0; 
}

// Function to compare two poker hands and determine the winner
int compare_Hands(const char *hand_1, const char *hand_2) {
    int rank_1 = evaluate_Hand(hand_1);
    int rank_2 = evaluate_Hand(hand_2);

    if (rank_1 > rank_2) {
        return 1; 
    } else if (rank_1 < rank_2) {
        return 2; 
    } else {
        return 0; 
    }
}

int main() {
    char input[100];
    int Player1wins = 0, Player2wins = 0;
    
    printf("Enter poker hands (each line contains 10 cards separated by space):\n");
    while (fgets(input, sizeof(input), stdin) != NULL) {
        char hand_1[11], hand_2[11];
        parse_PokerHands(input, hand_1, hand_2);
        int result = compare_Hands(hand_1, hand_2);
        if (result == 1) {
            Player1wins++;
        } else if (result == 2) {
            Player2wins++;
        }
    }

    if (Player1wins > Player2wins) {
        printf("Player 1 wins more games\n");
    } else if (Player1wins <Player2wins) {
        printf("Player 2 wins more games\n");
    } else {
        printf("Both players win the same number of games\n");
    }

    return 0;
}
