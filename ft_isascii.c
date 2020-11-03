/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 21:45:55 by dpowdere          #+#    #+#             */
/*   Updated: 2020/11/02 21:47:11 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

inline int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
