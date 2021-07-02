EOC = \033[0m
BOLD = \033[1m
GREEN = \033[32m
YELLOW = \033[33m

NAME := ft_container

INCLUDES += ./includes/
SRCS_DIR = ./srcs
CC = clang++
OBJ_DIR = ./objs_$(NAME)/
PCH_DIR = ./pchs_$(NAME)/

CFLAGS += -Wall
CFLAGS += -Wextra
# CFLAGS += -g3

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	CFLAGS += -fPIC
endif

ifeq ($(UNAME_S),Darwin)
	CFLAGS += -Wno-self-assign-overloaded
	CFLAGS += -Wno-deprecated-copy
endif

ifeq ($(noassert), 1)
	CFLAGS += -DNDEBUG=1
endif

ifeq ($(valgrind_mode), 1)
	CFLAGS += -D VALGRIND_MODE=1
else
	CFLAGS += -D VALGRIND_MODE=0
endif

ifeq ($(print_all), 1)
	OTHER_FLAGS += -D NOPRINT=1
else
	OTHER_FLAGS += -D NOPRINT=0
endif

ifeq ($(unused), 1)
	CFLAGS += -Wno-unused
endif

ifeq ($(help), 1)
	CFLAGS += -Wconversion
else ifeq ($(help), 2)
	CFLAGS += -Wsuggest-attribute=pure
else ifeq ($(help), 3)
	CFLAGS += -Wsuggest-attribute=const
else ifeq ($(help), 4)
	CFLAGS += -Wsuggest-attribute=noreturn
else ifeq ($(help), 5)
	CFLAGS += -fsanitize-undefined-trap-on-error
else ifneq ($(no_error), 1)
	CFLAGS += -Werror
endif

ifeq ($(debug), 1)
	CFLAGS += -g3
else ifeq ($(debug), 2)
	CFLAGS += -fsanitize=address,undefined
	CFLAGS += -g3
else ifeq ($(debug), 3)
	CFLAGS += -fsanitize=address,undefined
	CFLAGS += -g3
	CFLAGS += -Wpadded
else ifeq ($(debug), 4)
	CFLAGS += -fsanitize=address,undefined
	CFLAGS += -g3
	CFLAGS += -Wpadded
	ifneq ($(CC), gcc)
		CFLAGS += -Weverything
	endif
endif

ifeq ($(opti), 1)
	CFLAGS += -O3
endif

ifeq ($(debug_mode), 1)
	CFLAGS += -D DEBUG_MODE=1
else ifeq ($(debug_mode), 2)
	CFLAGS += -D DEBUG_MODE=2
else ifeq ($(debug_mode), 3)
	CFLAGS += -D DEBUG_MODE=3
else ifeq ($(debug_mode), 4)
	CFLAGS += -D DEBUG_MODE=4
endif

PROJECT_HEADER += ./your_headers.hpp

HEADER += ./bvaletteTester.hpp
HEADER += ./bvaletteTester_defines.hpp
HEADER += ./bvaletteTester_list.hpp
HEADER += ./bvaletteTester_vector.hpp
HEADER += ./bvaletteTester_deque.hpp
HEADER += ./bvaletteTester_map.hpp
HEADER += ./bvaletteTester_set.hpp
HEADER += ./exampleClass.hpp
HEADER += ./compClass.hpp

################################################################################
#-------- MAIN #################################################################
################################################################################

SRCS += ./main.cpp
SRCS += ./main_utils.cpp

################################################################################
#-------- LIST #################################################################
################################################################################

SRCS += ./main_tester_list.cpp

SRCS += ./test_list_instantiation.cpp
SRCS += ./test_list_push_back_push_front_pop_back_pop_front.cpp
SRCS += ./test_list_clear.cpp
SRCS += ./test_list_capacities.cpp
SRCS += ./test_list_insert_erase.cpp
SRCS += ./test_list_operatorEqual.cpp
SRCS += ./test_list_resize.cpp
SRCS += ./test_list_assign.cpp
SRCS += ./test_list_member_swap.cpp
SRCS += ./test_list_nonmember_swap.cpp
SRCS += ./test_list_relational_operators.cpp
SRCS += ./test_list_splice.cpp
SRCS += ./test_list_remove_if.cpp
SRCS += ./test_list_remove.cpp
SRCS += ./test_list_unique.cpp
SRCS += ./test_list_merge.cpp
SRCS += ./test_list_sort.cpp
SRCS += ./test_list_iterator.cpp
SRCS += ./test_list_reverseIterator.cpp
SRCS += ./test_list_reverse.cpp
SRCS += ./test_list_element_access.cpp

################################################################################
#-------- VECTOR ###############################################################
################################################################################

SRCS += ./main_tester_vector.cpp

SRCS += ./test_vector_instantiation.cpp
SRCS += ./test_vector_push_back_pop_back.cpp
SRCS += ./test_vector_clear.cpp
SRCS += ./test_vector_capacities.cpp
SRCS += ./test_vector_insert_erase.cpp
SRCS += ./test_vector_operatorEqual.cpp
SRCS += ./test_vector_resize.cpp
SRCS += ./test_vector_assign.cpp
SRCS += ./test_vector_at_operatorBrackets.cpp
SRCS += ./test_vector_member_swap.cpp
SRCS += ./test_vector_nonmember_swap.cpp
SRCS += ./test_vector_relational_operators.cpp
SRCS += ./test_vector_iterator.cpp
SRCS += ./test_vector_reverseIterator.cpp
SRCS += ./test_vector_element_access.cpp

################################################################################
#-------- STACK  ###############################################################
################################################################################

SRCS += ./main_tester_stack.cpp

SRCS += ./test_stack_general.cpp

# ################################################################################
# #-------- QUEUE  ###############################################################
# ################################################################################

SRCS += ./main_tester_queue.cpp

SRCS += ./test_queue_general.cpp

################################################################################
#-------- DEQUE  ###############################################################
################################################################################

SRCS += ./main_tester_deque.cpp

SRCS += ./test_deque_instantiation.cpp
SRCS += ./test_deque_push_pop.cpp
SRCS += ./test_deque_clear.cpp
SRCS += ./test_deque_capacities.cpp
SRCS += ./test_deque_insert_erase.cpp
SRCS += ./test_deque_operatorEqual.cpp
SRCS += ./test_deque_resize.cpp
SRCS += ./test_deque_assign.cpp
SRCS += ./test_deque_at_operatorBrackets.cpp
SRCS += ./test_deque_member_swap.cpp
SRCS += ./test_deque_nonmember_swap.cpp
SRCS += ./test_deque_relational_operators.cpp
SRCS += ./test_deque_iterator.cpp
SRCS += ./test_deque_reverseIterator.cpp
SRCS += ./test_deque_element_access.cpp

################################################################################
#-------- MAP    ###############################################################
################################################################################

SRCS += ./main_tester_map.cpp

SRCS += ./test_map_instantiation.cpp
SRCS += ./test_map_insert_erase.cpp
SRCS += ./test_map_capacities.cpp
SRCS += ./test_map_iterator.cpp
SRCS += ./test_map_at_operatorBrackets.cpp
SRCS += ./test_map_swap.cpp
SRCS += ./test_map_clear.cpp
SRCS += ./test_key_compare_value_compare.cpp
SRCS += ./test_map_operatorEqual.cpp
SRCS += ./test_map_find.cpp
SRCS += ./test_map_count.cpp
SRCS += ./test_map_lower_bound.cpp
SRCS += ./test_map_upper_bound.cpp
SRCS += ./test_map_equal_range.cpp
SRCS += ./test_map_reverseIterator.cpp

################################################################################
#-------- SET    ###############################################################
################################################################################

SRCS += ./main_tester_set.cpp

SRCS += ./test_set_instantiation.cpp
SRCS += ./test_set_insert_erase.cpp
SRCS += ./test_set_capacities.cpp
SRCS += ./test_set_iterator.cpp
SRCS += ./test_set_swap.cpp
SRCS += ./test_set_clear.cpp
SRCS += ./test_set_key_compare_value_compare.cpp
SRCS += ./test_set_operatorEqual.cpp
SRCS += ./test_set_find.cpp
SRCS += ./test_set_count.cpp
SRCS += ./test_set_lower_bound.cpp
SRCS += ./test_set_upper_bound.cpp
SRCS += ./test_set_equal_range.cpp
SRCS += ./test_set_reverseIterator.cpp

vpath %.cpp ./srcs
vpath %.cpp ./srcs/list_tests
vpath %.cpp ./srcs/vector_tests
vpath %.cpp ./srcs/deque_tests
vpath %.cpp ./srcs/stack_tests
vpath %.cpp ./srcs/queue_tests
vpath %.cpp ./srcs/map_tests
vpath %.cpp ./srcs/set_tests

vpath %.hpp ./includes
vpath %.hpp ./includes/tester

vpath %.hpp ./includes/list
vpath %.hpp ./includes/vector
vpath %.hpp ./includes/deque
vpath %.hpp ./includes/stack
vpath %.hpp ./includes/queue
vpath %.hpp ./includes/map
vpath %.hpp ./includes/set

vpath %.hpp ./includes/utils

OBJS = $(patsubst %.cpp, $(OBJ_DIR)%.o, $(SRCS))
PCHS = $(patsubst %.hpp, $(PCH_DIR)%.pch, $(PROJECT_HEADER))

all :
	$(MAKE) $(NAME)
	@echo
	@echo

vector : all
	@echo
	@echo "🎉 \033[32m Ready to test $@ !\033[0m ✅"
	@./$(NAME) $@ | cat -n

list : all
	@echo
	@echo "🎉 \033[32m Ready to test $@ !\033[0m ✅"
	@./$(NAME) $@ | cat -n

map : all
	@echo
	@echo "🎉 \033[32m Ready to test $@ !\033[0m ✅"
	@./$(NAME) $@ | cat -n

set : all
	@echo
	@echo "🎉 \033[32m Ready to test $@ !\033[0m ✅"
	@./$(NAME) $@ | cat -n

queue : all
	@echo
	@echo "🎉 \033[32m Ready to test $@ !\033[0m ✅"
	@./$(NAME) $@ | cat -n

stack : all
	@echo
	@echo "🎉 \033[32m Ready to test $@ !\033[0m ✅"
	@./$(NAME) $@ | cat -n

deque : all
	@echo
	@echo "🎉 \033[32m Ready to test $@ !\033[0m ✅"
	@./$(NAME) $@ | cat -n

$(OBJS): $(OBJ_DIR)%.o: %.cpp $(PROJECT_HEADER) $(HEADER)
	$(CC) -std=c++11 $(CFLAGS) $(OTHER_FLAGS) -c $<  -I $(INCLUDES) -o $@

$(NAME): $(PCH_DIR) $(PCHS) $(OBJ_DIR) $(OBJS)
	$(CC) -std=c++11 $(CFLAGS) $(OBJS) -I $(INCLUDES) -o $@
	@echo "🎉 \033[32m$@ is ready !\033[0m ✅"

$(PCHS): $(PCH_DIR)%.pch: %.hpp $(PROJECT_HEADER)
	$(CC) -std=c++98 $(CFLAGS) $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

$(PCH_DIR):
	@mkdir -p $@

pch:
	$(MAKE) $(PCHS)

FORCE :

clean :
	$(RM) -R $(OBJ_DIR) $(PCH_DIR)

fclean : clean
	$(RM) $(NAME) output.log

re : fclean
	@$(MAKE)

f : all
	@echo
	@echo
	@./$(NAME) | cat -n

cmp: all
	./$(NAME) > output.log
	@echo "\n 🎉  \033[32m Colordiff. Reference on the left, my output on the right\033[0m"
	diff -y ./subject.log ./output.log

.PHONY: all clean fclean mclean re FORCE cmp
#.SILENT:
