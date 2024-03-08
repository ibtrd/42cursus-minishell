#ifndef TESTING_H
# define TESTING_H

#include <stdio.h>
#include <stdlib.h>

int	executor(t_astnode *root, char **env); //REMOVE
void dprint_ast(int fd, t_astnode* root, char *color);

#endif //TESTING_H