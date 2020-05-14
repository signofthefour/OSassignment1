#include <get_proc_info.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

int main() {
	pid_t pid = getpid();
	printf("PID: %d\n", pid);
	struct procinfos info;
	if (get_proc_info(pid, &info) == 0) {
		printf("studentID: %ld\n", info.studentID);
		printf("proc.pid: %d\n", info.proc.pid);
		printf("proc.name: %s\n", info.proc.name);
		printf("parent_proc.pid: %d\n", info.parent_proc.pid);
		printf("parent_proc.name: %s\n", info.parent_proc.name);
		printf("oldest_child_proc.pid: %d\n", info.oldest_child_proc.pid);
		printf("oldest_child_proc.name: %s\n", info.oldest_child_proc.name);
	}
	else {
		printf("Cannot get infomation of process %d\n", pid);
	}
	return 0;
}
