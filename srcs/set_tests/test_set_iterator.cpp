/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_iterator.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:50:38 by bvalette          #+#    #+#             */
/*   Updated: 2021/02/23 09:01:38 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_set.hpp"

static void
test_constIterator( ft::set<int> const & ft_c0, std::set<int> const & std_c0 )	{

	std::cout << HEADER_TITLE << "Test const version of reverse iterator" << RESET_COLOR << std::endl;
	std::cout << SUBTITLE << "If compile fails, const version of function are missing" << RESET_COLOR << std::endl;
	ft::set<int>::const_iterator	ft_it = ft_c0.begin(); //  !!!! ---> HINT:  IN CASE OF COMPILER ISSUE: const version is MISSING !
	ft::set<int>::const_iterator	ft_itend = ft_c0.end(); //  !!!! ---> HINT:  IN CASE OF COMPILER ISSUE: const version is MISSING !

	std::set<int>::const_iterator	std_it = std_c0.begin();
	std::set<int>::const_iterator	std_itend = std_c0.end();

	testBool(*ft_it== *std_it, __FILE__, __LINE__);
	ft_it++;
	std_it++;
	testBool(*ft_it== *std_it, __FILE__, __LINE__);

	ft_itend--;
	std_itend--;
	testBool(*ft_itend== *std_itend, __FILE__, __LINE__);
}

int
test_set_iterator( void )	{
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with ints ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		std::cout << SUBTITLE << "[ Default Ctor, copy ctor, copy assignable ]" << RESET_COLOR << std::endl;

		std::set<double> 				std_c0;
		ft::set<double> 				ft_c0;

		// insert some values:
		std_c0.insert(1);
		std_c0.insert(0);
		std_c0.insert(-4);

		ft_c0.insert(1);
		ft_c0.insert(0);
		ft_c0.insert(-4);

		std::set<double>::iterator		std_it_1 = std_c0.begin();
		ft::set<double>::iterator			ft_it_1 = ft_c0.begin();


		std::set<double>::iterator		std_it_2(std_it_1);
		ft::set<double>::iterator		ft_it_2(ft_it_1);
		std::set<double>::iterator		std_it_3;
		ft::set<double>::iterator		ft_it_3;
		std_it_3 = std_it_1;
		ft_it_3 = ft_it_1;
		testBool(*std_it_1 == *ft_it_1, __FILE__, __LINE__);
		testBool(*std_it_2 == *ft_it_2, __FILE__, __LINE__);
		testBool(*std_it_3 == *ft_it_3, __FILE__, __LINE__);
	}
	std::cout << HEADER_TITLE << "ASCENDING ORDER VALUES" << RESET_COLOR << std::endl;
	{
		std::cout << SUBTITLE << "[ Iterator construction: default ]" << RESET_COLOR << std::endl;
		ft::set<int>	ft_c0;
		std::set<int>	std_c0;
		size_t				testSize = 10;

		std::cout << SUBTITLE << "[ pushback " << testSize << " ASCENDING even values in list 0 ]" << RESET_COLOR << std::endl;

		for (size_t i = 1; i < testSize; i++)	{
			ft_c0.insert(i);
			std_c0.insert(i);
		}
		test_constIterator(ft_c0, std_c0);
		ft::set<int>::iterator		ft_it = ft_c0.begin();
		ft::set<int>::iterator		ft_it2 = ft_c0.begin();
		ft::set<int>::iterator		ft_itend = ft_c0.end();
		std::cout << SUBTITLE << "[ test operator= ]" << RESET_COLOR << std::endl;
		ft_it--;
		ft_it2 = ft_it;
		testBool(ft_it == ft_it2, __FILE__, __LINE__);
	}

	std::cout << HEADER_TITLE << "TEST ITERATOR ARITHMETIC" << RESET_COLOR << std::endl;

	{
		ft::set<int>		ft_c0;
		std::set<int>	std_c0;
		int testSize = 42;

		for (int i = 0; i < testSize; i++)	{
			ft_c0.insert(i);
			std_c0.insert(i);
		}
		testSet(ft_c0, std_c0, NOPRINT);

		ft::set<int>::iterator ft_it0;
		std::set<int>::iterator std_it0;

		std::cout << SUBTITLE << "[ Iterator construction: copy assignation ]" << RESET_COLOR << std::endl;
		ft_it0 = ft_c0.begin();
		std_it0	= std_c0.begin();

		std::cout << SUBTITLE << "[ Iterator construction: copye construction ]" << RESET_COLOR << std::endl;
		ft::set<int>::iterator ft_it1(ft_it0);
		std::set<int>::iterator std_it1(std_it0);

		std::cout << SUBTITLE << "[ Pre post increment decrement of iterator ]" << RESET_COLOR << std::endl;
		testBool(*ft_it0 == *std_it0, __FILE__, __LINE__);
		ft_it0++;
		std_it0++;
		testBool(*ft_it0 == *std_it0, __FILE__, __LINE__);
		ft_it0--;
		std_it0--;
		testBool(*ft_it0 == *std_it0, __FILE__, __LINE__);
		testSet(ft_c0, std_c0, NOPRINT);
		std::cout << SUBTITLE << "[ Pre post increment decrement of value with * ]" << RESET_COLOR << std::endl;
		*ft_it0++;
		*std_it0++;
		testBool(*ft_it0 == *std_it0, __FILE__, __LINE__);
		testSet(ft_c0, std_c0, NOPRINT);

		ft_it1 = ft_it0;
		std_it1 = std_it0;
		std::cout << SUBTITLE << "[ Relational Operators ]" << RESET_COLOR << std::endl;
		testBool(ft_it0 == ft_it1 && std_it0 == std_it1, __FILE__, __LINE__);
		ft_it1 = ft_c0.begin();
		std_it1 = std_c0.begin();
		testBool(ft_it0 != ft_it1 && std_it0 != std_it1, __FILE__, __LINE__);
		ft_it0 = ft_c0.begin();
		std_it0 = std_c0.begin();
	}
	return (0);
}
