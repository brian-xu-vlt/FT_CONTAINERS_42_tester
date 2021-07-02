/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_deque_member_swap.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:52:49 by bvalette          #+#    #+#             */
/*   Updated: 2021/05/31 10:48:59 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_deque.hpp"

int
test_deque_member_swap( void )	{
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with ints ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		std::cout << SUBTITLE << "[ Instanciate deque0 of 3 elements value -1 ]" << RESET_COLOR << std::endl;
		ft::deque<int>	ft_c0(3, -1);
		std::deque<int>	std_c0(3, -1);
		testDeque(ft_c0, std_c0, NOPRINT);

		std::cout << SUBTITLE << "[ Instanciate deque1 of 3 elements value 42 + push front 0 + push back 99 ]" << RESET_COLOR << std::endl;
		ft::deque<int>	ft_c1(3, 42);
		std::deque<int>	std_c1(3, 42);
		ft_c1.insert(ft_c1.begin(), 0);
		std_c1.insert(std_c1.begin(), 0);
		ft_c1.push_back(99);
		std_c1.push_back(99);
		testDeque(ft_c1, std_c1, NOPRINT);

		std::cout << SUBTITLE << "[ instanciate iterator to begin of deque 0 and deque 1 ]" << RESET_COLOR << std::endl;

		ft::deque<int>::iterator		ft_it0 = ft_c0.begin();
		ft::deque<int>::iterator		ft_it1 = ft_c1.begin();
		std::deque<int>::iterator	std_it0 = std_c0.begin();
		std::deque<int>::iterator	std_it1 = std_c1.begin();

		std::cout << SUBTITLE << "[ swap 2 deques ]" << RESET_COLOR << std::endl;
		ft_c0.swap(ft_c1);
		std_c0.swap(std_c1);
		testDeque(ft_c0, std_c0, NOPRINT, "Test deque0");
		testDeque(ft_c1, std_c1, NOPRINT, "Test deque1");

		std::cout << SUBTITLE << "[ test if iterator stayed valid while pointing to new values ]" << RESET_COLOR << std::endl;
		testBool(&(*ft_it0) == &(*ft_c1.begin()), __FILE__, __LINE__);
		testBool(&(*ft_it1) == &(*ft_c0.begin()), __FILE__, __LINE__);
		testBool(&(*std_it0) == &(*std_c1.begin()), __FILE__, __LINE__);
		testBool(&(*std_it1) == &(*std_c0.begin()), __FILE__, __LINE__);

		std::cout << SUBTITLE << "[ assign deque 1 with 10 value 99 ]" << RESET_COLOR << std::endl;
		ft_c1.assign(10, 99);
		std_c1.assign(10, 99);
		testDeque(ft_c1, std_c1, NOPRINT);
		std::cout << SUBTITLE << "[ swap 2 deques ]" << RESET_COLOR << std::endl;
		ft_c0.swap(ft_c1);
		std_c0.swap(std_c1);
		testDeque(ft_c0, std_c0, NOPRINT, "Test deque0");
		testDeque(ft_c1, std_c1, NOPRINT, "Test deque1");


		std::cout << SUBTITLE << "[ assign deque 1 with 10 value 99 ]" << RESET_COLOR << std::endl;
		ft_c1.assign(10, 99);
		std_c1.assign(10, 99);
		testDeque(ft_c1, std_c1, NOPRINT);
		std::cout << SUBTITLE << "[ swap 2 deques ]" << RESET_COLOR << std::endl;
		ft_c0.swap(ft_c1);
		std_c0.swap(std_c1);
		testDeque(ft_c0, std_c0, NOPRINT, "Test deque0");
		testDeque(ft_c1, std_c1, NOPRINT, "Test deque1");

		std::cout << SUBTITLE << "[ clear deque0 ]" << RESET_COLOR << std::endl;
		ft_c0.clear();
		std_c0.clear();
		testDeque(ft_c0, std_c0, NOPRINT);
		std::cout << SUBTITLE << "[ swap 2 deques ]" << RESET_COLOR << std::endl;
		ft_c0.swap(ft_c1);
		std_c0.swap(std_c1);
		testDeque(ft_c0, std_c0, NOPRINT, "Test deque0");
		testDeque(ft_c1, std_c1, NOPRINT, "Test deque1");
		std::cout << SUBTITLE << "[ call swap with the same object ]" << RESET_COLOR << std::endl;
		ft_c0.swap(ft_c0);
		std_c0.swap(std_c0);
		testDeque(ft_c0, std_c0, NOPRINT, "Test deque0");
		ft_c1.swap(ft_c1);
		std_c1.swap(std_c1);
		testDeque(ft_c1, std_c1, NOPRINT, "Test deque1");
	}
	return (0);
}
