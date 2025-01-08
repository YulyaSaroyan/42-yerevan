# Variables
NAME	=	libft.a    # Name of the library (archive file)
CC	=	cc          # Compiler
CFLAGS	=	-Wall -Wextra -Werror
SRCS	=	main.c ft_bzero.c ft_isdigit.c ft_memset.c ft_strlen.c \
		ft_isalnum.c  ft_isprint.c  ft_strchr.c   ft_strrchr.c \
		ft_isalpha.c  ft_memcpy.c   ft_strlcat.c  ft_tolower.c \
		ft_isascii.c  ft_memmove.c  ft_strlcpy.c  ft_toupper.c \
		ft_strncmp.c  ft_memchr.c   ft_memcmp.c	  ft_strnstr.c \
		ft_strdup.c   ft_atoi.c     ft_calloc.c   ft_strjoin.c \
		ft_itoa.c     ft_substr.c   ft_strtrim.c  ft_split.c   \
		ft_strmapi.c  ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c
BONUS_SRCS =	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		ft_lstmap.c
OBJS	=	$(SRCS:.c=.o)            # Convert source files to object files
BONUS_OBJS = $(BONUS_SRCS:.c=.o)  # Convert bonus source files to object files
RM	=	rm -f          # Command to remove files

all: $(NAME)         # Default rule is to build the library

$(NAME): $(OBJS)     # Create the library from object files
	ar rcs $(NAME) $(OBJS)

bonus: $(NAME) $(BONUS_OBJS)  # Build the library with bonus functions
	ar rcs $(NAME) $(BONUS_OBJS)

%.o: %.c             # Rule to compile .c files to .o files
	$(CC) $(CFLAGS) -c $< -o $@

clean:               # Remove object files
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean        # Remove everything including the library
	$(RM) $(NAME)

re: fclean all       # Rebuild everything

# Prevent Makefile from relinking if nothing has changed
.PHONY: all clean fclean re bonus

