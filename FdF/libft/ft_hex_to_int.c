/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:13:19 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/07 18:40:41 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hex_to_int(const char *hex) {
    int		result;
	int		value;
	char	c;

	result = 0;
    if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X')) {
        hex += 2;
    }
    while (*hex) {
        c = *hex;
        value = 0;

        if (ft_isdigit(c)) {
            value = c - '0';  // '0' to '9' -> 0 to 9
        } else if (c >= 'A' && c <= 'F') {
            value = c - 'A' + 10;  // 'A' to 'F' -> 10 to 15
        } else if (c >= 'a' && c <= 'f') {
            value = c - 'a' + 10;  // 'a' to 'f' -> 10 to 15
        } else {
            return -1;
        }
        result = result * 16 + value;
        hex++;
    }
    return (result);
}
