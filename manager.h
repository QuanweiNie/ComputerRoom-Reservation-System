#pragma once
#include <fstream>
#include "globalFile.h"
#include "identity.h"
#include <vector>
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"

using namespace std;

// 管理员类设计
class Manager : public Identity{
public:
	// 构造函数
	Manager();
	Manager(string name, string password);

	virtual void openMeau();       // 打开菜单
	void addPerson();              // 添加账号
	void showPerson();             // 查看账号
	void showComputerRoom();       // 查看机房信息
	void clearOrderRecord();       // 清空预约记录

	void initVector();             // 初始化容器
	bool checkRepeat(int id, int type_id);    // 查重

	
	vector<Student> _vstu;             // 学生容器
	vector<Teacher> _vtec;             // 老师容器
	vector<ComputerRoom>  _vcompRoom;  // 机房容器
};
