#include <stdio.h>
#include <stdlib.h>


// http://www.unknownroad.com/rtfm/gdbtut/gdbsegfault.html
int main(int argc, char **argv) {
	char *buf;

	buf = malloc(1<<31);

	fgets(buf, 1024, stdin);
	printf("%s\n", buf);

	return 1;
}
