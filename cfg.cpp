
#include<bits/stdc++.h>
using namespace std;

bool found = false;
string path;

void cfg(vector<string> baseA, string target, string curr, string currPath) {
    if (found)
        return;

    if(curr.size()>target.size()+2)
    return;

    if (curr.find('S') == string::npos && curr!=" ") {
        if (curr == target) {
            found = true;
            path = currPath;
        }
        return;
    }

    for (string x : baseA) {
        if (curr.find('S') != string::npos) {
            string temp = curr.substr(0, curr.find('S'));
            temp += x;
            temp += curr.substr(curr.find('S') + 1);
            x = temp;
        }
        cfg(baseA, target, x, currPath+"->"+x);
        if (found)
            return;
    }
}

int main() {
    vector<string> baseA = { "SS", "(S)", "()" };
    string s;
    cin >> s;
    cfg(baseA, s, " ", path);

    found ? cout << "S" << path << endl : cout << "Rejected" << endl;
    return 0;
}
