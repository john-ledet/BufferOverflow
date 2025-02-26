from flask import Flask, request

app = Flask(__name__)

def vulnerable_function(user_input):
    buffer = bytearray(64)  # Fixed buffer size of 64 bytes
    if len(user_input) > 64:
        raise Exception("Input too large!")
    buffer[:len(user_input)] = user_input.encode()  # Unsafe memory operation
    return "Processed input: " + user_input

@app.route('/vuln', methods=['POST'])
def vuln_endpoint():
    user_input = request.form.get('input', '')
    return vulnerable_function(user_input)

if __name__ == '__main__':
    app.run(debug=True)
