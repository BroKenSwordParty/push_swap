/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 00:10:51 by jchamorr          #+#    #+#             */
/*   Updated: 2021/11/11 19:11:13 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int x)
{
	if (x >= 0 && x <= 127)
		return (1);
	else
		return (0);
}
