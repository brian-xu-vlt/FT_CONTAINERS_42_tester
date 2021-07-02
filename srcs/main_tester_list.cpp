/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tester_list.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:23:15 by bvalette          #+#    #+#             */
/*   Updated: 2021/07/02 14:14:03 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_list.hpp"

int
main( void )	{

	std::cout << std::endl << std::endl;
	std::cout << MAIN_TITLE << " CONTAINER TESTER =============> " << __func__ << "  " << RESET_COLOR << std::endl;
	bool error_flag = false;
	try {

		try {	test_list_instantiation();	}		catch (std::exception &e)	{ error_flag = true; }
		try {	test_list_operatorEqual();	}		catch (std::exception &e)	{ error_flag = true; }
		try {	test_list_iterator();	}		catch (std::exception &e)	{ error_flag = true; }
		try {	test_list_reverseIterator();	}		catch (std::exception &e)	{ error_flag = true; }
		try {	test_list_capacities();	}		catch (std::exception &e)	{ error_flag = true; }
		try {	test_list_element_access();	}		catch (std::exception &e)	{ error_flag = true; }
		try {	test_list_assign();	}		catch (std::exception &e)	{ error_flag = true; }
		try {	test_list_push_back_push_front_pop_back_pop_front();	}		catch (std::exception &e)	{ error_flag = true; }
		try {	test_list_insert_erase();	}		catch (std::exception &e)	{ error_flag = true; }
		try {	test_list_resize();	}		catch (std::exception &e)	{ error_flag = true; }
		try {	test_list_clear();	}		catch (std::exception &e)	{ error_flag = true; }
		try {	test_list_splice();	}		catch (std::exception &e)	{ error_flag = true; }
		try {	test_list_remove();	}		catch (std::exception &e)	{ error_flag = true; }
		try {	test_list_remove_if();	}		catch (std::exception &e)	{ error_flag = true; }
		try {	test_list_unique();	}		catch (std::exception &e)	{ error_flag = true; }
		try {	test_list_merge();	}		catch (std::exception &e)	{ error_flag = true; }
		try {	test_list_sort();	}		catch (std::exception &e)	{ error_flag = true; }
		try {	test_list_reverse();	}		catch (std::exception &e)	{ error_flag = true; }
		try {	test_list_relational_operators();	}		catch (std::exception &e)	{ error_flag = true; }
		try {	test_list_member_swap();	}		catch (std::exception &e)	{ error_flag = true; }
		try {	test_list_nonmember_swap();	}		catch (std::exception &e)	{ error_flag = true; }

		if (error_flag == true)
			throw failedTest();
		else if (DEBUG_MODE == 0)
		{
			std::cout << SUBTITLE << "For :" << __FILE__ <<", ALL TESTS PASSED ~~~~~~> " << RESET_COLOR;
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
