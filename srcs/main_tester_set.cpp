/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tester_set.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:23:15 by bvalette          #+#    #+#             */
/*   Updated: 2021/06/09 17:48:59 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_set.hpp"

int
main_tester_set( void )	{

	std::cout << std::endl << std::endl;
	std::cout << MAIN_TITLE << " CONTAINER TESTER ============= " << __func__ << RESET_COLOR << std::endl;

	try {

		test_set_instantiation();
		test_set_insert_erase();
		test_set_capacities();
		test_set_iterator();
		test_set_swap();
		test_set_clear();
		test_set_key_compare_value_compare();
		test_set_operatorEqual();
		test_set_find();
		test_set_count();
		test_set_lower_bound();
		test_set_upper_bound();
		test_set_equal_range();
		test_set_reverseIterator();

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
