#include <stdio.h>
#define NUM_STUDENT 3

float average(int inputValues[]);

int main(void) {

    // Set Valiables 
    int mid[NUM_STUDENT];
    int fin[NUM_STUDENT];
    int tot[NUM_STUDENT];
    float mean;

    // Input scores
    for (int i=0; i < NUM_STUDENT; i++){
        printf("student %d's mid score: ", i);
        scanf("%d", &mid[i]);
        printf("student %d's final score: ", i);
        scanf("%d", &fin[i]);
    }

    // Calculate total scores
    for (int i=0; i < NUM_STUDENT; i++){
        tot[i] = mid[i] + fin[i];
    }

    // Print scores
    for (int i=0; i < NUM_STUDENT; i++){
        printf("Total score for student %d is %d\n", i, tot[i]);
    }

    // average
    mean = average(tot);
    printf("The average score of the students is %f\n", mean);
    return 0;
} 

// Definition

float average(int inputValues[]){
    float sum = 0;

    for (int i=0; i < NUM_STUDENT; i++){
        sum += inputValues[i];
    }
    float res = (sum / NUM_STUDENT);

    return res;

}
