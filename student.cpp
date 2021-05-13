#include "student.h"

// Ĭ�Ϲ���
Student::Student(){}

// �вι���
Student::Student(int id, string name, string password){
	// ��ʼ��
	this->_id = id;
	this->_name = name;
	this->_password = password;

	// ������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	
	ComputerRoom cpr;
	while (ifs >> cpr._id && ifs >> cpr._size)
		_vcpr.push_back(cpr);
	ifs.close();
}


// �򿪲˵�
void Student::openMeau(){
	cout << "��ӭѧ������" << this->_name << " ��½!" << endl;
	cout << "\t\t--------------------------------------\n";
	cout << "\t\t|                                     \n";
	cout << "\t\t|              1.����ԤԼ             \n";
	cout << "\t\t|                                     \n";
	cout << "\t\t|              2.�鿴�ҵ�ԤԼ         \n";
	cout << "\t\t|                                     \n";
	cout << "\t\t|              3.�鿴����ԤԼ         \n";
	cout << "\t\t|                                     \n";
	cout << "\t\t|              4.ȡ��ԤԼ             \n";
	cout << "\t\t|                                     \n";
	cout << "\t\t|              0.ע����½             \n";
	cout << "\t\t--------------------------------------\n";
	cout << "����������Ҫִ�еĲ�����" << endl;
 }   

// ����ԤԼ
void Student::applyOrder(){
	cout << "��������ʱ�䣺��һ������" << endl;
	cout << "������ԤԼ��ʱ�䣺" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;
	cout << endl;

	int date = 0;        // ����
	int interval = 0;    // ʱ���
	int room = 0;        // �������

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
			break;
		cout << "�����������������룡" << endl;
	}
	cout << "����������ԤԼ��ʱ��Σ�" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2) break;
		cout << "������������������" << endl;
	}
	cout << "��ѡ�������" << endl;
	cout << _vcpr[0]._id << "�Ż�������Ϊ��" << _vcpr[0]._size << endl;
	cout << _vcpr[1]._id << "�Ż�������Ϊ��" << _vcpr[1]._size << endl;
	cout << _vcpr[2]._id << "�Ż�������Ϊ��" << _vcpr[2]._size << endl;
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3) break;
		cout << "�����������������룡" << endl;
	}
	cout << "ԤԼ�ɹ�! �����" << endl;

	// д�ļ�
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->_id << " ";
	ofs << "stuName:" << this->_name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << "1" << endl;    // 1 ���������

	ofs.close();
	system("pause");
	system("cls");
}

// �鿴�Լ���ԤԼ
void Student::showMyOrder(){
	OrderFile of;
	of.isEmpty();

	for (int i = 0; i < of._size; i++)
	{
		if (this->_id == atoi(of._orderData[i]["stuId"].c_str()))  // c-style�ַ���ת����
		{
			cout << "ԤԼ����:��" << of._orderData[i]["date"] << " ";
			cout << "ʱ���:" << (of._orderData[i]["interval"] == "1" ? "����" : "����") << " ";
			cout << "����:" << of._orderData[i]["roomId"] << " ";

			string status = "״̬:";
			if (of._orderData[i]["status"] == "1") status += " �����";
			else if (of._orderData[i]["status"] == "2") status += " ԤԼ�ɹ�";
			else if (of._orderData[i]["status"] == "-1") status += " ԤԼʧ��,���δͨ��";
			else status += " ԤԼ��ȡ��";
			cout << status << endl;
		}
	}
	cout << endl;
	system("pause");
	system("cls");
}

// �鿴����ԤԼ
void Student::showAllOrder()
{
	OrderFile of;
	of.isEmpty();

	for (int i = 0; i < of._size; i++)
	{
		cout << i + 1 << "��";
		cout << "ԤԼ����:��" << of._orderData[i]["date"] << " ";
		cout << "ʱ���:" << (of._orderData[i]["interval"] == "1" ? "����" : "����") << " ";
		cout << "ѧ��:" << of._orderData[i]["stuId"] << " ";
		cout << "����:" << of._orderData[i]["stuName"] << " ";
		cout << "����:" << of._orderData[i]["roomId"] << " ";

		string status = "״̬:";
		if (of._orderData[i]["status"] == "1") status += " �����";
		else if (of._orderData[i]["status"] == "2") status += " ԤԼ�ɹ�";
		else if (of._orderData[i]["status"] == "-1") status += " ԤԼʧ��,���δͨ��";
		else status += " ԤԼ��ȡ��";
		cout << status << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
}

// ȡ��ԤԼ
void Student::cancelOrder()
{
	OrderFile of;
	of.isEmpty();

	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;
	map<int,int>  m;   // ������ȡ����¼���ļ��иü�¼�ı�� 
	 
	int index = 1;
	for (int i = 0; i < of._size; i++)
	{
		// ���ж������ѧ��
		if (this->_id == atoi(of._orderData[i]["stuId"].c_str()))
		{
			// ��ɸѡ״̬
			if (of._orderData[i]["status"] == "1" || of._orderData[i]["status"] == "2")
			{
				m.insert(make_pair(index, i));
				cout << index++ << " ";
				cout << "ԤԼ����: ��" << of._orderData[i]["date"] << " ";
				cout << "ʱ���:" << (of._orderData[i]["interval"] == "1" ? "����" : "����") << " ";
				cout << "����:" << of._orderData[i]["roomId"] << " ";
				string status = "״̬:";
				if (of._orderData[i]["status"] == "1") status += " �����";
				else if (of._orderData[i]["status"] == "2") status += " ԤԼ�ɹ�";
				cout << status << endl;
			}
		}
	}
	cout << "������ȡ���ļ�¼��0 to quit��:";
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= m.size())
		{
			if (select == 0) break;
			else {
				// ����Ϊȡ��ԤԼ
				of._orderData[m[select]]["status"] = "0";
				of.updateOrderToFile();
				cout << "��ȡ��ԤԼ��" << endl;
				break;
			}
		}
		cout << "�����������������룡" << endl;
	}
	system("pause");
	system("cls");
}