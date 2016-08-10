CFLAGS = -g -O3 -ansi -pedantic -Wall -Wextra -Wno-unused-parameter -undefined dynamic_lookup -dynamiclib

ERLANG_PATH = $(shell erl -eval 'io:format("~s", [lists:concat([code:root_dir(), "/erts-", erlang:system_info(version), "/include"])])' -s init stop -noshell)
CFLAGS += -I$(ERLANG_PATH)
CFLAGS += -Isrc


.PHONY: all clean

all: priv/hello.so

priv/hello.so: src/hello.c
	$(CC) $(CFLAGS) -shared $(LDFLAGS) -o $@ src/hello.c

clean:
	$(RM) -r priv/hello.so*
