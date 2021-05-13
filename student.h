#pragma once
#include "identity.h"
#include <vector>
#include "computerRoom.h"
#include <fstream>
#include "globalFile.h"
#include "orderFile.h"
#include <map>

using namespace std;

// ѧ����
class Student :public Identity {
public:
	Student();
	Student(int id,string name, string password);   // �вι��죺 ѧ�ţ�����������

	virtual void openMeau();   // �򿪲˵�    
	void applyOrder();  	   // ����ԤԼ
	void showMyOrder();        // �鿴�Լ���ԤԼ
	void showAllOrder();       // �鿴����ԤԼ
	void cancelOrder();        // ȡ��ԤԼ

	// ѧ��ѧ��
	int _id;
	vector<ComputerRoom> _vcpr;   // ��������
};