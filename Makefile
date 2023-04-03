#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

NAME	=	push_swap
LIBFT	= 	libft.a
LDIR	=	libft/

# Color
GREEN	=	\033[0;32m
RED		=	\033[0;31m
BLUE	=	\033[0;34m
WHITE	=	\033[0m

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f

# Sources are all .c files
SRCS	=	push.c\
			push_swap.c\
			reverse.c\
			rotate.c\
			swap.c\
			list.c\
			sort.c\
			bucket.c\
			verif.c\
			random.c\
			min_max.c\
			exit.c\

OBJS	=	$(SRCS:.c=.o)

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(NAME)

# Generates output file
$(NAME): $(OBJS)
	@echo "$(GREEN)Compiling . . .$(WHITE)\n"
	@ $(MAKE) -C $(LDIR)
	@ $(CC) $(CFLAGS) $(SRCS) $(LDIR)$(LIBFT) -o $(NAME)

$(OBJS): $(SRCS)
	@$(CC) $(CFLAGS) -c $(SRCS)
	@echo "$(BLUE)Create objects$(WHITE)"

# Removes objects
clean:
	@$(RM) $(OBJS)
	@$(RM) $(LDIR)*.o
	@echo "$(RED)Removes objects$(WHITE)"

# Removes objects and executables
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LDIR)$(LIBFT)
	@echo "$(RED)Removes executables$(WHITE)"

visuinstall:
	git clone https://github.com/o-reo/push_swap_visualizer.git && cd push_swap_visualizer && mkdir build && cd build && cmake .. && make

visu:
	./push_swap_visualizer/build/bin/visualizer

# Removes objects and executables and remakes
re: fclean all
