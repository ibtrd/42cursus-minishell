# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 22:03:24 by ibertran          #+#    #+#              #
#    Updated: 2024/02/15 01:03:29 by ibertran         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = minishell

# *** FILES ****************************************************************** #

BUILD_DIR := .build/

SRCS_DIR = srcs/
SRC = \
	main

SRCS = $(addsuffix .c, $(SRC))

OBJS = $(patsubst %.c,$(BUILD_DIR)%.o,$(SRCS))

DEPS = $(patsubst %.o,%.d,$(OBJS))
-include $(DEPS)

# *** LIBRARIES && INCLUDES  ************************************************* #

LIBS_PATH = \
	# libft/libft.a \
		
LIBS = \
	$(patsubst lib%.a,%,$(notdir $(LIBS_PATH))) \

INCS_DIR = incs/

INCS = \
	$(INCS_DIR) \
	$(dir $(LIBS_PATH))$(INCS_DIR) \

# *** CONFIG ***************************************************************** #

CFLAGS		=	-Wall -Wextra -Werror $(OFLAGS)
OFLAGS 		=	-O3

CPPFLAGS 	= 	$(addprefix -I, $(INCLUDES)) \
				$(addprefix -D, $(DEFINES)) \
				-MMD -MP \

LDFLAGS		=	$(addprefix -L, $(dir $(LIBS_PATH)))
LDLIBS		=	$(addprefix -l, $(LIBS))

MAKEFLAGS	=	--no-print-directory

# *** COMPILATION MODES ****************************************************** #

MODE_TRACE = .trace 
LAST_MODE = $(shell cat $(MODE_TRACE) 2>/dev/null)

MODE ?=

ifneq ($(MODE),)
BUILD_DIR := $(BUILD_DIR)$(MODE)/
endif

ifeq ($(MODE),debug)
CFLAGS := $(filter-out $(OFLAGS),$(CFLAGS)) -g3
else ifeq ($(MODE),fsanitize)
CFLAGS := $(filter-out $(OFLAGS),$(CFLAGS)) -g3 -fsanitize=address
else ifneq ($(MODE),)
ERROR = MODE
endif

ifneq ($(LAST_MODE),$(MODE))
$(NAME) : FORCE
endif

# *** TARGETS **************************************************************** #

.PHONY : all
all : $(NAME) 

$(NAME) : $(LIBS_PATH) $(OBJS) | ERROR_CHECK
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	@echo "$(MODE)" > $(MODE_TRACE)
ifneq ($(MODE),)
	@echo "$(GREEN) $(NAME)($(MODE)) has been built! $(RESET)"
else
	@echo "$(GREEN) $(NAME) has been built! $(RESET)"
endif


$(BUILD_DIR)%.o : $(SRCS_DIR)%.c | ERROR_CHECK
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(LIBS_PATH): FORCE | ERROR_CHECK
	@$(MAKE) -C $(@D)

.PHONY : bonus
bonus : $(NAME)

.PHONY : clean
clean :
	-for f in $(dir $(LIBS_PATH)); do $(MAKE) -s -C $$f $@; done
	rm -rf $(BUILD_DIR) $(LAST_MODE_FILE)
	echo "$(YELLOW) $(NAME) building files removed! $(RESET)"

.PHONY : fclean
fclean :
	-for f in $(dir $(LIBS_PATH)); do $(MAKE) -s -C $$f $@; done
	rm -rf $(BUILD_DIR) $(LAST_MODE_FILE)
	$(RM) $(NAME) $(NAME_BONUS) $(TRACE)
	echo "$(YELLOW) $(NAME) files removed! $(RESET)"

.PHONY : re
re : fclean
	$(MAKE)

.PHONY : debug
debug :
	$(MAKE) MODE=debug

.PHONY : fsanitize
fsanitize :
	$(MAKE) MODE=fsanitize
	
# .PHONY : %debug
# %debug :
# 	$(MAKE) $(patsubst %debug,%,$@) DEBUG=1

.PHONY : norminette
norminette :
	-for f in $(dir $(LIBS_PATH)); do $(MAKE) -s -C $$f $@; done
	norminette $(HEADERS) $(SRCS_DIR) > norminette.log || true
	if [ $$(< norminette.log grep Error | wc -l) -eq 0 ]; \
		then echo "$(NAME): \e[32;49;1mOK!\e[0m"; \
		else echo "$(NAME): \e[31;49;1mKO!\e[0m" \
			&& < norminette.log grep Error; fi
	$(RM) norminette.log

.PHONY : print%
print% :
	@echo $(patsubst print%,%,$@)=
	@echo $($(patsubst print%,%,$@))
	
# *** SPECIAL TARGETS ******************************************************** #

.DEFAULT_GOAL := all

.SILENT : bonus clean fclean re debug %debug fsanitize norminette

.PHONY : FORCE
FORCE :

ERROR_CHECK :
ifeq ($(ERROR),MODE)
	$(error Invalid mode: $(MODE))
endif

# *** FANCY STUFF ************************************************************ #

RESET	=	\e[0m
RED		=	\e[31;49;1m ¯\_(ツ)_/¯ \e[39;41;1m
GREEN	=	\e[32;49;1m ¯\_(ツ)_/¯ \e[39;42;1m
YELLOW	=	\e[33;49;1m ¯\_(ツ)_/¯ \e[39;43;1m
BLUE	=	\e[34;49;1m ¯\_(ツ)_/¯ \e[39;44;1m

# **************************************************************************** #