#include <stdio.h>
#include <ctime>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
	srand(time(0));
	float arr[100];
	vector<float> temp;
	vector<float> temp2;

	printf("Original Array: \n");
	for(int i = 0; i < 100; i++){
		arr[i] =(float)(rand() % 30 / 10.0);
		printf("%6.1f;", arr[i]);
		if(i%10==9)printf("\n");

		if(abs(arr[i])<=1) temp.push_back(arr[i]);
		else temp2.push_back(arr[i]);
	}
//	sort(temp.begin(), temp.end());
//	sort(temp2.begin(), temp2.end());

	printf("Modded Array: \n");
	for(int i = 0; i < 100; i++ ){
		arr[i] = i < temp.size() ? temp[i] : temp2[i - temp.size() + 1];
		printf("%6.1f;", arr[i]);
		if(i%10==9)printf("\n");
	}

	return 0;
}
