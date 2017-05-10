#include<iostream>
#include<string>
using namespace std;
string add(string str1, string str2)
{
	int i, j;
	if (str1.size() >= str2.size()){
		for(i = str1.size() - 1, j = str2.size() - 1 ; i >= 0 && j >= 0 ; i--, j--){
			str1[i] += str2[j] - '0';
			if(str1[i] > '9'){
				str1[i] -= 10;
				if(i == 0){
					str1 = "1" + str1;
				}else{
					str1[i - 1] += 1;
				}
			}
		}
		return str1;
	}else if (str1.size() < str2.size()){
		for(i = str1.size() - 1, j = str2.size() - 1 ; i >= 0 && j >= 0 ; i--, j--){
			str2[j] += str1[i] - '0';
			if(str2[j] > '9'){
				str2[j] -= 10;
				if(j == 0){
					str2 = "1" + str2;
				}else{
					str2[j - 1] += 1;
				}
			}
		}
		return str2;
	}
}
int main(void)
{
	int num;
	string f[5000];
	for(int i = 0 ; i < 5000 ; i++){
		if(i == 0){
			f[i] = "0";
		}else if(i == 1){
			f[i] = "1";
		}else{
			f[i] = add(f[i - 1], f[i - 2]);
		}
	}
	while(1)
	{
		cout << "num < 5000:";
		cin >> num;
		cout << "Fibonacci[" << num << "]:" << f[num] << endl;
	}
	return 0;
}
