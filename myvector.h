#pragma once
#include<iostream>
#include<vector>
using namespace std;

template<typename T, int N>

class myvector {
	T m_array[1000];//����1000���ȵ�T��������
	int m_n = N;//��������Ԫ�ظ���
public:
	myvector() = default;//Ĭ�Ϲ��캯��
	myvector(const T* s);
	myvector(const myvector& a);//���ƹ��캯��
	~myvector() = default;//Ĭ����������
	myvector& operator=(const myvector& a);//��ֵ�����
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
	void sort();//��ð�����򷨶Լ���Ԫ�ؽ��д�С�������� 
	bool binary_search(const T& a);//���ֲ���


};
template<typename T, int N>
myvector<T, N>::myvector(const T* s) {//
	for (int i = 0; i < N; i++) {
		m_array[i] = s[i];
	}
}

template<typename T, int N>
myvector<T, N>::myvector(const myvector<T, N>& a) {//���ƹ��캯�����������������ͣ������Ƿ����ã��β���Ҫͨ������ʵ�εķ�ʽ���죬��Ҫ���ø��ƹ��캯�����γ�����ݹ�
	//for (int i = 0; i < a.m_n; i++)
	//{
	//	m_array[i] = a.m_array[i];
	//}
	//m_n = a.m_n;
	m_array = a.m_array;
}

template<typename T, int N>
myvector<T, N>& myvector<T, N>::operator=(const myvector<T, N>& a) {//��ֵ�����
	for (int i = 0; i < a.m_n; i++)
	{
		m_array[i] = a.m_array[i];
	}
	m_n = a.m_n;
	return *this;//��this ��Ա���޸�
}

template<typename T, int N>
int myvector<T, N>::size() {//��ȡԪ�ظ�������
	return m_n;
}

template<typename T, int N>
T& myvector<T, N>::operator [](size_t a) {//���������
	if (a >= m_n) {
		cout << "������Χ,����ֻ��" << m_n << "����,��λ��Ϊ�����" << endl;
	}
	else {
		cout << "��Ԫ��Ϊ��";
		return  m_array[a];
	}
}

template<typename T, int N>
int myvector<T, N>::at(T a) {//Ԫ�ط��ʺ������Ƿ���Ԫ��a������±�
	int i = 0;
	for (; i < m_n; i++) {
		if (m_array[i] == a) {
			cout << "���ڸ�Ԫ��,���±�Ϊ:" << i << endl;
			return i;
			break;
		}
	}
	if ((i == m_n) && (m_array[m_n - 1] != a)) {
		cout << "�����ڸ�Ԫ��" << endl;
		return -1;
	}
}

template<typename T, int N>
T myvector<T, N>::front() {//��ȡ��Ԫ�غ���
	return m_array[0];
}

template<typename T, int N>
T myvector<T, N>::back() {//��ȡβԪ�غ���
	return m_array[m_n - 1];
}

template<typename T, int N>
void myvector<T, N>::push_back(T s) { //β�庯�� 
	m_array[m_n] = s;
	m_n++;
}

template<typename T, int N>
void myvector<T, N>::pop_back() { //β��ɾ������ 
	m_n--;
}

template<typename T, int N>
void myvector<T, N>::insert(T a, int b) {//ָ��λ�ò��뺯��,�ڵ�b��λ�ò���a 
	if (b > m_n + 1) {
		cout << "�����ɲ��뷶Χ�����ɲ���λ��Ϊĩβ��" << m_n + 1 << endl;
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
void myvector<T, N>::erase(int a) { //ɾ��ָ��λ��Ԫ�غ��� 
	if (a < m_n) {
		for (int i = a - 1; i < m_n - 1; i++) {
			m_array[i] = m_array[i + 1];
		}
		m_n--;
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
		cout << " " << m_array[i] << " ";
	}
	cout << '\n';
}

template<typename T, int N>
void myvector<T, N>::sort() { //��ð�����򷨶Լ���Ԫ�ؽ��д�С�������� 
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
bool myvector<T, N>::binary_search(const T& a) {//���ֲ���
	int le = 0;
	int ri = m_n;
	while (le <= ri) {
		int m = (le + ri) / 2;//�����е�λ��
		if (m_array[m] == a) {
			cout << "�ҵ���Ԫ�أ����±�Ϊ" << m << endl;
			return 1;
		}
		else if (m_array[m] > a)
			ri = m - 1;//�޸���ָ��
		else
			le = m + 1;//�޸���ָ��
	}
	cout << "δ�ҵ���Ԫ��" << endl;
	return 0;
}