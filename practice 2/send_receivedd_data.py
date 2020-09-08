import network
import urequests as requests
import ujson as json
import time

def connect_to_wifi(wlan, ssid, password):
    if not wlan.isconnected():
        print("Connecting to network...")
        wlan.connect(ssid, password)
        while not wlan.isconnected():
            pass
wlan = network.WLAN(network.STA_IF)
wlan.active(True)

SSID = "*******"
PASSWORD = "*******"

connect_to_wifi(wlan, SSID, PASSWORD)


def send():
    print('sending', end="")
    for i in range(3):
        print('.', end=" ")
        time.sleep(1)

def receive():
    print('receiving', end="")
    for i in range(3):
        print('.', end=" ")
        time.sleep(1)

def send_and_receive():
    print('\n\n******DATA sensors send*******')
    data_sensors = {'sensor1': {'id': 101, 'type': 'temp', 'value': 37},
                    'sensor2': {'id': 102, 'type': 'speed', 'value': 10}}
    data_json = json.dumps(data_sensors)
    print(data_json)
    send()
    response = requests.post('https://httpbin.org/post', data = data_json)
    print('\n\n******DATA sensors receive*******')
    receive()
    print("\nStatus code: ", response.status_code)
    print("Printing  Request Data")
    data_json = response.json()
    print(json.loads(data_json['data']), '\n')
    

for i in range(3):
    send_and_receive()
    time.sleep(2)
