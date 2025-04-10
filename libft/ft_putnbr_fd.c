/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijoubair <ijoubair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:59:21 by ijoubair          #+#    #+#             */
/*   Updated: 2024/11/06 11:45:20 by ijoubair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	if (n <= 9)
	{
		ft_putchar_fd(n + 48, fd);
	}
}
// #include <stdio.h>

// int	main(void)
// {
// 	ft_putnbr_fd(42, 1);       // Expected: "42"
// 	printf("\n");
//     ft_putnbr_fd(-42, 1);      // Expected: "-42"
// 	printf("\n");

//     // Edge cases
//     ft_putnbr_fd(2147483647, 1);  // Expected: "2147483647"
// 	printf("\n");
//     ft_putnbr_fd(-2147483648, 1);  // Expected: "-2147483648"

//     // Zero
//     ft_putnbr_fd(0, 1);        // Expected: "0"
// 	printf("\n");

//     // Single-digit cases
//     ft_putnbr_fd(5, 1);        // Expected: "5"
// 	printf("\n");

//     ft_putnbr_fd(-9, 1);       // Expected: "-9"
// 		printf("\n");
//     // File descriptor testing
//     ft_putnbr_fd(123, 1);      // Expected output to stdout: "123"
// 		printf("\n");
//     ft_putnbr_fd(456, 2);      // Expected output to stderr: "456"
// 		printf("\n");
//     ft_putnbr_fd(789, -1);     // Expected behavior: Handle error gracefully
// 		printf("\n");

// }