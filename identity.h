#pragma once
#include <iostream>
#include <string>

using std::string;

// 身份抽象基类
class Identity {
public:
	// 操作菜单
	virtual void openMeau() = 0;

	string _name;       // 用户名
	string _password;   // 密码
};