/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_deque_reverseIterator.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:51:28 by bvalette          #+#    #+#             */
/*   Updated: 2021/06/02 10:41:27 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_deque.hpp"

void
test_constReverseIterator( ft::deque<int> const & ft_c0, std::deque<int> const & std_c0 )	{

	std::cout << HEADER_TITLE << "Test const version of reverse reverse_iterator" << RESET_COLOR << std::endl;
	std::cout << HEADER_TITLE << "If compile fails, const version of function are missing" << RESET_COLOR << std::endl;
	ft::deque<int>::const_reverse_iterator		ft_it = ft_c0.rbegin(); //  !!!! ---> HINT:  IN CASE OF COMPILER ISSUE: const version is MISSING !
	ft::deque<int>::const_reverse_iterator		ft_itend = (ft_c0.rend() - 1); //  !!!! ---> HINT:  IN CASE OF COMPILER ISSUE: const version is MISSING !

	std::deque<int>::const_reverse_iterator	std_it = std_c0.rbegin();
	std::deque<int>::const_reverse_iterator	std_itend = (std_c0.rend() - 1);

	testDeque(ft_c0, std_c0, NOPRINT);
	testBool(*ft_it== *std_it, __FILE__, __LINE__);
	testBool(*ft_itend == *std_itend, __FILE__, __LINE__);
	ft_it++;
	std_it++;
	testBool(*ft_it== *std_it, __FILE__, __LINE__);
}

int
test_deque_reverseIterator( void )	{
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with ints ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	std::cout << HEADER_TITLE << "ASCENDING ORDER VALUES" << RESET_COLOR << std::endl;
	{
		std::cout << HEADER_TITLE << "[ Iterator construction: default ]" << RESET_COLOR << std::endl;
		ft::deque<int>		ft_c0;
		std::deque<int>	std_c0;
		size_t				testSize = 10;

		std::cout << HEADER_TITLE << "[ pushback " << testSize << " ASCENDING even values in deque 0 ]" << RESET_COLOR << std::endl;

		for (size_t i = 1; i < testSize; i++)	{
			ft_c0.push_back(i);
			std_c0.push_back(i);
		}
		ft::deque<int>::reverse_iterator		ft_it = ft_c0.rbegin();
		ft::deque<int>::reverse_iterator		ft_it2 = ft_c0.rbegin();
		ft::deque<int>::reverse_iterator		ft_itend = ft_c0.rend();
		std::deque<int>::reverse_iterator		std_it = std_c0.rbegin();
		std::deque<int>::reverse_iterator		std_it2 = std_c0.rbegin();
		std::deque<int>::reverse_iterator		std_itend = std_c0.rend();

		std::cout << HEADER_TITLE << "[ test operator< with reverse_iterator to rbegin < rend ]" << RESET_COLOR << std::endl;
		testBool(ft_it < ft_itend && std_it < std_itend, __FILE__, __LINE__);
		std::cout << HEADER_TITLE << "[ loop test reverse_iterator increment vs. reverse_iterator + i ]" << RESET_COLOR << std::endl;
		for (size_t i = 0; i < ft_c0.size(); i++)
		{
			testBool(*ft_it == *(ft_it2 + i) && *std_it == *(std_it2 + i), __FILE__, __LINE__, i);
			ft_it++;
			std_it++;
		}
		std::cout << HEADER_TITLE << "[ test operator= ]" << RESET_COLOR << std::endl;
		ft_it--;
		ft_it2 = ft_it;
		testBool(ft_it == ft_it2, __FILE__, __LINE__);
		std::cout << HEADER_TITLE << "[ loop test reverse_iterator increment vs. reverse_iterator + i ]" << RESET_COLOR << std::endl;
		for (size_t i = 0; i < ft_c0.size() - 1; ++i, --ft_it)
			testBool((*ft_it == *(ft_it2 - i)), __FILE__, __LINE__, i);
		std::cout << HEADER_TITLE << "[ test size() vs. rend() - rbeing() ] with size == " << std_c0.size() << RESET_COLOR << std::endl;
		std::cout << "op = " << static_cast<size_t>(ft_c0.rend() - ft_c0.rbegin()) << " size = " << ft_c0.size() << std::endl;
		std::cout << "op = " << static_cast<size_t>(std_c0.rend() - std_c0.rbegin()) << " size = " << std_c0.size() << std::endl;
		testBool(static_cast<size_t>(ft_c0.rend() - ft_c0.rbegin()) == ft_c0.size()
			&& static_cast<size_t>(std_c0.rend() - std_c0.rbegin()) == std_c0.size(), __FILE__, __LINE__);
		test_constReverseIterator(ft_c0, std_c0);
	}
	std::cout << HEADER_TITLE << "TEST ITERATOR ARITHMETIC" << RESET_COLOR << std::endl;
	{

		ft::deque<int>		ft_c0;
		std::deque<int>	std_c0;
		int testSize = 42;

		for (int i = 0; i < testSize; i++)	{
			ft_c0.insert(ft_c0.end(), i);
			std_c0.insert(std_c0.end(), i);
		}
		testDeque(ft_c0, std_c0, NOPRINT);

		ft::deque<int>::reverse_iterator ft_it0;
		std::deque<int>::reverse_iterator std_it0;

		std::cout << HEADER_TITLE << "[ Iterator construction: copy assignation ]" << RESET_COLOR << std::endl;
		ft_it0 = ft_c0.rbegin();
		std_it0	= std_c0.rbegin();

		std::cout << HEADER_TITLE << "[ Iterator construction: copy construction ]" << RESET_COLOR << std::endl;
		ft::deque<int>::reverse_iterator ft_it1(ft_it0);
		std::deque<int>::reverse_iterator std_it1(std_it0);

		std::cout << HEADER_TITLE << "[ Iterator construction: copy assignation ]" << RESET_COLOR << std::endl;
		{
			ft::deque<int>::reverse_iterator ft_it1(ft_c0.begin());
			std::deque<int>::reverse_iterator std_it1(std_c0.begin());
			testBool(true);
			std::cout << HEADER_TITLE << "[ base() return ]" << RESET_COLOR << std::endl;
			testBool( ft_it1.base() == ft_c0.begin()
					&& std_it1.base() == std_c0.begin(), __FILE__, __LINE__);
		}

		std::cout << HEADER_TITLE << "[ Pre post increment decrement of reverse_iterator ]" << RESET_COLOR << std::endl;
		testBool(*ft_it0 == *std_it0, __FILE__, __LINE__);
		ft_it0++;
		std_it0++;
		testBool(*ft_it0 == *std_it0, __FILE__, __LINE__);
		ft_it0 += 21;
		std_it0 += 21;
		testBool(*ft_it0 == *std_it0, __FILE__, __LINE__);
		ft_it0--;
		std_it0--;
		testBool(*ft_it0 == *std_it0, __FILE__, __LINE__);
		std::cout << HEADER_TITLE << "[ operator[] ]" << RESET_COLOR << std::endl;
		testBool(ft_it0[4] == std_it0[4], __FILE__, __LINE__);
		testBool(ft_it0[-4] == std_it0[-4], __FILE__, __LINE__);
		std::cout << HEADER_TITLE << "[ Pre post increment decrement of value with * ]" << RESET_COLOR << std::endl;
		*ft_it0++;
		*std_it0++;
		testBool(*ft_it0 == *std_it0, __FILE__, __LINE__);
		testDeque(ft_c0, std_c0, NOPRINT);

		ft_it1 = ft_it0;
		std_it1 = std_it0;
		std::cout << HEADER_TITLE << "[ Relational Operators ]" << RESET_COLOR << std::endl;
		testBool(ft_it0 == ft_it1 && std_it0 == std_it1, __FILE__, __LINE__);
		testBool(ft_it0 >= ft_it1 && std_it0 >= std_it1, __FILE__, __LINE__);
		testBool(ft_it0 <= ft_it1 && std_it0 <= std_it1, __FILE__, __LINE__);
		ft_it1 = ft_c0.rbegin();
		std_it1 = std_c0.rbegin();
		testBool(ft_it0 != ft_it1 && std_it0 != std_it1, __FILE__, __LINE__);
		testBool(ft_it0 > ft_it1 && std_it0 > std_it1, __FILE__, __LINE__);
		testBool(ft_it0 >= ft_it1 && std_it0 >= std_it1, __FILE__, __LINE__);
		testBool(ft_it1 < ft_it0 && std_it1 < std_it0, __FILE__, __LINE__);
		testBool(ft_it1 <= ft_it0 && std_it1 <= std_it0, __FILE__, __LINE__);
		ft_it0 = ft_c0.rbegin();
		std_it0 = std_c0.rbegin();
		ft_it0 += 5;
		std_it0 += 5;
		std::cout << HEADER_TITLE << "[ reverse_iterator substraction ]" << RESET_COLOR << std::endl;
		testBool(ft_it0 - ft_it1 == std_it0 - std_it1, __FILE__, __LINE__);
		testBool(ft_it1 - ft_it0 == std_it1 - std_it0, __FILE__, __LINE__);

		std::cout << HEADER_TITLE << "[ reverse_iterator addition ]" << RESET_COLOR << std::endl;
		ft_it0 = ft_c0.rbegin() + 10;
		std_it0 = std_c0.rbegin() + 10;
		testBool(ft_it0 - ft_it1 == std_it0 - std_it1, __FILE__, __LINE__);
		testBool(ft_it1 - ft_it0 == std_it1 - std_it0, __FILE__, __LINE__);

		std::cout << HEADER_TITLE << "[ reverse_iterator substraction ]" << RESET_COLOR << std::endl;
		ft_it0 = ft_c0.rend() - 1;
		std_it0 = std_c0.rend() - 1;
		testBool(*ft_it0 == *std_it0, __FILE__, __LINE__);

		ft_it0 = ft_c0.rbegin() + 10;
		std_it0 = std_c0.rbegin() + 10;
		std::cout << HEADER_TITLE << "[ reverse_iterator's value changed but dereferencing with operator*]" << RESET_COLOR << std::endl;
		*ft_it0 = 5000;
		*std_it0 = 5000;
		testBool(*ft_it0 == *std_it0, __FILE__, __LINE__);
		testDeque(ft_c0, std_c0, NOPRINT);
		std::cout << HEADER_TITLE << "[ reverse_iterator's value changed by dereferencing with operator[] ]" << RESET_COLOR << std::endl;
		ft_it0[1] = 42;
		std_it0[1] = 42;
		testBool(*ft_it0 == *std_it0, __FILE__, __LINE__);
		testDeque(ft_c0, std_c0, NOPRINT);
	}
	{
		std::cout << HEADER_TITLE << "[ reverse_iterator's value changed by dereferencing with operator->]" << RESET_COLOR << std::endl;

		ft::deque<std::pair<int, int> >				ft_c0(12, std::make_pair(1, 2));
		std::deque<std::pair<int, int> >				std_c0(12, std::make_pair(1, 2));
		ft::deque<std::pair<int, int> >::reverse_iterator 		ft_it0 = ft_c0.rbegin();
		std::deque<std::pair<int, int> >::reverse_iterator 	std_it0 = std_c0.rbegin();

		testBool(ft_it0->first == std_it0->first, __FILE__, __LINE__);
		testBool(ft_it0->second == std_it0->second, __FILE__, __LINE__);
	}
	return (0);

}
