/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:23:24 by bvalette          #+#    #+#             */
/*   Updated: 2021/07/02 11:19:52 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Compilation may change DEBUG_MODE setting to
 *
 * 	DEBUG_MODE=0 -> no special output
 * 	DEBUG_MODE=1 -> continue after test a failed (abort otherwise)
 * 				 	+ minimal informations (mainly constructor/destructor calls)
 * 	DEBUG_MODE=2 -> more indepth infos
*/

# include "./tester/bvaletteTester_list.hpp"
# include "./tester/bvaletteTester_vector.hpp"
# include "./tester/bvaletteTester_map.hpp"

# include "./tester/bvaletteTester_deque.hpp"
# include "./tester/bvaletteTester_stack.hpp"
# include "./tester/bvaletteTester_queue.hpp"
# include "./tester/bvaletteTester_set.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

bool checkArgs(std::string av, const std::string *containers, size_t nb_containers)	{

	for (size_t i = 0; i < nb_containers ; i++)	{
		if (av == containers[i])
			return true;
	}
	return false;
}

int main ( int ac, char** av )	{

	size_t const 	nb_tests = 7;
	std::string const	containers[7] = {"vector", "list", "map", "set", "deque", "stack", "queue"};
	int				(*tester[7])() = {&main_tester_vector, &main_tester_list,
		&main_tester_map, &main_tester_set, &main_tester_deque, &main_tester_stack, &main_tester_queue};

	try {

		if (ac == 1)	{

			for (size_t i = 0; i < nb_tests; i++)	{
				tester[i]();
			}

			std::cout << SUBTITLE << " For ALL CONTAINERS, ALL TESTS PASSED ~~~~~~> " << RESET_COLOR;
			std::cout << BLINK << "\t \xF0\x9F\x8E\x89 \xF0\x9F\x8E\x8A" << RESET_COLOR << std::endl;
			std::cout << BLINK << "                         " << "\t \xF0\x9F\x8E\x89 \xF0\x9F\x8E\x8A" << RESET_COLOR << std::endl;
			std::cout << BLINK << "                         " << "\t \xF0\x9F\x8E\x89 \xF0\x9F\x8E\x8A" << RESET_COLOR << std::endl;

		}
		else	{

			if (ac > 2 || checkArgs(std::string(av[1]), containers, nb_tests) == false) {
				std::cout << "This tester takes no argument to test every container, or one argument to test a specific container. " << std::endl;
				std::cout << "Containers avaiblable: " << std::endl;
				for (size_t i = 0; i < (sizeof(containers) / sizeof(std::string)); i++)
					std::cout << "\t * " << containers[i] << std::endl;
				return (1);
			}
			for (size_t i = 0; i < nb_tests; i++)	{
				if (std::string(av[1]) == containers[i])	{
					tester[i]();
				}
			}
		}

	}
	catch ( failedTest & )	{
		std::cout << ERROR_TITLE << "SOME TEST FAILED !! \t \xE2\x9D\x8C" << RESET_COLOR << std::endl;
		return (1);
	}
	catch ( std::exception & e )	{
		std::cout << ERROR_TITLE << "Got exception: " << e.what() << RESET_COLOR << std::endl;
		return (1);
	}
	return (0);
}
