/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_swap.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:42:32 by bvalette          #+#    #+#             */
/*   Updated: 2021/07/02 14:32:43 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_set.hpp"
# include "./tester/compClass.hpp"

void
test_basic_member_swap(  ft::set<int>& ft_c0, ft::set<int>& ft_c1, std::set<int>& std_c0, std::set<int>& std_c1  )	{


		ft::set<int>::iterator			ft_it0 = ft_c0.begin();
		ft::set<int>::iterator			ft_it1 = ft_c1.begin();
		std::set<int>::iterator		std_it0 = std_c0.begin();
		std::set<int>::iterator		std_it1 = std_c1.begin();

		std::cout << SUBTITLE << __func__ << "[ MEMBER swap 2 sets ]" << RESET_COLOR << std::endl;
		ft_c0.swap(ft_c1);
		std_c0.swap(std_c1);

		std::cout << SUBTITLE << "[ test if iterator stayed valid while pointing to new values ]" << RESET_COLOR << std::endl;
		if (ft_c1.empty() == false)
			testBool(*ft_it0 == *ft_c1.begin(), __FILE__, __LINE__);
		if (ft_c0.empty() == false)
			testBool(*ft_it1 == *ft_c0.begin(), __FILE__, __LINE__);
		if (std_c1.empty() == false)
			testBool(*std_it0 == *std_c1.begin(), __FILE__, __LINE__);
		if (std_c0.empty() == false)
			testBool(*std_it1 == *std_c0.begin(), __FILE__, __LINE__);
		if (ft_c1.empty() == false)
			testBool(*ft_it0 == *ft_c1.begin(), __FILE__, __LINE__);
		if (ft_c0.empty() == false)
			testBool(*ft_it1 == *ft_c0.begin(), __FILE__, __LINE__);
		if (std_c1.empty() == false)
			testBool(*std_it0 == *std_c1.begin(), __FILE__, __LINE__);
		if (std_c0.empty() == false)
			testBool(*std_it1 == *std_c0.begin(), __FILE__, __LINE__);
}

void
test_basic_non_member_swap(  ft::set<int>& ft_c0, ft::set<int>& ft_c1, std::set<int>& std_c0, std::set<int>& std_c1  )	{


		ft::set<int>::iterator			ft_it0 = ft_c0.begin();
		ft::set<int>::iterator			ft_it1 = ft_c1.begin();
		std::set<int>::iterator		std_it0 = std_c0.begin();
		std::set<int>::iterator		std_it1 = std_c1.begin();

		std::cout << SUBTITLE << __func__ << "[ NON MEMBERT swap 2 sets ]" << RESET_COLOR << std::endl;
		ft::swap(ft_c0, ft_c1);
		std::swap(std_c0, std_c1);

		std::cout << SUBTITLE << "[ test if iterator stayed valid while pointing to new values ]" << RESET_COLOR << std::endl;
		if (ft_c1.empty() == false)
			testBool(*ft_it0 == *ft_c1.begin(), __FILE__, __LINE__);
		if (ft_c0.empty() == false)
			testBool(*ft_it1 == *ft_c0.begin(), __FILE__, __LINE__);
		if (std_c1.empty() == false)
			testBool(*std_it0 == *std_c1.begin(), __FILE__, __LINE__);
		if (std_c0.empty() == false)
			testBool(*std_it1 == *std_c0.begin(), __FILE__, __LINE__);
		if (ft_c1.empty() == false)
			testBool(*ft_it0 == *ft_c1.begin(), __FILE__, __LINE__);
		if (ft_c0.empty() == false)
			testBool(*ft_it1 == *ft_c0.begin(), __FILE__, __LINE__);
		if (std_c1.empty() == false)
			testBool(*std_it0 == *std_c1.begin(), __FILE__, __LINE__);
		if (std_c0.empty() == false)
			testBool(*std_it1 == *std_c0.begin(), __FILE__, __LINE__);
}

int
test_set_swap( void )	{


	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with ints ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		int test_size = 1000;
		std::vector<int>	ft_val_0(test_size);
		std::vector<int>	std_val_0(test_size);
		for (int i = 0; i < test_size; i++)	{
			srand(i);
			int val = rand() % test_size;
			ft_val_0[i] = val;
			std_val_0[i] = val;
		}

		std::cout << SUBTITLE << "[ Instanciate set0 with iterator to vector of pair val_0 ]" << RESET_COLOR << std::endl;
		std::set<int>	std_c0(std_val_0.begin(), std_val_0.end());
		ft::set<int>	ft_c0(ft_val_0.begin(), ft_val_0.end());
		testSet(ft_c0, std_c0, NOPRINT);


		std::cout << SUBTITLE << "[ Instanciate set1 with default ctor]" << RESET_COLOR << std::endl;
		ft::set<int>	ft_c1;
		std::set<int>	std_c1;
		testSet(ft_c1, std_c1, NOPRINT);

		std::vector<int>	ft_val_1(test_size);
		std::vector<int>	std_val_1(test_size);
		for (int i = 0; i < test_size / 2; i++)	{
			srand(i);
			int val = rand() % test_size;
			ft_val_1[i] = val;
			std_val_1[i] = val;
		}
		std::cout << SUBTITLE << "[ Instanciate set2 with iterator to vector of pair val_1 ]" << RESET_COLOR << std::endl;
		std::vector<int>	val_1(1, 42);
		std::set<int>	std_c2(std_val_1.begin(), std_val_1.end());
		ft::set<int>	ft_c2(ft_val_1.begin(), ft_val_1.end());
		testSet(ft_c2, std_c2, NOPRINT);

		std::cout << SUBTITLE << "[ Instanciate set3 with custom Compare empty then insert ]" << RESET_COLOR << std::endl;
		ft::set<int>	ft_c3;
		std::set<int>	std_c3;
		ft_c3.insert(42);
		std_c3.insert(42);
		testSet(ft_c3, std_c3, NOPRINT);

		std::cout << HEADER_TITLE << "[ non member swap 0 with 1 ]" << RESET_COLOR << std::endl;
		test_basic_non_member_swap(ft_c0, ft_c1, std_c0, std_c1);
		testSet(ft_c0, std_c0, NOPRINT, "test ft_c0/std_c0");
		testSet(ft_c1, std_c1, NOPRINT, "test ft_c1/std_c1");
		testSet(ft_c2, std_c2, NOPRINT, "test ft_c2/std_c2");
		testSet(ft_c3, std_c3, NOPRINT, "test ft_c3/std_c3");
		std::cout << HEADER_TITLE << "[ non member swap 1 with 2 ]" << RESET_COLOR << std::endl;
		test_basic_non_member_swap(ft_c1, ft_c2, std_c1, std_c2);
		testSet(ft_c0, std_c0, NOPRINT, "test ft_c0/std_c0");
		testSet(ft_c1, std_c1, NOPRINT, "test ft_c1/std_c1");
		testSet(ft_c2, std_c2, NOPRINT, "test ft_c2/std_c2");
		testSet(ft_c3, std_c3, NOPRINT, "test ft_c3/std_c3");
		std::cout << HEADER_TITLE << "[ non member swap 3 with 2 ]" << RESET_COLOR << std::endl;
		test_basic_non_member_swap(ft_c3, ft_c2, std_c3, std_c2);
		testSet(ft_c0, std_c0, NOPRINT, "test ft_c0/std_c0");
		testSet(ft_c1, std_c1, NOPRINT, "test ft_c1/std_c1");
		testSet(ft_c2, std_c2, NOPRINT, "test ft_c2/std_c2");
		testSet(ft_c3, std_c3, NOPRINT, "test ft_c3/std_c3");
		std::cout << HEADER_TITLE << "[ non member swap 2 with 2 ]" << RESET_COLOR << std::endl;
		test_basic_non_member_swap(ft_c2, ft_c2, std_c2, std_c2);
		testSet(ft_c0, std_c0, NOPRINT, "test ft_c0/std_c0");
		testSet(ft_c1, std_c1, NOPRINT, "test ft_c1/std_c1");
		testSet(ft_c2, std_c2, NOPRINT, "test ft_c2/std_c2");
		testSet(ft_c3, std_c3, NOPRINT, "test ft_c3/std_c3");

		std::cout << HEADER_TITLE << "[ member_swap 0 with 1 ]" << RESET_COLOR << std::endl;
		test_basic_member_swap(ft_c0, ft_c1, std_c0, std_c1);
		testSet(ft_c0, std_c0, NOPRINT, "test ft_c0/std_c0");
		testSet(ft_c1, std_c1, NOPRINT, "test ft_c1/std_c1");
		testSet(ft_c2, std_c2, NOPRINT, "test ft_c2/std_c2");
		testSet(ft_c3, std_c3, NOPRINT, "test ft_c3/std_c3");
		std::cout << HEADER_TITLE << "[ member_swap 1 with 2 ]" << RESET_COLOR << std::endl;
		test_basic_member_swap(ft_c1, ft_c2, std_c1, std_c2);
		testSet(ft_c0, std_c0, NOPRINT, "test ft_c0/std_c0");
		testSet(ft_c1, std_c1, NOPRINT, "test ft_c1/std_c1");
		testSet(ft_c2, std_c2, NOPRINT, "test ft_c2/std_c2");
		testSet(ft_c3, std_c3, NOPRINT, "test ft_c3/std_c3");
		std::cout << HEADER_TITLE << "[ member_swap 3 with 2 ]" << RESET_COLOR << std::endl;
		test_basic_member_swap(ft_c3, ft_c2, std_c3, std_c2);
		testSet(ft_c0, std_c0, NOPRINT, "test ft_c0/std_c0");
		testSet(ft_c1, std_c1, NOPRINT, "test ft_c1/std_c1");
		testSet(ft_c2, std_c2, NOPRINT, "test ft_c2/std_c2");
		testSet(ft_c3, std_c3, NOPRINT, "test ft_c3/std_c3");
		std::cout << HEADER_TITLE << "[ member_swap 2 with 2 ]" << RESET_COLOR << std::endl;
		test_basic_member_swap(ft_c2, ft_c2, std_c2, std_c2);
		testSet(ft_c0, std_c0, NOPRINT, "test ft_c0/std_c0");
		testSet(ft_c1, std_c1, NOPRINT, "test ft_c1/std_c1");
		testSet(ft_c2, std_c2, NOPRINT, "test ft_c2/std_c2");
		testSet(ft_c3, std_c3, NOPRINT, "test ft_c3/std_c3");
	}
	return (0);
}
