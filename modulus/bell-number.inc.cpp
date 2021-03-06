/**
 * @brief the Bell number
 * @description the number of ways a set of n elements can be partitioned into nonempty subsets
 * @see http://mathworld.wolfram.com/BellNumber.html
 * @see https://oeis.org/A110
 * @see https://ja.wikipedia.org/wiki/%E3%83%99%E3%83%AB%E6%95%B0
 * @tparam MOD must be a prime
 * @note O(n^2)
 */
template <int MOD>
mint<MOD> bell_number(int n) {
    vector<mint<MOD> > dp(n + 1);
    dp[0] = 1;
    REP (i, n) {
        REP (j, i + 1) {
            dp[i + 1] += dp[j] * choose<MOD>(i, j);
        }
    }
    return dp[n];
}

unittest {
    constexpr int MOD = 1e9 + 7;
    const ll table[] = { 1, 1, 2, 5, 15, 52, 203, 877, 4140, 21147, 115975, 678570, 4213597, 27644437, 190899322, 1382958545, 10480142147, 82864869804, 682076806159, 5832742205057, 51724158235372, 474869816156751, 4506715738447323, 44152005855084346, 445958869294805289 };
    REP (i, sizeof(table) / sizeof(ll)) {
        assert (bell_number<MOD>(i) == table[i] % MOD);
    }
    assert (bell_number<MOD>(1000) == 465231251);  // https://www.wolframalpha.com/input/?i=1000-th+bell+number+modulo+10%5E9+%2B+7
}

template <int MOD>
mint<MOD> binary_bell_number(int n, int k) {
    mint<MOD> acc = 0;
    REP3 (i, 1, k + 1) {
        acc += stirling_number_of_the_second_kind(n, i);
    }
    return acc;
}
