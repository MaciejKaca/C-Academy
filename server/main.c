/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <string.h>
int listen_sock, conn_sock, portno, clilen;
char buffer[256];
struct sockaddr_in serv_addr, cli_addr;
int n;

void error(char *msg)
{
    perror(msg);
    exit(1);
}

void connect_()
{
    listen(listen_sock,5);
    clilen = sizeof(cli_addr);
}

void setUp(int port)
{
    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0)
       error("ERROR opening socket");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = port;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(listen_sock, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0)
             error("ERROR on binding");
}

void setnonblocking(int sock)
{
    int opts;
    opts = fcntl(sock, F_GETFL);

    if(opts < 0) {
        perror("fcntl(sock, GETFL)");
        exit(1);
    }

    opts = opts | O_NONBLOCK;

    if(fcntl(sock, F_SETFL, opts) < 0) {
        perror("fcntl(sock, SETFL, opts)");
        exit(1);
    }
}

void get_message(int sock, int epollfd, struct epoll_event ev)
{
       int n;
       char buffer[256];

       bzero(buffer,256);
       n = read(sock, buffer,250);

       if( strstr(buffer, "quit") )
       {
           printf("Connection closed with user: %d\n ", sock);
           epoll_ctl(epollfd, EPOLL_CTL_DEL, sock, &ev);
       }
       else
       {
           if(n < 0)
               error("ERROR reading from socket!");
           printf("From: %d\n", sock);
           printf("Message: %s\n\n", buffer);
       }
}

void do_stuff()
{
    #define MAX_EVENTS 10
    struct epoll_event ev, events[MAX_EVENTS];
    int nfds, epollfd;

    epollfd = epoll_create1(0);
    if (epollfd == -1)
    {
        perror("epoll_create1");
        exit(EXIT_FAILURE);
    }

    ev.events = EPOLLIN;
    ev.data.fd = listen_sock;
    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, listen_sock, &ev) == -1)
    {
        perror("epoll_ctl: listen_sock");
        exit(EXIT_FAILURE);
    }

    while(1) {
        nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        if (nfds == -1)
        {
            perror("epoll_wait");
            exit(EXIT_FAILURE);
        }

        for (n = 0; n < nfds; ++n)
        {
            if (events[n].data.fd == listen_sock)
            {
                conn_sock = accept(listen_sock,
                (struct sockaddr *) &cli_addr, &clilen);
                 if (conn_sock == -1)
                 {
                    perror("accept");
                    exit(EXIT_FAILURE);
                 }
                 setnonblocking(conn_sock);
                 ev.events = EPOLLIN | EPOLLET;
                 ev.data.fd = conn_sock;
                 if (epoll_ctl(epollfd, EPOLL_CTL_ADD, conn_sock, &ev) == -1)
                 {
                          perror("epoll_ctl: conn_sock");
                          exit(EXIT_FAILURE);
                 }
            } else
                get_message(events[n].data.fd, epollfd, ev);
        }
    }
}

int main(int argc, char *argv[])
{

    setUp(atoi(argv[1]));
    connect_();
    do_stuff();

    close(listen_sock);
    return 0;
}
