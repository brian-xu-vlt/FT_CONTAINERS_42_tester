/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_resize.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:02:19 by bvalette          #+#    #+#             */
/*   Updated: 2021/05/31 15:25:04 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/exampleClass.hpp"
# include "./tester/bvaletteTester_list.hpp"

int
test_list_resize( void )	{
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with ints ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		std::cout << SUBTITLE << "[ Instanciate list of 3 elements with no value ]" << RESET_COLOR << std::endl;
		ft::list<exampleClass>	ftl0(3);
		std::list<exampleClass>	stdl0(3);
		testList(ftl0, stdl0, NOPRINT);
		std::cout << SUBTITLE << "[ resize to same size with no value ]" << RESET_COLOR << std::endl;
		ftl0.resize(3);
		stdl0.resize(3);
		testList(ftl0, stdl0, NOPRINT);
		std::cout << SUBTITLE << "[ resize to 5 with no value ]" << RESET_COLOR << std::endl;
		ftl0.resize(5);
		stdl0.resize(5);
		testList(ftl0, stdl0, NOPRINT);
		std::cout << SUBTITLE << "[ resize to 7 with value 42 ]" << RESET_COLOR << std::endl;
		ftl0.resize(7, 42);
		stdl0.resize(7, 42);
		testList(ftl0, stdl0, NOPRINT);
		std::cout << SUBTITLE << "[ resize to 0 with value 42 ]" << RESET_COLOR << std::endl;
		ftl0.resize(0, 42);
		stdl0.resize(0, 42);
		testList(ftl0, stdl0, NOPRINT);
		std::cout << SUBTITLE << "[ push back 999 and push front 111 ]" << RESET_COLOR << std::endl;
		ftl0.push_back(999);
		stdl0.push_back(999);
		ftl0.push_front(111);
		stdl0.push_front(111);
		testList(ftl0, stdl0, NOPRINT);
		std::cout << SUBTITLE << "[ resize to 3 with value 42 ]" << RESET_COLOR << std::endl;
		ftl0.resize(3, 42);
		stdl0.resize(3, 42);
		testList(ftl0, stdl0, NOPRINT);
		std::cout << SUBTITLE << "[ resize to 4 with value 42 ]" << RESET_COLOR << std::endl;
		ftl0.resize(4, 42);
		stdl0.resize(4, 42);
		testList(ftl0, stdl0, NOPRINT);
		std::cout << SUBTITLE << "[ resize to 4 with value 99 ]" << RESET_COLOR << std::endl;
		ftl0.resize(4, 99);
		stdl0.resize(4, 99);
		testList(ftl0, stdl0, NOPRINT);
		std::cout << SUBTITLE << "[ resize to 0 with no value ]" << RESET_COLOR << std::endl;
		ftl0.resize(0);
		stdl0.resize(0);
		testList(ftl0, stdl0, NOPRINT);
	}
	return (0);
}
