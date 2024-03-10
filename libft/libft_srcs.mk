# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_srcs.mk                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 06:32:49 by ibertran          #+#    #+#              #
#    Updated: 2024/03/10 17:22:08 by kchillon         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS_DIR = srcs/
SRCS = \
	$(addprefix $(SRCS_DIR)$(CHAR_DIR)ft_, $(addsuffix .c, $(CHAR_SRC))) \
	$(addprefix $(SRCS_DIR)$(STR_DIR)ft_, $(addsuffix .c, $(STR_SRC))) \
	$(addprefix $(SRCS_DIR)$(INT_DIR)ft_, $(addsuffix .c, $(INT_SRC))) \
	$(addprefix $(SRCS_DIR)$(MEM_DIR)ft_, $(addsuffix .c, $(MEM_SRC))) \
	$(addprefix $(SRCS_DIR)$(VECTOR_DIR)ft_, $(addsuffix .c, $(VECTOR_SRC))) \
	$(addprefix $(SRCS_DIR)$(LST_DIR)ft_, $(addsuffix .c, $(LST_SRC))) \
	$(addprefix $(SRCS_DIR)$(GNL_DIR), $(addsuffix .c, $(GNL_SRC))) \
	$(addprefix $(SRCS_DIR)$(PRINTF_DIR)ft_, $(addsuffix .c, $(PRINTF_SRC))) \
	$(addprefix $(SRCS_DIR)$(MISC_DIR)ft_, $(addsuffix .c, $(MISC_SRC))) \

# *** CHAR ******************************************************************* #

CHAR_DIR = char/
CHAR_SRC = \
	isalnum \
	isalpha \
	isascii \
	ischarset \
	isdigit \
	isprint \
	isspace \
	tolower \
	toupper \

# *** STRING ***************************************************************** #

STR_DIR = str/
STR_SRC = \
	countwords \
	split \
	strchr \
	strcmp \
	strcpy \
	strdup \
	striteri \
	strjoin \
	strjoin2 \
	strlcat \
	strlcpy \
	strlen \
	strmapi \
	strncmp \
	strnstr \
	strrchr \
	strtok \
	strtrim \
	substr \

# *** INTERGER *************************************************************** #

INT_DIR = int/
INT_SRC = \
	abs \
	atoi \
	fabs \
	isrange \
	itoa \
	itoalen \
	strtoi \
	strtol \

# *** MEMORY ***************************************************************** #

MEM_DIR = mem/
MEM_SRC = \
	bzero \
	calloc \
	memchr \
	memcmp \
	memcpy \
	memcpy2 \
	memmove \
	memset \
	vfree \

# *** VECTOR ***************************************************************** #

VECTOR_DIR = vector/
VECTOR_SRC = \
	vector_add \
	vector_add_ptr \
	vector_alloc \
	vector_deallocate \
	vector_delete \
	vector_deleten \
	vector_free \
	vector_get \
	vector_init \
	vector_insert \
	vector_insert_ptr \
	vector_insertn \
	vector_join \
	vector_resize \
	vector_set \
	vector_set_ptr \
	vector_strncat \
	vector_trim \

# *** LINKED LIST ************************************************************ #

LST_DIR = lst/
LST_SRC = \
	lstadd_back \
	lstadd_front \
	lstclear \
	lstdelone \
	lstiter \
	lstlast \
	lstmap \
	lstnew \
	lstsize \

# *** GET_NEXT_LINE ********************************************************** #

GNL_DIR = get_next_line/
GNL_SRC = \
	get_next_line \

# *** FT_PRINTF ************************************************************** #

PRINTF_DIR = ft_printf/
PRINTF_SRC = \
	dprintf \
	addconversion \

# *** MISCELLANEOUS ********************************************************** #

MISC_DIR = misc/
MISC_SRC = \
	close \
	free_array \
	free_2darray_char \
