/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_reverse.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:02:22 by bvalette          #+#    #+#             */
/*   Updated: 2021/05/31 15:54:50 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_list.hpp"

int
test_list_reverse( void )	{
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with ints ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		ft::list<int>		ftl0;
		std::list<int>		stdl0;
		size_t				testSize = 600;


		for (size_t i = 1; i < testSize; i++)	{
			ftl0.push_back(i);
			stdl0.push_back(i);
		}
		testList(ftl0, stdl0, NOPRINT);
		std::cout << HEADER_TITLE << "LIST FILLED WITH "<< testSize << " DESCENDING VALUES " << RESET_COLOR << std::endl;
		std::cout << SUBTITLE << "[ reverse with no arguments ]" << RESET_COLOR << std::endl;
		ftl0.reverse();
		stdl0.reverse();
		testList(ftl0, stdl0, NOPRINT);
		std::cout << SUBTITLE << "[ push back 1 value in list, increasing size by 1, chaging oddness ]" << RESET_COLOR << std::endl;
		ftl0.push_back(42);
		stdl0.push_back(42);
		std::cout << SUBTITLE << "[ reverse with no arguments ]" << RESET_COLOR << std::endl;
		ftl0.reverse();
		stdl0.reverse();
		testList(ftl0, stdl0, NOPRINT);
	}
	{
		ft::list<int>		ftl0;
		std::list<int>		stdl0;
		srand(reinterpret_cast<long unsigned int>(&stdl0));
		size_t			valgrind_factor = (VALGRIND_MODE == true) ? 10000 : 1;
		size_t			testSize = rand() % (500000 / valgrind_factor);

		for (size_t i = 1; i < testSize; i++)	{
			int val = rand() % 100;
			ftl0.push_back(val);
			stdl0.push_back(val);
		}
		testList(ftl0, stdl0, NOPRINT);
		std::cout << HEADER_TITLE << "LIST FILLED WITH "<< testSize << " VALUES, A RANDOM NUMBER OF RANDOM VALUES " << RESET_COLOR << std::endl;
		std::cout << SUBTITLE << "[ reverse with no arguments ]" << RESET_COLOR << std::endl;
		ftl0.reverse();
		stdl0.reverse();
		testList(ftl0, stdl0, NOPRINT);
		std::cout << SUBTITLE << "[ push back 1 value in list, increasing size by 1, chaging oddness ]" << RESET_COLOR << std::endl;
		ftl0.push_back(42);
		stdl0.push_back(42);
		std::cout << SUBTITLE << "[ reverse with no arguments ]" << RESET_COLOR << std::endl;
		ftl0.reverse();
		stdl0.reverse();
		testList(ftl0, stdl0, NOPRINT);
	}
	return (0);
}
