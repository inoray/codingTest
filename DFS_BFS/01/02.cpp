#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
// 미로탈출
// start 1,1
// end left bottom

// input
// 5 6
// 101010
// 111111
// 000001
// 111111
// 111111

struct TPoint
{
    int x;
    int y;
    TPoint(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
};

int bfs(std::vector<std::vector<int>> &map, int x, int y)
{
    int h = map.size();
    int w = map[0].size();

    std::queue<TPoint> q;
    q.push(TPoint(x, y));

    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};

    while (!q.empty())
    {
        const TPoint& pt = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            TPoint next(pt.x + dx[i], pt.y + dy[i]);
            if (next.x < 0 || next.x >= w || next.y < 0 || next.y >= h)
                continue;
            if (next.x == 0 && next.y == 0)
                continue;
            if (map[next.y][next.x] == 1)
            {
                map[next.y][next.x] = map[pt.y][pt.x] + 1;
                q.push(next);
            }
        }
    }
    return map.back().back();
}

int main()
{
    int m = 0;
    int n = 0;
    std::cin >> m >> n;
    std::vector<std::vector<int>> map(m);
    for (int i = 0; i < m; ++i)
    {
        map[i].resize(n);
        for (int j = 0; j < n; ++j)
            scanf("%1d", &map[i][j]);
    }

    std::cout << "m: " << m << ", n: " << n << std::endl;
    for (int i = 0; i < static_cast<int>(map.size()); ++i)
    {
        for (int j = 0; j < static_cast<int>(map[i].size()); ++j)
            std::cout << map[i][j];
        std::cout << std::endl;
    }

    std::cout << bfs(map, 0, 0) << std::endl;

    for (int i = 0; i < static_cast<int>(map.size()); ++i)
    {
        for (int j = 0; j < static_cast<int>(map[i].size()); ++j)
            std::cout << map[i][j];
        std::cout << std::endl;
    }
    return 0;
}
