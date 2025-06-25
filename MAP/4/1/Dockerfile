FROM ubuntu:latest
RUN apt-get update 
RUN apt-get install -y nano g++

# Создаём файл test.cpp
RUN echo '#include <iostream>' >> test.cpp && \
    echo 'int main() {' >> test.cpp && \
    echo ' std::cout << "Hello world" << std::endl;' >> test.cpp && \
    echo '}' >> test.cpp

RUN g++ test.cpp -o test
CMD ["./test"]