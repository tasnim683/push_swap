/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasnimo <tasnimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 13:15:18 by username          #+#    #+#             */
/*   Updated: 2026/08/13 14:18:36 by tasnimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_isdigit(int c);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
#endif
