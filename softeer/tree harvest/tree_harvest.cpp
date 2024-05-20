#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned short n_size;
    unsigned short apple[1000][1000];
    unsigned int banna[2][1002] = {0};
    unsigned int real_banna[2][1002] = {0};
    unsigned short melon[2][1002] = {0};
    unsigned short real_melon[2][1002] = {0};
    int mode = 0;
    int not_mode = 1;
    
    cin >> n_size;

    for(int i = 0; i < n_size; i++) {
        for(int j = 0; j < n_size; j++) {
            cin >> apple[i][j];
        }
    }

    melon[mode][1] = banna[mode][1] = real_banna[mode][1] = apple[0][0];

    for(int i = 1; i < n_size; i++) {
        for(int j = 0; j <= i; j++) {
            int x = i - j;
            int y = j;
            if(banna[mode][j] + melon[mode][j] > banna[mode][j + 1] + melon[mode][j + 1]) {
                banna[not_mode][j + 1] = banna[mode][j] + apple[y][x];
                if( melon[mode][j] < apple[y][x] ) melon[not_mode][j + 1] = apple[y][x];
                else melon[not_mode][j + 1] = melon[mode][j];
            } else {
                banna[not_mode][j + 1] = banna[mode][j + 1] + apple[y][x];
                if( melon[mode][j + 1] < apple[y][x] ) melon[not_mode][j + 1] = apple[y][x];
                else melon[not_mode][j + 1] = melon[mode][j + 1];
            }
            if(real_banna[mode][j] > real_banna[mode][j + 1]) {
                real_banna[not_mode][j + 1] = real_banna[mode][j] + apple[y][x];
                if( real_melon[mode][j] < apple[y][x] ) real_melon[not_mode][j + 1] = apple[y][x];
                else real_melon[not_mode][j + 1] = real_melon[mode][j];
            } else {
                real_banna[not_mode][j + 1] = real_banna[mode][j + 1] + apple[y][x];
                if( real_melon[mode][j + 1] < apple[y][x] ) real_melon[not_mode][j + 1] = apple[y][x];
                else real_melon[not_mode][j + 1] = real_melon[mode][j + 1];
            }
            if(real_banna[not_mode][j + 1] + real_melon[not_mode][j + 1] > banna[not_mode][j + 1] + melon[not_mode][j + 1]) {
                banna[not_mode][j + 1] = real_banna[not_mode][j + 1];
            }
        }

        if(mode == 0) {
            mode = 1;
            not_mode = 0;
        } else {
            mode = 0;
            not_mode = 1;
        }
    }

    for(int i = n_size - 1; i > 0; --i) {
        for(int j = 0; j < i; j++) {
            int x = n_size - j - 1;
            int y = j + n_size - i;
            if(banna[mode][j + 1] + melon[mode][j + 1] > banna[mode][j + 2] + melon[mode][j + 2]) {
                banna[not_mode][j + 1] = banna[mode][j + 1] + apple[y][x];
                if( melon[mode][j + 1] < apple[y][x] ) melon[not_mode][j + 1] = apple[y][x];
                else melon[not_mode][j + 1] = melon[mode][j + 1];
            } else {
                banna[not_mode][j + 1] = banna[mode][j + 2] + apple[y][x];
                if( melon[mode][j + 2] < apple[y][x] ) melon[not_mode][j + 1] = apple[y][x];
                else melon[not_mode][j + 1] = melon[mode][j + 2];
            }
            if(real_banna[mode][j + 1] > real_banna[mode][j + 2]) {
                real_banna[not_mode][j + 1] = real_banna[mode][j + 1] + apple[y][x];
                if( real_melon[mode][j + 1] < apple[y][x] ) real_melon[not_mode][j + 1] = apple[y][x];
                else real_melon[not_mode][j + 1] = real_melon[mode][j + 1];
            } else {
                real_banna[not_mode][j + 1] = real_banna[mode][j + 2] + apple[y][x];
                if( real_melon[mode][j + 2] < apple[y][x] ) real_melon[not_mode][j + 1] = apple[y][x];
                else real_melon[not_mode][j + 1] = real_melon[mode][j + 2];
            }
            if(real_banna[not_mode][j + 1] + real_melon[not_mode][j + 1] > banna[not_mode][j + 1] + melon[not_mode][j + 1]) {
                banna[not_mode][j + 1] = real_banna[not_mode][j + 1];
            }
        }

        if(mode == 0) {
            mode = 1;
            not_mode = 0;
        } else {
            mode = 0;
            not_mode = 1;
        }
    }

    cout << melon[mode][1] + banna[mode][1] << endl;

    return 0;
}