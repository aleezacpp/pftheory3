/*Write a program that organizes a digital cricket match, "Cricket Showdown," where two players,
Player 1 and Player 2, compete over 12 balls. Each player takes turns to score runs on each
ball. Players can enter scores between 0 and 6 for each ball, and if a score outside this range is
entered, it will be disregarded, but the ball will still be marked.
1. Define a structure Player with the following members:
a. ballScores[12]: An array to store the score for each ball.
b. playerName: A string to hold the player's name.
c. totalScore: An integer to store the total score for each player.
2. Define functions:
a. playGame(struct Player player): This function prompts each player to enter their
score for each of the 12 balls.
b. validateScore(int score): This function checks if the score is between 0 and 6
(inclusive). If it’s not, the score is disregarded, but the ball is still marked.
c. findWinner(struct Player player1,struct Player player2): Determines the winner
based on the total score.
d. displayMatchScoreboard(struct Player player1,struct Player player2): Displays a
summary of each player’s performance, including each ball’s score, the average
score, and total score.*/
#include <stdio.h>
#include <string.h>

typedef struct Player {
    int ballScores[12];
    char playerName[15];
    int totalScore;
} Player;

// Function prototypes
void playGame(Player *player);
int validateScore(int score);
void findWinner(Player player1, Player player2);
void displayMatchScoreboard(Player player1, Player player2);

int main() {
    Player player1, player2;

    player1.totalScore = 0;
    player2.totalScore = 0;

    printf("Enter Player 1 name: ");
    scanf("%s", player1.playerName);
    printf("Enter Player 2 name: ");
    scanf("%s", player2.playerName);

    printf("\n%s's turn:\n", player1.playerName);
    playGame(&player1);
    printf("\n%s's turn:\n", player2.playerName);
    playGame(&player2);

    displayMatchScoreboard(player1, player2);

    findWinner(player1, player2);

    return 0;
}

// Function to play the game
void playGame(Player *player) {
    for (int i = 0; i < 12; i++) {
        int score;
        printf("Enter score for ball %d: ", i + 1);
        scanf("%d", &score);

        // Validate the score
        if (validateScore(score)) {
            player->ballScores[i] = score;
            player->totalScore += score;
        } else {
            printf("Invalid score! Ball %d marked.\n", i + 1);
            player->ballScores[i] = 0; // Assign 0 for invalid score
        }
    }
}

int validateScore(int score) {
    return score >= 0 && score <= 6;
}

void findWinner(Player player1, Player player2) {
    printf("\nMatch Result:\n");
    if (player1.totalScore > player2.totalScore) {
        printf("%s wins with %d runs!\n", player1.playerName, player1.totalScore);
    } else if (player1.totalScore < player2.totalScore) {
        printf("%s wins with %d runs!\n", player2.playerName, player2.totalScore);
    } else {
        printf("The match is a tie! Both players scored %d runs.\n", player1.totalScore);
    }
}

void displayMatchScoreboard(Player player1, Player player2) {
    printf("\nMatch Scoreboard:\n");
    printf("-------------------------------------------------\n");
    printf("%-15s: ", player1.playerName);
    for (int i = 0; i < 12; i++) {
        printf("%d ", player1.ballScores[i]);
    }
    printf("\nTotal Score: %d\n", player1.totalScore);

    printf("%-15s: ", player2.playerName);
    for (int i = 0; i < 12; i++) {
        printf("%d ", player2.ballScores[i]);
    }
    printf("\nTotal Score: %d\n", player2.totalScore);


}
