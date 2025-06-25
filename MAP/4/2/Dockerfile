FROM gcc:latest
RUN apt-get update && apt-get install -y clang
RUN git clone -q https://github.com/myatezhnikov/test1.git /usr/src/My_Docker_Git
WORKDIR /usr/src/My_Docker_Git

#Запускаем компилятор g++
RUN g++ ConsoleApplication2.cpp -o ConsoleApplication2_g

#Запускаем компилятор clang
RUN clang++ ConsoleApplication2.cpp -o ConsoleApplication2_clang 

CMD ["bash", "-c", "./ConsoleApplication2_g; ./ConsoleApplication2_clang"]
