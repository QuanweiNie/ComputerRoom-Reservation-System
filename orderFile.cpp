#include "orderFile.h"

// ���캯��
OrderFile::OrderFile(){
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	// ԤԼ��¼��ʽ
	string date;    
	string interval;    // ʱ���
	string stuId;
	string stuName;
	string roomId;     // ������
	string status;     // ԤԼ״̬

	this->_size = 0;   // ԤԼ��¼����

	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status){
		map<string, string> m;
		initData(date,m);
		initData(interval,m);
		initData(stuId,m);
		initData(stuName,m);
		initData(roomId,m);
		initData(status,m);

		// ��ӵ���map
		this->_orderData.insert(make_pair(this->_size, m));

		// ���Ӽ�¼
		this->_size++;  
	}
	ifs.close();
}


// ����Ԥ����
void OrderFile::initData(const string str,map<string,string> &m){
	string key;
	string value;
	
	// �ָ�
	int pos = str.find(":");    // δ�ҵ�����-1
	if (pos != -1){
		key = str.substr(0, pos);
		value = str.substr(pos + 1, str.size() - pos - 1);
	    // �����ֵ��
		m.insert(make_pair(key, value));
	}
}

bool OrderFile::isEmpty(){
	if (this->_size == 0){
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return true;
	}
	return false;
}


// ����ԤԼ��¼���ļ�
void OrderFile::updateOrderToFile(){
	// ԤԼΪ�գ����ظ���
	if (this->_size == 0) return;
	
	// ���µ��ļ���
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);   // trunc ɾ���󴴽�
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