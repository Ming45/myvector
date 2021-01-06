#pragma once
#include<iostream>
//#include<vector>
#include<string>
#include<complex>
using namespace std;

template<typename T,int N>

class myvector {
	int m_n ;//用于容器元素个数
	int m_mm=0;//现实际内存
	T* m_arr;//指向动态数组
public:

	myvector() = default;//默认构造函数
	myvector(const T * s);//赋值
	myvector(const myvector & a);//复制构造函数
	myvector(myvector&& rhs); //移动构造函数
	~myvector(); //析构函数
	myvector& operator=(const myvector & a);//赋值运算符
	myvector& operator=(myvector&& rhs); //移动赋值运算符

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
	//void sort();//用冒泡排序法对集合元素进行从小到大排序 
	//bool binary_search(const T& a);//二分查找
};

template<typename T, int N>
myvector<T, N>::myvector(const T* s) :m_n(N),m_mm(2*m_n),m_arr(m_n>0?new T[m_mm]:nullptr){//赋值构造函数先对个数初始化赋值，再利用三目运算符，判断是否非空数组，若非空，则用new分配相应大小的内存，否则不分配
	for (int i = 0; i < m_n; i++) {
		m_arr[i] = s[i];
	}
}

template<typename T, int N>
myvector<T, N>::myvector(const myvector<T, N>& a):m_n(a.m_n), m_mm(2 * m_n), m_arr( nullptr) {//复制构造函数，同理初始化，区别在于这里用的是a的m_n
	m_arr = a.m_arr;
}

template<typename T, int N>
myvector<T, N>::~myvector() {//析构函数
	delete[]m_arr;
}

template<typename T, int N>
 myvector<T, N>& myvector<T, N>::operator=(const myvector<T, N>& a) {//复制运算符
	if (this != &a) {//避免自身复制
		delete[]m_arr;//释放原来的内存
		m_n = a.m_n;
		m_mm = a.m_mm;
		m_arr = new T[m_mm];//重新分配内存

	}
	for (int i = 0; i < m_n; i++) {//复制数据
		m_arr[i] = a[i];
	}
	return *this;//对this 成员的修改
}

template<typename T, int N>
myvector<T, N>::myvector(myvector&& rhs) :m_n(rhs.m_n), m_mm(rhs.m_mm), m_arr(rhs.m_arr) {//移动构造函数
	rhs.m_arr = nullptr;//若再向添加对象会导致重新分配内存，用移动构造函数移动到原临时对象的内存中，从而避免再分配内存
	rhs.m_n = 0;
	rhs.m_mm = 0;
}

template<typename T, int N>
myvector<T, N>& myvector<T, N>::operator=(myvector&& rhs) {//移动赋值运算符
	if (this != &rhs) {//避免自身赋值
		delete[]m_arr;
		m_n = rhs.m_n;
		m_mm = rhs.m_mm;
		m_arr = rhs.m_arr;
		rhs.m_arr = nullptr;//将临时对象指针成员置为空指针
		rhs.m_n = 0;
		rhs.m_mm = 0;
	}
	return *this;
}

template<typename T, int N>
int myvector<T, N>::size() {//获取元素个数函数
	return m_n;
}

template<typename T, int N>
T& myvector<T, N>::operator [](size_t a) {//访问运算符
	if (a >= m_n) {
		cout << "超出范围,数组只有" << m_n << endl;
	}
	else {
		cout << "该元素为：";
		return  m_arr[a];
	}
}

template<typename T,int N>
int myvector<T,N>::at(T a) {//元素访问函数，是否有元素a并输出下标
	int i = 0;
	for (; i < m_n; i++) {
		if (m_arr[i] == a) {
			cout << "存在该元素,其下标为:" << i << endl;
			return i;
			break;
		}
	}
	if ((i == m_n) && (m_arr[m_n - 1] != a)) {
		cout << "不存在该元素" << endl;
		return -1;
	}
}

template<typename T,int N>
T myvector<T, N>::front() {//获取首元素函数（判断非空）
	return m_arr[0];
}

template<typename T,int N>
T myvector<T, N>::back() {//获取尾元素函数
	return m_arr[m_n - 1];
}

template<typename T, int N>
void myvector<T, N>::push_back(T s) { //尾插函数（对于这些内存变化了的，由于不断的new会产生碎片，最好少用。解决办法是：当不够时，将内存扩展为现有内存的一倍，当不够用时再拓展，否则不需要用new操作，减少碎片产生）
	if ((m_n + 1) >= m_mm) {//当元素个数加一要大于现内存大小时，需要用new两倍内存，否则直接操作
		T* array = new T[m_n];
		for (int i = 0; i < m_n; i++) {//新建一个动态内存的数组存放原数据
			array[i] = m_arr[i];
		}
		delete[]m_arr;//释放原来的内存
		m_n++;
		m_mm = 2 * m_n;
		m_arr = new T[m_mm];// 新建一个
		for (int i = 0; i < m_n - 1; i++) {//放回原数据
			m_arr[i] = array[i];
		}
		m_arr[m_n - 1] = s;//并插入要插入的数
		delete[]array;//释放工具数组
	}
	else {
		m_n++;//个数加一
		m_arr[m_n - 1] = s;//并插入要插入的数	
	}
}

template<typename T, int N>
void myvector<T, N>::pop_back() { //尾部删除函数 
	m_n--;//减去一个数
}

template<typename T, int N>
void myvector<T, N>::insert(T a, int b) {//指定位置插入函数,在第b个位置插入a 
	if (b > m_n + 1) {
		cout << "超出可插入范围，最大可插入位置为末尾：" << m_n + 1 << endl;
	}
	else {
		if ((m_n + 1) >= m_mm) {
			T* array = new T[m_n];
			for (int i = 0; i < m_n; i++) {//新建一个动态内存的数组存放原数据
				array[i] = m_arr[i];
			}
			delete[]m_arr;//释放原来的内存
			m_mm = 2 * m_n;
			m_arr = new T[m_mm];// 新建一个
			m_mm = 2 * m_n;
			for (int i = 0; i < m_n - 1; i++) {//放回原数据
				m_arr[i] = array[i];
			}
			for (int i = m_n - 1; i > b - 1; i--) {//将目标位置之后的向后退一位
				m_arr[i] = m_arr[i - 1];
			}
			m_arr[b - 1] = a;
			delete[]array;//释放工具数组
		}
		else {
			m_n++;//个数加一
			for (int i = m_n - 1; i > b - 1; i--) {//将目标位置之后的向后退一位
				m_arr[i] = m_arr[i - 1];
			}
			m_arr[b - 1] = a;
		}
	}
}

template<typename T, int N>
void myvector<T, N>::erase(int a) { //删除指定位置元素函数 
	if (a <= m_n) {		
        for (int i = a - 1; i < m_n - 1; i++) {//直接在工具数组中将目标元素覆盖
			m_arr[i] = m_arr[i + 1];
		}
		m_n--;//减去一个数
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
		cout << " " << m_arr[i] << " ";
	}
	cout << '\n';
}
/*
template<typename T, int N>
void myvector<T, N>::sort() { //用冒泡排序法对集合元素进行从小到大排序 
	for (int i = m_n - 1; i >= 0; --i)
	{
		for (int j = 0; j <= i - 1; ++j)
		{
			if (m_arr[j] > m_arr[j + 1])
			{
				T s = m_arr[j];
				m_arr[j] = m_arr[j + 1];
				m_arr[j + 1] = s;
			}
		}
	}
}

template<typename T, int N>
bool myvector<T, N>::binary_search(const T& a) {//二分查找
	if (imag(a)) {
		return 0;
	}
	int le = 0;
	int ri = m_n;
	while (le <= ri) {
		int m = (le + ri) / 2;//计算中点位置
		if (m_arr[m] == a) {
			cout << "找到该元素，其下标为" << m << endl;
			return 1;
		}
		else if (m_arr[m] > a)
			ri = m - 1;//修改右指针
		else
			le = m + 1;//修改左指针
	}
	cout << "未找到该元素" << endl;
	return 0;
	
}*/