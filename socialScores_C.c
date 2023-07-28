// PPL - HW 3 - Social Sent Scores
// - Jake McKnight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// taken from the length of the socialscores.csv file
#define MAX_PAIRS 6500

struct WordScore {
    char word[128];
    float score;
};

struct WordScore dictionary[MAX_PAIRS];
int total_words = 0;

void populate_dict(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File '%s' not found.\n", filename);
        return;
    }

    char line[256];
    char key[128], value[128];

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%127[^,],%127s", key, value);

        for (size_t i = 0; i < strlen(key); i++) {
            key[i] = tolower(key[i]);
        }

        strncpy(dictionary[total_words].word, key, sizeof(dictionary[total_words].word) - 1);
        dictionary[total_words].score = atof(value);
        total_words++;
    }

    fclose(file);
}

float read_file_and_map(const char* filename) {
    float counter = 0.0;

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File '%s' not found.\n", filename);
        return 0.0;
    }

    printf("[word: current_score, accumulated_score]\n");

    char word[128];
    int output_counter = 0;

    while (fscanf(file, "%127s", word) == 1) {
        char cleaned_word[128];
        int j = 0;
        for (size_t i = 0; i < strlen(word); i++) {
            if (isalnum(word[i])) {
                cleaned_word[j++] = tolower(word[i]);
            }
        }
        cleaned_word[j] = '\0';

        if (strlen(cleaned_word) > 0) {
            for (int i = 0; i < total_words; i++) {
                if (strcmp(dictionary[i].word, cleaned_word) == 0) {
                    float score_for_word = dictionary[i].score;
                    counter += score_for_word;
                    if (output_counter <= 10) {
                        printf("[%s: %.2f, %.2f]\n", cleaned_word, score_for_word, counter);
                        output_counter++;
                    }
                    break;
                }
            }
        }
    }

    fclose(file);
    return counter;
}

int get_star_rating(float score) {
    if (score < -5) {
        return 1;
    } else if (-5 <= score && score < -1.0) {
        return 2;
    } else if (-1.0 <= score && score < 1.0) {
        return 3;
    } else if (1.0 <= score && score < 5.0) {
        return 4;
    } else if (score >= 5) {
        return 5;
    }
    else {
        return 0;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char* file_to_process = argv[1];
    populate_dict("socialsent.csv");

    float file_score = read_file_and_map(file_to_process);

    int file_stars = get_star_rating(file_score);

    printf("%s score: %.2f\n", file_to_process, file_score);
    printf("%s Stars: %d\n", file_to_process, file_stars);

    return 0;
}
