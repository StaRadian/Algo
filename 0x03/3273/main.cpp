#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;

    cin >> n;

    int *a = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    cin >> x;

    int result = 0;
    int temp, temp2;
    int cnt = n - 1;

    for(int i = 0; i < cnt; i++) {
        temp = a[i];
        for(int j = cnt; j > 0; j--) {
            temp2 = temp + a[j];
            if(temp2 == x) result++;
            else if(temp2 < x) {
                cnt = j;
                break;
            }
        }
    }

    cout << result;

    delete[] a;

    return 0;
}