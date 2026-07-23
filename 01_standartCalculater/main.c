#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    double num1;
    double num2;

    printf("\t\t-------Standart Calculater-------\n\n");
        printf("\t\t\t1.Addition\n\n");
        printf("\t\t\t2.Subtraction\n\n");
        printf("\t\t\t3.Multiplication\n\n");
        printf("\t\t\t4.Division\n\n");
        printf("\t\t\t5.Exit\n\n");

while(1)
    {

        printf("\n\t\t\tPlease enter your selection(between 1 and 5):");
        scanf("%d",&choice);

        if(choice == 5){
            return 0;
        }
        if(choice < 1 || choice >  5){
            printf("\n\t\t\tInvalid selection! Please try again.\n");
            continue;
        }

        printf("\t\t\tPlease enter two numbers:");
        scanf("%lf %lf",&num1,&num2);



        switch(choice){

            case 1:
               printf("\n\t\t\t%.2f + %.2f = %.2f\n\n",num1,num2,num1 + num2);
               break;

            case 2:
                printf("\n\t\t\t%.2f - %.2f = %.2f\n\n",num1,num2,num1 - num2);
                break;

            case 3:
                printf("\n\t\t\t%.2f x %.2f = %.2f\n\n",num1,num2,num1 * num2);
                break;

            case 4:
                if(num2 == 0){
                    printf("\n\t\t\tA number cannot be divided by zero.\n\n");
                    break;

                }
                else{
                    printf("\n\t\t\t%.2f / %.2f = %.2f\n\n",num1,num2,num1 / num2);
                    break;
                }
        }

    }

}

