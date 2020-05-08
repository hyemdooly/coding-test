#include <string>
#include <vector>
#include <unordered_map>
// #include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    unordered_map<string, int> counter;
    for(auto ele : completion) {
    	if(counter.find(ele) == counter.end()) { // 못찾으면 end()를 반환하기 때문에
    		counter.insert(make_pair(ele, 1));
    	} else counter[ele]++;
    }

    for(auto ele : participant) {
    	if(counter.find(ele) == counter.end()) {
    		answer = ele;
    		break;
    	} else {
    		counter[ele]--;
    		if(counter[ele] < 0) {
    			answer = ele;
    			break;
    		}
    	}
    }
    // cout << answer << endl;
    return answer;
}
