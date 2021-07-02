/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_element_access.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:50:54 by bvalette          #+#    #+#             */
/*   Updated: 2021/05/31 10:43:52 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_vector.hpp"

void
test_front_back(
		ft::vector<int>& 	ft_c0,
		std::vector<int>& 	std_c0)	{

	std::cout << SUBTITLE << "Test front() / back()" << RESET_COLOR << std::endl;
	std::cout << "ft front = " << ft_c0.front() << " std front = " << std_c0.front() << std::endl;
	std::cout << "ft back = " << ft_c0.back() << " std back = " << std_c0.back() << std::endl;
	testBool(ft_c0.front() == std_c0.front(), __LINE__);
	testBool(ft_c0.back() == std_c0.back(), __LINE__);
}

int
test_vector_element_access( void )	{
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with ints ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		ft::vector<int>		ft_c0;
		std::vector<int>	std_c0;
		size_t				testSize = 10;


		for (size_t i = 1; i < testSize; i++)	{
			ft_c0.push_back(i);
			std_c0.push_back(i);
			test_front_back(ft_c0, std_c0);
			testVector(ft_c0, std_c0, NOPRINT);
		}

		std::cout << HEADER_TITLE << "Assign 1,42" << RESET_COLOR << std::endl;
		ft_c0.assign(1,42);
		std_c0.assign(1,42);
		testVector(ft_c0, std_c0, NOPRINT);
		test_front_back(ft_c0, std_c0);
	}
	return (0);
}

