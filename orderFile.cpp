#include "orderFile.h"

// 构造函数
OrderFile::OrderFile(){
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	// 预约记录格式
	string date;    
	string interval;    // 时间段
	string stuId;
	string stuName;
	string roomId;     // 机房号
	string status;     // 预约状态

	this->_size = 0;   // 预约记录条数

	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status){
		map<string, string> m;
		initData(date,m);
		initData(interval,m);
		initData(stuId,m);
		initData(stuName,m);
		initData(roomId,m);
		initData(status,m);

		// 添加到大map
		this->_orderData.insert(make_pair(this->_size, m));

		// 增加记录
		this->_size++;  
	}
	ifs.close();
}


// 数据预处理
void OrderFile::initData(const string str,map<string,string> &m){
	string key;
	string value;
	
	// 分割
	int pos = str.find(":");    // 未找到返回-1
	if (pos != -1){
		key = str.substr(0, pos);
		value = str.substr(pos + 1, str.size() - pos - 1);
	    // 构造键值对
		m.insert(make_pair(key, value));
	}
}

bool OrderFile::isEmpty(){
	if (this->_size == 0){
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return true;
	}
	return false;
}


// 更新预约记录到文件
void OrderFile::updateOrderToFile(){
	// 预约为空，不必更新
	if (this->_size == 0) return;
	
	// 更新到文件中
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);   // trunc 删除后创建
	for (int i = 0; i < this->_size; i++){
		ofs << "date:" << this->_orderData[i]["date"] << " ";
		ofs << "interval:" << this->_orderData[i]["intgerval"] << " ";
		ofs << "stuId:" << this->_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->_orderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->_orderData[i]["roomId"] << " ";
		ofs << "status:" << this->_orderData[i]["status"] << endl;
	}
	ofs.close();
}