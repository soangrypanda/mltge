SRCDIR = src
OBJDIR = obj
HEADDIR = headers

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c, %.o, $(SRC))

vpath %.h $(HEADDIR)
vpath %.c $(SRCDIR)
vpath %.o $(OBJDIR)

LIB = mltge
CFLAGS = -lcurses -Iheaders


statlib: $(OBJ)
	ar rcs lib$(LIB).a $(addprefix $(OBJDIR)/, $^) 

objects: $(OBJ)

$(OBJ): %.o :%.c %.h | $(OBJDIR)
	$(CC) $(CFLAGS) $< -c -o $(OBJDIR)/$@

$(OBJDIR):
	mkdir $@


.PHONY: clean cleanall print

cleanall: clean
	-rm lib$(LIB).a lib$(LIB).so

clean:
	-rm -r $(OBJDIR)

print:
	@echo objects: $(OBJ)


