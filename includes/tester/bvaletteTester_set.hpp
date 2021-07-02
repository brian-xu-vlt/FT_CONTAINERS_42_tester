#ifndef BVALETTETESTER_SET_HPP
# define BVALETTETESTER_SET_HPP

# include "../your_headers.hpp"
# include "./tester/bvaletteTester.hpp"

/**	===========================================================================+
 *  ----------- TESTER FOR MAP ------------------------------------------------|
 **	===========================================================================+
*/

template< typename T, typename Compare, typename Alloc>
void
putSet( ft::set<T, Compare, Alloc> const & container, int errorPos = -1 )	{

	std::cout << PRINT_TITLE << "[ FT::set ]" << RESET_COLOR << std::endl;
	std::cout << PRINT_TITLE << "[ size of set ]" << RESET_COLOR << " -> ";
	std::cout << container.size() << std::endl;
	typename ft::set<T, Compare, Alloc>::const_iterator it = container.begin();
	typename ft::set<T, Compare, Alloc>::const_iterator ite = container.end();

	int	printMax;

	if (container.size() > 100)
		printMax = 10;
	else
		printMax = static_cast<int>(container.size());
	for (int i = 0; container.size() > 0 && i <= printMax && it != ite; it++, i++)
	{
		if (i == errorPos || i > static_cast<int>(container.size()))
			std::cout << ERROR_SOURCE << "ft: [" << i << "] " << RESET_COLOR << *it<< " @ " << &(*it) << std::endl;
		else
			std::cout << "ft: [" << i << "] " << *it<< " @ " << &(*it) << std::endl;
	}
	if (printMax != static_cast<int>(container.size()))
		std::cout << " !!\t set size is too large to print... stoping here." << std::endl;
}

template< typename T, typename Compare, typename Alloc>
void
putSet( std::set<T, Compare, Alloc> const & container, int errorPos = -1 )	{

	std::cout << PRINT_STD_TITLE << "[ STD::set ]" << RESET_COLOR << std::endl;
	std::cout << PRINT_STD_TITLE << "[ size of set ]" << RESET_COLOR << " -> ";
	std::cout << container.size() << std::endl;
	typename std::set<T, Compare, Alloc>::const_iterator it = container.begin();
	typename std::set<T, Compare, Alloc>::const_iterator ite = container.end();

	int	printMax;

	if (container.size() > 100)
		printMax = 10;
	else
		printMax = static_cast<int>(container.size());
	for (int i = 0; container.size() > 0 && i <= printMax && it != ite; it++, i++)
	{
		if (i == errorPos || i > static_cast<int>(container.size()))
			std::cout << ERROR_SOURCE << "std: [" << i << "] " << RESET_COLOR << *it<< " @ " << &(*it) << std::endl;
		else
			std::cout << "std: [" << i << "] " << *it<< " @ " << &(*it) << std::endl;
	}
	if (printMax != static_cast<int>(container.size()))
		std::cout << " !!\t set size is too large to print... stoping here." << std::endl;
}


template<
			class T,
			class Compare = std::less<T>,
			class ftAlloc = std::allocator<T>,
			class stdAlloc = std::allocator<T> >
void
testSet( ft::set<T, Compare, ftAlloc> const & ft_c, std::set<T, Compare, stdAlloc> const &std_c,
bool print, std::string message = "" )	{

	bool	success = true;

	if (message.empty() == false)
		std::cout << SUBTITLE << message << RESET_COLOR << std::endl;

	if (print == true)
	{
		putSet<T>(ft_c);
		putSet<T>(std_c);
	}

	if(ft_c.size() != std_c.size())	{
		if (print == false && success == true)
		{
			putSet<T>(ft_c);
			putSet<T>(std_c);
		}
		std::cout << TITLE <<"size: ft (" << ft_c.size() << ") std (" << std_c.size() << ") Diff ! " << RESET_COLOR << std::endl;
		std::cout << ERROR_TITLE << "ERROR !" << RESET_COLOR << std::endl;
		if (DEBUG_MODE < 1)
			throw failedTest();
		else
			success = false;
	}

	if (ft_c.size() > 0)
	{
		int i = 0;
		typename ft::set<T, Compare, ftAlloc>::const_iterator	ft_it = ft_c.begin();
		typename ft::set<T, Compare, ftAlloc>::const_iterator	ft_ite = ft_c.end();

		typename std::set<T, Compare, stdAlloc>::const_iterator	std_it = std_c.begin();
		typename std::set<T, Compare, stdAlloc>::const_iterator	std_ite = std_c.end();
		while (ft_it != ft_ite && std_it != std_ite)	{

			if(*ft_it!= *std_it)	{
				putSet<T>(ft_c, i);
				putSet<T>(std_c, i);
				std::cout << TITLE <<"iterator at pos " << i << ": ft (" << *ft_it<< ")";
				std::cout << " / std (" << *std_it<< ") Diff ! " << RESET_COLOR << std::endl;
				std::cout << ERROR_TITLE << "ERROR !" << RESET_COLOR << std::endl;
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
				putSet<T>(ft_c);
				putSet<T>(std_c);
			}
			std::cout << TITLE <<"Diff in set after iterating thought it." << RESET_COLOR << std::endl;
			std::cout << ERROR_TITLE << "ERROR !" << RESET_COLOR << std::endl;
			if (DEBUG_MODE < 1)
				throw failedTest();
			else
				success = false;
		}
	}

	if (print == true && success == true)
		std::cout << TESTOK_TITLE << "[ TEST PASSED: no diff ] set size: ft(" << ft_c.size() << ") std(" << std_c.size() << ")" << RESET_COLOR << "\t  \342\234\205" << std::endl;
	else if (success == true)
		std::cout << "[ TEST PASSED: no diff ] set size: ft(" << ft_c.size() << ") std(" << std_c.size() << ") \t \342\234\205" << std::endl;
	else
		std::cout << ERROR_TITLE << "TEST FAILED !" << RESET_COLOR << std::endl;
}

/**	===========================================================================+
 *  ----------- TESTER FUNCTIONS ----------------------------------------------|
 **	===========================================================================+
*/

int	main_tester_set( void );
int	test_set_instantiation( void );
int	test_set_insert_erase( void );
int	test_set_key_compare_value_compare();

int	test_set_push_back_pop_back( void );
int	test_set_clear( void );
int	test_set_find( void );
int	test_set_count( void );
int	test_set_lower_bound( void );
int	test_set_upper_bound( void );
int	test_set_equal_range( void );

int	test_set_capacities( void );
int	test_set_operatorEqual( void );
int	test_set_resize( void );
int	test_set_assign( void );
int	test_set_at_operatorBrackets( void );
int	test_set_member_swap( void );
int	test_set_swap( void );
int	test_set_relational_operators( void );
int	test_set_splice( void );
int	test_set_remove_if( void );
int	test_set_remove( void );
int	test_set_unique( void );
int	test_set_merge( void );
int	test_set_sort( void );
int	test_set_iterator( void );
int	test_set_reverseIterator( void );
int	test_set_reverse( void );
int	test_set_element_access( void );

#endif
