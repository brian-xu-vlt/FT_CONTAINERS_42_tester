/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_relational_operators.cpp               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:52:07 by bvalette          #+#    #+#             */
/*   Updated: 2021/05/18 09:50:28 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_vector.hpp"

int
test_vector_relational_operators( void )	{
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with int ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		std::cout << SUBTITLE << "[ Preliminary test on parameters ]" << RESET_COLOR << std::endl;

		std::vector<float> std_a;
		std_a.push_back(10);
		std_a.push_back(20);
		std_a.push_back(30);
		std::vector<float> std_b;
		std_b.push_back(10.42f);
		std_b.push_back(20);
		std_b.push_back(30.33f);

		testBool(std_a != std_b, __LINE__);

		std::cout << SUBTITLE << "[ Same values, same calls for ft ]" << RESET_COLOR << std::endl;

		ft::vector<float> ft_a;
		ft_a.push_back(10);
		ft_a.push_back(20);
		ft_a.push_back(30);
		ft::vector<float> ft_b;
		ft_b.push_back(10.42f);
		ft_b.push_back(20);
		ft_b.push_back(30.33f);

		testBool(ft_a != ft_b, __LINE__);
	}
	{
		std::cout << SUBTITLE << "[ Batch 1: All relational called for std ]" << RESET_COLOR << std::endl;
		std::vector<int> std_a;
		std_a.push_back(10);
		std_a.push_back(20);
		std_a.push_back(30);
		std::vector<int> std_b;
		std_b.push_back(10);
		std_b.push_back(20);
		std_b.push_back(30);
		std::vector<int> std_c;
		std_c.push_back(30);
		std_c.push_back(20);
		std_c.push_back(10);

		testBool(std_a == std_b, __LINE__);
		testBool(std_b != std_c, __LINE__);
		testBool(std_b < std_c, __LINE__);
		testBool(std_c > std_b, __LINE__);
		testBool(std_a <= std_b, __LINE__);
		testBool(std_a >= std_b, __LINE__);

		std::cout << SUBTITLE << "[ Same values, same calls for ft ]" << RESET_COLOR << std::endl;

		ft::vector<int> ft_a;
		ft_a.push_back(10);
		ft_a.push_back(20);
		ft_a.push_back(30);
		ft::vector<int> ft_b;
		ft_b.push_back(10);
		ft_b.push_back(20);
		ft_b.push_back(30);
		ft::vector<int> ft_c;
		ft_c.push_back(30);
		ft_c.push_back(20);
		ft_c.push_back(10);

		testBool(ft_a == ft_b, __LINE__);
		testBool(ft_b != ft_c, __LINE__);
		testBool(ft_b < ft_c, __LINE__);
		testBool(ft_c > ft_b, __LINE__);
		testBool(ft_a <= ft_b, __LINE__);
		testBool(ft_a >= ft_b, __LINE__);
	}
	{
		std::cout << SUBTITLE << "[ Batch 2: All relational called for std ]" << RESET_COLOR << std::endl;
		std::vector<int> std_a;
		std_a.push_back(10);
		std_a.push_back(20);
		std_a.push_back(30);
		std::vector<int> std_b;
		std_b.push_back(10);
		std_b.push_back(20);
		std_b.push_back(20);
		std_b.push_back(30);
		std::vector<int> std_c;
		std_c.push_back(30);
		std_c.push_back(20);
		std_c.push_back(10);

		testBool(!(std_a == std_b), __LINE__);
		testBool(std_b != std_c, __LINE__);
		testBool(std_b < std_c, __LINE__);
		testBool(std_c > std_b, __LINE__);
		testBool(!(std_a <= std_b), __LINE__);
		testBool(std_a >= std_b, __LINE__);

		std::cout << SUBTITLE << "[ Same values, same calls for ft ]" << RESET_COLOR << std::endl;

		ft::vector<int> ft_a;
		ft_a.push_back(10);
		ft_a.push_back(20);
		ft_a.push_back(30);
		ft::vector<int> ft_b;
		ft_b.push_back(10);
		ft_b.push_back(20);
		ft_b.push_back(20);
		ft_b.push_back(30);
		ft::vector<int> ft_c;
		ft_c.push_back(30);
		ft_c.push_back(20);
		ft_c.push_back(10);

		testBool(!(ft_a == ft_b), __LINE__);
		testBool(ft_b != ft_c, __LINE__);
		testBool(ft_b < ft_c, __LINE__);
		testBool(ft_c > ft_b, __LINE__);
		testBool(!(ft_a <= ft_b), __LINE__);
		testBool(ft_a >= ft_b, __LINE__);
	}
	{
		std::cout << SUBTITLE << "[ Batch 3: All relational called for std ]" << RESET_COLOR << std::endl;
		std::vector<int> std_a;
		std_a.push_back(10);
		std_a.push_back(20);
		std_a.push_back(30);
		std::vector<int> std_b;
		std_b.push_back(10);
		std_b.push_back(20);
		std_b.push_back(30);
		std_b.push_back(30);
		std::vector<int> std_c;

		testBool((std_a != std_b), __LINE__);
		testBool(std_b != std_c, __LINE__);
		testBool(!(std_b < std_c), __LINE__);
		testBool(!(std_c > std_b), __LINE__);
		testBool((std_a <= std_b), __LINE__);
		testBool(std_a < std_b, __LINE__);

		std::cout << SUBTITLE << "[ Same values, same calls for ft ]" << RESET_COLOR << std::endl;

		ft::vector<int> ft_a;
		ft_a.push_back(10);
		ft_a.push_back(20);
		ft_a.push_back(30);
		ft::vector<int> ft_b;
		ft_b.push_back(10);
		ft_b.push_back(20);
		ft_b.push_back(30);
		ft_b.push_back(30);
		ft::vector<int> ft_c;

		testBool((ft_a != ft_b), __LINE__);
		testBool(ft_b != ft_c, __LINE__);
		testBool(!(ft_b < ft_c), __LINE__);
		testBool(!(ft_c > ft_b), __LINE__);
		testBool((ft_a <= ft_b), __LINE__);
		testBool(ft_a < ft_b, __LINE__);
	}
	return(0);
}
