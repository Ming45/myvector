#pragma once
#include<iostream>
#include<vector>
using namespace std;

template<typename T, int N>

class myvector {
	T m_array[1000];//定义1000长度的T类型数组
	int m_n = N;//用于容器元素个数
public:
	myvector() = default;//默认构造函数
	myvector(const T* s);
	myvector(const myvector& a);//复制构造函数
	~myvector() = default;//默认析构函数
	myvector& operator=(const myvector& a);//赋值运算符
	int size();//获取元素个数函数
	T& operator [](size_t a);//访问运算符
	int at(T a);//元素访问函数
	T front();//获取首元素函数
	T back();//获取尾元素函数
	void push_back(T s); //尾插函数
	void pop_back();//尾部删除函数
	void insert(T a, int b);//指定位置插入函数
	void erase(int a); //删除指定位置元素函数
	void clear();//清空所有元素函数 
	void open();//打开显示所有元素
	void sort();//用冒泡排序法对集合元素进行从小到大排序 
	bool binary_search(const T& a);//二分查找


};
template<typename T, int N>
myvector<T, N>::myvector(const T* s) {//
	for (int i = 0; i < N; i++) {
		m_array[i] = s[i];
	}
}

template<typename T, int N>
myvector<T, N>::myvector(const myvector<T, N>& a) {//复制构造函数，必须是引用类型，若不是非引用，形参需要通过复制实参的方式构造，又要调用复制构造函数，形成无穷递归
	//for (int i = 0; i < a.m_n; i++)
	//{
	//	m_array[i] = a.m_array[i];
	//}
	//m_n = a.m_n;
	m_array = a.m_array;
}

template<typename T, int N>
myvector<T, N>& myvector<T, N>::operator=(const myvector<T, N>& a) {//赋值运算符
	for (int i = 0; i < a.m_n; i++)
	{
		m_array[i] = a.m_array[i];
	}
	m_n = a.m_n;
	return *this;//对this 成员的修改
}

template<typename T, int N>
int myvector<T, N>::size() {//获取元素个数函数
	return m_n;
}

template<typename T, int N>
T& myvector<T, N>::operator [](size_t a) {//访问运算符
	if (a >= m_n) {
		cout << "超出范围,数组只有" << m_n << "个数,该位置为随机数" << endl;
	}
	else {
		cout << "该元素为：";
		return  m_array[a];
	}
}

template<typename T, int N>
int myvector<T, N>::at(T a) {//元素访问函数，是否有元素a并输出下标
	int i = 0;
	for (; i < m_n; i++) {
		if (m_array[i] == a) {
			cout << "存在该元素,其下标为:" << i << endl;
			return i;
			break;
		}
	}
	if ((i == m_n) && (m_array[m_n - 1] != a)) {
		cout << "不存在该元素" << endl;
		return -1;
	}
}

template<typename T, int N>
T myvector<T, N>::front() {//获取首元素函数
	return m_array[0];
}

template<typename T, int N>
T myvector<T, N>::back() {//获取尾元素函数
	return m_array[m_n - 1];
}

template<typename T, int N>
void myvector<T, N>::push_back(T s) { //尾插函数 
	m_array[m_n] = s;
	m_n++;
}

template<typename T, int N>
void myvector<T, N>::pop_back() { //尾部删除函数 
	m_n--;
}

template<typename T, int N>
void myvector<T, N>::insert(T a, int b) {//指定位置插入函数,在第b个位置插入a 
	if (b > m_n + 1) {
		cout << "超出可插入范围，最大可插入位置为末尾：" << m_n + 1 << endl;
	}
	else {
		m_n++;
		for (int i = m_n - 1; i > b - 1; i--) {
			m_array[i] = m_array[i - 1];
		}
		m_array[b - 1] = a;
	}
}

template<typename T, int N>
void myvector<T, N>::erase(int a) { //删除指定位置元素函数 
	if (a < m_n) {
		for (int i = a - 1; i < m_n - 1; i++) {
			m_array[i] = m_array[i + 1];
		}
		m_n--;
	}
	else {
		cout << "超出范围,只有" << m_n << "个数" << endl;
	}
}

template<typename T, int N>
void myvector<T, N>::clear() {//清空所有元素函数 
	m_n = 0;
}

template<typename T, int N>
void myvector<T, N>::open() {//打开显示所有元素
	for (int i = 0; i < m_n; i++) {
		cout << " " << m_array[i] << " ";
	}
	cout << '\n';
}

template<typename T, int N>
void myvector<T, N>::sort() { //用冒泡排序法对集合元素进行从小到大排序 
	for (int i = m_n - 1; i >= 0; --i)
	{
		for (int j = 0; j <= i - 1; ++j)
		{
			if (m_array[j] > m_array[j + 1])
			{
				T s = m_array[j];
				m_array[j] = m_array[j + 1];
				m_array[j + 1] = s;
			}
		}
	}
}

template<typename T, int N>
bool myvector<T, N>::binary_search(const T& a) {//二分查找
	int le = 0;
	int ri = m_n;
	while (le <= ri) {
		int m = (le + ri) / 2;//计算中点位置
		if (m_array[m] == a) {
			cout << "找到该元素，其下标为" << m << endl;
			return 1;
		}
		else if (m_array[m] > a)
			ri = m - 1;//修改右指针
		else
			le = m + 1;//修改左指针
	}
	cout << "未找到该元素" << endl;
	return 0;
}