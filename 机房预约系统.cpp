#include <iostream>
#include <fstream>
#include <string>
#include "globalFile.h"
#include "identity.h"
#include "manager.h"
#include "student.h"
#include "teacher.h"

using namespace std;


// ��ʦ�Ӳ˵�
void teacherMeau(Identity* teacher){
	while (true){
		// ��̬���ý�ʦ�Ӳ˵�
		teacher->openMeau();

		Teacher* tec = (Teacher*)teacher;

		int select = 0;
		cin >> select;
		if (select == 1){
			// �鿴ԤԼ
			tec->showOrder();  
		}
		else if (select == 2){
			// ���ԤԼ
			tec->validOrder();  
		}
		else if (select == 0) {
			// ע����½
			delete teacher;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


// ѧ���Ӳ˵�
void studentMeau(Identity* student){
	while (true){
		// ��̬����ѧ���Ӳ˵�
		student->openMeau();

		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		if (select == 1)  {
			// ����ԤԼ
			stu->applyOrder();

		}
		else if (select == 2){
			// �鿴ԤԼ
			stu->showMyOrder();
		}
		else if (select == 3){
			// �鿴������ԤԼ
			stu->showAllOrder();
		}
		else if (select == 4){
			// ȡ��ԤԼ
			stu->cancelOrder();
		}
		else{
			// ע����½
			delete student;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


// ����Ա�Ӳ˵�
void managerMeau(Identity* manager) {
	while (true){
		// ��̬ʵ�ֵ��ù���Ա�Ӳ˵�
		manager->openMeau();

		// ����ָ��ת��Ϊ����ָ��
		Manager* man = (Manager*)manager;

		int select;
		cin >> select;
		if (select == 1) {
			// ����˺�
			man->addPerson();
		}
		else if (select == 2) {
			// �鿴�˺�
			man->showPerson();
		}
		else if (select == 3) {
			// �鿴������Ϣ
			man->showComputerRoom();
		}
		else if (select == 4) {
			// ���ԤԼ
			man->clearOrderRecord();
		}
		else {
			// ע����½
			delete manager;    // �ͷ�ָ����������ָ�룬ͬʱ�ͷŸ��ڴ�Ķ���
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


// ��½
void loginIn(string fileName, int type_id){
	Identity* person = nullptr;     // ����ָ��,����ͨ����̬��ʹ�����������

	// ���û����ݣ����е�½��֤
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open()){
		cout << " �ļ������ڻ��߼�¼Ϊ�գ�" << endl;
		ifs.close();
		return;
	}
	
    int id = 0;        // �������������ֶ���ʼ��
	string name;       // ��׼�� string �ṩĬ�Ϲ��캯��
	string password;

	if (type_id == 1){
		cout << "������ѧ�ţ� " << endl;
		cin >> id;
	}
	else if (type_id == 2){
		cout << "������ְ���ţ�" << endl;
		cin >> id;
	}
	cout << "�������û����� " << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> password;

	// ѧ�������֤
	if (type_id == 1)   { 
		int fid;
		string fname;
		string fpassword;
		while (ifs >> fid && ifs >> fname && ifs >> fpassword){
			// ��ѧ������Ϣ���Ա�
			if (fid == id && fname == name && fpassword == password){
				cout << "ѧ����֤��½�ɹ���" << endl;
				system("pause");
				system("cls");
			    person = new Student(id, name, password);

				// ����ѧ���ӽ���
				studentMeau(person);
				return;
			}
		}
	}
	// ��ʦ�����֤
	else if (type_id == 2)  {
		int fid;
		string fname;
		string fpassword;
		while (ifs >> fid && ifs >> fname && ifs >> fpassword){
			// ���ʦ����Ϣ���Ա�
			if (fid == id && fname == name && fpassword == password){
				cout << "��ʦ��֤��½�ɹ���" << endl;
				system("pause");
				system("cls");

				person = new Teacher(id, name, password);

				// ������ʦ�ӽ���
				teacherMeau(person);
				return;
			}
		}
	}
	// ����Ա�����֤
	else if (type_id == 3){
		string fname;
		string fpassword;
		while (ifs >> fname && ifs >> fpassword){
			// ����Ա��Ϣ�Ա�
			if (fname == name && fpassword == password){
				cout << "����Ա��֤��½�ɹ���" << endl;
				system("pause");
				system("cls");

				person = new Manager(name, password);

				// �������Ա�ӽ���
				managerMeau(person);
				return;
			}
		}
	}
	cout << "��֤��½ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
}



int main(){
	// �û�ѡ��
	int select = 0;
	while (true){
		cout << "==========    ��ӭ���� UESTC ѧ������ԤԼϵͳ   ===========\n" << endl;
		cout << "\t\t------------------------------\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|       1.ѧ������           |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|       2.��    ʦ           |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|       3.�� �� Ա           |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|       0.��    ��           |\n";
		cout << "\t\t------------------------------\n";
		cout << "============================================================" << endl;
		cout << "����������ѡ��:";

		cin >> select;
		switch (select){
		    case 1:  // ѧ������
				loginIn(STUDENT_FILE, 1);
			   break;
		    case 2:  // ��ʦ
				loginIn(TEACHER_FILE, 2);
			   break;
		    case 3:  // ����Ա
				loginIn(ADMIN_FILE, 3);
			   break;
		    case 0:  // �˳�ϵͳ
		    {
			    cout << "��ӭ�´�ʹ�ã�" << endl;
			    system("pause");
			    return 0;
		    }
		    default:{
			    cout << "�Ƿ����룬���������룡" << endl;
			    system("pause");
			    system("cls");
			    break;
		    }			
		}
	}
	system("pause");
	return 0;
}