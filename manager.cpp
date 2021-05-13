#include "manager.h"

// 默认构造
Manager::Manager(){}

// 有参构造
Manager::Manager(string name, string password){
	// 初始化管理员信息
	this->_name = name;
	this->_password = password;

	// 初始化容器
	this->initVector();

	// 初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	
	ComputerRoom cpr ;
	while (ifs >> cpr._id && ifs >> cpr._size)
		_vcompRoom.push_back(cpr);
	ifs.close();

	cout << "机房的数量：" << _vcompRoom.size() << endl;
}

// 打开菜单
void Manager::openMeau(){
	cout << "欢迎管理员：" << this->_name << " 登陆！" << endl;
	cout << "\t\t--------------------------------\n";
	cout << "\t\t|         1.添加账号           |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|         2.查看账号           |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|         3.查看机房           |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|         4.清空预约           |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|         0.注销登陆           |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t--------------------------------\n";
	cout << "请选择您的操作：" << endl;
}

// 添加账号
void Manager::addPerson(){
	cout << "请输入添加的账号类型" << endl;
	cout << "1.学生" << endl;
	cout << "2.老师" << endl;

	string fileName;
	string tip;
	string errorTip;
	ofstream ofs;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		// 添加学生
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
		errorTip = "学号重复，请重新输入";
	}
	else {
		// 添加老师
		fileName = TEACHER_FILE;
		tip = "请输入职工编号：";
		errorTip = "职工学号重复，请重新输入";
	}
	ofs.open(fileName,ios::out | ios::app);

	int id;
	string name;
	string password;

	cout << tip << endl;
	while (true)
	{
		cin >> id;
		// 查重
		if (checkRepeat(id, select))
		{
		   cout << errorTip << endl;
		}
		else break;
	}
	cout << "请输入姓名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> password;

	ofs << id << " " << name << " " << password << endl;
	cout << "添加成功！" << endl;

	system("pause");
	system("cls");

	ofs.close();

	// 重新从文件中获取数据到对象中
	initVector();
}


// 查看账号
void Manager::showPerson()
{
	cout << "请选择查看内容：" << endl;
	cout << "1.查看所有的学生" << endl;
	cout << "2.查看所有的老师\n" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "所有学生信息如下:" << endl;
		for (auto stu : _vstu)
			cout << "学号：" << stu._id << "  姓名：" << stu._name << "  密码：" << stu._password << endl;
	}
	else if (select == 2)
	{
		cout << "所有老师信息如下：" << endl;
		for (auto tec : _vtec)
			cout << "职工号：" << tec._id << "  姓名：" << tec._name << "  密码：" << tec._password << endl;
	}
	system("pause");
	system("cls");
}

// 查看机房信息
void Manager::showComputerRoom(){
	for (auto cpr : _vcompRoom)
		cout << "机房编号:" << cpr._id << "  机房最大容量：" << cpr._size << endl;

	system("pause");
	system("cls");
}

// 清空预约记录
void Manager::clearOrderRecord()
{
	cout << "1.确认？" << endl;
	cout << "2.取消？" << endl;

	int choice = 0;
	cin >> choice;
	if (choice == 1)
	{
		ofstream  ofs(ORDER_FILE, ios::trunc);
		ofs.close();
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}


void Manager::initVector() {
	//确保容器为空
	_vstu.clear();
	_vtec.clear();

	// 读信息  学生
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()){
		cout << "文件打开失败" << endl;
		return;
	}
	Student s;
	while (ifs >> s._id && ifs >> s._name && ifs >> s._password)
		_vstu.push_back(s);

	cout << "当前的学生数量为：" << _vstu.size() << endl;
	ifs.close();

	// 读信息  老师
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()){
		cout << "文件打开失败" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t._id && ifs >> t._name && ifs >> t._password)
		_vtec.push_back(t);

	cout << "当前的老师数量为：" << _vtec.size() << endl;
	ifs.close();
}


// 查重
bool Manager::checkRepeat(int id, int type_id)
{
	// 检测学生
	if (type_id == 1)
	{
		for (auto stu : _vstu)
		{
			if (id == stu._id)
				return true;
		}
	}
	// 检测老师
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
