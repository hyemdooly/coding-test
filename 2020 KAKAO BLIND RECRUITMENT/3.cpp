ng namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    
    
    
    return answer;
}

int main() {
	vector<vector<int>> key;
	vector<vector<int>> lock;

	vector<int> temp1;
	temp1.push_back(0);
	temp1.push_back(0);
	temp1.push_back(0);

	vector<int> temp2;
	temp2.push_back(1);
	temp2.push_back(0);
	temp2.push_back(0);

	vector<int> temp3;
	temp3.push_back(0);
	temp3.push_back(1);
	temp3.push_back(1);

	key.push_back(temp1);
	key.push_back(temp2);
	key.push_back(temp3);

	vector<int> temp4;
	temp1.push_back(1);
	temp1.push_back(1);
	temp1.push_back(1);

	vector<int> temp5;
	temp2.push_back(1);
	temp2.push_back(1);
	temp2.push_back(0);

	vector<int> temp6;
	temp3.push_back(1);
	temp3.push_back(0);
	temp3.push_back(1);

	lock.push_back(temp4);
	lock.push_back(temp5);
	lock.push_back(temp6);

	solution(key, lock);

}