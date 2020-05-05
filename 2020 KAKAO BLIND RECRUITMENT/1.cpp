#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    int len = s.length();
    int min = 1001;
    vector<string> str;
    
    if(len == 1) { // 문자열 1개 예외처리
      answer = len;
      return answer;
    }

    for(int i = 1 ; i <= len/2 ; i++) {
      int num = 1;
      int count = 0;
      string temp;
      for(int j = 0 ; j < len ; j += i) {
        str.push_back(s.substr(j, i));
        // cout << s.substr(j, i) << " ";
      }
      // cout << endl;

      str.push_back("/"); // 마지막 원소를 계산하기 위한 더미

      temp = str[0];
      for(int j = 1 ; j < str.size() ; j++) {
        if(temp == str[j]) {
          num++;
        } else {
          if(num >= 2) {
            count += temp.length()+to_string(num).length(); // a*10, a*100, a*1000과 같은 개수가 10개 이상될 수도 있어서
            num = 1;
          }
          else {
            count += temp.length();
          }
          temp = str[j];
        }
      }
      // cout << count << endl;
      if(min > count) min = count;
      str.clear();
    }
    answer = min;
    cout << answer << endl;
    return answer;
}

