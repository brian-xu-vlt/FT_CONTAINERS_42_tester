/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_unique.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:02:16 by bvalette          #+#    #+#             */
/*   Updated: 2021/05/31 15:47:17 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_list.hpp"

int
test_list_unique( void )	{
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with doubles ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		ft::list<double>	ftl0;
		std::list<double>	stdl0;
		size_t			valgrind_factor = (VALGRIND_MODE == true) ? 10000 : 1;
		size_t			testSize = 3000000 / valgrind_factor;

		std::cout << SUBTITLE << "[ pushback " << testSize << " random float values in list (same value for ft and std list, 0 <= val < 5) ]" << RESET_COLOR << std::endl;
		srand(reinterpret_cast<long unsigned int>(&stdl0));

		int		divider;
		float	val;
		for (size_t i = 0; i < testSize; i++)	{
			if (i < (testSize / 3) || i > (testSize / 2))	{
				divider = rand() % 5;
				val = static_cast<float>(rand() % 15) / ( (divider == 0) ? i + 1 : divider );
			}
			ftl0.push_back(val);
			stdl0.push_back(val);
		}
		testList(ftl0, stdl0, NOPRINT);

		std::cout << SUBTITLE << "[ unique (1) no arg ]" << RESET_COLOR << std::endl;
		testList(ftl0, stdl0, NOPRINT);
		stdl0.unique();
		ftl0.unique();
		testList(ftl0, stdl0, NOPRINT);

		std::cout << SUBTITLE << "[ unique (2) with binary predicate as boolean function (same_integral_part) ]" << RESET_COLOR << std::endl;
		stdl0.unique(same_integral_part);
		ftl0.unique(same_integral_part);
		testList(ftl0, stdl0, NOPRINT);

		std::cout << SUBTITLE << "[ unique (2) with binary predicate as a structure (is_near()) ]" << RESET_COLOR << std::endl;
		stdl0.unique(is_near());
		ftl0.unique(is_near());
		testList(ftl0, stdl0, NOPRINT);
	}
	return (0);
}
