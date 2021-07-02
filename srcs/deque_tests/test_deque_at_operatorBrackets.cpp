/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_deque_at_operatorBrackets.cpp                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:51:35 by bvalette          #+#    #+#             */
/*   Updated: 2021/05/31 11:15:05 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_deque.hpp"

void
test_constAt(ft::deque<int> const & ft_c0, std::deque<int> const & std_c0) {

		std::cout << SUBTITLE << " Calling const version of functions at and operator[] " << RESET_COLOR << std::endl;
		const int & constVal_std = std_c0.at(1);
		const int & constVal_ft = ft_c0.at(1); 				//  !!!! ---> HINT:  IN CASE OF COMPILER ISSUE: const version is MISSING !
		testBool(constVal_std == constVal_ft, __FILE__, __LINE__);
		testBool( ft_c0[1] == std_c0[1], __FILE__, __LINE__);	//  !!!! ---> HINT:  IN CASE OF COMPILER ISSUE: const version is MISSING !
}

int
test_deque_at_operatorBrackets( void )	{
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with ints ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		ft::deque<int>			ft_c0;
		std::deque<int>		std_c0;


		srand(reinterpret_cast<long unsigned int>(&std_c0));
		size_t	testSize = 20 + rand() % 10000;
		std::cout << HEADER_TITLE << "Instanciate deque with "<< testSize << " values, a random number of random valueS " << RESET_COLOR << std::endl;

		int		val;

		for (size_t i = 1; i < testSize; i++)	{
			val = rand();
			ft_c0.push_back(val);
			std_c0.push_back(val);
		}
		testDeque(ft_c0, std_c0, NOPRINT);

		bool	success = true;
		std::cout << SUBTITLE << " Going though the whole deque, one at function call at the time " << RESET_COLOR << std::endl;
		for (size_t i = 0; i < testSize - 1 ; i++)	{
			if (ft_c0.at(i) != std_c0.at(i))
			 	success = testBool(false, __FILE__, __LINE__, i);
		}
		testBool(success, __FILE__, __LINE__);

		if (VALGRIND_MODE != true)	{
			try {
				try { std_c0.at(testSize); } catch (std::out_of_range & e) {};
				ft_c0.at(testSize);
				std::cout << "No exception thrown ! Bad, it should have !! " << std::endl;
				testBool(false, __FILE__, __LINE__);
			}
			catch ( std::out_of_range & e)	{
				std::cout << "Catched exception, as  it should, Out of Range : " << e.what() << std::endl;
				testBool(true, __FILE__, __LINE__);
			}
		}

		success = true;
		std::cout << SUBTITLE << " Going though the whole deque, with operator[]" << RESET_COLOR << std::endl;
		for (size_t i = 0; i < testSize - 1 ; i++)	{
			if (ft_c0[i] != std_c0[i])
			 	success = testBool(false, __FILE__, __LINE__, i);
		}
		testBool(success, __FILE__, __LINE__);

		test_constAt(ft_c0, std_c0);

		std::cout << SUBTITLE << " Changing value at index with operator[]" << RESET_COLOR << std::endl;
		for (size_t i = 0; i < testSize - 1 ; i++)	{
			ft_c0[i] = i + 42;
			std_c0[i] = i + 42;
		}
		testDeque(ft_c0, std_c0, NOPRINT);
	}
	return (0);
}

