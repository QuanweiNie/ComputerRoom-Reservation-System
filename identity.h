#pragma once
#include <iostream>
#include <string>

using std::string;

// ��ݳ������
class Identity {
public:
	// �����˵�
	virtual void openMeau() = 0;

	string _name;       // �û���
	string _password;   // ����
};