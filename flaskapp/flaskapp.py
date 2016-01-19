from flask import Flask, render_template
from pymongo import MongoClient
app = Flask(__name__)

@app.route('/')
def hello_world():
    db = MongoClient('192.168.0.3')['homeautomation']['temperatures']
    temp = db.find_one({'_id':'current_temp'})
    test = temp['temp']
    return render_template('index.html', temp=test)

@app.route('/test')
def test():
    return 'Hello from flaskapp1 test'

if __name__ == '__main__':
    app.run(host='0.0.0.0')
