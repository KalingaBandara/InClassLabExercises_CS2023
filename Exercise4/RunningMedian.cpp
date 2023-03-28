#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<int> left; // max heap to store smaller half of numbers
    priority_queue<int, vector<int>, greater<int>> right; // min heap to store larger half of numbers
    
    // read in first number
    int x;
    cin >> x;
    left.push(x);
    cout << fixed << setprecision(1) << static_cast<double>(x) << endl;

    for (int i = 2; i <= n; i++) {
        cin >> x;
        if (left.size() == right.size()) {
            // add new number to max heap
            if (x < right.top()) {
                left.push(x);
            }
            // add new number to min heap
            else {
                left.push(right.top());
                right.pop();
                right.push(x);
            }
            // median is the top element of max heap
            cout << fixed << setprecision(1) << static_cast<double>(left.top()) << endl;
        }
        else {
            // add new number to min heap
            if (x > left.top()) {
                right.push(x);
            }
            // add new number to max heap
            else {
                right.push(left.top());
                left.pop();
                left.push(x);
            }
            // median is the average of top elements of both heaps
            cout << fixed << setprecision(1) << static_cast<double>((left.top() + right.top()) / 2.0) << endl;
        }
    }

    return 0;
}
