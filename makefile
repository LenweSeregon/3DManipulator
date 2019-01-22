# Makefile #

# Compilation #
CC = g++
EXECUTABLE = exec
CPPFLAGS = -Wall -Wextra -pedantic -g -std=c++17 -lpthread -Wreorder
LDFLAGS = -lpthread -std=c++14 -lSDL2 -lSDL2_ttf
LIBS = L/usr/lib/x86_64-linux-gnu/

# Directory #
OBJDIR = bin
SRCDIR = src
INCDIR = include

# Finding #
SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(SRC:.cpp=.o)
OBJS := $(subst src/,,$(OBJS))
OBJS := $(addprefix $(OBJDIR)/, $(OBJS))


# Rules
all : $(EXECUTABLE)

$(EXECUTABLE) : $(OBJS)
	$(CC) $^ $(LDFLAGS) $(LIB) -o $@\


$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CC) $(CPPFLAGS) $(LIB) $(INCLUDES) -I $(INCDIR) -o $@ -c $<

clean:
	@rm -rf $(OBJDIR)/*.o
	@rm -f $(EXECUTABLE)
	@rm -rf $(SRCDIR)/*.cpp~
	@rm -rf $(INCDIR)/*.hpp~
	@rm -rf $(OBJDIR)/*.o~
	@rm -rf *~
