/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_deque_resize.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:51:42 by bvalette          #+#    #+#             */
/*   Updated: 2021/05/31 11:17:17 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/exampleClass.hpp"
# include "./tester/bvaletteTester_deque.hpp"

#define NOVALUE -1

template < typename T >
void
testResize(ft::deque<T> & ft_c0, std::deque<T> & std_c0, size_t testSize, int value = NOVALUE)	 {

		if (value == NOVALUE)
			std::cout << SUBTITLE << "[ resize to " << testSize << " with no value ]" << RESET_COLOR << std::endl;
		else
			std::cout << SUBTITLE << "[ resize to " << testSize << " with value " << value << " ]" << RESET_COLOR << std::endl;

		ft_c0.resize(testSize, value);
		std_c0.resize(testSize, value);
		testDeque(ft_c0, std_c0, NOPRINT);
}

int
test_deque_resize( void )	{
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with ints ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		std::cout << HEADER_TITLE << "[ Resize() ]" << RESET_COLOR << std::endl;
		std::cout << HEADER_TITLE << "[ Instanciate deque<int> of 3 elements with no value ]" << RESET_COLOR << std::endl;
		ft::deque<int>		ft_c0(3);
		std::deque<int>	std_c0(3);
		testDeque(ft_c0, std_c0, NOPRINT);

		testResize<int>(ft_c0, std_c0, 3);
		testResize<int>(ft_c0, std_c0, 5);
		testResize<int>(ft_c0, std_c0, 7);
		std::cout << SUBTITLE << "[ push back 999 ]" << RESET_COLOR << std::endl;
		ft_c0.push_back(999);
		std_c0.push_back(999);
		testDeque(ft_c0, std_c0, NOPRINT);

		testResize<int>(ft_c0, std_c0, 32);
		testResize<int>(ft_c0, std_c0, 3);
		testResize<int>(ft_c0, std_c0, 3, 21);
		testResize<int>(ft_c0, std_c0, 5, 42);
		testResize<int>(ft_c0, std_c0, 7, 42);
		testResize<int>(ft_c0, std_c0, 4, 99);
		testResize<int>(ft_c0, std_c0, 4, 42);
		testResize<int>(ft_c0, std_c0, 4);
		testResize<int>(ft_c0, std_c0, 1000000);
		testResize<int>(ft_c0, std_c0, 0);

		{
			std::cout << HEADER_TITLE << "[ Instanciate deque<exampleClass> of 3 elements with no value ]" << RESET_COLOR << std::endl;
			ft::deque<exampleClass>	ft_c0(3);
			std::deque<exampleClass>	std_c0(3);
			testDeque(ft_c0, std_c0, NOPRINT);
			testResize<exampleClass>(ft_c0, std_c0, 32);
			testResize<exampleClass>(ft_c0, std_c0, 3);
			testResize<exampleClass>(ft_c0, std_c0, 3, 21);
			testResize<exampleClass>(ft_c0, std_c0, 5, 42);
			testResize<exampleClass>(ft_c0, std_c0, 7, 42);
			testResize<exampleClass>(ft_c0, std_c0, 4, 99);
			testResize<exampleClass>(ft_c0, std_c0, 4, 42);
			testResize<exampleClass>(ft_c0, std_c0, 4);
			testResize<exampleClass>(ft_c0, std_c0, 1000000);
			testResize<exampleClass>(ft_c0, std_c0, 0);
		}

		if (VALGRIND_MODE == true)
			return 0 ;

		size_t testResize = std_c0.max_size();
		std::cout << SUBTITLE << "[ resize("<< testResize << ") Max size, will throw exception ]" << RESET_COLOR << std::endl;
		try {
			try { std_c0.resize(testResize); }
				catch ( std::exception & e) {}
				catch ( std::bad_alloc & e) {}
			ft_c0.resize(testResize);
			testBool( false, __FILE__, __LINE__);
		}
		catch (  std::bad_alloc & e )	{
			std::cout << "Exception thrown: std::bad_alloc, as it should." << std::endl;
			testBool( true, __FILE__, __LINE__);
		}
		catch (  std::exception & e )	{
			std::cout << "Exception thrown: std::exception, should be bad_alloc but it's ok..." << std::endl;
			testBool( true, __FILE__, __LINE__);
		}
		catch (  std::length_error & e )	{
			std::cout << "Exception thrown: std::length_error, Wrong !" << std::endl;
			testBool( false, __FILE__, __LINE__);
		}
	}
	return (0);
}
