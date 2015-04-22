job: job.c job.h error.c enq deq stat Demo
	cc -o job -g job.c job.h error.c
enq: enq.c job.h error.c
	cc -o enq -g enq.c job.h error.c
deq: deq.c job.h error.c
	cc -o deq -g deq.c job.h error.c
stat: stat.c job.h error.c
	cc -o stat -g stat.c job.h error.c
Demo: Demo.c
	cc -o Demo -g Demo.c
clean:
	rm job enq deq stat Demo
	rm -R Demo.dSYM deq.dSYM enq.dSYM job.dSYM stat.dSYM 
