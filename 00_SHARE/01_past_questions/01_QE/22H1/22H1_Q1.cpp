#include <iostream>
#include <string>
#include <functional>
#include <vector>

using namespace std;

bool palindrome(const string& s) {
    bool flag = false;
    if (s == string(s.rbegin(), s.rend())) {
        flag = true;
    }
    return flag;
}

bool substring(const string& s, const string& t) {
    bool flag = false;
    if (s.find(t) != string::npos) {
        flag = true;
    }
    return flag;
}

vector<string> max_palindromes(const string& s) {
    int s_length = s.length();
    vector<string> pal_list;
    vector<string> max_pals_list;

    for (int i = 0; i < s_length; i++) {
        for (int j = i + 1; j <= s_length; j++) {
            string target = s.substr(i, j - i);
            if (palindrome(target) && find(pal_list.begin(), pal_list.end(), target) == pal_list.end()) {
                pal_list.push_back(target);
            }
        }
    }

    for (const string& i : pal_list) {
        bool max_flag = true;
        for (const string& j : pal_list) {
            if (i != j && substring(j, i)) {
                max_flag = false;
                break;
            }
        }
        if (max_flag) {
            max_pals_list.push_back(i);
        }
    }

    return max_pals_list;
}

int main() {
    string testa1 = "asdsa";
    string testa2 = "asddsa";
    string testa3 = "asefavsae";

    string testc1 = "kabccbadzdefgfeda";
    string testc2 = "kabccba dzabccbaza";
    string testc3 = "bbacaz";

    string sub1 = "a";
    string sub2 = "f";

    // (a) palindrome test
    cout << "(a) test" << endl;
    cout << palindrome(testa1) << endl; // True
    cout << palindrome(testa2) << endl; // True
    cout << palindrome(testa3) << endl; // False

    // (b) substring test
    cout << "\n(b) test" << endl;
    cout << substring(testc1, sub1) << endl; // True
    cout << substring(testc2, sub1) << endl; // True
    cout << substring(testc1, sub2) << endl; // True
    cout << substring(testc2, sub2) << endl; // False

    // (c) max_palindrome test
    cout << "\n(c) test" << endl;

    cout << "----[1]----" << endl;
    vector<string> max_pals1 = max_palindromes(testc1);
    for (const string& max_pal : max_pals1) {
        cout << max_pal << endl;
    }
    cout << "-----------" << endl;

    cout << "----[2]----" << endl;
    vector<string> max_pals2 = max_palindromes(testc2);
    for (const string& max_pal : max_pals2) {
        cout << max_pal << endl;
    }
    cout << "-----------" << endl;

    cout << "----[3]----" << endl;
    vector<string> max_pals3 = max_palindromes(testc3);
    for (const string& max_pal : max_pals3) {
        cout << max_pal << endl;
    }
    cout << "-----------" << endl;

    return 0;
}
