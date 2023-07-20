#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct {
    int ID;
    int age;
    float gpa;
} Student;

float calculateAverageGPA(Student* students) {
    float sumGPA = 0.0;
    for (int i = 0; i < 10000; i++) {
        sumGPA += students[i].gpa;
    }
    return sumGPA / 10000;
}

int main() {
    srand(time(NULL));
    float sumAverageGPA = 0.0;
    for (int i = 0; i < 10000; i++) {   // average hesaplamak icin for
        Student* students = (Student*)malloc(10000 * sizeof(Student));
        for (int j = 0; j < 10000; j++) {   // her ogrencinin verilerini yazmak icin for.
            students[j].ID = j + 1;
            students[j].age = rand() % 10 + 18;  
            students[j].gpa = (float)(rand() % 400) / 100;
        }
        float averageGPA = calculateAverageGPA(students);
        sumAverageGPA += averageGPA;
        free(students);
    }
    float overallAverageGPA = sumAverageGPA / 10000;
    printf("Average GPA of %d x %d students: %.2f\n", 10000, 10000, overallAverageGPA);

    return 0;
}
