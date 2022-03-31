#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

bool isDistOne (const string& a, const string& b)
{
    int dist = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] != b[i])
            dist++;
        if (dist > 1)
            return false;
    }
    return true;
}

int bfs (const string& begin, const string& target, const vector<string>& words)
{
    queue<int> q;
    vector<int> visited(words.size());
    for (int i = 0; i < words.size(); ++i)
    {
        if (isDistOne(begin, words[i]))
        {
            q.push(i);
            visited[i] = 1;
        }
    }
    int step = 0;

    while(!q.empty())
    {
        int idx = q.front();
        const string& w = words[idx];
        q.pop();
        if (w.compare(target) == 0)
        {
            step = visited[idx];
            break;
        }

        for (int i = 0; i < words.size(); ++i)
        {
            if (visited[i] != 0)
                continue;
            if (!isDistOne(w, words[i]))
                continue;
            q.push(i);
            visited[i] = visited[idx] + 1;
        }
    }
    return step;
}

int solution(string begin, string target, vector<string> words) {
    return bfs(begin, target, words);
}

int main ()
{
    string begin = "hit";
    string target = "cog";
    vector<string> words = {"hot", "dot", "dog", "lot", "log"};

    cout << solution(begin, target, words);
    return 0;
}
