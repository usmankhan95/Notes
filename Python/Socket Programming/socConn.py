#socConn - make a request by using socket
import socket

sock = socket.socket()
sock.connect(('maps.google.com', 80)) #port number 80 - HTTP(web)

sock.sendall(
	'GET /maps/api/geocode/json?address=The%20Hong%20Kong%20Polytechnic%20University'
	'&sensor=false&region=Hong%20Kong HTTP/1.1\r\n'
	'Host: maps.google.com:80\r\n'
	'User-Agent: socConn.py\r\n'
	'Connection: close\r\n'
	'\r\n'
	)
rawreply = sock.recv(4096)
print rawreply