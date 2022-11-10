/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandbox.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:50:22 by jhii              #+#    #+#             */
/*   Updated: 2022/11/10 15:26:32 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SANDBOX_H
# define SANDBOX_H

# define RESET		"\033[0m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

# include "libft.h"
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>

int	sandbox(int argc, char **argv, char **envp);

#endif