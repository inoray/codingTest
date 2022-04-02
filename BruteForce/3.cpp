// 프로그래머스

// 카펫
// 문제 설명
// Leo는 카펫을 사러 갔다가 아래 그림과 같이 중앙에는 노란색으로 칠해져 있고 테두리 1줄은 갈색으로 칠해져 있는 격자 모양 카펫을 봤습니다.

// carpet.png

// Leo는 집으로 돌아와서 아까 본 카펫의 노란색과 갈색으로 색칠된 격자의 개수는 기억했지만, 전체 카펫의 크기는 기억하지 못했습니다.

// Leo가 본 카펫에서 갈색 격자의 수 brown, 노란색 격자의 수 yellow가 매개변수로 주어질 때 카펫의 가로, 세로 크기를 순서대로 배열에 담아 return 하도록 solution 함수를 작성해주세요.

// 제한사항
// 갈색 격자의 수 brown은 8 이상 5,000 이하인 자연수입니다.
// 노란색 격자의 수 yellow는 1 이상 2,000,000 이하인 자연수입니다.
// 카펫의 가로 길이는 세로 길이와 같거나, 세로 길이보다 깁니다.
// 입출력 예
// brown	yellow	return
// 10	2	[4, 3]
// 8	1	[3, 3]
// 24	24	[8, 6]

#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

/*
vector<int> factor (int n)
{
    vector<int> vFactor;
    vFactor.push_back(1);
    int harf = n / 2;
    for (int i = 2; i <= harf; ++i)
    {
        if (n % i == 0)
            vFactor.push_back(i);
    }
    vFactor.push_back(n);
    return vFactor;
}

vector<int> solution(int brown, int yellow) {
    vector<int> vFactor = factor(yellow);

    for (int i = 0; i < vFactor.size(); ++i)
        cout << vFactor[i] << " ";
    cout << endl;

    int area = brown + yellow;
    vector<int> answer;
    for (int i = 0; i < vFactor.size() / 2; ++i)
    {
        int h = vFactor[i];
        int w = vFactor[vFactor.size() - i - 1];
        cout << "w: " << w << ", h: " << h << endl;
        if ((h + 2) * (w + 2) == area && h * w == yellow)
        {
            answer.push_back(w + 2);
            answer.push_back(h + 2);
            break;
        }
    }
    return answer;
}
*/

vector<int> solution (int brown, int yellow)
{
    int area = brown + yellow;
    vector<int> answer;

    vector<pair<int, int>> wh;
    int sqrtArea = sqrt(area);
    for (int i = 1; i <= sqrtArea; ++i)
    {
        if (area % i == 0)
            wh.push_back(pair<int,int>(area/i, i));
    }
    for (int i = 0; i < wh.size(); ++i)
    {
        const pair<int, int>& curWh = wh[i];
        if ( (curWh.first + curWh.second) * 2 - 4 == brown )
        {
            answer.push_back(curWh.first);
            answer.push_back(curWh.second);
            break;
        }
    }
    return answer;
}

int main()
{
    vector<int> result = solution (24, 24);
    cout << result[0] << ", " << result[1];
    return 0;
}
