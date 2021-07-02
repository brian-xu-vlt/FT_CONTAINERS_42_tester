/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_insert_erase.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:50:19 by bvalette          #+#    #+#             */
/*   Updated: 2021/07/02 14:37:08 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./tester/bvaletteTester_vector.hpp"

static void
testInsert ( void )	{
	{
		std::cout << HEADER_TITLE << "[ Instanciate vector of 4 strings ]" << RESET_COLOR << std::endl;
		ft::vector<std::string>		ft_c0(4, "___");
		std::vector<std::string>	std_c0(4, "___");
		ft::vector<std::string>::iterator	ft_ret;
		std::vector<std::string>::iterator	std_ret;
		testVector(ft_c0, std_c0, NOPRINT);

		std::cout << SUBTITLE << "[ Insert with insert(iterator, value) ]" << RESET_COLOR << std::endl;

		ft_ret = ft_c0.insert(ft_c0.begin(), "A");
		std_ret = std_c0.insert(std_c0.begin(), "A");
		testBool(*ft_ret == *std_ret, __FILE__, __LINE__);
		testVector(ft_c0, std_c0, NOPRINT);

		ft_ret = ft_c0.insert(ft_c0.begin(), "B");
		std_ret = std_c0.insert(std_c0.begin(), "B");
		testBool(*ft_ret == *std_ret, __FILE__, __LINE__);
		testVector(ft_c0, std_c0, NOPRINT);

		ft_ret = ft_c0.insert(++ft_c0.begin(), "42");
		std_ret = std_c0.insert(++std_c0.begin(), "42");
		testBool(*ft_ret == *std_ret, __FILE__, __LINE__);
		testVector(ft_c0, std_c0, NOPRINT);

		ft_ret = ft_c0.insert(--ft_c0.end(), "The End...");
		std_ret = std_c0.insert(--std_c0.end(), "The End...");
		testBool(*ft_ret == *std_ret, __FILE__, __LINE__);
		testVector(ft_c0, std_c0, NOPRINT);

		ft_ret = ft_c0.insert(ft_c0.end(), "End...");
		std_ret = std_c0.insert(std_c0.end(), "End...");
		testBool(*ft_ret == *std_ret, __FILE__, __LINE__);
		testVector(ft_c0, std_c0, NOPRINT);

		ft_ret = ft_c0.insert(ft_c0.begin() + ft_c0.size() / 2, "middle...");
		std_ret = std_c0.insert(std_c0.begin() + std_c0.size() / 2, "middle...");
		testBool(*ft_ret == *std_ret, __FILE__, __LINE__);
		testVector(ft_c0, std_c0, NOPRINT);


		std::cout << SUBTITLE << "[ test return of insert function ]" << RESET_COLOR << std::endl;
		testBool(*(ft_c0.insert(++ft_c0.begin(), "Return_this")) == *(std_c0.insert(++std_c0.begin(), "Return_this")), __FILE__, __LINE__);
	}
	{
		std::cout << HEADER_TITLE << "[ Instanciate empty vector ]" << RESET_COLOR << std::endl;
		ft::vector<std::string>		ft_c0;
		std::vector<std::string>	std_c0;
		testVector(ft_c0, std_c0, NOPRINT);

		std::cout << SUBTITLE << "[ Insert at begin() and check return ]" << RESET_COLOR << std::endl;

		testBool(*(ft_c0.insert(ft_c0.begin(), "Return_this")) == *(std_c0.insert(std_c0.begin(), "Return_this")), __FILE__, __LINE__);
		testVector(ft_c0, std_c0, NOPRINT);
	}
	{
		std::cout << HEADER_TITLE << "[ Instanciate empty vector ]" << RESET_COLOR << std::endl;
		ft::vector<std::string>		ft_c0;
		std::vector<std::string>	std_c0;
		testVector(ft_c0, std_c0, NOPRINT);

		std::cout << SUBTITLE << "[ Insert at end() and check return ]" << RESET_COLOR << std::endl;

		testBool(*(ft_c0.insert(ft_c0.end(), "Return_this")) == *(std_c0.insert(std_c0.end(), "Return_this")), __FILE__, __LINE__);
		testVector(ft_c0, std_c0, NOPRINT);
	}

}
static void
testInsert ( size_t n )	{
	{
		std::cout << HEADER_TITLE << "[ Instanciate vector of 4 strings ]" << RESET_COLOR << std::endl;
		ft::vector<std::string>		ft_c0(4, "___");
		std::vector<std::string>	std_c0(4, "___");
		testVector(ft_c0, std_c0, NOPRINT);

		std::cout << SUBTITLE << "[ Insert with insert(iterator, " << n <<",value) ]" << RESET_COLOR << std::endl;

		ft_c0.insert(ft_c0.begin(), n, "A");
		std_c0.insert(std_c0.begin(), n, "A");
		testVector(ft_c0, std_c0, NOPRINT);

		ft_c0.insert(ft_c0.begin(), n, "B");
		std_c0.insert(std_c0.begin(), n, "B");
		testVector(ft_c0, std_c0, NOPRINT);

		ft_c0.insert(++ft_c0.begin(), n, "42");
		std_c0.insert(++std_c0.begin(), n, "42");
		testVector(ft_c0, std_c0, NOPRINT);

		ft_c0.insert(--ft_c0.end(), "n, The End...");
		std_c0.insert(--std_c0.end(), "n, The End...");
		testVector(ft_c0, std_c0, NOPRINT);

		ft_c0.insert(ft_c0.end(), n, "End...");
		std_c0.insert(std_c0.end(), n, "End...");
		testVector(ft_c0, std_c0, NOPRINT);

		ft_c0.insert(ft_c0.begin() + ft_c0.size() / 2, n, "middle...");
		std_c0.insert(std_c0.begin() + std_c0.size() / 2, n, "middle...");
		testVector(ft_c0, std_c0, NOPRINT);
	}
	{
		std::cout << HEADER_TITLE << "[ Instanciate empty vector ]" << RESET_COLOR << std::endl;
		ft::vector<std::string>		ft_c0;
		std::vector<std::string>	std_c0;
		testVector(ft_c0, std_c0, NOPRINT);

		std::cout << SUBTITLE << "[ Insert " << n << " elements at begin() ]" << RESET_COLOR << std::endl;

		ft_c0.insert(ft_c0.begin(), n, "Return_this");
		std_c0.insert(std_c0.begin(), n, "Return_this");
		testVector(ft_c0, std_c0, NOPRINT);
	}
	{
		std::cout << HEADER_TITLE << "[ Instanciate empty vector ]" << RESET_COLOR << std::endl;
		ft::vector<std::string>		ft_c0;
		std::vector<std::string>	std_c0;
		testVector(ft_c0, std_c0, NOPRINT);

		std::cout << SUBTITLE << "[ Insert " << n << " elements at end() ]" << RESET_COLOR << std::endl;

		ft_c0.insert(ft_c0.end(), n, "Return_this");
		std_c0.insert(std_c0.end(), n, "Return_this");
		testVector(ft_c0, std_c0, NOPRINT);
	}

}
static void
testInsert ( ft::vector<std::string>::iterator ft_it,
			ft::vector<std::string>::iterator ft_ite,
			std::vector<std::string>::iterator std_it,
			std::vector<std::string>::iterator std_ite)	{

	{
		std::cout << HEADER_TITLE << "[ Instanciate vector of 4 strings ]" << RESET_COLOR << std::endl;
		ft::vector<std::string>		ft_c0(4, "___");
		std::vector<std::string>	std_c0(4, "___");
		testVector(ft_c0, std_c0, NOPRINT);

		std::cout << SUBTITLE << "[ Insert with insert(iterator, iterator, iterator) ]" << RESET_COLOR << std::endl;

		ft_c0.insert(ft_c0.begin(), ft_it, ft_ite);
		std_c0.insert(std_c0.begin(), std_it, std_ite);
		testVector(ft_c0, std_c0, NOPRINT);

		ft_c0.insert(ft_c0.begin(), ft_it, ft_ite);
		std_c0.insert(std_c0.begin(), std_it, std_ite);
		testVector(ft_c0, std_c0, NOPRINT);

		ft_c0.insert(++ft_c0.begin(), ft_it, ft_ite);
		std_c0.insert(++std_c0.begin(), std_it, std_ite);
		testVector(ft_c0, std_c0, NOPRINT);

		ft_c0.insert(--ft_c0.end(), ft_it, ft_ite);
		std_c0.insert(--std_c0.end(), std_it, std_ite);
		testVector(ft_c0, std_c0, NOPRINT);

		ft_c0.insert(ft_c0.end(), ft_it, ft_ite);
		std_c0.insert(std_c0.end(), std_it, std_ite);
		testVector(ft_c0, std_c0, NOPRINT);

		ft_c0.insert(ft_c0.begin() + ft_c0.size() / 2, ft_it, ft_ite);
		std_c0.insert(std_c0.begin() + std_c0.size() / 2, std_it, std_ite);
		testVector(ft_c0, std_c0, NOPRINT);
	}
	{
		std::cout << HEADER_TITLE << "[ Instanciate empty vector ]" << RESET_COLOR << std::endl;
		ft::vector<std::string>		ft_c0;
		std::vector<std::string>	std_c0;
		testVector(ft_c0, std_c0, NOPRINT);

		std::cout << SUBTITLE << "[ Insert with insert(iterator, iterator, iterator) ]" << RESET_COLOR << std::endl;

		ft_c0.insert(ft_c0.begin(), ft_it, ft_ite);
		std_c0.insert(std_c0.begin(), std_it, std_ite);
		testVector(ft_c0, std_c0, NOPRINT);
	}
	{
		std::cout << HEADER_TITLE << "[ Instanciate empty vector ]" << RESET_COLOR << std::endl;
		ft::vector<std::string>		ft_c0;
		std::vector<std::string>	std_c0;
		testVector(ft_c0, std_c0, NOPRINT);

		std::cout << SUBTITLE << "[ Insert with insert(iterator, iterator, iterator) ]" << RESET_COLOR << std::endl;

		ft_c0.insert(ft_c0.end(), ft_it, ft_ite);
		std_c0.insert(std_c0.end(), std_it, std_ite);
		testVector(ft_c0, std_c0, NOPRINT);
	}

}

static void
testErase (void )	{
		std::cout << TITLE << "[ Erase ]" << RESET_COLOR << std::endl;
		size_t	testSize = 10;
		std::cout << HEADER_TITLE << "[ Instanciate vector with "<< testSize <<" \"helloWorld\" ]" << RESET_COLOR << std::endl;

		ft::vector<std::string>		ft_c0(testSize, "helloWorld");
		std::vector<std::string>	std_c0(testSize, "helloWorld");

		for (size_t i = 0; i < 2; i++)	{
			ft_c0.push_back("THE END");
			std_c0.push_back("THE END");
		}
		for (size_t i = 0; i < 1; i++)	{
			ft_c0.insert(ft_c0.begin(), "THE BEGINING");
			std_c0.insert(std_c0.begin(), "THE BEGINING");
		}
		testVector(ft_c0, std_c0, NOPRINT);

		testSize = std_c0.size();
		std::cout << SUBTITLE << "[ Loop Erase with erase(iterator) ]" << RESET_COLOR << std::endl;
		for (size_t i = 0; i < testSize / 2; i++)
		{

			ft::vector<std::string>::iterator	ftIt;
			std::vector<std::string>::iterator	stdIt;
			if (i == 1)	{
				std::cout << SUBTITLE << "[ Erase with erase(iterator) size() / 2 ]" << RESET_COLOR << std::endl;
				ftIt = ft_c0.begin() + (ft_c0.size() / 2);
				stdIt = std_c0.begin() + (std_c0.size() / 2);
			}
			else if (i % 2 == 0)	{
				std::cout << SUBTITLE << "[ Erase with erase(iterator) --end() ]" << RESET_COLOR << std::endl;
				ftIt = --ft_c0.end();
				stdIt = --std_c0.end();
			}
			else	{
				std::cout << SUBTITLE << "[ Erase with erase(iterator) begin() ]" << RESET_COLOR << std::endl;
				ftIt = ft_c0.begin();
				stdIt = std_c0.begin();
			}

			std::string * ft_ptr = &(*ftIt);
			std::string * std_ptr = &(*stdIt);

			std::string * ret_ft_ptr = &(*ft_c0.erase(ftIt));
			std::string * ret_std_ptr = &(*std_c0.erase(stdIt));

			if (ft_ptr != ret_ft_ptr || std_ptr != ret_std_ptr)	{
				std::cout << "ft\tPtr expected = " << ft_ptr << ", got = " << ret_ft_ptr << std::endl;
				std::cout << "std\tPtr expected = " << std_ptr << ", got = " << ret_std_ptr << std::endl;
			}
			testVector(ft_c0, std_c0, NOPRINT);
			testBool(ft_ptr == ret_ft_ptr && std_ptr == ret_std_ptr, __FILE__, __LINE__, i);
		}
}

static void
testEraseRange(
			ft::vector<std::string> & ft_c0,
			std::vector<std::string> & std_c0,
			ft::vector<std::string>::iterator ftIt,
			ft::vector<std::string>::iterator ftIte,
			std::vector<std::string>::iterator stdIt,
			std::vector<std::string>::iterator stdIte)	{

			std::string * ft_ptr = &(*ftIt);
			std::string * std_ptr = &(*stdIt);

			std::string * ret_ft_ptr = &(*ft_c0.erase(ftIt, ftIte));
			std::string * ret_std_ptr = &(*std_c0.erase(stdIt, stdIte));

			if (ft_ptr != ret_ft_ptr || std_ptr != ret_std_ptr)	{
				std::cout << "ft\tPtr expected = " << ft_ptr << ", got = " << ret_ft_ptr << std::endl;
				std::cout << "std\tPtr expected = " << std_ptr << ", got = " << ret_std_ptr << std::endl;
			}
			testVector(ft_c0, std_c0, NOPRINT);
			testBool(ft_ptr == ret_ft_ptr && std_ptr == ret_std_ptr, __FILE__, __LINE__);
}

int
test_vector_insert_erase( void )	{

	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " with std::string ~~~~~~~~~~~" << RESET_COLOR << std::endl;

		std::cout << TITLE << "[ INSERT ]" << RESET_COLOR << std::endl;
		testInsert();
		testInsert(1);
		testInsert(3);
		testInsert(100000);
		{
			ft::vector<std::string>		ft_c0(20, "XX");
			std::vector<std::string>	std_c0(20, "XX");

			testInsert(ft_c0.begin(), ft_c0.end(), std_c0.begin(), std_c0.end());
			testInsert(++ft_c0.begin(), --ft_c0.end(), ++std_c0.begin(), --std_c0.end());
		}

		testErase();

		{
			size_t	testSize = 40;
			std::cout << HEADER_TITLE << "[ Instanciate vector with "<< testSize <<" \"XX\" ]" << RESET_COLOR << std::endl;
			ft::vector<std::string>		ft_c0(testSize, "XX");
			std::vector<std::string>	std_c0(testSize, "XX");
			testVector(ft_c0, std_c0, NOPRINT);
			std::cout << SUBTITLE << "[ Erase with various erase(iterator, iterator) ]" << RESET_COLOR << std::endl;

			ft::vector<std::string>::iterator	ftIt = ft_c0.begin();
			ft::vector<std::string>::iterator	ftIte = ft_c0.end() - ft_c0.size() / 2;
			std::vector<std::string>::iterator	stdIt = std_c0.begin();
			std::vector<std::string>::iterator	stdIte = std_c0.end() - std_c0.size() / 2;

			testEraseRange(ft_c0, std_c0, ftIt, ftIte, stdIt, stdIte);

			ftIt = ft_c0.begin();
			ftIte = ft_c0.begin() + 1;
			stdIt = std_c0.begin();
			stdIte = std_c0.begin() + 1;
			testEraseRange(ft_c0, std_c0, ftIt, ftIte, stdIt, stdIte);

			ftIt = ft_c0.end() - 5;
			ftIte = ft_c0.end() - 0;
			stdIt = std_c0.end() - 5;
			stdIte = std_c0.end() - 0;
			testEraseRange(ft_c0, std_c0, ftIt, ftIte, stdIt, stdIte);

			ftIt = ft_c0.begin() + 4;
			ftIte = ft_c0.begin() + 11;
			stdIt = std_c0.begin() + 4;
			stdIte = std_c0.begin() + 11;
			testEraseRange(ft_c0, std_c0, ftIt, ftIte, stdIt, stdIte);

			ftIt = ft_c0.begin();
			ftIte = ft_c0.end();
			stdIt = std_c0.begin();
			stdIte = std_c0.end();
			testEraseRange(ft_c0, std_c0, ftIt, ftIte, stdIt, stdIte);
		}
	return (0);
}
