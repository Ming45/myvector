#pragma once
#include<iostream>
//#include<vector>
#include<string>
#include<complex>
using namespace std;

template<typename T,int N>

class myvector {
	int m_n ;//��������Ԫ�ظ���
	int m_mm=0;//��ʵ���ڴ�
	T* m_arr;//ָ��̬����
public:

	myvector() = default;//Ĭ�Ϲ��캯��
	myvector(const T * s);//��ֵ
	myvector(const myvector & a);//���ƹ��캯��
	myvector(myvector&& rhs); //�ƶ����캯��
	~myvector(); //��������
	myvector& operator=(const myvector & a);//��ֵ�����
	myvector& operator=(myvector&& rhs); //�ƶ���ֵ�����

	int size();//��ȡԪ�ظ�������
	T& operator [](size_t a);//���������
	int at(T a);//Ԫ�ط��ʺ���
	T front();//��ȡ��Ԫ�غ���
	T back();//��ȡβԪ�غ���
	void push_back(T s); //β�庯��
	void pop_back();//β��ɾ������
	void insert(T a, int b);//ָ��λ�ò��뺯��
	void erase(int a); //ɾ��ָ��λ��Ԫ�غ���
	void clear();//�������Ԫ�غ��� 
	void open();//����ʾ����Ԫ��
	//void sort();//��ð�����򷨶Լ���Ԫ�ؽ��д�С�������� 
	//bool binary_search(const T& a);//���ֲ���
};

template<typename T, int N>
myvector<T, N>::myvector(const T* s) :m_n(N),m_mm(2*m_n),m_arr(m_n>0?new T[m_mm]:nullptr){//��ֵ���캯���ȶԸ�����ʼ����ֵ����������Ŀ��������ж��Ƿ�ǿ����飬���ǿգ�����new������Ӧ��С���ڴ棬���򲻷���
	for (int i = 0; i < m_n; i++) {
		m_arr[i] = s[i];
	}
}

template<typename T, int N>
myvector<T, N>::myvector(const myvector<T, N>& a):m_n(a.m_n), m_mm(2 * m_n), m_arr( nullptr) {//���ƹ��캯����ͬ���ʼ�����������������õ���a��m_n
	m_arr = a.m_arr;
}

template<typename T, int N>
myvector<T, N>::~myvector() {//��������
	delete[]m_arr;
}

template<typename T, int N>
 myvector<T, N>& myvector<T, N>::operator=(const myvector<T, N>& a) {//���������
	if (this != &a) {//����������
		delete[]m_arr;//�ͷ�ԭ�����ڴ�
		m_n = a.m_n;
		m_mm = a.m_mm;
		m_arr = new T[m_mm];//���·����ڴ�

	}
	for (int i = 0; i < m_n; i++) {//��������
		m_arr[i] = a[i];
	}
	return *this;//��this ��Ա���޸�
}

template<typename T, int N>
myvector<T, N>::myvector(myvector&& rhs) :m_n(rhs.m_n), m_mm(rhs.m_mm), m_arr(rhs.m_arr) {//�ƶ����캯��
	rhs.m_arr = nullptr;//��������Ӷ���ᵼ�����·����ڴ棬���ƶ����캯���ƶ���ԭ��ʱ������ڴ��У��Ӷ������ٷ����ڴ�
	rhs.m_n = 0;
	rhs.m_mm = 0;
}

template<typename T, int N>
myvector<T, N>& myvector<T, N>::operator=(myvector&& rhs) {//�ƶ���ֵ�����
	if (this != &rhs) {//��������ֵ
		delete[]m_arr;
		m_n = rhs.m_n;
		m_mm = rhs.m_mm;
		m_arr = rhs.m_arr;
		rhs.m_arr = nullptr;//����ʱ����ָ���Ա��Ϊ��ָ��
		rhs.m_n = 0;
		rhs.m_mm = 0;
	}
	return *this;
}

template<typename T, int N>
int myvector<T, N>::size() {//��ȡԪ�ظ�������
	return m_n;
}

template<typename T, int N>
T& myvector<T, N>::operator [](size_t a) {//���������
	if (a >= m_n) {
		cout << "������Χ,����ֻ��" << m_n << endl;
	}
	else {
		cout << "��Ԫ��Ϊ��";
		return  m_arr[a];
	}
}

template<typename T,int N>
int myvector<T,N>::at(T a) {//Ԫ�ط��ʺ������Ƿ���Ԫ��a������±�
	int i = 0;
	for (; i < m_n; i++) {
		if (m_arr[i] == a) {
			cout << "���ڸ�Ԫ��,���±�Ϊ:" << i << endl;
			return i;
			break;
		}
	}
	if ((i == m_n) && (m_arr[m_n - 1] != a)) {
		cout << "�����ڸ�Ԫ��" << endl;
		return -1;
	}
}

template<typename T,int N>
T myvector<T, N>::front() {//��ȡ��Ԫ�غ������жϷǿգ�
	return m_arr[0];
}

template<typename T,int N>
T myvector<T, N>::back() {//��ȡβԪ�غ���
	return m_arr[m_n - 1];
}

template<typename T, int N>
void myvector<T, N>::push_back(T s) { //β�庯����������Щ�ڴ�仯�˵ģ����ڲ��ϵ�new�������Ƭ��������á�����취�ǣ�������ʱ�����ڴ���չΪ�����ڴ��һ������������ʱ����չ��������Ҫ��new������������Ƭ������
	if ((m_n + 1) >= m_mm) {//��Ԫ�ظ�����һҪ�������ڴ��Сʱ����Ҫ��new�����ڴ棬����ֱ�Ӳ���
		T* array = new T[m_n];
		for (int i = 0; i < m_n; i++) {//�½�һ����̬�ڴ��������ԭ����
			array[i] = m_arr[i];
		}
		delete[]m_arr;//�ͷ�ԭ�����ڴ�
		m_n++;
		m_mm = 2 * m_n;
		m_arr = new T[m_mm];// �½�һ��
		for (int i = 0; i < m_n - 1; i++) {//�Ż�ԭ����
			m_arr[i] = array[i];
		}
		m_arr[m_n - 1] = s;//������Ҫ�������
		delete[]array;//�ͷŹ�������
	}
	else {
		m_n++;//������һ
		m_arr[m_n - 1] = s;//������Ҫ�������	
	}
}

template<typename T, int N>
void myvector<T, N>::pop_back() { //β��ɾ������ 
	m_n--;//��ȥһ����
}

template<typename T, int N>
void myvector<T, N>::insert(T a, int b) {//ָ��λ�ò��뺯��,�ڵ�b��λ�ò���a 
	if (b > m_n + 1) {
		cout << "�����ɲ��뷶Χ�����ɲ���λ��Ϊĩβ��" << m_n + 1 << endl;
	}
	else {
		if ((m_n + 1) >= m_mm) {
			T* array = new T[m_n];
			for (int i = 0; i < m_n; i++) {//�½�һ����̬�ڴ��������ԭ����
				array[i] = m_arr[i];
			}
			delete[]m_arr;//�ͷ�ԭ�����ڴ�
			m_mm = 2 * m_n;
			m_arr = new T[m_mm];// �½�һ��
			m_mm = 2 * m_n;
			for (int i = 0; i < m_n - 1; i++) {//�Ż�ԭ����
				m_arr[i] = array[i];
			}
			for (int i = m_n - 1; i > b - 1; i--) {//��Ŀ��λ��֮��������һλ
				m_arr[i] = m_arr[i - 1];
			}
			m_arr[b - 1] = a;
			delete[]array;//�ͷŹ�������
		}
		else {
			m_n++;//������һ
			for (int i = m_n - 1; i > b - 1; i--) {//��Ŀ��λ��֮��������һλ
				m_arr[i] = m_arr[i - 1];
			}
			m_arr[b - 1] = a;
		}
	}
}

template<typename T, int N>
void myvector<T, N>::erase(int a) { //ɾ��ָ��λ��Ԫ�غ��� 
	if (a <= m_n) {		
        for (int i = a - 1; i < m_n - 1; i++) {//ֱ���ڹ��������н�Ŀ��Ԫ�ظ���
			m_arr[i] = m_arr[i + 1];
		}
		m_n--;//��ȥһ����
	}
	else {
		cout << "������Χ,ֻ��" << m_n << "����" << endl;
	}
}

template<typename T, int N>
void myvector<T, N>::clear() {//�������Ԫ�غ��� 
	m_n = 0;
}

template<typename T, int N>
void myvector<T, N>::open() {//����ʾ����Ԫ��
	for (int i = 0; i < m_n; i++) {
		cout << " " << m_arr[i] << " ";
	}
	cout << '\n';
}
/*
template<typename T, int N>
void myvector<T, N>::sort() { //��ð�����򷨶Լ���Ԫ�ؽ��д�С�������� 
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
bool myvector<T, N>::binary_search(const T& a) {//���ֲ���
	if (imag(a)) {
		return 0;
	}
	int le = 0;
	int ri = m_n;
	while (le <= ri) {
		int m = (le + ri) / 2;//�����е�λ��
		if (m_arr[m] == a) {
			cout << "�ҵ���Ԫ�أ����±�Ϊ" << m << endl;
			return 1;
		}
		else if (m_arr[m] > a)
			ri = m - 1;//�޸���ָ��
		else
			le = m + 1;//�޸���ָ��
	}
	cout << "δ�ҵ���Ԫ��" << endl;
	return 0;
	
}*/