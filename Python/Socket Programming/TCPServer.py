#TCPServer - Simple TCP server which receives 16 octets
import socket, sys
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

HOST = '127.0.0.1' #localhost
PORT = 8888 	   

def recv_all(sock, length):
	data = ''
	while len(data) < length:
		more = sock.recv(length - len(data))
		if not more:
			raise EOFError('socket closed %d bytes into a %d-byte message'
							% (len(data), length))
		data += more
	return data

s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
s.bind((HOST, PORT))
s.listen(1) #listen 1 client only
while True:
	print 'Listening at', s.getsockname()
	sc, sockname = s.accept() #wait here until there is a request
	print 'We have accepted a connection from ', sockname
	print 'Socket connects', sc.getsockname(), 'and', sc.getpeername()
	message = recv_all(sc, 16)
	print 'The incoming 16-octet message says', repr(message)
	sc.sendall('Bye Bye Client..') #16 characters
	sc.close()
	print 'Reply sent, socket closed'
