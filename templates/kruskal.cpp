vector<int> sz, id;

int find(int x)
{
    return id[x] = id[x] == x ? x : find(id[x]);
}

void uni(int x, int y)
{
    int x = find(x), y = find(y);
    if (x == y)
        return;
    if (sz[x] > sz[y])
        swap(x, y);
    id[x] = y;
    sz[y] += sz[x];
}

int main()
{
    int n = 2;

    id = vector<int>(n);
    sz = vector<int>(n, 1);
    iota(id.begin(), id.end(), 0);

    vector<tuple<int, int, int>> graph;

    int a, b, w;

    cin >> a >> b >> w;

    graph.emplace_back(w, a, b);

    sort(graph.begin(), graph.end());

    int c = 0;

    for (auto [w, a, b] : graph)
    {
        if (find(a) != find(b))
        {
            uni(a, b);
            c += w;
        }
    }

    return 0;
}

