/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tester_deque.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:43:21 by bvalette          #+#    #+#             */
/*   Updated: 2021/06/08 17:12:56 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_deque.hpp"

int
main_tester_deque( void )	{

	std::cout << std::endl << std::endl;
	std::cout << MAIN_TITLE << " CONTAINER TESTER ============= " << __func__ << RESET_COLOR << std::endl;

	try {

		test_deque_instantiation();
		test_deque_insert_erase();
		test_deque_clear();
		test_deque_assign();
		test_deque_iterator();
		test_deque_reverseIterator();
		test_deque_capacities();
		test_deque_resize();
		test_deque_at_operatorBrackets();
		test_deque_element_access();
		test_deque_member_swap();
		test_deque_nonmember_swap();
		test_deque_relational_operators();
		test_deque_operatorEqual();
		test_deque_push_pop();

		if (DEBUG_MODE == 0)
		{
			std::cout << SUBTITLE << "For :" << __func__ <<", ALL TESTS PASSED ~~~~~~> " << RESET_COLOR;
			std::cout << BLINK << "\t \xF0\x9F\x8E\x89 \xF0\x9F\x8E\x8A" << RESET_COLOR << std::endl;
			std::cout << BLINK << "                         " << "\t \xF0\x9F\x8E\x89 \xF0\x9F\x8E\x8A" << RESET_COLOR << std::endl;
			std::cout << BLINK << "                         " << "\t \xF0\x9F\x8E\x89 \xF0\x9F\x8E\x8A" << RESET_COLOR << std::endl;
		}
	}
	catch ( failedTest & )	{
		std::cout << ERROR_TITLE << "SOME TEST FAILED !! \t \xE2\x9D\x8C" << RESET_COLOR << std::endl;
		throw failedTest();
		return (1);
	}
	catch ( std::exception & e )	{
		std::cout << ERROR_TITLE << "Got exception: " << e.what() << RESET_COLOR << std::endl;
		throw std::exception();
		return (1);
	}
	return (0);
}
