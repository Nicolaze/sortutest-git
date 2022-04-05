# case generate nums
NUMS := 100
SOURCE := sort
OBJECT := insertsort

CPPFLAGS := -I include
CFLAGS := -Wall -g
PY := python3
PYPATH := python

TESTDIR := test

vpath %.c src
vpath %.h include
vpath %.a lib
vpath %.py python
vpath %_test.c test


# mission pattern

# case product pattern
$(OBJECT) : % : %.py
	$(PY) $< $@.txt $(NUMS) 
	mv $@.txt $(TESTDIR)

# main functions build
main: LDFLAGS = -L lib
main: LDLIBS = -lmyio -lcunit
main: all_test.o $(SOURCE).o

# source compile
$(SOURCE).o : $(SOURCE).h mydef.h mystd.h
all_test.o : $(SOURCE).h mystd.h mydef.h

# test lib compile
LIBOBJS := mystd.o
$(LIBOBJS): CFLAGS = -Wall
$(LIBOBJS): %.o: %.h
libmyio.a: ARFLAGS = rcv
libmyio.a: $(LIBOBJS)
	$(AR) $(ARFLAGS) $@ $^
	mv $@ lib

# intermedia
.INTERMEDIATE: $(LIBOBJS)


# inital the workspace
.PHONY: inital
initial:
	mkdir doc
	mkdir include
	mkdir src
	mkdir python
	mkdir backup
	mkdir test
	mkdir lib

# clean mission
clean:
	rm lib/lib*
#	rm *_test
	rm *.o


