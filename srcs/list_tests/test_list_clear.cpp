/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_clear.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:01:11 by bvalette          #+#    #+#             */
/*   Updated: 2021/05/31 16:00:41 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_list.hpp"

int
test_list_clear( void )	{
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with floats ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		size_t			valgrind_factor = (VALGRIND_MODE == true) ? 10000 : 1;
		size_t			testSize = 3000000 / valgrind_factor;

		std::cout << HEADER_TITLE << "TEST CLEAR FUNCTION with list of "<< testSize <<" floats" << RESET_COLOR << std::endl;
		ft::list<float> ftl0 (testSize, 42.21f);
		std::list<float> stdl0 (testSize, 42.21f);

		testList(ftl0, stdl0, NOPRINT);
		ftl0.clear();
		stdl0.clear();
		testList(ftl0, stdl0, NOPRINT);
	}
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with floats ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		std::cout << HEADER_TITLE << "TEST CLEAR FUNCTION with empty list" << RESET_COLOR << std::endl;
		ft::list<float> ftl0;
		std::list<float> stdl0;

		testList(ftl0, stdl0, NOPRINT);
		ftl0.clear();
		stdl0.clear();
		testList(ftl0, stdl0, NOPRINT);
	}
	return (0);
}
