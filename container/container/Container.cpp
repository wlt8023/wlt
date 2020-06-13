#include <iostream>
#include <Windows.h>
#include "Container.h"
//#include <set>

int main(void){
	/*set<int> setInt;
	setInt.insert(1);*/

	Container<int> _cInt;
	
	for(int i=0;i<10;i++){
		_cInt.insert(i*5);
	}
	
	bool _cBool = _cInt.empty();
	cout<<_cBool<<endl;

	int _cSize = _cInt.size();
	cout<<_cSize<<endl;

	_cInt.erase(25);
	_cInt.erase(0);
	_cInt.erase(45);
	_cInt.erase(0);

	pair<int,bool> min = _cInt.getMin();
	cout<<"min:"<<min.first<<endl;

	pair<int,bool> max = _cInt.getMax();
	cout<<"max:"<<max.first<<endl;

	system("pause");
	return 0;
}