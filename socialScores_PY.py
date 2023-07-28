# PPL - HW 3 - Python Implementation for Sent Social Scores
# Jake McKnight

import csv
import sys


# this function will read through a csv file and populate the dictionary I need to reference
def populate_dict(filename):
    result_dict = {}

    try:
        with open(filename, 'r') as csvfile:
            csvreader = csv.reader(csvfile)
            for row in csvreader:
                if len(row) == 2:  # Ensure there are exactly two columns in each row
                    key, value = row
                    result_dict[key.lower()] = value  # case all characters to lowercase
                else:
                    print(f"Warning: Skipping row {row} due to invalid format.")
    except FileNotFoundError:
        print(f"Error: File '{filename}' not found.")

    return result_dict


def read_file_and_map(filename, ref_dictionary):
    counter = 0.0
    output_counter = 0

    try:
        with open(filename, 'r') as file:
            print("[word: current_score, accumulated_score]")
            # go line by line
            for line in file:
                words = line.split()
                # go word by word
                for word in words:
                    # Remove any punctuation or special characters from the word
                    word = ''.join(c for c in word if c.isalnum())
                    if word:
                        # Convert the word to lowercase for case-insensitive mapping
                        word = word.lower()
                        if word in ref_dictionary:
                            # keep a running tally of the score
                            score_for_word = float(ref_dictionary[word])
                            counter += score_for_word
                            # output the first 10 words that impact the counter for testing
                            if output_counter <= 10:
                                print(f"[{word}: {score_for_word}, {counter:.2f}]")
                                output_counter += 1
    except FileNotFoundError:
        print(f"Error: File '{filename}' not found.")

    return counter


def get_star_rating(score):
    if score < -5:
        return 1
    elif -5 <= score < -1.0:
        return 2
    elif -1.0 <= score < 1.0:
        return 3
    elif 1.0 <= score < 5.0:
        return 4
    elif score >= 5:
        return 5


if __name__ == '__main__':

    if len(sys.argv) != 2:
        print("Usage: python socialScores_PY.py <filename>")

    file_to_process = sys.argv[1]
    # pass in the reference file to use for populating the dictionary
    social_scores = populate_dict('socialsent.csv')

    # file_to_process = input("Please input the name (and associated filepath, if applicable) of the file you wish to "
    # "process: ")

    file_score = read_file_and_map(file_to_process, social_scores)

    file_stars = get_star_rating(file_score)

    print(f"{file_to_process} score: {file_score:.2f}")
    print(f"{file_to_process} Stars: {file_stars}")
