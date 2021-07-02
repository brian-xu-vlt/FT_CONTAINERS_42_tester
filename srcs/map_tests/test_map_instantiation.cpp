/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_instantiation.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:50:31 by bvalette          #+#    #+#             */
/*   Updated: 2021/02/20 12:17:25 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_map.hpp"
# include "./tester/exampleClass.hpp"
# include "./tester/compClass.hpp"

int
test_map_instantiation( void )	{

	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	std::cout << TITLE << "~~~~ To see constructor calls, compile with " << RESET_COLOR << "-> make debug_mode=1 re f "<< std::endl;

	{
		std::cout << SUBTITLE << "[ DEFAULT CONSTRUCTOR ]" << RESET_COLOR << std::endl;
		{
			ft::map<std::string, float>		ft_c0;
			std::map<std::string, float>	std_c0;

			testMap<std::string, float>(ft_c0, std_c0, NOPRINT);

			ft::map<float, int>		ft_c1;
			std::map<float, int>	std_c1;

			testMap<float, int>(ft_c1, std_c1, NOPRINT);
		}

		std::map<char, int>	std_first;
		std_first.insert(std::pair<char, int>('a',10));
		std_first.insert(std::pair<char, int>('b',30));
		std_first.insert(std::pair<char, int>('c',50));
		std_first.insert(std::pair<char, int>('d',70));

		ft::map<char, int>	ft_first;
		ft_first.insert(ft::pair<char, int>('a',10));
		ft_first.insert(ft::pair<char, int>('b',30));
		ft_first.insert(ft::pair<char, int>('c',50));
		ft_first.insert(ft::pair<char, int>('d',70));


		std::cout << SUBTITLE << "[ RANGE CONSTRUCTOR ]" << RESET_COLOR << std::endl;
		{
			ft::map<char, int>		ft_c0(ft_first.begin(), ft_first.end());
			std::map<char, int>		std_c0(std_first.begin(), std_first.end());
			testMap<char, int>(ft_c0, std_c0, NOPRINT);
		}
		std::cout << SUBTITLE << "[ COPY CONSTRUCTOR ]" << RESET_COLOR << std::endl;
		{
			ft::map<char, int>		ft_c0(ft_first);
			std::map<char, int>		std_c0(std_first);
			testMap<char, int>(ft_c0, std_c0, NOPRINT);
		}
		std::cout << SUBTITLE << "[ COPY CONSTRUCTOR with specific Compare function]" << RESET_COLOR << std::endl;
		{
			std::map<char, int, std::greater<char> >	std_first_greater;
			std_first_greater.insert(std::pair<char, int>('a',10));
			std_first_greater.insert(std::pair<char, int>('b',30));
			std_first_greater.insert(std::pair<char, int>('c',50));
			std_first_greater.insert(std::pair<char, int>('d',70));

			ft::map<char, int, std::greater<char> >	ft_first_greater;
			ft_first_greater.insert(ft::pair<char, int>('a',10));
			ft_first_greater.insert(ft::pair<char, int>('b',30));
			ft_first_greater.insert(ft::pair<char, int>('c',50));
			ft_first_greater.insert(ft::pair<char, int>('d',70));

			std::map<char, int, std::greater<char> >	std_c0(std_first_greater);
			ft::map<char, int,  std::greater<char> >	ft_c0(ft_first_greater);

			testMap<char, int, std::greater<char> >(ft_c0, std_c0, NOPRINT);
		}
		std::cout << SUBTITLE << "[ COPY CONSTRUCTOR with Custom compare class]" << RESET_COLOR << std::endl;
		{

			std::map<char, int, compClass>	std_first_greater;
			std_first_greater.insert(std::pair<char, int>('a',10));
			std_first_greater.insert(std::pair<char, int>('b',30));
			std_first_greater.insert(std::pair<char, int>('c',50));
			std_first_greater.insert(std::pair<char, int>('d',70));

			ft::map<char, int, compClass>	ft_first_greater;
			ft_first_greater.insert(ft::pair<char, int>('a',10));
			ft_first_greater.insert(ft::pair<char, int>('b',30));
			ft_first_greater.insert(ft::pair<char, int>('c',50));
			ft_first_greater.insert(ft::pair<char, int>('d',70));

			std::map<char, int, compClass >	std_c0(std_first_greater);
			ft::map<char, int,  compClass >	ft_c0(ft_first_greater);

			testMap<char, int, compClass >(ft_c0, std_c0, NOPRINT);
		}
		std::cout << SUBTITLE << "[ CONSTRUCTOR WITH CUSTOM CLASS ]" << RESET_COLOR << std::endl;
		{
			std::map<exampleClass, int>	std_c0;
			ft::map<exampleClass, int>	ft_c0;

			for (size_t i = 0; i < 10; i++)	{
				int ran = rand() % 10000;
				std_c0.insert(std::pair<exampleClass, int>(exampleClass(i + ran), 42));
				ft_c0.insert(ft::pair<exampleClass, int>(exampleClass(i + ran), 42));
			}
			testMap<exampleClass, int>(ft_c0, std_c0, NOPRINT);
		}
	}
	return (0);
}
