CFDIR = src

Object = server1 client1 \
		 server2 client2 \
		 server3 client3 \
		 server4 client4 \
		 server5 client5 \
		 udp_server udp_client \
		 getdate

.PHONY: all

all: ${Object}

server1: ${CFDIR}/server1.c
	gcc ${CFDIR}/server1.c -o server1
client1: ${CFDIR}/client1.c
	gcc ${CFDIR}/client1.c -o client1
server2: ${CFDIR}/server2.c
	gcc ${CFDIR}/server2.c -o server2
client2: ${CFDIR}/client2.c
	gcc ${CFDIR}/client2.c -o client2
server3: ${CFDIR}/server3.c
	gcc ${CFDIR}/server3.c -o server3
client3: ${CFDIR}/client3.c
	gcc ${CFDIR}/client3.c -o client3
server4: ${CFDIR}/server4.c
	gcc ${CFDIR}/server4.c -o server4
client4: ${CFDIR}/client4.c
	gcc ${CFDIR}/client4.c -o client4
server5: ${CFDIR}/server5.c
	gcc ${CFDIR}/server5.c -pthread -o server5
client5: ${CFDIR}/client5.c
	gcc ${CFDIR}/client5.c -pthread -o client5
udp_server: ${CFDIR}/udp_server.c
	gcc ${CFDIR}/udp_server.c -o udp_server
udp_client: ${CFDIR}/udp_client.c
	gcc ${CFDIR}/udp_client.c -o udp_client
getdate: ${CFDIR}/getdate.c
	gcc ${CFDIR}/getdate.c -o getdate

	@mv ${Object} ./obj

clean:
	rm ./obj/*
