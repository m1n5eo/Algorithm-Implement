#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

vector<int> makeFailure(string cmp) {
    int cmpSize = cmp.size(), j = 0;
    vector<int> failure(cmpSize, 0);

    failure[0] = -1;
    for(int i = 1; i < cmpSize; i++) {
        j = failure[i-1];

        while(cmp[i] != cmp[j+1] && j >= 0) {
            j = failure[j];
        }

        if(cmp[i] == cmp[j+1]) failure[i] = j+1;
        else failure[i] = -1;
    }

    return failure;
}

queue<int> kmp(string str, string cmp) {
    vector<int> failure = makeFailure(cmp);
    queue<int> result;
    int i = 0, j = 0;
    int strSize = str.size(), cmpSize = cmp.size();

    while(i < strSize && j < cmpSize) {
        if(str[i] == cmp[j]) {
            i += 1;
            j += 1;
        }
        else if(j == 0) i += 1;
        else j = failure[j-1]+1;

        if(j == cmpSize) {
            result.push(i-cmpSize+1);
            j = failure[j-1]+1;
        }
    }

    return result;
}

int main() {
    string str, cmp;

    getline(cin, str);
    getline(cin, cmp);

    queue<int> result = kmp(str, cmp);

    while(result.size()) {
        if(result.front() == 1) cout << "Found it in the 1st." << "\n";
        else if(result.front() == 2) cout << "Found it in the 2nd." << "\n";
        else if(result.front() == 3) cout << "Found it in the 3rd." << "\n";
        else cout << "Found it in the " << result.front() << "th." << "\n";

        result.pop();
    }
}