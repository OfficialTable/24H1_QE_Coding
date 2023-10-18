#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <set>

using namespace std;

string foo(string s) {
    int length = s.length();
    vector<string> res;

    function<void(string, string)> dfs = [&](string sub, string cur) {
        if (cur.length() == length) {
            res.push_back(cur);
            return;
        }

        for (int i = 0; i < sub.length(); i++) {
            string newStr = cur;
            if (newStr.empty() || abs(sub[i] - newStr.back()) > 1) {
                newStr += sub[i];
                dfs(sub.substr(0, i) + sub.substr(i + 1), newStr);
            }
        }
    };

    string t = "";
    dfs(s, t);

    if (res.empty()) {
        return "";
    }

    return res.back();
}

string bar(string s) {
    set<char> uniqueChars(s.begin(), s.end());
    int length = uniqueChars.size();
    vector<string> res;

    function<void(string, string)> dfs = [&](string sub, string cur) {
        if (cur.length() == length) {
            res.push_back(cur);
            return;
        }

        for (int i = 0; i < sub.length(); i++) {
            string newStr = cur;
            if (newStr.empty() || abs(sub[i] - newStr.back()) > 1) {
                newStr += sub[i];
                dfs(sub.substr(0, i) + sub.substr(i + 1), newStr);
            }
        }
    };

    string t = "";
    dfs(s, t);

    if (res.empty()) {
        return "";
    }

    return res.back();
}

int main() {
    vector<string> input = {"abcde", "abc", "", "abccde", "abcdcef"};

    cout << "Q1_a" << endl;
    for (string i : input) {
        cout << "  input: " << i << " | output: " << foo(i) << endl;
    }

    cout << endl;

    cout << "Q1_b" << endl;
    for (string i : input) {
        cout << "  input: " << i << " | output: " << bar(i) << endl;
    }

    return 0;
}