/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_element_access.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:01:17 by bvalette          #+#    #+#             */
/*   Updated: 2021/07/02 14:32:43 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_list.hpp"

void
test_front_back(
		ft::list<int>& 		ft_c0,
		std::list<int>& 	std_c0)	{

	std::cout << SUBTITLE << "Test front() / back()" << RESET_COLOR << std::endl;
	std::cout << "ft front = " << ft_c0.front() << " std front = " << std_c0.front() << std::endl;
	std::cout << "ft back = " << ft_c0.back() << " std back = " << std_c0.back() << std::endl;
	testBool(ft_c0.front() == std_c0.front(), __FILE__, __LINE__);
	testBool(ft_c0.back() == std_c0.back(), __FILE__, __LINE__);
}

int
test_list_element_access( void )	{
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with ints ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		ft::list<int>		ft_c0;
		std::list<int>		std_c0;
		size_t				testSize = 10;


		for (size_t i = 1; i < testSize; i++)	{
			ft_c0.push_back(i);
			std_c0.push_back(i);
			test_front_back(ft_c0, std_c0);
			testList(ft_c0, std_c0, NOPRINT);
		}

		std::cout << HEADER_TITLE << "Assign 1,42" << RESET_COLOR << std::endl;
		ft_c0.assign(1,42);
		std_c0.assign(1,42);
		testList(ft_c0, std_c0, NOPRINT);
		test_front_back(ft_c0, std_c0);
	}
	return (0);
}
