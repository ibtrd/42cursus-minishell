# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 22:03:24 by ibertran          #+#    #+#              #
#    Updated: 2024/04/05 18:10:43 by kchillon         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = minishell

# *** FILES ****************************************************************** #

MAKE_DIR := .make/
BUILD_DIR := $(MAKE_DIR)$(shell git branch --show-current)/

SRCS_DIR = srcs/
SRCS = $(addsuffix .c, $(SRC))

OBJS = $(patsubst %.c,$(BUILD_DIR)%.o,$(SRCS))

DEPS = $(patsubst %.o,%.d,$(OBJS))

SRC = \
	get_input \
	main \
	search_path \
	create_here_documents \
	minishell_history \
	$(addprefix $(DEBUG_DIR),$(DEBUG_SRC)) ##REMOVE DEBUG

# ********** PARSING ********** #

SRC += $(addprefix $(PARSING_DIR),$(PARSING_SRC))

PARSING_DIR = parsing/
PARSING_SRC = \
	escape_utils \
	check_unclosed_input \
	commandline_parser \

#		# ***** LEXER ***** #

SRC += $(addprefix $(LEXER_DIR),$(LEXER_SRC))

LEXER_DIR = $(PARSING_DIR)lexer/
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

EXPANDER_DIR = $(PARSING_DIR)expander/
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
	special_parameter_utils \
	filename_expansion_utils \
	is_match \

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

BUILDER_DIR = $(AST_DIR)builder/
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
	exec_builtins \
	exec_cleanup \
	executor \
	node_exec \
	retrieve_status \

#		# ******* BRANCH ******* #

SRC += $(addprefix $(BRANCH_DIR),$(BRANCH_SRC))       

BRANCH_DIR = $(EXECUTION_DIR)branch/
BRANCH_SRC = \
		branch_command \
		branch_logicaloperator \
		branch_pipe \
		branch_redirection \

#		# ******** OPEN ******** #

SRC += $(addprefix $(OPEN_DIR),$(OPEN_SRC))

OPEN_DIR = $(EXECUTION_DIR)open/
OPEN_SRC = \
		open_append \
		open_heredoc \
		open_input \
		open_output \

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
	history \

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

#		# ******* BRANCH ******* #

SRC += $(addprefix $(INIT_VAR_DIR),$(INIT_VAR_SRC))       

INIT_VAR_DIR = $(ENV_DIR)init_var/
INIT_VAR_SRC = \
		init_path \
		init_shlvl \

# **************** PROMPT **************** #

SRC += $(addprefix $(PROMPT_DIR),$(PROMPT_SRC))

PROMPT_DIR = prompt/
PROMPT_SRC = \
	add_git \
	get_prompt \

# **************** SIGNAL **************** #

SRC += $(addprefix $(SIGNAL_DIR),$(SIGNAL_SRC))

SIGNAL_DIR = signals/
SIGNAL_SRC = \
	child_int_handler \
	child_quit_handler \
	ft_rl_event \
	input_int_handler \
	main_int_handler \
	signal_ign_main \
	signal_setup_child \
	signal_setup_input \
	signal_setup_main \

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


$(NAME) : $(LIBS_PATH) $(OBJS) | PREMAKE
	@echo "$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)" >> $(LOGFILE)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	@echo "$(MODE)" > $(MODE_TRACE)
ifneq ($(MODE),)
	@printf "\n$(BOLD)$(GREEN)$(NAME)($(MODE)) compiled!$(RESET)\n"
else
	@printf "\n$(BOLD)$(GREEN)$(NAME) compiled!$(RESET)\n"
endif
	@printf "$(BOLD)\
     88     888b     d888 d8b          d8b          888               888 888\n\
 .d88888b.  8888b   d8888 Y8P          Y8P          888               888 888\n\
d88P 88\"88b 88888b.d88888                           888               888 888\n\
Y88b.88     888Y88888P888 888 88888b.  888 .d8888b  88888b.   .d88b.  888 888\n\
 \"Y88888b.  888 Y888P 888 888 888 \"88b 888 88K      888 \"88b d8P  Y8b 888 888\n\
     88\"88b 888  Y8P  888 888 888  888 888 \"Y8888b. 888  888 88888888 888 888\n\
Y88b 88.88P 888   \"   888 888 888  888 888      X88 888  888 Y8b.     888 888\n\
 \"Y88888P\"  888       888 888 888  888 888  88888P' 888  888  \"Y8888  888 888\n\
     88                                                   $(RESET)@kchillon @ibertran\n"

$(BUILD_DIR)%.o : $(SRCS_DIR)%.c | count PREMAKE
	@true || echo "$(NAME)_object"
	$(eval COUNT_DONE := $(shell echo $$(($(COUNT_DONE) + 1))))
	$(eval LOADING_COMPLETED := $(shell echo "$(COUNT_DONE) * $(LOADING_BAR_SIZE) / $(COUNT_TOTAL)" | bc 2> /dev/null))
	@mkdir -p $(@D)
	@echo "$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@" >> $(LOGFILE)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@printf "$(ERASE)$(BOLD)$(CC) $(BLUE)$(CFLAGS) $(YELLOW)$(patsubst $(MAKE_DIR)%, %, $(basename $@)) $(RESET)\n"
	@printf "🔧 $(BOLD)$(CYAN)Compiling sources: $(WHITE)["
	@for i in $(shell seq 1 $(LOADING_COMPLETED)); do printf "="; done 
	@for i in $(shell seq 1 $(shell echo "$(LOADING_BAR_SIZE) - $(LOADING_COMPLETED)" | bc 2> /dev/null)); do printf " "; done
	@printf "] $(shell echo "$(COUNT_DONE) * 100 / $(COUNT_TOTAL)" | bc 2> /dev/null)%%$(RESET)"

$(LIBS_PATH): FORCE | PREMAKE
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
	@printf "$(BOLD)(╯°□°)╯︵ ┻━┻ $(NAME) building files removed!$(RESET)\n"

.PHONY : fclean
fclean :
	-for f in $(dir $(LIBS_PATH)); do $(MAKE) -s -C $$f $@; done
	rm -rf $(MAKE_DIR) $(NAME)
	@printf "$(BOLD)(╯°□°)╯︵ ┻━┻ $(NAME) files removed!$(RESET)\n"

.PHONY : re
re : fclean
	$(MAKE)

NORM_LOG = $(MAKE_DIR)norminette.log

.PHONY : norminette
norminette :
	-for f in $(dir $(LIBS_PATH)); do $(MAKE) -s -C $$f $@; done
	mkdir -p $(dir $(NORM_LOG))
	norminette $(INCS_DIR) $(SRCS_DIR) > $(NORM_LOG) || true
	if [ $$(< $(NORM_LOG) grep Error | wc -l) -eq 0 ]; \
		then echo "$(NAME): \e[32;49;1mOK!\e[0m"; \
		else echo "$(NAME): \e[31;49;1mKO!\e[0m" \
			&& < $(NORM_LOG) grep Error; fi
	$(RM) $(NORM_LOG)

.PHONY : print%
print% :
	echo $(patsubst print%,%,$@)=
	echo $($(patsubst print%,%,$@))

.PHONY : count
count :
ifneq ($(AS_COUNTED),TRUE)
	$(eval COUNT_TOTAL := $(shell $(MAKE) -j -n MODE=$(MODE) AS_COUNTED=TRUE | grep "$(NAME)_object" | wc -l))
	$(eval COUNT_DONE := 0)
endif

.PHONY : run
run : $(NAME)
	./$(NAME)

VALGRIND = \
	valgrind \
	--suppressions=.valgrindignore.txt \
	--leak-check=full \
	--trace-children=yes \
	--track-fds=yes \
	--show-leak-kinds=all \

.PHONY : valgrind
valgrind : debug
	$(VALGRIND) ./$(NAME)

# *** SPECIAL TARGETS ******************************************************** #

-include $(DEPS)

.DEFAULT_GOAL := all

.SILENT : bonus clean fclean re debug %debug fsanitize norminette

.PHONY : FORCE
FORCE :

.PHONY : PREMAKE
PREMAKE :
ifneq ($(MODE),)
	@printf "🔨 $(BOLD)Building $(NAME)($(MODE))...$(RESET)\n"
else
	@printf "🔨 $(BOLD)Building $(NAME)...$(RESET)\n"
endif
	@rm -f $(LOGFILE)
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
C12	=	\033[39m
C13	=	\033[43m

# **************************************************************************** #
