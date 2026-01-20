/*
Modify Programming Project 7 so that it prompts for five quiz grades for each of five stu
dents. then computes the total score and average score for each student, and the average
score, high score, and low score for each quiz.
*/
#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_STUDENTS sizeof(qGrades) / sizeof(qGrades[0])
#define NUM_OF_QUIZES sizeof(qGrades[0]) / sizeof(qGrades[0][0]) 

int main(void)
{
    int qGrades[5][5] = {0};

    printf("Enter the grades of the student for each quizes (ex: 4 2 5 2 6):\n");

    for(size_t i = 0; i < NUM_OF_STUDENTS; i++)
    {
        printf("Student %lld: ", i + 1);
        for (size_t j = 0; j < NUM_OF_QUIZES; j++)
        {
            scanf("%d", &qGrades[i][j]);
        }
        
    }

    printf("\n|Students|\tScores\t  | Total |\t Avg Score\n");
    for(size_t i = 0, stuTotal = 0; i < NUM_OF_STUDENTS; i++)
    {
        double stuAvgScore = 0;

        printf("Student %lld: ", i + 1);
        for (size_t j = 0; j < NUM_OF_QUIZES; j++)
        {
            printf(" %d ", qGrades[i][j] );
            stuTotal += qGrades[i][j];
        }
        stuAvgScore = stuTotal / 5;

        printf("|\t %lld|\t %.2lf", stuTotal, stuAvgScore);
        printf("\n");
    }

    printf("\n=================================\n");
    printf("Quizes | Avg score |\t High Score |\t Low Score\n");
    for(size_t i = 0; i < NUM_OF_QUIZES; i++)
    {
        double qAvgScore = 0;
        int qHighScore = 0, qLowScore = qGrades[0][0], qTotal = 0;

        for (size_t j = 0; j < NUM_OF_STUDENTS; j++)
        {
            qTotal += qGrades[j][i];

            qHighScore = qGrades[j][i] > qHighScore ? qGrades[j][i] : qHighScore;
            qLowScore = qGrades[j][i] < qLowScore ? qGrades[j][i] : qLowScore;
        }

        qAvgScore = qTotal / 5;

        printf("Quiz %lld | %.2lf      |\t %d \t|\t %d\n", i + 1, qAvgScore, qHighScore, qLowScore);
        
    }

    return 0;
}

//TTC 38:09