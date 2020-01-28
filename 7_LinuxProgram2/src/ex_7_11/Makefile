target = customer producer

.PHONY:all
all: ${target}

customer: customer.c
	gcc customer.c -o customer
producer: producer.c
	gcc producer.c -o producer

clean:
	rm ${target}
