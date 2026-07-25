#include <stdio.h>
#include <stdlib.h>

struct Student{
    int id;
    char name[50];
    float grade;
};
void addStudent(){
    struct Student std;

    FILE * file;
    file = fopen("student.txt","a");

    if(file == NULL){
        printf("Error: The file could not be opened!\n");
        return;
    }
    printf("\n---New Student Registiration---\n");

    printf("Student Number: ");
    scanf("%d",&std.id);

    printf("Student Name: ");
    scanf("%s",std.name);

    printf("Student Grade: ");
    scanf("%f",&std.grade );

    fprintf(file, "%d %s %.2f\n",std.id,std.name,std.grade);
    fclose(file);
    printf("-->Record successfully created.\n");
}
void listStudents(){
    struct Student std;

    FILE *file;
    file = fopen("student.txt","r");

    if(file == NULL){
        printf("Error: No records yet or file not found!\n");
        return;
    }
    printf("\n--- ALL STUDENT REGISTRATION---\n");

    printf("%-10s | %-20s | %-10s\n", "ID", "NAME", "GRADE");
    printf("-------------------------------------------\n");

    while(fscanf(file, "%d %s %f",&std.id,std.name,&std.grade) != EOF){
        printf("%-10d | %-20s | %-10.2f\n", std.id, std.name, std.grade);
    }
    fclose(file);
    printf("-------------------------------------------\n");
}
void deleteStudent(){
    int targetId, found = 0;
    struct Student std;

    FILE *file = fopen("student.txt","r");
    FILE *temp = fopen("temp.txt","w");

    if( file == NULL){
        printf("Eror: No records found to delete!\n");
        if(temp != NULL) fclose(temp);
        return;
    }

    printf("\n--- DELETE STUDENT ---\n");

    printf("Enter the Student ID to delete: ");
    scanf("%d",&targetId);

    while(fscanf(file,"%d %s %f", &std.id, std.name,&std.grade) != EOF){
        if(std.id == targetId){
            found = 1;
        }
        else{
            fprintf(temp, "%d %s %.2f\n", std.id,std.name,std.grade);
        }
    }

    fclose(file);
    fclose(temp);

    remove("student.txt");
    rename("temp.txt","student.txt");

    if(found){
        printf("--> Student with ID %d successfully deleted!\n",targetId);
    }
    else{
        printf("--> Error: Student ID not found!\n");
    }
}
void updateStudent(){
    int targetId, found = 0;
    struct Student std;

    FILE *file = fopen("student.txt","r");
    FILE *temp = fopen("temp.txt","w");

    if(file == NULL){
        printf("Error: No records found to update!\n");
        if (temp != NULL) fclose(temp);
        return ;
    }
    printf("\n--- UPDATE STUDENT ---\n");
    printf("Enter the Student ID to update: ");
    scanf("%d", &targetId);

    while (fscanf(file, "%d %s %f", &std.id, std.name, &std.grade) != EOF) {
        if (std.id == targetId) {
            found = 1;
            printf("Student found! Enter new details:\n");
            printf("New Name: ");
            scanf("%s", std.name);
            printf("New Grade: ");
            scanf("%f", &std.grade);
        }
        if(found){
            fprintf(temp, "%d %s %.2f\n", std.id, std.name, std.grade);
        }

        else {
            fprintf(temp, "%d %s %.2f\n", std.id, std.name, std.grade);
        }
    }

    fclose(file);
    fclose(temp);

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (found) {
        printf("--> Student record successfully updated!\n");
    } else {
        printf("--> Error: Student ID not found!\n");
    }
}

int main()
{
    int choice;

    while(1){
        printf("\n=== STUDENT GRADING SYSTEM ===\n");
        printf("1. add new student\n");
        printf("2. list students\n");
        printf("3. delete student\n");
        printf("4.update studen\n");
        printf("5. Exit\n");
        printf("your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                listStudents();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                printf("Logging out of the system...\n");
                return 0;
            default:
                printf("Invalid selection,please try again.\n");
        }
    }
    return 0;
}



