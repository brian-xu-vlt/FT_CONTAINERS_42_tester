/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_deque_operatorEqual.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:52:23 by bvalette          #+#    #+#             */
/*   Updated: 2021/05/31 10:54:14 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_deque.hpp"

int
test_deque_operatorEqual( void )	{

	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with std::string ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		ft::deque<std::string>	ft_c0(10, "hello");
		std::deque<std::string>	std_c0(10, "hello");
		ft::deque<std::string>	ft_c1(5, "byee");
		std::deque<std::string>	std_c1(5, "byee");

		std::cout << SUBTITLE << "[ Instanciate deque 0 with 10 \"hello\" and deque 1 with 5 \"byeee\" ]" << RESET_COLOR << std::endl;
		testDeque(ft_c0, std_c0, NOPRINT);
		testDeque(ft_c1, std_c1, NOPRINT);

		std::cout << SUBTITLE << "[ deque0=deque1 ]" << RESET_COLOR << std::endl;

		ft_c0 = ft_c1;
		std_c0 = std_c1;

		testDeque(ft_c0, std_c0, NOPRINT);
		testDeque(ft_c1, std_c1, NOPRINT);

		std::cout << SUBTITLE << "[ deque0=deque0 ! same object ]" << RESET_COLOR << std::endl;
		ft_c0 = ft_c0;
		std_c0 = std_c0;

		testDeque(ft_c0, std_c0, NOPRINT);
	}
	return (0);
}
