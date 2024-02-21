# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_srcs.mk                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 06:32:49 by ibertran          #+#    #+#              #
#    Updated: 2024/02/19 00:58:31 by ibertran         ###   ########lyon.fr    #
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

# *** VECTOR ***************************************************************** #

VECTOR_DIR = vector/
VECTOR_SRC = \
	vector_add \
	vector_delete \
	vector_free \
	vector_get \
	vector_init \
	vector_join \
	vector_resize \
	vector_set \
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
	convert_char \
	convert_decimal \
	convert_decimal_utils \
	convert_lower_hexa \
	convert_percent \
	convert_pointer \
	convert_pointer_utils \
	convert_string \
	convert_unsigned_decimal \
	convert_upper_hexa \
	dprintf \
	format \
	printf \

# *** MISCELLANEOUS ********************************************************** #

MISC_DIR = misc/
MISC_SRC = \
	close \
	free_array \
	free_2darray_char \
