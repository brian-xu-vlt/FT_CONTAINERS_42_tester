/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_reverseIterator.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:51:28 by bvalette          #+#    #+#             */
/*   Updated: 2021/02/23 09:02:27 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_set.hpp"

static void
test_iterator_values_pointed(
				ft::set<int>::reverse_iterator ft_it_test ,
				ft::set<int>& ft_c0 ,
				std::set<int>::reverse_iterator std_it_test ,
				std::set<int>& std_c0 , int line)	{

	if (std_it_test == std_c0.rend())
		testBool(ft_it_test == ft_c0.rend(), __FILE__, line);
	else
		testBool(*ft_it_test == *std_it_test, __FILE__, line);
	if (std_it_test != std_c0.rbegin())
		testBool(ft_it_test != ft_c0.rbegin(), __FILE__, line);
}

static void
test_const_iterator_values_pointed(
				ft::set<int>::const_reverse_iterator ft_it_test ,
				const ft::set<int>& ft_c0 ,
				std::set<int>::const_reverse_iterator std_it_test ,
				const std::set<int>& std_c0 , int line)	{

	if (std_it_test == std_c0.rend())
		testBool(ft_it_test == ft_c0.rend(), __FILE__, line);
	else
		testBool(*ft_it_test == *std_it_test, __FILE__, line);
	if (std_it_test != std_c0.rbegin())
		testBool(ft_it_test != ft_c0.rbegin(), __FILE__, line);
}

static void
test_constReverseIterator( ft::set<int> const & ft_c0, std::set<int> const & std_c0 )	{

	std::cout << HEADER_TITLE << "Test const version of reverse iterator" << RESET_COLOR << std::endl;
	std::cout << SUBTITLE << "If compile fails, const version of function are missing" << RESET_COLOR << std::endl;
	std::set<int>::const_reverse_iterator	std_it = std_c0.rbegin();
	std::set<int>::const_reverse_iterator	std_itend = std_c0.rend()--;

	ft::set<int>::const_reverse_iterator		ft_it = ft_c0.rbegin(); //  !!!! ---> HINT:  IN CASE OF COMPILER ISSUE: const version is MISSING !
	ft::set<int>::const_reverse_iterator		ft_itend = ft_c0.rend()--; //  !!!! ---> HINT:  IN CASE OF COMPILER ISSUE: const version is MISSING !

	test_const_iterator_values_pointed(ft_it, ft_c0, std_it, std_c0, __LINE__);
	test_const_iterator_values_pointed(ft_itend, ft_c0, std_itend, std_c0, __LINE__);

	ft_it++;
	std_it++;
	test_const_iterator_values_pointed(ft_it, ft_c0, std_it, std_c0, __LINE__);
	++ft_it;
	++std_it;
	test_const_iterator_values_pointed(ft_it, ft_c0, std_it, std_c0, __LINE__);
	ft_it--;
	std_it--;
	test_const_iterator_values_pointed(ft_it, ft_c0, std_it, std_c0, __LINE__);
	--ft_it;
	--std_it;
	test_const_iterator_values_pointed(ft_it, ft_c0, std_it, std_c0, __LINE__);

}

int
test_set_reverseIterator( void )	{
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with ints ~~~~~~~~~~~" << RESET_COLOR << std::endl;

	{
		size_t			valgrind_factor = (VALGRIND_MODE == true) ? 100 : 1;
		size_t			testSize = 5000 / valgrind_factor;
		int findKey = 42;
		std::cout << HEADER_TITLE << "[ Create a set of " << testSize << " int key ]" << RESET_COLOR << std::endl;

		std::vector<int>	ft_val_0(testSize);
		std::vector<int>	std_val_0(testSize);
		srand(time(NULL));
		for (size_t i = 0; i < testSize; i++)	{
			int val = rand() % testSize;
			if (i == testSize / 2)
				findKey = val;
			ft_val_0[i] = val;
			std_val_0[i] = val;
		}

		std::set<int>	std_c0(std_val_0.begin(), std_val_0.end());
		ft::set<int>	ft_c0(ft_val_0.begin(), ft_val_0.end());
		testSet(ft_c0, std_c0, NOPRINT);

		ft::set<int>::reverse_iterator			ft_it = ft_c0.rbegin();
		ft::set<int>::reverse_iterator			ft_it2 = --ft_c0.rend();
		ft::set<int>::reverse_iterator			ft_it3 = ++ft_c0.rbegin();
		ft::set<int>::reverse_iterator			ft_itend = ft_c0.rend();

		std::set<int>::reverse_iterator		std_it = std_c0.rbegin();
		std::set<int>::reverse_iterator		std_it2 = --std_c0.rend();
		std::set<int>::reverse_iterator		std_it3 = ++std_c0.rbegin();
		std::set<int>::reverse_iterator		std_itend = std_c0.rend();

		test_iterator_values_pointed(ft_it, ft_c0, std_it, std_c0, __LINE__);
		test_iterator_values_pointed(ft_itend, ft_c0, std_itend, std_c0, __LINE__);
		test_iterator_values_pointed(ft_it2, ft_c0, std_it2, std_c0, __LINE__);
		test_iterator_values_pointed(ft_it3, ft_c0, std_it3, std_c0, __LINE__);

		std::cout << HEADER_TITLE << "[ TEST REVERSE ITERATOR ARITHMETIC ]" << RESET_COLOR << std::endl;

		ft_it++;
		std_it++;
		test_iterator_values_pointed(ft_it, ft_c0, std_it, std_c0, __LINE__);
		++ft_it;
		++std_it;
		test_iterator_values_pointed(ft_it, ft_c0, std_it, std_c0, __LINE__);
		ft_it--;
		std_it--;
		test_iterator_values_pointed(ft_it, ft_c0, std_it, std_c0, __LINE__);
		--ft_it;
		--std_it;
		test_iterator_values_pointed(ft_it, ft_c0, std_it, std_c0, __LINE__);

		ft_itend--;
		std_itend--;
		test_iterator_values_pointed(ft_itend, ft_c0, std_itend, std_c0, __LINE__);
		--ft_itend;
		--std_itend;
		test_iterator_values_pointed(ft_itend, ft_c0, std_itend, std_c0, __LINE__);
		ft_itend++;
		std_itend++;
		test_iterator_values_pointed(ft_itend, ft_c0, std_itend, std_c0, __LINE__);
		++ft_itend;
		++std_itend;
		test_iterator_values_pointed(ft_itend, ft_c0, std_itend, std_c0, __LINE__);

		test_constReverseIterator(ft_c0, std_c0);

		std::cout << HEADER_TITLE << "[ TEST BASE MEMBER FUNCTION ]" << RESET_COLOR << std::endl;
		{
			std_it = ++std_c0.rbegin();
			ft_it = ++ft_c0.rbegin();
			std::set<int>::iterator		std_base = std_it.base();
			ft::set<int>::iterator			ft_base = ft_it.base();
			testBool( *ft_base == *std_base, __FILE__, __LINE__);
		}
		{
			std_it = --std_c0.rend();
			ft_it = --ft_c0.rend();
			std::set<int>::iterator		std_base = std_it.base();
			ft::set<int>::iterator			ft_base = ft_it.base();
			testBool( *ft_base == *std_base, __FILE__, __LINE__);
		}
	}
	return (0);
}
