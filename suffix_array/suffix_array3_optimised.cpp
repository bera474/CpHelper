// It takes n*log(n) time complexity
#include <bits/stdc++.h>
using namespace std;

void count_sort(vector<int> &p, vector<int> &c)
{
    int n = p.size();

    vector<int> cnt(n);
    for (auto it : c)
    {
        cnt[it]++;
    }
    vector<int> p_new(n);
    vector<int> pos(n);
    pos[0] = 0;
    for (int i = 1; i < n; i++)
    {
        pos[i] = pos[i - 1] + cnt[i - 1];
    }
    for (auto it : p)
    {
        int i = c[it];
        p_new[pos[i]] = it;
        pos[i]++;
    }
    p = p_new;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    s += '$';
    int n = s.size();
    vector<int> p(n), c(n);

    {
        // k==0;
        vector<pair<char, int>> a(n);
        for (int i = 0; i < n; i++)
            a[i] = {s[i], i};
        sort(a.begin(), a.end());

        for (int i = 0; i < n; i++)
            p[i] = a[i].second;
        c[p[0]] = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i].first == a[i - 1].first)
            {
                c[p[i]] = c[p[i - 1]];
            }
            else
            {
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
    }

    // for other value of k
    int k = 0;
    while ((1 << k) < n)
    {
        // k->k + 1;
        for (int i = 0; i < n; i++)
        {
            p[i] = (p[i] - (1 << k) + n) % n;
        }

        count_sort(p, c);
        vector<int> c_new(n);
        c_new[p[0]] = 0;
        for (int i = 1; i < n; i++)
        {
            pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
            pair<int, int> now = {c[p[i]], c[(p[i] + (1 << k)) % n]};
            if (now == prev)
            {
                c_new[p[i]] = c_new[p[i - 1]];
            }
            else
            {
                c_new[p[i]] = c_new[p[i - 1]] + 1;
            }
        }
        c = c_new;
        k++;
    }

    // vector p stores the sorted index of all the suffix
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << " " << s.substr(p[i], n - p[i]) << "\n";
    }
    return 0;
}