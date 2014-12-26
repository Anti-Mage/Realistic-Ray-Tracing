#ifndef __DYNARRAY_H__
#define __DYNARRAY_H__

template<class _Tp>
class DynArray{
public:
	DynArray();
	DynArray(int n);
	~DynArray();

	bool append(const _Tp& item);
	bool truncate();
	void clear(){ nData = 0; }
	int length() const { return nData; }
	bool empty() const { return nData == 0; }
	const _Tp& operator[](int i) const { return data[i]; }
	_Tp& operator[](int i){ return data[i]; }

private:
	_Tp* data;
	int nData;
	int arraySize;

};

//默认构造函数
template<class _Tp>
DynArray<_Tp>::DynArray(){
	nData = 0;
	arraySize = 4;
	data = new int[arraySize];
}

//创建一个有n个存储党员的数组
template<class _Tp>
DynArray<_Tp>::DynArray(int n){
	nData = 0;
	arraySize = n;
	data = new int[arraySize];
}

//析构函数
template<class _Tp>
DynArray<_Tp>::~DynArray(){
	nData = 0;
	delete[] data;
}

//将申请的空间调整为实际的空间大小
template<class _Tp>
bool DynArray<_Tp>::truncate(){
	if (nData != arraySize){
		_Tp* tmp = data;
		arraySize = nData;
		if (!(data = new _Tp[arraySize]))
			return false;
		for (int i = 0; i < nData; ++i)
			data[i] = tmp[i];
		delete[] tmp;
	}
	return true;
}

//在数组的尾部添加一个元素，如果内存不够则申请一个两倍的内存并将原来的元素移到新的空间
template<class _Tp>
bool DynArray<_Tp>::append(const _Tp& item){
	if (nData == arraySize){
		arraySize *= 2;
		_Tp* tmp = data;
		if (!(data = new _Tp[arraySize]))
			return false;
		for (int i = 0; i < nData; ++i){
			data[i] = tmp[i];
		}
		delete[] tmp;
	}
	data[nData++] = item;

	return true;
}

#endif