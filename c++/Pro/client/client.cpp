#include<iostream>
#include<string>
#include<cstring>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
using namespace std;

int main(){
    int s1=socket(AF_INET,SOCK_STREAM,0);
    if(s1<0){cout<<"Socket creation failed."<<endl;return 1;}

    sockaddr_in anAddr;
    anAddr.sin_family=AF_INET;
    anAddr.sin_port=htons(80);
    inet_pton(AF_INET,"127.0.0.1",&anAddr.sin_addr);

    cout<<"Connecting to server..."<<endl;
    usleep(500*1000);

    if(connect(s1,(sockaddr*)&anAddr,sizeof(anAddr))<0){
        cout<<"Connect failed."<<endl;
        close(s1);
        return 1;
    }

    cout<<"Connected to server!"<<endl;

    while(true){
        char str[100]={0};
        cout<<"input str:"<<endl;
        cin.getline(str,100);

        if(strlen(str)==0)continue;
        send(s1,str,strlen(str),0);

        if(strcmp(str,"Bye")==0||strcmp(str,"bye")==0){
            cout<<"Closing connection..."<<endl;
            break;
        }

        char buf[100]={0};
        recv(s1,buf,sizeof(buf)-1,0);
        cout<<"Server:"<<buf<<endl;
    }

    close(s1);
    cout<<"Client stopped."<<endl;
    return 0;
}