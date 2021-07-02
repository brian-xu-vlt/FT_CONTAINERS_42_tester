#ifndef EXAMPLECLASS_HPP
# define EXAMPLECLASS_HPP

#include <iostream>
#include <string>
# include "./bvaletteTester_defines.hpp"

class exampleClass	{

	public:

		std::string a;
		int			b;

		exampleClass( void ) : a("HelloWorld"), b(42)	{

			if (DEBUG_MODE >=3) std::cout << "Ctor exampleClass.." << std::endl;
		};

		exampleClass( int i ) : a("HelloWorld"), b(i)	{

			if (DEBUG_MODE >=3) std::cout << "Ctor exampleClass.." << std::endl;
		};

		exampleClass( const exampleClass& src ) : a(src.a), b(src.b)	{

			if (DEBUG_MODE >=3) std::cout << "Ctor exampleClass.." << std::endl;
		};

		~exampleClass( void ) {
			if (DEBUG_MODE >=3) std::cout << "Dtor exampleClass.." << std::endl;
		};

		exampleClass & operator=( exampleClass const & rhs )	{
			if (DEBUG_MODE >=3) std::cout << "Equal operator =" << std::endl;
			if ( this != &rhs )
			{
				this->a = rhs.a;
				this->b = rhs.b;
			}
			return *this;
		}
};

inline bool
operator<( const exampleClass& lhs, const exampleClass& rhs ) {
	return (lhs.b < rhs.b);
}

inline bool
operator==( const exampleClass& lhs, const exampleClass& rhs ) {
	return (lhs.b == rhs.b && lhs.a == rhs.a);
}

inline bool
operator!=( const exampleClass& lhs, const exampleClass& rhs ) {
	return (!(lhs==rhs));
}

inline std::ostream&
operator<<( std::ostream & o, exampleClass const & i )	{
	o << i.b << " - " << i.a;
	return o;
};

#endif
