#define MKFS_H

#define SB_OFFSET 512
#define INODE_OFFSET 4096
#define DATA_OFFSET 10485760
#define MAX_INODE 100
#define MAX_DATA_BLK 25600
#define MAX_OPEN_FILES 10
#define BLOCK_SIZE 4096
#define MAX_NESTING_DIR 10
#define MAX_COMMAND_LENGTH 50
#define DIR_TYPE 0
#define FILE_TYPE 1

int fd[MAX_OPEN_FILES];
int cwd_inode;
int cwd_name[100];

struct superblock
{
	int magic_number;
	int inode_offset;
	int data_offset;
	int sb_offset;
	int max_inode;
	int max_data_blk;
	int next_available_inode;
	int next_available_blk;
	int blk_size;
};

struct inode
{
	int i_number;
	int i_type;
	int i_size;
	int i_name;
	int i_blocks;
	int direct_blk[2];
	int indirect_blk; 
	int file_num;

};

struct indirect_block
{
	int blocks[256];
};

struct dirEntry
{
	int i_number;
	int type;
	int length;
	char name[20]
};

struct dir
{
	struct dirEntry dentry[32];
};


extern int open_t (const char*pathname, int flags);
extern int read_t (int inode_number, int offset, void*buf, int count);
extern int write_t (int inode_number, int offset, void*buf, int count);

extern void mkfs_t (const char*pathname);
extern int mkdir_t (const char*pathname);
extern int cd_t (const char*pathname);
extern int ls_t ();
extern int cp_t ();
extern int external_cp ();
extern int cat_t ();

extern int dev_open (const char * pathname);
extern int read_block(int block_num, void * block);
extern int write_block(int block_num, void * block);
extern int read_inode(int inode_num, void * inode);
extern int write_inode(int inode_num, void * inode);
extern struct inode *find(const char *pathname);
