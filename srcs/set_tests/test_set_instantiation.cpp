/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_instantiation.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:50:31 by bvalette          #+#    #+#             */
/*   Updated: 2021/02/20 12:17:25 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_set.hpp"
# include "./tester/exampleClass.hpp"
# include "./tester/compClass.hpp"

int
test_set_instantiation( void )	{

	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	std::cout << TITLE << "~~~~ To see constructor calls, compile with " << RESET_COLOR << "-> make debug_mode=1 re f "<< std::endl;

	{
		std::cout << SUBTITLE << "[ DEFAULT CONSTRUCTOR ]" << RESET_COLOR << std::endl;
		{
			ft::set< float>		ft_c0;
			std::set< float>	std_c0;

			testSet< float>(ft_c0, std_c0, NOPRINT);

			ft::set< int>		ft_c1;
			std::set< int>	std_c1;

			testSet< int>(ft_c1, std_c1, NOPRINT);
		}

		std::set< int>	std_first;
		std_first.insert(10);
		std_first.insert(30);
		std_first.insert(50);
		std_first.insert(70);

		ft::set< int>	ft_first;
		ft_first.insert(10);
		ft_first.insert(30);
		ft_first.insert(50);
		ft_first.insert(70);


		std::cout << SUBTITLE << "[ RANGE CONSTRUCTOR ]" << RESET_COLOR << std::endl;
		{
			ft::set< int>		ft_c0(ft_first.begin(), ft_first.end());
			std::set< int>		std_c0(std_first.begin(), std_first.end());
			testSet< int>(ft_c0, std_c0, NOPRINT);
		}
		std::cout << SUBTITLE << "[ COPY CONSTRUCTOR ]" << RESET_COLOR << std::endl;
		{
			ft::set< int>		ft_c0(ft_first);
			std::set< int>		std_c0(std_first);
			testSet< int>(ft_c0, std_c0, NOPRINT);
		}
		std::cout << SUBTITLE << "[ COPY CONSTRUCTOR with specific Compare function]" << RESET_COLOR << std::endl;
		{
			std::set< int, std::greater<char> >	std_first_greater;
			std_first_greater.insert(10);
			std_first_greater.insert(30);
			std_first_greater.insert(50);
			std_first_greater.insert(70);

			ft::set< int, std::greater<char> >	ft_first_greater;
			ft_first_greater.insert(10);
			ft_first_greater.insert(30);
			ft_first_greater.insert(50);
			ft_first_greater.insert(70);

			std::set< int, std::greater<char> >	std_c0(std_first_greater);
			ft::set< int,  std::greater<char> >	ft_c0(ft_first_greater);

			testSet< int, std::greater<char> >(ft_c0, std_c0, NOPRINT);
		}
		std::cout << SUBTITLE << "[ COPY CONSTRUCTOR with Custom compare class]" << RESET_COLOR << std::endl;
		{

			std::set< int, compClass>	std_first_greater;
			std_first_greater.insert(10);
			std_first_greater.insert(30);
			std_first_greater.insert(50);
			std_first_greater.insert(70);

			ft::set< int, compClass>	ft_first_greater;
			ft_first_greater.insert(10);
			ft_first_greater.insert(30);
			ft_first_greater.insert(50);
			ft_first_greater.insert(70);

			std::set< int, compClass >	std_c0(std_first_greater);
			ft::set< int,  compClass >	ft_c0(ft_first_greater);

			testSet< int, compClass >(ft_c0, std_c0, NOPRINT);
		}
		std::cout << SUBTITLE << "[ CONSTRUCTOR WITH CUSTOM CLASS ]" << RESET_COLOR << std::endl;
		{
			std::set<exampleClass>	std_c0;
			ft::set<exampleClass>	ft_c0;

			for (size_t i = 0; i < 10; i++)	{
				int ran = rand() % 10000;
				std_c0.insert(exampleClass(ran + i));
				ft_c0.insert(exampleClass(ran + i));
			}
			testSet< exampleClass>(ft_c0, std_c0, NOPRINT);
		}
	}
	return (0);
}
