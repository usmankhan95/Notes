include <stdio.h>
include <stdlib.h>
include <string.h>
include "mkfs.h"

int open_t (const char * path)
{
	int inum;
	int ret = -1;
	struct inode *this;
	int i, j, k;
	this = find(path);
	if (this == NULL)
		return -1;

	inum = this->num;
	for (i = 0; i < MAX_OPEN_FILES; i++) {
		if (fd[i] == -1 || fd[i] == 0) {
			fd[i] = inum;
			ret = i;
			break;
		}
	}

	if (ret == -1) printf("No empty fd !\n");
	free(this);
	return ret;
}

int my_read(int fdd, void * buf, int cnt) {
	
	int i, j, k;
	int count = cnt;
	int blknum = (count - 1) / 4096 + 1;
	int indnum;
	
	struct inode this;
	struct inode *node = &this;
	struct inode *mi = (struct inode *)malloc(sizeof(struct inode));
	int len = 0;            
	int temp = 0;   
	int flag = 0;

	unsigned char tmp[4096];

	read_inode(fd[fdd], &this);        // load file's inode

	/* only need direct blocks */
	if (blknum <= 10) {
		if (count > 4096) temp = 4096;             // remain Bytes greater than 1024(block space)?
		else temp = count;
		for (i = 0; i < blknum; i ++) {
			read_block(this.blocks[i], tmp);
			memcpy(buf + len, tmp, temp);          // copy 'temp' Bytes
			length += temp;                        // file offset 'temp' Bytes
		}
		break;
	}


	/* need indirect blocks, firstly read from direct blocks */
	for (i = 0; i < 10; i++) {
		temp = 4096;

		if (flag) {
			read_block(this.blocks[i], tmp);
			memcpy(buf + len - tempp, tmp, temp);
			fp += temp;
		} else {
			if (len + temp >= tempp) {
				temp = temp - fpoff;
				if (temp > 0) {
					read_block(this.blocks[i], tmp);
					memcpy(buf, tmp + fpoff, temp);
					fp += temp;
					len += fpoff;
				}
				flag = 1;
			}
		}
		len += temp;
	}

	blknum = blknum - 10;
	indnum = blknum / 256 + 1;  /* number of indirect blocks needed */

	/* read from indirect blocks */
	for (i = 0; i < indnum; i++) {
		struct ind_block ib;
		read_block(this.ind_blocks[i], (char *) &ib);

		for (j = 0; j < 256; j++) {
			temp = 1024;
			if ((temp + len) > count)
				temp = count - len;
			
			if (flag) {
		    		read_block(ib.blocks[j], tmp);
				memcpy(buf + len - tempp, tmp, temp);
				fp += temp;
			} else {
				if (len + temp >= tempp) {
					temp = temp - fpoff;
					if (temp > 0) {
						read_block(ib.blocks[j], tmp);
						memcpy(buf, tmp + fpoff, temp);
						fp += temp;
						len += fpoff;
					}
					flag = 1;
				}
			}
			len += temp;		
			if (blknum == (j + i * 256))
				break; 
		}
	}
	return len - tempp;
}
