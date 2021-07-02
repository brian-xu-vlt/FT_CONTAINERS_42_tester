/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_swap.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:42:32 by bvalette          #+#    #+#             */
/*   Updated: 2021/07/02 14:32:43 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_map.hpp"
# include "./tester/compClass.hpp"

void
test_basic_member_swap(  ft::map<int , int>& ft_c0, ft::map<int , int>& ft_c1, std::map<int , int>& std_c0, std::map<int , int>& std_c1  )	{


		ft::map<int, int>::iterator			ft_it0 = ft_c0.begin();
		ft::map<int, int>::iterator			ft_it1 = ft_c1.begin();
		std::map<int, int>::iterator		std_it0 = std_c0.begin();
		std::map<int, int>::iterator		std_it1 = std_c1.begin();

		std::cout << SUBTITLE << __func__ << "[ MEMBER swap 2 maps ]" << RESET_COLOR << std::endl;
		ft_c0.swap(ft_c1);
		std_c0.swap(std_c1);

		std::cout << SUBTITLE << "[ test if iterator stayed valid while pointing to new values ]" << RESET_COLOR << std::endl;
		if (ft_c1.empty() == false)
			testBool(ft_it0->first == ft_c1.begin()->first, __FILE__, __LINE__);
		if (ft_c0.empty() == false)
			testBool(ft_it1->first == ft_c0.begin()->first, __FILE__, __LINE__);
		if (std_c1.empty() == false)
			testBool(std_it0->first == std_c1.begin()->first, __FILE__, __LINE__);
		if (std_c0.empty() == false)
			testBool(std_it1->first == std_c0.begin()->first, __FILE__, __LINE__);
		if (ft_c1.empty() == false)
			testBool(ft_it0->second == ft_c1.begin()->second, __FILE__, __LINE__);
		if (ft_c0.empty() == false)
			testBool(ft_it1->second == ft_c0.begin()->second, __FILE__, __LINE__);
		if (std_c1.empty() == false)
			testBool(std_it0->second == std_c1.begin()->second, __FILE__, __LINE__);
		if (std_c0.empty() == false)
			testBool(std_it1->second == std_c0.begin()->second, __FILE__, __LINE__);
}

void
test_basic_non_member_swap(  ft::map<int , int>& ft_c0, ft::map<int , int>& ft_c1, std::map<int , int>& std_c0, std::map<int , int>& std_c1  )	{


		ft::map<int, int>::iterator			ft_it0 = ft_c0.begin();
		ft::map<int, int>::iterator			ft_it1 = ft_c1.begin();
		std::map<int, int>::iterator		std_it0 = std_c0.begin();
		std::map<int, int>::iterator		std_it1 = std_c1.begin();

		std::cout << SUBTITLE << __func__ << "[ NON MEMBERT swap 2 maps ]" << RESET_COLOR << std::endl;
		ft::swap(ft_c0, ft_c1);
		std::swap(std_c0, std_c1);

		std::cout << SUBTITLE << "[ test if iterator stayed valid while pointing to new values ]" << RESET_COLOR << std::endl;
		if (ft_c1.empty() == false)
			testBool(ft_it0->first == ft_c1.begin()->first, __FILE__, __LINE__);
		if (ft_c0.empty() == false)
			testBool(ft_it1->first == ft_c0.begin()->first, __FILE__, __LINE__);
		if (std_c1.empty() == false)
			testBool(std_it0->first == std_c1.begin()->first, __FILE__, __LINE__);
		if (std_c0.empty() == false)
			testBool(std_it1->first == std_c0.begin()->first, __FILE__, __LINE__);
		if (ft_c1.empty() == false)
			testBool(ft_it0->second == ft_c1.begin()->second, __FILE__, __LINE__);
		if (ft_c0.empty() == false)
			testBool(ft_it1->second == ft_c0.begin()->second, __FILE__, __LINE__);
		if (std_c1.empty() == false)
			testBool(std_it0->second == std_c1.begin()->second, __FILE__, __LINE__);
		if (std_c0.empty() == false)
			testBool(std_it1->second == std_c0.begin()->second, __FILE__, __LINE__);
}

int
test_map_swap( void )	{


	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with ints ~~~~~~~~~~~" << RESET_COLOR << std::endl;
	{
		int test_size = 1000;
		std::vector<ft::pair<int, int> >	ft_val_0(test_size);
		std::vector<std::pair<int, int> >	std_val_0(test_size);
		for (int i = 0; i < test_size; i++)	{
			srand(i);
			int val = rand() % test_size;
			ft_val_0[i] = ft::make_pair(val, i);
			std_val_0[i] = std::make_pair(val, i);
		}

		std::cout << SUBTITLE << "[ Instanciate map0 with iterator to vector of pair val_0 ]" << RESET_COLOR << std::endl;
		std::map<int, int>	std_c0(std_val_0.begin(), std_val_0.end());
		ft::map<int, int>	ft_c0(ft_val_0.begin(), ft_val_0.end());
		testMap(ft_c0, std_c0, NOPRINT);


		std::cout << SUBTITLE << "[ Instanciate map1 with default ctor]" << RESET_COLOR << std::endl;
		ft::map<int, int>	ft_c1;
		std::map<int, int>	std_c1;
		testMap(ft_c1, std_c1, NOPRINT);

		std::vector<ft::pair<int, int> >	ft_val_1(test_size);
		std::vector<std::pair<int, int> >	std_val_1(test_size);
		for (int i = 0; i < test_size / 2; i++)	{
			srand(i);
			int val = rand() % test_size;
			ft_val_1[i] = ft::make_pair(val, test_size - i);
			std_val_1[i] = std::make_pair(val, test_size - i);
		}
		std::cout << SUBTITLE << "[ Instanciate map2 with iterator to vector of pair val_1 ]" << RESET_COLOR << std::endl;
		std::vector<int>	val_1(1, 42);
		std::map<int, int>	std_c2(std_val_1.begin(), std_val_1.end());
		ft::map<int, int>	ft_c2(ft_val_1.begin(), ft_val_1.end());
		testMap(ft_c2, std_c2, NOPRINT);

		std::cout << SUBTITLE << "[ Instanciate map3 with custom Compare empty then insert 1 pair with insert function ]" << RESET_COLOR << std::endl;
		ft::map<int, int>	ft_c3;
		std::map<int, int>	std_c3;
		ft_c3.insert(ft::make_pair(42, 21));
		std_c3.insert(std::make_pair(42, 21));
		testMap(ft_c3, std_c3, NOPRINT);

		std::cout << HEADER_TITLE << "[ non member swap 0 with 1 ]" << RESET_COLOR << std::endl;
		test_basic_non_member_swap(ft_c0, ft_c1, std_c0, std_c1);
		testMap(ft_c0, std_c0, NOPRINT, "test ft_c0/std_c0");
		testMap(ft_c1, std_c1, NOPRINT, "test ft_c1/std_c1");
		testMap(ft_c2, std_c2, NOPRINT, "test ft_c2/std_c2");
		testMap(ft_c3, std_c3, NOPRINT, "test ft_c3/std_c3");
		std::cout << HEADER_TITLE << "[ non member swap 1 with 2 ]" << RESET_COLOR << std::endl;
		test_basic_non_member_swap(ft_c1, ft_c2, std_c1, std_c2);
		testMap(ft_c0, std_c0, NOPRINT, "test ft_c0/std_c0");
		testMap(ft_c1, std_c1, NOPRINT, "test ft_c1/std_c1");
		testMap(ft_c2, std_c2, NOPRINT, "test ft_c2/std_c2");
		testMap(ft_c3, std_c3, NOPRINT, "test ft_c3/std_c3");
		std::cout << HEADER_TITLE << "[ non member swap 3 with 2 ]" << RESET_COLOR << std::endl;
		test_basic_non_member_swap(ft_c3, ft_c2, std_c3, std_c2);
		testMap(ft_c0, std_c0, NOPRINT, "test ft_c0/std_c0");
		testMap(ft_c1, std_c1, NOPRINT, "test ft_c1/std_c1");
		testMap(ft_c2, std_c2, NOPRINT, "test ft_c2/std_c2");
		testMap(ft_c3, std_c3, NOPRINT, "test ft_c3/std_c3");
		std::cout << HEADER_TITLE << "[ non member swap 2 with 2 ]" << RESET_COLOR << std::endl;
		test_basic_non_member_swap(ft_c2, ft_c2, std_c2, std_c2);
		testMap(ft_c0, std_c0, NOPRINT, "test ft_c0/std_c0");
		testMap(ft_c1, std_c1, NOPRINT, "test ft_c1/std_c1");
		testMap(ft_c2, std_c2, NOPRINT, "test ft_c2/std_c2");
		testMap(ft_c3, std_c3, NOPRINT, "test ft_c3/std_c3");

		std::cout << HEADER_TITLE << "[ member_swap 0 with 1 ]" << RESET_COLOR << std::endl;
		test_basic_member_swap(ft_c0, ft_c1, std_c0, std_c1);
		testMap(ft_c0, std_c0, NOPRINT, "test ft_c0/std_c0");
		testMap(ft_c1, std_c1, NOPRINT, "test ft_c1/std_c1");
		testMap(ft_c2, std_c2, NOPRINT, "test ft_c2/std_c2");
		testMap(ft_c3, std_c3, NOPRINT, "test ft_c3/std_c3");
		std::cout << HEADER_TITLE << "[ member_swap 1 with 2 ]" << RESET_COLOR << std::endl;
		test_basic_member_swap(ft_c1, ft_c2, std_c1, std_c2);
		testMap(ft_c0, std_c0, NOPRINT, "test ft_c0/std_c0");
		testMap(ft_c1, std_c1, NOPRINT, "test ft_c1/std_c1");
		testMap(ft_c2, std_c2, NOPRINT, "test ft_c2/std_c2");
		testMap(ft_c3, std_c3, NOPRINT, "test ft_c3/std_c3");
		std::cout << HEADER_TITLE << "[ member_swap 3 with 2 ]" << RESET_COLOR << std::endl;
		test_basic_member_swap(ft_c3, ft_c2, std_c3, std_c2);
		testMap(ft_c0, std_c0, NOPRINT, "test ft_c0/std_c0");
		testMap(ft_c1, std_c1, NOPRINT, "test ft_c1/std_c1");
		testMap(ft_c2, std_c2, NOPRINT, "test ft_c2/std_c2");
		testMap(ft_c3, std_c3, NOPRINT, "test ft_c3/std_c3");
		std::cout << HEADER_TITLE << "[ member_swap 2 with 2 ]" << RESET_COLOR << std::endl;
		test_basic_member_swap(ft_c2, ft_c2, std_c2, std_c2);
		testMap(ft_c0, std_c0, NOPRINT, "test ft_c0/std_c0");
		testMap(ft_c1, std_c1, NOPRINT, "test ft_c1/std_c1");
		testMap(ft_c2, std_c2, NOPRINT, "test ft_c2/std_c2");
		testMap(ft_c3, std_c3, NOPRINT, "test ft_c3/std_c3");
	}
	return (0);
}
