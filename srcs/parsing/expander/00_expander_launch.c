/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_expander_launch.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:20:50 by ibertran          #+#    #+#             */
/*   Updated: 2024/03/12 03:06:24 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishelldef.h"
#include "ast.h"
#include "env.h"
#include "expander.h"
#include "interpreter.h"

static int	has_interpreter(t_astnode *node);
static int	expand_node(t_astnode *node, t_vector *env);
static int	expand_string(t_vector *str, t_vector *masks, size_t *index, t_vector *env);

void debug_print_str_mask(t_vector *str, t_vector *masks, size_t *index, char *msg); //REMOVE

int	expander_launch(t_astnode *node, t_vector *env)
{
	if (!node)
		return (SUCCESS);
	if (has_interpreter(node) && expand_node(node, env))
		return (FAILURE);
	if (expander_launch(node->left, env) || expander_launch(node->right, env))
		return (FAILURE);
	return (SUCCESS);
}

static int	has_interpreter(t_astnode *node)
{
	t_vector	*str;
	size_t		i;

	if (node->type != _CMD && (node->type < _INPUT || node->type > _APPEND))
		return (!FAILURE);
	i = 0;
	while (i < ((t_vector *)node->args)->total)
	{
		str = ft_vector_get(node->args, i);
		if (ft_strpbrk((char *)str->ptr, __INTERPRETERS))
			return (!SUCCESS);
		i++;
	}
	return (!FAILURE);
}

static int	expand_node(t_astnode *node, t_vector *env)
{
	t_vector	mask;
	size_t		i;

	if (init_interpretation_masks(&mask, node->args))
		return (FAILURE);
	i = 0;
	while (i < ((t_vector *)node->args)->total)
	{
		if (expand_string(node->args, &mask, &i, env))
		{
			ft_vector_free(&mask);
			return (FAILURE);
		}
		i++;
	}
	ft_vector_free(&mask);
	args_vectors_to_stings((t_vector **)&node->args, node->type);
	return (SUCCESS);
}

static int	expand_string(t_vector *str, t_vector *masks, size_t *index, t_vector *env)
{
	// char *printstr = (char *)((t_vector *)ft_vector_get(str, *index))->ptr;
	// char *printmask = (char *)((t_vector *)ft_vector_get(masks, *index))->ptr;

	debug_print_str_mask(str, masks, index, "EXPANDING");
	if (tilde_expansion(str, masks, *index))
		return (FAILURE);
	debug_print_str_mask(str, masks, index, "TILDE");
	if (envars_expansion(str, masks, *index, env))
		return (FAILURE);
	debug_print_str_mask(str, masks, index, "ENVARS");
	if (quote_removal(str, masks, index))
		return (FAILURE);
	debug_print_str_mask(str, masks, index, "QUOTE REMOVAL");	
	return (SUCCESS);
}

void debug_print_str_mask(t_vector *str, t_vector *masks, size_t *index, char *msg)
{
	const t_vector	*print = ft_vector_get(str, *index);
	const t_vector	*mask = ft_vector_get(masks, *index);
	size_t			i;
	char			*c;

	ft_dprintf(2, "%s:\nstr  |%s|\nmask |", msg, (char *)print->ptr);
	i = 0;
	while (i < mask->total - 1)
	{
		c = ft_vector_get((t_vector *)mask, i);
		if (*c & __ENVAR_MASK && *c & __DQUOTE_MASK)
			printf("&");
		else if (*c & __ENVAR_MASK)
			printf("$");
		else if (*c & __SQUOTE_MASK)
			printf("\'");
		else if (*c & __DQUOTE_MASK)
			printf("\"");
		else
			printf(".");
		i++;
	}
	printf("|\n\n");

}
