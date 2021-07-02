/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_capacities.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 09:56:19 by bvalette          #+#    #+#             */
/*   Updated: 2021/07/02 09:06:41 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <limits>
# include "./tester/exampleClass.hpp"
# include "./tester/bvaletteTester_set.hpp"

template <typename T>
class foo {
	public:
		typedef T	value_type;

		foo(void) : value(), _verbose(false) { };
		foo(value_type src, const bool verbose = false) : value(src), _verbose(verbose) { };
		foo(foo const &src, const bool verbose = false) : value(src.value), _verbose(verbose) { };
		~foo(void) { if (this->_verbose) std::cout << "~foo::foo()" << std::endl; };

		void m(void) 		{ std::cout << "foo::m called [" << this->value << "]" << std::endl; };
		void m(void) const	{ std::cout << "foo::m const called [" << this->value << "]" << std::endl; };

		foo &operator=(value_type src) { this->value = src; return *this; };
		foo &operator=(foo const &src) {
			if (this->_verbose || src._verbose)
				std::cout << "foo::operator=(foo) CALLED" << std::endl;
			this->value = src.value;
			return *this;
		};

		value_type	getValue(void) const { return this->value; };
		void		switchVerbose(void) { this->_verbose = !(this->_verbose); };

		operator value_type(void) const {
			return value_type(this->value);
		}

	private:
		value_type	value;
		bool		_verbose;

};

template <typename T>
class bar {
	public:

		bar(void) {};
		~bar(void) {};

	private:
		T			value;
		bool		_verbose;

};

template < typename T>
void
test_max_size()	{
	size_t std_c0 = std::set<const T>().max_size();
	size_t ft_c0 = ft::set<const T>().max_size();
	std::cout << "Sizes returned : ft("<< ft_c0 <<") std("<< std_c0 <<")" << RESET_COLOR << std::endl;
	try {
		testBool(std_c0 == ft_c0, __LINE__);
	}
	catch (failedTest &e) {
		std::cout << ERROR_TITLE << "Sizes returned : ft("<< ft_c0/100000000000000 <<") std("<< std_c0/100000000000000 <<")" << RESET_COLOR << std::endl;
		throw failedTest();
	}
}

int
test_set_capacities( void )	{

	std::cout << TITLE << "~~~~~~~~~~~ " << __func__ << " ~~~~~~~~~~~" << RESET_COLOR << std::endl;

	{
		size_t		testSize = 5;

		std::cout << HEADER_TITLE << "[ Empty / size on empty set ]" << RESET_COLOR << std::endl;
		std::set<int>		std_c0;
		ft::set<int>		ft_c0;
		testBool(std_c0.empty() == ft_c0.empty(), __LINE__);
		testBool(std_c0.size() == ft_c0.size(), __LINE__);

		std::cout << HEADER_TITLE << "[ Empty / size on non empty set ]" << RESET_COLOR << std::endl;
		for(int i = 0; i < static_cast<int>(testSize); i++)	{
			std_c0.insert(i);
			ft_c0.insert(i);
			testBool(std_c0.empty() == ft_c0.empty(), __LINE__, i);
			testBool(std_c0.size() == ft_c0.size(), __LINE__, i);
		}
	}
	std::cout << HEADER_TITLE << "[ Max Size with various types ]" << RESET_COLOR << std::endl;

	std::cout << HEADER_TITLE << "[ Max Size with various types ]" << RESET_COLOR << std::endl;
	int error_line = __LINE__;
	try {
		std::cout << "Test <bar<bool> >		: " ;			test_max_size<bar<bool> >();		error_line = __LINE__ + 1;
		std::cout << "Test <bar<double> >		: " ;			test_max_size<bar<double> >();		error_line = __LINE__ + 1;
		std::cout << "Test <int >		: " ;			test_max_size<int>();		error_line = __LINE__ + 1;
		std::cout << "Test <int >		: " ;			test_max_size<int>();		error_line = __LINE__ + 1;
		std::cout << "Test <bar<int> >		: " ;			test_max_size<bar<int> >();		error_line = __LINE__ + 1;
		std::cout << "Test <foo<bool> >		: " ;			test_max_size<foo<bool> >();		error_line = __LINE__ + 1;
		std::cout << "Test <foo<double> >		: " ;			test_max_size<foo<double> >();		error_line = __LINE__ + 1;
		std::cout << "Test <foo<int> >		: " ;			test_max_size<foo<int> >();		error_line = __LINE__ + 1;
		std::cout << "Test <double>		: " ;			test_max_size<long>();		error_line = __LINE__ + 1;
		std::cout << "Test <int>			: " ;			test_max_size<int>();		error_line = __LINE__ + 1;
		std::cout << "Test <float>		: " ;			test_max_size<float>();		error_line = __LINE__ + 1;
		std::cout << "Test <double>		: " ;			test_max_size<double>();		error_line = __LINE__ + 1;
		std::cout << "Test <std::string>		: " ;	test_max_size<std::string>();		error_line = __LINE__ + 1;
		std::cout << "Test <exampleClass>	: " ;		test_max_size<exampleClass>();		error_line = __LINE__ + 1;
		std::cout << "Test <int>		: " ;				test_max_size<int>();		error_line = __LINE__ + 1;
		std::cout << "Test <int>		: " ;				test_max_size<int>();		error_line = __LINE__ + 1;
		std::cout << "Test <int>		: " ;				test_max_size<int>();		error_line = __LINE__ + 1;
		std::cout << "Test <int>		: " ;				test_max_size<int>();		error_line = __LINE__ + 1;
		std::cout << "Test <int>		: " ;				test_max_size<int>();		error_line = __LINE__ + 1;
		std::cout << "Test <int>	: " ;				test_max_size<int>();		error_line = __LINE__ + 1;
		std::cout << "Test <int>	: " ;		test_max_size<int>();		error_line = __LINE__ + 1;
		std::cout << "Test <int>	: " ;		test_max_size<int>();		error_line = __LINE__ + 1;
		std::cout << "Test <bool>			: " ;				test_max_size<bool>();		error_line = __LINE__ + 1;
		std::cout << "Test <short>			: " ;				test_max_size<short>();		error_line = __LINE__ + 1;
		std::cout << "Test <char>			: " ;				test_max_size<char>();		error_line = __LINE__ + 1;
		std::cout << "Test <int>			: " ;				test_max_size<int>();		error_line = __LINE__ + 1;
		std::cout << "Test <float>			: " ;				test_max_size<float>();		error_line = __LINE__ + 1;
		std::cout << "Test <double>		: " ;				test_max_size<double>();		error_line = __LINE__ + 1;
		std::cout << "Test <std::string>	: " ;		test_max_size<std::string>();		error_line = __LINE__ + 1;
		std::cout << "Test <exampleClass>	: " ;		test_max_size<exampleClass>();		error_line = __LINE__ + 1;
	}
	catch (std::exception &e)	{

		std::cout << "\033[041m [ FAILURE at " << __FILE__ << ":" << error_line << "]  \xf0\x9f\x94\xb4 The tester will keep going because this test may perform differently on different OS." << RESET_COLOR << " \t \342\235\214" << std::endl;


	}


	// -- requires node specialization
	// std::cout << "Test <bool, short>			: ";			test_max_size<bool, bool>();
	// std::cout << "Test <bool, bool>			: ";				test_max_size<bool, bool>();
	// std::cout << "Test <short, short>		: ";				test_max_size<short, short>();
	// std::cout << "Test <char, char>			: ";				test_max_size<char, char>();


	return (0);
}
