/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ezxml_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 15:36:33 by smamba            #+#    #+#             */
/*   Updated: 2016/08/31 14:10:12 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "imod.h"

const char	*ezxml_child_value(ezxml_t node, const char *name)
{
	ezxml_t	child;

	child = ezxml_child(node, name);
	if (child == NULL)
		ft_exit(0, "IOError: No accessible child named %s", name);
	return (child->txt);
}

const char	*ezxml_child_soft(ezxml_t node, const char *name)
{
	ezxml_t	child;

	child = ezxml_child(node, name);
	if (child == NULL)
	{
		if (!ft_strcmp(name, "transparency") || !ft_strcmp(name, "reflection")
			|| !ft_strcmp(name, "mirror") || !ft_strcmp(name, "backcolor"))
			return ("0");
		else
		{
			ft_putstr(ANSI_YELLOW"IOWarning: Unkown child "ANSI_YELLOW);
			return ("0");
		}
	}
	if (!ft_strcmp(name, "reflection") || !ft_strcmp(name, "mirror"))
		return (!ft_strcmp(child->txt, "TRUE") ? "1" : "0");
	return (child->txt);
}

const char	*ezxml_attr_value(ezxml_t xml, const char *attr)
{
	const char	*val;

	val = ezxml_attr(xml, attr);
	if (val == NULL)
		ft_exit(0, "IOError: No accessible attribute called %s", attr);
	return (val);
}

const char	*ezxml_attr_soft(ezxml_t xml, const char *attr)
{
	const char	*val;

	val = ezxml_attr(xml, attr);
	if (val == NULL)
		if (!ft_strcmp(attr, "type"))
			return ("POINT_LIGHT");
	return (val);
}
