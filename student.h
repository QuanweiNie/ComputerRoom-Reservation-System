#pragma once
#include "identity.h"
#include <vector>
#include "computerRoom.h"
#include <fstream>
#include "globalFile.h"
#include "orderFile.h"
#include <map>

using namespace std;

// 学生类
class Student :public Identity {
public:
	Student();
	Student(int id,string name, string password);   // 有参构造： 学号，姓名，密码

	virtual void openMeau();   // 打开菜单    
	void applyOrder();  	   // 申请预约
	void showMyOrder();        // 查看自己的预约
	void showAllOrder();       // 查看所有预约
	void cancelOrder();        // 取消预约

	// 学生学号
	int _id;
	vector<ComputerRoom> _vcpr;   // 机房容器
};