/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tester_deque.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:43:21 by bvalette          #+#    #+#             */
/*   Updated: 2021/07/02 14:13:35 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_deque.hpp"

int
main( void )	{

	std::cout << std::endl << std::endl;
	std::cout << MAIN_TITLE << " CONTAINER TESTER ============= " << __func__ << RESET_COLOR << std::endl;
	bool error_flag = false;
	try {

		try { test_deque_instantiation(); } 			catch(std::exception &e) 		{ error_flag = true;}
		try { test_deque_insert_erase(); } 			catch(std::exception &e) 		{ error_flag = true;}
		try { test_deque_clear(); } 			catch(std::exception &e) 		{ error_flag = true;}
		try { test_deque_assign(); } 			catch(std::exception &e) 		{ error_flag = true;}
		try { test_deque_iterator(); } 			catch(std::exception &e) 		{ error_flag = true;}
		try { test_deque_reverseIterator(); } 			catch(std::exception &e) 		{ error_flag = true;}
		try { test_deque_capacities(); } 			catch(std::exception &e) 		{ error_flag = true;}
		try { test_deque_resize(); } 			catch(std::exception &e) 		{ error_flag = true;}
		try { test_deque_at_operatorBrackets(); } 			catch(std::exception &e) 		{ error_flag = true;}
		try { test_deque_element_access(); } 			catch(std::exception &e) 		{ error_flag = true;}
		try { test_deque_member_swap(); } 			catch(std::exception &e) 		{ error_flag = true;}
		try { test_deque_nonmember_swap(); } 			catch(std::exception &e) 		{ error_flag = true;}
		try { test_deque_relational_operators(); } 			catch(std::exception &e) 		{ error_flag = true;}
		try { test_deque_operatorEqual(); } 			catch(std::exception &e) 		{ error_flag = true;}
		try { test_deque_push_pop(); } 			catch(std::exception &e) 		{ error_flag = true;}

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
		return (1);
	}
	catch ( std::exception & e )	{
		std::cout << ERROR_TITLE << "Got exception: " << e.what() << RESET_COLOR << std::endl;
		throw std::exception();
		return (1);
	}
	return (0);
}
