TARGET = main

SRC = src
INC = inc
OBJ = obj

SOURCE = $(wildcard $(SRC)/*.c)
OBJECT = $(patsubst %,$(OBJ)/%, $(notdir $(SOURCE:.c=.o)))

CC = gcc
CFLAGS = -Wall -std=gnu99 -pedantic -I$(INC)

RED = \033[1;31m
GREEN = \033[1;32m
BLUE = \033[1;34m
YELLOW = \033[1;33m
NC = \033[1;0m
$(OBJ)/$(TARGET) : $(OBJECT)
	@echo "$(RED)Linkowanie...$(NC)"
	$(CC) -o $@ $^ -lm
	@echo "$(BLUE)Zakonczono linkowanie.$(NC)"

$(OBJ)/%.o : $(SRC)/%.c
	@echo "$(GREEN)Kompilacja...$(NC)"
	$(CC) $(CFLAGS) -c $< -o $@ 

.PHONY : help run clean

run : $(OBJ)/$(TARGET)
	@echo "$(YELLOW)Uruchamianie.$(NC)"
	$(OBJ)/$(TARGET)

clean :
	rm -f $(OBJECT) $(OBJ)/$(TARGET)
help :
	@echo "src: $(SOURCE)"
	@echo "obj: $(OBJECT)"
