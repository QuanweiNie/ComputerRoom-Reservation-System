#pragma once
#include "identity.h"
#include "orderFile.h"
#include "student.h"

using namespace std;

// ��ʦ��
class Teacher : public Identity{
public:
	// ���캯��
	Teacher();
	Teacher(int id, string name, string password);

	virtual void openMeau();   // �򿪲˵�
	void showOrder();          // ��ʾԤԼ
	void validOrder();         // ���ԤԼ

	// ��ְ�����
	int _id;
};