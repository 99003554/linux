src = fifo.c fifo1.c fifo2.c 
project = target
target: $(src)
	gcc $^ -o $@
run: $(project)
	./$^
clean:
	rm *.out