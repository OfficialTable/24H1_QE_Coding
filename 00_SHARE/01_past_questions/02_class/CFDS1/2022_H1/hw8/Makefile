TARGET1=nn
TARGET2=tool

OBJECTS1=main.o tensor.o op.o util.o
OBJECTS2=tool.o tensor.o op.o util.o

CXX=g++
CXXFLAGS=-O3

SLURM_FLAGS=--nodes=1 --ntasks-per-node=1 --time=5 --cpus-per-task=1 --mem=1G

all: $(TARGET1) $(TARGET2)

$(TARGET1): $(OBJECTS1)
	$(CXX) -o $@ $(OBJECTS1)

$(TARGET2): $(OBJECTS2)
	$(CXX) -o $@ $(OBJECTS2)

clean:
	rm -rf $(TARGET1) $(OBJECTS1) $(TARGET2) $(OBJECTS2)

run: $(TARGET1)
	salloc $(SLURM_FLAGS) ./$(TARGET1)
