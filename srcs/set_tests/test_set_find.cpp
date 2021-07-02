/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_find.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 10:09:19 by bvalette          #+#    #+#             */
/*   Updated: 2021/07/02 14:32:43 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_set.hpp"
# include "./tester/exampleClass.hpp"

void
test_set_const_find(int findKey, std::set<exampleClass> const std_c0, ft::set<exampleClass> const ft_c0)	{

		std::cout << HEADER_TITLE << "[ Test find with const set ]" << RESET_COLOR << std::endl;
		testSet(ft_c0, std_c0, NOPRINT);

		std::set<exampleClass>::const_iterator	std_c0_ret = std_c0.find(findKey);
		ft::set<exampleClass>::const_iterator	ft_c0_ret = ft_c0.find(findKey);

		if (std_c0_ret == std_c0.end())
			testBool(ft_c0_ret == ft_c0.end(), __FILE__, __LINE__);
		else if (testBool(ft_c0_ret != ft_c0.end(), __FILE__, __LINE__) == true)
			testBool(*ft_c0_ret == *std_c0_ret, __FILE__, __LINE__);
}

int
test_set_find( void )	{
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		size_t			valgrind_factor = (VALGRIND_MODE == true) ? 100 : 1;
		size_t			testSize = 3000 / valgrind_factor;
		int findKey = 42;
		std::cout << HEADER_TITLE << "[ Test find function with set of " << testSize << " int key ]" << RESET_COLOR << std::endl;

		std::vector<exampleClass>	ft_val_0(testSize);
		std::vector<exampleClass>	std_val_0(testSize);
		for (size_t i = 0; i < testSize; i++)	{
			srand(i);
			int val = rand() % testSize;
			if (i == testSize / 2)
				findKey = val;
			ft_val_0[i] = val;
			std_val_0[i] = val;
		}

		std::set<exampleClass>	std_c0(std_val_0.begin(), std_val_0.end());
		ft::set<exampleClass>	ft_c0(ft_val_0.begin(), ft_val_0.end());
		testSet(ft_c0, std_c0, NOPRINT);

		std::cout << HEADER_TITLE << "[ Test find with a value added previously to the set ]" << RESET_COLOR << std::endl;
		std::set<exampleClass>::iterator	std_c0_ret = std_c0.find(findKey);
		ft::set<exampleClass>::iterator	ft_c0_ret = ft_c0.find(findKey);

		if (std_c0_ret == std_c0.end())
			testBool(ft_c0_ret == ft_c0.end(), __FILE__, __LINE__);
		else if (testBool(ft_c0_ret != ft_c0.end(), __FILE__, __LINE__) == true)
			testBool(*ft_c0_ret == *std_c0_ret	, __FILE__, __LINE__);

		test_set_const_find(findKey, std_c0, ft_c0);

		std::cout << HEADER_TITLE << "[ Test find with a value absent from the set (higher than the highest key)]" << RESET_COLOR << std::endl;
		std_c0_ret = std_c0.find(testSize * 2);
		ft_c0_ret = ft_c0.find(testSize * 2);

		if (std_c0_ret == std_c0.end())
			testBool(ft_c0_ret == ft_c0.end(), __FILE__, __LINE__);
		else if (testBool(ft_c0_ret != ft_c0.end(), __FILE__, __LINE__) == true)
			testBool(*ft_c0_ret == *std_c0_ret	, __FILE__, __LINE__);

		std::cout << HEADER_TITLE << "[ Test find with a value absent from the set (lower than the lowest key)]" << RESET_COLOR << std::endl;
		std_c0_ret = std_c0.find(-42);
		ft_c0_ret = ft_c0.find(-42);

		if (std_c0_ret == std_c0.end())
			testBool(ft_c0_ret == ft_c0.end(), __FILE__, __LINE__);
		else if (testBool(ft_c0_ret != ft_c0.end(), __FILE__, __LINE__) == true)
			testBool(*ft_c0_ret == *std_c0_ret	, __FILE__, __LINE__);

		std::cout << HEADER_TITLE << "[ Test find with empty set ]" << RESET_COLOR << std::endl;
		ft_c0.clear();
		std_c0.clear();
		testSet(ft_c0, std_c0, NOPRINT);

		std_c0_ret = std_c0.find(42);
		ft_c0_ret = ft_c0.find(42);

		if (std_c0_ret == std_c0.end())
			testBool(ft_c0_ret == ft_c0.end(), __FILE__, __LINE__);
		else if (testBool(ft_c0_ret != ft_c0.end(), __FILE__, __LINE__) == true)
			testBool(*ft_c0_ret == *std_c0_ret	, __FILE__, __LINE__);
	}
	return (0);
}
