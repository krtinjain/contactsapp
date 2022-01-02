# First at the top of the program are two macros.

# Objects is simply a shorthand way of referring to all the .o files we need for compilation
# ie., we declared a variable to make our code more efficient

OBJECTS = Contact.o Date.o Person.o misc.o Network.o test_network.o

# The CC macro tells Make what compiler to use. By default, it's 'cc.' I prefer g++, so I change it here to g++.

CC= g++ -std=c++11


# general format for targets:

# target: dependencies
# 	action

# Each .o file below has the following format:

	# blah.o: blah.cpp blah.h and other files that blah.o would depend on
		# perform some action. In this case, we want to compile and create a .o file.
		# so g++ -c blah.cpp

# Specific example:
	# connection.o: connection.cpp connection.h
	# 	g++ -c connection.cpp

# output is the executable file that is created upon typing "make" in the terminal
# Since this is the first target, it is called the "default" target
# So if you type "make" in the terminal, the action under "output" is performed

all: $(OBJECTS)
	$(CC) $(OBJECTS) -o trojan-book.out 

contact: Contact.o test_contact.o
	$(CC) Contact.o test_contact.o -o test-contact.out

date: Date.o test_date.o 
	$(CC) Date.o test_date.o -o test-date.out

person: Date.o Contact.o Person.o  misc.o test_person.o
	$(CC) Date.o Contact.o Person.o misc.o test_person.o -o test-person.out

# Makefiles have a bunch of implicit rules and so a lot of the stuff can be removed from the format I mentioned above
# For example, a makefile will deduce that network.o came from network.cpp, and was compiled to create that
# So it deduces that network.o is automatically dependent on network.cpp, so we can remove that as one of the dependencies.
# Furthermore, Make knows that to create a .o file from a .cpp file, g++ is used. So we can actually remove that as well.

# To illustrate, look at what connection.o looks like now versus what it looked like before in my example above

Person.o: Person.h

Contact.o: Contact.h

Date.o: Date.h

misc.o: misc.h

Network.o: Network.h

test_network.o: test_network.cpp
	$(CC) -c test_network.cpp

# You may ask, what is the point of creating targets for each file? 
# It is helpful to just be able to compile one file at a time for debugging purposes.

# I put this target here in case we want to compile and run all in one command
# Since this is not the default target, you have to type "make flash"
# I called it "flash" because that's what we seem to do in my EE classes.

flash: $(OBJECTS)
	$(CC) $(OBJECTS) -o trojan-book.out
	./trojan-book.out


# The below code cleans out the executable file ("output") and all the .o files that resulted from running "make"

# This could be done without the .PHONY line, but it does two things:
# 1) In case there's an actual file called "clean", the cleaning will still work
# 2) Improves efficiency of the cleaning

# Type "make clean" to run this 

.PHONY: clean
clean:
	-rm trojan-book.out $(OBJECTS)

