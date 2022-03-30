#include <stdio.h>
#include <queue>

void dfs(int (&image)[5][4], int x, int y, int label)
{
    if (image[y][x] == 0)
    {
        printf("[%d][%d]: %d\n", y, x, label);
        image[y][x] = label;
        if (x < 3)
            dfs(image, x + 1, y, label);
        if (y < 4)
            dfs(image, x, y + 1, label);
        if (x > 0)
            dfs(image, x - 1, y, label);
        if (y > 0)
            dfs(image, x, y - 1, label);
    }
}

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

void bfs(int (&image)[5][4], int x, int y, int label)
{
    std::queue<TPoint> q;
    q.push(TPoint(x, y));

    while (!q.empty())
    {
        TPoint pt = q.front();
        q.pop();
        if (image[pt.y][pt.x] == 0)
        {
            printf("[%d][%d]: %d\n", pt.y, pt.x, label);
            image[pt.y][pt.x] = label;
            if (pt.x < 3)
                q.push(TPoint(pt.x + 1, pt.y));
            if (pt.y < 4)
                q.push(TPoint(pt.x, pt.y + 1));
            if (pt.x > 0)
                q.push(TPoint(pt.x - 1, pt.y));
            if (pt.y > 0)
                q.push(TPoint(pt.x, pt.y - 1));
        }
    }
}

int main()
{
    int image[5][4] = {
        {0, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 1, 1}};
    int label = 2;
    for (int y = 0; y < 5; ++y)
    {
        for (int x = 0; x < 4; ++x)
        {
            if (image[y][x] == 0)
            {
                // dfs(image, x, y, label++);
                bfs(image, x, y, label++);
            }
        }
    }
    printf("count: %d\n", label - 2);
    for (int y = 0; y < 5; ++y)
    {
        for (int x = 0; x < 4; ++x)
            printf("%d", image[y][x]);
        printf("\n");
    }
    return 0;
}
