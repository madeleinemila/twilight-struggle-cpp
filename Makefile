release: 
	/usr/bin/clang++ -fcolor-diagnostics -fansi-escape-codes -g -O2 -DNDEBUG -std=c++20 src/**.cpp -o roll

dev: 
	/usr/bin/clang++ -fcolor-diagnostics -fansi-escape-codes -ggdb -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror -std=c++20 src/**.cpp -o roll
