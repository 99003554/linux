src = circ.c 
project = target
target: $(src)
	gcc $^ -lpthread -o $@
run: $(project)
	./$^
clean:
	rm *.out