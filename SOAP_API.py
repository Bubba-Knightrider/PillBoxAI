from spyne import Application, rpc, ServiceBase, Integer, Unicode
from spyne.protocol.soap import Soap11
from spyne.server.wsgi import WsgiApplication

class PillboxService(ServiceBase):
    @rpc(Unicode, Integer, Unicode, _returns=Unicode)
    def postData(ctx, timestamp, sensorValue, status):
        print(f"[SOAP] Data Received: {timestamp} - {sensorValue} - {status}")
        return "Data received successfully"

app = Application([PillboxService],
                  tns='spyne.examples.pillbox',
                  in_protocol=Soap11(),
                  out_protocol=Soap11())

if __name__ == '__main__':
    from wsgiref.simple_server import make_server
    wsgi_app = WsgiApplication(app)
    server = make_server('0.0.0.0', 8000, wsgi_app)
    print("SOAP API running on http://localhost:8000")
    server.serve_forever()
