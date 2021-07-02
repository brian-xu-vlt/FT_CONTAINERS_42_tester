/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:23:24 by bvalette          #+#    #+#             */
/*   Updated: 2021/07/02 14:05:15 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester.hpp"

bool more_than_100 (const int& value) { return (value>100); }
bool more_than_10 (const int& value) { return (value>10); }
bool less_or_eq_10 (const int& value) { return (value<=10); }
bool smaller_than ( int first, int second)	{ return ( first<second ); }
bool greater_than ( int first, int second)	{ return ( first>second ); }

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

bool	testBool(bool b, int const lineNo, int const loopIter )	{
	if (b == true)
		std::cout << "[ TEST PASSED: no diff ] \t \342\234\205" << std::endl;
	else	{
		std::cout << ERROR_TITLE << "[ FAILURE at line..." << lineNo << "]" << RESET_COLOR << " \t \342\235\214" << std::endl;
		if (loopIter != -1)
			std::cout << ERROR_TITLE << " loop iteration = " << loopIter << "." << RESET_COLOR << " \t \342\235\214" << std::endl;
		if (DEBUG_MODE < 1)
			throw failedTest();
	}
	return (b);
}
