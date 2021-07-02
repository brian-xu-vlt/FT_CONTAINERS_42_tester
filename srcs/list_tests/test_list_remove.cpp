/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_remove.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:02:16 by bvalette          #+#    #+#             */
/*   Updated: 2021/05/31 15:35:16 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_list.hpp"

int
test_list_remove( void )	{

	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with ints ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		std::cout << HEADER_TITLE << "[ Instanciate empty list ]" << RESET_COLOR << std::endl;
		ft::list<int>	ftl0;
		std::list<int>	stdl0;
		size_t			valgrind_factor = (VALGRIND_MODE == true) ? 10000 : 1;
		size_t			testSize = 3000000 / valgrind_factor;
		testList(ftl0, stdl0, NOPRINT);
		std::cout << SUBTITLE << "[ remove with value = 42 (on empty list)]" << RESET_COLOR << std::endl;
		ftl0.remove(42);
		stdl0.remove(42);
		testList(ftl0, stdl0, NOPRINT);
		std::cout << SUBTITLE << "[ pushback " << testSize << " random values in list (same value for ft and std list, 0 <= val < 20) ]" << RESET_COLOR << std::endl;


		srand(reinterpret_cast<long unsigned int>(&stdl0));
		int val;
		for (size_t i = 0; i < testSize; i++)	{
			val = rand() % 20;
			ftl0.push_back(val);
			stdl0.push_back(val);
		}
		testList(ftl0, stdl0, NOPRINT);
		std::cout << SUBTITLE << "[ remove with the last value pushed in the list ]" << RESET_COLOR << std::endl;
		ftl0.remove(val);
		stdl0.remove(val);
		testList(ftl0, stdl0, NOPRINT);
		std::cout << SUBTITLE << "[ remove with valus which is not contained in list (42) ]" << RESET_COLOR << std::endl;
		ftl0.remove(42);
		stdl0.remove(42);
		testList(ftl0, stdl0, NOPRINT);
	}
	{
		std::cout << HEADER_TITLE << "[ Instanciate a list of 5 elements, all 42]" << RESET_COLOR << std::endl;
		ft::list<int>	ftl0(5, 42);
		std::list<int>	stdl0(5, 42);
		testList(ftl0, stdl0, NOPRINT);
		ftl0.remove(42);
		stdl0.remove(42);
		testList(ftl0, stdl0, NOPRINT);
	}
	return (0);
}
