EXE = miceinjoy

CFLAGS = -c -Wall

HOST?=mipsel-linux-

CC = $(HOST)gcc
STRIP = $(HOST)strip

DEPS= -lini

DEFS+=-DUINPUT_FILE="\"/dev/uinput\""
DEFS+=-DJOYSTICK_FILE=\""/dev/js0\""
DEFS+=-DCONFIG_FILE=\""/boot/local/home/analog.conf\""

SRC = 	main.c \
	configure.c \
	analog.c
	
CFLAGS += $(DEFS)
ifdef DEBUG
	DEFS += -DDEBUG
endif

OBJ = $(SRC:.c=.o)

all : $(SRC) $(EXE)

$(EXE): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) $(DEPS) -o $@
ifndef DEBUG
	$(STRIP) $(EXE)
endif

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) $< -o $@

clean:
	rm -rf *.o $(EXE)