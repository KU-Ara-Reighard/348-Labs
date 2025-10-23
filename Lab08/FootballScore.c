#include <stdio.h>

int main() {
    int TD = 6, FG = 3, SAFETY = 3, TDC = 8, TDFG = 7, score;

    while (1) {
        printf("Enter the NFL score (Enter 1 to stop): ");
        scanf("%d", &score);
        printf("\n");

        if (score == 1) {
            printf("exiting...\n");
            break;
        }

        else if (score > 0) {

            printf("Possible combinations of scoring plays if a team's score is %d:\n", score);

            for (int field_goals = 0; field_goals <= score / FG; field_goals++) {

                for (int safeties = 0; safeties <= score / SAFETY; safeties++) {

                    for (int touchdowns = 0; touchdowns <= score / TD; touchdowns++) {

                        for (int touchdowns_with_field_goals = 0; touchdowns_with_field_goals <= score / TDFG; touchdowns_with_field_goals++) {

                            for (int touchdowns_with_conversion = 0; touchdowns_with_conversion <= score / TDC; touchdowns_with_conversion++) {

                                if (field_goals * FG + safeties * SAFETY + touchdowns * TD + touchdowns_with_field_goals * TDFG + touchdowns_with_conversion * TDC == score) 
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", touchdowns_with_conversion, touchdowns_with_field_goals, touchdowns, field_goals, safeties);

                            }

                        }

                    }

                }

            }

        }

        else {
            printf("Please enter a positive integer\n");
        }
    }
}