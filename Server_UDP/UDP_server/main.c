 // UDP ������
  #pragma comment ( lib, "ws2_32.lib" )
  #include <stdio.h>
  #include <winsock2.h>

#include <iostream>

using namespace std;

  int main()
  {

	char buff[1024];

    printf("UDP Server Started\n");

    // ������������� WinSock
	WORD wVersionRequested = MAKEWORD (2,2);
	WSADATA wsaData;
    int err = WSAStartup(wVersionRequested, &wsaData);
	if (err !=0)
    {
      printf("WSAStartup error: %d\n",WSAGetLastError());
    }
	else printf("WinSock intializing\n");

    // �������� � �������� ������
    SOCKET my_sock = socket(AF_INET,SOCK_DGRAM,0);
    if (my_sock==INVALID_SOCKET)
    {
      printf("Socket error: %d\n",WSAGetLastError());
      WSACleanup();
    }

    // ���������� ������
    sockaddr_in sin;
    sin.sin_family=AF_INET;
    sin.sin_addr.s_addr=htonl(INADDR_ANY);
    sin.sin_port=htons(5150);

    if (bind(my_sock,(sockaddr *) &sin, sizeof(sin))==SOCKET_ERROR)
    {
      printf("bind error: %d\n",WSAGetLastError());
      closesocket(my_sock);
    }


	// ��������� ���������� ������
	while(1)
	{
		sockaddr_in client_addr;
		int client_addr_size = sizeof(client_addr);
		int bsize= recvfrom(my_sock,&buff[0],sizeof(buff)-1,0, (sockaddr *) &client_addr, &client_addr_size);
		if (bsize==SOCKET_ERROR)
		printf("recvfrom() error: %d\n",WSAGetLastError());


      // ���������� IP-����� ������� � ������ ��������
	  HOSTENT *hostent;
      hostent = gethostbyaddr((char *)&client_addr.sin_addr,4,AF_INET);
      printf("accepted connection from %s, port %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

	  // ���������� ������������ ����
	  buff[bsize]=0;

		        // ����� �� �����
      printf("C=>S:%s\n",&buff[0]);

      // ������� ���������� �������
      sendto(my_sock,&buff[0],bsize,0,
        (sockaddr *)&client_addr, sizeof(client_addr));

  }
return 0;
  }
