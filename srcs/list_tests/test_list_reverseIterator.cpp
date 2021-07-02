/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_reverseIterator.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:02:26 by bvalette          #+#    #+#             */
/*   Updated: 2021/07/02 14:45:12 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_list.hpp"

void
test_constReverseIterator( ft::list<int> const & ft_c0, std::list<int> const & std_c0 )	{

	std::cout << HEADER_TITLE << "Test const version of reverse reverse_iterator" << RESET_COLOR << std::endl;
	std::cout << HEADER_TITLE << "If compile fails, const version of function are missing" << RESET_COLOR << std::endl;
	ft::list<int>::const_reverse_iterator		ft_it = ft_c0.rbegin(); //  !!!! ---> HINT:  IN CASE OF COMPILER ISSUE: const version is MISSING !
	ft::list<int>::const_reverse_iterator		ft_itend = --ft_c0.rend();  //  !!!! ---> HINT:  IN CASE OF COMPILER ISSUE: const version is MISSING !

	std::list<int>::const_reverse_iterator	std_it = std_c0.rbegin();
	std::list<int>::const_reverse_iterator	std_itend = --std_c0.rend();
	testBool(*ft_it== *std_it, __FILE__, __LINE__);
	testBool(*ft_itend == *std_itend, __FILE__, __LINE__);
	ft_it++;
	std_it++;
	testBool(*ft_it== *std_it, __FILE__, __LINE__);
}

int
test_list_reverseIterator( void )	{
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with ints ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	std::cout << HEADER_TITLE << "ASCENDING ORDER VALUES" << RESET_COLOR << std::endl;
	{
		std::cout << HEADER_TITLE << "[ Iterator construction: default ]" << RESET_COLOR << std::endl;
		ft::list<int>		ft_c0;
		std::list<int>	std_c0;
		size_t				testSize = 10;

		std::cout << HEADER_TITLE << "[ pushback " << testSize << " ASCENDING even values in list 0 ]" << RESET_COLOR << std::endl;

		for (size_t i = 1; i < testSize; i++)	{
			ft_c0.push_back(i);
			std_c0.push_back(i);
		}
		ft::list<int>::reverse_iterator		ft_it = ft_c0.rbegin();
		ft::list<int>::reverse_iterator		ft_it2 = ft_c0.rbegin();
		ft::list<int>::reverse_iterator		ft_itend = ft_c0.rend();

		std::cout << SUBTITLE << "[ test operator= ]" << RESET_COLOR << std::endl;
		ft_it--;
		ft_it2 = ft_it;
		testBool(ft_it == ft_it2, __FILE__, __LINE__);
		test_constReverseIterator(ft_c0, std_c0);
	}
	std::cout << HEADER_TITLE << "TEST ITERATOR ARITHMETIC" << RESET_COLOR << std::endl;
	{

		ft::list<int>	ft_c0;
		std::list<int>	std_c0;
		int testSize = 42;

		for (int i = 0; i < testSize; i++)	{
			ft_c0.insert(ft_c0.end(), i);
			std_c0.insert(std_c0.end(), i);
		}
		testList(ft_c0, std_c0, NOPRINT);

		ft::list<int>::reverse_iterator ft_it0;
		std::list<int>::reverse_iterator std_it0;

		std::cout << HEADER_TITLE << "[ Iterator construction: copy assignation ]" << RESET_COLOR << std::endl;
		ft_it0 = ft_c0.rbegin();
		std_it0	= std_c0.rbegin();
		testBool(true);

		std::cout << HEADER_TITLE << "[ Iterator construction: copy assignation ]" << RESET_COLOR << std::endl;
		{
			ft::list<int>::reverse_iterator ft_it1(ft_c0.begin());
			std::list<int>::reverse_iterator std_it1(std_c0.begin());
			testBool(true);
			std::cout << HEADER_TITLE << "[ base() return ]" << RESET_COLOR << std::endl;
			testBool( ft_it1.base() == ft_c0.begin()
					&& std_it1.base() == std_c0.begin(), __FILE__, __LINE__);
		}

		std::cout << HEADER_TITLE << "[ Iterator construction: copye construction ]" << RESET_COLOR << std::endl;
		ft::list<int>::reverse_iterator ft_it1(ft_it0);
		std::list<int>::reverse_iterator std_it1(std_it0);

		testBool( *ft_it1 == *ft_it0 && *std_it1 == *std_it0, __FILE__, __LINE__);

		std::cout << HEADER_TITLE << "[ Pre post increment decrement of reverse_iterator ]" << RESET_COLOR << std::endl;
		testBool(*ft_it0 == *std_it0, __FILE__, __LINE__);
		ft_it0++;
		std_it0++;
		testBool(*ft_it0 == *std_it0, __FILE__, __LINE__);
		ft_it0--;
		std_it0--;
		testBool(*ft_it0 == *std_it0, __FILE__, __LINE__);
		std::cout << HEADER_TITLE << "[ Pre post increment decrement of value with * ]" << RESET_COLOR << std::endl;
		*ft_it0++;
		*std_it0++;
		testBool(*ft_it0 == *std_it0, __FILE__, __LINE__);
		testList(ft_c0, std_c0, NOPRINT);

		ft_it1 = ft_it0;
		std_it1 = std_it0;
		std::cout << HEADER_TITLE << "[ Relational Operators ]" << RESET_COLOR << std::endl;
		testBool(ft_it0 == ft_it1 && std_it0 == std_it1, __FILE__, __LINE__);
		ft_it1 = ft_c0.rbegin();
		std_it1 = std_c0.rbegin();
		testBool(ft_it0 != ft_it1 && std_it0 != std_it1, __FILE__, __LINE__);

		std::cout << HEADER_TITLE << "[ reverse_iterator's value changed but dereferencing with operator*]" << RESET_COLOR << std::endl;
		*ft_it0 = 5000;
		*std_it0 = 5000;
		testBool(*ft_it0 == *std_it0, __FILE__, __LINE__);
		testList(ft_c0, std_c0, NOPRINT);
	}
	{
		std::cout << HEADER_TITLE << "[ reverse_iterator's value changed by dereferencing with operator->]" << RESET_COLOR << std::endl;

		ft::list<std::pair<int, int> >				ft_c0(12, std::make_pair(1, 2));
		std::list<std::pair<int, int> >				std_c0(12, std::make_pair(1, 2));
		ft::list<std::pair<int, int> >::reverse_iterator 		ft_it0 = ft_c0.rbegin();
		std::list<std::pair<int, int> >::reverse_iterator 	std_it0 = std_c0.rbegin();

		testBool(ft_it0->first == std_it0->first, __FILE__, __LINE__);
		testBool(ft_it0->second == std_it0->second, __FILE__, __LINE__);
	}

	return (0);

}
