/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_count.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:18:28 by bvalette          #+#    #+#             */
/*   Updated: 2021/07/02 14:32:43 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_map.hpp"
# include "./tester/exampleClass.hpp"

int
test_map_count( void )	{
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		int testSize = 1000;
		double findKey = 42;
		std::cout << HEADER_TITLE << "[ Test count function with map of " << testSize << " double key and float mapped value ]" << RESET_COLOR << std::endl;

		std::vector<ft::pair<double, float> >	ft_val_0(testSize);
		std::vector<std::pair<double, float> >	std_val_0(testSize);
		for (int i = 0; i < testSize; i++)	{
			srand(i);
			double val = rand() % testSize;
			if (i == testSize / 2)
				findKey = val;
			ft_val_0[i] = ft::make_pair(val, i);
			std_val_0[i] = std::make_pair(val, i);
		}

		std::map<double, float>	std_c0(std_val_0.begin(), std_val_0.end());
		ft::map<double, float>	ft_c0(ft_val_0.begin(), ft_val_0.end());
		testMap(ft_c0, std_c0, NOPRINT);

		std::cout << HEADER_TITLE << "[ Test count with a value added previously to the map ]" << RESET_COLOR << std::endl;
		size_t	std_c0_ret = std_c0.count(findKey);
		size_t	ft_c0_ret = ft_c0.count(findKey);

		testBool(ft_c0_ret == std_c0_ret, __FILE__, __LINE__);

		std::cout << HEADER_TITLE << "[ Test count with a value absent from the map (higher than the highest key)]" << RESET_COLOR << std::endl;
		std_c0_ret = std_c0.count(testSize * 2);
		ft_c0_ret = ft_c0.count(testSize * 2);

		testBool(ft_c0_ret == std_c0_ret, __FILE__, __LINE__);

		std::cout << HEADER_TITLE << "[ Test count with a value absent from the map (lower than the lowest key)]" << RESET_COLOR << std::endl;
		std_c0_ret = std_c0.count(-42);
		ft_c0_ret = ft_c0.count(-42);

		testBool(ft_c0_ret == std_c0_ret, __FILE__, __LINE__);

		std::cout << HEADER_TITLE << "[ Test count with empty map ]" << RESET_COLOR << std::endl;
		ft_c0.clear();
		std_c0.clear();
		testMap(ft_c0, std_c0, NOPRINT);

		std_c0_ret = std_c0.count(42);
		ft_c0_ret = ft_c0.count(42);

		testBool(ft_c0_ret == std_c0_ret, __FILE__, __LINE__);
	}
	return (0);
}
