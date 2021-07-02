/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_key_compare_value_compare.cpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:46:24 by bvalette          #+#    #+#             */
/*   Updated: 2021/07/02 14:50:29 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_map.hpp"
# include "./tester/exampleClass.hpp"

template< typename Key, typename T>
void
test_value_compare(ft::map<Key, T>& ft_c0, std::map<Key, T>& std_c0)	{

	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	std::pair<Key, T>	std_highest = *(--std_c0.end());  	// key value of last element
	ft::pair<Key, T>	ft_highest = *(--ft_c0.end());    	// key value of last element

	std::cout << HEADER_TITLE << "[ Go though map while using value_comp() to check cursor value against the highest value ]" << RESET_COLOR << std::endl;
	std::map<char,int>::iterator	std_it = std_c0.begin();
	ft::map<char,int>::iterator		ft_it = ft_c0.begin();
	do {
		testBool(std_c0.value_comp()(*std_it++,  std_highest) == true
				&& ft_c0.value_comp()(*ft_it++, ft_highest) == true,__FILE__, __LINE__);
	} while ( std_it != --std_c0.end() && ft_it != --ft_c0.end());
	testBool((std_c0.value_comp()(*std_it++,  std_highest) == false)
			&& (ft_c0.value_comp()(*ft_it++, ft_highest) == false),__FILE__, __LINE__);
	testBool((std_c0.value_comp()((*std_it),  (*std_it--)) == false
			&& ft_c0.value_comp()((*ft_it), (*ft_it--)) == false),__FILE__, __LINE__);
}

template< typename Key, typename T>
void
test_key_compare(ft::map<Key, T>& ft_c0, std::map<Key, T>& std_c0)	{

	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	typename std::map<Key, T>::key_compare std_cmp = std_c0.key_comp();
	typename std::map<Key, T>::key_compare ft_cmp = ft_c0.key_comp();

	char std_highest = (--std_c0.end())->first;  	// key value of last element
	char ft_highest = (--ft_c0.end())->first;    	// key value of last element

	std::cout << HEADER_TITLE << "[ Go though map while using key_comp() to check cursor value against the highest value ]" << RESET_COLOR << std::endl;
	std::map<char,int>::iterator std_it = std_c0.begin();
	ft::map<char,int>::iterator ft_it = ft_c0.begin();
	do {
		testBool(std_cmp((*std_it++).first,  std_highest) == true
				&& ft_cmp((*ft_it++).first, ft_highest) == true,__FILE__, __LINE__);
	} while ( std_it != --std_c0.end() && ft_it != --ft_c0.end());
	testBool((std_cmp((*std_it++).first,  std_highest) == false)
			&& (ft_cmp((*ft_it++).first, ft_highest) == false),__FILE__, __LINE__);
	testBool((std_cmp((*std_it).first,  (*std_it--).first) == false)
			&& (ft_cmp((*ft_it).first, (*ft_it--).first) == false),__FILE__, __LINE__);
}

int
test_key_compare_value_compare()	{

	std::map<char,int> std_c0;
	ft::map<char,int> ft_c0;

	std::cout << HEADER_TITLE << "[ Instanciate a map with 3 values (incremental both key and value) ]" << RESET_COLOR << std::endl;
	std_c0['a'] = ft_c0['a'] = 100;
	std_c0['b'] = ft_c0['b'] = 101;
	std_c0['c'] = ft_c0['c'] = 200;
	std_c0['d'] = ft_c0['d'] = 300;
	std_c0['e'] = ft_c0['e'] = 400;
	std_c0['f'] = ft_c0['f'] = 500;
	std_c0['g'] = ft_c0['g'] = 600;
	std_c0['h'] = ft_c0['h'] = 700;

	test_value_compare<char, int>(ft_c0, std_c0);
	test_key_compare<char, int>(ft_c0, std_c0);

	return (0);
}
