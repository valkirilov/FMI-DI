#include <iostream>

using namespace std;

pair<int, int> find_most_distanced_chars(string input) {
    int min_index = 0;
    int max_index = 0;
    int max_distance = 0;

    for (int i=0; i < input.length(); ++i) {
        for (int j=input.length()-1; j > i; --j) {
            if (input[i] == input[j]) {
                if (j - i > max_distance) {
                    max_distance = j - i;
                    min_index = i;
                    max_index = j;
                }
            }
        }
    }

    return pair<int, int>(min_index, max_index);
}

int main(int argc, char** argv) {

    string input = "this is just a simple example";
    pair<int, int> output = find_most_distanced_chars(input);
    cout << input << ": " << output.first << " - " << output.second << endl;

    string input2 = "this is this";
    pair<int, int> output2 = find_most_distanced_chars(input2);
    cout << input2 << ": " << output2.first << " - " << output2.second << endl;

    string input3 = "abcf";
    pair<int, int> output3 = find_most_distanced_chars(input3);
    cout << input3 << ": " << output3.first << " - " << output3.second << endl;

    return 0;
}