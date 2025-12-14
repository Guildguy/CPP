NAME := PmergeMe
CC := c++

FLAGS := -Wall -Wextra -Werror -std=c++98

SRC_DIR := .
OBJ_DIR := obj

CPP_FILES := PmergeMe.cpp main.cpp
OBJ_FILES := $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(CPP_FILES))

all: $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES)
	$(CC) $(FLAGS) $(OBJ_FILES) -o $(NAME)

v: 
	valgrind --leak-check=full ./$(NAME)

test: $(NAME)
	@echo "=== TESTE 1: Números pequenos ==="
	@./$(NAME) 5 2 8 1 9
	@echo ""
	@echo "=== TESTE 2: Números já ordenados ==="
	@./$(NAME) 1 2 3 4 5 6 7 8
	@echo ""
	@echo "=== TESTE 3: Números invertidos ==="
	@./$(NAME) 9 8 7 6 5 4 3 2 1
	@echo ""
	@echo "=== TESTE 4: Lista grande ==="
	@./$(NAME) 42 17 89 5 63 23 91 11 56 34 78 2 45 67 29 81 13 55 88 31
	@echo ""
	@echo "=== TESTE 5: Um único número ==="
	@./$(NAME) 42
	@echo ""
	@echo "=== TESTE 6: Dois números ==="
	@./$(NAME) 5 3
	@echo ""
	@echo "=== TESTE 7: Números com duplicatas (erro esperado) ==="
	@./$(NAME) 5 3 7 3 2 2>&1 || true
	@echo ""
	@echo "=== TESTE 8: String vazia (erro esperado) ==="
	@./$(NAME) "" 2>&1 || true
	@echo ""
	@echo "=== TESTE 9: Números negativos (erro esperado) ==="
	@./$(NAME) 5 -3 7 2>&1 || true
	@echo ""
	@echo "=== TESTE 10: Números aleatórios pares ==="
	@./$(NAME) 100 50 75 25 99 1 33 77

test-large: $(NAME)
	@echo "=== TESTE LARGE 1: 1000 números aleatórios (1-10000) ===" | tee output_1000.txt
	@time ./$(NAME) $$(shuf -i 1-3000 -n 1000) >> output_1000.txt 2>&1
	@echo "✓ Output salvo em output_1000.txt"
	@echo ""
	@echo "=== TESTE LARGE 2: 3000 números aleatórios (1-10000) ===" | tee output_3000.txt
	@time ./$(NAME) $$(shuf -i 1-4000 -n 3000) >> output_3000.txt 2>&1
	@echo "✓ Output salvo em output_3000.txt"
	@echo ""
	@echo "=== TESTE LARGE 3: 5000 números aleatórios (1-10000) ===" | tee output_5000.txt
	@time ./$(NAME) $$(shuf -i 1-6000 -n 5000) >> output_5000.txt 2>&1
	@echo "✓ Output salvo em output_5000.txt"
	@echo ""
	@echo "=== TESTE LARGE 4: 10000 números aleatórios (1-10000) ===" | tee output_10000.txt
	@time ./$(NAME) $$(shuf -i 1-15000 -n 10000) >> output_10000.txt 2>&1
	@echo "✓ Output salvo em output_10000.txt"

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f output_*.txt

re: fclean all

.PHONY: all clean fclean re v test test-large
