#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct student {
    char first_name[20],last_name[20];
    char branch[10];
    int roll_no;
    char city[20];
    long int pin, mobno;
};

void addstudent();
void studentrecord();
void searchstudent();
void deletestudent();

int main() {
    int choice;
    while (choice != 5) {
        printf("\n\t\t\t\tSTUDENT DATABASE SYSTEM");
        printf("\n\n\n\t\t\t1. Add Student Record");
        printf("\n\t\t\t2. View Student Records");
        printf("\n\t\t\t3. Search Students");
        printf("\n\t\t\t4. Delete Student Record");
        printf("\n\t\t\t5. Exit");
        printf("\n\t\t_______________________________________");
        printf("\n\t\t\tEnter the choice :");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            system("cls");
            addstudent();
            system("cls");
            break;
        case 2:
            system("cls");
            studentrecord();
            printf("\t\t\t\tPress any key to exit......\n");
            getch();
            system("cls");
            break;
         case 3:
            system("cls");
            printf("\n\t\t\tEnter Roll No to search: ");
            int roll_to_search;
            scanf("%d", &roll_to_search);
            searchstudent(roll_to_search);
            printf("\t\t\t\tPress any key to exit......\n");
            getch();
            system("cls");
            break;
        case 4:
            system("cls");
            printf("\n\t\t\tEnter Roll No to delete: ");
            int roll_to_delete;
            scanf("%d", &roll_to_delete);
            deletestudent(roll_to_delete);
            printf("\t\t\t\tPress enter key to delete......\n");
            getch();
            system("cls");
            break;
        }
    }

    return 0;
}

void addstudent() {
    char c;
    FILE *fp;
    struct student std;

    do {
        system("cls");
        printf("\n\t\t\t\tADD STUDENT DETAILS");
        fp = fopen("student_details.txt", "a");

        printf("\n\t\t\tFirst name     :");
        scanf("%s", std.first_name);
        printf("\n\t\t\tLast name      :");
        scanf("%s", std.last_name);
        printf("\n\t\t\tDepartment     :");
        scanf("%s", std.branch);
        printf("\n\t\t\tRoll no        :");
        scanf("%d", &std.roll_no);
        printf("\n\t\t\tCity           :");
        scanf("%s", std.city);
        printf("\n\t\t\tPincode        :");
        scanf("%ld", &std.pin);
        printf("\n\t\t\tMobile no      :");
        scanf("%ld", &std.mobno);
        printf("\n\t\t_______________________________________");

        if (fp == NULL) {
            fprintf(stderr, "\n\t\t\tCan't open the file");
        } else {
            //fprintf(fp,"%s %s %s %d %s %ld %ld",std.first_name,std.last_name,std.branch,std.roll_no,std.city,std.pin,std.mobno);
            fprintf(fp, "\n\t\t\tName           : %s %s", std.first_name,std.last_name);
            fprintf(fp, "\n\t\t\tDepartment     : %s", std.branch);
            fprintf(fp, "\n\t\t\tRoll no        : %d", std.roll_no);
            fprintf(fp, "\n\t\t\tCity           : %s", std.city);
            fprintf(fp, "\n\t\t\tPincode        : %ld", std.pin);
            fprintf(fp, "\n\t\t\tMobile no      : %ld", std.mobno);
            fprintf(fp, "\n\t\t_______________________________________");

            printf("\n\t\t\tRecord stored successfully");
        }

        fclose(fp);

        printf("\n\t\t\tDo you want to add another? (y/n)");
        scanf(" %c", &c);
    } while (c == 'y' || c == 'Y');
}

void studentrecord() {
    FILE *fp;
    struct student std;

    fp = fopen("student_details.txt", "r");

    if (fp == NULL) {
        fprintf(stderr, "\n\t\t\tCan't open the file");
        return;
    }

    printf("\n\t\t\t\tSTUDENT RECORDS");

    while (fscanf(fp, "\n\t\t\tName           : %s %s", std.first_name, std.last_name) != EOF) {
        fscanf(fp, "\n\t\t\tDepartment     : %s", std.branch);
        fscanf(fp, "\n\t\t\tRoll no        : %d", &std.roll_no);
        fscanf(fp, "\n\t\t\tCity           : %s", std.city);
        fscanf(fp, "\n\t\t\tPincode        : %ld", &std.pin);
        fscanf(fp, "\n\t\t\tMobile no      : %ld", &std.mobno);
        fscanf(fp, "\n\t\t_______________________________________");

        printf("\n\t\t\tName           : %s %s", std.first_name, std.last_name);
        printf("\n\t\t\tDepartment     : %s", std.branch);
        printf("\n\t\t\tRoll no        : %d", std.roll_no);
        printf("\n\t\t\tCity           : %s", std.city);
        printf("\n\t\t\tPincode        : %ld", std.pin);
        printf("\n\t\t\tMobile no      : %ld", std.mobno);
        printf("\n\t\t_______________________________________");
    }

    fclose(fp);
}

void searchstudent(int roll)
{
    FILE *fp;
    struct student std;
    int found = 0;

    fp = fopen("student_details.txt", "r");

    if (fp == NULL) {
        fprintf(stderr, "\n\t\t\tCan't open the file");
        return;
    }

    while (fscanf(fp, "\n\t\t\tName           : %s %s", std.first_name, std.last_name) != EOF)
        {
        fscanf(fp, "\n\t\t\tDepartment     : %s", std.branch);
        fscanf(fp, "\n\t\t\tRoll no        : %d", &std.roll_no);
        fscanf(fp, "\n\t\t\tCity           : %s", std.city);
        fscanf(fp, "\n\t\t\tPincode        : %ld", &std.pin);
        fscanf(fp, "\n\t\t\tMobile no      : %ld", &std.mobno);
        fscanf(fp, "\n\t\t_______________________________________");

        if (std.roll_no == roll)
        {
            found=1;
        printf("\n\t\t\tName           : %s %s", std.first_name, std.last_name);
        printf("\n\t\t\tDepartment     : %s", std.branch);
        printf("\n\t\t\tRoll no        : %d", std.roll_no);
        printf("\n\t\t\tCity           : %s", std.city);
        printf("\n\t\t\tPincode        : %ld", std.pin);
        printf("\n\t\t\tMobile no      : %ld", std.mobno);
        printf("\n\t\t_______________________________________");
        }
        }

    if (found==0) {
        printf("\n\t\t\tStudent with Roll No %d not found", roll);
    }

    fclose(fp);
}

void deletestudent(int roll)
{
    FILE *fp, *temp;
    struct student std;

    fp = fopen("student_details.txt", "r");
    temp = fopen("temp.txt", "w");

    if (fp == NULL || temp == NULL) {
        fprintf(stderr, "\n\t\t\tError opening files");
        return;
    }

    int found = 0;

    while (fscanf(fp, "\n\t\t\tName           : %s %s", std.first_name, std.last_name) != EOF)
        {
        fscanf(fp, "\n\t\t\tDepartment     : %s", std.branch);
        fscanf(fp, "\n\t\t\tRoll no        : %d", &std.roll_no);
        fscanf(fp, "\n\t\t\tCity           : %s", std.city);
        fscanf(fp, "\n\t\t\tPincode        : %ld", &std.pin);
        fscanf(fp, "\n\t\t\tMobile no      : %ld", &std.mobno);
        fscanf(fp, "\n\t\t_______________________________________");

        if (std.roll_no == roll)
        {
            found=1;
        printf("\n\t\t\tName           : %s %s", std.first_name, std.last_name);
        printf("\n\t\t\tDepartment     : %s", std.branch);
        printf("\n\t\t\tRoll no        : %d", std.roll_no);
        printf("\n\t\t\tCity           : %s", std.city);
        printf("\n\t\t\tPincode        : %ld", std.pin);
        printf("\n\t\t\tMobile no      : %ld", std.mobno);
        printf("\n\t\t_______________________________________");
        }
         else {
            //fprintf(temp, "%s %s %s %d %s %ld %ld\n", std.first_name, std.last_name, std.branch, std.roll_no, std.city, std.pin, std.mobno);
            fprintf(temp, "\n\t\t\tName           : %s %s", std.first_name,std.last_name);
            fprintf(temp, "\n\t\t\tDepartment     : %s", std.branch);
            fprintf(temp, "\n\t\t\tRoll no        : %d", std.roll_no);
            fprintf(temp, "\n\t\t\tCity           : %s", std.city);
            fprintf(temp, "\n\t\t\tPincode        : %ld", std.pin);
            fprintf(temp, "\n\t\t\tMobile no      : %ld", std.mobno);
            fprintf(temp, "\n\t\t_______________________________________");

        }
    }

    fclose(fp);
    fclose(temp);

    remove("student_details.txt");
    rename("temp.txt", "student_details.txt");

    if (!found) {
        printf("\n\t\t\tStudent with Roll No %d not found", roll);
    }
}
