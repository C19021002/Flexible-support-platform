#ifndef DEMO_H
#define DEMO_H

#include<iostream>
#include<WinSock.h>
#pragma comment(lib,"ws2_32.lib")


using namespace std;
struct sensor {
	int PORT = 2001;
	const char* IP_ADDRESS;
	int data = 0;
};
class Client {
public:
	Client();

	Client(sensor SENSOR_INFORMATION);

	SOCKET socket_client_creat(const char* ip, int PORT);

	void socket_init();

	const int get_data(sensor SENSOR_IMFORMATION);

	const char Order[8] = { 0x01,0x03,0x00,0x00,0x00,0x02,0xC4,0x0B };

	char BUFFER_RECEIVED[16];

private:
	sensor SENSOR_INFORMATION;

};
#endif
