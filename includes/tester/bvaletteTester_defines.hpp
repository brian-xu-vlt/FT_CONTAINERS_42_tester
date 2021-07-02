#ifndef BVALETTETESTER_DEFINES_HPP
# define BVALETTETESTER_DEFINES_HPP

#ifndef DEBUG_MODE
# define DEBUG_MODE 0
#endif

#ifndef VALGRIND_MODE
# define VALGRIND_MODE 0
#endif

#ifndef RESET_COLOR
# define RESET_COLOR   "\033[0m"
#endif

#ifndef MAIN_TITLE
# define MAIN_TITLE    "\n\033[32m\033[7m\033[4m"
#endif

#ifndef TITLE
# define TITLE    "\n SUBTEST FUNCTION: \033[32m\033[7m"
#endif

#ifndef ERROR_TITLE
# define ERROR_TITLE    "\n\033[41m\t"
#endif

#ifndef ERROR_SOURCE
# define ERROR_SOURCE    "\n\033[5m\033[041m"
#endif

#ifndef BLINK
# define BLINK    "\033[05m"
#endif

#ifndef SUBTITLE
# define SUBTITLE    "\n\033[7m"
#endif

#ifndef HEADER_TITLE
# define HEADER_TITLE    "\n   \xF0\x9F\x86\x95 \033[43m\033[30m "
#endif

#ifndef PRINT_TITLE
# define PRINT_TITLE    "\n\033[43m\t"
#endif

#ifndef PRINT_STD_TITLE
# define PRINT_STD_TITLE    "\n\033[44m\t"
#endif

#ifndef TESTOK_TITLE
# define TESTOK_TITLE    "\n\033[102m\t"
#endif

#ifndef PRINT
# define PRINT		true
#endif

#ifndef PRINT
# define NOPRINT	false
#endif

#endif
