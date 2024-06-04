
// time : O(n)
// space: O(n) due to suffMin

#include<iostream>
#include<vector>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    vector<int> suffMin(n);
    suffMin[n - 1] = h[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        suffMin[i] = min(h[i], suffMin[i + 1]);
    }

    int numCuts = 0;
    int leftMaxSoFar = h[0];

    for (int i = 0; i < n - 1; i++) {

        leftMaxSoFar = max(leftMaxSoFar, h[i]);

        // can I make a cut at ith index ?

        if (leftMaxSoFar <= suffMin[i + 1]) {
            numCuts++;
        }

    }

    cout << numCuts + 1 << endl;

}