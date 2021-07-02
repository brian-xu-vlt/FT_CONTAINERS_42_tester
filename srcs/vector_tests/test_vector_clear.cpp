/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_clear.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:49:36 by bvalette          #+#    #+#             */
/*   Updated: 2021/07/02 14:32:43 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_vector.hpp"

int
test_vector_clear( void )	{
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with floats ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		std::cout << HEADER_TITLE << "TEST CLEAR FUNCTION with vector of 1000000 floats" << RESET_COLOR << std::endl;
		ft::vector<float> ft_c0 (1000000, 42.21f);
		std::vector<float> std_c0 (1000000, 42.21f);

		testVector(ft_c0, std_c0, NOPRINT);
		ft_c0.clear();
		std_c0.clear();
		testVector(ft_c0, std_c0, NOPRINT);

		std::cout << HEADER_TITLE << "TEST Clear with forced reallocation by swapping with a default constructed vector" << RESET_COLOR << std::endl;
		ft::vector<float>().swap(ft_c0);
		std::vector<float>().swap(std_c0);
		testVector(ft_c0, std_c0, NOPRINT);
		testBool(ft_c0.capacity() == std_c0.capacity(), __FILE__, __LINE__);
	}
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with floats ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		std::cout << HEADER_TITLE << "TEST CLEAR FUNCTION with empty vector" << RESET_COLOR << std::endl;
		ft::vector<float> ft_c0;
		std::vector<float> std_c0;

		testVector(ft_c0, std_c0, NOPRINT);
		ft_c0.clear();
		std_c0.clear();
		testVector(ft_c0, std_c0, NOPRINT);
	}
	return (0);
}
