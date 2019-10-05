#include<iostream>
using namespace std;

int n;
int A[30][30];
int B[2][4]= {{0,1,1,1},{1,1,0,-1}};

int algoCaro(int x, int y){
	int _x, _y, count = 1, ans = 0;
	for(int i=0; i<4; i++){
		_x = x + B[0][i];
		_y = y + B[1][i];
		while(A[_x][_y] == A[x][y]){
			_x += B[0][i];
			_y += B[1][i];
			count++;
		}	
		if(count == 5){
			ans = A[x][y];
			break;
		}
	}
	return ans;
}

void result(){
	int ans = 0;
	for(int i=1; i<n+1; i++)
		for(int j=1; j<n+1; j++){
			if(algoCaro(i,j) == 1)
				ans = 1;	
			if(algoCaro(i,j) == 2)
				ans = 2;			
		}
	if(ans == 1)
		cout << "Ti wins";
	else if(ans == 2)
		cout << "Teo wins";
	else
		cout << "Not yet";	
}

int main(){
	string s;
	freopen("caro.txt","r",stdin);
	cin >> n;

	A[n+2][n+2] = {0};
	for(int i=0; i<n+2;i++){
		A[0][i] = 0;
		A[i][0] = 0;
		A[i][n+1] = 0;
		A[n+1][i] = 0;
	}
	for(int i=0; i<n; i++){
		cin >> s;
		for(int j=0; j<n; j++){
			if(s[j] == '.')
				A[i+1][j+1] = 0;
			if(s[j] == 'x')
				A[i+1][j+1] = 1;
			if(s[j] == 'o')
				A[i+1][j+1] = 2;
		}
	}
	result();
	return 0;		
}
