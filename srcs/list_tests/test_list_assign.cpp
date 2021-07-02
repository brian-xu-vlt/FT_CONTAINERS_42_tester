/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_assign.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:53:56 by bvalette          #+#    #+#             */
/*   Updated: 2021/05/31 14:59:34 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_list.hpp"


void
testAssign(ft::list<int> & ft_c0, std::list<int> & std_c0, size_t n, int val)	{

		std::cout << SUBTITLE << "[ assign "<< n <<" elements of value "<< val <<" ]" << RESET_COLOR << std::endl;
		ft_c0.assign(n, val);
		std_c0.assign(n, val);
		testList(ft_c0, std_c0, NOPRINT);
}

void
testAssign(ft::list<int> & ft_c0, std::list<int> & std_c0,
	ft::list<int>::iterator ft_it, ft::list<int>::iterator ft_ite,
	std::list<int>::iterator std_it, std::list<int>::iterator std_ite){

		std::cout << SUBTITLE << "[ assign with iterators ]" << RESET_COLOR << std::endl;
		ft_c0.assign(ft_it, ft_ite);
		std_c0.assign(std_it, std_ite);
		testList(ft_c0, std_c0, NOPRINT);
}

int
test_list_assign( void )	{
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with ints ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		std::cout << HEADER_TITLE << "[ Instanciate list of 3 elements value -1 ]" << RESET_COLOR << std::endl;
		ft::list<int>		ft_c0(3, -1);
		std::list<int>	std_c0(3, -1);
		testList(ft_c0, std_c0, NOPRINT);

		testAssign(ft_c0, std_c0, 5, 42);
		testAssign(ft_c0, std_c0, ft_c0.size() + 1, 99);
		testAssign(ft_c0, std_c0, 1,100);
		testAssign(ft_c0, std_c0, 100,1);
		testAssign(ft_c0, std_c0, 0, 42);

		ft_c0.clear();
		std_c0.clear();

		testAssign(ft_c0, std_c0, 100,1);


		ft::list<int>		ft_c1(10, -1);
		std::list<int>	std_c1(10, -1);
		ft_c1.insert(ft_c1.begin(), 111);
		std_c1.insert(std_c1.begin(), 111);
		ft_c1.push_back(99);
		std_c1.push_back(99);

		testList(ft_c1, std_c1, NOPRINT);
		testAssign(ft_c0, std_c0, ft_c1.end(), ft_c1.end(), std_c1.end(), std_c1.end());
		testList(ft_c1, std_c1, NOPRINT);
		testAssign(ft_c0, std_c0, --ft_c1.end(), ft_c1.end(), --std_c1.end(), std_c1.end());
		testList(ft_c1, std_c1, NOPRINT);
		testAssign(ft_c0, std_c0, ft_c1.begin()++, --ft_c1.end(), std_c1.begin()++, --std_c1.end());
		testList(ft_c1, std_c1, NOPRINT);
		testAssign(ft_c0, std_c0, ft_c1.begin(), ft_c1.end(), std_c1.begin(), std_c1.end());
		testList(ft_c1, std_c1, NOPRINT);
		testAssign(ft_c0, std_c0, ft_c1.begin(), ft_c1.begin(), std_c1.begin(), std_c1.begin());
		testList(ft_c1, std_c1, NOPRINT);
	}
	return (0);
}
