#include <string>
#include <vector>
#include <iostream>

using namespace std;

string repeat(string p) {
    int i = 0;
    int cnt = 0;
    int isRight = 1;
    string u = "";
    string v = "";
    for(i = 0 ; i < p.length() ; i++) { // u, v로 분리
        if(p[i] == '(') {
            cnt++;
        } else {
            cnt--;
            if(cnt < 0) isRight = 0;
        }
        if(cnt == 0) {
            v = p.substr(i+1, p.length()-i-1);
            u = p.substr(0, i+1);
            break;
        }
    }

    // u는 올바른 괄호 문자열인가?
    if(isRight == 1) {
        if(v == "") return u;
        u += repeat(v);
        return u;
    } else { // u는 올바르지 않은 괄호 문자열이다.
        string temp = "(";
        temp += repeat(v);
        temp += ")";
        for(int j = 1 ; j < u.length()-1 ; j++) {
            if(u[j] == '(') temp += ')';
            else temp += '(';
        }
        return temp;
    }
    
}

string solution(string p) {
    string answer = "";
    int isRight;
    if(p == "") return answer;
    answer = repeat(p);
    // cout << answer << endl;
    return answer;
}
