#include <iostream>

using namespace std;

//Follow up for N-Queens problem,return the total number of distinct solutions.
//其他解法，主是用main(2 * n - 1)保存主对角线上是否使用，anti(2 * n - 1）保存副对角线是否被使用
//int totalNQueens(int n) {
//	vector<bool> col(n, true);
//	vector<bool> anti(2 * n - 1, true);
//	vector<bool> main(2 * n - 1, true);
//	vector<int> row(n, 0);
//	int count = 0;
//	dfs(0, row, col, main, anti, count);
//	return count;
//}
//void dfs(int i, vector<int> &row, vector<bool> &col, vector<bool>& main, vector<bool> &anti, int &count) {
//	if (i == row.size()) {
//		count++;
//		return;
//	}
//	for (int j = 0; j < col.size(); j++) {
//		if (col[j] && main[i + j] && anti[i + col.size() - 1 - j]) {
//			row[i] = j;
//			col[j] = main[i + j] = anti[i + col.size() - 1 - j] = false;
//			dfs(i + 1, row, col, main, anti, count);
//			col[j] = main[i + j] = anti[i + col.size() - 1 - j] = true;
//		}
//	}
//}

class Solution {
public:
	int totalNQueens(int n) {
		if (0 == n)
			return 0;
		/*if (1 == n)
			return 1;*/

		int **graph = new int*[n];
		int i, j;
		for (i = 0; i < n; i++)
			graph[i] = new int[n];
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				graph[i][j] = -1;

		int res = chechNQueens(graph, 0, n);
		for (i = 0; i < n; i++)
			delete[] graph[i];
		delete[]graph;
		
		return res;
	}

	int chechNQueens(int **graph, int index,int n){
		if (index == n)
			return 1;

		int i,sum = 0;
		for (i = 0; i < n; i++)
			if (-1 == graph[index][i]){
				addPawn(graph, index, i, n);

				/*cout << index << endl;
				for (int x = 0; x < n; x++){
					for (int y = 0; y < n; y++)
						cout << graph[x][y] << " ";
					cout << endl;
				}*/

				if (check(graph, index + 1, n))
					sum = sum + chechNQueens(graph, index + 1, n);
				/*else if (n == index + 1)
					sum++;*/

				deletePawn(graph, index, i, n);

				/*cout << index << endl;
				for (int x = 0; x < n; x++){
					for (int y = 0; y < n; y++)
						cout << graph[x][y] << " ";
					cout << endl;
				}*/
			}
		return sum;
	}

	bool check(int **graph, int index,int n){
		int i, j,sum;
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

	void addPawn(int **graph, int x, int y,int n){
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

int main(){
	Solution a;
	int i;

	cout << a.totalNQueens(8)<<endl;

	cin >> i;
	
	return 0;
}