#TCPClient - Simple TCP client which sends 16 octets

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


s.connect((HOST, PORT))
print 'Client has been assigned socket name', s.getsockname()
s.sendall('Hello!! Server!!') #16 characters
reply = recv_all(s, 16) 
print 'The server said', repr(reply)
s.close