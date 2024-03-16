/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishelldef.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:01:05 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/15 23:04:08 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELLDEF_H
# define MINISHELLDEF_H

// # define __PRGM_NAME "minishell"
// # define __PRGM_NAME_LEN 9 //REMOVE

//STATUS
# define SUCCESS 0
# define FAILURE -1

# define __UNCLOSED_SINGLE_QUOTE -1
# define __UNCLOSED_DOUBLE_QUOTE -2
# define __UNCLOSED_BRACKET -3

# define REMOVAL 1

//ENV
# define __MAX_SHLVL 1000
# define __DEFAULT_PATH "/usr/bin:/bin:/usr/sbin:/sbin"

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
# define __OPEN_RBRACKET "("
# define __CLOSE_RBRACKET ")"
# define __NEXT_CMD ";"

# define __UNSUPPORTED_OPERATOR1 "<<<"
# define __UNSUPPORTED_OPERATOR2 "<>"
# define __UNSUPPORTED_OPERATOR3 "&"
# define __UNSUPPORTED_OPERATOR4 ";"

//PARSING CHARSETS
# define __DEFAULT_IFS " \t\n"
# define __METACHARACTER "&|<>();"
# define __INTERPRETERS "\"\'$*~"
# define __QUOTES "\"\'"

//EXPANDER
# define __HOME_ENVAR "$HOME"
# define __PWD_ENVAR "$PWD"
# define __OLDPWD_ENVAR "$OLDPWD"

# define __NO_MASK 0x0
# define __DQUOTE_MASK 0x1
# define __SQUOTE_MASK 0x2
# define __ENVAR_MASK 0x4

# define __WORKING_DIRECTORY "."

//PRINT
# define __MINISHELL "minishell"
# define __UNCLOSED_ERROR "syntax error: unclosed"
# define __SYNTAX_ERROR "syntax error near unexpected token"
# define __UNSUPPORTED_ERROR "unsupported operator"
# define __AST_ERROR "AST building failed"
# define __CMD_NOT_FOUND "command not found"

#endif //MINISHELLDEF_H
