#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#define int long long
using namespace std;


/*
void CountRightSeq (string str, int diff)
{

    int new_diff = diff;
    int ans = 0;
    auto it = str.begin();
    //cout << str << " " << left << right << "\n";
    while (it < str.end() && (*it != '?'))
    {
        if (*it == '(')
            new_diff++;
        else if  (*it == ')' && new_diff > 0)
            new_diff--;
        else if  (*it == ')' && new_diff <= 0)
            return 0;
        it++;
    }
    if (*it == '?')
    {
        ans += CountRightSeq (string(it + 1, str.end()), new_diff + 1);
    }
    if (*it == '?' && left - right > 0)
    {
        ans += CountRightSeq (string(it + 1, str.end()), new_diff - 1);
    }
    if (it == str.end() && new_diff == 0)
    {
        ans += 1;
    }
    //cout << ans << "\n";
    return ans;

}
*/
signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    /*
    freopen("input.txt", "w",  stdout);
    for (int i = 0; i < 100; i++)
    {
        cout << '?';
    }
    */
    string str;
    cin >> str;

    int n = str.size();
    vector <vector <int>> seq;
    seq.resize(n + 2); // первый параметр от -1 до n
    for (int i = 0; i <= n + 1; i++ )
        seq[i].resize(n + 2);
    seq[0][1] = 1; // длина 0, глубина 0
    for (int i = 0; i < n ; i++ )
    {
        for (int j = 1; j <= n + 1 ; j++ )
        {
            if (str[i] == '(' || str[i] == '?' )
                seq[i + 1][j] += seq[i][j - 1];
            if (str[i] == ')' || str[i] == '?')
                seq[i + 1][j] += seq[i][j + 1];
        }
    }
    cout << seq[n][1];

    //cout << CountRightSeq(str, 0);
    return 0;
}
