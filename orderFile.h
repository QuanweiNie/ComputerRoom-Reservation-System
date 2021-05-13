#pragma once
#include <iostream>
#include "globalFile.h"
#include <fstream>
#include <map>
#include <string>

using namespace std;

// 记录文件
class OrderFile{
public:
	// 构造函数
	OrderFile();

	// 处理数据
	void initData(const string str,map<string,string> &m);

	// 更新预约记录
	void updateOrderToFile();

	// 检查记录是否为空
	bool isEmpty();

	// 记录预约条数
	int _size;

	// 记录容器
	map<int, map<string, string>>  _orderData;
};