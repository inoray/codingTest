// 프로그래머스
// 여행경로
// 문제 설명
// 주어진 항공권을 모두 이용하여 여행경로를 짜려고 합니다. 항상 "ICN" 공항에서 출발합니다.

// 항공권 정보가 담긴 2차원 배열 tickets가 매개변수로 주어질 때, 방문하는 공항 경로를 배열에 담아 return 하도록 solution 함수를 작성해주세요.

// 제한사항
// 모든 공항은 알파벳 대문자 3글자로 이루어집니다.
// 주어진 공항 수는 3개 이상 10,000개 이하입니다.
// tickets의 각 행 [a, b]는 a 공항에서 b 공항으로 가는 항공권이 있다는 의미입니다.
// 주어진 항공권은 모두 사용해야 합니다.
// 만일 가능한 경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로를 return 합니다.
// 모든 도시를 방문할 수 없는 경우는 주어지지 않습니다.
// 입출력 예
// tickets	return
// [["ICN", "JFK"], ["HND", "IAD"], ["JFK", "HND"]]	["ICN", "JFK", "HND", "IAD"]
// [["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL","SFO"]]	["ICN", "ATL", "ICN", "SFO", "ATL", "SFO"]
// 입출력 예 설명
// 예제 #1

// ["ICN", "JFK", "HND", "IAD"] 순으로 방문할 수 있습니다.

// 예제 #2

// ["ICN", "SFO", "ATL", "ICN", "ATL", "SFO"] 순으로 방문할 수도 있지만 ["ICN", "ATL", "ICN", "SFO", "ATL", "SFO"] 가 알파벳 순으로 앞섭니다.

#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
typedef map<string, vector<string>> TMapTickets;

bool dfs (TMapTickets& mapTickets, const string& from, vector<int>& visited, vector<string>& path)
{
    //if (path.size() + 1 == tickets.size())
    //    return true;

    TMapTickets::iterator itFound = mapTickets.find(from);
    if (itFound == mapTickets.end())
    {
        return false; // todo
    }

    for (int i = 0; i < itFound->second.size(); ++i)
    {
        vector<int> curVisited = visited;
        vector<string> curPath = path;
        curVisited[nextIdxs[i]] = 1;
        curPath.push_back(tickets[nextIdxs[i]][1]);
        bool bGood = dfs (tickets, tickets[nextIdxs[i]][1], curVisited, curPath);
        if (bGood)
        {
            path = curPath;
            break;
        }
    }
    return true;
}

void createMap (
    const vector<vector<string>>& tickets
    , TMapTickets& mapTickets)
{
    for (int i = 0; i < tickets.size(); ++i)
    {
        TMapTickets::iterator it = mapTickets.find(tickets[i][0]);
        if (it != mapTickets.end())
            it->second.push_back (tickets[i][1]);
        else
            mapTickets[tickets[i][0]] = vector<string>({tickets[i][1]});
    }
    //sort
    for (TMapTickets::iterator it = mapTickets.begin(); it != mapTickets.end(); ++it)
        sort(it->second.begin(), it->second.end());
}

vector<string> solution(vector<vector<string>> tickets) {
    TMapTickets mapTickets;
    createMap (tickets, mapTickets);

    vector<int> visited(tickets.size());
    vector<string> path;
    dfs (mapTickets, "ICN", visited, path);
    return path;
}
/*
int next (const vector<vector<string>>& tickets, vector<int>& visited, const string& cur)
{
    int nextIdx = -1;
    for (int i = 0; i < tickets.size(); ++i)
    {
        if (visited[i] != 0)
            continue;
        if (tickets[i][0].compare(cur) != 0)
            continue;
        if (nextIdx == -1)
            nextIdx = i;
        else if (tickets[i][1] < tickets[nextIdx][1])
            nextIdx = i;
    }
    return nextIdx;
}

vector<string> bfs (const vector<vector<string>>& tickets)
{
    vector<string> path;
    vector<int> visited(tickets.size());
    queue<int> q;
    int nextId = next(tickets, visited, "ICN");
    path.push_back("ICN");
    q.push(nextId);

    while(!q.empty())
    {
        int idx = q.front();
        q.pop();

        visited[idx] = 1;
        path.push_back(tickets[idx][1]);

        nextId = next(tickets, visited, tickets[idx][1]);
        if (-1 == nextId)
            break;
        q.push(nextId);
    }
    return path;
}

vector<string> solution(vector<vector<string>> tickets) {
    return bfs(tickets);
}
*/
int main()
{
    vector<vector<string>> tickets = {
        {"ICN", "SFO"},
        {"ICN", "ATL"},
        {"SFO", "ATL"},
        {"ATL", "ICN"},
        {"ATL", "SFO"}};

    vector<string> path = solution(tickets);
    for (int i = 0; i < path.size(); ++i)
        cout << path[i] << endl;

    return 0;
}
