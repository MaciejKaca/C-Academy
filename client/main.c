#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <pthread.h>

int sockfd, portno, n;
struct sockaddr_in serv_addr;
struct hostent *server;
char buffer[256];
pthread_t recive_message, send_message;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void error(char *msg)
{
    perror(msg);
    exit(0);
}

void recive()
{
    while(1)
    {
        bzero(buffer,256);
        read(sockfd,buffer,255);
        if (n < 0) error("ERROR reading from socket");
    }

}

void connect_( int argc ,int argv[])
{
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");
}

void send_()
{
        printf("Please enter the message: ");
        bzero(buffer,256);
        fgets(buffer,255,stdin);
        n = write(sockfd,buffer,strlen(buffer));
        if (n < 0)
             error("ERROR writing to socket");
}

int main(int argc, char *argv[])
{
    connect_(argc, argv);

    while(1)
    {
        send_();
    }
    return 0;
}
