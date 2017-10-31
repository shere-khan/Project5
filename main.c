/* Matthew Funk
COP 3223C
Sarah Angel
10/15/17
 */

#include <stdio.h>

#define NUMBEROFMONTHS 12

int main(){

    int cold_temp,hot_temp,j;
    char name_of_file[30];

    printf("Tell me about your crew's preferred temperature for sailing:\n");
    printf ("What is the coldest temperature they can sail in?\n");
    scanf("%d", &cold_temp);
    printf("What is the hottest temperature they can sail in?\n");
    scanf("%d", &hot_temp);
    printf("Please enter the name of the weather data file:\n");
    scanf("%s", &name_of_file);

    while ((cold_temp <= 0 || cold_temp >= 80) || (hot_temp <= cold_temp || hot_temp >= 120)){
        printf("Sorry, one of you temperature bounds is invalid.\n");
        printf ("What is the coldest temperature they can sail in?\n");
        scanf("%d", &cold_temp);
        printf("What is the hottest temperature they can sail in?\n");
        scanf("%d", &hot_temp);}

    FILE *ifp = fopen(name_of_file, "r");

    int num_of_temps,i,num_of_days = 0, target_month;
    float temp_of_day, perc_of_month=0.0, new_percent = 0.00;



    for (j=1; j<=NUMBEROFMONTHS; j++){

        fscanf(ifp, "%d", &num_of_temps);

        for (i=0; i<num_of_temps; i++){
            fscanf(ifp, "%f", &temp_of_day);

            if (temp_of_day >= cold_temp && temp_of_day <= hot_temp)
                num_of_days += 1;


        }
        perc_of_month = ((double)(num_of_days)/num_of_temps) * 100;

        if (perc_of_month > new_percent){
            new_percent = perc_of_month;
            target_month = j;}
        printf("Month %d: %.1f percent of days in range.\n",j, perc_of_month);

        num_of_days = 0;


    }
    printf("\nYou should leave for the Caribbean in month %d!\n",target_month);

    fclose(ifp);

    return 0;
}

