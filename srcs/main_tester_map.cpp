/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tester_map.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:23:15 by bvalette          #+#    #+#             */
/*   Updated: 2021/06/08 17:12:56 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_map.hpp"

int
main_tester_map( void )	{

	std::cout << std::endl << std::endl;
	std::cout << MAIN_TITLE << " CONTAINER TESTER ============= " << __func__ << RESET_COLOR << std::endl;

	try {

		test_map_instantiation();
		test_map_insert_erase();
		test_map_capacities();
		test_map_iterator();
		test_map_at_operatorBrackets();
		test_map_swap();
		test_map_clear();
		test_key_compare_value_compare();
		test_map_operatorEqual();
		test_map_find();
		test_map_count();

		test_map_lower_bound();
		test_map_upper_bound();
		test_map_equal_range();
		test_map_reverseIterator();

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
