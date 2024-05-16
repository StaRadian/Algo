#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;

    cin >> a >> b >> c;

    int abc = a * b * c;

    string s_abc = to_string(abc);
    int num_cnt[10] = {0};

    for(char c : s_abc) {
        num_cnt[c-'0']++;
    }

    for(int i = 0; i < 10; i++) {
        cout << num_cnt[i] << endl;
    }

    return 0;
}