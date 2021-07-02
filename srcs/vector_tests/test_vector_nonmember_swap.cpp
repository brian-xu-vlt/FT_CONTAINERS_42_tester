/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_nonmember_swap.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:52:27 by bvalette          #+#    #+#             */
/*   Updated: 2021/07/02 14:32:43 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_vector.hpp"

int
test_vector_nonmember_swap( void )	{
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with ints ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		std::cout << SUBTITLE << "[ Instanciate vector0 of 3 elements value -1 ]" << RESET_COLOR << std::endl;
		ft::vector<int>		ft_c0(3, -1);
		std::vector<int>	std_c0(3, -1);
		testVector(ft_c0, std_c0, NOPRINT);


		std::cout << SUBTITLE << "[ Instanciate vector1 of 3 elements value 42 + push front 0 + push back 99 ]" << RESET_COLOR << std::endl;
		ft::vector<int>	ft_c1(3, 42);
		std::vector<int>	std_c1(3, 42);
		ft_c1.insert(ft_c1.begin(), 0);
		std_c1.insert(std_c1.begin(), 0);
		ft_c1.push_back(99);
		std_c1.push_back(99);
		testVector(ft_c1, std_c1, NOPRINT);

		ft::vector<int>::iterator		ft_it0 = ft_c0.begin();
		ft::vector<int>::iterator		ft_it1 = ft_c1.begin();
		std::vector<int>::iterator		std_it0 = std_c0.begin();
		std::vector<int>::iterator		std_it1 = std_c1.begin();

		std::cout << SUBTITLE << "[ swap 2 vectors ]" << RESET_COLOR << std::endl;
		ft::swap(ft_c0, ft_c1);
		std::swap(std_c0, std_c1);
		testVector(ft_c0, std_c0, NOPRINT, "Test vector0");
		testVector(ft_c1, std_c1, NOPRINT, "Test vector1");

		std::cout << SUBTITLE << "[ test if iterator stayed valid while pointing to new values ]" << RESET_COLOR << std::endl;
		testBool(&(*ft_it0) == &(*ft_c1.begin()), __FILE__, __LINE__);
		testBool(&(*ft_it1) == &(*ft_c0.begin()), __FILE__, __LINE__);
		testBool(&(*std_it0) == &(*std_c1.begin()), __FILE__, __LINE__);
		testBool(&(*std_it1) == &(*std_c0.begin()), __FILE__, __LINE__);

		std::cout << SUBTITLE << "[ assign vector 1 with 10 value 99 ]" << RESET_COLOR << std::endl;
		ft_c1.assign(10, 99);
		std_c1.assign(10, 99);
		testVector(ft_c1, std_c1, NOPRINT);
		std::cout << SUBTITLE << "[ swap 2 vectors ]" << RESET_COLOR << std::endl;
		ft::swap(ft_c0, ft_c1);
		std::swap(std_c0, std_c1);
		testVector(ft_c0, std_c0, NOPRINT, "Test vector0");
		testVector(ft_c1, std_c1, NOPRINT, "Test vector1");


		std::cout << SUBTITLE << "[ assign vector 1 with 10 value 99 ]" << RESET_COLOR << std::endl;
		ft_c1.assign(10, 99);
		std_c1.assign(10, 99);
		testVector(ft_c1, std_c1, NOPRINT);
		std::cout << SUBTITLE << "[ swap 2 vectors ]" << RESET_COLOR << std::endl;
		ft::swap(ft_c0, ft_c1);
		std::swap(std_c0, std_c1);
		testVector(ft_c0, std_c0, NOPRINT, "Test vector0");
		testVector(ft_c1, std_c1, NOPRINT, "Test vector1");

		std::cout << SUBTITLE << "[ clear vector0 ]" << RESET_COLOR << std::endl;
		ft_c0.clear();
		std_c0.clear();
		testVector(ft_c0, std_c0, NOPRINT);
		std::cout << SUBTITLE << "[ swap 2 vectors ]" << RESET_COLOR << std::endl;
		ft::swap(ft_c0, ft_c1);
		std::swap(std_c0, std_c1);
		testVector(ft_c0, std_c0, NOPRINT, "Test vector0");
		testVector(ft_c1, std_c1, NOPRINT, "Test vector1");

		std::cout << SUBTITLE << "[ call swap with the same object ]" << RESET_COLOR << std::endl;
		ft::swap(ft_c0, ft_c0);
		std::swap(std_c0, std_c0);
		testVector(ft_c0, std_c0, NOPRINT, "Test vector0");
		ft::swap(ft_c1, ft_c1);
		std::swap(std_c1, std_c1);
		testVector(ft_c1, std_c1, NOPRINT, "Test vector1");
	}
	return (0);
}
