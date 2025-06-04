#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 400

struct phone_directory {
    int id;
    char name[80];
    char number[25];
} phone[MAX];

int loc = 0;

int menu();
void enter();
void find();
void save();
void load();

int main() {
    int choice;
    while ((choice = menu()) != 5) {
        switch (choice) {
            case 1: enter(); break;
            case 2: find(); break;
            case 3: save(); break;
            case 4: load(); break;
        }
        if (choice != 5) {
            printf("\nPress any key to continue ...\n");
            getchar(); 
        }
    }
    return 0;
}

int menu() {
    int i;
    printf("Welcome to Computerized Telephone Directory\n");
    printf("--------------------------------------------\n");
    printf("1. Enter names and numbers\n");
    printf("2. Find numbers\n");
    printf("3. Save directory to disk\n");
    printf("4. Load directory from disk\n");
    printf("5. Quit\n");

    do {
        printf("Enter your choice: ");
        i = atoi(fgets((char[10]){0}, 10, stdin));
    } while (i < 1 || i > 5);

    return i;
}

void enter() {
    if (loc >= MAX) {
        printf("Directory is full!\n");
        return;
    }

    printf("\nEnter ID: ");
    phone[loc].id = atoi(fgets((char[10]){0}, 10, stdin));

    if (phone[loc].id == 0) {
        printf("Invalid ID entered. Entry will be discarded.\n");
        return;
    }

    printf("Enter name: ");
    fgets(phone[loc].name, sizeof(phone[loc].name), stdin);
    phone[loc].name[strcspn(phone[loc].name, "\n")] = 0;  

    printf("Enter phone number: ");
    fgets(phone[loc].number, sizeof(phone[loc].number), stdin);
    phone[loc].number[strcspn(phone[loc].number, "\n")] = 0;  

    loc++;

    printf("\nEntry saved successfully.\n");
}

void find() {
    int id;
    printf("\nEnter ID: ");
    id = atoi(fgets((char[10]){0}, 10, stdin));

    for (int i = 0; i < loc; i++) {
        if (id == phone[i].id) {
            printf("Name: %s\n", phone[i].name);
            printf("Number: %s\n", phone[i].number);
            return;
        }
    }

    printf("\nNo entry found for ID '%d'.\n", id);
}

void load() {
    FILE *fp = fopen("phone.txt", "r");
    if (!fp) {
        printf("\nCannot open file.\n");
        return;
    }

    loc = 0;
    while (fscanf(fp, "%d %[^\n] %[^\n]", &phone[loc].id, phone[loc].name, phone[loc].number) != EOF && loc < MAX) {
        loc++;
    }
    fclose(fp);
    printf("\nLoad complete.\n");
}

void save() {
    FILE *fp = fopen("phone.txt", "w");
    if (!fp) {
        printf("\nCannot open file.\n");
        return;
    }

    for (int i = 0; i < loc; i++) {
        fprintf(fp, "%d %s %s\n", phone[i].id, phone[i].name, phone[i].number);
    }
    fclose(fp);
    printf("\nSave complete.\n");
}
