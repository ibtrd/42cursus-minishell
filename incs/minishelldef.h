/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishelldef.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:01:05 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/03 16:45:17 by kchillon         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELLDEF_H
# define MINISHELLDEF_H

// # define __PRGM_NAME "minishell"
// # define __PRGM_NAME_LEN 9 //REMOVE

# define __GLOBAL_HISTORY ".minishell_history"

//STATUS
# define SUCCESS 0
# define FAILURE -1
# define REMOVAL 1
# define MATCH 1
# define NO_MATCH 0

//ENV
# define __MAX_SHLVL 1000
# define __DEFAULT_PATH "/usr/bin:/bin:/usr/sbin:/sbin"

//PROMPT
# define __DEFAULT_PROMPT "\001\e[36;1m\002minishell\001\e[0m\002 "
# define __PROMPT "\001\e[1m\002%s\001↳\002 \001\e[33m\002%s\001\e[0m\002 "
# define __GIT_PROMPT "%s\001\e[34m\002[%s%s\001\e[34m\002]\001\e[0m\002"
# define __SECONDARY_PROMPT " \001\e[33;1m\002>\001\e[0m\002 "

# define P_WHITE "\001\e[37m\002"
# define P_CYAN "\001\e[36m\002"
# define P_BLUE "\001\e[34m\002"
# define P_YELLOW "\001\e[33m\002"
# define P_GREEN "\001\e[32m\002"
# define P_RED "\001\e[31m\002"	
# define P_BOLD "\001\e[1m\002"
# define P_RESET "\001\e[0m\002"

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
# define __INTERPRETERS "\"\'$*?~"
# define __QUOTES "\"\'"

//EXPANDER
# define __HOME_ENVAR "$HOME"
# define __PWD_ENVAR "$PWD"
# define __OLDPWD_ENVAR "$OLDPWD"

# define __NO_MASK 0x0
# define __DQUOTE_MASK 0x1
# define __SQUOTE_MASK 0x2
# define __ENVAR_MASK 0x4
# define __FILE_MASK 0x8

# define __WORKING_DIRECTORY "."

//PRINT
# define __MINISHELL "minishell"
# define __UNEXPECTED_EOF "unexpected EOF while looking for matching `"
# define __UNCLOSED_ERROR "syntax error: unclosed"
# define __SYNTAX_ERROR "syntax error near unexpected token"
# define __UNSUPPORTED_ERROR "unsupported operator"
# define __AST_ERROR "AST building failed"
# define __CMD_NOT_FOUND "command not found"
# define __IS_DIR "Is a directory"
# define __NO_FILE "No such file or directory"

#endif //MINISHELLDEF_H
