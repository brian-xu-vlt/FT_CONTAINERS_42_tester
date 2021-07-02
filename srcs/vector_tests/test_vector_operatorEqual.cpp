/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_operatorEqual.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:52:23 by bvalette          #+#    #+#             */
/*   Updated: 2021/05/31 10:54:14 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_vector.hpp"

int
test_vector_operatorEqual( void )	{

	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with std::string ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		ft::vector<std::string>	ft_c0(10, "hello");
		std::vector<std::string>	std_c0(10, "hello");
		ft::vector<std::string>	ft_c1(5, "byee");
		std::vector<std::string>	std_c1(5, "byee");

		std::cout << SUBTITLE << "[ Instanciate vector 0 with 10 \"hello\" and vector 1 with 5 \"byeee\" ]" << RESET_COLOR << std::endl;
		testVector(ft_c0, std_c0, NOPRINT);
		testVector(ft_c1, std_c1, NOPRINT);

		std::cout << SUBTITLE << "[ vector0=vector1 ]" << RESET_COLOR << std::endl;

		ft_c0 = ft_c1;
		std_c0 = std_c1;

		testVector(ft_c0, std_c0, NOPRINT);
		testVector(ft_c1, std_c1, NOPRINT);

		std::cout << SUBTITLE << "[ vector0=vector0 ! same object ]" << RESET_COLOR << std::endl;
		ft_c0 = ft_c0;
		std_c0 = std_c0;

		testVector(ft_c0, std_c0, NOPRINT);
	}
	return (0);
}
