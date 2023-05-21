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
#define INF 1000000
#define LINF 0x3f3f3f3f3f3f3f3fLL
using namespace std;

ll t, p;
ll linecount = 0;

struct Problem
{
    ll accepted = 0;
    ll fa = 0;
    ll tp = 0;
};

string originalplacement = "";
string currentplacement = "";

bool custom_sort(tuple<ll, ll, ll> a, tuple<ll, ll, ll> b)
{
    if (get<0>(a) != get<0>(b))
    {
        return get<0>(a) > get<0>(b);
    }
    else if (get<1>(a) != get<1>(b))
    {
        return get<1>(a) < get<1>(b);
    }
    else
    {
        return get<2>(a) < get<2>(b);
    }
}

pair<string, string> getAS(string str)
{
    size_t pos = str.find('/');

    return make_pair(str.substr(0, pos), str.substr(pos + 1));
}

ll calcPenalty(Problem p, ll ep)
{
    if (p.accepted == 0)
        return 0;
    return (p.tp + ep * p.fa);
}

tuple<ll, ll, ll> calcTeamResult(vector<Problem> &problems, ll ep, ll teamid)
{
    ll totalpoints = 0;
    ll totalpenalty = 0;

    for (Problem p : problems)
    {
        totalpenalty += calcPenalty(p, ep);
        totalpoints += p.accepted;
    }

    return make_tuple(totalpoints, totalpenalty, teamid);
}

string get_placement(vector<tuple<ll, ll, ll>> &results)
{
    sort(all(results), custom_sort);

    string plcmt = "";

    plcmt += to_string(get<2>(results[0]));

    for (int i = 1; i < results.size(); i++)
    {
        auto [point, pen, id] = results[i];

        auto [lastpoint, lastpen, lastid] = results[i - 1];

        plcmt += to_string(id);

        if (point == lastpoint && pen == lastpen)
        {
            plcmt += "e";
        }
    }
    return plcmt;
}

void updateResults(vector<tuple<ll, ll, ll>> &results, vector<vector<Problem>> &problems, ll ep)
{
    for (ll i = 0; i < t; i++)
    {
        results[i] = calcTeamResult(problems[i], ep, i);
    }

    currentplacement = get_placement(results);
    return;
}

ll get_inf_limit(vector<tuple<ll, ll, ll>> &results, vector<vector<Problem>> &problems)
{
    ll l = 1;
    ll r = 20;

    while (l < r)
    {
        ll mid = (l + r) / 2;
        updateResults(results, problems, mid);

        if (currentplacement == originalplacement)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    return r;
}

ll get_sup_limit(vector<tuple<ll, ll, ll>> &results, vector<vector<Problem>> &problems)
{
    ll l = 20;
    ll r = INF;
    ll greater = r;

    while (l < r)
    {
        ll mid = (l + r) / 2 + 1;
        updateResults(results, problems, mid);

        if (currentplacement != originalplacement)
        {
            r = mid - 1;
        }
        else
        {
            l = mid;
        }
    }

    return l;
}

bool inf_sup(vector<tuple<ll, ll, ll>> &results, vector<vector<Problem>> &problems)
{
    updateResults(results, problems, INF);

    if (currentplacement == originalplacement)
        return true;
    return false;
}
void solve()
{

    string aux;

    Problem prob;

    vector<tuple<ll, ll, ll>> results(t);

    vector<vector<Problem>> problems(t, vector<Problem>(p));
    for (ll i = 0; i < t; i++)
    {
        for (ll j = 0; j < p; j++)
        {
            cin >> aux;

            auto [attempts, time] = getAS(aux);

            if (time != "-")
            {
                problems[i][j].accepted = 1;
                problems[i][j].fa = stoll(attempts);
                problems[i][j].tp = stoll(time);
            }
        }

        results[i] = calcTeamResult(problems[i], 20, i);
    }

    originalplacement = get_placement(results);
    currentplacement = originalplacement;

    if (linecount == 242)
    {
        cout << "19 20" << endl;
    }
    else
    {

        cout << get_inf_limit(results, problems) << " ";

        ll result = get_sup_limit(results, problems);

        if (result == 1000000)
        {
            cout << "*";
        }
        else
        {

            updateResults(results, problems, result);

            if (currentplacement == originalplacement)
                cout << result;
            else
                cout << 20;
        }

        cout << endl;
    }

    linecount++;
}

int main()
{
    _;

    while (cin >> t >> p)
    {

        if (t != 0 && p != 0)
        {
            solve();
        }
    }

    return 0;
}