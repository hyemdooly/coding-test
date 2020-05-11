#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int pick1[] = {1, 2, 3, 4, 5}; // 5
    int pick2[] = {2, 1, 2, 3, 2, 4, 2, 5}; // 8
    int pick3[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}; // 10
    
    int grade1 = 0;
    int grade2 = 0;
    int grade3 = 0;
    
    for(int i = 0 ; i < answers.size() ; i++) {
        if(pick1[i%5] == answers[i]) grade1++;
        if(pick2[i%8] == answers[i]) grade2++;
        if(pick3[i%10] == answers[i]) grade3++;
    }
    
    if(grade1 > grade2) {
        if(grade1 > grade3) answer.push_back(1);
        else if(grade1 < grade3) answer.push_back(3);
        else {
            answer.push_back(1);
            answer.push_back(3);
        }
    } else if(grade1 < grade2) {
        if(grade2 > grade3) answer.push_back(2);
        else if(grade2 < grade3) answer.push_back(3);
        else {
            answer.push_back(2);
            answer.push_back(3);
        }
    } else { // grade1 == grade2
        if(grade1 > grade3) {
            answer.push_back(1);
            answer.push_back(2);
        } else if(grade1 < grade3) {
            answer.push_back(3);
        } else { // grade1 == grade2 == grade3
            answer.push_back(1);
            answer.push_back(2);
            answer.push_back(3);
        }
    }
    
    return answer;
}