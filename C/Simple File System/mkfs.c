#include "mkfs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mkfs_t (const char * path)
{
	struct superblock *sb = (struct superblock *) calloc(BLOCK_SIZE, 1);
	struct inode *root = (struct inode *) malloc(sizeof(struct inode));
	struct dir *root_block = (struct dir *) malloc(sizeof(struct dir));
	int i;
		
	sb->magic_number = 2012;
	sb->sb_offset = 512;
	sb->data_offset = 10485760;
	sb->inode_offset = 4096;
	sb->max_inode = 99;
	sb->max_data_blk = 25599;
	write_block(0, sb);

	for(i = 0; i < MAX_OPEN_FILES; i++)
		fd[i] = -1;
		
	root->i_type = DIR_TYPE;
	root->i_number = 1;
	root->i_size = 1;
	strcpy(root->i_name, "/");
	root->direct_blk[0] = DATA_OFFSET; 
	write_inode(1, root);
	for(i = 0; i < 2; i++)
		root->direct_blk[i] = -1;
	root->indirect_blk = 1;
	write_inode(1, root);

	root_block->dentry[0].i_number = 1;
	root_block->dentry[0].type=DIR_TYPE;
	root_block->dentry[0].length= 32;
	strcpy(root_block->dentry[0].name, ".");
	
	root_block->dentry[1].i_number = 1;
        root_block->dentry[1].type=DIR_TYPE;
        root_block->dentry[1].length = 32;
        strcpy(root_block->dentry[1].name, "..");	

	write_block(DATA_OFFSET, root_block);

	free(sb);
	free(root);
	free(root_block);
}

struct inode *find(const char *path)
{
	struct inode *root = (struct inode *) malloc(sizeof(struct inode));
	struct inode *tmp = root;
	struct dir *direc = (struct dir *) malloc(sizeof(struct dir));
	int i = 0, j = 0, k = 0, abs = 0, d = 0, count = 0;

	char arg[MAX_NESTING_DIR][MAX_COMMAND_LENGTH];

	if(!strcmp(path, "/"))
	{
		read_inode(1, root);
		return root;
	}

	if(path[0] == '/')
	{
		i = 1;
		abs = 1;
	}

	if (path[strlen(path) -1] == '/')
		d = 1;

	while (path[i] != '\0')
	{
		if (j == MAX_NESTING_DIR)
		{
			printf("Max reached, error!");
			return NULL;
		}
		if (path[i] != '/')
		{
			arg[j][k] = path [i];
			i++;
			k++;
		}
		else
		{
			arg[j][k] = '\0';
			i++;
			j++;
			k=0;
		}
	}
	 
	if (d == 1) count = j -1;
	else count = j;
	
	if(abs == 1)
		read_inode(1, tmp);			

	for (i = 0; i <= count; i++)
		{
		int flag = 0;
		for (j=0; j < 10; j++)
			if(tmp->direct_blk[j], direc);
			read_block(tmp->direct_blk[j], direc);
			for (k = 0; k < 32; k++)
			{
				if (direc->dentry[k].i_number == 0)
					continue;
				if (d == 1 && direc->dentry[k].type == FILE_TYPE)
					continue;
				if (d == 0 && direc->dentry[k].type == DIR_TYPE)
					continue;
				if (!strcmp(direc->dentry[k].name, arg[i]))
				{
					read_inode(direc->dentry[k].i_number, tmp);
					flag = 1;
					break;
				}
			}
			if (k < 32) break;
		
		if (!flag)
		{
			printf("%s not found\n", path);
 			return NULL;
		}
	}
	
	return tmp;
}
