#include "student.h"

// 默认构造
Student::Student(){}

// 有参构造
Student::Student(int id, string name, string password){
	// 初始化
	this->_id = id;
	this->_name = name;
	this->_password = password;

	// 机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	
	ComputerRoom cpr;
	while (ifs >> cpr._id && ifs >> cpr._size)
		_vcpr.push_back(cpr);
	ifs.close();
}


// 打开菜单
void Student::openMeau(){
	cout << "欢迎学生代表：" << this->_name << " 登陆!" << endl;
	cout << "\t\t--------------------------------------\n";
	cout << "\t\t|                                     \n";
	cout << "\t\t|              1.申请预约             \n";
	cout << "\t\t|                                     \n";
	cout << "\t\t|              2.查看我的预约         \n";
	cout << "\t\t|                                     \n";
	cout << "\t\t|              3.查看所有预约         \n";
	cout << "\t\t|                                     \n";
	cout << "\t\t|              4.取消预约             \n";
	cout << "\t\t|                                     \n";
	cout << "\t\t|              0.注销登陆             \n";
	cout << "\t\t--------------------------------------\n";
	cout << "请输入你想要执行的操作：" << endl;
 }   

// 申请预约
void Student::applyOrder(){
	cout << "机房开放时间：周一至周五" << endl;
	cout << "请输入预约的时间：" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;
	cout << endl;

	int date = 0;        // 日期
	int interval = 0;    // 时间段
	int room = 0;        // 机房编号

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
			break;
		cout << "输入有误，请重新输入！" << endl;
	}
	cout << "请输入申请预约的时间段：" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2) break;
		cout << "输入有误，请重新输入" << endl;
	}
	cout << "请选择机房：" << endl;
	cout << _vcpr[0]._id << "号机房容量为：" << _vcpr[0]._size << endl;
	cout << _vcpr[1]._id << "号机房容量为：" << _vcpr[1]._size << endl;
	cout << _vcpr[2]._id << "号机房容量为：" << _vcpr[2]._size << endl;
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3) break;
		cout << "输入有误，请重新输入！" << endl;
	}
	cout << "预约成功! 审核中" << endl;

	// 写文件
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->_id << " ";
	ofs << "stuName:" << this->_name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << "1" << endl;    // 1 代表审核中

	ofs.close();
	system("pause");
	system("cls");
}

// 查看自己的预约
void Student::showMyOrder(){
	OrderFile of;
	of.isEmpty();

	for (int i = 0; i < of._size; i++)
	{
		if (this->_id == atoi(of._orderData[i]["stuId"].c_str()))  // c-style字符串转整型
		{
			cout << "预约日期:周" << of._orderData[i]["date"] << " ";
			cout << "时间段:" << (of._orderData[i]["interval"] == "1" ? "上午" : "下午") << " ";
			cout << "机房:" << of._orderData[i]["roomId"] << " ";

			string status = "状态:";
			if (of._orderData[i]["status"] == "1") status += " 审核中";
			else if (of._orderData[i]["status"] == "2") status += " 预约成功";
			else if (of._orderData[i]["status"] == "-1") status += " 预约失败,审核未通过";
			else status += " 预约已取消";
			cout << status << endl;
		}
	}
	cout << endl;
	system("pause");
	system("cls");
}

// 查看所有预约
void Student::showAllOrder()
{
	OrderFile of;
	of.isEmpty();

	for (int i = 0; i < of._size; i++)
	{
		cout << i + 1 << "、";
		cout << "预约日期:周" << of._orderData[i]["date"] << " ";
		cout << "时间段:" << (of._orderData[i]["interval"] == "1" ? "上午" : "下午") << " ";
		cout << "学号:" << of._orderData[i]["stuId"] << " ";
		cout << "姓名:" << of._orderData[i]["stuName"] << " ";
		cout << "机房:" << of._orderData[i]["roomId"] << " ";

		string status = "状态:";
		if (of._orderData[i]["status"] == "1") status += " 审核中";
		else if (of._orderData[i]["status"] == "2") status += " 预约成功";
		else if (of._orderData[i]["status"] == "-1") status += " 预约失败,审核未通过";
		else status += " 预约已取消";
		cout << status << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
}

// 取消预约
void Student::cancelOrder()
{
	OrderFile of;
	of.isEmpty();

	cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;
	map<int,int>  m;   // 关联可取消记录和文件中该记录的编号 
	 
	int index = 1;
	for (int i = 0; i < of._size; i++)
	{
		// 先判断自身的学号
		if (this->_id == atoi(of._orderData[i]["stuId"].c_str()))
		{
			// 再筛选状态
			if (of._orderData[i]["status"] == "1" || of._orderData[i]["status"] == "2")
			{
				m.insert(make_pair(index, i));
				cout << index++ << " ";
				cout << "预约日期: 周" << of._orderData[i]["date"] << " ";
				cout << "时间段:" << (of._orderData[i]["interval"] == "1" ? "上午" : "下午") << " ";
				cout << "机房:" << of._orderData[i]["roomId"] << " ";
				string status = "状态:";
				if (of._orderData[i]["status"] == "1") status += " 审核中";
				else if (of._orderData[i]["status"] == "2") status += " 预约成功";
				cout << status << endl;
			}
		}
	}
	cout << "请输入取消的记录（0 to quit）:";
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= m.size())
		{
			if (select == 0) break;
			else {
				// 设置为取消预约
				of._orderData[m[select]]["status"] = "0";
				of.updateOrderToFile();
				cout << "已取消预约！" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入！" << endl;
	}
	system("pause");
	system("cls");
}