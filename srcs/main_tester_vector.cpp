/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tester_vector.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:23:15 by bvalette          #+#    #+#             */
/*   Updated: 2021/06/08 17:12:56 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_vector.hpp"

int
main_tester_vector( void )	{

	std::cout << std::endl << std::endl;
	std::cout << MAIN_TITLE << " CONTAINER TESTER ============= " << __func__ << RESET_COLOR << std::endl;

	try {

		test_vector_instantiation();
		test_vector_iterator();
		test_vector_reverseIterator();
		test_vector_capacities();
		test_vector_resize();
		test_vector_insert_erase();
		test_vector_push_back_pop_back();
		test_vector_assign();
		test_vector_clear();
		test_vector_at_operatorBrackets();
		test_vector_element_access();
		test_vector_member_swap();
		test_vector_nonmember_swap();
		test_vector_relational_operators();
		test_vector_operatorEqual();

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
