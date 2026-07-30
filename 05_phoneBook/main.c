#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact
{
    char name[50];
    char phoneNumber[15];

};

int main()
{
    int choice;
    printf("\t\t\t----------Phone Directory------------\n\n");

    while(1){
        printf("\t\t\t Press 1 to add a person.\n");
        printf("\t\t\t Press 2 to list the guide.\n");
        printf("\t\t\t Press 3 to call.\n");
        printf("\t\t\t Press 4 to exit.\n\n");
        printf("\t\t\t Please select an option:");
        scanf("%d",&choice);

        switch (choice){
            case 1:{
                struct Contact newContact;

                printf("\n\t\t\t Please enter a name:");
                scanf("%s",newContact.name);
                printf("\n\t\t\t Please enter a phone number:");
                scanf("%s",newContact.phoneNumber);
                FILE *file = fopen("contacts.txt","a");
                fprintf(file, "%s %s\n",newContact.name,newContact.phoneNumber);
                printf("\n\t\t\t Person successfully added!\n\n");
                fclose(file);
                break;
            }
            case 2:{
                struct Contact tempContact;
                FILE *file = fopen("contacts.txt","r");
                if(file == NULL){
                    printf("\n\t\t\tThe guide is still empty.\n\n");
                    break;
                }
                while(fscanf(file , "%s %s",tempContact.name, tempContact.phoneNumber) != EOF){
                    printf("\n\t\t\t %s - %s\n\n", tempContact.name, tempContact.phoneNumber);
                }
                fclose(file);
                break;
            }
            case 3:{
                char searchName[50];
                struct Contact tempContact;
                int found = 0;

                printf("\n\t\t\t To call whom: ");
                scanf("%s",searchName);

                FILE *file = fopen("contacts.txt","r");
                if(file == NULL){
                    printf("\n\t\t\tThe guide is still empty.\n\n");
                    break;
                }
                while(fscanf(file, "%s %s",tempContact.name,tempContact.phoneNumber) != EOF){
                   if(strcmp(tempContact.name,searchName)== 0){
                        printf("\n\t\t\t Calling %s...\n\n",tempContact.phoneNumber);
                        found =1;
                        break;
                   }
                }
                if(found == 0){
                   printf("\n\t\t\t This person is not saved in your contacts.\n\n");
                }
                fclose(file);
                break;
            }
            case 4:
                printf("\n\t\t\t Logging out...\n");
                return 0;
        }
    }
    return 0;
}
