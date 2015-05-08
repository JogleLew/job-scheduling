job: job.c job.h error.c enq deq stat Demo
	gcc -o job -g job.c job.h error.c
enq: enq.c job.h error.c
	gcc -o enq -g enq.c job.h error.c
deq: deq.c job.h error.c
	gcc -o deq -g deq.c job.h error.c
stat: stat.c job.h error.c
	gcc -o stat -g stat.c job.h error.c
Demo: Demo.c
	gcc -o Demo -g Demo.c
clean:
	rm job enq deq stat Demo
	rm -R Demo.dSYM deq.dSYM enq.dSYM job.dSYM stat.dSYM 
