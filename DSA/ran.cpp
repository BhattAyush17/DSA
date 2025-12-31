
#include <iostream>
using namespace std;

int main() {
    int n;
    cout <<"Enter number of rows:";
    cin >> n;

    string prev = "1";   

    for (int i = 1; i <= n; i++) {
        cout << prev << endl;   

        string next = ""; 
        int count = 1;

        for (int j = 1; j < prev.size(); j++) {
            if (prev[j] == prev[j-1]) {
                count++;
            } else {
                next += to_string(count);
                next += prev[j-1];
                count = 1;
            }
        }

        next += to_string(count);
        next += prev.back();

        prev = next;  
    }
}
