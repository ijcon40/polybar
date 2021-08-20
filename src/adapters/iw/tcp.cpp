#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <strings.h>
#include <unistd.h>

#define buffer_size 4096

char * listen(char * host, unsigned short port, n) {
  /* create TCP client socket (endpoint) */
  int sd = socket(PF_INET, SOCK_STREAM, 0);

  if (sd == -1) {
    perror("socket() failed");
    exit(EXIT_FAILURE);
  }

  int vals[1 + n];
  vals[0] = n;
  struct hostent *hp = gethostbyname(host);

  if (hp == NULL) {
    fprintf(stderr, "ERROR: gethostbyname() failed\n");
    return EXIT_FAILURE;
  }

  int index=1;
  while(index<n+1){
    vals[index]= atoi(argv[3+index]);
    index+=1;
  }
  index = 0;
  uint32_t net_vals[n+1];
  while(index<n+1){
    net_vals[index]= htonl(vals[index]);
    index+=1;
  }

  struct sockaddr_in server;
  server.sin_family = AF_INET;
  memcpy((void *) &server.sin_addr, (void *) hp->h_addr, hp->h_length);
  server.sin_port = htons(port);

  if (connect(sd, (struct sockaddr *) &server, sizeof(server)) == -1) {
    return EXIT_FAILURE;
  }

  int packet = write(sd, &net_vals, (n+1)*sizeof(uint32_t));    /* or send()/recv() */

  if (packet == -1) {
    perror("write() failed");
    return EXIT_FAILURE;
  }


  char buffer[buffer_size];
  packet = read(sd, buffer, buffer_size - 1);



  if (packet == -1) {
    perror("read() failed");
    return EXIT_FAILURE;
  } else if (packet == 0) {
    return ""
  } else  /* n > 0 */
  {
    buffer[packet] = '\0';
    close(sd)
    return buffer
  }


  return buffer;
}