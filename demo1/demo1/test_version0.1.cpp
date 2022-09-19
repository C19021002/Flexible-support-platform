#include<iostream>
#include<iomanip>
#include"IP_ADDRESS.h"
#include"trans.h"
#include"hex_ascii_to_hex_char.h"
#include"demo1.h"

using namespace std;
using std::setw;

int main() {
	Client client[36];
	sensor CLIENT[36];
	SOCKET socket_client[36];
	for (int i = 0;i < 36;i++) {
		CLIENT[i].IP_ADDRESS = IP_ADDRESS[i];
	}
	for (int i = 0;i < 36;i++) {
		client[i].socket_init();
		socket_client[i]=client[i].socket_client_creat(CLIENT[i].IP_ADDRESS, CLIENT[i].PORT);
	}
	while (1) {
		int data_send[36];
		for (int t = 0;t < 36;t++) {
			if (send(socket_client[t], client[t].Order, 8, 0) < 0) {
				cout << "发送失败！" << endl;
			}
			if (recv(socket_client[t], client[t].BUFFER_RECEIVED, 10, 0) < 0) {
				cout << "接受失败" << endl;
			}
			else {
				client[t].BUFFER_RECEIVED[9] = '\0';
				cout << "服务端信息：" << client[t].BUFFER_RECEIVED << endl;
				char high;
				char low;
				for (int i = 0;i < 9;i++) {
					Hex_ascii_to_Hex_char(client[t].BUFFER_RECEIVED[i], low, high);
					cout << high << low << setw(5);
				}
				cout << endl;
				char Low[5], High[5];
				Low[4] = '\0';//结尾终止符，防输出乱码
				High[4] = '\0';
				char Hex[9];
				Hex[8] = '\0';
				for (int i = 3;i < 7; i++) {
					Hex_ascii_to_Hex_char(client[t].BUFFER_RECEIVED[i], Low[i - 3], High[i - 3]);
				}
				for (int i = 0;i < 4;i++) Hex[2 * i] = High[i];
				for (int i = 0;i < 4;i++) Hex[2 * i + 1] = Low[i];
				cout << setw(5) << Hex << endl;
				int data = 0;
				for (int i = 0;i < 8;i++) {
					int product = 0;
					product = reverse_trans(Hex[i], product);
					data = data * 16 + product;
				}
				cout << hex << setw(5) << data << endl;
				int Data = data;
				if ((Data >> 31 & 1) == 1) {
					cout << "是负数" << endl;
					data = ~(data);
					data = data + 1;
					cout << "结果是：" << dec << setw(5) << " -" << data << endl;
				}
				else {
					cout << "是正数:" << endl;
					cout << "结果是:" << dec << data << endl;
				}
				cout << "执行了" << t << "个服务器" << endl;
				CLIENT[t].data = data;
				client[t].get_data(CLIENT[t]);
				//socket_close(client);
			}
			//delete(BUFFER_received);

		}
		Sleep(5000);
	}
	for (int n = 0;n < 36;n++)
		closesocket(socket_client[n]);
	WSACleanup();
	return 0;
}