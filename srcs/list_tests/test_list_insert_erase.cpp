/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_insert_erase.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:01:21 by bvalette          #+#    #+#             */
/*   Updated: 2021/07/02 14:32:43 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_list.hpp"

int
test_list_insert_erase( void )	{
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with std::string ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		ft::list<std::string>	ftl0;
		std::list<std::string>	stdl0;

		std::string	val("helloworld");

		std::cout << SUBTITLE << "[ Insert with single element insert(iterator, val) and check return iterator ]" << RESET_COLOR << std::endl;
		testBool( *(ftl0.insert(ftl0.end(), val)) == *(stdl0.insert(stdl0.end(), val)), __FILE__, __LINE__);
		testList(ftl0, stdl0, NOPRINT);
		testBool( *(ftl0.insert(ftl0.begin(), val)) == *(stdl0.insert(stdl0.begin(), val)), __FILE__, __LINE__);
		testList(ftl0, stdl0, NOPRINT);

		std::cout << SUBTITLE << "[ Insert with insert(iterator, size_t, value_type) ]" << RESET_COLOR << std::endl;
		ftl0.insert(ftl0.end(), 5, val);
		ftl0.push_front("the Begining...");
		ftl0.push_back("the End...");

		stdl0.insert(stdl0.end(), 5, val);
		stdl0.push_front("the Begining...");
		stdl0.push_back("the End...");

		testList(ftl0, stdl0, NOPRINT);

		ft::list<std::string>	ftl1;
		std::list<std::string>	stdl1;

		std::cout << SUBTITLE << "[ Insert with insert(iterator, iterator, iterator) ]" << RESET_COLOR << std::endl;
		ftl1.insert(ftl1.begin(), ftl0.begin(), ftl0.end());
		stdl1.insert(stdl1.begin(), stdl0.begin(), stdl0.end());

		testList(ftl1, stdl1, NOPRINT);

		std::cout << SUBTITLE << "[ Erase with erase(iterator) ]" << RESET_COLOR << std::endl;
		for (int i = 0; i < 3; i++)
		{
			std::cout << "return ft = " << &(*ftl1.erase(--ftl1.end())) << std::endl;
			std::cout << "return std= " << &(*stdl1.erase(--stdl1.end())) << std::endl;
		}

		testList(ftl1, stdl1, NOPRINT);
		std::cout << SUBTITLE << "[ Erase with erase(iterator, iterator) ]" << RESET_COLOR << std::endl;
		std::cout << "return ft  = " << &(*ftl1.erase(ftl1.begin(), --ftl1.end())) << std::endl;
		std::cout << "return std = " << &(*stdl1.erase(stdl1.begin(), --stdl1.end())) << std::endl;

		testList(ftl1, stdl1, NOPRINT);
		ftl1.erase(ftl1.begin(), ftl1.end());
		stdl1.erase(stdl1.begin(), stdl1.end());
		testList(ftl1, stdl1, NOPRINT);
	}
	return (0);
}
