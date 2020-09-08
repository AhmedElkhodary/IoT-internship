import network, urequests
#from urllib.parse import urlencode
from parse import urlencode # uncomment the above line and comment out this one if the code above worked in the REPL

parameters = {
    "q":"Damietta",
    "appid":"*******************",
    "units":"metric"
}

def connect_to_wifi(wlan, ssid, password):
    if not wlan.isconnected():
        print("Connecting to network...")
        wlan.connect(ssid, password)
        while not wlan.isconnected():
            pass

def get(url, params=None, **kw):
    if params:
        url = url.rstrip('?') + '?' + urlencode(params, doseq=True)
        #print("url with parameters: " + url)
    return urequests.get(url, **kw)

wlan = network.WLAN(network.STA_IF)
wlan.active(True)

SSID = "*******"
PASSWORD = "*******"

connect_to_wifi(wlan, SSID, PASSWORD)

response = get('https://api.openweathermap.org/data/2.5/weather', parameters)
#print(response.text)
weather_data = response.json()
print("****Damietta Weather****")
print(weather_data["main"])
