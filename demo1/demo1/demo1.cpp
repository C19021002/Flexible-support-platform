#include <iostream>
#include <iomanip>
#include "demo1.h" 
using namespace std;
using std::setw;

Client::Client(sensor client) {
	//int data = client.data;
	//char IP_address = client.IP_ADDRESS;
	///int PORT = client.PORT;
	//SENSOR_INFORMATION.IP_ADDRESS = IP;
}

SOCKET Client::socket_client_creat(const char *ip,int PORT) {
	//socket_init();
	SOCKET c_client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (c_client == INVALID_SOCKET) {
		cout << "�׽��ִ���ʧ��" << endl;
	}
	else {
		cout << "�׽��ִ����ɹ�" << endl;
	}

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.S_un.S_addr = inet_addr(ip);

	if (connect(c_client, (struct sockaddr*)&addr, sizeof(addr)) == INVALID_SOCKET) {
		cout << "������" << setw(5) << ip << setw(5) << "����ʧ�ܣ�" << endl;
		WSACleanup();
	}
	else {
		cout << "������" << setw(5) << ip << setw(5) << "���ӳɹ���" << endl;
		return c_client;
}
	}
void Client::socket_init(){
	WORD w_req = MAKEWORD(2, 2);
	WSADATA wsadata;
	if (WSAStartup(w_req, &wsadata) != 0) {
		cout << "��ʼ���׽��ֿ�ʧ�ܣ�" << endl;
	}
	else {
		cout << "��ʼ���׽��ֿ�ɹ���" << endl;
	}
}
const int Client::get_data(sensor SENSOR_INFORMATION) {
	int get_data = SENSOR_INFORMATION.data;
	return get_data;
}


