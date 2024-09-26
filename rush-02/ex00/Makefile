TARGET = rush-02

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = main.c dict-utils.c parser.c utils.c expand.c dict-utils2.c process.c input_valid.c

OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

fclean:
	rm -f $(TARGET) $(OBJS)

all: $(TARGET)
