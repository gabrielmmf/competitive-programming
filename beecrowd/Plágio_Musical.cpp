#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define _                             \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'
#define pii pair<int, int>
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define eb emplace_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
using namespace std;

int m, t;

unordered_map<string, int> tone_index;

vector<int> song;
vector<int> subsong;
vector<int> song_p;
vector<int> subsong_p;

vector<int> getPrefix(const vector<int> &subv)
{
    int m = subv.size();
    vector<int> prefix(m);
    int size = 0;
    int i = 1;

    while (i < m)
    {
        if (subv[i] == subv[size])
        {
            size++;
            prefix[i] = size;
            i++;
        }
        else
        {
            if (size != 0)
            {
                size = prefix[size - 1];
            }
            else
            {
                prefix[i] = 0;
                i++;
            }
        }
    }

    return prefix;
}

bool search(const vector<int> &v, const vector<int> &subv)
{
    int n = v.size();
    int m = subv.size();
    vector<int> prefix = getPrefix(subv);

    int i = 0;
    int j = 0;

    while (i < n)
    {
        if (subv[j] == v[i])
        {
            i++;
            j++;
        }

        if (j >= m)
            return true;
        if (i < n && subv[j] != v[i])
        {
            if (j != 0)
            {
                j = prefix[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    return false;
}

int calcDist(int a, int b)
{
    return (12 + b - a) % 12;
}

void solve()
{
    song.clear();
    subsong.clear();
    song.resize(m, 0);
    subsong.resize(t, 0);

    song_p.clear();
    subsong_p.clear();
    song_p.resize(m - 1, 0);
    subsong_p.resize(t - 1, 0);

    string aux;
    for (int i = 0; i < m; i++)
    {
        cin >> aux;
        song[i] = tone_index[aux];
    }
    for (int i = 0; i < t; i++)
    {
        cin >> aux;
        subsong[i] = tone_index[aux];
    }

    for (int i = 1; i < m; i++)
    {
        song_p[i - 1] = calcDist(song[i], song[i - 1]);
    }
    for (int i = 1; i < t; i++)
    {
        subsong_p[i - 1] = calcDist(subsong[i], subsong[i - 1]);
    }

    if (search(song_p, subsong_p))
    {
        cout << "S" << endl;
        return;
    }

    cout << "N" << endl;
    return;
}

int main()
{
    _;

    tone_index["A"] = 1;
    tone_index["A#"] = 2;
    tone_index["Ab"] = 12;
    tone_index["B"] = 3;
    tone_index["B#"] = 4;
    tone_index["Bb"] = 2;
    tone_index["C"] = 4;
    tone_index["C#"] = 5;
    tone_index["Cb"] = 3;
    tone_index["D"] = 6;
    tone_index["D#"] = 7;
    tone_index["Db"] = 5;
    tone_index["E"] = 8;
    tone_index["E#"] = 9;
    tone_index["Eb"] = 7;
    tone_index["F"] = 9;
    tone_index["F#"] = 10;
    tone_index["Fb"] = 8;
    tone_index["G"] = 11;
    tone_index["G#"] = 12;
    tone_index["Gb"] = 10;

    while (cin >> m >> t)
    {
        if (m == 0 && t == 0)
            break;

        solve();
    }

    return 0;
}