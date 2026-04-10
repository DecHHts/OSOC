#--------------VERIABLES-------------
CFLAGS	= -Wall -g
TARGETS	= ex1 ex3

#--------------DECLARATION----------
.PHONY:	all clean

#--------------TARGETS--------------
all: $(TARGETS)


%: %.c
	cc $(CFLAGS) $< -o $@

#--------------CLEAN----------------
clean:
	rm -rf $(TARGETS) *.dSYM
