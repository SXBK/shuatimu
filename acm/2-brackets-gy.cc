#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool matchPair(char a, char b) {
    if (a == '(' && b == ')') {
        return true;
    }

    if (a == '[' && b == ']') {
        return true;
    }

    return false;
}

int main() {
    int num;
    string stmp;
    cin >> num;
    vector<vector<char> > vstr;
    vector<bool> res;
    vector<char> tmp;
    getline(cin, stmp);

    for (int i = 0; i < num; ++i) {
        char a;
        vector<char> vc;
        cin.get(a);

        while (a != '\n') {
            vc.push_back(a);
            cin.get(a);
        }

        vstr.push_back(vc);
    }

    for (int i = 0; i < vstr.size(); ++i) {
        tmp.push_back(vstr[i][0]);

        for (int j = 1; j < vstr[i].size(); ++j) {
            if (tmp.size() > 0 && matchPair(tmp[tmp.size() - 1], vstr[i][j])) {
                tmp.pop_back();
            } else {
                tmp.push_back(vstr[i][j]);
            }
        }

        if (0 == tmp.size()) {
            res.push_back(true);
        } else {
            res.push_back(false);
        }

        tmp.clear();
    }

    for (int i = 0; i < vstr.size(); ++i) {
        if (res[i]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
