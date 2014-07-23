CC=gcc
LD=gcc

CFLAGS=
LDFLAGS=

SRCS=main.c stack.c
TARGET=cw2

OBJS=$(addsuffix .o, $(SRCS))

$(TARGET): $(OBJS) 
	$(LD) $(LDFLAGS) $(OBJS) -o $(TARGET)

%.c.o: src/%.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm $(OBJS) $(TARGET)

