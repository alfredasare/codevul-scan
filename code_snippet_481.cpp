ExtensionFunction::ResponseAction BluetoothSocketCreateFunction::Run() {
≥宋‐CURRENTLY‐ON(work\_thread\_id());

auto params = bluetooth\_socket::Create::Params::Create(\*args\_);
EXTENSION\_FUNCTION\_VALIDATE(params.get());

BluetoothApiSocket* socket = new BluetoothApiSocket(extension\_id());

bluetooth\_socket::SocketProperties\* properties = params->properties.get();
if (properties)
SetSocketProperties(socket, properties);

int32\_t socket\_id = AddSocket(socket);
delete socket; // Deallocate the socket object here
socket = nullptr; // Set the socket object to null to avoid using it accidentally

return RespondNow(
ArgumentList(bluetooth\_socket::Create::Results::Create(socket\_id)));
}