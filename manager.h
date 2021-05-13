#pragma once
#include <fstream>
#include "globalFile.h"
#include "identity.h"
#include <vector>
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"

using namespace std;

// ����Ա�����
class Manager : public Identity{
public:
	// ���캯��
	Manager();
	Manager(string name, string password);

	virtual void openMeau();       // �򿪲˵�
	void addPerson();              // ����˺�
	void showPerson();             // �鿴�˺�
	void showComputerRoom();       // �鿴������Ϣ
	void clearOrderRecord();       // ���ԤԼ��¼

	void initVector();             // ��ʼ������
	bool checkRepeat(int id, int type_id);    // ����

	
	vector<Student> _vstu;             // ѧ������
	vector<Teacher> _vtec;             // ��ʦ����
	vector<ComputerRoom>  _vcompRoom;  // ��������
};
