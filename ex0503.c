#include <sys/types.h>
#include <dirent.h>
struct dirent
{
	long d_ino;
	char d_name[100 +1];
}
int main(){
	DIR *dirp;
	struct dirent *dentry;
	if(dirp=opendir(".))) == NULL) {
		fprintf(stderr, "error\n");
		exit(1);
	}

	while(dentry = readdir(dirp)) {
		if(dentry -> d_ino!=0)
			printf("%s\n", dentry -> d_name);
	}
	closedir(dirp);
}
