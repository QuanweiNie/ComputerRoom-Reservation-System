#include "teacher.h"

Teacher::Teacher(){}

// �вι���
Teacher::Teacher(int id, string name, string password)
{
	// ��ʼ������
	this->_id = id;
	this->_name = name;
	this->_password = password;
}

// �򿪲˵�
void Teacher::openMeau()
{
	cout << "��ӭ��ʦ:" << this->_name << "��½��" << endl;
	cout << "\t\t-----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.���ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����½              |\n";
	cout << "\t\t-----------------------------------\n";
	cout << "��ѡ�����Ĳ���:" << endl;
}

// ��ʾԤԼ
void Teacher::showOrder(){
	Student s;
	s.showAllOrder();
}


// ���ԤԼ
void Teacher::validOrder(){
	OrderFile of;
	if (of.isEmpty()) return;

	cout << "����˵�ԤԼ��¼����:" << endl;
	map<int, int>  m;  // ������ʾ��¼���ļ��еļ�¼�±�

	int index = 1;
	for (int i = 0; i < of._size; i++)
	{
		// �����
		if ( of._orderData[i]["status"] == "1")   // "1" ��ʾ�����
		{
			m.insert(make_pair(index, i));
			cout << index++ << " ";

			cout << "ԤԼ����: ��" << of._orderData[i]["date"] << " ";
			cout << "ʱ���:" << (of._orderData[i]["interval"] == "1" ? "����" : "����") << " ";
			cout << "����:" << of._orderData[i]["roomId"] << " ";

			string status = "״̬:";
			if (of._orderData[i]["status"] == "1") status += " �����";
			cout << status << endl;
		}
	}
	cout << "������Ҫ��˵�ԤԼ��¼��ţ�0 to quit��:";
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= m.size())
		{
			if (select == 0) break;
			else {
				// ��˼�¼
				cout << "��������˽��" << endl;
				cout << "1.ͨ��" << endl;
				cout << "2.��ͨ��" << endl;

				int valid = 0;
				cin >> valid;
				if (valid == 1)
				{
					of._orderData[m[select]]["status"] = "2";
				}
				else if (valid == 2)
				{
					of._orderData[m[select]]["status"] = "-1";
				}
				of.updateOrderToFile();
				cout << "��˳ɹ���" << endl;
				break;
			}
		}
		cout << "�����������������룡" << endl;
	}
	system("pause");
	system("cls");
}