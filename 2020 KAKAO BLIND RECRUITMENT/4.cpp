#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Trie {
public:
	Trie* next[26];
	bool finish;
	Trie() : finish(false) {
		for(int i = 0 ; i < 26 ; i++) {
			if(next[i]) next[i] = 0;
		}
	}

	~Trie() {
		for(int i = 0 ; i < 26 ; i++) {
			if(next[i]) delete next[i];
		}
	}

	void insert(const char* key) {
		if(*key == '\0') {
			finish = true;
		}
		else {
			int current = *key - 'a';
			if(next[current] == NULL) {
				next[current] = new Trie();
			}
			next[current]->insert(key + 1);
		}
	}

	int find(const char* key) {
		int count = 0;
		if(*key == '\0' && finish) {
			return 1;
		}
		else if(*key == '\0' && !finish){ // 검색어 끝 && 단어 끝X
			return 0;
		}
		if(*key == '?') {
			// 하위노드 다검색해야함
			for(int i = 0 ; i < 26 ; i++) {
				if(next[i] != NULL) {
					count += next[i]->find(key+1);
				}
			}
		} else { 
			int current = *key - 'a';
			if(next[current] == NULL) return 0;
			count += next[current]->find(key+1);
		}
		return count;
	}

};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    Trie *tries = new Trie();

    for(int i = 0 ; i < words.size() ; i++) {
    	tries->insert(words[i].c_str());
    }
    for(int i = 0 ; i < queries.size() ; i++) {
    	answer.push_back(tries->find(queries[i].c_str()));
    	// cout << answer[i] << endl;
    }

    return answer;
}

int main() {
	vector<string> words;
	vector<string> queries;

	words.push_back("frodo");
	words.push_back("front");
	words.push_back("frost");
	words.push_back("frozen");
	words.push_back("frame");
	words.push_back("kakao");
	words.push_back("kaka");

	queries.push_back("fro??");
	queries.push_back("????o");
	queries.push_back("fr???");
	queries.push_back("fro???");
	queries.push_back("pro?");
	queries.push_back("????o");
	solution(words, queries);
}