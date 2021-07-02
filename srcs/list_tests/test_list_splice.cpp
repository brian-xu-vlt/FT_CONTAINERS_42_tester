/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_splice.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:02:32 by bvalette          #+#    #+#             */
/*   Updated: 2021/07/02 14:32:43 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_list.hpp"

int
test_list_splice( void )	{
	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with int ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		std::cout << HEADER_TITLE << "[ list 0 with 8 values '0', list 1 with 8 values '1' ]" << RESET_COLOR << std::endl;

		ft::list<int>	ftl0(8, 0);
		ft::list<int>	ftl1(8, 1);
		std::list<int>	stdl0(8, 0);
		std::list<int>	stdl1(8, 1);

		testList(ftl0, stdl0,  NOPRINT);
		testList(ftl1, stdl1,  NOPRINT);

		std::cout << SUBTITLE << "[ splice (entire list (1)) entire list 0 to begining of list 1 ]" << RESET_COLOR << std::endl;
		ftl1.splice(ftl1.begin(), ftl0);
		stdl1.splice(stdl1.begin(), stdl0);
		testList(ftl0, stdl0,  NOPRINT);
		testList(ftl1, stdl1,  NOPRINT);
		std::cout << SUBTITLE << "[ splice (entire list (1)) entire list 1 to end of list 0 ]" << RESET_COLOR << std::endl;
		ftl0.splice(ftl0.end(), ftl1);
		stdl0.splice(stdl0.end(), stdl1);
		testList(ftl0, stdl0,  NOPRINT);
		testList(ftl1, stdl1,  NOPRINT);

		std::cout << SUBTITLE << "[ instanciate new empty list 3 and splice (entire list (1)) entire list 0 to end of list 3 ]" << RESET_COLOR << std::endl;
		ft::list<int>	ftl3;
		std::list<int>	stdl3;
		ftl3.splice(ftl3.end(), ftl0);
		stdl3.splice(stdl3.end(), stdl0);
		testList(ftl0, stdl0,  NOPRINT);
		testList(ftl1, stdl1,  NOPRINT);
		testList(ftl3, stdl3,  NOPRINT);
	}
	{
		std::cout << HEADER_TITLE << "[ list 0 with 5 HelloWorld, list 1 with 5 Bye! ]" << RESET_COLOR << std::endl;

		ft::list<std::string>	ftl0(5, "HelloWorld!");
		ft::list<std::string>	ftl1(5, "bye!");
		std::list<std::string>	stdl0(5, "HelloWorld!");
		std::list<std::string>	stdl1(5, "bye!");

		testList(ftl0, stdl0, NOPRINT);
		testList(ftl1, stdl1, NOPRINT);
		std::cout << SUBTITLE << "[ splice (single element(2) version):transfer second element of list 0 to the first position of list 1 ]" << RESET_COLOR << std::endl;
		ft::list<std::string>::iterator		ft_itl0 = ++ftl0.begin();
		std::list<std::string>::iterator	std_itl0 = ++stdl0.begin();

		void * ft_ptr_splicedElem = &(*ft_itl0);
		void * std_ptr_splicedElem = &(*std_itl0);

		ftl1.splice(ftl1.begin(), ftl0, ft_itl0);
		stdl1.splice(stdl1.begin(), stdl0, std_itl0);

		testList(ftl0, stdl0, NOPRINT);
		testList(ftl1, stdl1, NOPRINT);

		std::cout << SUBTITLE << "[ check the address of the spliced element, it should remain similar ]" << RESET_COLOR << std::endl;
		testBool( ft_ptr_splicedElem ==  &(*ftl1.begin()), __FILE__,__LINE__);
		testBool( std_ptr_splicedElem ==  &(*stdl1.begin()), __FILE__,__LINE__);
		std::cout << SUBTITLE << "[ check if previously list 0 iterator does iterate on list 1 now ]" << RESET_COLOR << std::endl;
		testBool( *(++ft_itl0) == "bye!" , __FILE__, __LINE__);
		testBool( *(++std_itl0) == "bye!" , __FILE__, __LINE__);
	}
	{
		std::cout << HEADER_TITLE << "[ list 0 with 5 HelloWorld, list 1 with 5 Bye! ]" << RESET_COLOR << std::endl;

		ft::list<std::string>	ftl0(5, "HelloWorld!");
		ft::list<std::string>	ftl1(5, "bye!");
		std::list<std::string>	stdl0(5, "HelloWorld!");
		std::list<std::string>	stdl1(5, "bye!");

		testList(ftl0, stdl0, NOPRINT);
		testList(ftl1, stdl1, NOPRINT);
		std::cout << SUBTITLE << "[ splice (single element(2) version):transfer the LAST element of list 0 to the first position of list 1 ]" << RESET_COLOR << std::endl;
		ft::list<std::string>::iterator		ft_itl0 = --ftl0.end();
		std::list<std::string>::iterator	std_itl0 = --stdl0.end();

		void * ft_ptr_splicedElem = &(*ft_itl0);
		void * std_ptr_splicedElem = &(*std_itl0);

		ftl1.splice(ftl1.begin(), ftl0, ft_itl0);
		stdl1.splice(stdl1.begin(), stdl0, std_itl0);

		testList(ftl0, stdl0, NOPRINT);
		testList(ftl1, stdl1, NOPRINT);

		std::cout << SUBTITLE << "[ check the address of the spliced element, it should remain similar ]" << RESET_COLOR << std::endl;
		testBool( ft_ptr_splicedElem ==  &(*ftl1.begin()), __FILE__,__LINE__);
		testBool( std_ptr_splicedElem ==  &(*stdl1.begin()), __FILE__,__LINE__);

	}
	{
		std::cout << HEADER_TITLE << "[ list 0 with 1 HelloWorld, list 1 with 1 Bye! ]" << RESET_COLOR << std::endl;

		ft::list<std::string>	ftl0(1, "HelloWorld!");
		ft::list<std::string>	ftl1(1, "bye!");
		std::list<std::string>	stdl0(1, "HelloWorld!");
		std::list<std::string>	stdl1(1, "bye!");

		testList(ftl0, stdl0,  NOPRINT);
		testList(ftl1, stdl1,  NOPRINT);
		std::cout << SUBTITLE << "[ splice (single element(2) version):transfer the first (and only) element from list 0 to list 1 begin ]" << RESET_COLOR << std::endl;
		ft::list<std::string>::iterator		ft_itl0 = ftl0.begin();
		std::list<std::string>::iterator	std_itl0 = stdl0.begin();

		void * ft_ptr_splicedElem = &(*ft_itl0);
		void * std_ptr_splicedElem = &(*std_itl0);

		ftl1.splice(ftl1.begin(), ftl0, ft_itl0);
		stdl1.splice(stdl1.begin(), stdl0, std_itl0);

		testList(ftl0, stdl0,  NOPRINT);
		testList(ftl1, stdl1,  NOPRINT);

		std::cout << SUBTITLE << "[ check the address of the spliced element, it should remain similar ]" << RESET_COLOR << std::endl;
		testBool( ft_ptr_splicedElem ==  &(*ftl1.begin()), __FILE__,__LINE__);
		testBool( std_ptr_splicedElem ==  &(*stdl1.begin()), __FILE__,__LINE__);
	}
	{
		std::cout << HEADER_TITLE << "[ list 0 with 8 values '0', list 1 with 8 values '1' ]" << RESET_COLOR << std::endl;

		ft::list<int>	ftl0(8, 0);
		ft::list<int>	ftl1(8, 1);
		std::list<int>	stdl0(8, 0);
		std::list<int>	stdl1(8, 1);

		testList(ftl0, stdl0,  NOPRINT);
		testList(ftl1, stdl1,  NOPRINT);
		std::cout << SUBTITLE << "[ splice (range(3) version):transfer list 0 elements from begin to begin + 4 to list 1 ]" << RESET_COLOR << std::endl;
		ft::list<int>::iterator		ft_itl0 = ftl0.begin();
		std::list<int>::iterator	std_itl0 = stdl0.begin();
		ft::list<int>::iterator		ft_it_4_l0 = ftl0.begin();
		std::list<int>::iterator	std_it_4_l0 = stdl0.begin();
		for (int i = 0; i < 4; ++i)	{
			ft_it_4_l0++;
			std_it_4_l0++;
		}

		testList(ftl0, stdl0,  NOPRINT, "before test on list 0");
		testList(ftl1, stdl1,  NOPRINT, "before test on list 1");
		std::cout << SUBTITLE << "[ splice here ]" << RESET_COLOR << std::endl;
		ftl1.splice(ftl1.begin(), ftl0, ft_itl0, ft_it_4_l0);
		stdl1.splice(stdl1.begin(), stdl0, std_itl0, std_it_4_l0);
		testList(ftl0, stdl0,  NOPRINT, "test on list 0");
		testList(ftl1, stdl1,  NOPRINT, "test on list 1");
		std::cout << HEADER_TITLE << "[ splice with twice the same iterator as arguments ]" << RESET_COLOR << std::endl;
		ftl1.splice(ftl1.begin(), ftl0, ft_itl0, ft_itl0);
		stdl1.splice(stdl1.begin(), stdl0, std_itl0, std_itl0);
		testList(ftl0, stdl0,  NOPRINT, "test on list 0");
		testList(ftl1, stdl1,  NOPRINT, "test on list 1");
	}
	{
		std::cout << HEADER_TITLE << "[ list 0 with 8 values '0', list 1 with 8 values '1' ]" << RESET_COLOR << std::endl;

		ft::list<int>	ftl0(8, 0);
		ft::list<int>	ftl1(8, 1);
		std::list<int>	stdl0(8, 0);
		std::list<int>	stdl1(8, 1);

		testList(ftl0, stdl0,  NOPRINT);
		testList(ftl1, stdl1,  NOPRINT);
		std::cout << SUBTITLE << "[ splice (range(3) version): iterator begin of list 0 into list 1 until list 0 is empty ]" << RESET_COLOR << std::endl;

		while(ftl0.empty() == false && stdl0.empty() == false)	{
			ftl1.splice(ftl1.begin(), ftl0, ftl0.begin());
			stdl1.splice(stdl1.begin(), stdl0, stdl0.begin());
			testList(ftl0, stdl0,  NOPRINT);
			testList(ftl1, stdl1,  NOPRINT);
		}
		std::cout << SUBTITLE << "[ check if ft list 0 AND std list 0 are both empty ]" << RESET_COLOR << std::endl;
		testBool( ftl0.empty() == stdl0.empty());
		std::cout << SUBTITLE << "[ same opposite direction ( list 1 to list 0) ]" << RESET_COLOR << std::endl;

		while(ftl1.empty() == false && stdl1.empty() == false)	{
			ftl0.splice(ftl0.begin(), ftl1, ftl1.begin());
			stdl0.splice(stdl0.begin(), stdl1, stdl1.begin());
			testList(ftl0, stdl0,  NOPRINT);
			testList(ftl1, stdl1,  NOPRINT);
		}
		std::cout << SUBTITLE << "[ check if ft list 1 AND std list 1 are both empty ]" << RESET_COLOR << std::endl;
		testBool( ftl1.empty() == stdl1.empty());
	}
	{
		std::cout << HEADER_TITLE << "[ list 0 with 8 values '0', list 1 with 8 values '1' ]" << RESET_COLOR << std::endl;

		ft::list<int>	ftl0(8, 0);
		ft::list<int>	ftl1(8, 1);
		std::list<int>	stdl0(8, 0);
		std::list<int>	stdl1(8, 1);

		testList(ftl0, stdl0,  NOPRINT);
		testList(ftl1, stdl1,  NOPRINT);
		std::cout << SUBTITLE << "[ splice (range(3) version): last element from list 0 to begining of list 1, back and forth 100 times]" << RESET_COLOR << std::endl;

		for (int i = 0; i < 100; i++)	{
			ftl1.splice(ftl1.begin(), ftl0, --ftl0.end());
			stdl1.splice(stdl1.begin(), stdl0, --stdl0.end());
			ftl0.splice(ftl0.begin(), ftl1, ftl1.begin());
			stdl0.splice(stdl0.begin(), stdl1, stdl1.begin());
		}
		testList(ftl0, stdl0,  NOPRINT);
		testList(ftl1, stdl1,  NOPRINT);
	}
	return (0);
}
