/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_capacities.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 08:43:18 by bvalette          #+#    #+#             */
/*   Updated: 2021/05/31 16:54:32 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/exampleClass.hpp"
# include "./tester/bvaletteTester_list.hpp"

template < typename T>
void
test_max_size()	{
	std::list<T>	std_c0;
	ft::list<T>		ft_c0;
	if (testBool(std_c0.max_size() == ft_c0.max_size(), __LINE__) != true)
		std::cout << ERROR_TITLE << "Sizes returned : ft("<< ft_c0.max_size() <<") std("<< std_c0.max_size() <<")" << RESET_COLOR << std::endl;
}

int
test_list_capacities( void )	{

	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " ~~~~~~~~~~~" << RESET_COLOR << std::endl;

	{
		size_t		testSize = 0;
		std::cout << SUBTITLE << "[ Size on list with " << testSize << " elements ]" << RESET_COLOR << std::endl;
		std::list<int>	std(testSize);
		ft::list<int>	ft(testSize);

		std::cout << "empty for std : " << std::boolalpha << std.empty() << std::endl;
		std::cout << "empty for ft  : " << std::boolalpha << ft.empty() << std::endl;

		testBool(std.empty() == ft.empty(), __LINE__);
	}
	{
		size_t		testSize = 5;
		std::cout << SUBTITLE << "[ Size on list with " << testSize << " elements ]" << RESET_COLOR << std::endl;
		std::list<int>	std(testSize);
		ft::list<int>	ft(testSize);

		std::cout << "Size of std : " << std.size() << std::endl;
		std::cout << "Size of ft  : " << ft.size() << std::endl;

		testBool(std.size() == ft.size(), __LINE__);

		std::cout << "empty for std : " << std::boolalpha << std.empty() << std::endl;
		std::cout << "empty for ft  : " << std::boolalpha << ft.empty() << std::endl;

		testBool(std.empty() == ft.empty(), __LINE__);
	}
	std::cout << HEADER_TITLE << "[ Max Size with various types ]" << RESET_COLOR << std::endl;
	test_max_size<bool>();
	test_max_size<short>();
	test_max_size<char>();
	test_max_size<int>();
	test_max_size<float>();
	test_max_size<double>();
	test_max_size<std::string>();
	test_max_size<exampleClass>();
	return (0);
}
