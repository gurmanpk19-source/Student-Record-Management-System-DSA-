#include <stdio.h>
#include <stdlib.h>

struct student {
    int roll;
    char name[50];
    float marks;
    struct student *next;
};

struct student *head = NULL;

// Insert
void insert() {
    struct student *newnode = (struct student*)malloc(sizeof(struct student));

    printf("Enter Roll No: ");
    scanf("%d", &newnode->roll);

    printf("Enter Name: ");
    scanf("%s", newnode->name);

    printf("Enter Marks: ");
    scanf("%f", &newnode->marks);

    newnode->next = head;
    head = newnode;

    printf("Student Added Successfully!\n");
}

// Display
void display() {
    struct student *temp = head;

    if(temp == NULL) {
        printf("No Records Found!\n");
        return;
    }

    while(temp != NULL) {
        printf("Roll: %d | Name: %s | Marks: %.2f\n",
               temp->roll, temp->name, temp->marks);
        temp = temp->next;
    }
}

// Search
void search() {
    int roll;
    printf("Enter Roll No to Search: ");
    scanf("%d", &roll);

    struct student *temp = head;

    while(temp != NULL) {
        if(temp->roll == roll) {
            printf("Student Found: %s (%.2f marks)\n",
                   temp->name, temp->marks);
            return;
        }
        temp = temp->next;
    }

    printf("Student Not Found!\n");
}

// Delete
void deleteStudent() {
    int roll;
    printf("Enter Roll No to Delete: ");
    scanf("%d", &roll);

    struct student *temp = head, *prev = NULL;

    if(temp != NULL && temp->roll == roll) {
        head = temp->next;
        free(temp);
        printf("Deleted Successfully!\n");
        return;
    }

    while(temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Student Not Found!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("Deleted Successfully!\n");
}

// Main
int main() {
    int choice;

    while(1) {
        printf("\n1.Insert\n2.Display\n3.Search\n4.Delete\n5.Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: insert(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: deleteStudent(); break;
            case 5: exit(0);
            default: printf("Invalid Choice!\n");
        }
    }
}