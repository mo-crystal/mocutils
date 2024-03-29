GCC_LIB_DIRS = $(wildcard /usr/lib/gcc/$(shell uname -m)-linux-gnu/*)

build: src/*.cc
	g++ -c src/*.cc
	ar -crv libmocutils.a *.o

install: build uninstall
	mkdir /usr/include/mocutils
	cp src/*.h /usr/include/mocutils/
	$(foreach dir, $(GCC_LIB_DIRS), cp libmocutils.a $(dir)/)
	@echo "[ok] Installation finished."

uninstall:
	-rm -rf /usr/include/mocutils
	-$(foreach dir, $(GCC_LIB_DIRS), rm $(dir)/libmocutils.a)

clean:
	rm -rf *.o
	rm -rf *.a
