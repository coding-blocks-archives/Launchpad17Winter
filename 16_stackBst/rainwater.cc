// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int harvesting(int height[], int n) {
    vector<int> left(n, 0);
    vector<int> right(n, 0);

    // max in the left
    for (int i = 1; i < n; ++i) {
        left[i] = max(height[i - 1], left[i - 1]);
        if (left[i] < height[i]) {
            left[i] = 0;
        }
    }

    // max in the right
    for (int i = n - 2; i >= 0; --i) {
        right[i] = max(height[i + 1], right[i + 1]);
        if (right[i] < height[i]) {
            right[i] = 0;
        }
    }

    // find the water trapped
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int diff = min(left[i], right[i]) - height[i];
        ans += max(diff, 0);
    }
    return ans;
}

void printVec(vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}


vector<int> nearestSmaller(int arr[], int n) {
    stack<int> s;
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        while (s.empty() == false && s.top() > arr[i]) {
            s.pop();
        }
        int smallerThanI = s.empty() ? -1 : s.top();
        ans.push_back(smallerThanI);
        s.push(arr[i]);
    }
    return ans;
}

int histogram(int height[], int n) {
    stack<int> index;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        bool flag = false;
        while (index.empty() == false && height[index.top()] > height[i]) {
            flag = true;
            int idx = index.top();
            index.pop();
            int curArea = height[idx] * (i - idx);
            ans = max(ans, curArea);
        }
        index.push(i);
    }

    int idx = index.top();
    index.pop();
    int curArea = height[idx] * (n - idx);
    ans = max(ans, curArea);

    return ans;
}

int histogram2(int height[], int n){
    // working fine
    stack<int> index;
    int ans = 0;

    for(int i = 0; i <= n; ++i){
        int curHeight = (i == n) ? 0 : height[i];
        while(index.empty() == false && height[index.top()] >= curHeight){
            int h = height[index.top()];
            index.pop();

            int idx = index.empty() ? -1 : index.top();
            int curArea = h * (i - idx - 1);
            ans = max(curArea, ans);
        }
        index.push(i);
    }
    return ans;
}

int main() {
    int height[100];
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> height[i];
    }

    // int ans = harvesting(height, n);
    // cout << ans;

    // vector<int> ans  = nearestSmaller(height, n);
    // printVec(ans);

    int ans = histogram2(height, n);
    cout << ans;
}