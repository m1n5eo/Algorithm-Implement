#include <iostream>
#include <vector>
using namespace std;

vector<int> uf;

int Find(int a) {
    if(a == uf[a]) return a;
    else return uf[a] = Find(uf[a]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a > b) uf[a] = b;
    else uf[b] = a;
}

bool Same(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a == b) return true;
    else return false;
}

int main() {
    int n = 5;

    for(int i = 0; i <= n; i++) {
        uf.push_back(i);
    }

    Union(1, 2);
    Union(2, 3);
    Union(4, 5);

    cout << "parent : ";
    for(int i = 1; i <= 5; i++) {
        cout << uf[i] << " ";
    }
    cout << "\n";

    cout << "Is 1 and 3 connected? " << Same(1, 3) << "\n";
    cout << "Is 1 and 5 connected? " << Same(1, 5) << "\n";
    cout << "Is 4 and 5 connected? " << Same(4, 5) << "\n";
}