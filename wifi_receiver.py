from flask import Flask, request

app = Flask(__name__)

@app.route('/wifi', methods=['POST'])
def receive_wifi_data():
    data = request.data.decode('utf-8')
    print("Received data:\n", data)

    with open("wifi_scans.txt", "a") as f:
        f.write(data + "\n---\n")

    return "OK"

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
