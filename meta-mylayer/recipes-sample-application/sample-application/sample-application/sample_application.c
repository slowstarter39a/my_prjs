#include <stdio.h>
#include <assert.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <poll.h>
#include <unistd.h>

int main(void)
{
	printf("This is a sample application!\n");

	char kernel_val[20];
	int fd,ret,n;
	struct pollfd pfd;

	fd = open("/dev/scull0", O_RDWR | O_NONBLOCK);

	if (fd == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	pfd.fd = fd;
	pfd.events = (POLLIN | POLLRDNORM | POLLOUT | POLLWRNORM);

	while(1) {
		printf("String poll...\n");

		ret = poll(&pfd, (unsigned long)1, -1);

		if (ret < 0) {
			perror("poll");
			assert(0);
		}

		if ((pfd.revents & POLLIN) == POLLIN) {
			read (pfd.fd, &kernel_val, sizeof(kernel_val));
			printf("POLLIN : Kernel_val = %s\n", kernel_val);
		}

		if ((pfd.revents & POLLOUT) == POLLOUT) {
			strcpy(kernel_val, "user space");
			write(pfd.fd, &kernel_val, strlen(kernel_val));
			printf("POLLOUT : Kernel_val = %s\n", kernel_val);
		}
	}

	return 0;
}

