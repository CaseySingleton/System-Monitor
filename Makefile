# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csinglet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/22 18:59:57 by csinglet          #+#    #+#              #
#    Updated: 2019/07/28 01:06:17 by nwhitlow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_gkrellm

CC			= clang++
CFLAGS		= -Wall -Werror -Wextra -O3 -Wno -deprecated -declarations
FLAGS		= $(CFLAGS)

FILES		= main.cpp \
			  Cpu.cpp CpuCore.cpp CpuModule.cpp \
			  Ram.cpp RamModule.cpp \
			  Network.cpp NetworkModule.cpp \
			  TerminalDisplay.cpp \
			  DateTimeModule.cpp \
			  WhoModule.cpp \
			  TestModule.cpp \
			  FrameClock.cpp time_util.cpp

# FRAMEWORKS	= -framework OpenGL -framework GLUT

ALL_FILES	= $(FILES)

OBJ			= $(addprefix build/, $(ALL_FILES:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Creating: $(NAME)"
	@$(CC) $(FLAGS) -I includes $(OBJ) -o $@ -ltermcap

build:
	@echo "Creating build directory"
	@mkdir build

build/%.o: sources/%.cpp | build
	@echo "  Building $@"
	@$(CC) -I includes -c $< -o $@

clean:
	@rm -fr build

fclean: clean
	@rm -f $(NAME)

re: fclean all
