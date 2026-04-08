#include<winsock2.h>
#include<ws2tcpip.h>
#include<iostream>
#include<string>
#pragma comment(lib, "ws2_32.lib")
using namespace std;

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        scout<<"WSAStartup failed. Error: "<<WSAGetLastError()<<endl;
        return 1;
    }

    SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == INVALID_SOCKET) {
        cout<<"Socket creation failed. Error: "<<WSAGetLastError()<<endl;
        WSACleanup();
        return 1;
    }

    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(80);                    //change port here
    sin.sin_addr.s_addr = INADDR_ANY;            //listen on all interfaces 127.0.0.1

    if (bind(s, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR) {
        cout<<"Bind failed. Error: "<<WSAGetLastError()<<endl;
        closesocket(s);
        WSACleanup();
        return 1;
    }

    if (listen(s, 100) == SOCKET_ERROR) {
        scout<<"Listen failed. Error: "<<WSAGetLastError()<<endl;
        closesocket(s);
        WSACleanup();
        return 1;
    }

    cout< "Server is listening on port 80..."<<endl;

    sockaddr_in from;
    int fromlen = sizeof(from);
    SOCKET s1 = accept(s, (struct sockaddr*)&from, &fromlen);
    if (s1 == INVALID_SOCKET) {
        cout<<"Accept failed. Error: " <<WSAGetLastError()<<endl;
        closesocket(s);
        WSACleanup();
        return 1;
    }

    cout<<"Client connected!"<<endl;

    //main communication loop
    while (true) {
        char str[100] = {0};
        int bytes = recv(s1, str, sizeof(str) - 1, 0);
        if (bytes <= 0) {
            cout<<"Client disconnected."<<endl;
            break;
        }

        cout<<"Client: "<<str<<endl;

        //command to close connection
        if (strcmp(str, "Bye") == 0 || strcmp(str, "bye") == 0) {
            send(s1, "Connection is closed", 20, 0);
            break;
        }

        //send reply
        const char* reply = "Message was recieved";
        send(s1, reply, strlen(reply), 0);
    }

    closesocket(s1);
    closesocket(s);
    WSACleanup();

    cout<<"Server stopped."<<endl;
    return 0;
}