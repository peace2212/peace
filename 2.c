#include <stdio.h>
#include <string.h>

void read_strings(char *main_str, char *pattern_str, char *replace_str) {
    printf("Enter the main string: ");
    scanf("%s", main_str);
    printf("Enter the pattern string: ");
    scanf("%s", pattern_str);
    printf("Enter the replace string: ");
    scanf("%s", replace_str);
}


void find_and_replace(char *main_str, char *pattern_str, char *replace_str) {
    int main_len = strlen(main_str);
    int pattern_len = strlen(pattern_str);
    int replace_len = strlen(replace_str);

    for (int i = 0; i <= main_len - pattern_len; i++) {
        int j;

        
        for (j = 0; j < pattern_len; j++) {
            if (main_str[i+j] != pattern_str[j])
                break;
        }

        
        if (j == pattern_len) {
            for (j = 0; j < replace_len; j++) {
                main_str[i+j] = replace_str[j];
            }
        }
    }
}

int main() {
    char main_str[100], pattern_str[100], replace_str[100];

    
    read_strings(main_str, pattern_str, replace_str);

    
    find_and_replace(main_str, pattern_str, replace_str);

    
    printf("Modified string after pattern matching and replacement: %s\n", main_str);

    return 0;
}

