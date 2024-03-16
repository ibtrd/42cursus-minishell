# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 22:03:24 by ibertran          #+#    #+#              #
#    Updated: 2024/03/15 23:58:52 by ibertran         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = minishell

# *** FILES ****************************************************************** #

BUILD_DIR := .build/$(shell git branch --show-current)/

SRCS_DIR = srcs/
SRCS = $(addsuffix .c, $(SRC))

OBJS = $(patsubst %.c,$(BUILD_DIR)%.o,$(SRCS))

DEPS = $(patsubst %.o,%.d,$(OBJS))
-include $(DEPS)

SRC = \
	main \
	$(addprefix $(DEBUG_DIR),$(DEBUG_SRC)) ##REMOVE DEBUG

# ********** PARSING ********** #

SRC += $(addprefix $(PARSING_DIR),$(PARSING_SRC))

PARSING_DIR = parsing/
PARSING_SRC = \
	escape_utils \
	syntax_checker \
	commandline_parser \

#		# ***** LEXER ***** #

SRC += $(addprefix $(LEXER_DIR),$(LEXER_SRC))

LEXER_DIR = $(PARSING_DIR)/lexer/
LEXER_SRC = \
		cmdline_addspace \
		cmdline_tokenizer \
		lexer_build \
		lexer_close_bracket \
		lexer_error \
		lexer_launch \
		lexer_next_tok \
		lexer_open_bracket \
		lexer_operator_tok \
		lexer_rediction_tok \
		lexer_set_args \

#		# ********** EXPANDER ********** #

SRC += $(addprefix $(EXPANDER_DIR),$(EXPANDER_SRC))

EXPANDER_DIR = $(PARSING_DIR)/expander/
EXPANDER_SRC = \
	00_expander_launch \
	01_tilde_expansion \
	02_envars_expansion \
	03_word_splitting \
	04_filename_expansion \
	05_quote_removal \
	args_vectors_to_strings \
	expander_mask_utils \
	expander_utils \
	filename_expansion_utils \

# ********** AST ********** #

SRC += $(addprefix $(AST_DIR),$(AST_SRC))

AST_DIR = ast/
AST_SRC = \
	ast_utils \
	ast_print \
	ast_addnode \
	ast_addnode_utils \

#		# ***** BUILDER ***** #

SRC += $(addprefix $(BUILDER_DIR),$(BUILDER_SRC))

BUILDER_DIR = $(AST_DIR)/builder/
BUILDER_SRC = \
		ast_build \
		ast_build_command \
		ast_build_operator \
		ast_build_redirection \
		ast_build_brackets \
		ast_build_error \
		ast_build_argument \

# ********** EXECUTION ********** #

SRC += $(addprefix $(EXECUTION_DIR),$(EXECUTION_SRC))

EXECUTION_DIR = exec/
EXECUTION_SRC = \
	close_fds \
	exec_builtins \
	exec_cleanup \
	exec_utils \
	executor \
	node_exec \

#		# ******* BRANCH ******* #

SRC += $(addprefix $(BRANCH_DIR),$(BRANCH_SRC))       

BRANCH_DIR = $(EXECUTION_DIR)/branch/
BRANCH_SRC = \
		branch_command \
		branch_logicaloperator \
		branch_pipe \
		branch_redirection \

#		# ******** OPEN ******** #

SRC += $(addprefix $(OPEN_DIR),$(OPEN_SRC))

OPEN_DIR = $(EXECUTION_DIR)/open/
OPEN_SRC = \
		open_input \
		open_output \
		open_append \

# ********** BUILTINS ********** #

SRC += $(addprefix $(BUILTIN_DIR),$(BUILTIN_SRC))

BUILTIN_DIR = builtins/
BUILTIN_SRC = \
	cd \
	check_option \
	env \
	echo \
	exit \
	export \
	pwd \
	unset \

# **************** ENVIRONMENT **************** #

SRC += $(addprefix $(ENV_DIR),$(ENV_SRC))

ENV_DIR = env/
ENV_SRC = \
	add_var \
	copy_var \
	del_var \
	free_var \
	ft_getenv \
	init_env \
	search_var \
	overwrite_var \
	update_var \
	var_processing \

################################################################################

DEBUG_DIR = debug/
DEBUG_SRC = \
	debug_print_str_mask \

# *** LIBRARIES && INCLUDES  ************************************************* #

LIBS_PATH = \
	libft/libft.a \
		
LIBS = \
	$(patsubst lib%.a,%,$(notdir $(LIBS_PATH))) \
	readline

INCS_DIR = incs/
INCS = \
	$(INCS_DIR) \
	$(dir $(LIBS_PATH))$(INCS_DIR) \

# *** CONFIG ***************************************************************** #

CFLAGS		=	-Wall -Wextra -Werror $(OFLAGS)
OFLAGS 		=

CPPFLAGS 	= 	$(addprefix -I, $(INCS)) \
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

# *** TESTING **************************************************************** #

ifdef TEST
BUILD_DIR := $(BUILD_DIR)test/
NAME = minishell_test
CFLAGS := $(filter-out $(OFLAGS),$(CFLAGS)) -g3
SRC := tests/main_$(TEST) $(filter-out main, $(SRC))
endif

# *** TARGETS **************************************************************** #

.PHONY : all
all : $(NAME) 

$(NAME) : $(LIBS_PATH) $(OBJS) | ERROR_CHECK
	@printf "\n🔗 Linking $(NAME)...\n"
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	@echo "$(MODE)" > $(MODE_TRACE)
ifneq ($(MODE),)
	@echo "$(GREEN) $(NAME)($(MODE)) has been built! $(RESET)"
else
	@echo "$(GREEN) $(NAME) has been built! $(RESET)"
endif

$(BUILD_DIR)%.o : $(SRCS_DIR)%.c | ERROR_CHECK
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@printf "🔧 $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@\n"

$(LIBS_PATH): FORCE | ERROR_CHECK
	@$(MAKE) -C $(@D)

.PHONY : bonus
bonus : $(NAME)

.PHONY : debug
debug :
	$(MAKE) MODE=debug

.PHONY : fsanitize
fsanitize :
	$(MAKE) MODE=fsanitize

.PHONY : print
print :
	$(MAKE) MODE=debug DEFINES=PRINT

.PHONY : clean
clean :
	-for f in $(dir $(LIBS_PATH)); do $(MAKE) -s -C $$f $@; done
	rm -rf $(BUILD_DIR)
	echo "$(YELLOW) $(NAME) building files removed! $(RESET)"

.PHONY : fclean
fclean :
	-for f in $(dir $(LIBS_PATH)); do $(MAKE) -s -C $$f $@; done
	rm -rf $(BUILD_DIR) $(NAME) $(MODE_TRACE) $(NAME)_test
	echo "$(YELLOW) $(NAME) files removed! $(RESET)"

.PHONY : re
re : fclean
	$(MAKE)

.PHONY : norminette
norminette :
	-for f in $(dir $(LIBS_PATH)); do $(MAKE) -s -C $$f $@; done
	norminette $(INCS_DIR) $(SRCS_DIR) > norminette.log || true
	if [ $$(< norminette.log grep Error | wc -l) -eq 0 ]; \
		then echo "$(NAME): \e[32;49;1mOK!\e[0m"; \
		else echo "$(NAME): \e[31;49;1mKO!\e[0m" \
			&& < norminette.log grep Error; fi
	$(RM) norminette.log

.PHONY : print%
print% :
	@echo $(patsubst print%,%,$@)=
	@echo $($(patsubst print%,%,$@))

.PHONY : run
run :	$(NAME)
	./$(NAME)

VALGRIND = \
	valgrind \
	--suppressions=.valgrindignore.txt \
	--leak-check=full \
	--trace-children=yes \
	--track-fds=yes \

.PHONY : valgrind
valgrind : debug
	$(VALGRIND) ./$(NAME)

# *** TESTING **************************************************************** #

AVAILABLE_TESTS = \
	builtins \
	cmdline_addspace \
	env \
	executor \
	init_env \
	syntax_checker \
	lexer \
	lexerfull \
	dprintf \
	sprintf \
	vector_test \
	vector_alloc \
	vector_ian \
	tilde_expansion \

.PHONY : $(AVAILABLE_TESTS)
$(AVAILABLE_TESTS) :
	$(RM) minishell_test
	@$(MAKE) TEST=$@ MODE=debug
#	@$(VALGRIND) ./$(NAME)_test
#  ./$(NAME)_test

# *** SPECIAL TARGETS ******************************************************** #

.DEFAULT_GOAL := all

.SILENT : bonus clean fclean re debug %debug fsanitize norminette

.PHONY : FORCE
FORCE :

.PHONY : ERROR_CHECK
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
