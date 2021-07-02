/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_deque_assign.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:48:00 by bvalette          #+#    #+#             */
/*   Updated: 2021/05/31 10:25:55 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_deque.hpp"

void
testAssign(ft::deque<int> & ft_c0, std::deque<int> & std_c0, size_t n, int val)	{

		std::cout << SUBTITLE << "[ assign "<< n <<" elements of value "<< val <<" ]" << RESET_COLOR << std::endl;
		ft_c0.assign(n, val);
		std_c0.assign(n, val);
		testDeque(ft_c0, std_c0, NOPRINT);
}

void
testAssign(ft::deque<int> & ft_c0, std::deque<int> & std_c0,
	ft::deque<int>::iterator ft_it, ft::deque<int>::iterator ft_ite,
	std::deque<int>::iterator std_it, std::deque<int>::iterator std_ite){

		std::cout << SUBTITLE << "[ assign with iterators ]" << RESET_COLOR << std::endl;
		ft_c0.assign(ft_it, ft_ite);
		std_c0.assign(std_it, std_ite);
		testDeque(ft_c0, std_c0, NOPRINT);
}

int
test_deque_assign( void )	{
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with ints ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		std::cout << HEADER_TITLE << "[ Instanciate deque of 3 elements value -1 ]" << RESET_COLOR << std::endl;
		ft::deque<int>		ft_c0(3, -1);
		std::deque<int>	std_c0(3, -1);
		testDeque(ft_c0, std_c0, NOPRINT);

		testAssign(ft_c0, std_c0, 5, 42);
		testAssign(ft_c0, std_c0, 1,100);
		testAssign(ft_c0, std_c0, 100,1);
		testAssign(ft_c0, std_c0, 0, 42);
		ft_c0.clear();
		std_c0.clear();

		testAssign(ft_c0, std_c0, 100,1);


		ft::deque<int>		ft_c1(10, -1);
		std::deque<int>		std_c1(10, -1);
		ft_c1.insert(ft_c1.begin(), 111);
		std_c1.insert(std_c1.begin(), 111);
		ft_c1.push_back(99);
		std_c1.push_back(99);

		testDeque(ft_c1, std_c1, NOPRINT);
		testAssign(ft_c0, std_c0, ft_c1.end(), ft_c1.end(), std_c1.end(), std_c1.end());
		testDeque(ft_c1, std_c1, NOPRINT);
		testAssign(ft_c0, std_c0, --ft_c1.end(), ft_c1.end(), --std_c1.end(), std_c1.end());
		testDeque(ft_c1, std_c1, NOPRINT);
		testAssign(ft_c0, std_c0, ft_c1.begin()+ 2, --ft_c1.end(), std_c1.begin() + 2, --std_c1.end());
		testDeque(ft_c1, std_c1, NOPRINT);
		testAssign(ft_c0, std_c0, ft_c1.begin(), ft_c1.end(), std_c1.begin(), std_c1.end());
		testDeque(ft_c1, std_c1, NOPRINT);
		testAssign(ft_c0, std_c0, ft_c1.begin(), ft_c1.begin(), std_c1.begin(), std_c1.begin());
		testDeque(ft_c1, std_c1, NOPRINT);
	}
	return (0);
}
