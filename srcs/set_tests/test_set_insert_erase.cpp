/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_insert_erase.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:53:44 by bvalette          #+#    #+#             */
/*   Updated: 2021/07/02 14:32:43 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/exampleClass.hpp"
# include "./tester/bvaletteTester_set.hpp"

static void
testInserEraseAdvanced ( void )	{
		std::cout << HEADER_TITLE << "[ Insert with two different Compare functions]" << RESET_COLOR << std::endl;
		{
			std::set< int, std::greater<int> >	std_first_greater;
			std_first_greater.insert(10);
			std_first_greater.insert(30);
			std_first_greater.insert(50);
			std_first_greater.insert(70);
			ft::set< int, std::greater<int> >	ft_first_greater;
			ft_first_greater.insert(10);
			ft_first_greater.insert(30);
			ft_first_greater.insert(50);
			ft_first_greater.insert(70);

			std::set< int, std::greater<int> >::iterator	std_it = std_first_greater.begin();
			std::set< int, std::greater<int> >::iterator	std_ite = std_first_greater.end();
			ft::set< int, std::greater<int> >::iterator	ft_it = ft_first_greater.begin();
			ft::set< int, std::greater<int> >::iterator	ft_ite = ft_first_greater.end();

			std::set< int>	std_c0;
			ft::set< int>	ft_c0;
			std_c0.insert(std_it, std_ite);
			ft_c0.insert(ft_it, ft_ite);

			testSet<int, std::greater<int> >(ft_first_greater, std_first_greater, NOPRINT);
			testSet<int>(ft_c0, std_c0, NOPRINT);
		}
		{
			int testSize = 35000;
			int findKey = 42;
			std::cout << HEADER_TITLE << "[ Insert Range with " << testSize << " int key ]" << RESET_COLOR << std::endl;

			std::vector<int>	ft_val_0(testSize);
			std::vector< int>	std_val_0(testSize);
			srand(time(NULL));
			for (int i = 0; i < testSize; i++)	{
				int val = rand() % testSize;
				if (i == testSize / 2)
					findKey = val;
				ft_val_0[i] = (val);
				std_val_0[i] = (val);
			}

			std::set< int>	std_c0;
			ft::set< int>	ft_c0;

			std_c0.insert(std_val_0.begin(), std_val_0.end());
			ft_c0.insert(ft_val_0.begin(), ft_val_0.end());
			testSet(ft_c0, std_c0, NOPRINT);

			std::cout << HEADER_TITLE << "[ Insert with Hint ]" << RESET_COLOR << std::endl;

			std::set< int>::iterator	std_it = std_c0.find(findKey);
			ft::set< int>::iterator		ft_it = ft_c0.find(findKey);

			std_c0.insert(std_it, (testSize * 2 ));
			ft_c0.insert(ft_it, (testSize * 2 ));
			testSet(ft_c0, std_c0, NOPRINT);

			std_c0.insert(std_c0.end(), (-42));
			ft_c0.insert(ft_c0.end(), (-42));
			testSet(ft_c0, std_c0, NOPRINT);

			std_c0.insert(std_c0.find(-42), (-43));
			ft_c0.insert(ft_c0.find(-42), (-43));
			testSet(ft_c0, std_c0, NOPRINT);
			std_c0.insert(std_c0.find(-42), (-41));
			ft_c0.insert(ft_c0.find(-42), (-41));
			testSet(ft_c0, std_c0, NOPRINT);

			std_c0.insert(std_c0.find(testSize * 2), ((testSize * 2) + 1));
			ft_c0.insert(ft_c0.find(testSize * 2), ((testSize * 2) + 1));
			testSet(ft_c0, std_c0, NOPRINT);

			std_c0.insert(std_c0.find(testSize * 2), ((testSize * 2) - 1));
			ft_c0.insert(ft_c0.find(testSize * 2), ((testSize * 2) - 1));
			testSet(ft_c0, std_c0, NOPRINT);

			for (int i = 0; i < 10; i++)	{
				int	val_insert = rand() % testSize + 10;
				int	val_remove = std_val_0[rand() % (testSize / 2)];
				std::cout << HEADER_TITLE << "[Insert key: " << val_insert << " Remove key: " << val_remove << " ]" << RESET_COLOR << std::endl;

				std_it = std_c0.find(val_insert);
				ft_it = ft_c0.find(val_insert);
				if (std_it == std_c0.end())
					std::cout << TESTOK_TITLE << "[Hint position is end()]" << RESET_COLOR << std::endl;
				std_c0.insert(std_it, (val_insert + 1));
				ft_c0.insert(ft_it, (val_insert + 1));
				testSet(ft_c0, std_c0, NOPRINT);
				std_it = std_c0.insert(std_it, (val_insert - 1));
				ft_it = ft_c0.insert(ft_it, (val_insert - 1));

				if (std_it == std_c0.end())
					testBool(ft_it == ft_c0.end(), __FILE__, __LINE__);
				else if (testBool(ft_it != ft_c0.end(), __FILE__, __LINE__) == true)
					testBool(*ft_it == *std_it, __FILE__, __LINE__);
				testSet(ft_c0, std_c0, NOPRINT);
				std_c0.erase(val_remove);
				ft_c0.erase(val_remove);
				testSet(ft_c0, std_c0, NOPRINT);
			}
			std::cout << HEADER_TITLE << "[ Remove key 10000000 which does not exist ]" << RESET_COLOR << std::endl;
			std_c0.erase(10000000);
			ft_c0.erase(10000000);
			testSet(ft_c0, std_c0, NOPRINT);
		}
}

static void
testCppRefCode( void )	{
	std::cout << HEADER_TITLE << "[ Insert with code from Cpp reference]" << RESET_COLOR << std::endl;
	std::set<int> std_c0;
	ft::set<int> ft_c0;

	std::cout << HEADER_TITLE << "[ Insert Function ]" << RESET_COLOR << std::endl;
	// first insert function version (single parameter):
	std_c0.insert(100);
	std_c0.insert(200);
	ft_c0.insert(100);
	ft_c0.insert(200);

	testSet<int>(ft_c0, std_c0, NOPRINT);


	std::cout << HEADER_TITLE << "[ Test boolean returned in a pair in case of pre existing element ]" << RESET_COLOR << std::endl;
	std::pair<std::set<int>::iterator,bool> std_ret = std_c0.insert ( 500 );
	ft::pair<ft::set<int>::iterator,bool> ft_ret = ft_c0.insert ( 500 );
	testBool((std_ret.second == ft_ret.second), __FILE__, __LINE__);
	testSet<int>(ft_c0, std_c0, NOPRINT);

	std::cout << HEADER_TITLE << "[ Insert with hint ]" << RESET_COLOR << std::endl;
	// second insert function version (with hint position):
	std::set<int>::iterator std_it = std_c0.begin();
	ft::set<int>::iterator ft_it = ft_c0.begin();
	std_c0.insert (std_it,300);  // max efficiency inserting
	std_c0.insert (std_it,400);  // no max efficiency inserting
	ft_c0.insert (ft_it, 300);  // max efficiency inserting
	ft_c0.insert (ft_it, 400);  // no max efficiency inserting
	testSet<int>(ft_c0, std_c0, NOPRINT);

	std::cout << HEADER_TITLE << "[ Insert with range ]" << RESET_COLOR << std::endl;
	// third insert function version (range insertion):
	std::set<int> std_anotherset;
	ft::set<int> ft_anotherset;
	std_anotherset.insert(std_c0.begin(),std_c0.end());
	ft_anotherset.insert(ft_c0.begin(),ft_c0.end());
	testSet<int>(ft_anotherset, std_anotherset, NOPRINT);
}

static void
testBasicErase( void )	{

		std::set<exampleClass> 				std_c0;
		ft::set<exampleClass> 				ft_c0;

		// insert some values:
		std_c0.insert(10);
		std_c0.insert(20);
		std_c0.insert(30);
		std_c0.insert(40);
		std_c0.insert(50);
		std_c0.insert(60);
		ft_c0.insert(10);
		ft_c0.insert(20);
		ft_c0.insert(30);
		ft_c0.insert(40);
		ft_c0.insert(50);
		ft_c0.insert(60);

		std::set<exampleClass>::iterator		std_it = std_c0.begin();
		ft::set<exampleClass>::iterator		ft_it = ft_c0.begin();
		std::set<exampleClass>::iterator		std_ite = std_c0.end();
		ft::set<exampleClass>::iterator		ft_ite = ft_c0.end();

		std::cout << HEADER_TITLE << "[ Erase with position argument ]" << RESET_COLOR << std::endl;
		std_c0.erase(std_it);
		ft_c0.erase(ft_it);
		testSet<exampleClass>(ft_c0, std_c0, NOPRINT);
		testBool( *(--std_ite) == *(--ft_ite) , __FILE__, __LINE__);
		std_ite++;
		ft_ite++;

		std::cout << HEADER_TITLE << "[ Erase with key argument ]" << RESET_COLOR << std::endl;
		std_c0.erase(30);
		ft_c0.erase(30);
		std_c0.erase(60);
		ft_c0.erase(60);
		testSet<exampleClass>(ft_c0, std_c0, NOPRINT);

		std::cout << HEADER_TITLE << "[ Erase with range argument + iterator validity ]" << RESET_COLOR << std::endl;
		std_it = std_c0.begin();
		ft_it = ft_c0.begin();
		std_c0.erase(std_it,std_ite);
		ft_c0.erase(ft_it, ft_ite);
		testSet<exampleClass>(ft_c0, std_c0, NOPRINT);
}

int
test_set_insert_erase( void )	{

	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with std::string ~~~~~~~~~~~" << RESET_COLOR << std::endl;

		std::cout << TITLE << "[ INSERT ]" << RESET_COLOR << std::endl;

		testCppRefCode();
		std::cout << TITLE << "[ ERASE ]" << RESET_COLOR << std::endl;
		testBasicErase();
		std::cout << TITLE << "[ INSERT / ERASE ]" << RESET_COLOR << std::endl;
		testInserEraseAdvanced();

		return (0);
}
