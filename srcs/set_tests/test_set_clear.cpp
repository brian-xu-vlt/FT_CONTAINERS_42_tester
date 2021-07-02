/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_clear.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:49:36 by bvalette          #+#    #+#             */
/*   Updated: 2021/02/22 14:25:58 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_set.hpp"
# include "./tester/exampleClass.hpp"

int
test_set_clear( void )	{
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with floats ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		int test_size = 1000;
		std::cout << HEADER_TITLE << "[ Test clear function with set of " << test_size << " int key ]" << RESET_COLOR << std::endl;

		std::vector<exampleClass>	ft_val_0(test_size);
		std::vector<exampleClass>	std_val_0(test_size);
		for (int i = 0; i < test_size; i++)	{
			srand(i);
			int val = rand() % test_size;
			ft_val_0[i] = val;
			std_val_0[i] = val;
		}

		std::set<exampleClass>	std_c0(std_val_0.begin(), std_val_0.end());
		ft::set<exampleClass>	ft_c0(ft_val_0.begin(), ft_val_0.end());
		testSet(ft_c0, std_c0, NOPRINT);
		ft_c0.clear();
		std_c0.clear();
		testSet(ft_c0, std_c0, NOPRINT);
		std::cout << HEADER_TITLE << "[ Test insert values after call to clear() ]" << RESET_COLOR << std::endl;
		ft_c0.insert(21);
		ft_c0.insert(42);
		std_c0.insert(21);
		std_c0.insert(42);
		testSet(ft_c0, std_c0, NOPRINT);
	}
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with floats ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		std::cout << HEADER_TITLE << "[ test clear function with empty set ]" << RESET_COLOR << std::endl;
		ft::set<int> ft_c0;
		std::set<int> std_c0;

		testSet(ft_c0, std_c0, NOPRINT);
		ft_c0.clear();
		std_c0.clear();
		testSet(ft_c0, std_c0, NOPRINT);
		std::cout << HEADER_TITLE << "[ Test insert values after call to clear() ]" << RESET_COLOR << std::endl;
		ft_c0.insert(21);
		ft_c0.insert(42);
		std_c0.insert(21);
		std_c0.insert(42);
		testSet(ft_c0, std_c0, NOPRINT);
	}
	return (0);
}
