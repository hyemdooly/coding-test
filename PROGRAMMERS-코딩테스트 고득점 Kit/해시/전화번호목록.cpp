#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
// #include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for(int i = 0 ; i < phone_book.size() ; i++) {
        for(int j = i+1 ; j < phone_book.size() ; j++) {
            string temp = phone_book[j].substr(0, phone_book[i].size());
            if(phone_book[i] == temp) {
                answer = false;
                return answer;
            }
        }
    }
    // cout << answer << endl;
    return answer;
}

