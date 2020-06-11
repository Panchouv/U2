
SRCDIR=example01 example02 example03 example04 example06 example07 example08 example09

default: all

all: 
	@for i in $(SRCDIR); do \
	echo "make all in $$i..."; \
	(cd $$i && make); done

clean:
	@for i in $(SRCDIR); do \
	echo "make clean in $$i..."; \
	(cd $$i && make clean); done

distclean:
	@for i in $(SRCDIR); do \
	echo "make clean && make distclean in $$i..."; \
	(cd $$i && make clean && make distclean); done


.PHONY: all clean distclean

