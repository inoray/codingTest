// 프로그래머스

// 모의고사
// 문제 설명
// 수포자는 수학을 포기한 사람의 준말입니다. 수포자 삼인방은 모의고사에 수학 문제를 전부 찍으려 합니다. 수포자는 1번 문제부터 마지막 문제까지 다음과 같이 찍습니다.

// 1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
// 2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
// 3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...

// 1번 문제부터 마지막 문제까지의 정답이 순서대로 들은 배열 answers가 주어졌을 때, 가장 많은 문제를 맞힌 사람이 누구인지 배열에 담아 return 하도록 solution 함수를 작성해주세요.

// 제한 조건
// 시험은 최대 10,000 문제로 구성되어있습니다.
// 문제의 정답은 1, 2, 3, 4, 5중 하나입니다.
// 가장 높은 점수를 받은 사람이 여럿일 경우, return하는 값을 오름차순 정렬해주세요.
// 입출력 예
// answers	return
// [1,2,3,4,5]	[1]
// [1,3,2,4,2]	[1,2,3]
// 입출력 예 설명
// 입출력 예 #1

// 수포자 1은 모든 문제를 맞혔습니다.
// 수포자 2는 모든 문제를 틀렸습니다.
// 수포자 3은 모든 문제를 틀렸습니다.
// 따라서 가장 문제를 많이 맞힌 사람은 수포자 1입니다.

// 입출력 예 #2

// 모든 사람이 2문제씩을 맞췄습니다.

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> a(answers.size());
    vector<int> b(answers.size());
    vector<int> c(answers.size());

    const int patternB[4] = {1,3,4,5};
    const int patternC[5] = {3,1,2,4,5};
    int idxB = 0;
    int idxC = 0;
    for (int i = 0; i < answers.size(); ++i)
    {
        a[i] = i % 5 + 1;
        b[i] = i % 2 == 0 ? 2 : patternB[idxB++];
        c[i] = patternC[idxC];
        if (i % 2 == 1)
            idxC++;

        if (idxB >= 4)
            idxB = 0;
        if (idxC >= 5)
            idxC = 0;
    }

    int cntA = 0;
    int cntB = 0;
    int cntC = 0;
    int max = 0;
    for (int i = 0; i < answers.size(); ++i)
    {
        cntA = answers[i] == a[i] ? cntA + 1 : cntA;
        cntB = answers[i] == b[i] ? cntB + 1 : cntB;
        cntC = answers[i] == c[i] ? cntC + 1 : cntC;
    }
    if (cntA > max)
        max = cntA;
    if (cntB > max)
        max = cntB;
    if (cntC > max)
        max = cntC;


    vector<int> answer;
    if (max == cntA)
        answer.push_back(1);
    if (max == cntB)
        answer.push_back(2);
    if (max == cntC)
        answer.push_back(3);
    return answer;
}

int main () {
    vector<int> answers = {1,3,2,4,2};
    vector<int> result = solution (answers);
    for (int i = 0; i < result.size(); ++i)
        cout << result[i] << ", ";
    return 0;
}