#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

int main() {
  struct addrinfo hints, *servinfo;
  struct sockaddr_storage client_addr;

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  int status = getaddrinfo("127.0.0.1", "8000", &hints, &servinfo);

  if (status == -1) {
    fprintf(stderr, "address error\n");
    return 1;
  }
  int socket_fd = socket(servinfo->ai_family, servinfo->ai_socktype, 0);

  if (socket_fd == -1) {
    fprintf(stderr, "socket error\n");
    return 1;
  }

  if (bind(socket_fd, servinfo->ai_addr, servinfo->ai_addrlen) == -1) {
    fprintf(stderr, "bind error\n");
    return 1;
  }

  if (listen(socket_fd, 20) == -1) {
    fprintf(stderr, "listen error\n");
    return 1;
  }
  printf("Server listening on port 8000\n");

  char *msg = "Beej made this possible!";
  int msg_len = strlen(msg);

  while (1) {
    socklen_t client_addr_len = sizeof client_addr;
    int accept_fd =
        accept(socket_fd, (struct sockaddr *)&client_addr, &client_addr_len);

    if (accept_fd == -1) {
      fprintf(stderr, "connection error\n");
      return 1;
    }
    printf("Connection established \n");

    send(accept_fd, msg, msg_len, 0);
  }
  freeaddrinfo(servinfo);

  return 0;
}
