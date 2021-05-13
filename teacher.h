#pragma once
#include "identity.h"
#include "orderFile.h"
#include "student.h"

using namespace std;

// 教师类
class Teacher : public Identity{
public:
	// 构造函数
	Teacher();
	Teacher(int id, string name, string password);

	virtual void openMeau();   // 打开菜单
	void showOrder();          // 显示预约
	void validOrder();         // 审核预约

	// 教职工编号
	int _id;
};