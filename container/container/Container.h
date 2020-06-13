#ifndef _CONTAINER_
#define _CONTAINER_

#include <iostream>
#include <set>

using namespace std;

template <typename _Ty,
	typename _Container = set<_Ty> >
class Container{
	typedef Container<_Ty, _Container> _Mrt;
	typedef typename _Container::size_type size_type;
	typedef typename _Container::value_type value_type;
	//typedef typename _Container::iterator 
public:
	Container():c(){
	}

	Container(const _Mrt& _right):c(_right.c){
	}

	Container(const _Container& _right):c(_right){
	}

	_Mrt& operator=(const _Mrt& _right){
		c=_right.c;
		return *this;
	}

	bool empty()const{
		return c.empty();
	}

	size_type size()const{
		return c.size();
	}

	bool insert(const value_type& _value){
		pair<typename _Container::iterator,bool> ret = c.insert(_value);
		if(ret.second==true){
			cout<<"插入"<<_value<<"成功"<<endl;
		}
		else{
			cout<<"插入"<<_value<<"失败"<<endl;
		}
		return ret.second;
	}

	bool erase(const value_type& _value){
		if(c.erase(_value)>0){
			cout<<"删除"<<_value<<"成功"<<endl;
			return true;
		}
		else{
			cout<<"没有"<<_value<<"删除失败"<<endl;
			return false;
		}
	}

	pair<value_type,bool> getMin(){
		pair<value_type,bool> ret;
		if(empty()){
			ret.second = false; 
		}
		else{
			typename _Container::iterator it = c.begin();
			ret.first = *it;
			ret.second = true;
		}
		return ret;
	}

	pair<value_type,bool> getMax(){
		pair<value_type,bool> ret;
		if(empty()){
			ret.second = false; 
		}
		else{
			typename _Container::iterator it = c.end();
			ret.first = *(--it);
			ret.second = true;
		}
		return ret;
	}

protected:
	_Container c;
};

#endif