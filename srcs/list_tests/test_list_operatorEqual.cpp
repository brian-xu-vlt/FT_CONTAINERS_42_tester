/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_operatorEqual.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:02:01 by bvalette          #+#    #+#             */
/*   Updated: 2021/05/31 11:59:02 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_list.hpp"

int
test_list_operatorEqual( void )	{

	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with std::string ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		ft::list<std::string>	ftl0(10, "hello");
		std::list<std::string>	stdl0(10, "hello");
		ft::list<std::string>	ftl1(5, "byee");
		std::list<std::string>	stdl1(5, "byee");

		std::cout << SUBTITLE << "[ Instanciate list 0 with 10 \"hello\" and list 1 with 5 \"byeee\" ]" << RESET_COLOR << std::endl;
		testList(ftl0, stdl0, NOPRINT);
		testList(ftl1, stdl1, NOPRINT);

		std::cout << SUBTITLE << "[ list0=list1 ]" << RESET_COLOR << std::endl;

		ftl0 = ftl1;
		stdl0 = stdl1;

		testList(ftl0, stdl0, NOPRINT);
		testList(ftl1, stdl1, NOPRINT);

		std::cout << SUBTITLE << "[ list0=list0 ]" << RESET_COLOR << std::endl;
		ftl0 = ftl0;
		stdl0 = stdl0;
		testList(ftl0, stdl0, NOPRINT);
	}
	return (0);
}
