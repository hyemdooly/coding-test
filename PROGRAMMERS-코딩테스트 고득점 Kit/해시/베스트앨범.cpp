#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> total;
    for(int i = 0 ; i < genres.size() ; i++) {
        if(total.find(genres[i]) == total.end()) {
            total.insert(make_pair(genres[i], plays[i]));
        } else{
            total[genres[i]] += plays[i];
        }
    }

    while(!total.empty()) {
        string genre = "";
        int play = 0;
        int count = 0;
        vector<pair<int, int> > temp; // <plays, 고유번호i>

        for(pair<string, int> ele : total) { // max찾기
            if(ele.second > play) {
                play = ele.second;
                genre = ele.first;
            }
        }
        total.erase(genre); // 다음 max를 위해 삭제하기

        for(int i = 0 ; i < genres.size() ; i++) {
            if(genres[i] == genre) {
                temp.push_back(make_pair(plays[i], i));
            }
        }
        sort(temp.begin(), temp.end(), cmp);
        for(pair<int, int> ele : temp) {
            // cout << ele.first << " " << ele.second << endl;
            answer.push_back(ele.second);
            count++;
            if(count == 2) break;
        }
    }
    return answer;
}
