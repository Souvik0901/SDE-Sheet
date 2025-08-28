#include <bits/stdc++.h>
using namespace std;
const int MOD = 1'000'000'007;
using int64 = long long;

// -------------------- nCk mod MOD --------------------
struct Binom {
    vector<int64> fact, invfact;
    int n, kmax;
    int64 modpow(int64 a, int64 e) const {
        int64 r = 1;
        while (e) {
            if (e & 1) r = r * a % MOD;
            a = a * a % MOD;
            e >>= 1;
        }
        return r;
    }
    Binom(int N) : n(N) {
        fact.resize(n + 1);
        invfact.resize(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i % MOD;
        invfact[n] = modpow(fact[n], MOD - 2);
        for (int i = n; i; --i) invfact[i - 1] = invfact[i] * i % MOD;
    }
    inline int64 C(int n, int k) const {
        if (k < 0 || k > n) return 0;
        return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
    }
};
// -----------------------------------------------------

int get_ans(int N, int K, vector<int> A) {          // pass‑by‑value as requested
    K = min(K, N);
    Binom C(N);                                     // nCk helper
    sort(A.begin(), A.end());

    // Σ_A  and  Σ_{m=2..K} C(N-1, m-1)
    int64 sumA = 0;
    for (int x : A) sumA = (sumA + x) % MOD;
    int64 coeffSum = 0;
    for (int m = 2; m <= K; ++m)
        coeffSum = (coeffSum + C.C(N - 1, m - 1)) % MOD;
    int64 negPart = sumA * coeffSum % MOD;

    // positive part
    int64 posPart = 0;
    int pref = 0;                                   // #elements strictly < current value
    for (int i = 0; i < N; ) {
        int j = i;
        while (j < N && A[j] == A[i]) ++j;
        int cnt = j - i;                            // block size
        int v   = A[i];                             // block value

        for (int m = 2; m <= K; ++m) {
            int64 chooseAll    = C.C(pref + cnt, m);
            int64 chooseSmaller= C.C(pref, m);
            int64 waysMaxV = (chooseAll - chooseSmaller + MOD) % MOD;
            if (waysMaxV == 0) continue;
            int64 add = waysMaxV * v % MOD * m % MOD;
            posPart = (posPart + add) % MOD;
        }
        pref += cnt;
        i = j;
    }

    int64 ans = (posPart - negPart) % MOD;
    if (ans < 0) ans += MOD;
    return int(ans);
}
