/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:49:43 by jhii              #+#    #+#             */
/*   Updated: 2022/11/08 13:20:54 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/sandbox.h"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
		return(printf("Error: Invalid number of arguments..\n"));
	sandbox();
	return (0);
}