from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from flask import render_template
import flask_sqlalchemy

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'postgresql://(replace with postgress username ):(replace with posgress password)@localhost/Self_Driving_Cars'
db = SQLAlchemy(app)

class carmodel(db.Model):
    brand = db.Column(db.String(100))
    licenseplate = db.Column(db.String(100), primary_key=True)
    ownername = db.Column(db.String(100))


class gps(db.Model):
    longitude = db.Column(db.Float)
    latitude = db.Column(db.Float)
    time = db.Column(db.String)
    date = db.Column(db.String)
    licensplate = db.Column(db.String(100))
    dummy = db.Column(db.String(100), primary_key=True)

class eyetacking(db.Model):
    blinks = db.Column(db.Integer)
    yawns = db.Column(db.Integer)
    headtilt = db.Column(db.Integer)
    eyefocus = db.Column(db.Integer)
    licensplate = db.Column(db.String)
    dummy = db.Column(db.String(100), primary_key=True)

class alertness(db.Model):
    blinkscore = db.Column(db.Integer)
    yawnscore = db.Column(db.Integer)
    headtiltscore = db.Column(db.Integer)
    eyefocusscore = db.Column(db.Integer)
    licensplate = db.Column(db.String)
    dummy = db.Column(db.String(100), primary_key=True)

class alertsent(db.Model):
    combinedscore = db.Column(db.Integer)
    reportsent = db.Column(db.String)
    licensplate = db.Column(db.String)
    dummy = db.Column(db.String(100), primary_key=True)


@app.route('/')
def index():
    showCar = carmodel.query.all()
    showGps = gps.query.with_entities(gps.longitude,gps.latitude,gps.time,gps.date,gps.licensplate).all()
    showEye = eyetacking.query.with_entities(eyetacking.blinks,eyetacking.yawns,eyetacking.headtilt,eyetacking.eyefocus,eyetacking.licensplate)
    showAlert = alertness.query.with_entities(alertness.blinkscore,alertness.yawnscore,alertness.headtiltscore,alertness.eyefocusscore,alertness.licensplate)
    showSent = alertsent.query.with_entities(alertsent.combinedscore,alertsent.reportsent,alertsent.licensplate)
    return render_template('index.html', showCar=showCar, showGps=showGps, showEye=showEye, showAlert=showAlert, showSent=showSent)


if __name__ == "__main__":
    app.run(host='0.0.0.0', debug=True)



