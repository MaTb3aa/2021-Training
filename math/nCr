#include<iostream>
#include <math.h>
 using namespace std;
double Rec(double n, double r){
	if(r == 0)
		return 1;
return (n/r)*Rec(n-1,r-1);
}
 
int main(){
	double n, r;
	double res;
 
	cin>> n >> r;
    res = round(Rec(n,r));
	cout<< long(res) << endl;
}
-------------------------------------------
	long long arr[100][100] = { 0};
	for (int i = 0; i <= 70; i++){ arr[i][i] = arr[i][0] = 1; }
	for (int i = 1; i <= 70; i++){
		for (int j = 1; j < i; j++){
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
	int x, y;
	cin >> x >> y;
	cout << arr[x][y];
}
