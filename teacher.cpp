#include "teacher.h"

Teacher::Teacher(){}

// 有参构造
Teacher::Teacher(int id, string name, string password)
{
	// 初始化属性
	this->_id = id;
	this->_name = name;
	this->_password = password;
}

// 打开菜单
void Teacher::openMeau()
{
	cout << "欢迎教师:" << this->_name << "登陆！" << endl;
	cout << "\t\t-----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.审核预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登陆              |\n";
	cout << "\t\t-----------------------------------\n";
	cout << "请选择您的操作:" << endl;
}

// 显示预约
void Teacher::showOrder(){
	Student s;
	s.showAllOrder();
}


// 审核预约
void Teacher::validOrder(){
	OrderFile of;
	if (of.isEmpty()) return;

	cout << "待审核的预约记录如下:" << endl;
	map<int, int>  m;  // 关联显示记录和文件中的记录下标

	int index = 1;
	for (int i = 0; i < of._size; i++)
	{
		// 待审核
		if ( of._orderData[i]["status"] == "1")   // "1" 表示待审核
		{
			m.insert(make_pair(index, i));
			cout << index++ << " ";

			cout << "预约日期: 周" << of._orderData[i]["date"] << " ";
			cout << "时间段:" << (of._orderData[i]["interval"] == "1" ? "上午" : "下午") << " ";
			cout << "机房:" << of._orderData[i]["roomId"] << " ";

			string status = "状态:";
			if (of._orderData[i]["status"] == "1") status += " 审核中";
			cout << status << endl;
		}
	}
	cout << "请输入要审核的预约记录编号（0 to quit）:";
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= m.size())
		{
			if (select == 0) break;
			else {
				// 审核记录
				cout << "请输入审核结果" << endl;
				cout << "1.通过" << endl;
				cout << "2.不通过" << endl;

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
				cout << "审核成功！" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入！" << endl;
	}
	system("pause");
	system("cls");
}