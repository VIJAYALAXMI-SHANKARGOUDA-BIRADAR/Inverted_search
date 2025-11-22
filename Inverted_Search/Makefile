# Collect all source files
SRC := $(wildcard *.c)

# Directory to store object files
OBJDIR := obj

# Convert .c → obj/%.o
OBJ := $(patsubst %.c,$(OBJDIR)/%.o,$(SRC))

# Final executable target
inverted.out: $(OBJ)
	gcc -o $@ $^

# Rule to build .o files inside obj/
# $< = source file, $@ = target object file
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	gcc -c $< -o $@

# Create obj/ folder if it does not exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Clean rule → removes object directory and executable
clean:
	rm -rf $(OBJDIR) search.out