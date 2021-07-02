/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_deque_instantiation.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:50:31 by bvalette          #+#    #+#             */
/*   Updated: 2021/07/02 15:13:52 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_deque.hpp"
# include "./tester/exampleClass.hpp"

int
test_deque_instantiation( void )	{

	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	std::cout << TITLE << "~~~~ To see constructor calls, compile with " << RESET_COLOR << "-> make debug_mode=1 re f "<< std::endl;
	{
		std::cout << SUBTITLE << "[ DEFAULT CONSTRUCTOR ]" << RESET_COLOR << std::endl;
		{
			ft::deque<std::string>		ft_c0;
			std::deque<std::string>	std_c0;
			testDeque(ft_c0, std_c0, NOPRINT);
			ft::deque<float>	ft_c1;
			std::deque<float>	std_c1;
			testDeque(ft_c1, std_c1, NOPRINT);
		}
		std::cout << SUBTITLE << "[ FILL CONSTRUCTOR with value ]" << RESET_COLOR << std::endl;
		{
			ft::deque<int>	ft_c0(5, 123);
			std::deque<int>	std_c0(5, 123);
			testDeque(ft_c0, std_c0, NOPRINT);
		}
		std::cout << SUBTITLE << "[ FILL CONSTRUCTOR with value explicitly casted ]" << RESET_COLOR << std::endl;
		{
			ft::deque<int>	ft_c0(static_cast<size_t>(5),123);
			std::deque<int>	std_c0(static_cast<size_t>(5),123);
			testDeque(ft_c0, std_c0, NOPRINT);
		}
		std::cout << SUBTITLE << "[ FILL CONSTRUCTOR without value ]" << RESET_COLOR << std::endl;
		{
			ft::deque<int>	ft_c0(5);
			std::deque<int>	std_c0(5);
			testDeque(ft_c0, std_c0, NOPRINT);
		}
		std::cout << SUBTITLE << "[ FILL CONSTRUCTOR without value and with classExample which has a default value ]" << RESET_COLOR << std::endl;
		{
			ft::deque<exampleClass>	ft_c0(5);
			std::deque<exampleClass>	std_c0(5);
			testDeque(ft_c0, std_c0, NOPRINT);
		}
		std::cout << SUBTITLE << "[ FILL CONSTRUCTOR with larger than max_size n value ]" << RESET_COLOR << std::endl;
		{
			if (VALGRIND_MODE == false)	{
				try { std::deque<int>	std_c0(std::deque<int>().max_size() + 1);	}
				catch(const std::exception& e)	{

					std::cout << "EXCEPTION THROWN BY STD: " << e.what() << std::endl;
				}

				try {
					ft::deque<int>		ft_c0(ft::deque<int>().max_size() + 1);
					std::cout << ERROR_SOURCE << "SHOULD HAVE THROW A BAD ALLOC..." << RESET_COLOR << std::endl;
					testBool(false, __FILE__, __LINE__);
				}
				catch(const std::exception& e)	{
					std::cout << "Exception catched: " << e.what() << " -- ";
					testBool(true);
				}
			}
		}

		std::cout << SUBTITLE << "[ RANGE CONSTRUCTOR test: veque0 with fill and veque1 with range ctor from veque0 iterators ]" << RESET_COLOR << std::endl;
		{
			ft::deque<int>		ft_c0(5, 123);
			std::deque<int>	std_c0(5, 123);
			testDeque(ft_c0, std_c0, NOPRINT);
			std::cout << SUBTITLE << "->>\t\t[ RANGE CONSTRUCTOR with begin and ++begin as argument ]" << RESET_COLOR << std::endl;
			ft::deque<int>		ft_c1(ft_c0.begin(), ++ft_c0.begin());
			std::deque<int>	std_c1(std_c0.begin(), ++std_c0.begin());
			testDeque(ft_c1, std_c1, NOPRINT);

		}
		std::cout << SUBTITLE << "[ COPY CONSTRUCTOR <double> from deque with 5 elements]" << RESET_COLOR << std::endl;
		{
			ft::deque<double>		ft_c0(5, 123);
			std::deque<double>		std_c0(5, 123);
			testDeque(ft_c0, std_c0, NOPRINT);

			ft::deque<double>		ft_c1(ft_c0);
			std::deque<double>		std_c1(std_c0);
			testDeque(ft_c1, std_c1, NOPRINT);

			std::cout << SUBTITLE << "[ check if begin points to a new elements ]" << RESET_COLOR << std::endl;
			testBool(&(*std_c0.begin()) != &(*std_c1.begin())
				&& &(*ft_c0.begin()) != &(*ft_c1.begin()), __FILE__, __LINE__);
		}
		std::cout << SUBTITLE << "[ COPY CONSTRUCTOR from deque with no elements]" << RESET_COLOR << std::endl;
		{
			ft::deque<int>		ft_c0;
			std::deque<int>		std_c0;

			ft::deque<int>		ft_c1(ft_c0);
			std::deque<int>		std_c1(std_c0);
			testDeque(ft_c0, std_c0, NOPRINT);
			testDeque(ft_c1, std_c1, NOPRINT);
		}
		std::cout << SUBTITLE << "[ COPY ASSIGNATION from deque with no elements]" << RESET_COLOR << std::endl;
		{
			ft::deque<int>		ft_c0(42, 100);
			std::deque<int>		std_c0(42, 100);

			std::deque<int>		std_c1 = std_c0;
			ft::deque<int>		ft_c1 = ft_c0;
			testDeque(ft_c0, std_c0, NOPRINT);
			testDeque(ft_c1, std_c1, NOPRINT);
			ft_c1 = ft_c1;
			std_c1 = std_c1;
			testDeque(ft_c0, std_c0, NOPRINT);
			testDeque(ft_c1, std_c1, NOPRINT);
		}
	}
	return (0);
}
