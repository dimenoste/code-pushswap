# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/15 09:12:00 by yasmine.aic       #+#    #+#              #
#    Updated: 2026/03/04 16:45:24 by mberraho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# TODO
# ajouter .d
# ajouter -M

NAME            = push_swap
NAME_OP_TEST    = operations
NAME_PARSER_TEST = parser
NAME_LIS = lis
NAME_ISORT_TEST  = isort
NAME_MAIN_STRATEGY = strategy

OBJ_DIR = obj

VALGRIND_OUTPUT = valgrind-out.txt

# fichiers sources de la stack
STACK_SRCS = stack_init.c \
             stack_ops.c \
             stack_helpers.c \
			 indexing.c \
			 _sort_array.c


# fichiers sources des operations
OPS_SRCS = operations_swap.c \
           operations_rotate.c \
           operations_list.c \
		   stack_utils.c

# fichiers sources des algos
LIS_SRCS = medium_algo.c \
			lis.c
#sort_array.c 
		  

# fichiers sources du parser
PARSER_SRCS = init_parser.c \
	run_parser.c \
	extract_option.c \
	transitions_functions_parsing.c \
	transitions_functions_parsing2.c \
	utils_parsing.c \
	init_states1.c \
	init_states2.c \
	reactions_WhenInStart1.c \
	reactions_WhenInStart2.c \
	reactions_WhenInDash1.c \
	reactions_WhenInDash2.c \
	reactions_WhenInNumber1.c \
	reactions_WhenInNumber2.c \
	reactions_WhenInSpace1.c \
	reactions_WhenInSpace2.c \
	reactions_WhenInOption1.c \
	reactions_WhenInOption2.c \
	reactions_WhenInInvalid.c \
	get_options.c \
	classify_input.c 

# --- Module Disorder : calcul du desordre pour la strategie adaptive ---
DISORDER_SRCS = disorder.c
# --- fichiers source de insertion sort
SORT_SRCS = insertion_sort.c \
			insertion_sort_utils.c \
			insertion_sort_helpers.c \
            insertion_sort_cost.c 

STRAT_SRCS = strategy.c

PRINTF_SRCS = ft_printf.c \
			ft_putnbr.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_put_hexa.c \
			ft_ptr.c \
			ft_printf.h
#*----
HEADER = push_swap.h
MAIN_PUSH_SWAP   = main.c
MAIN_LIS_TEST   = test_lis.c
MAIN_OP_TEST     = test_operations.c
MAIN_PARSER_TEST = test_parser.c
MAIN_ISORT_TEST  = test_isort.c
MAIN_STRATEGY  = main_strategy.c

# Sources pour chaque executable
SRCS_PUSH_SWAP   =  $(HEADER) $(PRINTF_SRCS) $(STACK_SRCS) $(OPS_SRCS) $(PARSER_SRCS) $(MAIN_PUSH_SWAP) 
SRCS_OP_TEST     = $(HEADER) $(PRINTF_SRCS) $(STACK_SRCS) $(OPS_SRCS) $(DISORDER_SRCS) $(MAIN_OP_TEST)
SRCS_PARSER_TEST = $(STACK_SRCS) $(OPS_SRCS) $(PARSER_SRCS) $(MAIN_PARSER_TEST)
SRCS_LIS_TEST = $(HEADER) $(STACK_SRCS) $(OPS_SRCS) $(LIS_SRCS) $(MAIN_LIS_TEST)
SRCS_ISORT_TEST  = $(HEADER) $(PRINTF_SRCS) $(STACK_SRCS) $(OPS_SRCS) $(DISORDER_SRCS) $(SORT_SRCS) $(LIS_SRCS) $(MAIN_ISORT_TEST)
SRCS_MAIN_STRATEGY = $(HEADER) $(PRINTF_SRCS) $(STACK_SRCS) $(OPS_SRCS) $(PARSER_SRCS) $(DISORDER_SRCS)  $(SORT_SRCS) $(LIS_SRCS) $(STRAT_SRCS) $(MAIN_STRATEGY)



OBJS_PUSH_SWAP   = $(SRCS_PUSH_SWAP:%.c=$(OBJ_DIR)/%.o)
OBJS_OP_TEST     = $(SRCS_OP_TEST:%.c=$(OBJ_DIR)/%.o)
OBJS_PARSER_TEST = $(SRCS_PARSER_TEST:%.c=$(OBJ_DIR)/%.o)
OBJS_LIS_TEST = $(SRCS_LIS_TEST:%.c=$(OBJ_DIR)/%.o)

OBJS_ISORT_TEST  = $(SRCS_ISORT_TEST:%.c=$(OBJ_DIR)/%.o)

OBJS_MAIN_STRATEGY  = $(SRCS_MAIN_STRATEGY:%.c=$(OBJ_DIR)/%.o)

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g
INCLUDES = -Iinclude

GREEN  = '\033[0;32m'
YELLOW = '\033[0;33m'
RED    = '\033[0;31m'
NC     = '\033[0m'


# --- Target par defaut ---
all: $(NAME)

# --- Compilation de push_swap ---
# [TODO] Decommenter quand main.c de tout le programme existera
# $(NAME): $(OBJS_PUSH_SWAP)
# 	@$(CC) $(CFLAGS) $(OBJS_PUSH_SWAP) -o $(NAME)
# 	@echo "$(GREEN)✓ $(NAME) compile !$(NC)"
$(NAME): $(OBJS_PUSH_SWAP)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS_PUSH_SWAP) _g -o $(NAME)
	@echo -e ${RED}main.c pas encore implemente. Utilise 'make test_ops' ou 'make test_parser'${NC}

# --- Compilation du test des operations ---
$(NAME_OP_TEST): $(OBJS_OP_TEST)
	@$(CC) $(CFLAGS) $(INCLUDES) -g $(OBJS_OP_TEST) -o $(NAME_OP_TEST)
	@echo -e ${GREEN}✓ $(NAME_OP_TEST) compile !${NC}

# --- Compilation du test du parser ---
$(NAME_PARSER_TEST): $(OBJS_PARSER_TEST)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS_PARSER_TEST) -g -O0 -o $(NAME_PARSER_TEST)
	@echo -e ${GREEN}✓ $(NAME_PARSER_TEST) compile !${NC}

# --- Compilation du test algo medium---
$(NAME_LIS): $(OBJS_LIS_TEST)
	@$(CC) $(CFLAGS) $(INCLUDES) -g $(OBJS_LIS_TEST) -o $(NAME_LIS)
	@echo -e ${GREEN}✓ $(NAME_LIS) compile !${NC}


# -- Compilation du test du simple --
$(NAME_ISORT_TEST): $(OBJS_ISORT_TEST)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS_ISORT_TEST) -g -o $(NAME_ISORT_TEST)
	@echo -e ${GREEN}✓ $(NAME_ISORT_TEST) compile !${NC}


# -- Compilation du test des parser + algo + strategy --
$(NAME_MAIN_STRATEGY): $(OBJS_MAIN_STRATEGY)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS_MAIN_STRATEGY) -g -o $(NAME_MAIN_STRATEGY)
	@echo -e ${GREEN}✓ $(NAME_MAIN_STRATEGY) compile !${NC}


# general push_swap dir of .o
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo -e ${GREEN}✓ Compiled: $<${NC}

# lance le test des operations
test_ops: $(NAME_OP_TEST)
	@echo -e ${YELLOW}Lancement des tests operations...${NC}
	@./$(NAME_OP_TEST)

# lance le test du parser
test_parser: $(NAME_PARSER_TEST)
	@echo -e ${YELLOW}Lancement des tests parser...${NC}
	@echo -e ${YELLOW}.........Test ordonne...........${NC}
	@./$(NAME_PARSER_TEST) 1 2 
	@echo -e ${YELLOW}.........Test avec option...........${NC}
	@./$(NAME_PARSER_TEST) --simple 56 5 9 8
	@echo -e ${YELLOW}.........Test avec option et bench ...........${NC}
	@./$(NAME_PARSER_TEST) --simple 56 5 9 8 --bench
	@echo -e ${YELLOW}.........Test doit afficher Error...........${NC}
	@./$(NAME_PARSER_TEST) l 1 2 3
	@echo -e ${YELLOW}.........Test vide ...........${NC}
	@./$(NAME_PARSER_TEST)
	@echo -e ${YELLOW}.........Test doit afficher Error...........${NC}
	@./$(NAME_PARSER_TEST) --simple  --bencg= 1 2 6 -1
	@echo -e ${GREEN}Le parser marche...${NC}

# lance le test algo medium
test_lis: $(NAME_LIS)
	@echo -e ${YELLOW}Lancement des tests operations...${NC}
	@./$(NAME_LIS)

# insertion sort
test_isort: $(NAME_ISORT_TEST)
	@echo -e ${YELLOW}========================================${NC}
	@echo -e ${YELLOW} Running insertion_sort test suite...  ${NC}
	@echo -e ${YELLOW}========================================${NC}
	@./$(NAME_ISORT_TEST)
	@echo -e ${GREEN}✓ insertion_sort tests finished${NC}

# lance le test sur les algos branche au parser 
main_strategy : $(NAME_MAIN_STRATEGY)
	@echo -e ${YELLOW}========================================${NC}
	@echo -e ${YELLOW} Running  algo strategy test suite...  ${NC}
	@echo -e ${YELLOW}========================================${NC}
	@./$(NAME_MAIN_STRATEGY)
	@echo -e ${GREEN}✓ run algo strategy tests finished${NC}

# Valgrind sur le test des operations
valgrind: $(NAME_OP_TEST)
	@echo -e ${YELLOW}✓ Valgrind en cours...${NC}
	@valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(NAME_OP_TEST)

#Valgrind sur les test de l'algo simple
valgrind_isort: $(NAME_ISORT_TEST)
	@echo -e "\033[0;33m✓ Valgrind (insertion_sort) en cours...\033[0m"
	@valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(NAME_ISORT_TEST)

#Valgrind sur les test de l'algo medium
valgrind_lis: $(NAME_LIS)
	@echo -e "\033[0;33m✓ Valgrind (lis_sort) en cours...\033[0m"
	@valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(NAME_LIS)

#Valgrind sur strategy and algos
valgrind_algo: $(NAME_MAIN_STRATEGY)
	@echo -e "\033[0;33m✓ Valgrind (lis_sort) en cours...\033[0m"
	@valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(NAME_MAIN_STRATEGY)
	
norm:
	@norminette $(SRCS_PUSH_SWAP)

help:
	@echo -e ${YELLOW} Targets disponibles :${NC}
	@echo "  make            - Build push_swap (quand main.c existera)"
	@echo "  make test_ops   - Compile et lance les tests operations"
	@echo "  make test_parser   - Compile et lance les tests du parser"
	@echo "  make test_isort - Compile et lance les tests insertion sort"
	@echo "  make test_lis - Compile et lance de l'algo insertion sort + LIS"
	@echo "  make valgrind   - Test operations avec valgrind"
	@echo "  make valgrind_isort - Test insertion sort avec valgrind"
	@echo "  make valgrind_lis - Test lis sort avec valgrind"
	@echo "  make clean      - Supprime les .o"
	@echo "  make fclean     - Supprime tout (clean + executables)"
	@echo "  make re         - Recompile tout depuis zero"
	@echo "  make norm       - Verifie la norminette"

clean:
	@rm -rf $(OBJ_DIR)
	@echo -e ${GREEN}✓ Fichiers objets supprimes${NC}

fclean: clean
	@rm -f $(NAME) $(NAME_OP_TEST) $(NAME_PARSER_TEST) $(NAME_ISORT_TEST) $(NAME_LIS) $(NAME_ISORT_TEST) $(NAME_MAIN_STRATEGY)
	@rm -f $(VALGRIND_OUTPUT) vgcore* *.out
	@echo -e ${GREEN}✓ Executables supprimes${NC}
	
re: fclean all
# --- Phony ---
.PHONY: all clean fclean re test_ops test_parser test_isort \
        valgrind valgrind_isort norm help valgrind_lis
