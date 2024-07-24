#include <iostream>
using namespace std;

#define lli long long int

struct point {
    lli x, y;
};

int ccw(point a, point b, point c) {
    lli CrossProduct = (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);

    if(CrossProduct > 0) return 1;
    else if(CrossProduct < 0) return -1;
    else return 0;
}

int main() {
    point a, b, c;
    int save;

    a = {1, 1}, b = {5, 3}, c = {7, 3};
    save = ccw(a, b, c);

    cout << a.x << "," << a.y << " --> " << b.x << "," << b.y << " --> " << c.x << "," << c.y << " : ";
    if(save == -1) cout << "counterclockwise" << "\n";
    else if(save == 0) cout << "straignt line" << "\n";
    else if(save == 1) cout << "clockwise" << "\n";
}