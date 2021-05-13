#include "manager.h"

// Ĭ�Ϲ���
Manager::Manager(){}

// �вι���
Manager::Manager(string name, string password){
	// ��ʼ������Ա��Ϣ
	this->_name = name;
	this->_password = password;

	// ��ʼ������
	this->initVector();

	// ��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	
	ComputerRoom cpr ;
	while (ifs >> cpr._id && ifs >> cpr._size)
		_vcompRoom.push_back(cpr);
	ifs.close();

	cout << "������������" << _vcompRoom.size() << endl;
}

// �򿪲˵�
void Manager::openMeau(){
	cout << "��ӭ����Ա��" << this->_name << " ��½��" << endl;
	cout << "\t\t--------------------------------\n";
	cout << "\t\t|         1.����˺�           |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|         2.�鿴�˺�           |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|         3.�鿴����           |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|         4.���ԤԼ           |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|         0.ע����½           |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t--------------------------------\n";
	cout << "��ѡ�����Ĳ�����" << endl;
}

// ����˺�
void Manager::addPerson(){
	cout << "��������ӵ��˺�����" << endl;
	cout << "1.ѧ��" << endl;
	cout << "2.��ʦ" << endl;

	string fileName;
	string tip;
	string errorTip;
	ofstream ofs;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		// ���ѧ��
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errorTip = "ѧ���ظ�������������";
	}
	else {
		// �����ʦ
		fileName = TEACHER_FILE;
		tip = "������ְ����ţ�";
		errorTip = "ְ��ѧ���ظ�������������";
	}
	ofs.open(fileName,ios::out | ios::app);

	int id;
	string name;
	string password;

	cout << tip << endl;
	while (true)
	{
		cin >> id;
		// ����
		if (checkRepeat(id, select))
		{
		   cout << errorTip << endl;
		}
		else break;
	}
	cout << "������������" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> password;

	ofs << id << " " << name << " " << password << endl;
	cout << "��ӳɹ���" << endl;

	system("pause");
	system("cls");

	ofs.close();

	// ���´��ļ��л�ȡ���ݵ�������
	initVector();
}


// �鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1.�鿴���е�ѧ��" << endl;
	cout << "2.�鿴���е���ʦ\n" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "����ѧ����Ϣ����:" << endl;
		for (auto stu : _vstu)
			cout << "ѧ�ţ�" << stu._id << "  ������" << stu._name << "  ���룺" << stu._password << endl;
	}
	else if (select == 2)
	{
		cout << "������ʦ��Ϣ���£�" << endl;
		for (auto tec : _vtec)
			cout << "ְ���ţ�" << tec._id << "  ������" << tec._name << "  ���룺" << tec._password << endl;
	}
	system("pause");
	system("cls");
}

// �鿴������Ϣ
void Manager::showComputerRoom(){
	for (auto cpr : _vcompRoom)
		cout << "�������:" << cpr._id << "  �������������" << cpr._size << endl;

	system("pause");
	system("cls");
}

// ���ԤԼ��¼
void Manager::clearOrderRecord()
{
	cout << "1.ȷ�ϣ�" << endl;
	cout << "2.ȡ����" << endl;

	int choice = 0;
	cin >> choice;
	if (choice == 1)
	{
		ofstream  ofs(ORDER_FILE, ios::trunc);
		ofs.close();
		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}


void Manager::initVector() {
	//ȷ������Ϊ��
	_vstu.clear();
	_vtec.clear();

	// ����Ϣ  ѧ��
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()){
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	Student s;
	while (ifs >> s._id && ifs >> s._name && ifs >> s._password)
		_vstu.push_back(s);

	cout << "��ǰ��ѧ������Ϊ��" << _vstu.size() << endl;
	ifs.close();

	// ����Ϣ  ��ʦ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()){
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t._id && ifs >> t._name && ifs >> t._password)
		_vtec.push_back(t);

	cout << "��ǰ����ʦ����Ϊ��" << _vtec.size() << endl;
	ifs.close();
}


// ����
bool Manager::checkRepeat(int id, int type_id)
{
	// ���ѧ��
	if (type_id == 1)
	{
		for (auto stu : _vstu)
		{
			if (id == stu._id)
				return true;
		}
	}
	// �����ʦ
	else
	{
		for (auto tec : _vtec)
		{
			if (id == tec._id)
				return true;
		}
	}
	return false;
}
