// find the longest ssubstring without repeating any one
// using rabin carb algorithem
#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    int i = 0, j = 0;
    int ans = 0;
    unordered_map<char, int> mp;
    while (j < n)
    {
        mp[s[j]]++;
        if (mp.size() == j - i + 1)
        {
            ans = max(ans, j - i + 1);
            j++;
        }
        else if (mp.size() < j - i + 1)
        {
            while (mp.size() < j - i + 1)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    cout << ans << endl;
}
