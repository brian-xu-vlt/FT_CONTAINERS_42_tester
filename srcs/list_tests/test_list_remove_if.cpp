/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_remove_if.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:02:11 by bvalette          #+#    #+#             */
/*   Updated: 2021/05/31 15:46:07 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_list.hpp"

int
test_list_remove_if( void )	{
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with ints ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		std::cout << SUBTITLE << "[ Instanciate empty list ]" << RESET_COLOR << std::endl;
		ft::list<int>	ftl0;
		std::list<int>	stdl0;
		size_t			valgrind_factor = (VALGRIND_MODE == true) ? 10000 : 1;
		size_t			testSize = 3000000 / valgrind_factor;
		testList(ftl0, stdl0, NOPRINT);
		std::cout << SUBTITLE << "[ remove_if with predicate: bool function returning true for value>10 ]" << RESET_COLOR << std::endl;
		ftl0.remove_if(more_than_10);
		stdl0.remove_if(more_than_10);
		testList(ftl0, stdl0, NOPRINT);
		std::cout << SUBTITLE << "[ pushback " << testSize << " random values in list (same value for ft and std list, 0 <= val < 20) ]" << RESET_COLOR << std::endl;


		srand(reinterpret_cast<long unsigned int>(&stdl0));
		for (size_t i = 0; i < testSize; i++)	{
			int val = rand() % 20;
			ftl0.push_back(val);
			stdl0.push_back(val);
		}

		testList(ftl0, stdl0, NOPRINT);
		std::cout << SUBTITLE << "[ remove_if with predicate: bool function returning true for value>100 (no element will be removed) ]" << RESET_COLOR << std::endl;
		ftl0.remove_if(more_than_100);
		stdl0.remove_if(more_than_100);
		testList(ftl0, stdl0, NOPRINT);
		std::cout << SUBTITLE << "[ remove_if with predicate: bool function returning true for value>10 ]" << RESET_COLOR << std::endl;
		ftl0.remove_if(more_than_10);
		stdl0.remove_if(more_than_10);
		testList(ftl0, stdl0, NOPRINT);
		std::cout << SUBTITLE << "[ remove_if with predicate: bool function returning true for value<=10 ]" << RESET_COLOR << std::endl;
		ftl0.remove_if(less_or_eq_10);
		stdl0.remove_if(less_or_eq_10);
		testList(ftl0, stdl0, NOPRINT);
		std::cout << SUBTITLE << "[ same as before but list 0 is now empty ]" << RESET_COLOR << std::endl;
		ftl0.remove_if(less_or_eq_10);
		stdl0.remove_if(less_or_eq_10);
		testList(ftl0, stdl0, NOPRINT);
		std::cout << SUBTITLE << "[ assign 10 times value 1 to list, remove_if with less_or_eq_10 ]" << RESET_COLOR << std::endl;
		ftl0.clear();
		stdl0.clear();
		ftl0.assign(10, 1);
		stdl0.assign(10, 1);
		testList(ftl0, stdl0, NOPRINT);
		ftl0.remove_if(less_or_eq_10);
		stdl0.remove_if(less_or_eq_10);
		testList(ftl0, stdl0, NOPRINT);
	}
	return (0);
}
