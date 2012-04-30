var addon = require('./build/Release/hello');
var http = require('http');

var port = 8000;

var server = http.createServer(function (request, response) {
	response.writeHead(200, {'Content-Type': 'text/plain'});
	
	var obj1 = addon.createObject('obj1 from C++\n');
	var obj2 = addon.createObject('obj2 from C++\n');

	response.end(obj1.msg + obj2.msg);	  
});

server.listen(port);

console.log("Server running on localhost:"+port+"\n");