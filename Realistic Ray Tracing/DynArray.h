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

//Ĭ�Ϲ��캯��
template<class _Tp>
DynArray<_Tp>::DynArray(){
	nData = 0;
	arraySize = 4;
	data = new int[arraySize];
}

//����һ����n���洢��Ա������
template<class _Tp>
DynArray<_Tp>::DynArray(int n){
	nData = 0;
	arraySize = n;
	data = new int[arraySize];
}

//��������
template<class _Tp>
DynArray<_Tp>::~DynArray(){
	nData = 0;
	delete[] data;
}

//������Ŀռ����Ϊʵ�ʵĿռ��С
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

//�������β�����һ��Ԫ�أ�����ڴ治��������һ���������ڴ沢��ԭ����Ԫ���Ƶ��µĿռ�
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