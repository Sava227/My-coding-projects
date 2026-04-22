#include<iostream>
#include<string>
#include<cstring>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
using namespace std;

int main(){
    int s=socket(AF_INET,SOCK_STREAM,0);
    if(s<0){cout<<"Socket creation failed."<<endl;return 1;}

    sockaddr_in sin;
    sin.sin_family=AF_INET;
    sin.sin_port=htons(8080);
    sin.sin_addr.s_addr=INADDR_ANY;

    if(::bind(s,(sockaddr*)&sin,sizeof(sin))<0){
        cout<<"Bind failed."<<endl;
        close(s);
        return 1;
    }

    if(::listen(s,100)<0){
        cout<<"Listen failed."<<endl;
        close(s);
        return 1;
    }

    cout<<"Server is listening on port 80..."<<endl;

    sockaddr_in from;
    socklen_t fromlen=sizeof(from);

    int s1=::accept(s,(sockaddr*)&from,&fromlen);
    if(s1<0){
        cout<<"Accept failed."<<endl;
        close(s);
        return 1;
    }

    cout<<"Client connected!"<<endl;

    while(true){
        char str[100]={0};
        int bytes=recv(s1,str,sizeof(str)-1,0);

        if(bytes<=0){
            cout<<"Client disconnected."<<endl;
            break;
        }

        cout<<"Client:"<<str<<endl;

        if(strcmp(str,"Bye")==0||strcmp(str,"bye")==0){
            send(s1,"Connection is closed",20,0);
            break;
        }

        const char*reply="Message was received";
        send(s1,reply,strlen(reply),0);
    }

    close(s1);
    close(s);

    cout<<"Server stopped."<<endl;
    return 0;
}