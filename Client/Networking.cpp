#pragma comment(lib, "wsock32.lib")
#pragma comment(lib,"ws2_32.lib")
#include "pch.h"
#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <WS2tcpip.h>

int main() {
	std::cout << "test";

	Connect(L"123.55.10.1", 80);

	Packet packet;

}

struct Packet
{
	int size;
	char string[256];
};

SOCKET sock; // this is the socket that we will use it 
SOCKADDR_IN i_sock; // this will containt some informations about our socket
WSADATA Data; // this is to save our socket version

int Connect(PCWSTR IP, int Port)
{
	WSAStartup(MAKEWORD(2, 2), &Data);
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET)
	{

		return 1;
	}
	i_sock.sin_family = AF_INET;
	//i_sock.sin_addr.s_addr = inet_addr(IP);
	InetPton(AF_INET, IP, &i_sock.sin_addr.s_addr);
	i_sock.sin_port = htons(Port);
	int ss = connect(sock, (struct sockaddr *)&i_sock, sizeof(i_sock));
	if (ss != 0)
	{ 
		printf("Cannot connect");
		return 0;
	}

	printf("Succefully connected");
	return 1;
}