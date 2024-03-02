/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishelldef.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:01:05 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/02 03:05:09 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELLDEF_H
# define MINISHELLDEF_H

# define __PRGM_NAME "minishell"
# define __PRGM_NAME_LEN 9

//STATUS
# define SUCCESS 0
# define FAILURE -1

# define __UNCLOSED_SINGLE_QUOTE -1
# define __UNCLOSED_DOUBLE_QUOTE -2

# define __UNCLOSED_PARENTHESIS -1

//BUILTIN
# define __ECHO "echo"
# define __CD "cd"
# define __PWD "pwd"
# define __EXPORT "export"
# define __UNSET "unset"
# define __ENV "env"
# define __EXIT "exit"

//OPERATORS
# define __AND "&&"
# define __OR "||"
# define __PIPE "|"
# define __REDIR_INPUT "<"
# define __REDIR_OUTPUT ">"
# define __REDIR_HEREDOC "<<"
# define __REDIR_APPEND ">>"

# define __OPEN_PARENTHESIS "("
# define __CLOSE_PARENTHESIS ")"

//PARSING CHARSETS
# define __DEFAULT_IFS " \t\n"
# define __METACHARACTER "&|<>()"
# define __PARENTHESIS "()"
# define __SINGLE_QUOTE "\'"
# define __DOUBLE_QUOTE "\""

# define __SINGLE_QUOTE "\'"
# define __DOUBLE_QUOTE "\""

# define __SYNTAX_ERROR ": syntax error near unexpected token `"

#endif //MINISHELLDEF_H
