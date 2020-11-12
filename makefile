CC=g++
CFLAGS=-g -Wall -O2
CPP_FLAGS='-std=c++11'
LIBS=-I./libs -lboost_system -lpthread
INCLUDES=-I ./ -I ./include -I ./include/lib/rapidjson/include -I ./include/lib/websocketpp/

TARGET_HTRD_MINION_PROTECTOR = out
all:$(TARGET_HTRD_MINION_PROTECTOR)

$(TARGET_HTRD_MINION_PROTECTOR): sio_socket.cpp sio_socket.h ./internal/sio_client_impl.h ./internal/sio_client_impl.cpp sio_packet.h sio_packet.cpp sio_client.h sio_client.cpp sio_message.h WebSocketClient.cpp WebSocketClient.h
	$(CC) ${CPP_FLAGS} -o $@ ./libs/libsioclient.a sio_packet.cpp sio_client.cpp sio_socket.h sio_socket.cpp ./internal/sio_client_impl.cpp WebSocketClient.cpp $(INCLUDES) $(CFLAGS) main.cpp $(LIBS) 

clean:
	rm  -f *.o $(TARGET_HTRD_MINION_PROTECTOR)
