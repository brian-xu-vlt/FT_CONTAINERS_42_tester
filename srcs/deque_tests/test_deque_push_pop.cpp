/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_deque_push_pop.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:52:18 by bvalette          #+#    #+#             */
/*   Updated: 2021/06/07 18:11:21 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_deque.hpp"

int
test_deque_push_pop( void )	{

	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with std::string ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		size_t	testSize = 10;
		ft::deque<std::string>		ft_c0;
		std::deque<std::string>		std_c0;

		testDeque(ft_c0, std_c0, NOPRINT);

		std::cout << SUBTITLE << "[ Push_back " << testSize << " times ]" << RESET_COLOR << std::endl;
		while (std_c0.size() < testSize)
		{
			ft_c0.push_back("the End...");
			std_c0.push_back("the End...");
			testDeque(ft_c0, std_c0, NOPRINT);
		}
		testDeque(ft_c0, std_c0, NOPRINT);

		std::cout << SUBTITLE << "[ pop_back " << testSize << " times ]" << RESET_COLOR << std::endl;
		while (std_c0.empty() == false)
		{
			std_c0.pop_back();
			ft_c0.pop_back();
			testDeque(ft_c0, std_c0, NOPRINT);
		}
		testDeque(ft_c0, std_c0, NOPRINT);

		std::cout << SUBTITLE << "[ Push_front " << testSize << " times ]" << RESET_COLOR << std::endl;
		while (std_c0.size() < testSize)
		{
			ft_c0.push_front("the End...");
			std_c0.push_front("the End...");
			testDeque(ft_c0, std_c0, NOPRINT);
		}

		std::cout << SUBTITLE << "[ pop_front " << testSize << " times ]" << RESET_COLOR << std::endl;
		while (std_c0.empty() == false)
		{
			std_c0.pop_front();
			ft_c0.pop_front();
			testDeque(ft_c0, std_c0, NOPRINT);
		}
		testDeque(ft_c0, std_c0, NOPRINT);
	}
	return (0);
}
