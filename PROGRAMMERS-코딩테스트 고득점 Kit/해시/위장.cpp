#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> clothes_num;
    for(auto row : clothes) { 
        if(clothes_num.find(row[1]) == clothes_num.end()){
            clothes_num.insert(make_pair(row[1], 1));
        }else {
            clothes_num[row[1]]++;
        }
    }

    for(pair<string, int> ele : clothes_num) {
        answer *= (ele.second + 1);
    }
    answer--;
    return answer;
}