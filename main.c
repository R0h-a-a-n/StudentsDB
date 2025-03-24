#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

struct Student{
    int roll;
    char name[50];
    float marks;
};

struct Student students[MAX];
int count = 0;

void addStudent(){
    if (count>=MAX){
        printf("Database is full! \n");
        return;
    }
    
    printf("Enter the roll no. of the student: ");
    scanf("%d",&students[count].roll);

    printf("Enter the name of the student:" );
    scanf(" %[^\n]", students[count].name);

    printf("Enter the marks of the student: ");
    scanf("%f",&students[count].marks);

    printf("Student added successfully! \n");
    count++;
}

void viewStudents(){
    if (count==0){
        printf("No students in the database\n\n");
        return;
    }
    printf("\n--- Students List ---\n");
    for (int i =0;i<count;i++){
        printf("Roll: %d | Name: %s | Marks: %.2f\n",students[i].roll,students[i].name,students[i].marks);
    }
    printf("\n");
}

void searchStudents(){
    int roll;
    printf("Enter the roll number to search: ");
    scanf("%d",&roll);

    for (int i=0;i<count;i++){
        if (students[i].roll==roll){
            printf("Found: %s, Marks: %.2f\n\n",students[i].name,students[i].marks);
            return;
        }
    }
    printf("Student not found!\n\n");
}

void savetoFile(){
    FILE *fp =fopen("students.txt","w");
    if (fp==NULL){
        printf("Error opening the file!");
        return;
    }

    for (int i =0;i<count;i++){
        fprintf(fp,"%d,%s,%.2f\n",students[i].roll,students[i].name,students[i].marks);
    }

    fclose(fp);
    printf("Data successfully saved to students.txt !");
}

void loadfromFile(){
    FILE *fp = fopen("students.txt","r");
    if (fp==NULL){
        printf("No saved file was found !");
        return;
    }
    count = 0;
    while (fscanf(fp,"%d,%49[^,],%f\n",&students[count].roll,&students[count].name,&students[count].marks)==3){
        count++;
        if (count>=MAX) break;
    }
    
    fclose(fp);
    printf("Data loaded from students.txt\n\n");
}

int main(){
    int choice;
    while (1){
        printf("===Students Database===\n");
        printf("1. Add Student\n");
        printf("2. View all students\n");
        printf("3. Search student by roll no. \n");
        printf("4. Save to file\n");
        printf("5. Load from file\n");
        printf("6. Exit!\n");
        scanf("%d",&choice);
        getchar();

        switch(choice){
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudents(); break;
            case 4: savetoFile(); break;
            case 5: loadfromFile(); break;
            case 6: printf("Bye!\n");exit(0);
            default: printf("Invalid Choice, Try again!\n");
        }

    }
    return 0;
}