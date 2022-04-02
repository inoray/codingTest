// 프로그래머스

// 소수 찾기
// 문제 설명
// 한자리 숫자가 적힌 종이 조각이 흩어져있습니다. 흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 합니다.

// 각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때, 종이 조각으로 만들 수 있는 소수가 몇 개인지 return 하도록 solution 함수를 완성해주세요.

// 제한사항
// numbers는 길이 1 이상 7 이하인 문자열입니다.
// numbers는 0~9까지 숫자만으로 이루어져 있습니다.
// "013"은 0, 1, 3 숫자가 적힌 종이 조각이 흩어져있다는 의미입니다.
// 입출력 예
// numbers	return
// "17"	3
// "011"	2
// 입출력 예 설명
// 예제 #1
// [1, 7]으로는 소수 [7, 17, 71]를 만들 수 있습니다.

// 예제 #2
// [0, 1, 1]으로는 소수 [11, 101]를 만들 수 있습니다.

// 11과 011은 같은 숫자로 취급합니다.

#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

bool isPrimeNumber (int number)
{
    if (number < 2)
        return false;
    int limit = static_cast<int>(sqrt(number));
    for (int i = 2; i <= limit; ++i)
        if (number % i == 0)
            return false;
    return true;
}

void dfs (string numbers, string comb, int depth, set<int>& numberSet)
{
    for (int i = depth; i < numbers.size(); ++i)
    {
        comb += numbers[i];

        string tmp = comb;
        sort(tmp.begin(), tmp.end());
        do{
            numberSet.insert(atoi(tmp.c_str()));
        } while (next_permutation(tmp.begin(), tmp.end()));

        dfs(numbers, comb, i + 1, numberSet);
        comb.pop_back();
    }
}

int solution(string numbers) {
    set<int> numberSet;
    dfs (numbers, "", 0, numberSet);

    int answer = 0;
    for (set<int>::iterator it = numberSet.begin(); it != numberSet.end(); ++it)
    {
        if (isPrimeNumber(*it))
            answer++;
    }

    return answer;
}

void recursive (string comb, string others, set<int>& numberSet)
{
    if (comb != "")
    {
        numberSet.insert(stoi(comb));
        cout << comb << endl;
    }
    for (int i = 0; i < others.size(); ++i)
        recursive(comb + others[i], others.substr(0,i) + others.substr(i+1), numberSet);
}

int main ()
{
    string numbers = "1231";
    cout << solution(numbers);
    return 0;
}