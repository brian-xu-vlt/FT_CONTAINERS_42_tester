/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_nonmember_swap.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:01:57 by bvalette          #+#    #+#             */
/*   Updated: 2021/07/02 14:32:43 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_list.hpp"

int
test_list_nonmember_swap( void )	{
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with ints ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		std::cout << SUBTITLE << "[ Instanciate list0 of 3 elements value -1 ]" << RESET_COLOR << std::endl;
		ft::list<int>	ftl0(3, -1);
		std::list<int>	stdl0(3, -1);
		testList(ftl0, stdl0, NOPRINT);


		std::cout << SUBTITLE << "[ Instanciate list1 of 3 elements value 42 + push front 0 + push back 99 ]" << RESET_COLOR << std::endl;
		ft::list<int>	ftl1(3, 42);
		std::list<int>	stdl1(3, 42);
		ftl1.push_front(0);
		stdl1.push_front(0);
		ftl1.push_back(99);
		stdl1.push_back(99);
		testList(ftl1, stdl1, NOPRINT);

		ft::list<int>::iterator		ft_it0 = ftl0.begin();
		ft::list<int>::iterator		ft_it1 = ftl1.begin();
		std::list<int>::iterator	std_it0 = stdl0.begin();
		std::list<int>::iterator	std_it1 = stdl1.begin();

		std::cout << SUBTITLE << "[ swap 2 lists ]" << RESET_COLOR << std::endl;
		ft::swap(ftl0, ftl1);
		std::swap(stdl0, stdl1);
		testList(ftl0, stdl0, NOPRINT, "Test list0");
		testList(ftl1, stdl1, NOPRINT, "Test list1");

		std::cout << SUBTITLE << "[ test if iterator stayed valid while pointing to new values ]" << RESET_COLOR << std::endl;
		testBool(&(*ft_it0) == &(*ftl1.begin()), __FILE__, __LINE__);
		testBool(&(*ft_it1) == &(*ftl0.begin()), __FILE__, __LINE__);
		testBool(&(*std_it0) == &(*stdl1.begin()), __FILE__, __LINE__);
		testBool(&(*std_it1) == &(*stdl0.begin()), __FILE__, __LINE__);

		std::cout << SUBTITLE << "[ assign list 1 with 10 value 99 ]" << RESET_COLOR << std::endl;
		ftl1.assign(10, 99);
		stdl1.assign(10, 99);
		testList(ftl1, stdl1, NOPRINT);
		std::cout << SUBTITLE << "[ swap 2 lists ]" << RESET_COLOR << std::endl;
		ft::swap(ftl0, ftl1);
		std::swap(stdl0, stdl1);
		testList(ftl0, stdl0, NOPRINT, "Test list0");
		testList(ftl1, stdl1, NOPRINT, "Test list1");


		std::cout << SUBTITLE << "[ assign list 1 with 10 value 99 ]" << RESET_COLOR << std::endl;
		ftl1.assign(10, 99);
		stdl1.assign(10, 99);
		testList(ftl1, stdl1, NOPRINT);
		std::cout << SUBTITLE << "[ swap 2 lists ]" << RESET_COLOR << std::endl;
		ft::swap(ftl0, ftl1);
		std::swap(stdl0, stdl1);
		testList(ftl0, stdl0, NOPRINT, "Test list0");
		testList(ftl1, stdl1, NOPRINT, "Test list1");

		std::cout << SUBTITLE << "[ clear list0 ]" << RESET_COLOR << std::endl;
		ftl0.clear();
		stdl0.clear();
		testList(ftl0, stdl0, NOPRINT);
		std::cout << SUBTITLE << "[ swap 2 lists ]" << RESET_COLOR << std::endl;
		ft::swap(ftl0, ftl1);
		std::swap(stdl0, stdl1);
		testList(ftl0, stdl0, NOPRINT, "Test list0");
		testList(ftl1, stdl1, NOPRINT, "Test list1");


	}
	return (0);
}
