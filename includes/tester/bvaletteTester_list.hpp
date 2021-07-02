# include "../your_headers.hpp"
# include "./tester/bvaletteTester.hpp"

#ifndef BVALETTETESTER_LIST_HPP
# define BVALETTETESTER_LIST_HPP


/**	===========================================================================+
 *  ----------- TESTER FOR LIST -----------------------------------------------|
 **	===========================================================================+
*/

template< typename T>
void
putList( ft::list<T> const & lst, int errorPos = -1 )	{

	std::cout << PRINT_TITLE << "[ FT::LIST ]" << RESET_COLOR << std::endl;
	std::cout << PRINT_TITLE << "[ size of list ]" << RESET_COLOR << " -> ";
	std::cout << lst.size() << std::endl;
	typename ft::list<T>::const_iterator it = lst.begin();
	typename ft::list<T>::const_iterator ite = lst.end();

	int	printMax;

	if (lst.size() > 100)
		printMax = 10;
	else
		printMax = static_cast<int>(lst.size());
	for (int i = 0; lst.size() > 0 && i <= printMax && it != ite; it++, i++)
	{
		if (i == errorPos || i > static_cast<int>(lst.size()))
			std::cout << ERROR_SOURCE << "ft: [" << i << "] " << RESET_COLOR << *it << " -> " << &(*it) << std::endl;
		else
			std::cout << "ft: [" << i << "] " <<*it << " -> " << &(*it) << std::endl;
	}
	if (printMax != static_cast<int>(lst.size()))
		std::cout << " !!\t List size is too large to print... stoping here." << std::endl;
}

template< typename T>
void
putList( std::list<T> const & lst, int errorPos = -1 )	{

	std::cout << PRINT_STD_TITLE << "[ STD::LIST ]" << RESET_COLOR << std::endl;
	std::cout << PRINT_STD_TITLE << "[ size of list ]" << RESET_COLOR << " -> ";
	std::cout << lst.size() << std::endl;
	typename std::list<T>::const_iterator it = lst.begin();
	typename std::list<T>::const_iterator ite = lst.end();

	int	printMax;

	if (lst.size() > 100)
		printMax = 10;
	else
		printMax = static_cast<int>(lst.size());
	for (int i = 0; lst.size() > 0 && i <= printMax && it != ite; it++, i++)
	{
		if (i == errorPos || i > static_cast<int>(lst.size()))
			std::cout << ERROR_SOURCE << "std: [" << i << "] " << RESET_COLOR << *it << " -> " << &(*it) << std::endl;
		else
			std::cout << "std: [" << i << "] " <<*it << " -> " << &(*it) << std::endl;
	}
	if (printMax != static_cast<int>(lst.size()))
		std::cout << " !!\t List size is too large to print... stoping here." << std::endl;
}


template< typename T>
void
testList( ft::list<T> const & ft_lst, std::list<T> const &std_lst,
bool print, std::string message = "" )	{

	bool	success = true;

	if (message.empty() == false)
		std::cout << SUBTITLE << message << RESET_COLOR << std::endl;

	if (print == true)
	{
		putList<T>(ft_lst);
		putList<T>(std_lst);
	}

	if(ft_lst.size() != std_lst.size())	{
		if (print == false && success == true)
		{
			putList<T>(ft_lst);
			putList<T>(std_lst);
		}
		std::cout << TITLE <<"size: ft (" << ft_lst.size() << ") std (" << std_lst.size() << ") Diff ! " << RESET_COLOR << std::endl;
		std::cout << ERROR_TITLE << "ERROR !" << RESET_COLOR << std::endl;
		if (DEBUG_MODE < 1)
			throw failedTest();
		else
			success = false;
	}

	if (ft_lst.size() > 0)
	{
		int i = 0;
		typename ft::list<T>::const_iterator	ft_it = ft_lst.begin();
		typename ft::list<T>::const_iterator	ft_ite = ft_lst.end();

		typename std::list<T>::const_iterator	std_it = std_lst.begin();
		typename std::list<T>::const_iterator	std_ite = std_lst.end();
		while (ft_it != ft_ite && std_it != std_ite)	{

			if(*ft_it != *std_it)	{
				if (print == false && success == true)
				{
					putList<T>(ft_lst, i);
					putList<T>(std_lst, i);
				}
				std::cout << TITLE <<"iterator at pos " << i << ": ft (" << *ft_it << ") " << RESET_COLOR;
				std::cout << ERROR_TITLE << "ERROR !" << RESET_COLOR << std::endl;
				std::cout << "std (" << *std_it << ") Diff ! " << RESET_COLOR << std::endl;
				if (DEBUG_MODE < 1)
					throw failedTest();
				else
					success = false;
			}
			i++;
			ft_it++;
			std_it++;
		}
		if (ft_it != ft_ite || std_it != std_ite)	{
			if (print == false && success == true)
			{
				putList<T>(ft_lst);
				putList<T>(std_lst);
			}
			std::cout << TITLE <<"Diff in list after iterating thought it." << RESET_COLOR << std::endl;
			std::cout << ERROR_TITLE << "ERROR !" << RESET_COLOR << std::endl;
			if (DEBUG_MODE < 1)
				throw failedTest();
			else
				success = false;
		}
	}

	if (print == true && success == true)
		std::cout << TESTOK_TITLE << "[ TEST PASSED: no diff ] list sizes: ft(" << ft_lst.size() <<") std(" << std_lst.size() << ")" << RESET_COLOR << "\t  \342\234\205" << std::endl;
	else if (success == true)
		std::cout << "[ TEST PASSED: no diff ] list sizes: ft(" << ft_lst.size() <<") std(" << std_lst.size() << ") \t \342\234\205" << std::endl;
	else
		std::cout << ERROR_TITLE << "TEST FAILED !" << RESET_COLOR << std::endl;
}

/**	===========================================================================+
 *  ----------- TESTER FUNCTION -----------------------------------------------|
 **	===========================================================================+
*/

int	main_tester_list( void );

int	test_list_instantiation( void );
int	test_list_push_back_push_front_pop_back_pop_front( void );
int	test_list_clear( void );
int	test_list_capacities( void );
int	test_list_insert_erase( void );
int	test_list_operatorEqual( void );
int	test_list_resize( void );
int	test_list_assign( void );
int	test_list_member_swap( void );
int	test_list_nonmember_swap( void );
int	test_list_relational_operators( void );
int	test_list_splice( void );
int	test_list_remove_if( void );
int	test_list_remove( void );
int	test_list_unique( void );
int	test_list_merge( void );
int	test_list_sort( void );
int	test_list_iterator( void );
int	test_list_reverseIterator( void );
int	test_list_reverse( void );
int	test_list_element_access( void );

#endif
