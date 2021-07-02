/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_clear.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:49:36 by bvalette          #+#    #+#             */
/*   Updated: 2021/02/22 14:25:58 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_map.hpp"
# include "./tester/exampleClass.hpp"

int
test_map_clear( void )	{
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with floats ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		int test_size = 1000;
		std::cout << HEADER_TITLE << "[ Test clear function with map of " << test_size << " int key and exampleClass mapped value ]" << RESET_COLOR << std::endl;

		std::vector<ft::pair<int, exampleClass> >	ft_val_0(test_size);
		std::vector<std::pair<int, exampleClass> >	std_val_0(test_size);
		for (int i = 0; i < test_size; i++)	{
			srand(i);
			int val = rand() % test_size;
			ft_val_0[i] = ft::make_pair(val, i);
			std_val_0[i] = std::make_pair(val, i);
		}

		std::map<int, exampleClass>	std_c0(std_val_0.begin(), std_val_0.end());
		ft::map<int, exampleClass>	ft_c0(ft_val_0.begin(), ft_val_0.end());
		testMap(ft_c0, std_c0, NOPRINT);
		ft_c0.clear();
		std_c0.clear();
		testMap(ft_c0, std_c0, NOPRINT);
		std::cout << HEADER_TITLE << "[ Test insert values after call to clear() ]" << RESET_COLOR << std::endl;
		ft_c0[42] = 21;
		ft_c0[21] = 42;
		std_c0[42] = 21;
		std_c0[21] = 42;
		testMap(ft_c0, std_c0, NOPRINT);
	}
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with floats ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		std::cout << HEADER_TITLE << "[ test clear function with empty map ]" << RESET_COLOR << std::endl;
		ft::map<float, int> ft_c0;
		std::map<float, int> std_c0;

		testMap(ft_c0, std_c0, NOPRINT);
		ft_c0.clear();
		std_c0.clear();
		testMap(ft_c0, std_c0, NOPRINT);
		std::cout << HEADER_TITLE << "[ Test insert values after call to clear() ]" << RESET_COLOR << std::endl;
		ft_c0[42] = 21;
		ft_c0[21] = 42;
		std_c0[42] = 21;
		std_c0[21] = 42;
		testMap(ft_c0, std_c0, NOPRINT);
	}
	return (0);
}
