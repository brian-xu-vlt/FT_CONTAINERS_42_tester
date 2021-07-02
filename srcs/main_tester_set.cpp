/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tester_set.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:23:15 by bvalette          #+#    #+#             */
/*   Updated: 2021/07/02 14:14:53 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_set.hpp"

int
main( void )	{

	std::cout << std::endl << std::endl;
	std::cout << MAIN_TITLE << " CONTAINER TESTER ============= " << __func__ << RESET_COLOR << std::endl;
	bool error_flag = false;
	try {

		try 	{ test_set_instantiation(); }	catch(std::exception &e) { error_flag = true; }
		try 	{ test_set_insert_erase(); }	catch(std::exception &e) { error_flag = true; }
		try 	{ test_set_capacities(); }	catch(std::exception &e) { error_flag = true; }
		try 	{ test_set_iterator(); }	catch(std::exception &e) { error_flag = true; }
		try 	{ test_set_swap(); }	catch(std::exception &e) { error_flag = true; }
		try 	{ test_set_clear(); }	catch(std::exception &e) { error_flag = true; }
		try 	{ test_set_key_compare_value_compare(); }	catch(std::exception &e) { error_flag = true; }
		try 	{ test_set_operatorEqual(); }	catch(std::exception &e) { error_flag = true; }
		try 	{ test_set_find(); }	catch(std::exception &e) { error_flag = true; }
		try 	{ test_set_count(); }	catch(std::exception &e) { error_flag = true; }
		try 	{ test_set_lower_bound(); }	catch(std::exception &e) { error_flag = true; }
		try 	{ test_set_upper_bound(); }	catch(std::exception &e) { error_flag = true; }
		try 	{ test_set_equal_range(); }	catch(std::exception &e) { error_flag = true; }
		try 	{ test_set_reverseIterator(); }	catch(std::exception &e) { error_flag = true; }

		if (error_flag == true)
			throw failedTest();
		else if (DEBUG_MODE == 0)
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
