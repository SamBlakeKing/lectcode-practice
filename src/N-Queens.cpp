#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> result;
		vector<string> temp;
		string *LIST = new string[n];
		if (0 == n)
			return result;

		int **graph = new int*[n];
		int i, j;

		for (i = 0; i < n; i++)
			graph[i] = new int[n];
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				graph[i][j] = -1;

		string q(n, '.');
		for (i = 0; i < n; i++){
			q[i] = 'Q';
			LIST[i] = q;
			q[i] = '.';
		}

		/*for (i = 0; i < n; i++)
			cout << LIST[i] << endl;*/
		//cout << endl;

		chechNQueens(graph, 0, n, result, temp, LIST);
		for (i = 0; i < n; i++)
			delete[] graph[i];
		delete[]graph;

		delete[]LIST;

		return result;
	}

	void chechNQueens(int **graph, int index, int n, vector<vector<string>> &result, vector<string> &temp, string *LIST){
		if (index == n){
			result.push_back(temp);
			return;
		}

		int i, sum = 0;
		for (i = 0; i < n; i++)
			if (-1 == graph[index][i]){
				addPawn(graph, index, i, n);

				/*cout << index << endl;
				for (int x = 0; x < n; x++){
				for (int y = 0; y < n; y++)
				cout << graph[x][y] << " ";
				cout << endl;
				}*/

				
				if (check(graph, index + 1, n)){
					//cout << LIST[i] << endl;
					temp.push_back(LIST[i]);
					chechNQueens(graph, index + 1, n, result, temp, LIST);
					temp.pop_back();
				}
				

				deletePawn(graph, index, i, n);

				/*cout << index << endl;
				for (int x = 0; x < n; x++){
				for (int y = 0; y < n; y++)
				cout << graph[x][y] << " ";
				cout << endl;
				}*/
			}
	}

	bool check(int **graph, int index, int n){
		int i, j, sum;
		for (i = index; i < n; i++){
			sum = 0;
			for (j = 0; j < n; j++)
				if (-1 == graph[i][j])
					sum++;
			if (0 == sum)
				return false;
		}
		return true;
	}

	void addPawn(int **graph, int x, int y, int n){
		int i, j;
		for (i = 0; i < n; i++)
			if (-1 == graph[x][i])
				graph[x][i] = x;
		for (j = 0; j < n; j++)
			if (-1 == graph[j][y])
				graph[j][y] = x;
		i = x - 1;
		j = y - 1;
		while (i >= 0 && j >= 0){
			if (-1 == graph[i][j])
				graph[i][j] = x;
			i--;
			j--;
		}
		i = x + 1;
		j = y + 1;
		while (i < n && j < n){
			if (-1 == graph[i][j])
				graph[i][j] = x;
			i++;
			j++;
		}

		i = x + 1;
		j = y - 1;
		while (i <n && j >= 0){
			if (-1 == graph[i][j])
				graph[i][j] = x;
			i++;
			j--;
		}
		i = x - 1;
		j = y + 1;
		while (i >= 0 && j < n){
			if (-1 == graph[i][j])
				graph[i][j] = x;
			i--;
			j++;
		}
	}

	void deletePawn(int **graph, int x, int y, int n){
		int i, j;
		for (i = 0; i < n; i++)
			if (x == graph[x][i])
				graph[x][i] = -1;
		for (j = 0; j < n; j++)
			if (x == graph[j][y])
				graph[j][y] = -1;
		i = x - 1;
		j = y - 1;
		while (i >= 0 && j >= 0){
			if (x == graph[i][j])
				graph[i][j] = -1;
			i--;
			j--;
		}
		i = x + 1;
		j = y + 1;
		while (i < n && j < n){
			if (x == graph[i][j])
				graph[i][j] = -1;
			i++;
			j++;
		}
		i = x + 1;
		j = y - 1;
		while (i <n && j >= 0){
			if (x == graph[i][j])
				graph[i][j] = -1;
			i++;
			j--;
		}
		i = x - 1;
		j = y + 1;
		while (i >= 0 && j < n){
			if (x == graph[i][j])
				graph[i][j] = -1;
			i--;
			j++;
		}
	}
};

int N_Queens(){
	Solution a;
	int i,j;

	vector<vector<string>> res;
	vector<string> temp;
	res = a.solveNQueens(3);

	//cout << res.size() << endl;
	for (i = 0; i < res.size(); i++){
		temp = res[i];

		//cout << temp.size() << endl;
		for (j = 0; j < temp.size(); j++)
			cout << temp[j] << endl;
		cout << endl;
	}

	cin >> i;

	return 0;
}