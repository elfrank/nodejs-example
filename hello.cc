#include <node.h>
#include <v8.h>

using namespace v8;

Handle<Value> CreateObject(const Arguments& args) 
{
	HandleScope scope;

	Local<Object> obj = Object::New();
	obj->Set(String::NewSymbol("msg"), args[0]->ToString());

	return scope.Close(obj);
}

void Init(Handle<Object> target) 
{
	target->Set(String::NewSymbol("createObject"),
		FunctionTemplate::New(CreateObject)->GetFunction());
}

NODE_MODULE(hello, Init)