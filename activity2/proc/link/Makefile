src = pro2.c
src1 = new.c
project = Link
$(project): $(src) $(src1)
	gcc $< -o $@
	gcc $> -o new
run: $(project)
	./$^
