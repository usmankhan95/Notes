#rawConn - making raw connection to Google Maps

import httplib
import json
import urllib #for encode URL

path = ('/maps/api/geocode/json?address=%s&sensor=false&region=%s') % \
		(urllib.quote('The Hong Kong Polytechnic University', safe=''), \
		 urllib.quote('Hong Kong', safe=''))

#make a HTTP connection and send GET request
connection = httplib.HTTPConnection('maps.google.com')
connection.request('GET', path)

#get the JSON response and paste it
rawreply = connection.getresponse().read()
reply = json.loads(rawreply)

lat = reply['results'][0]['geometry']['location']['lat']
lng = reply['results'][0]['geometry']['location']['lng']

print lat, lng