/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_operatorEqual.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 09:04:41 by bvalette          #+#    #+#             */
/*   Updated: 2021/05/21 09:47:22 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_map.hpp"

void
test_basic_operator_equal(  ft::map<int , int>& ft_c0, ft::map<int , int>& ft_c1, std::map<int , int>& std_c0, std::map<int , int>& std_c1  )	{


		ft::map<int, int>::iterator			ft_it1 = ft_c1.begin();
		std::map<int, int>::iterator		std_it1 = std_c1.begin();

		std::cout << SUBTITLE << __func__ << "[ Operator= on 2 maps ]" << RESET_COLOR << std::endl;
		std_c0 = std_c1;
		ft_c0 = ft_c1;

		std::cout << SUBTITLE << "[ test if iterator stayed valid after = ]" << RESET_COLOR << std::endl;
		if (std_c1.empty() == false)
			testBool(*std_it1 == *std_c1.begin(), __LINE__);
		if (ft_c1.empty() == false)
			testBool(*ft_it1 == *ft_c1.begin(), __LINE__);
}

int
test_map_operatorEqual( void )	{


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

		std::cout << HEADER_TITLE << "[ map_0 = map_1 ]" << RESET_COLOR << std::endl;
		test_basic_operator_equal(ft_c0, ft_c1, std_c0, std_c1);
		testMap(ft_c0, std_c0, NOPRINT, "test ft_c0/std_c0");
		testMap(ft_c1, std_c1, NOPRINT, "test ft_c1/std_c1");
		testMap(ft_c2, std_c2, NOPRINT, "test ft_c2/std_c2");
		testMap(ft_c3, std_c3, NOPRINT, "test ft_c3/std_c3");
		std::cout << HEADER_TITLE << "[ map_1 = map_2 ]" << RESET_COLOR << std::endl;
		test_basic_operator_equal(ft_c1, ft_c2, std_c1, std_c2);
		testMap(ft_c0, std_c0, NOPRINT, "test ft_c0/std_c0");
		testMap(ft_c1, std_c1, NOPRINT, "test ft_c1/std_c1");
		testMap(ft_c2, std_c2, NOPRINT, "test ft_c2/std_c2");
		testMap(ft_c3, std_c3, NOPRINT, "test ft_c3/std_c3");
		std::cout << HEADER_TITLE << "[ map_3 = map_2 ]" << RESET_COLOR << std::endl;
		test_basic_operator_equal(ft_c3, ft_c2, std_c3, std_c2);
		testMap(ft_c0, std_c0, NOPRINT, "test ft_c0/std_c0");
		testMap(ft_c1, std_c1, NOPRINT, "test ft_c1/std_c1");
		testMap(ft_c2, std_c2, NOPRINT, "test ft_c2/std_c2");
		testMap(ft_c3, std_c3, NOPRINT, "test ft_c3/std_c3");
		std::cout << HEADER_TITLE << "[ map_2 = map_2 ]" << RESET_COLOR << std::endl;
		test_basic_operator_equal(ft_c2, ft_c2, std_c2, std_c2);
		testMap(ft_c0, std_c0, NOPRINT, "test ft_c0/std_c0");
		testMap(ft_c1, std_c1, NOPRINT, "test ft_c1/std_c1");
		testMap(ft_c2, std_c2, NOPRINT, "test ft_c2/std_c2");
		testMap(ft_c3, std_c3, NOPRINT, "test ft_c3/std_c3");
		std::cout << HEADER_TITLE << "[ map_0 = map_0 ]" << RESET_COLOR << std::endl;
		test_basic_operator_equal(ft_c0, ft_c0, std_c0, std_c0);
		testMap(ft_c0, std_c0, NOPRINT, "test ft_c0/std_c0");
		testMap(ft_c1, std_c1, NOPRINT, "test ft_c1/std_c1");
		testMap(ft_c2, std_c2, NOPRINT, "test ft_c2/std_c2");
		testMap(ft_c3, std_c3, NOPRINT, "test ft_c3/std_c3");
	}
	return (0);
}
