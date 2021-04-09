#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

vector<int> BubbleSort(vector<int> v);

const float pi = 3.1415;

int main(){

	vector<int> A;
	vector<int> B;
	int max = 0;

	int it = 0;

	cout << "A:" << endl;
	for(float i = -pi; i < pi; i+=pi/10){
		int y = (int)(3 * cos(5 * i) + 2 * sin(i));
		max = max > y ? max : y;
		if(it % 10 == 9) printf("%3i\n", y);
		else printf("%3i", y);
		A.push_back(it % 2 == 1 ? y * y : y);
		it++;
	}
	max /= 2;

	it = 0;

	cout << endl << endl << "B:" << endl;
	for(auto i : A){
		if(i < max) B.push_back(i);
		if(it % 10 == 9) printf("%3i\n", i);
		else printf("%3i", i);
		it++;
	}

	cout << endl << endl << "Edited A:" << endl;
	for(int i = 0; i < A.size(); i++){
		if(i % 10 == 9) printf("%3i\n", A[i]);
		else printf("%3i", A[i]);
	}

	B = BubbleSort(B);
	cout << endl << endl << "Sorted B:" << endl;
	for(int i = 0; i < B.size(); i++){
		if(i % 10 == 9) printf("%3i\n", B[i]);
		else printf("%3i", B[i]);
	}

	cout << endl << endl << "E:" << endl;
	size_t size = A.size() > B.size() ? B.size() : A.size();
	int mm = 0;
	int mmi = -1;
	int E[size][size];
	for(int i = 0; i < size; i++){
		int mmm = 0;
		for(int j = 0; j < size; j++){
			E[i][j] = A[i] - B[j];
			printf("%3i", E[i][j]);
			mmm += E[i][j] < 0 ? 1 : 0;
		}
		if(mmm > mm){
			mm = mmm;
			mmi = i;
		}
		cout << endl;
	}

	cout << endl << "First line with min items above 0: " << mmi << endl << endl;

	cout << " X      Y" << endl;
	for(float i = -pi; i < pi; i+=pi/10)
		printf("%6.2f %6.2f\n", i ,(3 * cos(5 * i) + 2 * sin(i)));

	cout << endl;
	return 0;

}

vector<int> BubbleSort(vector<int> v){
	for(int i = v.size(); i > 1; i--)
		for(int j = 1; j < v.size(); j++)
			if(v[j-1] < v[j]) swap(v[j-1], v[j]);
	return v;
}
