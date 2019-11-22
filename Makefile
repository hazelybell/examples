MAKEFLAGS += -r
CC = gcc
CFLAGS = --std=c99 -Wall -ftrapv -ggdb
LDFLAGS = -lm
EXES = $(patsubst %.c,%,$(wildcard *.c))
DEBUG := $(filter debug,$(MAKECMDGOALS))
ifeq ($(DEBUG), debug)
    CFLAGS += -DDEBUG
endif

SUBDIRS := $(wildcard */.)

.PHONY: all
all: $(EXES) $(SUBDIRS)

.PHONY: $(SUBDIRS)
$(SUBDIRS):
	@$(MAKE) -C $@ $(MAKECMDGOALS)

.PHONY: debug
debug: all

$(EXES): % : %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

.PHONY: clean
clean: $(SUBDIRS)
	@rm -vf $(EXES)

