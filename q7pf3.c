#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ContentMetadata {
    char title[100];
    float rating;
    int runtime;
    char encoding[50];
};

int main() {
    int numUsers = 3;
    int numCategories = 4;
    int numDevices = 3;
    int numContent = 5;

    double **engagementMatrix = malloc(numUsers * sizeof(double *));
    for (int i = 0; i < numUsers; i++) {
        engagementMatrix[i] = malloc(numCategories * sizeof(double));
    }

    engagementMatrix[0][0] = 5.0;
    engagementMatrix[0][1] = 3.5;
    engagementMatrix[1][2] = 4.7;
    engagementMatrix[2][3] = 4.2;

    double **deviceMatrix = malloc(numUsers * sizeof(double *));
    for (int i = 0; i < numUsers; i++) {
        deviceMatrix[i] = malloc(numDevices * sizeof(double));
    }

    deviceMatrix[0][0] = 1080.0;
    deviceMatrix[1][1] = 720.0;
    deviceMatrix[2][2] = 480.0;

    struct ContentMetadata ***contentMatrix = malloc(numCategories * sizeof(struct ContentMetadata **));
    for (int i = 0; i < numCategories; i++) {
        contentMatrix[i] = malloc(numContent * sizeof(struct ContentMetadata *));
    }

    for (int i = 0; i < numCategories; i++) {
        for (int j = 0; j < numContent; j++) {
            contentMatrix[i][j] = malloc(sizeof(struct ContentMetadata));
            snprintf(contentMatrix[i][j]->title, sizeof(contentMatrix[i][j]->title), "Content %d in Category %d", j + 1, i + 1);
            contentMatrix[i][j]->rating = 4.5 + (j % 3);
            contentMatrix[i][j]->runtime = 120;
            snprintf(contentMatrix[i][j]->encoding, sizeof(contentMatrix[i][j]->encoding), "H.264");
        }
    }

    printf("User 0's Engagement in Action Category: %.2f\n", engagementMatrix[0][0]);
    printf("User 1's Device Preference for Laptop: %.2f resolution\n", deviceMatrix[1][1]);
    printf("Content 1 in Drama Category:\n");
    printf("Title: %s\n", contentMatrix[1][0]->title);
    printf("Rating: %.1f\n", contentMatrix[1][0]->rating);
    printf("Runtime: %d minutes\n", contentMatrix[1][0]->runtime);
    printf("Encoding: %s\n", contentMatrix[1][0]->encoding);

    for (int i = 0; i < numUsers; i++) {
        free(engagementMatrix[i]);
    }
    free(engagementMatrix);

    for (int i = 0; i < numUsers; i++) {
        free(deviceMatrix[i]);
    }
    free(deviceMatrix);

    for (int i = 0; i < numCategories; i++) {
        for (int j = 0; j < numContent; j++) {
            free(contentMatrix[i][j]);
        }
        free(contentMatrix[i]);
    }
    free(contentMatrix);

    return 0;
}
