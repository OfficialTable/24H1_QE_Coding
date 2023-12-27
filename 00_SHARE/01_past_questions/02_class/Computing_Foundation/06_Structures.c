#include <stdio.h>
#define NUM_STUDENT 3

struct studentType {
    char name[50];
    int ID;
    int mid;
    int fin;
    float tot;
};

typedef struct studentType Student;
float average(Student *s);
void calTotal(Student *s);

int main(void) {

    // Set Valiables 
    Student s[NUM_STUDENT];
    float mean;

    // Input 
    for (int i=0; i < NUM_STUDENT; i++){
        printf("INPUT for student #%d\n", i);
        printf("    name: ");
        scanf("%s", s[i].name);
        printf("    ID  : ");
        scanf("%d", &s[i].ID);
        printf("    mid : ");
        scanf("%d", &s[i].mid);
        printf("    fin : ");
        scanf("%d", &s[i].fin);

        calTotal(&s[i]);
    }

    // Print scores
    for (int i=0; i < NUM_STUDENT; i++){
        printf("Total score for student %s is %f\n", s[i].name, s[i].tot);
    }

    // average
    mean = average(s);
    printf("The average score of the students is %f\n", mean);
    return 0;
} 

// Definition

void calTotal(Student *s) {
    s -> tot = 0.4*s->mid + 0.6*s->fin; 
}

float average(Student *s){
    float sum = 0;

    for (int i=0; i < NUM_STUDENT; i++){
        sum += s[i].tot;
    }
    float res = (sum / NUM_STUDENT);

    return res;

}
