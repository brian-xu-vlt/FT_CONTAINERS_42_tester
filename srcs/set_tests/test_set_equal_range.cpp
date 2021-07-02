/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_equal_range.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:37:34 by bvalette          #+#    #+#             */
/*   Updated: 2021/07/02 14:32:43 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_set.hpp"
# include "./tester/exampleClass.hpp"

void
test_set_const_equal_range(int findKey, std::set<exampleClass> const std_c0, ft::set<exampleClass> const ft_c0)	{

		std::cout << HEADER_TITLE << "[ Test equal_range with a value added previously to the set ]" << RESET_COLOR << std::endl;
		std::pair< std::set<exampleClass>::const_iterator, std::set<exampleClass>::const_iterator>	std_c0_ret = std_c0.equal_range(findKey);
		ft::pair< ft::set<exampleClass>::const_iterator, ft::set<exampleClass>::const_iterator>		ft_c0_ret = ft_c0.equal_range(findKey);

		if (std_c0_ret.first == std_c0.end())
			testBool(ft_c0_ret.first == ft_c0.end(), __FILE__, __LINE__);
		if (std_c0_ret.second == std_c0.end())
			testBool(ft_c0_ret.second == ft_c0.end(), __FILE__, __LINE__);
		if (ft_c0_ret.first != ft_c0.end())
			testBool(*(ft_c0_ret.first)== *(std_c0_ret.first), __FILE__, __LINE__);
		if (ft_c0_ret.second != ft_c0.end())
			testBool(*(ft_c0_ret.second)== *(std_c0_ret.second), __FILE__, __LINE__);
}

int
test_set_equal_range( void )	{
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		size_t			valgrind_factor = (VALGRIND_MODE == true) ? 100 : 1;
		size_t			testSize = 5000 / valgrind_factor;
		int findKey = 42;
		std::cout << HEADER_TITLE << "[ Test equal_range function with set of " << testSize << " int key ]" << RESET_COLOR << std::endl;

		std::vector<exampleClass>	ft_val_0(testSize);
		std::vector<exampleClass>	std_val_0(testSize);
		srand(time(NULL));
		for (size_t i = 0; i < testSize; i++)	{
			int val = rand() % testSize;
			if (i == testSize / 2)
				findKey = val;
			ft_val_0[i] = val;
			std_val_0[i] = val;
		}

		std::set<exampleClass>	std_c0(std_val_0.begin(), std_val_0.end());
		ft::set<exampleClass>	ft_c0(ft_val_0.begin(), ft_val_0.end());
		testSet(ft_c0, std_c0, NOPRINT);

		std::cout << HEADER_TITLE << "[ Test equal_range with a value added previously to the set ]" << RESET_COLOR << std::endl;
		std::pair< std::set<exampleClass>::iterator, std::set<exampleClass>::iterator>	std_c0_ret = std_c0.equal_range(findKey);
		ft::pair< ft::set<exampleClass>::iterator, ft::set<exampleClass>::iterator>		ft_c0_ret = ft_c0.equal_range(findKey);

		if (std_c0_ret.first == std_c0.end())
			testBool(ft_c0_ret.first == ft_c0.end(), __FILE__, __LINE__);
		if (std_c0_ret.second == std_c0.end())
			testBool(ft_c0_ret.second == ft_c0.end(), __FILE__, __LINE__);
		if (ft_c0_ret.first != ft_c0.end())
			testBool(*(ft_c0_ret.first)== *(std_c0_ret.first), __FILE__, __LINE__);
		if (ft_c0_ret.second != ft_c0.end())
			testBool(*(ft_c0_ret.second)== *(std_c0_ret.second), __FILE__, __LINE__);

		test_set_const_equal_range(findKey, std_c0, ft_c0);

		std::cout << HEADER_TITLE << "[ Test equal_range with a value absent from the set (higher than the highest key)]" << RESET_COLOR << std::endl;
		std_c0_ret = std_c0.equal_range(testSize * 2);
		ft_c0_ret = ft_c0.equal_range(testSize * 2);

		if (std_c0_ret.first == std_c0.end())
			testBool(ft_c0_ret.first == ft_c0.end(), __FILE__, __LINE__);
		if (std_c0_ret.second == std_c0.end())
			testBool(ft_c0_ret.second == ft_c0.end(), __FILE__, __LINE__);
		if (ft_c0_ret.first != ft_c0.end())
			testBool(*(ft_c0_ret.first)== *(std_c0_ret.first), __FILE__, __LINE__);
		if (ft_c0_ret.second != ft_c0.end())
			testBool(*(ft_c0_ret.second)== *(std_c0_ret.second), __FILE__, __LINE__);

		std::cout << HEADER_TITLE << "[ Test equal_range with a value absent from the set (lower than the lowest key)]" << RESET_COLOR << std::endl;
		std_c0_ret = std_c0.equal_range(-42);
		ft_c0_ret = ft_c0.equal_range(-42);

		if (std_c0_ret.first == std_c0.end())
			testBool(ft_c0_ret.first == ft_c0.end(), __FILE__, __LINE__);
		if (std_c0_ret.second == std_c0.end())
			testBool(ft_c0_ret.second == ft_c0.end(), __FILE__, __LINE__);
		if (ft_c0_ret.first != ft_c0.end())
			testBool(*(ft_c0_ret.first)== *(std_c0_ret.first), __FILE__, __LINE__);
		if (ft_c0_ret.second != ft_c0.end())
			testBool(*(ft_c0_ret.second)== *(std_c0_ret.second), __FILE__, __LINE__);

		std::cout << HEADER_TITLE << "[ Test equal_range with empty set ]" << RESET_COLOR << std::endl;
		ft_c0.clear();
		std_c0.clear();
		testSet(ft_c0, std_c0, NOPRINT);

		std_c0_ret = std_c0.equal_range(42);
		ft_c0_ret = ft_c0.equal_range(42);

		if (std_c0_ret.first == std_c0.end())
			testBool(ft_c0_ret.first == ft_c0.end(), __FILE__, __LINE__);
		if (std_c0_ret.second == std_c0.end())
			testBool(ft_c0_ret.second == ft_c0.end(), __FILE__, __LINE__);
		if (ft_c0_ret.first != ft_c0.end())
			testBool(*(ft_c0_ret.first)== *(std_c0_ret.first), __FILE__, __LINE__);
		if (ft_c0_ret.second != ft_c0.end())
			testBool(*(ft_c0_ret.second)== *(std_c0_ret.second), __FILE__, __LINE__);
	}
	return (0);
}
