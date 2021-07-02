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

SRCS += ./main_utils.cpp

################################################################################
#-------- LIST #################################################################
################################################################################

SRCS_LIST += ./main_tester_list.cpp
SRCS_LIST += ./test_list_instantiation.cpp
SRCS_LIST += ./test_list_push_back_push_front_pop_back_pop_front.cpp
SRCS_LIST += ./test_list_clear.cpp
SRCS_LIST += ./test_list_capacities.cpp
SRCS_LIST += ./test_list_insert_erase.cpp
SRCS_LIST += ./test_list_operatorEqual.cpp
SRCS_LIST += ./test_list_resize.cpp
SRCS_LIST += ./test_list_assign.cpp
SRCS_LIST += ./test_list_member_swap.cpp
SRCS_LIST += ./test_list_nonmember_swap.cpp
SRCS_LIST += ./test_list_relational_operators.cpp
SRCS_LIST += ./test_list_splice.cpp
SRCS_LIST += ./test_list_remove_if.cpp
SRCS_LIST += ./test_list_remove.cpp
SRCS_LIST += ./test_list_unique.cpp
SRCS_LIST += ./test_list_merge.cpp
SRCS_LIST += ./test_list_sort.cpp
SRCS_LIST += ./test_list_iterator.cpp
SRCS_LIST += ./test_list_reverseIterator.cpp
SRCS_LIST += ./test_list_reverse.cpp
SRCS_LIST += ./test_list_element_access.cpp

################################################################################
#-------- VECTOR ###############################################################
################################################################################

SRCS_VECTOR += ./main_tester_vector.cpp
SRCS_VECTOR += ./test_vector_instantiation.cpp
SRCS_VECTOR += ./test_vector_push_back_pop_back.cpp
SRCS_VECTOR += ./test_vector_clear.cpp
SRCS_VECTOR += ./test_vector_capacities.cpp
SRCS_VECTOR += ./test_vector_insert_erase.cpp
SRCS_VECTOR += ./test_vector_operatorEqual.cpp
SRCS_VECTOR += ./test_vector_resize.cpp
SRCS_VECTOR += ./test_vector_assign.cpp
SRCS_VECTOR += ./test_vector_at_operatorBrackets.cpp
SRCS_VECTOR += ./test_vector_member_swap.cpp
SRCS_VECTOR += ./test_vector_nonmember_swap.cpp
SRCS_VECTOR += ./test_vector_relational_operators.cpp
SRCS_VECTOR += ./test_vector_iterator.cpp
SRCS_VECTOR += ./test_vector_reverseIterator.cpp
SRCS_VECTOR += ./test_vector_element_access.cpp

################################################################################
#-------- STACK  ###############################################################
################################################################################

SRCS_STACK += ./main_tester_stack.cpp
SRCS_STACK += ./test_stack_general.cpp

# ################################################################################
# #-------- QUEUE  ###############################################################
# ################################################################################

SRCS_QUEUE += ./main_tester_queue.cpp
SRCS_QUEUE += ./test_queue_general.cpp

################################################################################
#-------- DEQUE  ###############################################################
################################################################################

SRCS_DEQUE += ./main_tester_deque.cpp
SRCS_DEQUE += ./test_deque_instantiation.cpp
SRCS_DEQUE += ./test_deque_push_pop.cpp
SRCS_DEQUE += ./test_deque_clear.cpp
SRCS_DEQUE += ./test_deque_capacities.cpp
SRCS_DEQUE += ./test_deque_insert_erase.cpp
SRCS_DEQUE += ./test_deque_operatorEqual.cpp
SRCS_DEQUE += ./test_deque_resize.cpp
SRCS_DEQUE += ./test_deque_assign.cpp
SRCS_DEQUE += ./test_deque_at_operatorBrackets.cpp
SRCS_DEQUE += ./test_deque_member_swap.cpp
SRCS_DEQUE += ./test_deque_nonmember_swap.cpp
SRCS_DEQUE += ./test_deque_relational_operators.cpp
SRCS_DEQUE += ./test_deque_iterator.cpp
SRCS_DEQUE += ./test_deque_reverseIterator.cpp
SRCS_DEQUE += ./test_deque_element_access.cpp

################################################################################
#-------- MAP    ###############################################################
################################################################################

SRCS_MAP += ./main_tester_map.cpp
SRCS_MAP += ./test_map_instantiation.cpp
SRCS_MAP += ./test_map_insert_erase.cpp
SRCS_MAP += ./test_map_capacities.cpp
SRCS_MAP += ./test_map_iterator.cpp
SRCS_MAP += ./test_map_at_operatorBrackets.cpp
SRCS_MAP += ./test_map_swap.cpp
SRCS_MAP += ./test_map_clear.cpp
SRCS_MAP += ./test_key_compare_value_compare.cpp
SRCS_MAP += ./test_map_operatorEqual.cpp
SRCS_MAP += ./test_map_find.cpp
SRCS_MAP += ./test_map_count.cpp
SRCS_MAP += ./test_map_lower_bound.cpp
SRCS_MAP += ./test_map_upper_bound.cpp
SRCS_MAP += ./test_map_equal_range.cpp
SRCS_MAP += ./test_map_reverseIterator.cpp

################################################################################
#-------- SET    ###############################################################
################################################################################

SRCS_SET += ./main_tester_set.cpp
SRCS_SET += ./test_set_instantiation.cpp
SRCS_SET += ./test_set_insert_erase.cpp
SRCS_SET += ./test_set_capacities.cpp
SRCS_SET += ./test_set_iterator.cpp
SRCS_SET += ./test_set_swap.cpp
SRCS_SET += ./test_set_clear.cpp
SRCS_SET += ./test_set_key_compare_value_compare.cpp
SRCS_SET += ./test_set_operatorEqual.cpp
SRCS_SET += ./test_set_find.cpp
SRCS_SET += ./test_set_count.cpp
SRCS_SET += ./test_set_lower_bound.cpp
SRCS_SET += ./test_set_upper_bound.cpp
SRCS_SET += ./test_set_equal_range.cpp
SRCS_SET += ./test_set_reverseIterator.cpp

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
vpath %.hpp ./includes/your_headers

OBJS_VECTOR = $(patsubst %.cpp, $(OBJ_DIR)%.o, $(SRCS_VECTOR))
OBJS_STACK= $(patsubst %.cpp, $(OBJ_DIR)%.o, $(SRCS_STACK))
OBJS_QUEUE = $(patsubst %.cpp, $(OBJ_DIR)%.o, $(SRCS_QUEUE))
OBJS_DEQUE = $(patsubst %.cpp, $(OBJ_DIR)%.o, $(SRCS_DEQUE))
OBJS_MAP = $(patsubst %.cpp, $(OBJ_DIR)%.o, $(SRCS_MAP))
OBJS_SET = $(patsubst %.cpp, $(OBJ_DIR)%.o, $(SRCS_SET))
OBJS_LIST = $(patsubst %.cpp, $(OBJ_DIR)%.o, $(SRCS_LIST))

OBJS = $(patsubst %.cpp, $(OBJ_DIR)%.o, $(SRCS))

PCHS = $(patsubst %.hpp, $(PCH_DIR)%.pch, $(PROJECT_HEADER))

all:
	$(MAKE) $(NAME)
	@echo
	@echo

deque: $(PCH_DIR) $(PCHS) $(OBJ_DIR) $(OBJS) $(OBJS_DEQUE)
	$(CC) -std=c++11 $(CFLAGS) $(OBJS) $(OBJS_DEQUE) -I $(INCLUDES) -o $@
	@echo
	@echo "🎉 \033[32m Ready to test $@ !\033[0m ✅"
	@./$@ | cat -n

list: $(PCH_DIR) $(PCHS) $(OBJ_DIR) $(OBJS) $(OBJS_LIST)
	$(CC) -std=c++11 $(CFLAGS) $(OBJS) $(OBJS_LIST) -I $(INCLUDES) -o $@
	@echo
	@echo "🎉 \033[32m Ready to test $@ !\033[0m ✅"
	@./$@ | cat -n

map: $(PCH_DIR) $(PCHS) $(OBJ_DIR) $(OBJS) $(OBJS_MAP)
	$(CC) -std=c++11 $(CFLAGS) $(OBJS) $(OBJS_MAP) -I $(INCLUDES) -o $@
	@echo
	@echo "🎉 \033[32m Ready to test $@ !\033[0m ✅"
	@./$@ | cat -n

vector: $(PCH_DIR) $(PCHS) $(OBJ_DIR) $(OBJS) $(OBJS_VECTOR)
	$(CC) -std=c++11 $(CFLAGS) $(OBJS) $(OBJS_VECTOR) -I $(INCLUDES) -o $@
	@echo
	@echo "🎉 \033[32m Ready to test $@ !\033[0m ✅"
	@./$@ | cat -n

stack: $(PCH_DIR) $(PCHS) $(OBJ_DIR) $(OBJS) $(OBJS_STACK)
	$(CC) -std=c++11 $(CFLAGS) $(OBJS) $(OBJS_STACK) -I $(INCLUDES) -o $@
	@echo
	@echo "🎉 \033[32m Ready to test $@ !\033[0m ✅"
	@./$@ | cat -n


set: $(PCH_DIR) $(PCHS) $(OBJ_DIR) $(OBJS) $(OBJS_SET)
	$(CC) -std=c++11 $(CFLAGS) $(OBJS) $(OBJS_SET) -I $(INCLUDES) -o $@
	@echo
	@echo "🎉 \033[32m Ready to test $@ !\033[0m ✅"
	@./$@ | cat -n

queue: $(PCH_DIR) $(PCHS) $(OBJ_DIR) $(OBJS) $(OBJS_QUEUE)
	$(CC) -std=c++11 $(CFLAGS) $(OBJS) $(OBJS_QUEUE) -I $(INCLUDES) -o $@
	@echo
	@echo "🎉 \033[32m Ready to test $@ !\033[0m ✅"
	@./$@ | cat -n

$(OBJS_DEQUE): $(OBJ_DIR)%.o: %.cpp $(PROJECT_HEADER) $(HEADER)
	$(CC) -std=c++11 $(CFLAGS) $(OTHER_FLAGS) -c $<  -I $(INCLUDES) -o $@

$(OBJS_LIST): $(OBJ_DIR)%.o: %.cpp $(PROJECT_HEADER) $(HEADER)
	$(CC) -std=c++11 $(CFLAGS) $(OTHER_FLAGS) -c $<  -I $(INCLUDES) -o $@

$(OBJS_MAP): $(OBJ_DIR)%.o: %.cpp $(PROJECT_HEADER) $(HEADER)
	$(CC) -std=c++11 $(CFLAGS) $(OTHER_FLAGS) -c $<  -I $(INCLUDES) -o $@

$(OBJS_QUEUE): $(OBJ_DIR)%.o: %.cpp $(PROJECT_HEADER) $(HEADER)
	$(CC) -std=c++11 $(CFLAGS) $(OTHER_FLAGS) -c $<  -I $(INCLUDES) -o $@

$(OBJS_SET): $(OBJ_DIR)%.o: %.cpp $(PROJECT_HEADER) $(HEADER)
	$(CC) -std=c++11 $(CFLAGS) $(OTHER_FLAGS) -c $<  -I $(INCLUDES) -o $@

$(OBJS_STACK): $(OBJ_DIR)%.o: %.cpp $(PROJECT_HEADER) $(HEADER)
	$(CC) -std=c++11 $(CFLAGS) $(OTHER_FLAGS) -c $<  -I $(INCLUDES) -o $@

$(OBJS_VECTOR): $(OBJ_DIR)%.o: %.cpp $(PROJECT_HEADER) $(HEADER)
	$(CC) -std=c++11 $(CFLAGS) $(OTHER_FLAGS) -c $<  -I $(INCLUDES) -o $@

$(OBJS): $(OBJ_DIR)%.o: %.cpp $(PROJECT_HEADER) $(HEADER)
	$(CC) -std=c++11 $(CFLAGS) $(OTHER_FLAGS) -c $<  -I $(INCLUDES) -o $@

$(NAME): vector list map set queue stack deque 

$(PCHS): $(PCH_DIR)%.pch: %.hpp $(PROJECT_HEADER)
	$(CC) -std=c++98 $(CFLAGS) $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

$(PCH_DIR):
	@mkdir -p $@

cpp98 : $(PCH_DIR) $(PCHS)
	@echo "🎉 \033[32m Your project's headers are cpp98 compliant $@ !\033[0m ✅"

pch:
	$(MAKE) $(PCH_DIR)
	$(MAKE) $(PCHS)

FORCE :

clean :
	$(RM) -R $(OBJ_DIR) $(PCH_DIR)

fclean : clean
	$(RM) $(NAME) list map queue stack deque set vector 

re : fclean
	@$(MAKE)

f : cpp98 all

.PHONY: all clean fclean mclean re list map queue stack deque set vector FORCE cmp
#.SILENT:
