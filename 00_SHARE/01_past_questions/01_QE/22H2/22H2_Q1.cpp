#include <iostream>
#include <vector>
#include <set>
#include <string>

#include <algorithm>

using namespace std;

vector<string> str_perm(string str) {
    vector<string> result;
    
    if (str.length() == 1) {
        result.push_back(str);
    } else {
        for (int i = 0; i < str.length(); i++) {
            string remaining = str;
            char current = str[i];
            remaining.erase(i, 1);

            vector<string> sub_perm = str_perm(remaining);
            for (string s : sub_perm) {
                result.push_back(current + s);
            }
        }
    }

    set<string> unique_set(result.begin(), result.end());
    result.assign(unique_set.begin(), unique_set.end());
    sort(result.begin(), result.end());

    return result;
}

int main() {
    string test1 = "abc";
    string test2 = "abb";

    vector<string> result1 = str_perm(test1);
    vector<string> result2 = str_perm(test2);

    cout << "\nPermutations of '" << test1 << "':" << endl;
    for (string s : result1) {
        cout << s << " ";
    }
    cout << endl;

    cout << "\nPermutations of '" << test2 << "':" << endl;
    for (string s : result2) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
