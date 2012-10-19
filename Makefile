EXE = miceinjoy

CFLAGS = -c -Wall

HOST=mipsel-linux-

CC = $(HOST)gcc
STRIP = $(HOST)strip

DEFS += -DUINPUT_FILE="\"/dev/uinput\""
DEFS += -DJOYSTICK_FILE=\""/dev/js0\""	
DEFS += -DCONFIG_FILE=\""/boot/local/home/analog.conf\""

SRC = 	main.c \
	configure.c \
	analog.c
	
CFLAGS += $(DEFS)

OBJ = $(SRC:.c=.o)

all : $(SRC) $(EXE)

$(EXE): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) $(LIB) -o $@
ifndef DEBUG
	$(STRIP) $(EXE)
endif

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) $< -o $@

clean:
	rm -rf *.o $(EXE)