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

msg = raw_input('Please enter your message: ')

#determine the message length (max 255 characters, i.e. 3 digits), pad with leading zeroes
msg_length_in_str = str(len(msg))
msg_length_in_str = msg_length_in_str.zfill(3)

s.sendall(msg_length_in_str + msg) #add the length at the beginning of the message

reply = recv_all(s, 3) 
print 'Server:', repr(reply)
s.close