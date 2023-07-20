#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ExamPaper {
    char studentName[100];
    long studentNumber;
    long score;
    struct ExamPaper* next;
} ExamPaper;

ExamPaper* push(ExamPaper* stack, char* studentName, long studentNumber, long score) {
    ExamPaper* newExamPaper = (ExamPaper*)malloc(sizeof(ExamPaper));

    strcpy(newExamPaper->studentName, studentName);
    newExamPaper->studentNumber = studentNumber;
    newExamPaper->score = score;
    newExamPaper->next = stack; // olusturugum structin next elemanini stacke esitleyerek en basa ekleme yapiyorum

    return newExamPaper;
}

ExamPaper* pop(ExamPaper* stack) {
    if (stack == NULL) {
        printf("Stack is empty.\n");
        return NULL;
    }

    ExamPaper* poppedExamPaper = stack; // poplanan yeni bir struct olusturuyorum.
    stack = stack->next;            // stackin hepsini bir adim kaydirip en bastakini siliyorum
    poppedExamPaper->next = NULL;

    printf("Last Added Exam Paper:\n");
    printf("- Student Name: %s, Student Number: %ld, Score: %ld\n", poppedExamPaper->studentName, poppedExamPaper->studentNumber, poppedExamPaper->score);

    free(poppedExamPaper);
    return stack;
}

int isEmpty(ExamPaper* stack) {
    if (stack == NULL) {
        printf("Stack is empty.\n");
        return 1;
    }

    printf("Stack is not empty.\n");
    return 0;
}

void display(ExamPaper* stack) {

    ExamPaper* current = stack;
    while (current != NULL) {
        printf("- Student Name: %s, Student Number: %ld, Score: %ld\n", current->studentName, current->studentNumber, current->score);
        current = current->next;
    }
}

int main() {
    ExamPaper* stack = NULL;
    printf("\n");
    
    stack = push(stack, "Zehra Bilici", 20220000001L, 90L);
    printf("Exam Paper Added: Student Name: %s, Student Number: %ld, Score: %ld\n", stack->studentName, stack->studentNumber, stack->score);
    
    stack = push(stack, "Barış Özcan", 20190000002L, 85L);
    printf("Exam Paper Added: Student Name: %s, Student Number: %ld, Score: %ld\n", stack->studentName, stack->studentNumber, stack->score);

    stack = push(stack, "Mehmet Burak Koca", 20180000010L, 95L);
    printf("Exam Paper Added: Student Name: %s, Student Number: %ld, Score: %ld\n", stack->studentName, stack->studentNumber, stack->score);

    printf("\nNow doing pop operation.\n");
    stack = pop(stack);
    isEmpty(stack);
    printf("\nStack after pop operation:\n");
    display(stack);

    return 0;
}
