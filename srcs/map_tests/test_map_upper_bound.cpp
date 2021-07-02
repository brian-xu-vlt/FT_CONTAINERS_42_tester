/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_upper_bound.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:37:34 by bvalette          #+#    #+#             */
/*   Updated: 2021/06/01 11:30:18 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_map.hpp"
# include "./tester/exampleClass.hpp"

void
test_map_const_upper_bound(int findKey, std::map<int, exampleClass, std::greater<int> > const std_c0, ft::map<int, exampleClass, std::greater<int> > const ft_c0)	{

		std::cout << HEADER_TITLE << "[ Test upper_bound with const map ]" << RESET_COLOR << std::endl;
		testMap(ft_c0, std_c0, NOPRINT);

		std::map<int, exampleClass, std::greater<int> >::const_iterator	std_c0_ret = std_c0.upper_bound(findKey);
		ft::map<int, exampleClass, std::greater<int> >::const_iterator	ft_c0_ret = ft_c0.upper_bound(findKey);

		if (std_c0_ret == std_c0.end())
			testBool(ft_c0_ret == ft_c0.end(), __LINE__);
		else if (testBool(ft_c0_ret != ft_c0.end(), __LINE__) == true)
			testBool(ft_c0_ret->first == std_c0_ret->first
				&& ft_c0_ret->second == std_c0_ret->second, __LINE__);
}

int
test_map_upper_bound( void )	{
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		size_t			valgrind_factor = (VALGRIND_MODE == true) ? 100 : 1;
		size_t			testSize = 5000 / valgrind_factor;
		int findKey = 42;
		std::cout << HEADER_TITLE << "[ Test upper_bound function with map of " << testSize << " int key and exampleClass mapped value ]" << RESET_COLOR << std::endl;

		std::vector<ft::pair<int, exampleClass> >	ft_val_0(testSize);
		std::vector<std::pair<int, exampleClass> >	std_val_0(testSize);
		for (size_t i = 0; i < testSize; i++)	{
			int val = rand() % testSize;
			if (i == testSize / 2)
				findKey = val;
			ft_val_0[i] = ft::make_pair(val, i);
			std_val_0[i] = std::make_pair(val, i);
		}

		std::map<int, exampleClass, std::greater<int> >	std_c0(std_val_0.begin(), std_val_0.end());
		ft::map<int, exampleClass, std::greater<int> >	ft_c0(ft_val_0.begin(), ft_val_0.end());
		testMap(ft_c0, std_c0, NOPRINT);

		std::cout << HEADER_TITLE << "[ Test upper_bound with a value added previously to the map ]" << RESET_COLOR << std::endl;
		std::map<int, exampleClass, std::greater<int> >::iterator	std_c0_ret = std_c0.upper_bound(findKey);
		ft::map<int, exampleClass, std::greater<int> >::iterator	ft_c0_ret = ft_c0.upper_bound(findKey);

		if (std_c0_ret == std_c0.end())
			testBool(ft_c0_ret == ft_c0.end(), __LINE__);
		else	{
			if (testBool(ft_c0_ret != ft_c0.end(), __LINE__) == true)
				testBool(ft_c0_ret->first == std_c0_ret->first
					&& ft_c0_ret->second == std_c0_ret->second, __LINE__);
		}

		test_map_const_upper_bound(findKey, std_c0, ft_c0);

		std::cout << HEADER_TITLE << "[ Test upper_bound with a value absent from the map (higher than the highest key)]" << RESET_COLOR << std::endl;
		std_c0_ret = std_c0.upper_bound(testSize * 2);
		ft_c0_ret = ft_c0.upper_bound(testSize * 2);

		if (std_c0_ret == std_c0.end())
			testBool(ft_c0_ret == ft_c0.end(), __LINE__);
		else if (testBool(ft_c0_ret != ft_c0.end(), __LINE__) == true)
			testBool(ft_c0_ret->first == std_c0_ret->first
				&& ft_c0_ret->second == std_c0_ret->second, __LINE__);

		std::cout << HEADER_TITLE << "[ Test upper_bound with a value absent from the map (lower than the lowest key)]" << RESET_COLOR << std::endl;
		std_c0_ret = std_c0.upper_bound(-42);
		ft_c0_ret = ft_c0.upper_bound(-42);

		if (std_c0_ret == std_c0.end())
			testBool(ft_c0_ret == ft_c0.end(), __LINE__);
		else if (testBool(ft_c0_ret != ft_c0.end(), __LINE__) == true)
			testBool(ft_c0_ret->first == std_c0_ret->first
				&& ft_c0_ret->second == std_c0_ret->second, __LINE__);

		std::cout << HEADER_TITLE << "[ Test upper_bound with empty map ]" << RESET_COLOR << std::endl;
		ft_c0.clear();
		std_c0.clear();
		testMap(ft_c0, std_c0, NOPRINT);

		std_c0_ret = std_c0.upper_bound(42);
		ft_c0_ret = ft_c0.upper_bound(42);

		if (std_c0_ret == std_c0.end())
			testBool(ft_c0_ret == ft_c0.end(), __LINE__);
		else if (testBool(ft_c0_ret != ft_c0.end(), __LINE__) == true)
			testBool(ft_c0_ret->first == std_c0_ret->first
				&& ft_c0_ret->second == std_c0_ret->second, __LINE__);
	}
	return (0);
}
