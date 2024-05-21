// Project UID db1f506d06d84ab787baf250c265e24e
#include <iostream>
#include <vector>
#include <map>
#include "csvstream.h"
#include <set>
#include <utility>
#include <string>
using namespace std;

// check command line arguments - check
// construct classifier adt -
// train classifier on training data
// classify items in testing data
//
// * The total number of posts in the entire training set. -- int
// * The number of unique words in the entire training set. (The vocabulary size.) -- int
// * For each word w, the number of posts in the entire training set that contain w.
// -- map (key = word w, value = numPosts)
// * For each label C, the num of posts with that label. -- map (key = label c, numPosts)
// * For each label C and word w, the number of posts with label C that contain w.
// -- map of pairs: map<pair<string,string>, int> my_map; -- pair<string, string> is key,
//    int is value
// -- or map of maps: map<string, map<string, int>> my_map; --

class Classifier {
private:
    double num_posts;
    int vocab_size;
    set<string> labels;
    set<string> words;
    map<string, int> map_each_w;
    map<string, int> map_each_c;
    map<string, map<string, int>> map_each_w_c;
public:
    // reads in test.csv file for the words
    // stores info into private member variables
    // predicted label function
    // probability score function
    // two fxns to print out stats
    set<string> unique_words(const string &str) {
     // Fancy modern C++ and STL way to do it
        istringstream source{str};
     return {istream_iterator<string>{source},
             istream_iterator<string>{}};
    }
    void read_train_file(csvstream csvin) {
        map<string, string> row;
        // edit this v
        while (csvin >> row) {
            // A row is a map<string, string> key = column name, value = datum
            cout << "row: " << "\n";
            for (auto &col:row) {
                const string &column_name = col.first;
                const string &datum = col.second;
                cout << " " << column_name << ": " << datum << "\n";
            }
    }
    }
  };

int main(int argc, char* argv[]) {
    cout.precision(3);
    // debug mode
    if (argc == 4 && string(argv[3]) == "--debug") {
    ifstream fin;
    ifstream fin2;
    string training = argv[1];
    string testing = argv[2];
    fin.open(training);
    if (!fin.is_open()) {
        cout << "Error opening file: " << training << endl;
        return 1;
    }
    fin2.open(testing);
    if (!fin.is_open()) {
        cout << "Error opening file: " << testing << endl;
        return 1;
    }
    csvstream train_file(fin);
    csvstream test_file(fin2);
//        csvstream csvin(fin);
//        csvstream train_file(argv[1]);
//        csvstream test_file(argv[2]);
//        Classifier (train_file);
    }
    else if (argc == 3) {
        return 1;
    }
    else {
        cout << "Usage: main.exe TRAIN_FILE TEST_FILE [--debug]" << endl;
        return 1;
    }
}
