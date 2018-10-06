#include <iostream>
#include <cstring>

using namespace std;

const int N = 1001;
const int INT_MAX2 = 0x7F7F7F7F;
int nums[N];
int minLen[N][N];
int index_k[N][N];
int sum[N];

int main() {

    int n;
    cin >> n;

    memset(minLen, INT_MAX2, sizeof(minLen));

    sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
        minLen[i][i] = 0;
        sum[i] = sum[i - 1] + nums[i];
        index_k[i][i] = i;
    }

    for (int l = 2; l <= n; ++l) {
        for (int i = 1; i + l <= n + 1; ++i) {
            int j = i + l - 1;
            for (int k = index_k[i][j - 1]; k <= index_k[i + 1][j]; ++k) {
                int len = minLen[i][k] + minLen[k + 1][j] + sum[j] - sum[i - 1];
                if (len < minLen[i][j]) {
                    minLen[i][j] = len;
                    index_k[i][j] = k;
                }
            }
        }
    }
    cout << minLen[1][n] << endl;

//    for (int i = 1; i < n ; ++i) {
//        for (int j = i+1; j <= n; ++j) {
//            cout<<"index_k["<<i<<"]["<<j<<"] = "<<index_k[i][j]<<"\t";
//        }
//        cout << endl;
//    }

    for (int m = 1; m <= n; ++m) {
        int i = 1, j = n;
        string code;
        while (i != j) {
            int k = index_k[i][j];
            if (m <= k) {
                code += "0";
                j = k;
            } else {
                code += "1";
                i = k + 1;
            }
        }
        cout << "word" << m << ": weight = " << nums[m] << " code = " + code << endl;
    }

    return 0;
}