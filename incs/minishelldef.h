/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishelldef.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:01:05 by ibertran          #+#    #+#             */
/*   Updated: 2024/04/06 17:31:57 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELLDEF_H
# define MINISHELLDEF_H

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
# define __PROMPT "\001\e[1m\002%s\001\xE2\x86\002\xAA \
\001\e[33m\002%s\001\e[0m\002 "
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
# define __UNEXPECTED_EOF "%s: unexpected EOF while looking for matching `%c'\n"
# define __UNCLOSED_ERROR "syntax error: unclosed"
# define __SYNTAX_ERROR "syntax error near unexpected token"
# define __UNSUPPORTED_ERROR "unsupported operator"
# define __CMD_NOT_FOUND "command not found"
# define __IS_DIR "Is a directory"
# define __NO_FILE "No such file or directory"
# define __HEREDOC_EOF "%s: warning: here-document delimited by end-of-file \
(wanted `%s')\n"
# define __NOT_A_TTY "%s: %d: Not a tty\n"
# define __INIT_ERROR "%s: Initialisation failure: %s\n"
# define __PARSING_ERROR "%s: Parsing failure: %s\n"

//EXIT
# define __MINISHELL_EXIT "exit\n"
# define __EXIT_NUMERIC_ERR "%s: exit: too many arguments\n"
# define __EXIT_ARGS_ERR "%s: exit: %s: numeric argument required\n"

//EXPORT
# define __INVALID_IDENTIFIER "%s: export: `%s': not a valid identifier\n"

//CD
# define __CD_NOT_SET "%s: cd: %s not set\n"
# define __CD_ARGS "%s: cd: too many arguments\n"
# define __CD_ERR "%s: cd: %s: %s\n"

//HISTORY
# define __HISTORY_USAGE "history: usage: history [-c]\n"
# define __HISTORY_INVAL "%s: history: %s: invalid option\n"

#endif //MINISHELLDEF_H
