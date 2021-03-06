src = shm_write.c shm_read.c
project = target
target: $(src)
	gcc $^ -o -lpthread -lrt $@
run: $(project)
	./$^
clean:
	rm *.out