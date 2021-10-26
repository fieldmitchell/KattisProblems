#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<bool> primes(n+1, true);
    vector<int> qs;
    primes[0] = false;
    primes[1] = false;
    int m = sqrt(n);
    int count = 0;

    for(int i = 0; i < q; i++) {
        int temp;
        cin >> temp;
        qs.push_back(temp);
    }

    for(int i = 2; i <= m; i++) {
        if(primes[i]) {
            count++;
            for(int j = i*2; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }

    for(int i = m+1; i <= n; i++) {
        if(primes[i]) {
            count++;
        }
    }

    cout << count << endl;

    for(int i = 0; i < q; i++) {
        cout << primes[qs[i]] << endl;
    }
}