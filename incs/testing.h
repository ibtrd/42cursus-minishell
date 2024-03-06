#ifndef TESTING_H
# define TESTING_H

#include <stdio.h>
#include <stdlib.h>

void	dprint_ast(int fd, t_astnode *root); //REMOVE
t_astnode	*ast_test1(void); //REMOVE
int	dup_cmdline(const char *cmdline, char **dup); //REMOVE
int	executor(t_astnode *root, char **env); //REMOVE
void print2D(int fd, t_astnode* root);

#endif //TESTING_H