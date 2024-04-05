# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 11:21:32 by ibertran          #+#    #+#              #
#    Updated: 2024/04/05 11:35:51 by kchillon         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# *** FILES  ***************************************************************** #

include libft_srcs.mk

MAKE_DIR = .make/
BUILD_DIR := $(MAKE_DIR)$(shell git branch --show-current)/

OBJS = $(patsubst $(SRCS_DIR)%.c,$(BUILD_DIR)%.o,$(SRCS))

DEPS = $(patsubst %.o,%.d,$(OBJS))

INCS_DIR = incs/

# *** CONFIG ***************************************************************** #

CFLAGS		=	-Wall -Wextra -Werror $(OFLAGS)
OFLAGS 		=	

CPPFLAGS	= 	$(addprefix -I, $(INCS_DIR)) \
				-MMD -MP \

ARFLAGS 	=	rcs

MAKEFLAGS	=	--no-print-directory

# *** COMPILATION MODES ****************************************************** #

MODE_TRACE = $(MAKE_DIR).trace 
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

# *** MISC ******************************************************************* #

LOGFILE = $(MAKE_DIR).mklog

LOADING_BAR_SIZE = 35

# *** TARGETS **************************************************************** #

.PHONY : all
all : $(NAME)

$(NAME) : $(OBJS) | ERROR_CHECK
	@printf "\n📚$(BOLD)$(PURPLE) Creating $(NAME) archive...\n$(RESET)"
	@echo "$(AR) $(ARFLAGS) $(NAME) $(OBJS)" >> $(LOGFILE)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "$(MODE)" > $(MODE_TRACE)
ifneq ($(MODE),)
	@printf "$(BOLD)$(GREEN)$(NAME)($(MODE)) has been created!$(RESET)\n"
else
	@printf "$(BOLD)$(GREEN)$(NAME) has been created!$(RESET)\n"
endif

$(BUILD_DIR)%.o : $(SRCS_DIR)%.c | count ERROR_CHECK
#	@true || echo "$(NAME)_object"
	$(eval COUNT_DONE := $(shell echo $$(($(COUNT_DONE) + 1))))
	$(eval LOADING_COMPLETED := $(shell echo "$(COUNT_DONE) * $(LOADING_BAR_SIZE) / $(COUNT_TOTAL)" | bc 2> /dev/null))
	@mkdir -p $(@D)
	@echo "$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@" >> $(LOGFILE)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@printf "$(ERASE)$(BOLD)$(CC) $(BLUE)$(CFLAGS) $(YELLOW)$(patsubst $(MAKE_DIR)%, %, $(basename $@))$(RESET)\n"
	@printf "🔧 $(BOLD)$(CYAN)Compiling sources: $(WHITE)["
	@for i in $(shell seq 1 $(LOADING_COMPLETED)); do printf "="; done 
	@for i in $(shell seq 1 $(shell echo "$(LOADING_BAR_SIZE) - $(LOADING_COMPLETED)" | bc 2> /dev/null)); do printf " "; done
	@printf "] $(shell echo "$(COUNT_DONE) * 100 / $(COUNT_TOTAL)" | bc 2> /dev/null)%%$(RESET)"

.PHONY : clean
clean :
	rm -rf $(BUILD_DIR)
	@printf "$(BOLD)(╯°□°)╯︵ ┻━┻ $(NAME) building files removed!$(RESET)\n"

.PHONY : fclean
fclean :
	rm -rf $(MAKE_DIR) $(NAME)
	@printf "$(BOLD)(╯°□°)╯︵ ┻━┻ $(NAME) files removed!$(RESET)\n"

.PHONY : re
re : fclean
	$(MAKE)

.PHONY : debug
debug :
	$(MAKE) MODE=debug

.PHONY : fsanitize
fsanitize :
	$(MAKE) MODE=fsanitize

NORM_LOG = $(MAKE_DIR)norminette.log

.PHONY : norminette
norminette :
	mkdir -p $(dir $(NORM_LOG))
	norminette $(INCS_DIR) $(SRCS_DIR) > $(NORM_LOG) || true
	if [ $$(< $(NORM_LOG) grep Error | wc -l) -eq 0 ]; \
		then echo "$(NAME): \e[32;49;1mOK!\e[0m"; \
		else echo "$(NAME): \e[31;49;1mKO!\e[0m" \
			&& < $(NORM_LOG) grep Error; fi
	$(RM) $(NORM_LOG)

.PHONY : print%
print% :
	@echo $(patsubst print%,%,$@)=
	@echo $($(patsubst print%,%,$@))

.PHONY : count
count :
ifneq ($(AS_COUNTED),TRUE)
	$(eval COUNT_TOTAL := $(shell $(MAKE) -n AS_COUNTED=TRUE | grep "mkdir" | wc -l))
	$(eval COUNT_DONE := 0)
endif

# *** SPECIAL TARGETS ******************************************************** #

-include $(DEPS)

.DEFAULT_GOAL := all

.SILENT : clean fclean re debug %debug fsanitize norminette

.PHONY : FORCE
FORCE :

ERROR_CHECK :
# ifneq ($(AS_COUNTED),TRUE)
# 	$(eval COUNT_TOTAL := $(shell $(MAKE) -n AS_COUNTED=TRUE | grep "$(NAME)_object" | wc -l))
# 	$(eval COUNT_DONE := 0)
# endif
ifeq ($(ERROR),MODE)
	$(error Invalid mode: $(MODE))
endif

# *** FANCY STUFF ************************************************************ #

RED_SHRUG		=	\e[31;49;1m ¯\_(ツ)_/¯ \e[39;41;1m
GREEN_SHRUG		=	\e[32;49;1m ¯\_(ツ)_/¯ \e[39;42;1m
YELLOW_SHRUG	=	\e[33;49;1m ¯\_(ツ)_/¯ \e[39;43;1m
BLUE_SHRUG		=	\e[34;49;1m ¯\_(ツ)_/¯ \e[39;44;1m
RESET	=	\e[0m
ERASE	=	\033[2K\r
BOLD	=	\033[1m
UNDER	=	\033[4m
SUR		=	\033[7m
GREY	=	\033[30m
RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m
PURPLE	=	\033[35m
CYAN	=	\033[36m
WHITE	=	\033[37m

# **************************************************************************** #
