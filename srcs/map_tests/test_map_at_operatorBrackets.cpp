/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_at_operatorBrackets.cpp                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:51:35 by bvalette          #+#    #+#             */
/*   Updated: 2021/02/22 15:36:06 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_map.hpp"
# include "./tester/exampleClass.hpp"


void
test_basic_brackets()	{

		std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " ~~~~~~~~~~~" << RESET_COLOR << std::endl;
		std::map<int, exampleClass>		std_c0;
		ft::map<int, exampleClass>		ft_c0;

		testBool(ft_c0[42] == std_c0[42], __FILE__, __LINE__);
		ft_c0[42] = 21;
		std_c0[42] = 21;
		testBool(ft_c0[42] == std_c0[42], __FILE__, __LINE__);
		ft_c0[42] = 1;
		std_c0[42] = 1;
		testBool(ft_c0[42] == std_c0[42], __FILE__, __LINE__);
		ft_c0[42];
		std_c0[42];
		testBool(ft_c0[42] == std_c0[42], __FILE__, __LINE__);
		ft_c0[-42];
		std_c0[-42];
		testBool(ft_c0[-42] == std_c0[-42], __FILE__, __LINE__);
}

template<typename T_FT, typename T_STD>
void
test_brackets(void)	{
	{
		std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " ~~~~~~~~~~~" << RESET_COLOR << std::endl;
		T_FT		ft_c0;
		T_STD		std_c0;

		srand(reinterpret_cast<long unsigned int>(&std_c0));
		size_t	testSize = 20 + rand() % 10000;
		std::cout << HEADER_TITLE << " Insert "<< testSize;
		std::cout << " random key values in a map with eighter incremental mapped value or no value set, the same key value will be tested more than one time " << RESET_COLOR << std::endl;

		int		val;
		std::vector<int>	testValues;
		testValues.reserve(testSize);
		for (size_t i = 1; i < testSize; i++)	{
			val = rand()%4200;
			testValues.push_back(val);
			if (i % 2 == 0)	{
				ft_c0[val];
				std_c0[val];
			}
			else	{
				ft_c0[val] = i;
				std_c0[val] = i;
			}
		}
		testMap(ft_c0, std_c0, NOPRINT);

		bool	success = true;
		std::cout << SUBTITLE << " Going though the whole map, one operator[] call at the time " << RESET_COLOR << std::endl;
		std::vector<int>::iterator it = testValues.begin();
		std::vector<int>::iterator ite = testValues.end();
		for (int i = 0; it != ite && success == true; i++, it++)	{
			success = (ft_c0[*it] == std_c0[*it]);
		}
		testBool(success, __FILE__, __LINE__);
	}
}


int
test_map_at_operatorBrackets( void )	{

	test_basic_brackets();
	test_brackets<ft::map<int, int>, std::map<int, int> >();
	test_brackets<ft::map<int, exampleClass>, std::map<int, exampleClass> >();
	return (0);
}

