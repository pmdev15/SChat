#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>

struct sockaddr_in *IPV4ADDRESS(char *ip,int port){

    struct sockaddr_in *address = malloc(sizeof(struct sockaddr_in));
    

    address->sin_port = htons(port);
    address->sin_family = AF_INET;
    inet_pton(AF_INET,ip,&address->sin_addr.s_addr);
    return address;

}

int main(int argc, char const **argv)
{
    (void)argc;
    int socketfd = socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in *address = IPV4ADDRESS("74.125.130.100",80);
    
    int result = connect(socketfd,address,sizeof(*address));
    printf("%d",result);
    if(result == 0)
        printf("connection was successfull");

    char *msg;
    msg = "GET // HTTPS/1.1\r\nHost:google.com\r\n\r\n";
    send(socketfd,msg,strlen(msg),0);

    char buffer[1024];
    recv(socketfd,buffer,1024,0);

    printf("%s",buffer);
    

    return 0;
}