#include<iostream>
#include<vector>

using namespace std;

int main(void){
	vector <int> v;
	v.reserve(8);//���� ������ Ȯ�� 
	
	vector<int>::iterator iter = v.begin();
	
	v.push_back(2);
	v.push_back(4);
	v.push_back(8);
	v.push_back(16);
	
	for(iter = v.begin();iter!=v.end();iter++){
		cout<<*iter<<endl;
		cout<<iter[0]<<endl; //iter+0��° ��ü�� ��ȯ 

	}	
} 
