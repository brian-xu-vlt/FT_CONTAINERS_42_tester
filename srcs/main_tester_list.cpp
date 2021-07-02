/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tester_list.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:23:15 by bvalette          #+#    #+#             */
/*   Updated: 2021/06/07 12:33:54 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_list.hpp"

int
main_tester_list( void )	{

	std::cout << std::endl << std::endl;
	std::cout << MAIN_TITLE << " CONTAINER TESTER =============> " << __func__ << "  " << RESET_COLOR << std::endl;

	try {

		test_list_instantiation();
		test_list_operatorEqual();

		test_list_iterator();
		test_list_reverseIterator();

		test_list_capacities();
		test_list_element_access();

		test_list_assign();
		test_list_push_back_push_front_pop_back_pop_front();
		test_list_insert_erase();
		test_list_resize();
		test_list_clear();

		test_list_splice();
		test_list_remove();
		test_list_remove_if();
		test_list_unique();
		test_list_merge();
		test_list_sort();
		test_list_reverse();

		test_list_relational_operators();

		test_list_member_swap();
		test_list_nonmember_swap();


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
