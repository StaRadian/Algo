#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;

    cin >> n >> x;

    int *a = new int[n];
    int a_temp, cnt = 0;

    for(int i = 0; i < n; i++) {
        cin >> a_temp;
        if(a_temp < x) {
            a[cnt] = a_temp;
            cnt++;
        }
    }

    for(int i = 0; i < cnt; i++) {
        cout << a[i] << " ";
    }

    delete[] a;
    return 0;
}