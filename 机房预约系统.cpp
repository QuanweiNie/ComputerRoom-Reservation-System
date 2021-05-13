#include <iostream>
#include <fstream>
#include <string>
#include "globalFile.h"
#include "identity.h"
#include "manager.h"
#include "student.h"
#include "teacher.h"

using namespace std;


// 教师子菜单
void teacherMeau(Identity* teacher){
	while (true){
		// 多态调用教师子菜单
		teacher->openMeau();

		Teacher* tec = (Teacher*)teacher;

		int select = 0;
		cin >> select;
		if (select == 1){
			// 查看预约
			tec->showOrder();  
		}
		else if (select == 2){
			// 审核预约
			tec->validOrder();  
		}
		else if (select == 0) {
			// 注销登陆
			delete teacher;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


// 学生子菜单
void studentMeau(Identity* student){
	while (true){
		// 多态调用学生子菜单
		student->openMeau();

		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		if (select == 1)  {
			// 申请预约
			stu->applyOrder();

		}
		else if (select == 2){
			// 查看预约
			stu->showMyOrder();
		}
		else if (select == 3){
			// 查看所有人预约
			stu->showAllOrder();
		}
		else if (select == 4){
			// 取消预约
			stu->cancelOrder();
		}
		else{
			// 注销登陆
			delete student;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


// 管理员子菜单
void managerMeau(Identity* manager) {
	while (true){
		// 多态实现调用管理员子菜单
		manager->openMeau();

		// 父类指针转换为子类指针
		Manager* man = (Manager*)manager;

		int select;
		cin >> select;
		if (select == 1) {
			// 添加账号
			man->addPerson();
		}
		else if (select == 2) {
			// 查看账号
			man->showPerson();
		}
		else if (select == 3) {
			// 查看机房信息
			man->showComputerRoom();
		}
		else if (select == 4) {
			// 清空预约
			man->clearOrderRecord();
		}
		else {
			// 注销登陆
			delete manager;    // 释放指向堆区对象的指针，同时释放该内存的对象
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


// 登陆
void loginIn(string fileName, int type_id){
	Identity* person = nullptr;     // 基类指针,可以通过多态来使用派生类对象

	// 读用户数据，进行登陆验证
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open()){
		cout << " 文件不存在或者记录为空！" << endl;
		ifs.close();
		return;
	}
	
    int id = 0;        // 内置数据类型手动初始化
	string name;       // 标准库 string 提供默认构造函数
	string password;

	if (type_id == 1){
		cout << "请输入学号： " << endl;
		cin >> id;
	}
	else if (type_id == 2){
		cout << "请输入职工号：" << endl;
		cin >> id;
	}
	cout << "请输入用户名： " << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> password;

	// 学生身份验证
	if (type_id == 1)   { 
		int fid;
		string fname;
		string fpassword;
		while (ifs >> fid && ifs >> fname && ifs >> fpassword){
			// 与学生的信息作对比
			if (fid == id && fname == name && fpassword == password){
				cout << "学生验证登陆成功！" << endl;
				system("pause");
				system("cls");
			    person = new Student(id, name, password);

				// 进入学生子界面
				studentMeau(person);
				return;
			}
		}
	}
	// 教师身份验证
	else if (type_id == 2)  {
		int fid;
		string fname;
		string fpassword;
		while (ifs >> fid && ifs >> fname && ifs >> fpassword){
			// 与教师的信息作对比
			if (fid == id && fname == name && fpassword == password){
				cout << "教师验证登陆成功！" << endl;
				system("pause");
				system("cls");

				person = new Teacher(id, name, password);

				// 进入老师子界面
				teacherMeau(person);
				return;
			}
		}
	}
	// 管理员身份验证
	else if (type_id == 3){
		string fname;
		string fpassword;
		while (ifs >> fname && ifs >> fpassword){
			// 管理员信息对比
			if (fname == name && fpassword == password){
				cout << "管理员验证登陆成功！" << endl;
				system("pause");
				system("cls");

				person = new Manager(name, password);

				// 进入管理员子界面
				managerMeau(person);
				return;
			}
		}
	}
	cout << "验证登陆失败！" << endl;
	system("pause");
	system("cls");
}



int main(){
	// 用户选择
	int select = 0;
	while (true){
		cout << "==========    欢迎来到 UESTC 学生机房预约系统   ===========\n" << endl;
		cout << "\t\t------------------------------\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|       1.学生代表           |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|       2.老    师           |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|       3.管 理 员           |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|       0.退    出           |\n";
		cout << "\t\t------------------------------\n";
		cout << "============================================================" << endl;
		cout << "请输入您的选择:";

		cin >> select;
		switch (select){
		    case 1:  // 学生代表
				loginIn(STUDENT_FILE, 1);
			   break;
		    case 2:  // 老师
				loginIn(TEACHER_FILE, 2);
			   break;
		    case 3:  // 管理员
				loginIn(ADMIN_FILE, 3);
			   break;
		    case 0:  // 退出系统
		    {
			    cout << "欢迎下次使用！" << endl;
			    system("pause");
			    return 0;
		    }
		    default:{
			    cout << "非法输入，请重新输入！" << endl;
			    system("pause");
			    system("cls");
			    break;
		    }			
		}
	}
	system("pause");
	return 0;
}