/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_iterator.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:50:38 by bvalette          #+#    #+#             */
/*   Updated: 2021/02/23 09:01:38 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_map.hpp"

void
test_constIterator( ft::map<double, int> const & ft_c0, std::map<double, int> const & std_c0 )	{

	std::cout << HEADER_TITLE << "Test const version of reverse iterator" << RESET_COLOR << std::endl;
	std::cout << SUBTITLE << "If compile fails, const version of function are missing" << RESET_COLOR << std::endl;
	ft::map<double, int>::const_iterator	ft_it = ft_c0.begin(); //  !!!! ---> HINT:  IN CASE OF COMPILER ISSUE: const version is MISSING !
	ft::map<double, int>::const_iterator	ft_itend = ft_c0.end(); //  !!!! ---> HINT:  IN CASE OF COMPILER ISSUE: const version is MISSING !

	std::map<double, int>::const_iterator	std_it = std_c0.begin();
	std::map<double, int>::const_iterator	std_itend = std_c0.end();

	testBool(ft_it->first== std_it->first, __FILE__, __LINE__);
	testBool(ft_it->second== std_it->second, __FILE__, __LINE__);
	ft_it++;
	std_it++;
	testBool(ft_it->first== std_it->first, __FILE__, __LINE__);
	testBool(ft_it->second== std_it->second, __FILE__, __LINE__);

	ft_itend--;
	std_itend--;
	testBool(ft_itend->first== std_itend->first, __FILE__, __LINE__);
	testBool(ft_itend->second== std_itend->second, __FILE__, __LINE__);
}

int
test_map_iterator( void )	{
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with ints ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		std::cout << SUBTITLE << "[ Default Ctor, copy ctor, copy assignable ]" << RESET_COLOR << std::endl;

		std::map<double,int> 				std_c0;
		ft::map<double,int> 				ft_c0;

		// insert some values:
		std_c0[1]= 42 ;
		std_c0[0] = 0;
		std_c0[-4] = 21;

		ft_c0[1]= 42 ;
		ft_c0[0] = 0;
		ft_c0[-4] = 21;

		std::map<double, int>::iterator		std_it_1 = std_c0.begin();
		ft::map<double, int>::iterator			ft_it_1 = ft_c0.begin();


		std::cout << SUBTITLE << "[ Change some mapped values through iterator ]" << RESET_COLOR << std::endl;
		std_it_1->second = 21;
		ft_it_1->second = 21;

		std::map<double, int>::iterator		std_it_2(std_it_1);
		ft::map<double, int>::iterator		ft_it_2(ft_it_1);
		std::map<double, int>::iterator		std_it_3;
		ft::map<double, int>::iterator		ft_it_3;
		std_it_3 = std_it_1;
		ft_it_3 = ft_it_1;
		testBool(std_it_1->first == ft_it_1->first && std_it_1->second == ft_it_1->second, __FILE__, __LINE__);
		testBool(std_it_2->first == ft_it_2->first && std_it_2->second == ft_it_2->second, __FILE__, __LINE__);
		testBool(std_it_3->first == ft_it_3->first && std_it_3->second == ft_it_3->second, __FILE__, __LINE__);
	}
	std::cout << HEADER_TITLE << "ASCENDING ORDER VALUES" << RESET_COLOR << std::endl;
	{
		std::cout << SUBTITLE << "[ Iterator construction: default ]" << RESET_COLOR << std::endl;
		ft::map<double, int>	ft_c0;
		std::map<double, int>	std_c0;
		size_t				testSize = 10;

		std::cout << SUBTITLE << "[ pushback " << testSize << " ASCENDING even values in list 0 ]" << RESET_COLOR << std::endl;

		for (size_t i = 1; i < testSize; i++)	{
			ft_c0.insert(ft::make_pair<double, int>(i, 0));
			std_c0.insert(std::make_pair<double, int>(i, 0));
		}
		ft::map<double, int>::iterator		ft_it = ft_c0.begin();
		ft::map<double, int>::iterator		ft_it2 = ft_c0.begin();
		ft::map<double, int>::iterator		ft_itend = ft_c0.end();
		std::cout << SUBTITLE << "[ test operator= ]" << RESET_COLOR << std::endl;
		ft_it--;
		ft_it2 = ft_it;
		testBool(ft_it == ft_it2, __FILE__, __LINE__);
	}

	std::cout << HEADER_TITLE << "TEST ITERATOR ARITHMETIC" << RESET_COLOR << std::endl;

	{
		ft::map<double, int>		ft_c0;
		std::map<double, int>	std_c0;
		int testSize = 42;

		for (int i = 0; i < testSize; i++)	{
			ft_c0.insert(ft::make_pair<double, int>(i, 0));
			std_c0.insert(std::make_pair<double, int>(i, 0));
		}
		testMap(ft_c0, std_c0, NOPRINT);

		ft::map<double, int>::iterator ft_it0;
		std::map<double, int>::iterator std_it0;

		std::cout << SUBTITLE << "[ Iterator construction: copy assignation ]" << RESET_COLOR << std::endl;
		ft_it0 = ft_c0.begin();
		std_it0	= std_c0.begin();

		std::cout << SUBTITLE << "[ Iterator construction: copye construction ]" << RESET_COLOR << std::endl;
		ft::map<double, int>::iterator ft_it1(ft_it0);
		std::map<double, int>::iterator std_it1(std_it0);

		std::cout << SUBTITLE << "[ Pre post increment decrement of iterator ]" << RESET_COLOR << std::endl;
		testBool(ft_it0->first == std_it0->first, __FILE__, __LINE__);
		testBool(ft_it0->second == std_it0->second, __FILE__, __LINE__);
		ft_it0++;
		std_it0++;
		testBool(ft_it0->first == std_it0->first, __FILE__, __LINE__);
		testBool(ft_it0->second == std_it0->second, __FILE__, __LINE__);
		ft_it0--;
		std_it0--;
		testBool(ft_it0->first == std_it0->first, __FILE__, __LINE__);
		testBool(ft_it0->second == std_it0->second, __FILE__, __LINE__);
		testMap(ft_c0, std_c0, NOPRINT);
		std::cout << SUBTITLE << "[ Pre post increment decrement of value with * ]" << RESET_COLOR << std::endl;
		*ft_it0++;
		*std_it0++;
		testBool(ft_it0->first == std_it0->first, __FILE__, __LINE__);
		testBool(ft_it0->second == std_it0->second, __FILE__, __LINE__);
		testMap(ft_c0, std_c0, NOPRINT);

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
