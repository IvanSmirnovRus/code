#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::swap;
using std::vector;

void WrongBubbleSort(vector<int>* sequence) {
  for (int iteration = 0; 
       iteration < sequence->size(); 
       ++iteration) {
    for (int element_index = 0; 
         element_index + iteration + 2 < sequence->size(); 
         ++element_index) {
      if (sequence->at(element_index + 1) < sequence->at(element_index)) {
        swap(sequence->at(element_index), sequence->at(element_index + 1));
      }
    }
  }
}

void ChooseMinimumSort(vector<int>* sequence) {
  for (int position = 0; position + 1 < sequence->size(); ++position) {
    int minimum = sequence->at(position);
    int index_of_minimum = position;
    for (int i = position + 1; i < sequence->size(); ++i) {
      if (sequence->at(i) < minimum) {
        minimum = sequence->at(i);
        index_of_minimum = i;
      }
    }
    swap(sequence->at(position), sequence->at(index_of_minimum));
  }
}

void OutputSequence(const string& name, 
                    const vector<int>& sequence) {
  cout << name;
  for (int i = 0; i < sequence.size(); ++i) {
    cout << ' ' << sequence[i];
  }
  cout << endl;
}


int main() {
  const int MAX_SEQUENCE_LENGTH = 10;
  const int MAX_ELEMENT = 10;
  srand(239);
  while (true) {
    int sequence_length = rand() % MAX_SEQUENCE_LENGTH + 1;
    vector<int> sequence;
    for (int i = 0; i < sequence_length; ++i) {
      sequence.push_back(rand() % MAX_ELEMENT + 1);
    }
    vector<int> sequence_copy_for_bubble_sort = sequence;
    WrongBubbleSort(&sequence_copy_for_bubble_sort);
    vector<int> sequence_copy_for_minimum_sort = sequence;
    ChooseMinimumSort(&sequence_copy_for_minimum_sort);
    if (sequence_copy_for_bubble_sort != sequence_copy_for_minimum_sort) {
      cout << "Wrong Answer!" << endl;
      OutputSequence("Test:", sequence);
      OutputSequence("Bubble sort:", sequence_copy_for_bubble_sort);
      OutputSequence("Minimum sort:", sequence_copy_for_minimum_sort);
      break;
    } else {
      cout << "OK" << endl;
    }
  }
  return 0;
}
