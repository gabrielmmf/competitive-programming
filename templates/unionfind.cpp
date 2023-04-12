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

id = vector<int>(n);
sz = vector<int>(n, 1);
iota(id.begin(), id.end(), 0);