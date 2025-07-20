# Nome do compilador
COMPILADOR = g++

# Flags de boa prática
FLAGS = -Wall -pedantic -std=c++17

# Nome do executável final
EXECUTAVEL = autocomplete

# Lista de arquivos fonte
FONTES = src/autoCompletar.cpp \
         src/main.cpp \
         src/termo.cpp

# Lista de arquivos objeto
OBJETOS = autoCompletar.o main.o termo.o

# Regra principal: compilar tudo
all: $(EXECUTAVEL)

# Como gerar o executável a partir dos objetos
$(EXECUTAVEL): $(OBJETOS)
	$(COMPILADOR) $(FLAGS) $(OBJETOS) -o $(EXECUTAVEL)

# Como compilar cada arquivo .cpp para .o
autoCompletar.o:
	$(COMPILADOR) $(FLAGS) -c src/autoCompletar.cpp -o autoCompletar.o

main.o:
	$(COMPILADOR) $(FLAGS) -c src/main.cpp -o main.o

termo.o:
	$(COMPILADOR) $(FLAGS) -c src/termo.cpp -o termo.o

# Regra de limpeza
clean:
ifeq ($(OS),Windows_NT)
	cmd /c del /f /q $(subst /,\,$(OBJETOS)) $(subst /,\,$(EXECUTAVEL).exe)
else
	rm -f $(OBJETOS) $(EXECUTAVEL)
endif