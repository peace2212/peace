#include <stdio.h>
#include <string.h>

// Function to read strings
void read_strings(char *main_str, char *pattern_str, char *replace_str) {
    printf("Enter the main string: ");
    scanf("%s", main_str);
    printf("Enter the pattern string: ");
    scanf("%s", pattern_str);
    printf("Enter the replace string: ");
    scanf("%s", replace_str);
}

// Function to find and replace pattern occurrences
void find_and_replace(char *main_str, char *pattern_str, char *replace_str) {
    int main_len = strlen(main_str);
    int pattern_len = strlen(pattern_str);
    int replace_len = strlen(replace_str);

    for (int i = 0; i <= main_len - pattern_len; i++) {
        int j;

        // Check if pattern matches at current position
        for (j = 0; j < pattern_len; j++) {
            if (main_str[i+j] != pattern_str[j])
                break;
        }

        // If pattern found, replace it
        if (j == pattern_len) {
            for (j = 0; j < replace_len; j++) {
                main_str[i+j] = replace_str[j];
            }
        }
    }
}

int main() {
    char main_str[100], pattern_str[100], replace_str[100];

    // Read strings
    read_strings(main_str, pattern_str, replace_str);

    // Perform pattern matching and replacement
    find_and_replace(main_str, pattern_str, replace_str);

    // Print the modified main string
    printf("Modified string after pattern matching and replacement: %s\n", main_str);

    return 0;
}

