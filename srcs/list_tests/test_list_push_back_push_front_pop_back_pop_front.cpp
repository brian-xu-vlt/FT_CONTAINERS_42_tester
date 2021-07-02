/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_push_back_push_front_pop_back_pop        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:02:04 by bvalette          #+#    #+#             */
/*   Updated: 2021/05/31 15:02:58 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_list.hpp"

int
test_list_push_back_push_front_pop_back_pop_front( void )	{

	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with std::string ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		ft::list<std::string>	ftl0;
		std::list<std::string>	stdl0;

		std::cout << SUBTITLE << "[ Insert with insert(iterator, size_t, value_type) ]" << RESET_COLOR << std::endl;
		ftl0.push_front("the Begining...");
		ftl0.push_back("the End...");
		ftl0.push_back("the End...2");

		stdl0.push_front("the Begining...");
		stdl0.push_back("the End...");
		stdl0.push_back("the End...2");

		testList(ftl0, stdl0, NOPRINT);

		ftl0.pop_front();
		ftl0.pop_back();
		stdl0.pop_front();
		stdl0.pop_back();
		testList(ftl0, stdl0, NOPRINT);

		ftl0.pop_front();
		stdl0.pop_front();
		testList(ftl0, stdl0, NOPRINT);
		ftl0.push_front("coucou");
		stdl0.push_front("coucou");
		testList(ftl0, stdl0, NOPRINT);
		ftl0.pop_back();
		stdl0.pop_back();
		testList(ftl0, stdl0, NOPRINT);

	}
	return (0);
}
