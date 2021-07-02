/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_deque_clear.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:49:36 by bvalette          #+#    #+#             */
/*   Updated: 2021/05/31 10:30:28 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_deque.hpp"

int
test_deque_clear( void )	{
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with floats ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		std::cout << HEADER_TITLE << "TEST CLEAR FUNCTION with deque of 1000000 floats" << RESET_COLOR << std::endl;
		ft::deque<float> ft_c0 (1000000, 42.21f);
		std::deque<float> std_c0 (1000000, 42.21f);

		testDeque(ft_c0, std_c0, NOPRINT);
		ft_c0.clear();
		std_c0.clear();
		testDeque(ft_c0, std_c0, NOPRINT);

		std::cout << HEADER_TITLE << "TEST Clear with forced reallocation by swapping with a default constructed deque" << RESET_COLOR << std::endl;
		ft::deque<float>().swap(ft_c0);
		std::deque<float>().swap(std_c0);
		testDeque(ft_c0, std_c0, NOPRINT);
	}
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with floats ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		std::cout << HEADER_TITLE << "TEST CLEAR FUNCTION with empty deque" << RESET_COLOR << std::endl;
		ft::deque<float> ft_c0;
		std::deque<float> std_c0;

		testDeque(ft_c0, std_c0, NOPRINT);
		ft_c0.clear();
		std_c0.clear();
		testDeque(ft_c0, std_c0, NOPRINT);
	}
	return (0);
}
