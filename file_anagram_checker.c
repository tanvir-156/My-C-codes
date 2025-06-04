#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 200

void normalize_string(char *str, char *result) {
    int index = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            result[index++] = tolower(str[i]); 
        }
    }
    result[index] = '\0'; 
}

int are_anagrams(char *str1, char *str2) {
    int count[26] = {0}; 

    for (int i = 0; str1[i] != '\0'; i++) {
        count[str1[i] - 'a']++;
    }
    for (int i = 0; str2[i] != '\0'; i++) {
        count[str2[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    FILE *file1, *file2;
    char line1[MAX_LENGTH], line2[MAX_LENGTH];
    char normalized1[MAX_LENGTH], normalized2[MAX_LENGTH];

    file1 = fopen("file1.txt", "r");
    file2 = fopen("file2.txt", "r");
    if (file1 == NULL || file2 == NULL) {
        printf("Error: Unable to open input files.\n");
        return 1;
    }

    while (fgets(line1, MAX_LENGTH, file1) && fgets(line2, MAX_LENGTH, file2)) {
        line1[strcspn(line1, "\n")] = '\0';
        line2[strcspn(line2, "\n")] = '\0';

        normalize_string(line1, normalized1);
        normalize_string(line2, normalized2);

        if (are_anagrams(normalized1, normalized2)) {
            printf("\"%s\" and \"%s\" are anagrams.\n", line1, line2);
        } else {
            printf("\"%s\" and \"%s\" are not anagrams.\n", line1, line2);
        }
    }

    fclose(file1);
    fclose(file2);

    return 0;
}
