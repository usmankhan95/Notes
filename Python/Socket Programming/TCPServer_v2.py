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
	
	#get the length of the message first
	msg_length = int(recv_all(sc, 3))

	#get the 'real' message with proper length
	message = recv_all(sc, msg_length)
	print 'Client said: ', repr(message)
	sc.sendall('Bye') 
	sc.close()	
