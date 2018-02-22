#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <time.h>



struct xx
{
        int xx_offset;
	time_t xx_time;      
}


int main()
{
	struct xx *pxx;
	struct xx y;
	int fd;

	pxx = (struct xx *)malloc(sizeof(struct xx));;
	pxx->xx_offset = 500;
	pxx->xx_time = time(NULL);
	
	fd = open ("myfile", O_RDWR, 660);
	
	lseek(fd, 1024, SEEK_SET);

	write(fd, (void *)pxx, sizeof(struct xx));

	lseek(fd, 1024, SEEK_SET);

	read(fd, (void *)&y, sizeof(struct xx));

	printf("offset-%d; seconds(1970.1.1)-%ld\n", y.xx_offset, y.xx_time);

	return 0;		
}
