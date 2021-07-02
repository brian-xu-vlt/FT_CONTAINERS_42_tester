/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_instantiation.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:50:31 by bvalette          #+#    #+#             */
/*   Updated: 2021/07/02 14:41:06 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_vector.hpp"
# include "./tester/exampleClass.hpp"

int
test_vector_instantiation( void )	{

	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	std::cout << TITLE << "~~~~ To see constructor calls, compile with " << RESET_COLOR << "-> make debug_mode=1 re f "<< std::endl;
	{
		std::cout << SUBTITLE << "[ DEFAULT CONSTRUCTOR ]" << RESET_COLOR << std::endl;
		{
			ft::vector<std::string>		ft_c0;
			std::vector<std::string>	std_c0;
			testVector(ft_c0, std_c0, NOPRINT);
			ft::vector<float>	ft_c1;
			std::vector<float>	std_c1;
			testVector(ft_c1, std_c1, NOPRINT);
		}
		std::cout << SUBTITLE << "[ FILL CONSTRUCTOR with value ]" << RESET_COLOR << std::endl;
		{
			ft::vector<int>	ft_c0(5, 123);
			std::vector<int>	std_c0(5, 123);
			testVector(ft_c0, std_c0, NOPRINT);
		}
		std::cout << SUBTITLE << "[ FILL CONSTRUCTOR with value explicitly casted ]" << RESET_COLOR << std::endl;
		{
			ft::vector<int>	ft_c0(static_cast<size_t>(5),123);
			std::vector<int>	std_c0(static_cast<size_t>(5),123);
			testVector(ft_c0, std_c0, NOPRINT);
		}
		std::cout << SUBTITLE << "[ FILL CONSTRUCTOR without value ]" << RESET_COLOR << std::endl;
		{
			ft::vector<int>	ft_c0(5);
			std::vector<int>	std_c0(5);
			testVector(ft_c0, std_c0, NOPRINT);
		}
		std::cout << SUBTITLE << "[ FILL CONSTRUCTOR without value and with classExample which has a default value ]" << RESET_COLOR << std::endl;
		{
			ft::vector<exampleClass>	ft_c0(5);
			std::vector<exampleClass>	std_c0(5);
			testVector(ft_c0, std_c0, NOPRINT);
		}
		std::cout << SUBTITLE << "[ FILL CONSTRUCTOR with larger than max_size n value ]" << RESET_COLOR << std::endl;
		{
			try { std::vector<int>	std_c0(std::vector<int>().max_size() + 1);	}
			catch(const std::exception& e)	{}

			try {
				ft::vector<int>		ft_c0(ft::vector<int>().max_size() + 1);
				std::cout << ERROR_SOURCE << "SHOULD HAVE THROW A BAD ALLOC..." << RESET_COLOR << std::endl;
				testBool(false, __FILE__, __LINE__);
			}
			catch(const std::exception& e)	{
				std::cout << "Exception catched: " << e.what() << " -- ";
				testBool(true, __FILE__, __LINE__);
			}
		}
		std::cout << SUBTITLE << "[ RANGE CONSTRUCTOR test: vector0 with fill and vector1 with range ctor from vector0 iterators ]" << RESET_COLOR << std::endl;
		{
			ft::vector<int>		ft_c0(5, 123);
			std::vector<int>	std_c0(5, 123);
			testVector(ft_c0, std_c0, NOPRINT);
			std::cout << SUBTITLE << "->>\t\t[ RANGE CONSTRUCTOR with begin and ++begin as argument ]" << RESET_COLOR << std::endl;
			ft::vector<int>		ft_c1(ft_c0.begin(), ++ft_c0.begin());
			std::vector<int>	std_c1(std_c0.begin(), ++std_c0.begin());
			testVector(ft_c1, std_c1, NOPRINT);

		}
		std::cout << SUBTITLE << "[ COPY CONSTRUCTOR <double> from vector with 5 elements]" << RESET_COLOR << std::endl;
		{
			ft::vector<double>		ft_c0(5, 123);
			std::vector<double>		std_c0(5, 123);
			testVector(ft_c0, std_c0, NOPRINT);

			ft::vector<double>		ft_c1(ft_c0);
			std::vector<double>		std_c1(std_c0);
			testVector(ft_c1, std_c1, NOPRINT);

			std::cout << SUBTITLE << "[ check if begin points to a new elements ]" << RESET_COLOR << std::endl;
			testBool(&(*std_c0.begin()) != &(*std_c1.begin())
				&& &(*ft_c0.begin()) != &(*ft_c1.begin()), __FILE__, __LINE__);
		}
		std::cout << SUBTITLE << "[ COPY CONSTRUCTOR from vector with no elements]" << RESET_COLOR << std::endl;
		{
			ft::vector<int>		ft_c0;
			std::vector<int>	std_c0;

			ft::vector<int>		ft_c1(ft_c0);
			std::vector<int>	std_c1(std_c0);
			testVector(ft_c0, std_c0, NOPRINT);
			testVector(ft_c1, std_c1, NOPRINT);
		}
		std::cout << SUBTITLE << "[ COPY ASSIGNATION from vector with no elements]" << RESET_COLOR << std::endl;
		{
			ft::vector<int>		ft_c0(42, 100);
			std::vector<int>	std_c0(42, 100);

			std::vector<int>	std_c1 = std_c0;
			ft::vector<int>		ft_c1 = ft_c0;
			testVector(ft_c0, std_c0, NOPRINT);
			testVector(ft_c1, std_c1, NOPRINT);
			ft_c1 = ft_c1;
			std_c1 = std_c1;
			testVector(ft_c0, std_c0, NOPRINT);
			testVector(ft_c1, std_c1, NOPRINT);
		}
	}
	return (0);
}
