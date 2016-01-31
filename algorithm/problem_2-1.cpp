#include <iostream>
#include <vector>
#include <algorithm>

static void input_sequence(std::vector<int> &sequence) {
    size_t length;
    std::cin >> length;
    sequence.resize(length);
    for (size_t i = 0; i < length; ++i) {
        std::cin >> sequence[i];
    }
}

static int longest_common_subsequence(const std::vector<int> &first_sequence,
                                      const std::vector<int> &second_sequence) {

    size_t rows_number = first_sequence.size() + 1;
    size_t columns_number = second_sequence.size() + 1;

    int subsequencies_lengths[rows_number][columns_number];
    
    for (size_t i = 0; i < rows_number; ++i) {
        subsequencies_lengths[i][0] = 0;
    }
    for (size_t i = 0; i < columns_number; ++i) {
        subsequencies_lengths[0][i] = 0;
    }

    for (size_t rows_counter = 1; rows_counter < rows_number; ++rows_counter) {
        for (size_t columns_counter = 1; columns_counter < columns_number; ++columns_counter) {
            
            if (first_sequence[rows_counter - 1] == second_sequence[columns_counter - 1]) {
                subsequencies_lengths[rows_counter][columns_counter] =
                                subsequencies_lengths[rows_counter - 1][columns_counter - 1] + 1;
            } else {
                subsequencies_lengths[rows_counter][columns_counter] =
                                std::max(subsequencies_lengths[rows_counter - 1][columns_counter],
                                        subsequencies_lengths[rows_counter][columns_counter - 1]);
            }
        }
    }

    return subsequencies_lengths[rows_number - 1][columns_number - 1];
}

int main(int argc, char const *argv[]) {

    std::vector<int> first_sequence;
    std::vector<int> second_sequence;
    input_sequence(first_sequence);
    input_sequence(second_sequence);

    std::cout << longest_common_subsequence(first_sequence, second_sequence) << std::endl;

    return 0;
}
