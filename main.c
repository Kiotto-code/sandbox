/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:49:43 by jhii              #+#    #+#             */
/*   Updated: 2022/08/09 20:36:26 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
		return(printf("Error: Invalid number of arguments..\n"));
	cub3d();
	return (0);
}