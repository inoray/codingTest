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

void bfs(std::vector<std::vector<int>> &map, int x, int y)
{
    int step = 1;
    std::queue<TPoint> q;
    q.push(TPoint(x, y));

    while (!q.empty())
    {
        TPoint pt = q.front();
        q.pop();

        if (map[y][x] == 1)
        {
            map[y][x] = step++;

            if (x < map[y].size() - 1 && map[x + 1][y] == 1)
                q.push(TPoint(x + 1, y));
            if (y < map.size() - 1 && map[x][y + 1] == 1)
                q.push(TPoint(x, y + 1));
            if (x > 0 && map[x - 1][y] == 1)
                q.push(TPoint(x - 1, y));
            if (y > 0 && map[x][y - 1] == 1)
                q.push(TPoint(x, y - 1));
        }
    }
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
    bfs(map, 0, 0);
    int result = map.back().back();
    std::cout << result;
    std::cout << std::endl;
    for (int i = 0; i < static_cast<int>(map.size()); ++i)
    {
        for (int j = 0; j < static_cast<int>(map[i].size()); ++j)
            std::cout << map[i][j];
        std::cout << std::endl;
    }
    return 0;
}
