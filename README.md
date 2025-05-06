# Otus_prof_https_client

Реализация программы асинхронного https клиента с пулом потоков.
* Асинхронность: Используется асинхронный ввод-вывод с помощью Boost.Asio.
* HTTPS поддержка: Реализовано с помощью OpenSSL через Boost.Beast.
* Выбранная IDE: VSCode
* Выбранный компилятор : CMake (C/С++ IntelliSense)

# Сборка и запуск

1. Установите зависимости:
sudo apt-get install libboost-all-dev libssl-dev

2. Создайте сертификаты для сервера:
openssl req -x509 -newkey rsa:4096 -keyout server.key -out server.crt -days 365 -nodes

3. Соберите клиент:
g++ -std=c++17 -o client client.cpp -lboost_system -lssl -lcrypto

4. Запустите клиент:
./https_client localhost 4433 /index.html
