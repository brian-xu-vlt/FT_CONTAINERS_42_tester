/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_key_compare_value_compare.cpp             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:46:24 by bvalette          #+#    #+#             */
/*   Updated: 2021/07/02 15:03:15 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_set.hpp"
# include "./tester/exampleClass.hpp"

template< typename T>
static void
test_value_compare(ft::set<T>& ft_c0, std::set<T>& std_c0)	{

	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	T	std_highest = *(--std_c0.end());  	// key value of last element
	T	ft_highest = *(--ft_c0.end());    	// key value of last element

	std::cout << HEADER_TITLE << "[ Go though set while using value_comp() to check cursor value against the highest value ]" << RESET_COLOR << std::endl;
	std::set<int>::iterator		std_it = std_c0.begin();
	ft::set<int>::iterator		ft_it = ft_c0.begin();
	do {
		testBool(std_c0.value_comp()(*std_it++, std_highest) == true
				&& ft_c0.value_comp()(*ft_it++, ft_highest) == true, __FILE__, __LINE__);
	} while ( std_it != --std_c0.end() && ft_it != --ft_c0.end());
	testBool((std_c0.value_comp()(*std_it++, std_highest) == false)
			&& (ft_c0.value_comp()(*ft_it++, ft_highest) == false), __FILE__, __LINE__);
	testBool((std_c0.value_comp()((*std_it), (*std_it--)) == false
			&& ft_c0.value_comp()((*ft_it), (*ft_it--)) == false), __FILE__, __LINE__);
}

template< typename T>
static void
test_key_compare(ft::set<T>& ft_c0, std::set<T>& std_c0)	{

	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	typename std::set<T>::key_compare std_cmp = std_c0.key_comp();
	typename ft::set<T>::key_compare ft_cmp = ft_c0.key_comp();

T std_highest = *(--std_c0.end());  	// key value of last element
	T ft_highest = *(--ft_c0.end());    	// key value of last element

	std::cout << HEADER_TITLE << "[ Go though set while using key_comp() to check cursor value against the highest value ]" << RESET_COLOR << std::endl;
	std::set<int>::iterator std_it = std_c0.begin();
	ft::set<int>::iterator ft_it = ft_c0.begin();
	do {
		testBool(std_cmp((*std_it++), std_highest) == true
				&& ft_cmp((*ft_it++), ft_highest) == true, __FILE__, __LINE__);
	} while ( std_it != --std_c0.end() && ft_it != --ft_c0.end());
	testBool((std_cmp((*std_it++), std_highest) == false)
			&& (ft_cmp((*ft_it++), ft_highest) == false), __FILE__, __LINE__);
	testBool((std_cmp((*std_it), (*std_it--)) == false)
			&& (ft_cmp((*ft_it), (*ft_it--)) == false), __FILE__, __LINE__);
}

int
test_set_key_compare_value_compare()	{

	std::set<int> std_c0;
	ft::set<int> ft_c0;

	std::cout << HEADER_TITLE << "[ Instanciate a set with 3 values (incremental both key and value) ]" << RESET_COLOR << std::endl;
	std_c0.insert(100);
	ft_c0.insert(100);
	std_c0.insert(101);
	ft_c0.insert(101);
	std_c0.insert(200);
	ft_c0.insert(200);
	std_c0.insert(300);
	ft_c0.insert(300);
	std_c0.insert(400);
	ft_c0.insert(400);
	std_c0.insert(500);
	ft_c0.insert(500);
	std_c0.insert(600);
	ft_c0.insert(600);
	std_c0.insert(700);
	ft_c0.insert(700);

	test_value_compare<int>(ft_c0, std_c0);
	test_key_compare<int>(ft_c0, std_c0);

	return (0);
}
