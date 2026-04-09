#include<winsock2.h>
#include<ws2tcpip.h>
#include<iostream>
#include<string>
#pragma comment(lib, "ws2_32.lib")
using namespase std;

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cout<<"WSAStartup failed. Error: "<<WSAGetLastError()<<endl;
        return 1;
    }

    SOCKET s1 = socket(AF_INET, SOCK_STREAM, 0);
    if (s1 == INVALID_SOCKET) {
        cout<<"Socket creation failed. Error: "<<WSAGetLastError()<<endl;
        WSACleanup();
        return 1;
    }

    struct sockaddr_in anAddr;
    anAddr.sin_family = AF_INET;
    anAddr.sin_port = htons(80);
    anAddr.sin_addr.s_addr = inet_addr("127.0.0.1");   //localhost

    cout<<"Connecting to server..."<<endl;
    Sleep(500);  //wmall delay so server can start first

    if (connect(s1, (struct sockaddr*)&anAddr, sizeof(anAddr)) == SOCKET_ERROR) {
        cout<<"Connect failed. Error: "<<WSAGetLastError()<<endl;
        closesocket(s1);
        WSACleanup();
        return 1;
    }
    cout<<"Connected to server!"<<endl;

    //communication loop
    while (true) {
        char str[100] = {0};
        cout<<"input str: "<<endl;
        cin.getline(str, 100);

        if (strlen(str) == 0) continue;
        send(s1, str, strlen(str), 0);

        //special command to exit
        if (strcmp(str, "Bye") == 0 || strcmp(str, "bye") == 0) {
            cout<<"Closing connection..."<<endl;
            break;
        }

        char buf[100] = {0};
        recv(s1, buf, sizeof(buf) - 1, 0);
        cout<<"Server: "<<buf<<endl;
    }
    closesocket(s1);
    WSACleanup();

    cout<<"Client stopped."<<endl;
    return 0;
}