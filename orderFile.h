#pragma once
#include <iostream>
#include "globalFile.h"
#include <fstream>
#include <map>
#include <string>

using namespace std;

// ��¼�ļ�
class OrderFile{
public:
	// ���캯��
	OrderFile();

	// ��������
	void initData(const string str,map<string,string> &m);

	// ����ԤԼ��¼
	void updateOrderToFile();

	// ����¼�Ƿ�Ϊ��
	bool isEmpty();

	// ��¼ԤԼ����
	int _size;

	// ��¼����
	map<int, map<string, string>>  _orderData;
};