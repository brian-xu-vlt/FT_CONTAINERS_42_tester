/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_capacities.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:48:58 by bvalette          #+#    #+#             */
/*   Updated: 2021/05/31 14:53:09 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/exampleClass.hpp"
# include "./tester/bvaletteTester_vector.hpp"

template < typename T>
void
test_max_size()	{
	std::vector<T>		std_c0;
	ft::vector<T>		ft_c0;
	testBool(std_c0.max_size() == ft_c0.max_size(), __LINE__);
}

int
test_vector_capacities( void )	{

	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " ~~~~~~~~~~~" << RESET_COLOR << std::endl;

	{
		size_t		testSize = 0;
		std::cout << HEADER_TITLE << "[ Empty() on vector with " << testSize << " elements ]" << RESET_COLOR << std::endl;
		std::vector<int>	std(testSize);
		ft::vector<int>		ft(testSize);

		std::cout << "empty for std : " << std::boolalpha << std.empty() << std::endl;
		std::cout << "empty for ft  : " << std::boolalpha << ft.empty() << std::endl;

		testBool(std.empty() == ft.empty(), __LINE__);
	}
	{
		size_t		testSize = 5;
		std::cout << HEADER_TITLE << "[ Size and capacity on vector with " << testSize << " elements ]" << RESET_COLOR << std::endl;
		std::vector<int>	std(testSize);
		ft::vector<int>		ft(testSize);

		std::cout << "Size of std : " << std.size() << std::endl;
		std::cout << "Size of ft  : " << ft.size() << std::endl;

		testBool(std.size() == ft.size(), __LINE__);
		testBool(std.capacity() >= std.size() && ft.capacity() >= ft.size(), __LINE__);

		std::cout << "empty for std : " << std::boolalpha << std.empty() << std::endl;
		std::cout << "empty for ft  : " << std::boolalpha << ft.empty() << std::endl;

		testBool(std.empty() == ft.empty(), __LINE__);
	}
	{
		size_t		testSize = 0;
		std::cout << HEADER_TITLE << "[ max_size for a vector of " << testSize << " elements ]" << RESET_COLOR << std::endl;
		std::vector<float>		std(testSize);
		ft::vector<float>		ft(testSize);
		std::cout << "max_size for std : " << std.max_size() << std::endl;
		std::cout << "max_size for ft  : " << ft.max_size() << std::endl;
		testBool(std.max_size() == ft.max_size(), __LINE__);

	}
	// ------------ bool specialization not tested
	// {
	// 	size_t		testSize = 0;
	// 	std::cout << SUBTITLE << "[ max_size for a vector of " << testSize << " elements ]" << RESET_COLOR << std::endl;
	// 	std::vector<bool>	std(testSize);
	// 	ft::vector<bool>		ft(testSize);
	// 	std::cout << "Bool ft: " << ft.max_size() << std::endl;
	// 	std::cout << "Bool std:" << std.max_size() << std::endl;
	// 	testBool(std.max_size() == ft.max_size(), __LINE__);
	// 	std::cout << "bool : max_size for std : " << std.max_size() << std::endl;
	// 	std::cout << "bool : max_size for ft  : " << ft.max_size() << std::endl;

	// }

	std::cout << HEADER_TITLE << "[ Max Size with various types ]" << RESET_COLOR << std::endl;
	test_max_size<short>();
	test_max_size<char>();
	test_max_size<int>();
	test_max_size<float>();
	test_max_size<double>();
	test_max_size<std::string>();
	test_max_size<exampleClass>();
	return (0);
}
